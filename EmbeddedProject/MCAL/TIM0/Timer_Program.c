/*
 * Timer_Program.c
 *
 *  Created on: Aug 12, 2024
 *      Author: ZBook G3
 */

#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"
#include "../DIO/DIO_Interface.h"
#include "Timer_Private.h"
#include "Timer_Config.h"
#include "Timer_Interface.h"
void MTIMER0_VoidInit(void){
	//select mode
// //	normal mode
//	clr_bit(TCCR0,TCCR0_WGM00);
//	clr_bit(TCCR0,TCCR0_WGM01);
// Other Modes uncomment desired one and comment the rest
//	//PWM
//	set_bit(TCCR0,TCCR0_WGM00);
//	clr_bit(TCCR0,TCCR0_WGM01);
	//CTC
	clr_bit(TCCR0,TCCR0_WGM00);
	set_bit(TCCR0,TCCR0_WGM01);
//	//Fast PWM
//	set_bit(TCCR0,TCCR0_WGM00);
//	set_bit(TCCR0,TCCR0_WGM01);
	//Compare Match Output Mode

	// select value
	TCNT0 = 0x00;
	OCR0 = 0x00;
	//interrupt enable / disable

	clr_bit(TIMSK,TIMSK_TOIE0);
	//disable ctc interrupt
	set_bit(TIMSK,TIMSK_OCIE0);
	//clear flag
	set_bit(TIFR,TIFR_TOV0);
	set_bit(TIFR,TIFR_OCF0);




}
void MTIMER0_VoidStart(void){
	//PRESCALER 8
	clr_bit(TCCR0,TCCR0_CS00);
	set_bit(TCCR0,TCCR0_CS01);
	clr_bit(TCCR0,TCCR0_CS02);

}
void MTIMER0_VoidStop(void){
	// no prescaler
	clr_bit(TCCR0,TCCR0_CS00);
	clr_bit(TCCR0,TCCR0_CS01);
	clr_bit(TCCR0,TCCR0_CS02);
}
void MTIMER0_VoidSetPreloadValue(u8 Copy_u8PreloadValue){
	TCNT0 = Copy_u8PreloadValue;
}
void MTIMER0_VoidBusyWait_OVMode(u32 Copy_u32Time){
	// so that we multiply desired time with a whole number 1000/250
	MTIMER0_VoidSetPreloadValue(6);
	// number of overflows = time *1000 (because time is in ms)/(2^ res - preload value)
    u32 counter = 0;
	u32 NUMBER_OF_OV =((u32) (Copy_u32Time) * 1000UL / 250);

	// res = 8
	// pres = 8
	// time = 1ms
	// freq = 8000000

	// timer freq = 1 MHZ
	// tick time = 1 microsec
	// # of overloads = 1ms / 256 = 3.9
	// preload value = 24

	while(counter < NUMBER_OF_OV){
		// BUSY WAIT TILL OVER FLOW
		while((get_bit(TIFR,TIFR_TOV0) == 0));
		set_bit(TIFR,TIFR_TOV0);
		counter++;
		MTIMER0_VoidSetPreloadValue(6);
	}


}
void MTIMER0_VoidCompareMatch(u32 Copy_u32Value){
	OCR0 = Copy_u32Value;
}
void MTIMER0_VoidBusyWait_CTCMode(u32 Copy_u32Time){
	MTIMER0_VoidCompareMatch(250);
	// number of overflows = time *1000 (because time is in ms)/(2^ res - preload value)
    u32 counter = 0;
	u32 NUMBER_OF_OV =((u32) (Copy_u32Time) * 1000UL / 250);

	// res = 8
	// pres = 8
	// time = 1ms
	// freq = 8000000

	// timer freq = 1 MHZ
	// tick time = 1 microsec
	// # of overloads = 1ms / 256 = 3.9
	// preload value = 24

	while(counter < NUMBER_OF_OV){
		// BUSY WAIT TILL OVER FLOW
		while((get_bit(TIFR,TIFR_OCF0) == 0));
		set_bit(TIFR,TIFR_OCF0);
		counter++;
		//MTIMER0_VoidCompareMatch(250);
	}
	CLR_REG(OCR0);
}

