
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

#define RPM 	13750
#define FREQ 	(13750 / 60)
#define T 		(60 / 13750)

void vInitClock(void);
void vClockCircumference(void);
void vClockSecondsMark(void);
void vClockMinutesMark(void);
void vClockHoursMark(void);
void vSecondsHand(void);
void vMinutesHand(void);
void vHoursHand(void);
void vClearLEDs(void);

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
	vClockDisplay();
}

int main(void)
{

	vInitClock();
	vClockCircumference();
	vTimer1_Init();
	MGIE_voidEnableInterrupt();

	while(1)
	{
		if(DIO_u8GetPinValue(DIO_PORTB, PIN0)){
			vClockDisplay();
		}
	}
}

void vInitClock(void){
	/* LEDs Port */
	DIO_voidSetPortSpecificDirection(DIO_PORTA, 0xff);
	DIO_voidSetPinDirection(DIO_PORTC, PIN6, OUTPUT);
	DIO_voidSetPinDirection(DIO_PORTC, PIN7, OUTPUT);
	/* Hall Sensor Port */
	DIO_voidSetPinDirection(DIO_PORTB, PIN0, INPUT);
}

void vClockCircumference(void){
	DIO_voidSetPinValue(DIO_PORTA, PIN0, HIGH);
//	DIO_voidSetPinValue(DIO_PORTA, PIN1, HIGH);
}

void vClockSecondsMark(void){
	DIO_voidSetPinValue(DIO_PORTA, PIN1, HIGH);
}

void vClockMinutesMark(void){
	DIO_voidSetPinValue(DIO_PORTA, PIN1, HIGH);
	DIO_voidSetPinValue(DIO_PORTA, PIN2, HIGH);
}

void vClockHoursMark(void){
	DIO_voidSetPinValue(DIO_PORTA, PIN1, HIGH);
	DIO_voidSetPinValue(DIO_PORTA, PIN2, HIGH);
	DIO_voidSetPinValue(DIO_PORTA, PIN3, HIGH);
}

void vSecondsHand(void){
	DIO_voidSetPinValue(DIO_PORTA, PIN4, HIGH);
	DIO_voidSetPinValue(DIO_PORTA, PIN5, HIGH);
	DIO_voidSetPinValue(DIO_PORTA, PIN6, HIGH);
	DIO_voidSetPinValue(DIO_PORTA, PIN7, HIGH);
	DIO_voidSetPinValue(DIO_PORTC, PIN6, HIGH);
	DIO_voidSetPinValue(DIO_PORTC, PIN7, HIGH);
}

void vMinutesHand(void){
	DIO_voidSetPinValue(DIO_PORTA, PIN5, HIGH);
	DIO_voidSetPinValue(DIO_PORTA, PIN6, HIGH);
	DIO_voidSetPinValue(DIO_PORTA, PIN7, HIGH);
	DIO_voidSetPinValue(DIO_PORTC, PIN6, HIGH);
	DIO_voidSetPinValue(DIO_PORTC, PIN7, HIGH);
}

void vHoursHand(void){
	DIO_voidSetPinValue(DIO_PORTA, PIN6, HIGH);
	DIO_voidSetPinValue(DIO_PORTA, PIN7, HIGH);
	DIO_voidSetPinValue(DIO_PORTC, PIN6, HIGH);
	DIO_voidSetPinValue(DIO_PORTC, PIN7, HIGH);
}
void vClearLEDs(void){
	/* LEDs Port */
	DIO_voidSetPortSpecificValue(DIO_PORTA, 0x01); // Don't clear the Circumference
	DIO_voidSetPinValue(DIO_PORTC, PIN6, LOW);
	DIO_voidSetPinValue(DIO_PORTC, PIN7, LOW);
}

void vClockDisplay(void){
	u32 ticks = 0, position = 0;
	while(ticks < 60){
		vClockSecondsMark();
		if(position % 5 == 0) vClockMinutesMark();
		if(position % 3 == 0) vClockHoursMark();
		if(position == sec) vSecondsHand();
		if(position == min)	vMinutesHand();
		if(position / 5 == hours) vHoursHand();
		ticks ++;
		position ++;
		_delay_us(560); // depends on the motor
		vClearLEDs();
		_delay_us(2400); // depends on the
	}
}



