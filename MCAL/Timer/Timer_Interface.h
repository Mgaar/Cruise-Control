//M.G3AR 30/10/2023
#ifndef TIMER_INTERFACE_H_
#define TIMER_INTERFACE_H_

void Timer3_PWM_Init( u8 channel ,u16 Duty);


void Timer2_Reset_Counter(void);
void Timer2_Init(void);
void TIM2_Stop (void);
void TIM2_start (void);
u32 TIM2_CaptureRead (void);
void TIM2SetCallBack (void (*localpointer)(void));
void capture (void);



#endif
