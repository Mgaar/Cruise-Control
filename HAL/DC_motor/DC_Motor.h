#ifndef _DC_MOTOR_H_
#define _DC_MOTOR_H_




#define Direction_Stop          (u8)0
#define Direction_Forward       (u8)1
#define Direction_Backward      (u8)2
#define Direction_Right         (u8)3
#define Direction_Left          (u8)4



void HMotor_Init(void);


void HMotor_Move(u8 Direction, u16 Speed);


#endif
