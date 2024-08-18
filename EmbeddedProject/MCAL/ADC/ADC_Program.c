/*
 * ADC_Program.c
 *
 *  Created on: Aug 11, 2024
 *      Author: Abdelrahman Nasr
 */

#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"

#include "ADC_Private.h"
#include "ADC_Config.h"
#include "ADC_Interface.h"


void MADC_VoidInit(void)
{
//	// ENABLE ADC
//
//	// enable auto trigger
//	//SET_BIT(ADCSRA,ADCSRA_ADATE);
//
//// slect ref
//
//#if ADC_REFRENCE_SELECTION == AREF
//	ADMUX &= REF_SEL_BIT_MASK;
//	ADMUX |= ADC_REFRENCE_SELECTION;
//#endif
//
//
//
//	// prescaller
//	/*check prescaler */
//
//#if ADC_PRESCALER_VALUE == PRE_DIV_BY_128
//	ADCSRA &= PRES_SEL_BIT_MASK;
//	ADCSRA |= ADC_PRESCALER_VALUE;
//#endif
//
//	//ADC_ADJUST
//// RIGHT ADJUST
//	CLR_BIT(ADMUX,ADMUX_ADLAR);
//
//
//#if ADC_ENABLE == ENABLE
//	SET_BIT(ADCSRA,ADCSRA_ADEN);
//#elif   ADC_ENABLE == DISABLE
//	CLR_BIT(ADCSRA,ADCSRA_ADEN);
//#endif

	// ADC Enable
		SET_BIT(ADCSRA,7);

		// Prescaler Configuration as 128
		SET_BIT(ADCSRA,2);
		SET_BIT(ADCSRA,1);
		SET_BIT(ADCSRA,0);


		// Referance Voltage as AVCC with external capacitor
		CLR_BIT(ADMUX,7);
		SET_BIT(ADMUX,6);

		// ADC Data Rgith Adjustment
		CLR_BIT(ADMUX,5);

}

u16 MADC_u8StartConversion(u8 Copy_u8ChannelNum)
{

	u8 Local_u8DigitalValue;
//	    /*Set The Channel Of ADC*/
//	    ADMUX &= CHANAEL_SEL_BIT_MASK;
//	    ADMUX |= Copy_u8ChannelNum;
//
//	    /*Start The ADC To Convert The Input Analog Signal*/
//	    SET_BIT(ADCSRA, ADCSRA_ADSC);
//	    /*Polling (busy wait) till the flag is raised*/
//	    while(GET_BIT(ADCSRA, ADCSRA_ADIF) == FALSE);
//	    /*Clear The Flag*/
//	    SET_BIT(ADCSRA, ADCSRA_ADIF);
/////*
////	    /*Check For Left or Right Adjust*/
////	    #if ADC_ADJUST_RESULT == LEFT_ADJUST
////	        Local_u8DigitalValue =  ADCH;
////	    #elif ADC_ADJUST_RESULT == RIGHT_ADJUST
////	        Local_u8DigitalValue =  ADCL;
////	    #endif
////*/
//
//
//	    /*Return The Digital Value*/
//	    return ADCHL;
	// ADC Channel Selection
	Copy_u8ChannelNum &= 0x07;
		ADMUX &= 0xE0;
		ADMUX |= Copy_u8ChannelNum;

		// Start Single Convertion
		SET_BIT(ADCSRA,6);

		//wait for the conversion
		while(!(ADCSRA & (1<<4)));

		//ADC Flag Clear
		SET_BIT(ADCSRA,4);
#if ADC_ADJUST_RESULT == LEFT_ADJUST
	        Local_u8DigitalValue =  ADCH;
	    #elif ADC_ADJUST_RESULT == RIGHT_ADJUST
	        Local_u8DigitalValue =  ADCL;
	    #endif
		return Local_u8DigitalValue;
}
