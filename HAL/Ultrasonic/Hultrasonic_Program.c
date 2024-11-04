#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "Timer_Interface.h"
#include "STK_Interface.h"
#include "GPIO_Interface.h"
#include "NVIC_Interface.h"
#include "Hultrasonic_Config.h"
#include "Hultrasonic_Interface.h"
volatile u32 u32Trig_Time;
volatile u32 u32Echo_Time;

static volatile u8 x = 0 ;


void Ultrasonic_Trigger (void)
{
	MSTK_voidSetBusyWait(120000);
	MGPIO_voidSetPinValue(MGPIOB,1,MGPIO_HIGH);
	MSTK_voidSetBusyWait(20*2);
	MGPIO_voidSetPinValue(MGPIOB,1,MGPIO_LOW);

}

void Ultrasonic_Init (void)
{
	MNVIC_voidEnablePerInt(28);
	MGPIO_voidSetPinMode(MGPIOA,0,MGPIO_AltrenativeFunc);
	MGPIO_voidSetPinAltFun(MGPIOA,0,1);
	MGPIO_voidSetPinMode(MGPIOB,1,MGPIO_OUTPUT);
	MGPIO_voidSetOutputPinMode(MGPIOB,1,MGPIO_OUTPUT_PUSHPULL_MODE,MGPIO_SPEED_LOW);
	TIM2SetCallBack(capture);
}

	
f32 Ultrasonic_Read (void)
{
	f32 Distance;
	u32 Local32_Final_Time = 0;
	while(x!=2);
	Local32_Final_Time = u32Echo_Time - u32Trig_Time;
	Distance=((f32)Local32_Final_Time*0.000862069);
	x=0;
	
	return Distance;
}

void capture (void)
{
	if(x==0)
	{
		TIM2_start();
		u32Trig_Time=TIM2_CaptureRead();
		x=1 ;
	}
	else if (x==1)
	{
		u32Echo_Time=TIM2_CaptureRead();
		x = 2 ;
		TIM2_Stop();
		Timer2_Reset_Counter();
	}
}
