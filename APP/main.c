#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "GPIO_Interface.h"
#include "MRCC_Interface.h"
#include "STK_Interface.h"
#include "DC_Motor.h"
#include "NVIC_Interface.h"
#include "Hultrasonic_Interface.h"
#include "Timer_Interface.h"
#include "Servo_Interface.h"

#define Obstacle_Distance	 (f32)50.0
#define Decrease_Distance_1  (f32)150.0
#define Decrease_Distance_2  (f32)100.0
#define stopspeed            (u16)0
#define Delay_Servo			 (u32)2000000
#define TurnSpeed            (u16)600
#define TurnDelay            (u32)500000
void main (void)
{
	f32 Distance;
	f32 LastDistance=0.0;
	f32 RightDistance=0.0;
	f32 LeftDistance=0.0;
	u16 speed=400;
	MRCC_vInit();
	MRCC_u8EnablePeripheralClock(AHB1,0);
	MRCC_u8EnablePeripheralClock(AHB1,1);
	MRCC_u8EnablePeripheralClock(APB1,1);
	MRCC_u8EnablePeripheralClock(APB1,0);

	Timer2_Init();
	Timer2_Reset_Counter();
	MSTK_voidInit();
	HServo_Init();
	HServo_Rotate(Angle_90);
	HMotor_Init();
	HMotor_Move(Direction_Forward,speed);

	Ultrasonic_Init();

	Ultrasonic_Trigger();
	Distance=Ultrasonic_Read();

	while(1)
	{
		while (Distance>Obstacle_Distance)
		{

			if ((Distance<Decrease_Distance_1)&&(Distance>Decrease_Distance_2)&&(Distance!=LastDistance)&&speed>=400)
			{
				speed-=40;
			}
			else if ((Distance<Decrease_Distance_2)&&(Distance!=LastDistance)&&speed>400)
			{
				speed-=40;
			}
			else if ((speed<800)&&(Distance!=LastDistance))
			{
					speed+=100;
			}
			else
			{
				//do nothing
			}
			HMotor_Move(Direction_Forward,speed);
			MSTK_voidSetBusyWait(200000);
			Ultrasonic_Trigger();
			LastDistance=Distance;
			Distance=Ultrasonic_Read();
		}


		HMotor_Move(Direction_Backward,speed);
		MSTK_voidSetBusyWait(1000000);
		HMotor_Move(Direction_Stop,stopspeed);




		HServo_Rotate(Angle_0);
		MSTK_voidSetBusyWait(Delay_Servo);
		Ultrasonic_Trigger();
		RightDistance=Ultrasonic_Read();

		HServo_Rotate(Angle_180);
		MSTK_voidSetBusyWait(Delay_Servo);
		Ultrasonic_Trigger();
		LeftDistance=Ultrasonic_Read();

		HServo_Rotate(Angle_90);

		if (LeftDistance < RightDistance)
		{
			HMotor_Move(Direction_Left, TurnSpeed);
			MSTK_voidSetBusyWait(TurnDelay);
		}

		else
		{
			HMotor_Move(Direction_Right, TurnSpeed);
			MSTK_voidSetBusyWait(TurnDelay);
		}


		Ultrasonic_Trigger();
		LastDistance=Distance;
		Distance=Ultrasonic_Read();



	}

}












