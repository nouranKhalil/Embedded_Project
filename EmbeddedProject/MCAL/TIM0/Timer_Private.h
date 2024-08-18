/*
 * Timer_Private.h
 *
 *  Created on: Aug 12, 2024
 *      Author: ZBook G3
 */

#ifndef MCAL_TIMER_TIMER_PRIVATE_H_
#define MCAL_TIMER_TIMER_PRIVATE_H_

#define TCCR0 *((volatile u8*)0x53)
#define TCCR0_CS00 PIN_0
#define TCCR0_CS01 PIN_1
#define TCCR0_CS02 PIN_2
#define TCCR0_WGM01 PIN_3
#define TCCR0_COM00 PIN_4
#define TCCR0_COM01 PIN_5
#define TCCR0_WGM00 PIN_6
#define TCCR0_FOC0 PIN_7

#define TCNT0 *((volatile u8*)0x52)

#define OCR0 *((volatile u8*)0x5C)
#define TIMSK *((volatile u8*)0x59)
#define TIMSK_OCIE0 PIN_1
#define TIMSK_TOIE0 PIN_0

#define TIFR *((volatile u8*)0x58)
#define TIFR_OCF0 PIN_1
#define TIFR_TOV0 PIN_0
#endif /* MCAL_TIMER_TIMER_PRIVATE_H_ */
