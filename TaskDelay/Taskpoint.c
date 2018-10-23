
#include "Taskpoint.h"
#include "stm32f10x_gpio.h"
#include "key.h"
#include "TaskConfig.h"
#include "stdio.h"
#include  <led.h>
//#include "usart.h"


DefStrTask Task1Infor ;
DefStrTask Task2Infor ;
DefStrTask Task3Infor ;
DefStrTask Task4Infor ;
DefStrTask Task5Infor ;
DefStrTask Task6Infor ;
DefStrTask Task7Infor ;
DefStrTask Task8Infor ;
DefStrTask Task9Infor ;
DefStrTask Task10Infor ;

DefStrTask Task11Infor ;
DefStrTask Task12Infor ;
DefStrTask Task13Infor ;
DefStrTask Task14Infor ;
DefStrTask Task15Infor ;

DefActions Actions_01;



#define TimeCy  850 
#define waitCy  600

uchar g_sem_self =0;


#define StopAndSwitch(time,next) InitDelay(P_DelayStr,time,next,&P_StateTask->TaskState); 


#define ReverLed GPIO_PinReverse(GPIOB,GPIO_Pin_13)
#define ReverUp  GPIO_PinReverse(GPIOA,GPIO_Pin_4)

DefSystemState G_SystemState;

#define ResetTask9 (Task9Infor.TaskState =1)
#define ResetState 1

uchar G_Sem_goback =1;
uchar G_Sem_goahead =0;

void InitTaskStr(void)
{

	Task1Infor.TaskState =ResetState;
	Task2Infor.TaskState =ResetState; 
	Task3Infor.TaskState =ResetState; 
	Task4Infor.TaskState =ResetState; 
	Task5Infor.TaskState =ResetState; 
	Task6Infor.TaskState =ResetState; 
	Task7Infor.TaskState =ResetState; 
	Task8Infor.TaskState =ResetState;   
	Task9Infor.TaskState =ResetState; 
	Task10Infor.TaskState =ResetState;

	Task11Infor.TaskState =ResetState;
	Task12Infor.TaskState =ResetState;  
	Task13Infor.TaskState =ResetState;
	Task14Infor.TaskState =ResetState;
	Task15Infor.TaskState =ResetState;
	

//	Actions_01.KeepDown_on =

  
  G_SystemState.RunState =InOver;
  G_SystemState.InOutState =1;
  G_SystemState.WhetherOpendoor =DonotOpen;
  G_SystemState.WhetherClose =DoesClose;
}

