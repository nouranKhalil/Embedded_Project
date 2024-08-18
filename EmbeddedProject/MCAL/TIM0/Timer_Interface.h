/*
 * Timer_Interface.h
 *
 *  Created on: Aug 12, 2024
 *      Author: ZBook G3
 */

#ifndef MCAL_TIMER_TIMER_INTERFACE_H_
#define MCAL_TIMER_TIMER_INTERFACE_H_


void MTIMER0_VoidInit(void);
void MTIMER0_VoidStart(void);
void MTIMER0_VoidStop(void);
void MTIMER0_VoidBusyWait_OVMode(u32 Copy_u32Time);
void MTIMER0_VoidBusyWait_CTCMode(u32 Copy_u32Time);
void MTIMER0_VoidSetPreloadValue(u8 Copy_u8PreloadValue);
void MTIMER0_VoidCompareMatch(u32 Copy_u32Value);
#endif /* MCAL_TIMER_TIMER_INTERFACE_H_ */
