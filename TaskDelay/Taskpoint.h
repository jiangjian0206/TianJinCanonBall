#ifndef _TASK_H_
#define _TASK_H_

#include "Delaypoint.h"

typedef struct StrTask
{
   uchar TaskState;
}DefStrTask;

enum EnumRunState{InOver, Running,OutOver};
enum EnumOpendoorEnable{DoesOpen,DonotOpen };
enum EnumClosedoorEnable{DoesClose,DonotClose };


typedef struct SystemState
{
   unsigned char InOutState;
   enum EnumOpendoorEnable  WhetherOpendoor;
   enum EnumClosedoorEnable WhetherClose;
   enum EnumRunState RunState;
}DefSystemState;

typedef struct Actions
{
// 	(void *) KeepDown_on(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin);
//	(void *) KeepDown_up(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin);
//	(void *) KeepUp_on(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin);
//	(void *) KeepUp_off(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin);
unsigned int a;	
}DefActions;

#endif


