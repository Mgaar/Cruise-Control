/*
 * Servo.c
 *
 *  Created on: Nov 4, 2023
 *      Author: G3ar
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "Servo_Interface.h"
#include "Servo_Config.h"
#include "GPIO_Interface.h"
#include "Timer_Interface.h"



void HServo_Init(void)
{
	MGPIO_voidSetPinMode(MGPIOB,Servo_Pin,MGPIO_AltrenativeFunc);
		MGPIO_voidSetPinAltFun(MGPIOB,Servo_Pin,2);



}


void HServo_Rotate(u16 Angle)
{
	Timer3_PWM_Init(Servo_Channel,Angle);


}

