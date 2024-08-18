/*
 * I2C_Program.c
 *
 *  Created on: Aug 18, 2024
 *      Author: nouran
 */


#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"


#include "I2C_Interface.h"
#include "I2C_Config.h"
#include "I2C_Private.h"


void TWI_voidMasterInit(u8 Copy_u8SlaveAddress){
	// Set Clock Frequency to 400kbps ( TWBR = 2, TWPS Two Bit = 00)
	TWBR = 2;
	CLR_BIT(TWSR, TWSR_TWPS0);
	CLR_BIT(TWSR, TWSR_TWPS1);

	// Set Address for Master When act as a Slave
	if(Copy_u8SlaveAddress != 0){
		// Assign the Required Node Address in the 7msb in the Register
		TWAR = (Copy_u8SlaveAddress << 1);
	}
	// Enable TWI
	SET_BIT(TWCR, TWCR_TWEN);
}
void TWI_voidSlaveInit(u8 Copy_u8SlaveAddress){
	// Assign the Required Node Address in the 7msb in the Register
	TWAR = (Copy_u8SlaveAddress << 1);
	// Enable TWI
	SET_BIT(TWCR, TWCR_TWEN);
}

static TWI_ErrStatus TWI_SendStartCondition(void){
	// variable for error status
	TWI_ErrStatus Local_ErrStatus = NoError;
	// send start condition on bus
	SET_BIT(TWCR, TWCR_TWSTA);
	// clear the interrupt flag to start previous operation
	SET_BIT(TWCR, TWCR_TWINT);
	//wait until the interrupt flag is raised again and previous operation is complete
	while(GET_BIT(TWCR, TWCR_TWINT) == 0);
	// check the operation
	if((TWSR & 0xf8) != START_ACK) Local_ErrStatus = StartConditionErr;
	return Local_ErrStatus;
}
TWI_ErrStatus TWI_SendRepeatedStart(void){
	// variable for error status
	TWI_ErrStatus Local_ErrStatus = NoError;
	// send start condition on bus
	SET_BIT(TWCR, TWCR_TWSTA);
	// clear the interrupt flag to start previous operation
	SET_BIT(TWCR, TWCR_TWINT);
	//wait until the interrupt flag is raised again and previous operation is complete
	while(GET_BIT(TWCR, TWCR_TWINT) == 0);
	// check the operation
	if((TWSR & 0xf8) != REP_START_ACK) Local_ErrStatus = RepeatedStartConditionErr;
	return Local_ErrStatus;
}

TWI_ErrStatus TWI_SendSlaveAddressWithWrite(u8 Copy_u8SlaveAddress){
	// variable for error status
	TWI_ErrStatus Local_ErrStatus = NoError;
	// Assign the Required Node Address in the 7msb in the Register
	TWDR = (Copy_u8SlaveAddress << 1);
	// select write
	CLR_BIT(TWDR, TWDR_TWD0);
	// clear start condition bit
	CLR_BIT(TWCR, TWCR_TWSTA);
	// clear the interrupt flag to start previous operation
	SET_BIT(TWCR, TWCR_TWINT);
	//wait until the interrupt flag is raised again and previous operation is complete
	while(GET_BIT(TWCR, TWCR_TWINT) == 0);
	// check the operation
	if((TWSR & 0xf8) != SLAVE_ADD_AND_WR_ACK) Local_ErrStatus = SlavedAddressWithWriteErr;
	return Local_ErrStatus;
}
TWI_ErrStatus TWI_SendSlaveAddressWithRead(u8 Copy_u8SlaveAddress){
	// variable for error status
	TWI_ErrStatus Local_ErrStatus = NoError;
	// Assign the Required Node Address in the 7msb in the Register
	TWDR = (Copy_u8SlaveAddress << 1);
	// select read
	SET_BIT(TWDR, TWDR_TWD0);
	// clear start condition bit
	CLR_BIT(TWCR, TWCR_TWSTA);
	// clear the interrupt flag to start previous operation
	SET_BIT(TWCR, TWCR_TWINT);
	//wait until the interrupt flag is raised again and previous operation is complete
	while(GET_BIT(TWCR, TWCR_TWINT) == 0);
	// check the operation
	if((TWSR & 0xf8) != SLAVE_ADD_AND_RD_ACK) Local_ErrStatus = SlaveAddressWithReadErr;
	return Local_ErrStatus;
}

TWI_ErrStatus TWI_MasterWriteDataByte(u8 Copy_u8DataByte){
	// variable for error status
	TWI_ErrStatus Local_ErrStatus = NoError;
	// write the data byte;
	TWDR = Copy_u8DataByte;
	// clear the interrupt flag to start previous operation
	SET_BIT(TWCR, TWCR_TWINT);
	//wait until the interrupt flag is raised again and previous operation is complete
	while(GET_BIT(TWCR, TWCR_TWINT) == 0);
	// check the operation
	if((TWSR & 0xf8) != MSTR_WR_BYTE_ACK) Local_ErrStatus = MasterWriteByteErr;
	return Local_ErrStatus;
}
TWI_ErrStatus TWI_MasterReadDataByte(u8 *Copy_pu8DataByte){
	// variable for error status
	TWI_ErrStatus Local_ErrStatus = NoError;
	// enable master generating acknowledge bit after receiving the data
	CLR_BIT(TWCR, TWCR_TWEA);
	// clear the interrupt flag to start previous operation
	SET_BIT(TWCR, TWCR_TWINT);
	//wait until the interrupt flag is raised again and previous operation is complete
	while(GET_BIT(TWCR, TWCR_TWINT) == 0);
	// check the operation
	if((TWSR & 0xf8) != MSTR_RD_BYTE_WITH_NACK) Local_ErrStatus = MasterReadByteErr;
	else // Read the data byte;
		*Copy_pu8DataByte = TWDR;
	return Local_ErrStatus;
}

void TWI_SendStopCondition(void){
	SET_BIT(TWCR, TWCR_TWSTO);
	SET_BIT(TWCR, TWCR_TWINT);
	SET_BIT(TWCR, TWCR_TWEN);
}
