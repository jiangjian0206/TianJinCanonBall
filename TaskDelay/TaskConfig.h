#ifndef		  _TASKCONFIG_H
#define       _TASKCONFIG_H

#define DOWN_keep_01    	  GPIO_SetBits(GPIOG,GPIO_Pin_13);
#define DOWN_over_01 	 	  GPIO_ResetBits(GPIOG,GPIO_Pin_13);
#define UP_keep_01      	  GPIO_SetBits(GPIOG,GPIO_Pin_14);
#define UP_over_01 			  GPIO_ResetBits(GPIOG,GPIO_Pin_14);
#define GreenLed_Light_01 	  GPIO_SetBits(GPIOG,GPIO_Pin_12);
#define GreenLed_Dark_01 	  GPIO_ResetBits(GPIOG,GPIO_Pin_12);
#define RedLed_Light_01 	  GPIO_SetBits(GPIOG,GPIO_Pin_11);
#define RedLed_Dark_01  	  GPIO_ResetBits(GPIOG,GPIO_Pin_11);



#define DOWN_keep_02   	 	  GPIO_SetBits(GPIOG,GPIO_Pin_9);
#define DOWN_over_02 	 	  GPIO_ResetBits(GPIOG,GPIO_Pin_9);
#define UP_keep_02      	  GPIO_SetBits(GPIOG,GPIO_Pin_10);
#define UP_over_02 			  GPIO_ResetBits(GPIOG,GPIO_Pin_10);
#define GreenLed_Light_02 	  GPIO_SetBits(GPIOD,GPIO_Pin_7);
#define GreenLed_Dark_02 	  GPIO_ResetBits(GPIOD,GPIO_Pin_7);
#define RedLed_Light_02 	  GPIO_SetBits(GPIOD,GPIO_Pin_6);
#define RedLed_Dark_02  	  GPIO_ResetBits(GPIOD,GPIO_Pin_6);


#define DOWN_keep_03    	  GPIO_SetBits(GPIOD,GPIO_Pin_4);
#define DOWN_over_03 	 	  GPIO_ResetBits(GPIOD,GPIO_Pin_4);
#define UP_keep_03     	  	  GPIO_SetBits(GPIOD,GPIO_Pin_5);
#define UP_over_03 			  GPIO_ResetBits(GPIOD,GPIO_Pin_5);
#define GreenLed_Light_03	  GPIO_SetBits(GPIOD,GPIO_Pin_3);
#define GreenLed_Dark_03	  GPIO_ResetBits(GPIOD,GPIO_Pin_3);
#define RedLed_Light_03	 	  GPIO_SetBits(GPIOD,GPIO_Pin_2);
#define RedLed_Dark_03  	  GPIO_ResetBits(GPIOD,GPIO_Pin_2);

#define DOWN_keep_04    	  GPIO_SetBits(GPIOD,GPIO_Pin_0);
#define DOWN_over_04 	 	  GPIO_ResetBits(GPIOD,GPIO_Pin_0);
#define UP_keep_04     	  	  GPIO_SetBits(GPIOD,GPIO_Pin_1);
#define UP_over_04 			  GPIO_ResetBits(GPIOD,GPIO_Pin_1);
#define GreenLed_Light_04	  GPIO_SetBits(GPIOC,GPIO_Pin_12);
#define GreenLed_Dark_04	  GPIO_ResetBits(GPIOC,GPIO_Pin_12);
#define RedLed_Light_04	 	  GPIO_SetBits(GPIOC,GPIO_Pin_11);
#define RedLed_Dark_04  	  GPIO_ResetBits(GPIOC,GPIO_Pin_11);

#define DOWN_keep_05    	  GPIO_SetBits(GPIOC,GPIO_Pin_9);
#define DOWN_over_05 	 	  GPIO_ResetBits(GPIOC,GPIO_Pin_9);
#define UP_keep_05     	  	  GPIO_SetBits(GPIOA,GPIO_Pin_8);  
#define UP_over_05 			  GPIO_ResetBits(GPIOA,GPIO_Pin_8);
#define GreenLed_Light_05	  GPIO_SetBits(GPIOC,GPIO_Pin_8);
#define GreenLed_Dark_05	  GPIO_ResetBits(GPIOC,GPIO_Pin_8);
#define RedLed_Light_05	 	  GPIO_SetBits(GPIOC,GPIO_Pin_7);
#define RedLed_Dark_05  	  GPIO_ResetBits(GPIOC,GPIO_Pin_7);

