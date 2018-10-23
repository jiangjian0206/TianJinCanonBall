/***************************************************************************************
 * ����    ��W5500�Ķ˿�0�����ڿͻ���ģʽ,�����롶TCP&UDP���Թ��ߡ��ϴ����ķ��������,
 *			
 * ʵ��ƽ̨���û�STM32������ + YIXIN_W5500��̫��(TCP/IP)ģ��
 * Ӳ�����ӣ�  PC5 -> W5500_RST       
 *             PA4 -> W5500_SCS      
 *             PA5 -> W5500_SCK    
 *             PA6 -> W5500_MISO    
 *             PA7 -> W5500_MOSI    
 * ��汾  ��ST_v3.5

***************************************************************************************/

/*�����������*/
//���أ�192.168.1.1
//����:	255.255.255.0

//������ַ��0C 29 AB 7C 00 01
//����MCU ��IP��ַ:192.168.1.199
//�˿�0�Ķ˿ںţ�5000

//���Զ˿�0��Ŀ��IP��ַ��192.168.1.190
//�˿�0��Ŀ�Ķ˿ںţ�6000

#include "stm32f10x.h"		
#include "W5500.h"			
#include <string.h>
#include <Delaypoint.h>
#include <TaskDelayExter.h>
#include <Key.h>
#include  <led.h>
#include "usart.h"
//#include <Timer2.h>

void RCC_Configuration(void);		//����ϵͳʱ��Ϊ72MHZ(������Ը�����Ҫ��)
void NVIC_Configuration(void);		//STM32�ж�������������
void Timer2_Init_Config(void);		//Timer2��ʼ������
void System_Initialization(void);	//STM32ϵͳ��ʼ������(��ʼ��STM32ʱ�Ӽ�����)
//void Delay(unsigned int d);			//��ʱ����(ms)
extern void LED_Init(void);
unsigned int Timer2_Counter=0; //Timer2��ʱ����������(ms)
unsigned int W5500_Send_Delay_Counter=0; //W5500������ʱ��������(ms)
unsigned char BuffSprintf[10]; 


/*******************************************************************************
* ������  : W5500_Initialization
* ����    : W5500��ʼ������
* ����    : ��
* ���    : ��
* ����ֵ  : ��
* ˵��    : ��
*******************************************************************************/
void W5500_Initialization(void)
{
	W5500_Init();		//��ʼ��W5500�Ĵ�������
	Detect_Gateway();	//������ط����� 
	Socket_Init(0);		//ָ��Socket(0~7)��ʼ��,��ʼ���˿�0
}

/*******************************************************************************
* ������  : Load_Net_Parameters
* ����    : װ���������
* ����    : ��
* ���    : ��
* ����ֵ  : ��
* ˵��    : ���ء����롢������ַ������IP��ַ���˿ںš�Ŀ��IP��ַ��Ŀ�Ķ˿ںš��˿ڹ���ģʽ
*******************************************************************************/
void Load_Net_Parameters(void)
{
	Gateway_IP[0] = 192;//�������ز���
	Gateway_IP[1] = 168;
	Gateway_IP[2] = 1;
	Gateway_IP[3] = 1;

	Sub_Mask[0]=255;//������������
	Sub_Mask[1]=255;
	Sub_Mask[2]=255;
	Sub_Mask[3]=0;

	Phy_Addr[0]=0x0c;//����������ַ
	Phy_Addr[1]=0x29;
	Phy_Addr[2]=0xab;
	Phy_Addr[3]=0x7c;
	Phy_Addr[4]=0x00;
	Phy_Addr[5]=0x01;

	IP_Addr[0]=192;//���ر���IP��ַ
	IP_Addr[1]=168;
	IP_Addr[2]=1;
	IP_Addr[3]=199;

	S0_Port[0] = 0x13;//���ض˿�0�Ķ˿ں�5000 
	S0_Port[1] = 0x88;

	S0_DIP[0]=192;//���ض˿�0��Ŀ��IP��ַ
	S0_DIP[1]=168;
	S0_DIP[2]=1;
	S0_DIP[3]=190;
	
	S0_DPort[0] = 0x17;//���ض˿�0��Ŀ�Ķ˿ں�6000
	S0_DPort[1] = 0x70;

	S0_Mode=TCP_CLIENT;//���ض˿�0�Ĺ���ģʽ,TCP�ͻ���ģʽ
}

