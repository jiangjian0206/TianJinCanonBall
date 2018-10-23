#ifndef __led_h
#define __led_h
#include "stm32f10x.h"	

extern  void LED_Init(void);
extern  void IWDG_Init(u8 prer,u16 rlr);
extern  void IWDG_Feed(void);
#endif

