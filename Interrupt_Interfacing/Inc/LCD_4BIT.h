/*
 * LCD_4BIT.h
 *
 *  Created on: 19-Sep-2022
 *      Author: kartik.iot
 */

#ifndef LCD_4BIT_H_
#define LCD_4BIT_H_

#include <stm32f401xe.h>
#include "delay.h"

#define RS			(1U<<0)
#define EN			(1U<<1)

void LCD4_Command(uint8_t cmd);
void LCD4_Character(char ch);
void LCD4_Initialize();
void LCD4_Print(char *str);
void LCD4_Clear();

#endif /* LCD_4BIT_H_ */
