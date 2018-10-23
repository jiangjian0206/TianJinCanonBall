/******************************************************************************

                  版权所有 (C), 2015.9.6,   江剑电子工程师

 ******************************************************************************



******************************************************************************

*-----------------移植性评估及说明 -----------------------------*

 //
 //

*-------------------外部变量说明---------------------------*

//
 //
******************************************************************************/
#include <key.h>
#include <keyConfig.h>

StrKeyClass Key1, Key2,Key3,Key4,Key5,Key6, Key7,Key8,Key9,Key10,Key11, Key12,Key13,Key14,Key15;
StrKeyClass LeftSensor_Push,LeftSensor_Pull,RightSensor_Push,RightSensor_Pull,BehindSensor_Push,BehindSensor_Pull;
StrKeyClass Riser1Sensor_Push,Riser1Sensor_Pull,Riser2Sensor_Push,Riser2Sensor_Pull;


volatile unsigned int  G_TimerCnt_KeyServe_10MS =0;

#define ScanIO(read_IO_down,read_IO_up,CLASS_KEY)  if((read_IO_down) )CLASS_KEY.TimeCnt_Key_Down >250?CLASS_KEY.TimeCnt_Key_Down =200:CLASS_KEY.TimeCnt_Key_Down++;\
			else CLASS_KEY.TimeCnt_Key_Down =0;\
	if((read_IO_up)) CLASS_KEY.TimeCnt_Key_Up >250?CLASS_KEY.TimeCnt_Key_Up =200:CLASS_KEY.TimeCnt_Key_Up++;\
			else CLASS_KEY.TimeCnt_Key_Up =0;

