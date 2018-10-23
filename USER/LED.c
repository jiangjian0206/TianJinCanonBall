#include "stm32f10x.h"	

							  
////////////////////////////////////////////////////////////////////////////////// 	   
//初始化PB5和PE5为输出口.并使能这两个口的时钟		    
//LED IO初始化
void LED_Init(void)
{
 
 GPIO_InitTypeDef  GPIO_InitStructure;
 	
 RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO |RCC_APB2Periph_GPIOA |RCC_APB2Periph_GPIOB |\
 	RCC_APB2Periph_GPIOC |RCC_APB2Periph_GPIOD |RCC_APB2Periph_GPIOE |RCC_APB2Periph_GPIOF |RCC_APB2Periph_GPIOG, ENABLE);	 //使能PA,PB端口时钟

	
 //GPIOA configure out 			
 GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_8 ;
 GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;		
 GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
 GPIO_Init(GPIOA, &GPIO_InitStructure);

 GPIO_InitStructure.GPIO_Pin  = 0X000F ;
 GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;		
 GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
 GPIO_Init(GPIOA, &GPIO_InitStructure);

  //GPIOB configure out 	
 GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_8 | GPIO_Pin_9 | 0X000F | GPIO_Pin_4 | GPIO_Pin_7 |GPIO_Pin_3;
 GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;		
 GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
 GPIO_Init(GPIOB, &GPIO_InitStructure);	

 GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_10 | GPIO_Pin_11  | GPIO_Pin_12 | GPIO_Pin_13;
 GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;		
 GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
 GPIO_Init(GPIOB, &GPIO_InitStructure);	
 
 //GPIOC configure out 			
 GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_11 | GPIO_Pin_12 |GPIO_Pin_6 |GPIO_Pin_7 | GPIO_Pin_8 |GPIO_Pin_9;
 GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;		
 GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
 GPIO_Init(GPIOC, &GPIO_InitStructure);


 GPIO_InitStructure.GPIO_Pin  =  GPIO_Pin_15 | GPIO_Pin_14 |GPIO_Pin_13 |GPIO_Pin_0  ;
 GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;		
 GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
 GPIO_Init(GPIOC, &GPIO_InitStructure);
 //GPIOD configure out 			
 GPIO_InitStructure.GPIO_Pin  = 0xfcff;
 GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;		
 GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
 GPIO_Init(GPIOD, &GPIO_InitStructure);
 
// GPIO_SetBits(GPIOD,GPIO_Pin_5);
// GPIO_SetBits(GPIOD,GPIO_Pin_4);
// GPIO_SetBits(GPIOD,GPIO_Pin_3);
// GPIO_SetBits(GPIOD,GPIO_Pin_2);
// GPIO_SetBits(GPIOD,GPIO_Pin_1);
// GPIO_SetBits(GPIOD,GPIO_Pin_0);
 //GPIOE configure out 			
 GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_2 |GPIO_Pin_1 | GPIO_Pin_3 |GPIO_Pin_6 | GPIO_Pin_5 | GPIO_Pin_4 | GPIO_Pin_0;
 GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;		
 GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
 GPIO_Init(GPIOE, &GPIO_InitStructure);

  GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_10 | GPIO_Pin_11 |GPIO_Pin_12 | GPIO_Pin_13 |GPIO_Pin_14  |GPIO_Pin_15 ;
 GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;		
 GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
 GPIO_Init(GPIOE, &GPIO_InitStructure);
 
 //GPIOF configure out 			
 GPIO_InitStructure.GPIO_Pin  = 0XFFFF;
 GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;		
 GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
 GPIO_Init(GPIOF, &GPIO_InitStructure);
 
 //GPIOG configure out 			
 GPIO_InitStructure.GPIO_Pin  = 0x7fcc;
 GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;		
 GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
 GPIO_Init(GPIOG, &GPIO_InitStructure);

 GPIO_InitStructure.GPIO_Pin  = 0x8000;
 GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;		
 GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
 GPIO_Init(GPIOG, &GPIO_InitStructure);

 GPIO_PinRemapConfig(GPIO_Remap_SWJ_JTAGDisable, ENABLE); 
}

/**
 * ????????
 * prer:???:0~7(??? 3 ???!)
 * ????=4*2^prer.??????? 256!
 * rlr:???????:? 11 ???.
 * ????(??):Tout=((4*2^prer)*rlr)/40 (ms).
 */
void IWDG_Init(u8 prer,u16 rlr)
{
    IWDG_WriteAccessCmd(IWDG_WriteAccess_Enable); /* ??????IWDG_PR?IWDG_RLR????*/
    IWDG_SetPrescaler(prer);    /*??IWDG????:??IWDG????*/
    IWDG_SetReload(rlr);     /*??IWDG????*/
    IWDG_ReloadCounter();    /*??IWDG???????????IWDG???*/
    IWDG_Enable();        /*??IWDG*/
}
/**
 * ??????
 */
void IWDG_Feed(void)
{
    IWDG_ReloadCounter();    /*reload*/
}
 