//goahead
void Task1(TypeDelayStr *P_DelayStr,DefStrTask *P_StateTask,StrKeyClass *CurKey)
{

 switch(P_StateTask->TaskState)
 {
        case 1://first time when system restart,first  get up once.
        //left  push,1
			if(CurKey->KeyShortDown_F == 1 && G_Sem_goahead ==1)
			{
			   
				CurKey->KeyShortDown_F = 0;
				DOWN_keep_leftPush;
				LeftSensor_Push.KeyShortDown_F =0;
				StopAndSwitch(waitCy,52);
			}
			break;
		case 52:
			LeftSensor_Push.KeyShortDown_F =0;
			StopAndSwitch(2,2);
			break;
		case 2:
			//left senser,and right push,2
			if(LeftSensor_Push.KeyShortDown_F ==1)
			{
			   DOWN_over_leftPush;
			   DOWN_keep_RightPush;
			   
			   StopAndSwitch(waitCy,53);
				
			}
		    
			break;
		case 53:
			RightSensor_Push.KeyShortDown_F =0;

			StopAndSwitch(2,3);
			break;	

		case 3://right sensor,and then behind push,3
		
			if( RightSensor_Push.KeyShortDown_F == 1)
			{

				DOWN_over_RightPush;
				DOWN_keep_BehindPush;
				
				StopAndSwitch(waitCy,54);
			}
			
			break;
		case 54:
			BehindSensor_Push.KeyShortDown_F =0;
			
			StopAndSwitch(2,4);
			break;	
		case 4://behind sensor,and then riser1 push.4
		    if(BehindSensor_Push.KeyShortDown_F ==1)
			{
			   
				DOWN_over_BehindPush;
				DOWN_keep_Riser01Push;
				
				StopAndSwitch(waitCy,55);
			}
			break;
		case 55:
			Riser1Sensor_Push.KeyShortDown_F =0;
			StopAndSwitch(2,5);

			break;	
		case 5://riser1 sensor,and then riser2 push;5
		    if(Riser1Sensor_Push.KeyShortDown_F ==1)
		    {
		       DOWN_over_Riser01Push;
			   DOWN_keep_Riser02Push;
			   Riser2Sensor_Push.KeyShortDown_F =0;
			   StopAndSwitch(waitCy,56);

			}

			
			break;	
		case 56:
			Riser2Sensor_Push.KeyShortDown_F =0;
			StopAndSwitch(2,6);

			break;
		case 6://total five action  run over.
		    if(Riser2Sensor_Push.KeyShortDown_F == 1)
		    {
			   DOWN_over_Riser02Push;
			   StopAndSwitch(2,7);
		    }
		   
			break;	
		case 7:
			G_Sem_goahead =0;
			G_Sem_goback =1;
			 StopAndSwitch(2,1);
			break;
		case 100:
			WaitingDelay(P_DelayStr,&P_StateTask->TaskState);
			break;
		case 101:
			//这个延时里面检测了
			WaitingDelay(P_DelayStr,&P_StateTask->TaskState);
			//if(CurKey->KeyLoosen_F ==1) P_StateTask->TaskState =102;
			break;	
		
		
		case 200://空闲状态，不运行。
			break;
		
		default:break;	
 
 }

}



//goback
void Task2(TypeDelayStr *P_DelayStr,DefStrTask *P_StateTask,StrKeyClass *CurKey)
{

 switch(P_StateTask->TaskState)
 {
        case 1://RISER2 get up;
			if(CurKey->KeyShortDown_F == 1 && G_Sem_goback ==1 )
			{
			   
				CurKey->KeyShortDown_F = 0;
				UP_keep_Riser02Pull;
				
				StopAndSwitch(waitCy,2);
			}
			break;

		case 2:

			Riser2Sensor_Pull.KeyShortDown_F =0;
			StopAndSwitch(2,3);
			
			break;
		case 3:
			if(Riser2Sensor_Pull.KeyShortDown_F ==1)
			{
			   UP_over_Riser02Pull;
			   UP_keep_Riser01Pull;
			   
			   StopAndSwitch(waitCy,4);
				
			}
		    
			break;
		case 4:
		    Riser1Sensor_Pull.KeyShortDown_F =0;
			StopAndSwitch(2,5);
			
			break;
		case 5:
			if(Riser1Sensor_Pull.KeyShortDown_F ==1)
			{
			   UP_keep_leftPull;
			   UP_over_Riser01Pull;
			   
			   StopAndSwitch(waitCy,6);
				
			}
			break;	
		case 6://
			
			 LeftSensor_Pull.KeyShortDown_F =0;
			StopAndSwitch(2,7);
			
			break;	
		case 7://
			if(LeftSensor_Pull.KeyShortDown_F ==1)
			{
			   UP_over_leftPull;
			   UP_keep_RightPull;
			   
			   StopAndSwitch(waitCy,8);
				
			}
			break;	
		case 8://	
			RightSensor_Pull.KeyShortDown_F =0;
			StopAndSwitch(2,9);
			break;	
		case 9:
			if(RightSensor_Pull.KeyShortDown_F ==1)
			{
			   UP_over_RightPull;
			   UP_keep_BehindPull;
			   
			   StopAndSwitch(waitCy,10);
				
			}
			break;
		case 10:
			BehindSensor_Pull.KeyShortDown_F =0;
			StopAndSwitch(2,11);
			break;
		case 11:
			if(BehindSensor_Pull.KeyShortDown_F ==1)
			{
				UP_over_BehindPull;
				StopAndSwitch(2,20);
			}	
			break;
		case 20:
			G_Sem_goahead =1;
			G_Sem_goback =0;
			StopAndSwitch(2,1);
			break;
		case 100:
			WaitingDelay(P_DelayStr,&P_StateTask->TaskState);
			break;
		case 101:
			//这个延时里面检测了
			WaitingDelay(P_DelayStr,&P_StateTask->TaskState);
			//if(CurKey->KeyLoosen_F ==1) P_StateTask->TaskState =102;
			break;	
		case 102://特殊情况处理。
			DOWN_over_05;
			UP_keep_05;
			GreenLed_Dark_05;
			StopAndSwitch(500,2);
			break;
		
		case 200://空闲状态，不运行。
			break;
		
		default:break;	
 
 }

}

