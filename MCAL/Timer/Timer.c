/*
 * Timer.c
 *
 *  Created on: Oct 30, 2023
 *      Author: G3AR
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "Timer_Interface.h"
#include "Timer_Private.h"
static void (*PointerToFunc) (void)=0;




void Timer3_PWM_Init( u8 channel ,u16 Duty) {


	// Set the prescaler value (to divide the timer clock, if needed)
	TIMER3->PSC = prescaler;


	// Auto-reload register (period value)
	TIMER3->ARR= ARR_Value;

	switch (channel)
	{
	case 1:
	{
		// Capture/Compare 1 value (duty cycle)
		TIMER3->CCR1 = Duty;

		// Configure Channel 1 in PWM1 mode
		TIMER3->CCMR1 |= TIM_CCMR1_OC1M_1 | TIM_CCMR1_OC1M_2; // PWM mode 1

		// Enable the output compare 1 (OC1) signal
		TIMER3->CCER |= 0x0001;


		break ;
	}
	case 2:
	{

		// Capture/Compare 2 value (duty cycle for Channel 2)
		TIMER3->CCR2 = Duty;


		// Configure Channel 2 in PWM1 mode
		TIMER3->CCMR1 |= TIM_CCMR1_OC2M_1 | TIM_CCMR1_OC2M_2; // PWM mode 1

		// Enable the output compare 2 (OC2) signal
		TIMER3->CCER |=  0x0010;
		break;

	}
	case 3:
	{
		// Capture/Compare 3 value (duty cycle for Channel 3)
		TIMER3->CCR3 = Duty;
		// Configure Channel 3 in PWM1 mode
		TIMER3->CCMR2 |= TIM_CCMR2_OC3M_1 | TIM_CCMR2_OC3M_2; // PWM mode 1
		// Enable the output compare 1 (OC1), output compare 2 (OC2), and output compare 3 (OC3) signals
		TIMER3->CCER |=  0x0100;
break;

	}
	}
	// Enable the timer
	TIMER3->CR1 |= 0x0001;

}



void Timer2_Init(void)
{
	CLR_BIT(TIM2->CR1,5);    // Set the counter to work counts up or down not alternatively
	CLR_BIT(TIM2->CR1,6);    // Set the counter to work counts up or down not alternatively

	CLR_BIT(TIM2->CR1,4);    // Counter used as upcounter

	TIM2->CCMR1 |= 0x0001;   // set the compare mode

	TIM2->PSC = 16;          // Set the prescaler

	TIM2->CCER &= ~(0x000A); // masking the data of this register and make zero
	SET_BIT(TIM2->CCER,1);   // set the both falling and rising
	SET_BIT(TIM2->CCER,3);   // set compare capture polarity


	TIM2->CCER |= 0x0001;    // set capture enable

	TIM2->DIER |= 0x0002;    // set the interrupt


}



void Timer2_Reset_Counter(void)
{
	TIM2->CNT=0;  // Set the number you want the counter to start with.
}


void TIM2_start (void)
{
	TIM2->CR1 |= 0x0001; //start timer func
}

void TIM2_Stop (void)
{
	CLR_BIT(TIM2->CR1 , 0);
}


u32 TIM2_CaptureRead (void)
{
	u32 t;
	t=TIM2->CCR1; //read capture func
	return t;

}

void TIM2SetCallBack (void (*localpointer)(void))
{

	if( localpointer != 0)
	{
	 PointerToFunc=localpointer;
	}

}
void TIM2_IRQHandler(void)
{

if( PointerToFunc != 0)
{
 PointerToFunc();
}

}






















