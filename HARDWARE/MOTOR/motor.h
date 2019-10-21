#ifndef _MOTOR_H

#define _MOTOR_H

void Stop(void);
void TurnFront(void);
void Turnleft(void);
void Turnright(void);
//��ǰ����ת
void LeftFrontForward(void);

//�������ת
void LeftRearForwardRotation(void);

//��ǰ����ת
void RightFrontWheelForward(void);

//�Һ�����ת
void RightRearWheelForward(void);


///////////////////////////////////
//��ǰ�ַ�ת
void LeftFrontWheelReverse(void);

//����ַ�ת
void LeftRearWheelReverse(void);

//��ǰ�ַ�ת
void RightFrontWheelReversal(void);

//�Һ��ַ�ת
void RightRearWheelReverse(void);
#define LEFT        HAL_GPIO_ReadPin(GPIOC,GPIO_PIN_6)  //KEY0����PH3
#define CLEFT        HAL_GPIO_ReadPin(GPIOC,GPIO_PIN_7)  //KEY1����PH2
#define CRIGHT        HAL_GPIO_ReadPin(GPIOC,GPIO_PIN_8) //KEY2����PC13
#define RIGHT       HAL_GPIO_ReadPin(GPIOC,GPIO_PIN_9)  //WKUP����PA0
#endif 
