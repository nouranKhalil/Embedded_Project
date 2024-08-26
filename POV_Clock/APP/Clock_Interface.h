/*
 * Clock_Interface.h
 *
 *  Created on: Aug 26, 2024
 *      Author: nouran
 */

#ifndef APP_CLOCK_INTERFACE_H_
#define APP_CLOCK_INTERFACE_H_

#define RPM 	13750
#define FREQ 	(13750 / 60)
#define T 		(60 / 13750)

#define LEDS_PORT1 DIO_PORTA

#define LEDS_PIN0 0
#define LEDS_PIN1 1
#define LEDS_PIN2 2
#define LEDS_PIN3 3
#define LEDS_PIN4 4
#define LEDS_PIN5 5
#define LEDS_PIN6 6
#define LEDS_PIN7 7

#define LEDS_PORT2 DIO_PORTC

#define LEDS_PIN8 6
#define LEDS_PIN9 7

#define HALL_SENSOR_PORT DIO_PORTB

#define HALL_SENSOR_PIN 0


void vInitClock(void);
void vClockCircumference(void);
void vClockSecondsMark(void);
void vClockMinutesMark(void);
void vClockHoursMark(void);
void vSecondsHand(void);
void vMinutesHand(void);
void vHoursHand(void);
void vClearLEDs(void);
void vClockDisplay(u32 hours, u32 min, u32 sec);
void vPrintString(u8 *ch);
void printLetter(u8 ch);
void vClockDisplayDigital(u32 hours, u32 min, u32 sec);

#endif /* APP_CLOCK_INTERFACE_H_ */