//进
void Task3(TypeDelayStr *P_DelayStr,DefStrTask *P_StateTask,StrKeyClass *CurKey)
{

 switch(P_StateTask->TaskState)
 {
        case 1://first time when system restart,first  get up once.
			if(CurKey->KeyShortDown_F == 1)
			{
			   
				
				CurKey->KeyShortDown_F =0;
				g_sem_self =1;
				//StopAndSwitch(TimeCy,2);
			}else if(CurKey->KeyKeepUp_F== 1)
				{
					CurKey->KeyKeepUp_F=0;
					g_sem_self =0;
				} 
			break;

		case 2:

		    
			StopAndSwitch(5,11);
			break;
		
		case 6://	
			
			break;	
		case 100:
			WaitingDelay(P_DelayStr,&P_StateTask->TaskState);
			break;
		case 101:
			//这个延时里面检测了
			WaitingDelay(P_DelayStr,&P_StateTask->TaskState);
			if(CurKey->KeyLoosen_F ==1) P_StateTask->TaskState =102;
			break;	
		case 102://特殊情况处理。
			DOWN_over_03;
			UP_keep_03;
			GreenLed_Dark_03;
			StopAndSwitch(500,2);
			break;
		
		case 200://空闲状态，不运行。
			break;
		
		default:break;	
 
 }

}


//进
void Task4(TypeDelayStr *P_DelayStr,DefStrTask *P_StateTask,StrKeyClass *CurKey)
{

 switch(P_StateTask->TaskState)
 {
        case 1://first time when system restart,first  get up once.
			if(CurKey->KeyShortDown_F == 1)
			{
			   
				CurKey->KeyShortDown_F = 0;
				GPIO_SetBits(GPIOA,GPIO_Pin_8);
				
				StopAndSwitch(700,2);
			}
			break;

		case 2:

		    GPIO_ResetBits(GPIOA,GPIO_Pin_8);
			StopAndSwitch(5,4);
			break;
		case 11:
			GPIO_SetBits(GPIOC,GPIO_Pin_7);
			StopAndSwitch(700,3);
			break;
		case 3:
		     GPIO_ResetBits(GPIOC,GPIO_Pin_7);
			 StopAndSwitch(2,4);
			
			break;
		
		case 4://
			
			
			StopAndSwitch(50,1);
			CurKey->KeyShortDown_F = 0;
			break;	
		
		case 6://	
			
			break;	
		case 100:
			WaitingDelay(P_DelayStr,&P_StateTask->TaskState);
			break;
		case 101:
			//这个延时里面检测了
			WaitingDelay(P_DelayStr,&P_StateTask->TaskState);
			if(CurKey->KeyLoosen_F ==1) P_StateTask->TaskState =102;
			break;	
		case 102://特殊情况处理。
			DOWN_over_04;
			UP_keep_04;
			GreenLed_Dark_04;
			StopAndSwitch(500,2);
			break;
		
		case 200://空闲状态，不运行。
			break;
		
		default:break;	
 
 }

}



