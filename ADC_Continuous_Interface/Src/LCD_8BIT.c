/*
 * LCD_8BIT.c
 *
 *  Created on: 15-Sep-2022
 *      Author: kartik.iot
 */

#include "LCD_8BIT.h"

void LCD_Command(uint8_t cmd)
{
	GPIOA -> ODR = 0;// to clear any previous value on ODR register
	GPIOA -> ODR &= ~(RS);
	GPIOA -> ODR &= ~(EN);
	GPIOA -> ODR |= (cmd << 2); // load DATA
	GPIOA -> ODR |= (EN);
	_delay_ms(10);
	GPIOA -> ODR &= ~(EN);
	_delay_ms(10);
}

void LCD_Character(char ch)
{
	GPIOA -> ODR = 0;// to clear any previous value on ODR register
	GPIOA -> ODR |= (RS);
	GPIOA -> ODR &= ~(EN);
	GPIOA -> ODR |= (ch << 2); // load DATA
	GPIOA -> ODR |= (EN);
	_delay_ms(10);
	GPIOA -> ODR &= ~(EN);
	_delay_ms(10);
}

void LCD_Initialize()
{
	_delay_ms(300);
	LCD_Command(0x38);// LCD 8 bit 2 row 16 character mode
	//
	LCD_Command(0x0E);// Cursor
	LCD_Command(0x01);// CLEAR
	_delay_ms(10);
	LCD_Command(0x06); // Left to RIGHT
	LCD_Command(0x80); // ROW-0 COL-0 Position
}

void LCD_Print(char *str)
{
	while(*str != '\0')
	{
		LCD_Character(*str);
		str++;
	}
}

void LCD_Clear()
{
	LCD_Command(0x01);
	_delay_ms(10);
}
