#include "sys.h"
#include "delay.h"
#include "usart.h"
#include "led.h"
#include "motor.h"
#include "key.h"
#include "pcf8574.h"
/************************************************
 ALIENTEK 阿波罗STM32F429开发板 实验1
 跑马灯实验-HAL库版本
 技术支持：www.openedv.com
 淘宝店铺：http://eboard.taobao.com 
 关注微信公众平台微信号："正点原子"，免费获取STM32资料。
 广州市星翼电子科技有限公司  
 作者：正点原子 @ALIENTEK
************************************************/




/*下面主函数是使用HAL库函数实现控制IO口输出*/
 
int main(void)
{
		u8 key;
	u8 beepsta=0;
    HAL_Init();                     //初始化HAL库   
    Stm32_Clock_Init(360,25,2,8);   //设置时钟,180Mhz
    delay_init(180);                //初始化延时函数
    LED_Init();                     //初始化LED  
	MotorInit();
	  KEY_Init();   
	PCF8574_Init();
    while(1)
    {
        HAL_GPIO_WritePin(GPIOB,GPIO_PIN_1,GPIO_PIN_RESET); //LED0对应引脚PB1拉低，亮，等同于LED0(0)
        HAL_GPIO_WritePin(GPIOB,GPIO_PIN_0,GPIO_PIN_SET);   //LED1对应引脚PB0拉高，灭，等同于LED1(1)
        delay_ms(500);										//延时500ms
        HAL_GPIO_WritePin(GPIOB,GPIO_PIN_1,GPIO_PIN_SET);   //LED0对应引脚PB1拉高，灭，等同于LED0(1)
        HAL_GPIO_WritePin(GPIOB,GPIO_PIN_0,GPIO_PIN_RESET); //LED1对应引脚PB0拉低，亮，等同于LED1(0)
        delay_ms(500);                                      //延时500ms 
			
				key=KEY_Scan(0);            //按键扫描
				switch(key)
				{				 
					case  WKUP_PRES:	//控制LED0,LED1互斥点亮
								//RightRearWheelForward();
							  Turnback(); 
								break;
					case  KEY0_PRES:
								//LeftFrontForward();
								TurnFront(); 
								break;
					case  KEY1_PRES:
								//LeftRearForw ardRotation();
								TurnLeft();
								break;
					case  KEY2_PRES:
								//RightFrontWheelForward();
								TurnRight(); 
								break;
			}
				/*
		if(CLEFT==1&&CRIGHT==1){
			TurnFront();
		}else if(LEFT==1){
			TurnLeft();
		}else if(RIGHT==1){
			TurnRight();
		}
		 else Stop();

    }*/
		}
}
 

 
/*下面主函数使用位带操作实现：*/
/*
int main(void)
{ 
    HAL_Init();                     //初始化HAL库   
    Stm32_Clock_Init(360,25,2,8);   //设置时钟,180Mhz
    delay_init(180);                //初始化延时函数
    LED_Init();                     //初始化LED    while(1)
	{
         LED0=0;			     //LED0亮
	     LED1=1;				 //LED1灭
		 delay_ms(500);
		 LED0=1;				//LED0灭
		 LED1=0;				//LED1亮
		 delay_ms(500);
	 }
}*/




/*
下面主函数使用直接操作结存器方式实现跑马灯
*/
/*
int main(void)
{ 
    HAL_Init();                     //初始化HAL库   
    Stm32_Clock_Init(360,25,2,8);   //设置时钟,180Mhz
    delay_init(180);                //初始化延时函数
    LED_Init();                     //初始化LED  
	while(1)
	{
      GPIOB->BSRR=GPIO_PIN_1;     //LED0亮
	  GPIOB->BSRR=GPIO_PIN_0<<16; //LED1灭
	  delay_ms(500);
      GPIOB->BSRR=GPIO_PIN_1<<16; //LED0灭
	  GPIOB->BSRR=GPIO_PIN_0;     //LED1亮
	  delay_ms(500);
	 }
 }	
*/




