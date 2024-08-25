/*
 * EXTI_Interface.h
 *
 *  Created on: Aug 6, 2024
 *      Author: Abdelrahman Nasr
 */

#ifndef MCAL_EXTI_EXTI_INTERFACE_H_
#define MCAL_EXTI_EXTI_INTERFACE_H_

#define EXTI_INT0		0
#define EXTI_INT1		1
#define EXTI_INT2		2


#define LOW_LEVEL			0
#define ANY_LOGIC_CHANGE 	1
#define FALLING_EDGE 		2
#define RISING_EDGE			3


//funtion
void MEXTI_VoidInitpin(u8 Copy_u8InterruptNum);
void MEXTI_VoidTriggerEdge(u8 Copy_u8InterruptNum,u8 Copy_u8Edge);
void MEXTI_VoidEnable(u8 Copy_u8InterruptNum);
void MEXTI_VoidDisable(u8 Copy_u8InterruptNum);
void EXTI_voidINT0SetCallback(void (*NotificationFunction)(void));





#endif /* MCAL_EXTI_EXTI_INTERFACE_H_ */
