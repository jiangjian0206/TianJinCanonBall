#ifndef TaskDelayExter_h
#define TaskDelayExter_h
/*添加任务详细步骤：
第一步：TypeDelayStr F_DelayStr_Exam2;添加延时变量。
第二步： DelayUpdata(&F_DelayStr_Exam2);加入ServeDelay扫描服务函数里面。
第三步：DefStrTask Task2Infor ;添加任务里面的变量。
第四步：Task2Infor.TaskState =1;添加到InitTaskStr任务初始化里面，初始化状态。
第五步：void Task2(TypeDelayStr *P_DelayStr,DefStrTask *P_StateTask)添加任务处理函数。
大功告成。

遗留问题点：移植的时候任务实现要加入外部定义，降低了可移植性。后期更改，比如：#include "stm32f10x_gpio.h"使用端口函数等等。
现在移植步骤：main添加：中断变量时钟计数，和一下函数：
InitTaskStr();
ServeDelay();
Task2(&F_DelayStr_Exam2,&Task2Infor);
编辑时间：2017年11月10日
*/
#include "Taskpoint.h"
#include <key.h>

extern volatile unsigned int  G_TimerCnt_DelayServe_10MS;
extern	DefStrTask Task1Infor ;
extern	DefStrTask Task2Infor ;
extern	DefStrTask Task3Infor ;
extern	DefStrTask Task4Infor ;
extern	DefStrTask Task5Infor ;
extern	DefStrTask Task6Infor ;
extern	DefStrTask Task7Infor ;
extern	DefStrTask Task8Infor ;
extern	DefStrTask Task9Infor ;
extern	DefStrTask Task10Infor ;

extern	DefStrTask Task11Infor ;
extern	DefStrTask Task12Infor ;
extern	DefStrTask Task13Infor ;
extern	DefStrTask Task14Infor ;
extern	DefStrTask Task15Infor ;

extern DefSystemState G_SystemState;
extern uchar g_sem_self ;

extern void InitTaskStr(void);

extern void Task1(TypeDelayStr *P_DelayStr,DefStrTask *P_StateTask,StrKeyClass *CurKey);

extern void Task2(TypeDelayStr *P_DelayStr,DefStrTask *P_StateTask,StrKeyClass *CurKey);
extern void Task3(TypeDelayStr *P_DelayStr,DefStrTask *P_StateTask,StrKeyClass *CurKey);
extern void Task4(TypeDelayStr *P_DelayStr,DefStrTask *P_StateTask,StrKeyClass *CurKey);
extern void Task5(TypeDelayStr *P_DelayStr,DefStrTask *P_StateTask,StrKeyClass *CurKey);
extern void Task6(TypeDelayStr *P_DelayStr,DefStrTask *P_StateTask,StrKeyClass *CurKey);
extern void Task7(TypeDelayStr *P_DelayStr,DefStrTask *P_StateTask,StrKeyClass *CurKey);
extern void Task8(TypeDelayStr *P_DelayStr,DefStrTask *P_StateTask,StrKeyClass *CurKey);
extern void Task9(TypeDelayStr *P_DelayStr,DefStrTask *P_StateTask,StrKeyClass *CurKey);
extern void Task10(TypeDelayStr *P_DelayStr,DefStrTask *P_StateTask,StrKeyClass *CurKey);







extern void Task11(TypeDelayStr *P_DelayStr,DefStrTask *P_StateTask);
extern void res(void );



#endif
