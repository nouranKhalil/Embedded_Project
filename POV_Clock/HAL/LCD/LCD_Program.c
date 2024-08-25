#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../../MCAL/DIO/DIO_interface.h"

#include "LCD_interface.h"
#include "util/delay.h"

void LCD_vidInit(void){

	DIO_voidSetPinValue(lcd_CONTROLPORT,lcd_EPIN,LOW);
	DIO_voidSetPortSpecificDirection(lcd_DATAPORT,0xff);

	DIO_voidSetPinDirection(lcd_CONTROLPORT,lcd_RSPIN,OUTPUT);
	DIO_voidSetPinDirection(lcd_CONTROLPORT,lcd_RWPIN,OUTPUT);
	DIO_voidSetPinDirection(lcd_CONTROLPORT,lcd_EPIN,OUTPUT);

	_delay_ms(30);

	LCD_vidSendCommand(lcd_Home);
	_delay_ms(5);

	LCD_vidSendCommand(lcd_FunctionSet8bit);
	_delay_ms(5);

	LCD_vidSendCommand(lcd_DisplayOn);
	_delay_ms(5);

	LCD_vidSendCommand(lcd_Clear);
	_delay_ms(5);

	LCD_vidSendCommand(lcd_EntryMode);
	_delay_ms(5);


}

void LCD_ClrCmd(void){
	LCD_vidSendCommand(lcd_Clear);
}
void LCD_vidSendCommand(u8 u8CmdCpy){
	DIO_voidSetPinValue(lcd_CONTROLPORT,lcd_RSPIN,LOW);
	DIO_voidSetPinValue(lcd_CONTROLPORT,lcd_RWPIN,LOW);
	DIO_voidSetPinValue(lcd_CONTROLPORT,lcd_EPIN,LOW);
	DIO_voidSetPortSpecificValue(lcd_DATAPORT,u8CmdCpy);
	DIO_voidSetPinValue(lcd_CONTROLPORT,lcd_EPIN,HIGH);
	_delay_ms(5);
	DIO_voidSetPinValue(lcd_CONTROLPORT,lcd_EPIN,LOW);

}
void LCD_vidWriteCharctr(u8 u8DataCpy){
	DIO_voidSetPinValue(lcd_CONTROLPORT,lcd_RSPIN,HIGH);
	DIO_voidSetPinValue(lcd_CONTROLPORT,lcd_RWPIN,LOW);
	DIO_voidSetPinValue(lcd_CONTROLPORT,lcd_EPIN,LOW);
	DIO_voidSetPortSpecificValue(lcd_DATAPORT,u8DataCpy);
	DIO_voidSetPinValue(lcd_CONTROLPORT,lcd_EPIN,HIGH);
	_delay_ms(5);
	DIO_voidSetPinValue(lcd_CONTROLPORT,lcd_EPIN,LOW);
}
void LCD_vidWriteString (u8* pu8StringCpy){
	u8 i=0;
	while(*(pu8StringCpy + i) != '\0'){
		LCD_vidWriteCharctr(*(pu8StringCpy + i));
		i++;
	}
}
void Gotoxy (u8 Y,u8 X){
	if (X>=0 && X<=16)
	{
		switch(Y)
		{
		case 1:
			LCD_vidSendCommand(X+128);
			break;
		case 2:
			LCD_vidSendCommand(X+192);
			break;
		default:
			break;
		}
	}
}

void LCD_vSetCGRamAdd (u8 Y,u8 X)
{

}