/*******************************************************************************
* ������  : W5500_Socket_Set
* ����    : W5500�˿ڳ�ʼ������
* ����    : ��
* ���    : ��
* ����ֵ  : ��
* ˵��    : �ֱ�����4���˿�,���ݶ˿ڹ���ģʽ,���˿�����TCP��������TCP�ͻ��˻�UDPģʽ.
*			�Ӷ˿�״̬�ֽ�Socket_State�����ж϶˿ڵĹ������
*******************************************************************************/
void W5500_Socket_Set(void)
{
	if(S0_State==0)//�˿�0��ʼ������
	{
		if(S0_Mode==TCP_SERVER)//TCP������ģʽ 
		{
			if(Socket_Listen(0)==TRUE)
				S0_State=S_INIT;
			else
				S0_State=0;
		}
		else if(S0_Mode==TCP_CLIENT)//TCP�ͻ���ģʽ 
		{
			if(Socket_Connect(0)==TRUE)
				S0_State=S_INIT;
			else
				S0_State=0;
		}
		else//UDPģʽ 
		{
			if(Socket_UDP(0)==TRUE)
				S0_State=S_INIT|S_CONN;
			else
				S0_State=0;
		}
	}
}

/*******************************************************************************
* ������  : Process_Socket_Data
* ����    : W5500���ղ����ͽ��յ�������
* ����    : s:�˿ں�
* ���    : ��
* ����ֵ  : ��
* ˵��    : �������ȵ���S_rx_process()��W5500�Ķ˿ڽ������ݻ�������ȡ����,
*			Ȼ�󽫶�ȡ�����ݴ�Rx_Buffer������Temp_Buffer���������д�����
*			������ϣ������ݴ�Temp_Buffer������Tx_Buffer������������S_tx_process()
*			�������ݡ�
*******************************************************************************/
void Process_Socket_Data(SOCKET s)
{
	unsigned short size;
	size=Read_SOCK_Data_Buffer(s, Rx_Buffer);
	memcpy(Tx_Buffer, Rx_Buffer, size);			
	Write_SOCK_Data_Buffer(s, Tx_Buffer, size);
}
void usart(void)
{
	   u16 t;  
			
		
	    //char buff[5] ={'R','S','T','\0'};
		if(USART_RX_STA&0x8000)
		{					   
			
			printf("\r\n send:  ");
			for(t=0;t< reciveNum;t++)
			{
				USART_SendData(USART1, USART_RX_BUF[t]);//�򴮿�1��������
				while(USART_GetFlagStatus(USART1,USART_FLAG_TC)!=SET);//�ȴ����ͽ���
				
			}
			sprintf( BuffSprintf,"(%d)", reciveNum );
			printf(BuffSprintf);
			if(reciveNum == 3)
			{
			   if(USART_RX_BUF[0] == 'R' && USART_RX_BUF[1] == 'S'&& USART_RX_BUF[2] == 'T' )
				{
					Key4.KeyShortDown_F =1;
					printf("  ---and run RST.");
				   
				}
				if(USART_RX_BUF[0] == 'N' && USART_RX_BUF[1] == 'M'&& USART_RX_BUF[2] == 'I' )
				{
					Key10.KeyShortDown_F =1;
					printf("  ---and run NMI.");
				}
				//printf("\r\n");//���뻻��
			}
			
			USART_RX_STA=0;
		}

}
 void AnalyzeCommand(void)
 {
//	unsigned short size =0; 
//	unsigned char *command ="hello\0"; 
//    size=Read_SOCK_Data_Buffer(0, Rx_Buffer);
//	memcpy(AnalyzeBuff, Rx_Buffer, size);
//	 AnalyzeBuff[size] ='\0';
//	 if(strcmp(AnalyzeBuff, command)==0)
//	 {
//	   Key3.KeyShortDown_F =1;
//	 }
//	 
 
 }
/*******************************************************************************
* ������  : main
* ����    : ���������û������main������ʼ����
* ����    : ��
* ���    : ��
* ����ֵ  : int:����ֵΪһ��16λ������
* ˵��    : ��
*******************************************************************************/
int main(void)
{
	System_Initialization();	//STM32ϵͳ��ʼ������(��ʼ��STM32ʱ�Ӽ�����)
	//Load_Net_Parameters();		//װ���������	
	//W5500_Hardware_Reset();		//Ӳ����λW5500
	//W5500_Initialization();		//W5500��ʼ������
	uart_init(9600);	 //���ڳ�ʼ��Ϊ115200
	LED_Init();
	InitKey();
	InitTaskStr();
	IWDG_Init(4,625);
     
	Key1.KeyShortDown_F =1;
	printf("\r\n start version 3!\r\n");
	while (1)
	{
		ServeDelay();
	
		KeyServe();
		Task3(&F_DelayStr_Exam3,&Task3Infor,&Key3);

		Task11(&F_DelayStr_Exam11,&Task11Infor);
		 usart();

		if(g_sem_self ==1)
		{
			Task1(&F_DelayStr_Exam1,&Task1Infor,&Key1);
			Task2(&F_DelayStr_Exam2,&Task2Infor,&Key1);
			Task4(&F_DelayStr_Exam4,&Task4Infor,&Key5); //
			Task10(&F_DelayStr_Exam10,&Task10Infor,&Key6); //

		}else {

		Task5(&F_DelayStr_Exam5,&Task5Infor,&Key5); // ��
		Task6(&F_DelayStr_Exam6,&Task6Infor,&Key6); // ��
		Task7(&F_DelayStr_Exam7,&Task7Infor,&Key7); // ��
		Task8(&F_DelayStr_Exam8,&Task8Infor,&Key8); //
		Task9(&F_DelayStr_Exam9,&Task9Infor,&Key9); //



		}
		

		Task4(&F_DelayStr_Exam4,&Task4Infor,&Key4); //
		Task10(&F_DelayStr_Exam10,&Task10Infor,&Key10); //

		
		
	}
}

