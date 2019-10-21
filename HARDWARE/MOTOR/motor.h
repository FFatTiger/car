#ifndef _MOTOR_H

#define _MOTOR_H

void Stop(void);
void TurnFront(void);
void Turnleft(void);
void Turnright(void);
//左前轮正转
void LeftFrontForward(void);

//左后轮正转
void LeftRearForwardRotation(void);

//右前轮正转
void RightFrontWheelForward(void);

//右后轮正转
void RightRearWheelForward(void);


///////////////////////////////////
//左前轮反转
void LeftFrontWheelReverse(void);

//左后轮反转
void LeftRearWheelReverse(void);

//右前轮反转
void RightFrontWheelReversal(void);

//右后轮反转
void RightRearWheelReverse(void);
#define LEFT        HAL_GPIO_ReadPin(GPIOC,GPIO_PIN_6)  //KEY0按键PH3
#define CLEFT        HAL_GPIO_ReadPin(GPIOC,GPIO_PIN_7)  //KEY1按键PH2
#define CRIGHT        HAL_GPIO_ReadPin(GPIOC,GPIO_PIN_8) //KEY2按键PC13
#define RIGHT       HAL_GPIO_ReadPin(GPIOC,GPIO_PIN_9)  //WKUP按键PA0
#endif 
