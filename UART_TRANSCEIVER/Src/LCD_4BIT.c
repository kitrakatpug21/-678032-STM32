/*
 * LCD4_4BIT.c
 *
 *  Created on: 19-Sep-2022
 *      Author: kartik.iot
 */


#include "LCD_4BIT.h"

void LCD4_Command(uint8_t cmd)
{
	GPIOA -> ODR = 0;// to clear any previous value on ODR register
	GPIOA -> ODR |= ((cmd & 0xF0)>>2); // load DATA (Upper Nibble)
	GPIOA -> ODR &= ~(RS);
	GPIOA -> ODR |= (EN);
	_delay_ms(10);
	GPIOA -> ODR &= ~(EN);
	_delay_ms(10);

	GPIOA -> ODR = 0;// to clear any previous value on ODR register
	GPIOA -> ODR |= ((cmd & 0x0F)<<2); // load DATA (Upper Nibble)
	GPIOA -> ODR &= ~(RS);
	GPIOA -> ODR |= (EN);
	_delay_ms(10);
	GPIOA -> ODR &= ~(EN);
	_delay_ms(10);
}

void LCD4_Character(char ch)
{
	GPIOA -> ODR = 0;// to clear any previous value on ODR register
	GPIOA -> ODR |= ((ch & 0xF0)>>2); // load DATA (Upper Nibble)
	GPIOA -> ODR |= (RS);
	GPIOA -> ODR |= (EN);
	_delay_ms(10);
	GPIOA -> ODR &= ~(EN);
	_delay_ms(10);

	GPIOA -> ODR = 0;// to clear any previous value on ODR register
	GPIOA -> ODR |= ((ch & 0x0F)<<2); // load DATA (Upper Nibble)
	GPIOA -> ODR |= (RS);
	GPIOA -> ODR |= (EN);
	_delay_ms(10);
	GPIOA -> ODR &= ~(EN);
	_delay_ms(10);
}

void LCD4_Initialize()
{
	_delay_ms(300);
	LCD4_Command(0x33);// Sync Bits
	LCD4_Command(0x32);// Sync Bits
	LCD4_Command(0x28);// LCD 4 bit 2 row 16 character mode
	//
	LCD4_Command(0x0E);// Cursor
	LCD4_Command(0x01);// CLEAR
	_delay_ms(10);
	LCD4_Command(0x06); // Left to RIGHT
	LCD4_Command(0x80); // ROW-0 COL-0 Position
}

void LCD4_Print(char *str)
{
	while(*str != '\0')
	{
		LCD4_Character(*str);
		str++;
	}
}

void LCD4_Clear()
{
	LCD4_Command(0x01);
	_delay_ms(10);
}
