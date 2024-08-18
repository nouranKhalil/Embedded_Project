/*
 * EXTI_Private.h
 *
 *  Created on: Aug 6, 2024
 *      Author: Abdelrahman Nasr
 */

#ifndef MCAL_EXTI_EXTI_PRIVATE_H_
#define MCAL_EXTI_EXTI_PRIVATE_H_

// interrupt pins

#define EXTI0_PORT DIO_PORTD
#define EXTI0_PIN  PIN2

#define EXTI1_PORT DIO_PORTD
#define EXTI1_PIN  PIN3

#define EXTI2_PORT DIO_PORTB
#define EXTI2_PIN  PIN2



///

#define INTERNAL_PULLUP 0
#define EXTERNAL_PULLUP 1
#define EXTERNAL_PULLDOWN 2



// reg dfination
// bits

#define MCUCR  *((volatile u8*)(0x55))

#define MCUCR_ISC00		0
#define MCUCR_ISC01		1
#define MCUCR_ISC10		2
#define MCUCR_ISC11		3


#define MCUCSR  *((volatile u8*)(0x54))

#define MCUCSR_ISC2		6



#define GICR  *((volatile u8*)(0x5B))

#define GICR_INT1	7
#define GICR_INT0	6
#define GICR_INT2	5


#define GIFR  *((volatile u8*)(0x5A))


#define GIFR_INTF1	7
#define GIFR_INTF0	6
#define GIFR_INTF2	5




#endif /* MCAL_EXTI_EXTI_PRIVATE_H_ */