void KeyServe(void)
{

  if(G_TimerCnt_KeyServe_10MS >=10)
	{

    G_TimerCnt_KeyServe_10MS =0;
	//key1 
	if(ReadKey_Down_01 && ReadKey_Down_02 && ReadRoute_Down_01 ) Key1.TimeCnt_Key_Down >250?Key1.TimeCnt_Key_Down =200:Key1.TimeCnt_Key_Down++;
			else Key1.TimeCnt_Key_Down =0;
	if(ReadKey_Up_01 && ReadKey_Up_02) Key1.TimeCnt_Key_Up >250?Key1.TimeCnt_Key_Up =200:Key1.TimeCnt_Key_Up++;
			else Key1.TimeCnt_Key_Up =0;
	
	//key2  进
	if( ReadKey_Down_02 && ReadRoute_Down_02 )Key2.TimeCnt_Key_Down>250?Key2.TimeCnt_Key_Down=200:Key2.TimeCnt_Key_Down++;
			else Key2.TimeCnt_Key_Down =0;
	if(ReadKey_Up_02) Key2.TimeCnt_Key_Up++;
			else Key2.TimeCnt_Key_Up =0;
	if(ReadRoute_up_02) Key2.TimeCnt_KeyLoosen_Up >250?Key2.TimeCnt_KeyLoosen_Up =200:Key2.TimeCnt_KeyLoosen_Up++;
			else Key2.TimeCnt_KeyLoosen_Up =0;


	if( ReadKey_Down_03  )Key3.TimeCnt_Key_Down>250?Key3.TimeCnt_Key_Down=200:Key3.TimeCnt_Key_Down++;
			else Key3.TimeCnt_Key_Down =0;
	if(ReadKey_Up_03) Key3.TimeCnt_Key_Up++;
			else Key3.TimeCnt_Key_Up =0;	
	
			
	//key4
	if(ReadKey_Down_04 && ReadRoute_Down_04 ) Key4.TimeCnt_Key_Down >250?Key4.TimeCnt_Key_Down =200:Key4.TimeCnt_Key_Down++;
			else Key4.TimeCnt_Key_Down =0;
	if(ReadKey_Up_04  ) Key4.TimeCnt_Key_Up >250?Key4.TimeCnt_Key_Up =200:Key4.TimeCnt_Key_Up++;
			else Key4.TimeCnt_Key_Up =0;
	if(ReadRoute_up_04) Key4.TimeCnt_KeyLoosen_Up >250?Key4.TimeCnt_KeyLoosen_Up =200:Key4.TimeCnt_KeyLoosen_Up++;
			else Key4.TimeCnt_KeyLoosen_Up =0;
			
	//key5 ReadKey_Down_05 && ReadRoute_Down_05  
//	if(Readmannul_Down_key_01) Key5.TimeCnt_Key_Down >250?Key5.TimeCnt_Key_Down =200:Key5.TimeCnt_Key_Down++;
//			else Key5.TimeCnt_Key_Down =0;
//	if(Readmannul_Up_key_01  ) Key5.TimeCnt_Key_Up >250?Key5.TimeCnt_Key_Up =200:Key5.TimeCnt_Key_Up++;
//			else Key5.TimeCnt_Key_Up =0;
	 ScanIO(Readmannul_Down_key_01,Readmannul_Up_key_01,Key5);
			
	//key6
	//if(Readmannul_Down_key_02) Key6.TimeCnt_Key_Down >250?Key6.TimeCnt_Key_Down =200:Key6.TimeCnt_Key_Down++;
			//else Key6.TimeCnt_Key_Down =0;
	//if(Readmannul_Up_key_02  ) Key6.TimeCnt_Key_Up >250?Key6.TimeCnt_Key_Up =200:Key6.TimeCnt_Key_Up++;
			//else Key6.TimeCnt_Key_Up =0;
	ScanIO(Readmannul_Down_key_02,Readmannul_Up_key_02,Key6);

			
	//key7
	if(Readmannul_Down_key_03 ) Key7.TimeCnt_Key_Down >250?Key7.TimeCnt_Key_Down =200:Key7.TimeCnt_Key_Down++;
			else Key7.TimeCnt_Key_Down =0;
	if(Readmannul_Up_key_03  ) Key7.TimeCnt_Key_Up >250?Key7.TimeCnt_Key_Up =200:Key7.TimeCnt_Key_Up++;
			else Key7.TimeCnt_Key_Up =0;

			
	//key8
	if(Readmannul_Down_key_04 ) Key8.TimeCnt_Key_Down >250?Key8.TimeCnt_Key_Down =200:Key8.TimeCnt_Key_Down++;
			else Key8.TimeCnt_Key_Down =0;
	if(Readmannul_Up_key_04 ) Key8.TimeCnt_Key_Up >250?Key8.TimeCnt_Key_Up =200:Key8.TimeCnt_Key_Up++;
			else Key8.TimeCnt_Key_Up =0;
	
			
	//key9
	if(Readmannul_Down_key_05 ) Key9.TimeCnt_Key_Down >250?Key9.TimeCnt_Key_Down =200:Key9.TimeCnt_Key_Down++;
			else Key9.TimeCnt_Key_Down =0;
	if(Readmannul_Up_key_05  ) Key9.TimeCnt_Key_Up >250?Key9.TimeCnt_Key_Up =200:Key9.TimeCnt_Key_Up++;
			else Key9.TimeCnt_Key_Up =0;
	

			
	//sener left push.
	if(ReadSensor_left_push_down ) LeftSensor_Push.TimeCnt_Key_Down >250?LeftSensor_Push.TimeCnt_Key_Down =200:LeftSensor_Push.TimeCnt_Key_Down++;
			else LeftSensor_Push.TimeCnt_Key_Down =0;
	if(ReadSensor_left_push_up) LeftSensor_Push.TimeCnt_Key_Up >250?LeftSensor_Push.TimeCnt_Key_Up =200:LeftSensor_Push.TimeCnt_Key_Up++;
			else LeftSensor_Push.TimeCnt_Key_Up =0;
	
    ScanIO(ReadSensor_left_pull_down,ReadSensor_left_pull_up,LeftSensor_Pull);
	
	ScanIO(ReadSensor_right_push_down,ReadSensor_right_push_up,RightSensor_Push);
	ScanIO(ReadSensor_right_pull_down,ReadSensor_right_pull_up,RightSensor_Pull);
	
	ScanIO(ReadSensor_behind_push_down,ReadSensor_behind_push_up,BehindSensor_Push);
	ScanIO(ReadSensor_behind_pull_down,ReadSensor_behind_pull_up,BehindSensor_Pull);
	
	ScanIO(ReadSensor_riser1_push_down,ReadSensor_riser1_push_up,Riser1Sensor_Push);
	ScanIO(ReadSensor_riser1_pull_down,ReadSensor_riser1_pull_up,Riser1Sensor_Pull);
	
	ScanIO(ReadSensor_riser2_push_down,ReadSensor_riser2_push_up,Riser2Sensor_Push);
	ScanIO(ReadSensor_riser2_pull_down,ReadSensor_riser2_pull_up,Riser2Sensor_Pull);
			
	//key3
//	if(ReadKey3Down) Key3.TimeCnt_Key_Down >250?Key3.TimeCnt_Key_Down =250:Key3.TimeCnt_Key_Down++;
//			else Key3.TimeCnt_Key_Down =0;
//	if(ReadKey3Up) Key3.TimeCnt_Key_Up++;
//			else Key3.TimeCnt_Key_Up =0;			
		
  }
   KeyUpdataSpeed(&Key1); 
   KeyUpdataSpeed(&Key2);
   KeySelf(&Key3);
   KeyUpdataSpeed(&Key4);
   KeyUpdataSpeed(&Key5);
   KeyUpdataSpeed(&Key6);
   KeyUpdataSpeed(&Key7);
   KeyUpdataSpeed(&Key8);
   KeyUpdataSpeed(&Key9);
   KeyUpdataSpeed(&Key10);
   KeyUpdataSpeed(&Key11);
   KeyUpdataSpeed(&Key12);
   KeyUpdataSpeed(&Key13);
   KeyUpdataSpeed(&Key14);

   KeySenser(&LeftSensor_Push);
   KeySenser(&LeftSensor_Pull);
   KeySenser(&RightSensor_Push);
   KeySenser(&RightSensor_Pull);

   KeySenser(&BehindSensor_Push);
   KeySenser(&BehindSensor_Pull);
   KeySenser(&Riser1Sensor_Push);
   KeySenser(&Riser1Sensor_Pull);
   KeySenser(&Riser2Sensor_Push);
   KeySenser(&Riser2Sensor_Pull);
   
   	
}
void InitKeyClassInfor(StrKeyClass *P_KeyClass)
{
   
		P_KeyClass->KeyLockBit =0;
		P_KeyClass->KeyLongDown_F =0;
		P_KeyClass->KeyShortDown_F =0;
		P_KeyClass->KeyUp_F =0;
		P_KeyClass->KeyKeepUp_F =0;
		
		P_KeyClass->KeyState =1;
		P_KeyClass->KeyStateLock =0;
		P_KeyClass->TimeCnt_Key_Down =0;
		P_KeyClass->TimeCnt_Key_Up =0;
		P_KeyClass->TimeCnt_Key_TwoUp =0;
}

