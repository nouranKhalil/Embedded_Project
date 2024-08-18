/*
 * LCD_Config.h
 *
 *  Created on: Aug 4, 2024
 *      Author: nouran
 */

#ifndef HAL_LCD_LCD_CONFIG_H_
#define HAL_LCD_LCD_CONFIG_H_

#define LCD_DATA_PORT MDIO_PORTA

/*
 * MDIO_PORTA
 * MDIO_PORTB
 * MDIO_PORTC
 * MDIO_PORTD
 */
#define LCD_CTRL_PORT DIO_PORTB

#define LCD_RW_PIN PIN0
#define LCD_RS_PIN PIN1
#define LCD_EN_PIN PIN2

#endif /* HAL_LCD_LCD_CONFIG_H_ */