//手动 左推
void Task5(TypeDelayStr *P_DelayStr,DefStrTask *P_StateTask,StrKeyClass *CurKey)
{

 switch(P_StateTask->TaskState)
 {
        case 1://first time when system restart,first  get up once.
			if(CurKey->KeyShortDown_F == 1)
			{
			   
				CurKey->KeyShortDown_F = 0;
				DOWN_keep_leftPush;
				
				StopAndSwitch(TimeCy,2);
			}
			break;

		case 2:

		    DOWN_over_leftPush;
			StopAndSwitch(5,11);
			break;
		case 11:
			CurKey->KeyShortDown_F =0;
			StopAndSwitch(2,3);
			break;
		case 3:
		    if(CurKey->KeyShortDown_F ==1)
			{
			   
				CurKey->KeyShortDown_F =0;
				
				CurKey->KeyLoosen_F =0;
				UP_keep_leftPull;
				StopAndSwitch(2,103);
			}
			break;
		case 103:
			InitDelay_01(P_DelayStr,TimeCy,4,&P_StateTask->TaskState);
			break;	
		case 4://
			
			UP_over_leftPull;
			StopAndSwitch(50,5);
			
			break;	
		case 5://
			CurKey->KeyShortDown_F =0;
			StopAndSwitch(50,1);
			break;	
		case 6://	
			
			break;	
		case 100:
			WaitingDelay(P_DelayStr,&P_StateTask->TaskState);
			break;
		case 101:
			//这个延时里面检测了
			WaitingDelay(P_DelayStr,&P_StateTask->TaskState);
			//if(CurKey->KeyLoosen_F ==1) P_StateTask->TaskState =102;
			break;	
		case 102://特殊情况处理。
			DOWN_over_02;
			UP_keep_02;
			GreenLed_Dark_02;
			StopAndSwitch(500,2);
			break;
		
		case 200://空闲状态，不运行。
			break;
		
		default:break;	
 
 }

}


//behind push
void Task6(TypeDelayStr *P_DelayStr,DefStrTask *P_StateTask,StrKeyClass *CurKey)
{

 switch(P_StateTask->TaskState)
 {
        case 1://first time when system restart,first  get up once.
			if(CurKey->KeyShortDown_F == 1)
			{
			   
				CurKey->KeyShortDown_F = 0;
				DOWN_keep_BehindPush;
				StopAndSwitch(TimeCy,2);
			}
			break;

		case 2:

		    DOWN_over_BehindPush;
			StopAndSwitch(5,11);
			break;
		case 11:
			CurKey->KeyShortDown_F =0;
			StopAndSwitch(2,3);
			break;
		case 3:
		    if(CurKey->KeyShortDown_F ==1)
			{
			   
				CurKey->KeyShortDown_F =0;
				
				CurKey->KeyLoosen_F =0;
				UP_keep_BehindPull;
				StopAndSwitch(2,103);
			}
			break;
		case 103:
			InitDelay_01(P_DelayStr,TimeCy,4,&P_StateTask->TaskState);
			break;	
		case 4://
			
			UP_over_BehindPull;
			StopAndSwitch(50,5);
			
			break;	
		case 5://
			CurKey->KeyShortDown_F =0;
			StopAndSwitch(50,1);
			break;	
		case 6://	
			
			break;	
		case 100:
			WaitingDelay(P_DelayStr,&P_StateTask->TaskState);
			break;
		case 101:
			//这个延时里面检测了
			WaitingDelay(P_DelayStr,&P_StateTask->TaskState);
			//if(CurKey->KeyLoosen_F ==1) P_StateTask->TaskState =102;
			break;	
		case 102://特殊情况处理。
			DOWN_over_06;
			UP_keep_06;
			GreenLed_Dark_06;
			StopAndSwitch(500,2);
			break;
		
		case 200://空闲状态，不运行。
			break;
		
		default:break;	
 
 }

}