/*******************************************************************************
* ������  : RCC_Configuration
* ����    : ����ϵͳʱ��Ϊ72MHZ(������Ը�����Ҫ��)
* ����    : ��
* ���    : ��
* ����ֵ  : ��
* ˵��    : STM32F107x��STM32F105xϵ��MCU��STM32F103xϵ��MCUʱ������������ͬ
*******************************************************************************/
void RCC_Configuration(void)
{
  ErrorStatus HSEStartUpStatus;               //�ⲿ����ʱ��(HSE)�Ĺ���״̬����
  
  RCC_DeInit();                               //��������ʱ����صļĴ�������ΪĬ��ֵ
  RCC_HSEConfig(RCC_HSE_ON);                  //�����ⲿ����ʱ��HSE 
  HSEStartUpStatus = RCC_WaitForHSEStartUp(); //�ȴ��ⲿ����ʱ��(HSE)�ȶ�

  if(SUCCESS == HSEStartUpStatus)             //����ⲿ����ʱ���Ѿ��ȶ�
  {
    /* Enable Prefetch Buffer */
    FLASH_PrefetchBufferCmd(FLASH_PrefetchBuffer_Enable); //Flash����
    /* Flash 2 wait state */
    FLASH_SetLatency(FLASH_Latency_2);
    
  
    RCC_HCLKConfig(RCC_SYSCLK_Div1); //����AHBʱ�ӵ���ϵͳʱ��(1��Ƶ)/72MHZ
    RCC_PCLK2Config(RCC_HCLK_Div1);  //����APB2ʱ�Ӻ�HCLKʱ�����/72MHz(���Ϊ72MHz)
    RCC_PCLK1Config(RCC_HCLK_Div2);  //����APB1ʱ����HCLKʱ�ӵ�2��Ƶ/36MHz(���Ϊ36MHz)
  
#ifndef STM32F10X_CL                 //���ʹ�õĲ���STM32F107x��STM32F105xϵ��MCU,PLL��������  
    RCC_PLLConfig(RCC_PLLSource_HSE_Div1, RCC_PLLMul_9); //PLLCLK = 8MHz * 9 = 72 MHz 
#else                                //���ʹ�õ���STM32F107x��STM32F105xϵ��MCU,PLL��������
    /***** ����PLLx *****/
    /* PLL2 configuration: PLL2CLK = (HSE / 5) * 8 = 40 MHz */
    RCC_PREDIV2Config(RCC_PREDIV2_Div5);
    RCC_PLL2Config(RCC_PLL2Mul_8);

    RCC_PLL2Cmd(ENABLE); //ʹ��PLL2 
    while (RCC_GetFlagStatus(RCC_FLAG_PLL2RDY) == RESET);//�ȴ�PLL2�ȶ�

    /* PLL configuration: PLLCLK = (PLL2 / 5) * 9 = 72 MHz */ 
    RCC_PREDIV1Config(RCC_PREDIV1_Source_PLL2, RCC_PREDIV1_Div5);
    RCC_PLLConfig(RCC_PLLSource_PREDIV1, RCC_PLLMul_9);
#endif

    RCC_PLLCmd(ENABLE); //ʹ��PLL
    while(RCC_GetFlagStatus(RCC_FLAG_PLLRDY) == RESET); //�ȴ�PLL�ȶ�

    RCC_SYSCLKConfig(RCC_SYSCLKSource_PLLCLK);          //����ϵͳʱ�ӵ�ʱ��ԴΪPLL

    while(RCC_GetSYSCLKSource() != 0x08);               //���ϵͳ��ʱ��Դ�Ƿ���PLL
    RCC_ClockSecuritySystemCmd(ENABLE);                 //ʹ��ϵͳ��ȫʱ�� 

	/* Enable peripheral clocks --------------------------------------------------*/
  	/* Enable I2C1 and I2C1 clock */
 	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);

  	/* Enable GPIOA GPIOB SPI1 and USART1 clocks */
  	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA | RCC_APB2Periph_GPIOB
					| RCC_APB2Periph_GPIOC | RCC_APB2Periph_GPIOD
					| RCC_APB2Periph_AFIO, ENABLE);    
  }
}

