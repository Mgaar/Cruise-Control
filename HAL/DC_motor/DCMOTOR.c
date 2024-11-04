/*
 * DCMOTOR.c
 *
 *  Created on: Oct 30, 2023
 *      Author: G3ar
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DC_Motor.h"
#include "DC_Motor_Config.h"
#include "GPIO_Interface.h"
#include "Timer_Interface.h"
void HMotor_Init(void)
{
	MGPIO_voidSetPinMode(MGPIOA,L298_EnaPin,MGPIO_AltrenativeFunc);
	MGPIO_voidSetPinAltFun(MGPIOA,L298_EnaPin,2);

	MGPIO_voidSetPinMode(MGPIOA,L298_EnbPin,MGPIO_AltrenativeFunc);
	MGPIO_voidSetPinAltFun(MGPIOA,L298_EnbPin,2);

	MGPIO_voidSetPinMode(MGPIOA,L298_In1Pin,MGPIO_OUTPUT);
	MGPIO_voidSetOutputPinMode(MGPIOA,L298_In1Pin,MGPIO_OUTPUT_PUSHPULL_MODE,MGPIO_SPEED_LOW);

	MGPIO_voidSetPinMode(MGPIOA,L298_In2Pin,MGPIO_OUTPUT);
	MGPIO_voidSetOutputPinMode(MGPIOA,L298_In2Pin,MGPIO_OUTPUT_PUSHPULL_MODE,MGPIO_SPEED_LOW);

	MGPIO_voidSetPinMode(MGPIOA,L298_In3Pin,MGPIO_OUTPUT);
	MGPIO_voidSetOutputPinMode(MGPIOA,L298_In3Pin,MGPIO_OUTPUT_PUSHPULL_MODE,MGPIO_SPEED_LOW);

	MGPIO_voidSetPinMode(MGPIOA,L298_In4Pin,MGPIO_OUTPUT);
	MGPIO_voidSetOutputPinMode(MGPIOA,L298_In4Pin,MGPIO_OUTPUT_PUSHPULL_MODE,MGPIO_SPEED_LOW);
}



void HMotor_Move(u8 Direction, u16 Speed)
{

	Timer3_PWM_Init(L298_EnAChannel,Speed);
	Timer3_PWM_Init(L298_EnBChannel,Speed);



    switch (Direction)
    {
    	/*stop the the car*/
        case Direction_Stop:
        	MGPIO_voidSetPinValue(MGPIOA, L298_In1Pin, MGPIO_LOW);
        	MGPIO_voidSetPinValue(MGPIOA, L298_In2Pin, MGPIO_LOW);
        	MGPIO_voidSetPinValue(MGPIOA, L298_In3Pin, MGPIO_LOW);
        	MGPIO_voidSetPinValue(MGPIOA, L298_In4Pin, MGPIO_LOW);
            break;
        /* Move the car forward*/
        case Direction_Forward:
        	MGPIO_voidSetPinValue(MGPIOA, L298_In1Pin, MGPIO_HIGH);
        	MGPIO_voidSetPinValue(MGPIOA, L298_In2Pin, MGPIO_LOW);
        	MGPIO_voidSetPinValue(MGPIOA, L298_In3Pin, MGPIO_HIGH);
        	MGPIO_voidSetPinValue(MGPIOA, L298_In4Pin, MGPIO_LOW);
            break;
        /* move the car backward*/
        case Direction_Backward:
        	MGPIO_voidSetPinValue(MGPIOA, L298_In1Pin, MGPIO_LOW);
        	MGPIO_voidSetPinValue(MGPIOA, L298_In2Pin, MGPIO_HIGH);
        	MGPIO_voidSetPinValue(MGPIOA, L298_In3Pin, MGPIO_LOW);
        	MGPIO_voidSetPinValue(MGPIOA, L298_In4Pin, MGPIO_HIGH);

            break;
        /* to make the car turn right*/
        case Direction_Right:
        	MGPIO_voidSetPinValue(MGPIOA, L298_In1Pin, MGPIO_LOW);
        	MGPIO_voidSetPinValue(MGPIOA, L298_In2Pin, MGPIO_LOW);
        	MGPIO_voidSetPinValue(MGPIOA, L298_In3Pin, MGPIO_HIGH);
        	MGPIO_voidSetPinValue(MGPIOA, L298_In4Pin, MGPIO_LOW);

            break;
        /*move the right motor in the forward direction and stop the left motors to make the car turn left*/
        case Direction_Left:
        	MGPIO_voidSetPinValue(MGPIOA, L298_In1Pin, MGPIO_HIGH);
        	MGPIO_voidSetPinValue(MGPIOA, L298_In2Pin, MGPIO_LOW);
        	MGPIO_voidSetPinValue(MGPIOA, L298_In3Pin, MGPIO_LOW);
        	MGPIO_voidSetPinValue(MGPIOA, L298_In4Pin, MGPIO_LOW);
			break;
    }
}
















