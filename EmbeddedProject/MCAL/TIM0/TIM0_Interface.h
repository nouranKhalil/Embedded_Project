/*
 * Timer0_Interface.h
 *
 *  Created on: Aug 5, 2024
 *      Author: Ahmed Saber
 */

#ifndef MCAL_TIMERS_TIMER0_INTERFACE_H_
#define MCAL_TIMERS_TIMER0_INTERFACE_H_

#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"
/*************************TIMER0*************************/

/*Timers Pre-scalers Options*/
#define		TIMER_SCALER_1     	 	1
#define		TIMER_SCALER_8    		2
#define	    TIMER_SCALER_64 		3
#define 	TIMER_SCALER_256        4
#define 	TIMER_SCALER_1024       5
#define 	EXTERNALl_FALLING       6
#define 	EXTERNAL_RISING         7

/*Timer0 Mode Options */
#define		TIMER0_NORMAL_MODE        0
#define		TIMER0_PHASECORRECT_MODE  1
#define		TIMER0_CTC_MODE           2
#define		TIMER0_FASTPWM_MODE       3

/*Timers OCx Pin Options*/
#define 	TIMER_OC_DISCONNECTED		0
#define 	TIMER_OC_TOGGLE				1
#define 	TIMER_OC_NON_INVERTING		2
#define 	TIMER_OC_INVERTING			3


void vTIMER0_Init(void);

void vTIMER0_Start(void);

void vTIMER0_Stop(void);

void vTimer0_SetMode(u8 mode);

void vTimer0_OC0_SetMode(u8 mode);

void vTimer0_SetPreLoad(u8 value);

void vTimer0_SetOCRValue(u8 value);

void vTimer0_OVF_InterruptEnable(void);

void vTimer0_OVF_InterruptDisable(void);

void vTimer0_OCM_InterruptEnable(void);

void vTimer0_OCM_InterruptDisable(void);

void vTimer0_PrescalerSelect(u8 prescaler);

/****************************** Timer 1 ********************************/

/*Timer1 Mode Options */
#define TIMER1_NORMAL_MODE							0
#define TIMER1_PWM_PHASE_CORRECT_MODE_8				1
#define TIMER1_PWM_PHASE_CORRECT_MODE_9				2
#define TIMER1_PWM_PHASE_CORRECT_MODE_10			3
#define TIMER1_CTC_MODE_OCRA_IS_TOP					4
#define TIMER1_PWM_FAST_MODE_8						5
#define TIMER1_PWM_FAST_MODE_9						6
#define TIMER1_PWM_FAST_MODE_10						7
#define TIMER1_PWM_PHASE_FREQ_CORRECT_ICR_IS_TOP	8
#define TIMER1_PWM_PHASE_FREQ_CORRECT_OCRA_IS_TOP	9
#define TIMER1_PWM_PHASE_CORRECT_ICR_IS_TOP			10
#define TIMER1_PWM_PHASE_CORRECT_OCRA_IS_TOP		11
#define TIMER1_CTC_MODE_ICR_IS_TOP					12
#define TIMER1_PWM_FAST_MODE_ICR_IS_TOP				14
#define TIMER1_PWM_FAST_MODE_OCRA_IS_TOP			15

void vTimer1_Init(void);
void vTimer1_Start(void);
void vTimer1_Stop(void);
void vTimer1_SetMode(u8 mode);

void vTimer1_OC1A_SetMode(u8 mode);
void vTimer1_OC1B_SetMode(u8 mode);

void vTimer1_SetPreLoad(u16 value);

void vTimer1_SetOCR_A_Value(u16 value);
void vTimer1_SetOCR_B_Value(u16 value);

void vTimer1_SetICR_Value(u16 value);

void vTimer1_OVF_InterruptEnable(void);

void vTimer1_OVF_InterruptDisable(void);

void vTimer1_OCM_A_InterruptEnable(void);

void vTimer1_OCM_A_InterruptDisable(void);

void vTimer1_OCM_B_InterruptEnable(void);

void vTimer1_OCM_B_InterruptDisable(void);

void vTimer1_PrescalerSelect(u8 prescaler);

#endif /* MCAL_TIMERS_TIMER0_INTERFACE_H_ */
