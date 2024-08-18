/*
 * LCD_Private.h
 *
 *  Created on: Aug 4, 2024
 *      Author: nouran
 */

#ifndef HAL_LCD_LCD_PRIVATE_H_
#define HAL_LCD_LCD_PRIVATE_H_

#define LCD_ALL_OUTPUT 0xff // 0b11111111

#define FUNCTION_SET_CMD 0x38 //0b00111000 // we write on d not r/w rs

#define DISPLAY_ON_OFF_CMD 0x0f //0b00001111

#define DISPLAY_CLEAR_CMD 0x01 //0b00000001

//#define ENTRY_MODE_ON_CMD 0x07 // 0b00000111

static void LCD_vSendCommand(u8 Copy_u8CopyCommend); // we put it in private and made it static, because we don't want the user to use it
#endif /* HAL_LCD_LCD_PRIVATE_H_ */
