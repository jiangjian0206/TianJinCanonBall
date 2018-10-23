#include "stm32f10x_gpio.h"

#define keyLongEnable 0  //为1 使能长按功能。

#define ReadKey_Down_01 (GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_8) == 0)
#define ReadKey_Up_01   (GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_8) == 1)
#define ReadKey_Down_02 (GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_9) == 0)
#define ReadKey_Up_02   (GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_9) == 1)

#define ReadRoute_Down_01 (GPIO_ReadInputDataBit(GPIOE,GPIO_Pin_1) == 0)
#define ReadRoute_up_01   (GPIO_ReadInputDataBit(GPIOE,GPIO_Pin_1) == 1)
#define ReadSelect_Down (GPIO_ReadInputDataBit(GPIOE,GPIO_Pin_0) == 0)
#define ReadSelect_Up   (GPIO_ReadInputDataBit(GPIOE,GPIO_Pin_0) == 1)


#define ReadKey_Down_32 (GPIO_ReadInputDataBit(GPIOG,GPIO_Pin_15) == 0)
#define ReadKey_Up_32   (GPIO_ReadInputDataBit(GPIOG,GPIO_Pin_15) == 1)
#define ReadRoute_Down_02 (GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_7) == 0)
#define ReadRoute_up_02   (GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_7) == 1)

#define ReadKey_Down_03 (GPIO_ReadInputDataBit(GPIOE,GPIO_Pin_0) == 0)
#define ReadKey_Up_03   (GPIO_ReadInputDataBit(GPIOE,GPIO_Pin_0) == 1)
#define ReadRoute_Down_03 (GPIO_ReadInputDataBit(GPIOE,GPIO_Pin_5) == 0)
#define ReadRoute_up_03   (GPIO_ReadInputDataBit(GPIOE,GPIO_Pin_5) == 1)

#define ReadKey_Down_04 (GPIO_ReadInputDataBit(GPIOE,GPIO_Pin_6) == 0)
#define ReadKey_Up_04   (GPIO_ReadInputDataBit(GPIOE,GPIO_Pin_6) == 1)
#define ReadRoute_Down_04 (GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_15) == 0)
#define ReadRoute_up_04   (GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_15) == 1)

#define ReadKey_Down_05 (GPIO_ReadInputDataBit(GPIOF,GPIO_Pin_0) == 0)
#define ReadKey_Up_05   (GPIO_ReadInputDataBit(GPIOF,GPIO_Pin_0) == 1)
#define ReadRoute_Down_05 (GPIO_ReadInputDataBit(GPIOF,GPIO_Pin_3) == 0)
#define ReadRoute_up_05   (GPIO_ReadInputDataBit(GPIOF,GPIO_Pin_3) == 1)

#define ReadKey_Down_06 (GPIO_ReadInputDataBit(GPIOF,GPIO_Pin_8) == 0)
#define ReadKey_Up_06   (GPIO_ReadInputDataBit(GPIOF,GPIO_Pin_8) == 1)
#define ReadRoute_Down_06 (GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_0) == 0)
#define ReadRoute_up_06   (GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_0) == 1)

#define ReadKey_Down_07 (GPIO_ReadInputDataBit(GPIOF,GPIO_Pin_4) == 0)
#define ReadKey_Up_07   (GPIO_ReadInputDataBit(GPIOF,GPIO_Pin_4) == 1)
#define ReadRoute_Down_07 (GPIO_ReadInputDataBit(GPIOF,GPIO_Pin_7) == 0)
#define ReadRoute_up_07   (GPIO_ReadInputDataBit(GPIOF,GPIO_Pin_7) == 1)

#define ReadKey_Down_08 (GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_0) == 0)
#define ReadKey_Up_08   (GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_0) == 1)
#define ReadRoute_Down_08 (GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_3) == 0)
#define ReadRoute_up_08   (GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_3) == 1)