//right push
void Task7(TypeDelayStr *P_DelayStr,DefStrTask *P_StateTask,StrKeyClass *CurKey)
{

 switch(P_StateTask->TaskState)
 {
        case 1://first time when system restart,first  get up once.
			if(CurKey->KeyShortDown_F == 1)
			{
			   
				CurKey->KeyShortDown_F = 0;
				DOWN_keep_RightPush;
				StopAndSwitch(TimeCy,2);
			}
			break;

		case 2:

		    DOWN_over_RightPush;
			StopAndSwitch(5,11);
			break;
		case 11:
			CurKey->KeyShortDown_F =0;
			StopAndSwitch(2,3);
			break;
		case 3:
		    if(CurKey->KeyShortDown_F ==1)
			{
			   
				CurKey->KeyShortDown_F =0;
				
				CurKey->KeyLoosen_F =0;
				UP_keep_RightPull;
				StopAndSwitch(2,103);
			}
			break;
		case 103:
			InitDelay_01(P_DelayStr,TimeCy,4,&P_StateTask->TaskState);
			break;	
		case 4://
			
			UP_over_RightPull;
			StopAndSwitch(50,5);
			
			break;	
		case 5://
			CurKey->KeyShortDown_F =0;
			StopAndSwitch(50,1);
			break;	
		case 6://	
			
			break;	
		case 100:
			WaitingDelay(P_DelayStr,&P_StateTask->TaskState);
			break;
		case 101:
			//这个延时里面检测了
			WaitingDelay(P_DelayStr,&P_StateTask->TaskState);
			//if(CurKey->KeyLoosen_F ==1) P_StateTask->TaskState =102;
			break;	
		case 102://特殊情况处理。
			DOWN_over_07;
			UP_keep_07;
			GreenLed_Dark_07;
			StopAndSwitch(500,2);
			break;
		
		case 200://空闲状态，不运行。
			break;
		
		default:break;	
 
 }

}


//riser1
void Task8(TypeDelayStr *P_DelayStr,DefStrTask *P_StateTask,StrKeyClass *CurKey)
{

 switch(P_StateTask->TaskState)
 {
        case 1://first time when system restart,first  get up once.
			if(CurKey->KeyShortDown_F == 1)
			{
			   
				CurKey->KeyShortDown_F = 0;
				DOWN_keep_Riser01Push;
				StopAndSwitch(TimeCy,2);
			}
			break;

		case 2:

		    DOWN_over_Riser01Push;
			StopAndSwitch(5,11);
			break;
		case 11:
			CurKey->KeyShortDown_F =0;
			StopAndSwitch(2,3);
			break;
		case 3:
		    if(CurKey->KeyShortDown_F ==1)
			{
			   
				CurKey->KeyShortDown_F =0;
				
				CurKey->KeyLoosen_F =0;
				UP_keep_Riser01Pull;
				StopAndSwitch(2,103);
			}
			break;
		case 103:
			InitDelay_01(P_DelayStr,TimeCy,4,&P_StateTask->TaskState);
			break;	
		case 4://
			
			UP_over_Riser01Pull;
			StopAndSwitch(10,5);
			
			break;	
		case 5://
			CurKey->KeyShortDown_F =0;
			StopAndSwitch(10,1);
			break;	
		case 6://	
			
			break;	
		case 100:
			WaitingDelay(P_DelayStr,&P_StateTask->TaskState);
			break;
		case 101:
			//这个延时里面检测了
			WaitingDelay(P_DelayStr,&P_StateTask->TaskState);
			//if(CurKey->KeyLoosen_F ==1) P_StateTask->TaskState =102;
			break;	
		case 102://特殊情况处理。
			DOWN_over_08;
			UP_keep_08;
			GreenLed_Dark_08;
			StopAndSwitch(500,2);
			break;
		
		case 200://空闲状态，不运行。
			break;
		
		default:break;	
 
 }

}


