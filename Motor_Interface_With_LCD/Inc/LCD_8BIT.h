/*
 * LCD_8BIT.h
 *
 *  Created on: 15-Sep-2022
 *      Author: kartik.iot
 */

#ifndef LCD_8BIT_H_
#define LCD_8BIT_H_

#include <stm32f401xe.h>
#include "delay.h"

#define RS			(1U<<0)
#define EN			(1U<<1)

void LCD_Command(uint8_t cmd);
void LCD_Character(char ch);
void LCD_Initialize();
void LCD_Print(char *str);
void LCD_Clear();

#endif /* LCD_8BIT_H_ */