#define DOWN_keep_06    	  GPIO_SetBits(GPIOG,GPIO_Pin_8);  
#define DOWN_over_06 	 	  GPIO_ResetBits(GPIOG,GPIO_Pin_8);
#define UP_keep_06     	  	  GPIO_SetBits(GPIOC,GPIO_Pin_6);
#define UP_over_06 			  GPIO_ResetBits(GPIOC,GPIO_Pin_6); 
#define GreenLed_Light_06	  GPIO_SetBits(GPIOG,GPIO_Pin_7);
#define GreenLed_Dark_06	  GPIO_ResetBits(GPIOG,GPIO_Pin_7);
#define RedLed_Light_06	 	  GPIO_SetBits(GPIOG,GPIO_Pin_6);
#define RedLed_Dark_06  	  GPIO_ResetBits(GPIOG,GPIO_Pin_6);

#define DOWN_keep_07    	  GPIO_SetBits(GPIOG,GPIO_Pin_2);
#define DOWN_over_07 	 	  GPIO_ResetBits(GPIOG,GPIO_Pin_2);
#define UP_keep_07     	  	  GPIO_SetBits(GPIOG,GPIO_Pin_3);
#define UP_over_07 			  GPIO_ResetBits(GPIOG,GPIO_Pin_3);
#define GreenLed_Light_07	  GPIO_SetBits(GPIOD,GPIO_Pin_15);
#define GreenLed_Dark_07	  GPIO_ResetBits(GPIOD,GPIO_Pin_15);
#define RedLed_Light_07	 	  GPIO_SetBits(GPIOD,GPIO_Pin_14);
#define RedLed_Dark_07  	  GPIO_ResetBits(GPIOD,GPIO_Pin_14);

#define DOWN_keep_08    	  GPIO_SetBits(GPIOD,GPIO_Pin_12);
#define DOWN_over_08 	 	  GPIO_ResetBits(GPIOD,GPIO_Pin_12);
#define UP_keep_08     	  	  GPIO_SetBits(GPIOD,GPIO_Pin_13);
#define UP_over_08 			  GPIO_ResetBits(GPIOD,GPIO_Pin_13);
#define GreenLed_Light_08	  GPIO_SetBits(GPIOD,GPIO_Pin_11);
#define GreenLed_Dark_08	  GPIO_ResetBits(GPIOD,GPIO_Pin_11);
#define RedLed_Light_08	 	  GPIO_SetBits(GPIOD,GPIO_Pin_10);
#define RedLed_Dark_08  	  GPIO_ResetBits(GPIOD,GPIO_Pin_10);


#define DOWN_keep_09    	  GPIO_SetBits(GPIOB,GPIO_Pin_12);
#define DOWN_over_09 	 	  GPIO_ResetBits(GPIOB,GPIO_Pin_12);
#define UP_keep_09     	  	  GPIO_SetBits(GPIOB,GPIO_Pin_13);
#define UP_over_09 			  GPIO_ResetBits(GPIOB,GPIO_Pin_13);
#define GreenLed_Light_09	  GPIO_SetBits(GPIOB,GPIO_Pin_11);
#define GreenLed_Dark_09	  GPIO_ResetBits(GPIOB,GPIO_Pin_11);
#define RedLed_Light_09	 	  GPIO_SetBits(GPIOB,GPIO_Pin_10);
#define RedLed_Dark_09  	  GPIO_ResetBits(GPIOB,GPIO_Pin_10);

#define DOWN_keep_10    	  GPIO_SetBits(GPIOE,GPIO_Pin_14);
#define DOWN_over_10 	 	  GPIO_ResetBits(GPIOE,GPIO_Pin_14);
#define UP_keep_10     	  	  GPIO_SetBits(GPIOE,GPIO_Pin_15);
#define UP_over_10 			  GPIO_ResetBits(GPIOE,GPIO_Pin_15);
#define GreenLed_Light_10	  GPIO_SetBits(GPIOE,GPIO_Pin_13);
#define GreenLed_Dark_10	  GPIO_ResetBits(GPIOE,GPIO_Pin_13);
#define RedLed_Light_10	 	  GPIO_SetBits(GPIOE,GPIO_Pin_12);
#define RedLed_Dark_10  	  GPIO_ResetBits(GPIOE,GPIO_Pin_12);

