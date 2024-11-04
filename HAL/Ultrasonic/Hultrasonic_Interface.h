#ifndef HULTRASONIC_INTERFACE_H
#define HULTRASONIC_INTERFACE_H


/************************************ Ultrasonic Trigger Function ******************************/
/***
Function Name        : Ultrasonic_Trigger
Function Purpose     : It allows the sensor trig pin to send signal for 10 MicroSec 
Function description : In the ultrasonic sensor in order to read the signal you need to send signal for 10 micro second
                       which the ultrasonic send eight cycle sonic burst at 40 KHZ
					   and receive in the echo pin  
***/ 
void Ultrasonic_Trigger (void);  

/************************************ Ultrasonic Initialization Function ******************************/
/***
Function Name        : Ultrasonic_Init	
Function Purpose     : It used for the intialization of the pins of ultrasonic sensor
Function description : this function used to access two pins of the ultrasonic trigger pin and
                       the echo pin from the Gpio periphral
***/ 
void Ultrasonic_Init (void); 

/************************************ Ultrasonic Reading Function ******************************/
/***
Function Name        : Ultrasonic_Read	
Function Purpose     : It used to get the read of the ultrasonic sensor
Function description : this function take the first capture from the icu and take the second and give me
                       the time between the two captures in order to know the 
***/ 
f32 Ultrasonic_Read (void);






#endif
