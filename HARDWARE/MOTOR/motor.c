/*#include "STM32F10X.h"
#include "motor.h"

void MotorInit(void)
{
	
	//初始化和使能单片机上的GPIO端口，保证可以正常给端口高低电平
	GPIO_InitTypeDef GPIO_InitStructure;
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC , ENABLE);
	GPIO_InitStructure.Pin=  GPIO_PIN_10 | GPIO_PIN_11 | GPIO_PIN_12 | GPIO_PIN_6 | GPIO_PIN_7 | GPIO_PIN_8;
	GPIO_InitStructure.Speed = GPIO_SPEED_HIGH;
	GPIO_InitStructure.GPIO_SPEED_HIGH = GPIO_SPEED_HIGH_OUTPUT_PP; 
	GPIO_Init(GPIOC, &GPIO_InitStructure);
	GPIO_SetBits(GPIOC, GPIO_PIN_10 | GPIO_PIN_11 | GPIO_PIN_12 | GPIO_PIN_6);
//	MOTOR_APB_PERIPH_FUNG(MOTOr_APB_PORT , ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOD , ENABLE);
	GPIO_InitStructure.Pin=  GPIO_PIN_2;
	GPIO_Init(GPIOD, &GPIO_InitStructure);
	GPIO_SetBits(GPIOD, GPIO_PIN_2);
}


//停止模式
void Stop(void)
{
	GPIO_ResetBits(GPIOC,GPIO_PIN_10);
	GPIO_ResetBits(GPIOC,GPIO_PIN_11);
	GPIO_ResetBits(GPIOC,GPIO_PIN_12);
	GPIO_ResetBits(GPIOD,GPIO_PIN_2);
}


//左转模式 -> 左电机正转，右电机反转
void Turnleft(void)
{
	GPIO_SetBits(GPIOC,GPIO_PIN_10); 
	GPIO_ResetBits(GPIOC,GPIO_PIN_11);
	GPIO_ResetBits(GPIOC,GPIO_PIN_12);
	GPIO_SetBits(GPIOD,GPIO_PIN_2);
	GPIO_SetBits(GPIOC,GPIO_PIN_6);
}

//右转模式 -> 左电机反转，右电机正转
void Turnright(void)
{
	GPIO_ResetBits(GPIOC,GPIO_PIN_10);
	GPIO_SetBits(GPIOC,GPIO_PIN_11);
	GPIO_SetBits(GPIOC,GPIO_PIN_12);
	GPIO_ResetBits(GPIOD,GPIO_PIN_2);
	GPIO_SetBits(GPIOC,GPIO_PIN_6);
}

//后退模式 -> 左电机反转，右电机反转
void Turnback(void)
{
	
	GPIO_ResetBits(GPIOC,GPIO_PIN_10);
	GPIO_SetBits(GPIOC,GPIO_PIN_11);
	GPIO_ResetBits(GPIOC,GPIO_PIN_12);
	GPIO_SetBits(GPIOD,GPIO_PIN_2);
	GPIO_SetBits(GPIOC,GPIO_PIN_8);
	
}

//前进模式 -> 左电机正转，右电机正转
void Turnfront(void)
{
	GPIO_SetBits(GPIOC,GPIO_PIN_10);
	GPIO_ResetBits(GPIOC,GPIO_PIN_11);
	GPIO_SetBits(GPIOC,GPIO_PIN_12); 
	GPIO_ResetBits(GPIOD,GPIO_PIN_2);
	GPIO_SetBits(GPIOC,GPIO_PIN_7);
}

//以左电机为中心原地左转
void Leftaround(void)
{
	GPIO_SetBits(GPIOC,GPIO_PIN_10);
	GPIO_ResetBits(GPIOC,GPIO_PIN_11);
	GPIO_SetBits(GPIOC,GPIO_PIN_12);
	GPIO_SetBits(GPIOD,GPIO_PIN_2);
	
}

//以右电机为中心原地右转
void Rightaround(void)
{
	GPIO_SetBits(GPIOC,GPIO_PIN_10);
	GPIO_SetBits(GPIOC,GPIO_PIN_11);
	GPIO_SetBits(GPIOC,GPIO_PIN_12);
	GPIO_ResetBits(GPIOD,GPIO_PIN_2);
	
}
*/
#include "sys.h"
#include "motor.h"

