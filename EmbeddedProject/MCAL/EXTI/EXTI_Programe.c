/*
 * EXTI_Programe.c
 *
 *  Created on: Aug 6, 2024
 *      Author: Abdelrahman Nasr
 */
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"
#include "../DIO/DIO_interface.h"

#include "EXTI_Config.h"
#include "EXTI_Private.h"
#include "EXTI_Interface.h"

// pointer to function
 void (*EXTI_pvoidINT0NotifiFunction) (void) = NULL;

//// notifiction for INT1


/// notifiction for INT1

void MEXTI_VoidInitpin(u8 Copy_u8InterruptNum)
{
	// swich TO CHOOSE interrupt number -- Init PINS thatuse for interrupt  -- internal pull up (pin - INPUT - high )
	// init interrupt pin
	switch (Copy_u8InterruptNum) {
	case EXTI_INT0:

		DIO_voidSetPinDirection(EXTI0_PORT,EXTI0_PIN,INPUT);
		DIO_voidSetPinValue(EXTI0_PORT,EXTI0_PIN,HIGH);

		break;
	case EXTI_INT1:
		DIO_voidSetPinDirection(EXTI1_PORT,EXTI1_PIN,INPUT);
		DIO_voidSetPinValue(EXTI1_PORT,EXTI1_PIN,HIGH);

		break;
	case EXTI_INT2:
		DIO_voidSetPinDirection(EXTI2_PORT,EXTI2_PIN,INPUT);
		DIO_voidSetPinValue(EXTI2_PORT,EXTI2_PIN,HIGH);

		break;
	default:
		break;
	}
}


void MEXTI_VoidTriggerEdge(u8 Copy_u8InterruptNum,u8 Copy_u8Edge)
{

	// choose interrupt
	// choose mode (EDGE)

	// set or clr for the bits

	// low level (clr_bit iscx0- clr_bit iscx1)
	// any logical (Set_bit iscx0- clr_bit iscx1)
	// Falling (clr_bit iscx0- set_bit iscx1)
	// Rising  (set_bit iscx0- set_bit iscx1)

	switch(Copy_u8InterruptNum)
	{
	case EXTI_INT0:
		switch (Copy_u8Edge) {
		case LOW_LEVEL:
			CLR_BIT(MCUCR,MCUCR_ISC00);
			CLR_BIT(MCUCR,MCUCR_ISC01);
			break;
		case ANY_LOGIC_CHANGE:
			SET_BIT(MCUCR,MCUCR_ISC00);
			CLR_BIT(MCUCR,MCUCR_ISC01);
			break;
		case FALLING_EDGE:
			CLR_BIT(MCUCR,MCUCR_ISC00);
			SET_BIT(MCUCR,MCUCR_ISC01);
			break;
		case RISING_EDGE:
			SET_BIT(MCUCR,MCUCR_ISC00);
			SET_BIT(MCUCR,MCUCR_ISC01);
			break;

		default:
			break;
		}
		break;
		case EXTI_INT1:
			switch (Copy_u8Edge) {
			case LOW_LEVEL:
				CLR_BIT(MCUCR,MCUCR_ISC10);
				CLR_BIT(MCUCR,MCUCR_ISC11);
				break;
			case ANY_LOGIC_CHANGE:
				SET_BIT(MCUCR,MCUCR_ISC10);
				CLR_BIT(MCUCR,MCUCR_ISC11);
				break;
			case FALLING_EDGE:
				CLR_BIT(MCUCR,MCUCR_ISC10);
				SET_BIT(MCUCR,MCUCR_ISC11);
				break;
			case RISING_EDGE:
				SET_BIT(MCUCR,MCUCR_ISC10);
				SET_BIT(MCUCR,MCUCR_ISC11);
				break;

			default:
				break;
			}
			break;
			case EXTI_INT2:
				switch (Copy_u8Edge) {


				case FALLING_EDGE:
					CLR_BIT(MCUCSR,MCUCSR_ISC2);
					break;
				case RISING_EDGE:
					SET_BIT(MCUCSR,MCUCSR_ISC2);
					break;

				default:
					break;
				}
				break;

				default:
					break;
	}

}


void MEXTI_VoidEnable(u8 Copy_u8InterruptNum)
{
	switch(Copy_u8InterruptNum)
	{
	case EXTI_INT0:
		SET_BIT(GICR,GICR_INT0);
		break;
	case EXTI_INT1:
		SET_BIT(GICR,GICR_INT1);
		break;
	case EXTI_INT2:
		SET_BIT(GICR,GICR_INT2);
		break;
	}

}


void MEXTI_VoidDisable(u8 Copy_u8InterruptNum)
{
	switch(Copy_u8InterruptNum)
	{
	case EXTI_INT0:
		CLR_BIT(GICR,GICR_INT0);
		break;
	case EXTI_INT1:
		CLR_BIT(GICR,GICR_INT1);
		break;
	case EXTI_INT2:
		CLR_BIT(GICR,GICR_INT2);
		break;
	}
}




void EXTI_voidINT0SetCallback(void (*NotificationFunction)(void))
{
	EXTI_pvoidINT0NotifiFunction = NotificationFunction;
}

/*ISR For INT0*/
void __vector_1 (void) __attribute__((signal));
void __vector_1 (void)
{
	if(EXTI_pvoidINT0NotifiFunction != NULL)
	{
		/*Invoke The Global Pointer To Function*/
		EXTI_pvoidINT0NotifiFunction();
	}
	else
	{
		/*Do Nothing*/
	}
}