/*******************************************************************************
* ������  : NVIC_Configuration
* ����    : STM32�ж�������������
* ����    : ��
* ���    : ��
* ����ֵ  : ��
* ˵��    : ����KEY1(PC11)���ж�������
*******************************************************************************/
void NVIC_Configuration(void)
{
	NVIC_InitTypeDef NVIC_InitStructure;						//����NVIC��ʼ���ṹ��

  	/* Set the Vector Table base location at 0x08000000 */
  	NVIC_SetVectorTable(NVIC_VectTab_FLASH, 0x0);
	
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);				//�����ж����ȼ���Ϊ1��������(����0��4λ)
	
	NVIC_InitStructure.NVIC_IRQChannel = TIM2_IRQn;				//�����ж�������
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;	//�����������ȼ�
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;			//������Ӧ���ȼ�
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;				//ʹ��NVIC
	NVIC_Init(&NVIC_InitStructure);
}

/*******************************************************************************
* ������  : Timer2_Init_Config
* ����    : Timer2��ʼ������
* ����    : ��
* ���    : ��
* ����    : �� 
* ˵��    : ��
*******************************************************************************/
void Timer2_Init_Config(void)
{
	TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;
	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);		//ʹ��Timer2ʱ��
	
	TIM_TimeBaseStructure.TIM_Period = 9;						//��������һ�������¼�װ�����Զ���װ�ؼĴ������ڵ�ֵ(������10Ϊ1ms)
	TIM_TimeBaseStructure.TIM_Prescaler = 7199;					//����������ΪTIMxʱ��Ƶ�ʳ�����Ԥ��Ƶֵ(10KHz�ļ���Ƶ��)
	TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1;		//����ʱ�ӷָ�:TDTS = TIM_CKD_DIV1
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;	//TIM���ϼ���ģʽ
	TIM_TimeBaseInit(TIM2, &TIM_TimeBaseStructure);				//����TIM_TimeBaseInitStruct��ָ���Ĳ�����ʼ��TIMx��ʱ�������λ
	 
	TIM_ITConfig(TIM2, TIM_IT_Update, ENABLE ); 				//ʹ��TIM2ָ�����ж�
	
	TIM_Cmd(TIM2, ENABLE);  									//ʹ��TIMx����
}

/*******************************************************************************
* ������  : TIM2_IRQHandler
* ����    : ��ʱ��2�ж϶Ϸ�����
* ����    : ��
* ���    : ��
* ����    : �� 
* ˵��    : ��
*******************************************************************************/
void TIM2_IRQHandler(void)
{
	if(TIM_GetITStatus(TIM2, TIM_IT_Update) == SET)
	{
		TIM_ClearITPendingBit(TIM2, TIM_IT_Update);
		Timer2_Counter++;
		//W5500_Send_Delay_Counter++;
		G_TimerCnt_DelayServe_10MS++;
		G_TimerCnt_KeyServe_10MS ++;
	}
}

/*******************************************************************************
* ������  : System_Initialization
* ����    : STM32ϵͳ��ʼ������(��ʼ��STM32ʱ�Ӽ�����)
* ����    : ��
* ���    : ��
* ����    : �� 
* ˵��    : ��
*******************************************************************************/
void System_Initialization(void)
{
	RCC_Configuration();		//����ϵͳʱ��Ϊ72MHZ(������Ը�����Ҫ��)
  	NVIC_Configuration();		//STM32�ж�������������
	SPI_Configuration();		//W5500 SPI��ʼ������(STM32 SPI1)
	Timer2_Init_Config();		//Timer2��ʼ������
	W5500_GPIO_Configuration();	//W5500 GPIO��ʼ������	
}

/*******************************************************************************
* ������  : Delay
* ����    : ��ʱ����(ms)
* ����    : d:��ʱϵ������λΪ����
* ���    : ��
* ����    : �� 
* ˵��    : ��ʱ������Timer2��ʱ��������1����ļ�����ʵ�ֵ�
*******************************************************************************/
void Delay(unsigned int d)
{
	Timer2_Counter=0; 
	while(Timer2_Counter < d);
}