void MotorInit(void)
{
	
	//初始化和使能单片机上的GPIO端口，保证可以正常给端口高低电平
	GPIO_InitTypeDef GPIO_InitStructure;
	
	__HAL_RCC_GPIOD_CLK_ENABLE();           //开启GPIOB时钟
	GPIO_InitStructure.Pin =  GPIO_PIN_6 | GPIO_PIN_4 | GPIO_PIN_11 | GPIO_PIN_5;
	GPIO_InitStructure.Speed = GPIO_SPEED_HIGH;
	GPIO_InitStructure.Mode = GPIO_MODE_OUTPUT_PP; 
	HAL_GPIO_Init(GPIOD,&GPIO_InitStructure);

	__HAL_RCC_GPIOG_CLK_ENABLE();
	GPIO_InitStructure.Pin= GPIO_PIN_13 |GPIO_PIN_14;
	GPIO_InitStructure.Speed = GPIO_SPEED_HIGH;
	GPIO_InitStructure.Mode = GPIO_MODE_OUTPUT_PP; 
	HAL_GPIO_Init(GPIOG,&GPIO_InitStructure);
	
	__HAL_RCC_GPIOC_CLK_ENABLE();
	GPIO_InitStructure.Pin=  GPIO_PIN_1;
	GPIO_InitStructure.Speed = GPIO_SPEED_HIGH;
	GPIO_InitStructure.Mode = GPIO_MODE_OUTPUT_PP; 
	HAL_GPIO_Init(GPIOC,&GPIO_InitStructure);

	__HAL_RCC_GPIOA_CLK_ENABLE();
	GPIO_InitStructure.Pin=  GPIO_PIN_1;
	GPIO_InitStructure.Speed = GPIO_SPEED_HIGH;
	GPIO_InitStructure.Mode = GPIO_MODE_OUTPUT_PP; 
	HAL_GPIO_Init(GPIOA,&GPIO_InitStructure);
	
	
	HAL_GPIO_WritePin(GPIOD,GPIO_PIN_6,GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOD,GPIO_PIN_4,GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOD,GPIO_PIN_11,GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOD,GPIO_PIN_5,GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOG,GPIO_PIN_13,GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOG,GPIO_PIN_14,GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOA,GPIO_PIN_1,GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOC,GPIO_PIN_1,GPIO_PIN_SET);
	
/********************************************************************************************/
	
	__HAL_RCC_GPIOC_CLK_ENABLE();           //开启GPIOB时钟
	GPIO_InitStructure.Pin =  GPIO_PIN_6 | GPIO_PIN_7 | GPIO_PIN_8 | GPIO_PIN_9;
	GPIO_InitStructure.Speed = GPIO_SPEED_HIGH;
	GPIO_InitStructure.Mode = GPIO_MODE_INPUT; 
	HAL_GPIO_Init(GPIOC,&GPIO_InitStructure);
	

}

void Stop(void)
{
	HAL_GPIO_WritePin(GPIOD,GPIO_PIN_6,GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOD,GPIO_PIN_4,GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOD,GPIO_PIN_11,GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOD,GPIO_PIN_5,GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOG,GPIO_PIN_13,GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOG,GPIO_PIN_14,GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOA,GPIO_PIN_1,GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOC,GPIO_PIN_1,GPIO_PIN_RESET);
}
//后退模式 -> 左电机反转，右电机反转
void Turnback(void)
{
	LeftFrontWheelReverse();
	LeftRearWheelReverse();
  RightFrontWheelReversal();
	RightRearWheelReverse();
	
}
//前进模式 -> 左电机正转，右电机正转
void TurnFront(void)
{
	LeftFrontForward();
	LeftRearForwardRotation();
	RightFrontWheelForward();
  RightRearWheelForward();

}
//左转模式 -> 左电机正转，右电机反转
void TurnLeft(void)
{
	RightFrontWheelForward();
	RightRearWheelForward();
	//LeftFrontWheelReverse();
	LeftRearWheelReverse();
}
//右转模式 -> 左电机反转，右电机正转
void TurnRight(void)
{
	LeftFrontForward();
	LeftRearForwardRotation();
//	RightFrontWheelReversal();
	//RightRearWheelReverse();
}




//左前轮正转
void LeftFrontForward(void)
{
	HAL_GPIO_WritePin(GPIOD,GPIO_PIN_6,GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOD,GPIO_PIN_4,GPIO_PIN_RESET);
}
//左后轮正转
void LeftRearForwardRotation(void)
{
	HAL_GPIO_WritePin(GPIOD,GPIO_PIN_11,GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOD,GPIO_PIN_5,GPIO_PIN_RESET);
}
//右前轮正转
void RightFrontWheelForward(void)
{
	HAL_GPIO_WritePin(GPIOG,GPIO_PIN_13,GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOG,GPIO_PIN_14,GPIO_PIN_RESET);
}
//右后轮正转
void RightRearWheelForward(void)
{
	HAL_GPIO_WritePin(GPIOC,GPIO_PIN_1,GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOA,GPIO_PIN_1,GPIO_PIN_RESET);
}

///////////////////////////////////
//左前轮反转
void LeftFrontWheelReverse(void)
{
	HAL_GPIO_WritePin(GPIOD,GPIO_PIN_6,GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOD,GPIO_PIN_4,GPIO_PIN_SET);
}
//左后轮反转
void LeftRearWheelReverse(void)
{
	HAL_GPIO_WritePin(GPIOD,GPIO_PIN_11,GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOD,GPIO_PIN_5,GPIO_PIN_SET);
}
//右前轮反转
void RightFrontWheelReversal(void)
{
	HAL_GPIO_WritePin(GPIOG,GPIO_PIN_13,GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOG,GPIO_PIN_14,GPIO_PIN_SET);
}
//右后轮反转
void RightRearWheelReverse(void)
{
	HAL_GPIO_WritePin(GPIOC,GPIO_PIN_1,GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOA,GPIO_PIN_1,GPIO_PIN_SET);
}

