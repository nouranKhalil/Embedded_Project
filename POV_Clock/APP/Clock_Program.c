/*
 * Clock_Program.c
 *
 *  Created on: Aug 26, 2024
 *      Author: nouran
 */


#include <util/delay.h>
#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"
#include "../MCAL/DIO/DIO_interface.h"

#include "Clock_Config.h"
#include "Clock_Interface.h"

void vInitClock(void){
	/* LEDs Port */
	DIO_voidSetPortSpecificDirection(LEDS_PORT1, 0xff);
	DIO_voidSetPinDirection(LEDS_PORT2, LEDS_PIN6, OUTPUT);
	DIO_voidSetPinDirection(LEDS_PORT2, LEDS_PIN7, OUTPUT);
	/* Hall Sensor Port */
	DIO_voidSetPinDirection(HALL_SENSOR_PORT, HALL_SENSOR_PIN, INPUT);
}

/************************Analog Clock************************/
void vClockCircumference(void){
	DIO_voidSetPinValue(LEDS_PORT1, LEDS_PIN0, HIGH);
}

void vClockSecondsMark(void){
	DIO_voidSetPinValue(LEDS_PORT1, LEDS_PIN1, HIGH);
}

void vClockMinutesMark(void){
	DIO_voidSetPinValue(LEDS_PORT1, LEDS_PIN1, HIGH);
	DIO_voidSetPinValue(LEDS_PORT1, LEDS_PIN2, HIGH);
}

void vClockHoursMark(void){
	DIO_voidSetPinValue(LEDS_PORT1, LEDS_PIN1, HIGH);
	DIO_voidSetPinValue(LEDS_PORT1, LEDS_PIN2, HIGH);
	DIO_voidSetPinValue(LEDS_PORT1, LEDS_PIN3, HIGH);
}

void vSecondsHand(void){
	DIO_voidSetPinValue(LEDS_PORT1, LEDS_PIN4, HIGH);
	DIO_voidSetPinValue(LEDS_PORT1, LEDS_PIN5, HIGH);
	DIO_voidSetPinValue(LEDS_PORT1, LEDS_PIN6, HIGH);
	DIO_voidSetPinValue(LEDS_PORT1, LEDS_PIN7, HIGH);
	DIO_voidSetPinValue(LEDS_PORT2, LEDS_PIN8, HIGH);
	DIO_voidSetPinValue(LEDS_PORT2, LEDS_PIN9, HIGH);
}

void vMinutesHand(void){
	DIO_voidSetPinValue(LEDS_PORT1, LEDS_PIN5, HIGH);
	DIO_voidSetPinValue(LEDS_PORT1, LEDS_PIN6, HIGH);
	DIO_voidSetPinValue(LEDS_PORT1, LEDS_PIN7, HIGH);
	DIO_voidSetPinValue(LEDS_PORT2, LEDS_PIN8, HIGH);
	DIO_voidSetPinValue(LEDS_PORT2, LEDS_PIN9, HIGH);
}

void vHoursHand(void){
	DIO_voidSetPinValue(LEDS_PORT1, LEDS_PIN6, HIGH);
	DIO_voidSetPinValue(LEDS_PORT1, LEDS_PIN7, HIGH);
	DIO_voidSetPinValue(LEDS_PORT2, LEDS_PIN8, HIGH);
	DIO_voidSetPinValue(LEDS_PORT2, LEDS_PIN9, HIGH);
}
void vClearLEDs(void){
	/* LEDs Port */
	DIO_voidSetPortSpecificValue(LEDS_PORT1, 0x01); // Don't clear the Circumference
	DIO_voidSetPinValue(LEDS_PORT2, LEDS_PIN8, LOW);
	DIO_voidSetPinValue(LEDS_PORT2, LEDS_PIN9, LOW);
}

void vClockDisplay(u32 hours, u32 min, u32 sec){
	u32 ticks = 0, position = 0;
	while(ticks < 60){
		vClockSecondsMark();
		if(position % 5 == 0) vClockMinutesMark();
		if(position % 3 == 0) vClockHoursMark();
		if(position == sec) vSecondsHand();
		if(position == min)	vMinutesHand();
		if(position / 5 == hours) vHoursHand();
		ticks ++;
		position ++; // update according to sensor position
		_delay_us(280); // increase for low speed motor decrease for high speed motor
		vClearLEDs();
		_delay_us(1200); // increase for low speed motor decrease for high speed motor
	}
}
/************************Digital Clock************************/


void vClockDisplayDigital(u32 hours, u32 min, u32 sec){
	u8 time[9], i = 8;
	time[i--] = '\0';
	for(; i >= 6; i--){
		time[i] = sec % 10;
		sec /= 10;
	}
	time[i--] =  ':';
	for(; i >= 3; i--){
		time[i] = min % 10;
		min /= 10;
	}
	time[i--] =  ':';
	for(; i >= 0; i--){
		time[i] = hours % 10;
		hours /= 10;
	}
}

/************************Print String************************/

void vPrintString(u8 *ch){
	u8 i = 0;
	while(*(ch + i) != '\0'){
		printLetter(*(ch + i));
		i++;
	}
}

void printLetter(u8 ch){
	 if (ch < 32 || ch > 126){
		 ch = 32;
	}
	ch -= 32;
	for(u8 i = 0; i < charWidth; i++){
		DIO_voidSetPortSpecificValue(LEDS_PORT1, font[ch][i]);
		_delay_us(280);// increase for low speed motor decrease for high speed motor
		vClearLEDs();
		_delay_us(1200);// increase for low speed motor decrease for high speed motor
	}

}
