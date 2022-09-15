/**
 ******************************************************************************
 * @file           : main.c
 * @author         : KARTIK
 * @brief          : LED BLINKING DELAY LIBRARY
 ******************************************************************************
 */

#include <stm32f401xe.h>
#include "delay.h"

#define GPIOAEN		(1U<<0)

#define RS			(1U<<0)
#define EN			(1U<<1)

#define D0			(1U<<2)
#define D1			(1U<<3)
#define D2			(1U<<4)
#define D3			(1U<<5)
#define D4			(1U<<6)
#define D5			(1U<<7)
#define D6			(1U<<8)
#define D7			(1U<<9)

//void Load_Data


// 8 bit LCD Mode
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

int main(void)
{
	RCC -> AHB1ENR |= GPIOAEN;

	// SETUP PA0 to PA9 as OUTPUT
	GPIOA -> MODER |= (1U<<0)|(1U<<2)|(1U<<4)|(1U<<6)|(1U<<8)|(1U<<10)|(1U<<12)|(1U<<14)|(1U<<16)|(1U<<18);
	GPIOA -> MODER &= ~((1U<<1)|(1U<<3)|(1U<<5)|(1U<<7)|(1U<<9)|(1U<<11)|(1U<<13)|(1U<<15)|(1U<<17)|(1U<<19));

	LCD_Initialize();
	while(1)
	{
		LCD_Command(0x80);
		LCD_Print("Shakuntla");
		_delay_ms(1000);
		LCD_Command(0xC0);
		LCD_Print("Jaiswal");
		_delay_ms(1000);
		LCD_Command(0x01);_delay_ms(1);
		LCD_Command(0x80);
		LCD_Print("Arjun");
		_delay_ms(1000);
		LCD_Command(0xC0);
		LCD_Print("Singh");
		_delay_ms(1000);
		LCD_Command(0x90);
		LCD_Print("Rajput");
		_delay_ms(1000);
		LCD_Command(0x01);_delay_ms(1);
	}
}