void InitKey(void)
{
     InitKeyClassInfor(&Key1);
	 InitKeyClassInfor(&Key2);
	 InitKeyClassInfor(&Key3);
	 InitKeyClassInfor(&Key4);
	 InitKeyClassInfor(&Key5);
	 InitKeyClassInfor(&Key6);
	 InitKeyClassInfor(&Key7);
	 InitKeyClassInfor(&Key8);
	 InitKeyClassInfor(&Key9);
	 InitKeyClassInfor(&Key10);
	 InitKeyClassInfor(&Key11);
	 InitKeyClassInfor(&Key12);
	 InitKeyClassInfor(&Key13);
	 InitKeyClassInfor(&Key14);
	 InitKeyClassInfor(&Key15);

	 InitKeyClassInfor(&LeftSensor_Push);
	 InitKeyClassInfor(&LeftSensor_Pull);
	 InitKeyClassInfor(&RightSensor_Pull);
	 InitKeyClassInfor(&RightSensor_Push);
	 InitKeyClassInfor(&BehindSensor_Pull);
	 InitKeyClassInfor(&BehindSensor_Push);
	 
	 InitKeyClassInfor(&Riser2Sensor_Pull);
	 InitKeyClassInfor(&Riser2Sensor_Push);
	 InitKeyClassInfor(&Riser1Sensor_Pull);
	 InitKeyClassInfor(&Riser1Sensor_Push);

}

//整体概况:先判断是否按下，如果有则判断是否在3s内抬起，有则是短按键，持续3s则判断长按；
//
//
//
void KeyUpdata(StrKeyClass *P_KeyClass)
{

	switch ( (*P_KeyClass).KeyState )
	{
	    case 1 :  //按键按下；
			
			 if((*P_KeyClass).TimeCnt_Key_Down>5)
			 	{
					(*P_KeyClass).KeyState =2;
					(*P_KeyClass).KeyStateLock =0;
				}
	
	        break;
		case 2:
	
			if((*P_KeyClass).TimeCnt_Key_Down >300 && keyLongEnable)    // 长按键 ,推进，需要加锁；
				{
					//if(KeyLock <0x003f)
					{
					  //长按键处理部分
					  (*P_KeyClass).KeyState =4;
					  (*P_KeyClass).KeyLongDown_F =1;
					  (*P_KeyClass).KeyStateLock |= 0x01; 
						
					}			
					
				}
			//没有到达300 按键抬起，则判断短按；
			 if((*P_KeyClass).TimeCnt_Key_Up >4)
			 {

                (*P_KeyClass).KeyState =3;
			 }
			break;
		case 3://短按键处理标志
       
		    (*P_KeyClass).KeyShortDown_F =1;
			(*P_KeyClass).KeyState =1;
			break;
		case 4:
			
      if((*P_KeyClass).TimeCnt_Key_Up >4)
			 {

				(*P_KeyClass).KeyState =1;
			 }
			break;
		case 100:
           // WaitingDelay(&F_DelayStr_Key1,&state);
            break;
	    default:
	        break;
	}
   

}

