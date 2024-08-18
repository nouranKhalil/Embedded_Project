/*
 * ADC_Interface.h
 *
 *  Created on: Aug 11, 2024
 *      Author: Abdelrahman Nasr
 */

#ifndef MCAL_ADC_ADC_INTERFACE_H_
#define MCAL_ADC_ADC_INTERFACE_H_

#define ENABLE 1
#define DISABLE 0


// difination channel
#define CHANNEL_0 0b00000000
#define CHANNEL_1 0b00000001
#define CHANNAL_2 0b00000010
#define CHANNAL_3 0b00000011
#define CHANNAL_4 0b00000100
#define CHANNAL_5 0b00000101
#define CHANNAL_6 0b00000110
#define CHANNAL_7 0b00000111


void MADC_VoidInit(void);

u16 MADC_u8StartConversion(u8 Copy_u8ChannelNum);







#endif /* MCAL_ADC_ADC_INTERFACE_H_ */