//riser2
void Task9(TypeDelayStr *P_DelayStr,DefStrTask *P_StateTask,StrKeyClass *CurKey)
{

 switch(P_StateTask->TaskState)
 {
        case 1://first time when system restart,first  get up once.
			if(CurKey->KeyShortDown_F == 1)
			{
			   
				CurKey->KeyShortDown_F = 0;
				DOWN_keep_Riser02Push;
				StopAndSwitch(TimeCy,2);
			}
			break;

		case 2:

		    DOWN_over_Riser02Push;
			StopAndSwitch(5,11);
			break;
		case 11:
			CurKey->KeyShortDown_F =0;
			StopAndSwitch(2,3);
			break;
		case 3:
		    if(CurKey->KeyShortDown_F ==1)
			{
			   
				CurKey->KeyShortDown_F =0;
				
				CurKey->KeyLoosen_F =0;
				UP_keep_Riser02Pull;
				//GreenLed_Light_09;
				StopAndSwitch(2,103);
			}
			break;
		case 103:
			InitDelay_01(P_DelayStr,TimeCy,4,&P_StateTask->TaskState);
			break;	
		case 4://
			
			UP_over_Riser02Pull;
			StopAndSwitch(50,5);
			
			break;	
		case 5://
			CurKey->KeyShortDown_F =0;
			StopAndSwitch(50,1);
			break;	
		case 6://	
			
			break;	
		case 100:
			WaitingDelay(P_DelayStr,&P_StateTask->TaskState);
			break;
		case 101:
			//这个延时里面检测了
			WaitingDelay(P_DelayStr,&P_StateTask->TaskState);
			//if(CurKey->KeyLoosen_F ==1) P_StateTask->TaskState =102;
			break;	
		case 102://特殊情况处理。
			DOWN_over_09;
			UP_keep_09;
			GreenLed_Dark_09;
			StopAndSwitch(500,2);
			break;
		
		case 200://空闲状态，不运行。
			break;
		
		default:break;	
 
 }

}


//进
void Task10(TypeDelayStr *P_DelayStr,DefStrTask *P_StateTask,StrKeyClass *CurKey)
{

 switch(P_StateTask->TaskState)
 {case 1://first time when system restart,first  get up once.
			if(CurKey->KeyShortDown_F == 1)
			{
			   
				CurKey->KeyShortDown_F = 0;
				GPIO_SetBits(GPIOC,GPIO_Pin_9);
				
				StopAndSwitch(700,2);
			}
			break;

		case 2:

		    GPIO_ResetBits(GPIOC,GPIO_Pin_9);
			StopAndSwitch(5,4);
			break;
		case 11:
			GPIO_SetBits(GPIOC,GPIO_Pin_9);
			StopAndSwitch(700,3);
			break;
		case 3:
		     GPIO_ResetBits(GPIOC,GPIO_Pin_9);
			 StopAndSwitch(2,4);
			
			break;
		
		case 4://
			
			
			StopAndSwitch(50,1);
			 CurKey->KeyShortDown_F = 0;
			break;	
		
		case 100:
			WaitingDelay(P_DelayStr,&P_StateTask->TaskState);
			break;
		case 101:
			//这个延时里面检测了
			WaitingDelay(P_DelayStr,&P_StateTask->TaskState);
			if(CurKey->KeyLoosen_F ==1) P_StateTask->TaskState =102;
			break;	
		case 102://特殊情况处理。
			DOWN_over_10;
			UP_keep_10;
			GreenLed_Dark_10;
			StopAndSwitch(500,2);
			break;
		
		case 200://空闲状态，不运行。
			break;
		
		default:break;	
 
 }

}



//step by step,one red button .
void Task11(TypeDelayStr *P_DelayStr,DefStrTask *P_StateTask)
{

 switch(P_StateTask->TaskState)
 {
     case 1:
		// if(Key3.KeyShortDown_F ==1)
		 {
			//Key3.KeyShortDown_F = 0; 
			GPIO_ResetBits(GPIOB,GPIO_Pin_10);
			 IWDG_Feed();
			InitDelay(P_DelayStr,200,2,&P_StateTask->TaskState);
		 }
			
		
         break;
     case 2://**进

	    GPIO_SetBits(GPIOB,GPIO_Pin_10);
	      IWDG_Feed();
		InitDelay(P_DelayStr,200,1,&P_StateTask->TaskState);
		break;
	 case 3:
		  InitDelay(P_DelayStr,3,1,&P_StateTask->TaskState);
		  break;
     case 100:
         WaitingDelay(P_DelayStr,&P_StateTask->TaskState);
         break;
	case 200://空闲状态，不运行。
		break;
     default:break;    
 
 }
 

}

void res(void )
{
	__set_FAULTMASK(1); 
    NVIC_SystemReset();


}