//按键扫描更改，实现按键按下去 就触发事件，不需要等待抬起。抬起后也触发一个up事件。
void KeyUpdataSpeed(StrKeyClass *P_KeyClass)
{

	switch ( (*P_KeyClass).KeyState )
	{
	    case 1 :  //按键按下；
			
			 if((*P_KeyClass).TimeCnt_Key_Down>3)
			 	{
					(*P_KeyClass).KeyState =2;
					(*P_KeyClass).KeyStateLock =0;
					(*P_KeyClass).KeyShortDown_F =1;
					(*P_KeyClass).KeyUp_F =0;
					//(*P_KeyClass).KeyKeepUp_F =0;
				}
			  if((*P_KeyClass).TimeCnt_Key_Up >3)
			  	{
					(*P_KeyClass).KeyKeepUp_F =1;			

			  }
			 //Key1.KeyLoosen_F
			 if((*P_KeyClass).TimeCnt_KeyLoosen_Up	>2)
			 	{
					(*P_KeyClass).KeyLoosen_F =1;
			 }
	        break;
		case 2:
	
			
			//没有到达300 按键抬起，则判断短按；
			 if((*P_KeyClass).TimeCnt_Key_Up >3)
			 {

                (*P_KeyClass).KeyState =3;
				
				(*P_KeyClass).KeyUp_F =1;
				(*P_KeyClass).KeyKeepUp_F =1;			
			 }
			 
			  if((*P_KeyClass).TimeCnt_KeyLoosen_Up	>2)
			 	{
					(*P_KeyClass).KeyLoosen_F =1;
			 }
			break;
		case 3://短按键处理标志
       
		   
			(*P_KeyClass).KeyState =1;
			break;
		case 4:
			

			break;
		case 100:
           // WaitingDelay(&F_DelayStr_Key1,&state);
            break;
	    default:
	        break;
	}
   

}


//按键扫描更改，实现按键按下去 就触发事件，不需要等待抬起。抬起后也触发一个up事件。
void KeySenser(StrKeyClass *P_KeyClass)
{

	switch ( (*P_KeyClass).KeyState )
	{
	    case 1 :  //按键按下；
			
			 if((*P_KeyClass).TimeCnt_Key_Down>3)
			 	{
					(*P_KeyClass).KeyState =1;
					(*P_KeyClass).KeyStateLock =0;
					(*P_KeyClass).KeyShortDown_F =1;
					(*P_KeyClass).KeyUp_F =0;
				}
			  
			 
	        break;
		
		case 100:
           // WaitingDelay(&F_DelayStr_Key1,&state);
            break;
	    default:
	        break;
	}
   

}

void KeySelf(StrKeyClass *P_KeyClass)
{

	switch ( (*P_KeyClass).KeyState )
	{
	    case 1 :  //按键按下；
			
			 if((*P_KeyClass).TimeCnt_Key_Down>10)
			 	{
					
					
					(*P_KeyClass).KeyShortDown_F =1;
					(*P_KeyClass).KeyKeepUp_F =0;
					(*P_KeyClass).KeyState =2;
					//(*P_KeyClass).KeyUp_F =0;
					//(*P_KeyClass).KeyKeepUp_F =0;
				}
			  if((*P_KeyClass).TimeCnt_Key_Up >10)
			  	{
					(*P_KeyClass).KeyKeepUp_F =1;	
					(*P_KeyClass).KeyShortDown_F =0;
						(*P_KeyClass).KeyState =3;
			  }
			
	        break;
		case 2:
			if((*P_KeyClass).TimeCnt_Key_Up >10)
			{
				(*P_KeyClass).KeyState =1;
				res();

			}
			break;

		case 3:
			 if((*P_KeyClass).TimeCnt_Key_Down>10)
			 	{
				
				(*P_KeyClass).KeyState =1;
				res();
			 }
			break;
		
		case 100:
           // WaitingDelay(&F_DelayStr_Key1,&state);
            break;
	    default:
	        break;
	}
   

}


