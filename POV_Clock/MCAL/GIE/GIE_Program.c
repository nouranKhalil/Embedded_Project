/*
 * GIE_Program.c
 *
 *  Created on: Aug 6, 2024
 *      Author: Abdelrahman Nasr
 */

#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"


#include "GIE_Config.h"
#include "GIE_Private.h"
#include "GIE_Interface.h"

void MGIE_voidEnableInterrupt(void)  // GIE = 1
{
	SET_BIT(SREG,SREG_I);
}

void MGIE_voidDisableInterrupt(void) //GIE=0
{
	CLR_BIT(SREG,SREG_I);
}