// ÷∂Ø
#define DOWN_keep_leftPush    	  GPIO_SetBits(GPIOG,GPIO_Pin_14);
#define DOWN_over_leftPush 	 	  GPIO_ResetBits(GPIOG,GPIO_Pin_14);
#define UP_keep_leftPull    	  GPIO_SetBits(GPIOG,GPIO_Pin_13);
#define UP_over_leftPull 	 	  GPIO_ResetBits(GPIOG,GPIO_Pin_13);

#define DOWN_keep_RightPush    	  GPIO_SetBits(GPIOG,GPIO_Pin_11);
#define DOWN_over_RightPush 	  GPIO_ResetBits(GPIOG,GPIO_Pin_11);
#define UP_keep_RightPull    	  GPIO_SetBits(GPIOG,GPIO_Pin_12);
#define UP_over_RightPull 	  GPIO_ResetBits(GPIOG,GPIO_Pin_12);

#define DOWN_keep_BehindPush    	  GPIO_SetBits(GPIOG,GPIO_Pin_10);
#define DOWN_over_BehindPush 	 	  GPIO_ResetBits(GPIOG,GPIO_Pin_10);
#define UP_keep_BehindPull    	  GPIO_SetBits(GPIOG,GPIO_Pin_9);
#define UP_over_BehindPull 	 	  GPIO_ResetBits(GPIOG,GPIO_Pin_9);


#define DOWN_keep_Riser01Push    	  GPIO_SetBits(GPIOD,GPIO_Pin_5);
#define DOWN_over_Riser01Push 	 	  GPIO_ResetBits(GPIOD,GPIO_Pin_5);
#define UP_keep_Riser01Pull    	  GPIO_SetBits(GPIOD,GPIO_Pin_4);
#define UP_over_Riser01Pull 	 	  GPIO_ResetBits(GPIOD,GPIO_Pin_4);

#define DOWN_keep_Riser02Push    	  GPIO_SetBits(GPIOD,GPIO_Pin_2);
#define DOWN_over_Riser02Push 	 	  GPIO_ResetBits(GPIOD,GPIO_Pin_2);
#define UP_keep_Riser02Pull    	  GPIO_SetBits(GPIOD,GPIO_Pin_3);
#define UP_over_Riser02Pull 	 	  GPIO_ResetBits(GPIOD,GPIO_Pin_3);


#define DOWN_keep_ResetPush    	  GPIO_SetBits(GPIOC,GPIO_Pin_8);
#define DOWN_over_ResetPush 	 	  GPIO_ResetBits(GPIOC,GPIO_Pin_8);
#define UP_keep_ResetPull    	  GPIO_SetBits(GPIOC,GPIO_Pin_8);
#define UP_over_ResetPull 	 	  GPIO_ResetBits(GPIOC,GPIO_Pin_8);

#define DOWN_keep_nmiPush    	  GPIO_SetBits(GPIOC,GPIO_Pin_9);
#define DOWN_over_nmiPush 	 	  GPIO_ResetBits(GPIOC,GPIO_Pin_9);
#define UP_keep_nmiPull    	  GPIO_SetBits(GPIOA,GPIO_Pin_8);
#define UP_over_nmiPull 	 	  GPIO_ResetBits(GPIOA,GPIO_Pin_8);








#define PutinON   GPIO_ResetBits(GPIOA,GPIO_Pin_3);
#define PutoutOn  GPIO_SetBits(GPIOA,GPIO_Pin_3);

#define ReadStateIn  (GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_3) )
#define ReadStateOut (GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_2) )

#define ReadStateDown  (GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_4) )
#define ReadStateUp    (GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_5) )


#define Rely2Open   GPIO_ResetBits(GPIOC,GPIO_Pin_14);
#define Rely2Close  GPIO_SetBits(GPIOC,GPIO_Pin_14);


#define Rely1Open   GPIO_ResetBits(GPIOC,GPIO_Pin_15);
#define Rely1Close  GPIO_SetBits(GPIOC,GPIO_Pin_15);




#endif
