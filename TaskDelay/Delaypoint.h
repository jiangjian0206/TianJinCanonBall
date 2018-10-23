/******************************************************************************

                  版权所有 (C), 2015.9.6,  电子工程师
******************************************************************************

*-----------------移植性评估及说明 -----------------------------*

使用如下：
 1.定义全局变量：F_DelayStr_Exam1,以及头文件。
 2.中断处理函数：调用 DelayServe 10ms更新一次结构体数据。
 3.
		void Task9(TypeDelayStr *P_DelayStr,DefStrTask *P_StateTask)
		{

			switch(P_StateTask->TaskState)
			{
        case 1:
						IO_Test =0;
            InitDelay(P_DelayStr,100,2,&P_StateTask->TaskState);
            break;
        case 2:
            IO_Test =1;
            InitDelay(P_DelayStr,100,1,&P_StateTask->TaskState);
            break;
        case 100:
            WaitingDelay(P_DelayStr,&P_StateTask->TaskState);
            break;
        default:break;    
    
           }
		}

*-------------------外部变量说明---------------------------*

//
 //
******************************************************************************/
#ifndef __DELAY_H__
#define __DELAY_H__


#ifdef __cplusplus
#if __cplusplus
extern "C"{
#endif
#endif /* __cplusplus */

//#include "stm32f10x.h"




#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */
#ifndef uShotType
#define uShotType

typedef unsigned char 	u8;
//typedef unsigned int	  u16;
typedef unsigned char 	uchar;
typedef unsigned int	  uint;

#endif

typedef  struct F_DelayStr
{
   unsigned int   F_Delay_10Ms;  //延时
   unsigned int   GI_Cnt;
   unsigned int   DelayTimes_MS ;
   unsigned int   GC_StateNext ;
}TypeDelayStr;

extern volatile uint  G_TimerCnt_DelayServe_10MS;
extern void InitDelay(TypeDelayStr *P_TypeDelayStr_Exam1,unsigned int Delay_ms ,u8 NextState,uchar *P_UseState);
extern void WaitingDelay(TypeDelayStr *P_TypeDelayStr_ExamPram,uchar *P_UseState);
extern void InitDelay_01(TypeDelayStr *P_TypeDelayStr_Exam1,unsigned int Delay_ms ,u8 NextState,uchar *P_UseState);

//part2


//part2
extern TypeDelayStr F_DelayStr_Exam1;
extern TypeDelayStr F_DelayStr_Exam2;
extern TypeDelayStr F_DelayStr_Exam3;
extern TypeDelayStr F_DelayStr_Exam4,F_DelayStr_Exam5,F_DelayStr_Exam6,F_DelayStr_Exam7,F_DelayStr_Exam8,F_DelayStr_Exam9,\
	F_DelayStr_Exam10,F_DelayStr_Exam11,\
	F_DelayStr_Exam12,F_DelayStr_Exam13,F_DelayStr_Exam14,F_DelayStr_Exam15;


extern void DelayUpdata(TypeDelayStr *P_TypeDelayStr);
extern void ServeDelay(void);


#endif /* __DELAY_H__ */
