
#ifndef F_CPU
#define F_CPU 8000000UL // 8 MHz clock speed
#endif

#include <util/delay.h>
#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"
#include "../MCAL/DIO/DIO_interface.h"
#include "../MCAL/EXTI/EXTI_Interface.h"
#include "../MCAL/GIE/GIE_Interface.h"
#include "../MCAL/TIM0/Timer_Interface.h"
#include "Clock_Interface.h"


u32 sec = 0, min = 5, hours = 3;

ISR(TIMER1_COMPA_vect) {
	sec++;
	if(sec == 60){
		sec = 0;
		min ++;
	}
	if(min == 60){
		min = 0;
		hours ++;
	}
	if(hours == 12){
		hours = 0;
	}
	vClockDisplay(hours, min, sec);
}

int main(void)
{
	vInitClock();
	/************************Analog Clock Start************************/
//	vClockCircumference();
//	vTimer1_Init();
//	MGIE_voidEnableInterrupt();
//
//	while(1)
//	{
//		if(DIO_u8GetPinValue(HALL_SENSOR_PORT, HALL_SENSOR_PIN)){
//			vClockDisplay(hours, min, sec);
//		}
//	}
	/************************Analog Clock End************************/

	/************************Digital Clock Start************************/
//	vTimer1_Init();
//	MGIE_voidEnableInterrupt();
//	while(1){
//		if(DIO_u8GetPinValue(HALL_SENSOR_PORT, HALL_SENSOR_PIN)){
//			vClockDisplayDigital(hours, min, sec);
//		}
//	}
	/************************Digital Clock End************************/

	/************************Print String Start************************/
	while(1){
		if(DIO_u8GetPinValue(HALL_SENSOR_PORT, HALL_SENSOR_PIN)){
			vPrintString("Hello");
		}
	}
	/************************Print String End************************/
}