#define ReadKey_Down_09 (GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_0) == 0)
#define ReadKey_Up_09   (GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_0) == 1)
#define ReadRoute_Down_09 (GPIO_ReadInputDataBit(GPIOF,GPIO_Pin_11) == 0)
#define ReadRoute_up_09   (GPIO_ReadInputDataBit(GPIOF,GPIO_Pin_11) == 1)

#define ReadKey_Down_10 (GPIO_ReadInputDataBit(GPIOF,GPIO_Pin_12) == 0)
#define ReadKey_Up_10   (GPIO_ReadInputDataBit(GPIOF,GPIO_Pin_12) == 1)
#define ReadRoute_Down_10 (GPIO_ReadInputDataBit(GPIOF,GPIO_Pin_15) == 0)
#define ReadRoute_up_10   (GPIO_ReadInputDataBit(GPIOF,GPIO_Pin_15) == 1)


#define Readmannul_Down_key_01 (GPIO_ReadInputDataBit(GPIOE,GPIO_Pin_6) == 0)
#define Readmannul_Up_key_01   (GPIO_ReadInputDataBit(GPIOE,GPIO_Pin_6) == 1)

#define Readmannul_Down_key_02 (GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_13) == 0)
#define Readmannul_Up_key_02   (GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_13) == 1)

#define Readmannul_Down_key_03 (GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_14) == 0)
#define Readmannul_Up_key_03  (GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_14) == 1)

#define Readmannul_Down_key_04 (GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_15) == 0)
#define Readmannul_Up_key_04   (GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_15) == 1)

#define Readmannul_Down_key_05 (GPIO_ReadInputDataBit(GPIOF,GPIO_Pin_8) == 0)
#define Readmannul_Up_key_05   (GPIO_ReadInputDataBit(GPIOF,GPIO_Pin_8) == 1)


#define ReadSensor_left_push_down   (GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_7) == 0)
#define ReadSensor_left_push_up     (GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_7) == 1)
#define ReadSensor_left_pull_down   (GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_4) == 0)
#define ReadSensor_left_pull_up     (GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_4) == 1)

#define ReadSensor_right_push_down   (GPIO_ReadInputDataBit(GPIOE,GPIO_Pin_3) == 0)
#define ReadSensor_right_push_up     (GPIO_ReadInputDataBit(GPIOE,GPIO_Pin_3) == 1)
#define ReadSensor_right_pull_down   (GPIO_ReadInputDataBit(GPIOE,GPIO_Pin_2) == 0)
#define ReadSensor_right_pull_up     (GPIO_ReadInputDataBit(GPIOE,GPIO_Pin_2) == 1)

#define ReadSensor_behind_push_down   (GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_3) == 0)
#define ReadSensor_behind_push_up     (GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_3) == 1)
#define ReadSensor_behind_pull_down   (GPIO_ReadInputDataBit(GPIOG,GPIO_Pin_15) == 0)
#define ReadSensor_behind_pull_up     (GPIO_ReadInputDataBit(GPIOG,GPIO_Pin_15) == 1)

#define ReadSensor_riser1_push_down   (GPIO_ReadInputDataBit(GPIOF,GPIO_Pin_1) == 0)
#define ReadSensor_riser1_push_up     (GPIO_ReadInputDataBit(GPIOF,GPIO_Pin_1) == 1)
#define ReadSensor_riser1_pull_down   (GPIO_ReadInputDataBit(GPIOF,GPIO_Pin_0) == 0)
#define ReadSensor_riser1_pull_up     (GPIO_ReadInputDataBit(GPIOF,GPIO_Pin_0) == 1)

#define ReadSensor_riser2_push_down   (GPIO_ReadInputDataBit(GPIOF,GPIO_Pin_3) == 0)
#define ReadSensor_riser2_push_up     (GPIO_ReadInputDataBit(GPIOF,GPIO_Pin_3) == 1)
#define ReadSensor_riser2_pull_down   (GPIO_ReadInputDataBit(GPIOF,GPIO_Pin_2) == 0)
#define ReadSensor_riser2_pull_up     (GPIO_ReadInputDataBit(GPIOF,GPIO_Pin_2) == 1)















