/**
 ******************************************************************************
 * @file           : main.c
 * @author         : KARTIK
 * @brief          : LCD Code for 8 Bit
 ******************************************************************************
 */

#include <stm32f401xe.h>
#include "delay.h"
#include "LCD_8BIT.h"

#define GPIOAEN		(1U<<0)
#define GPIOBEN		(1U<<1)

int main(void)
{
	RCC -> AHB1ENR |= GPIOAEN|GPIOBEN;

	// SETUP PA0 to PA9 as OUTPUT
	GPIOA -> MODER |= (1U<<0)|(1U<<2)|(1U<<4)|(1U<<6)|(1U<<8)|(1U<<10)|(1U<<12)|(1U<<14)|(1U<<16)|(1U<<18);
	GPIOA -> MODER &= ~((1U<<1)|(1U<<3)|(1U<<5)|(1U<<7)|(1U<<9)|(1U<<11)|(1U<<13)|(1U<<15)|(1U<<17)|(1U<<19));

	GPIOB -> MODER |= (1U<<0)|(1U<<2);
	GPIOB -> MODER &= ~((1U<<1)|(1U<<3));

	LCD_Initialize();
	while(1)
	{
		LCD_Command(0x80);LCD_Print("Moving Forward");
		GPIOB -> ODR |= (1U<<0); // Direction-1
		GPIOB -> ODR &= ~(1U<<1); // Direction-1
		_delay_ms(3000);
		LCD_Clear();

		LCD_Command(0x80);LCD_Print("Stopped");
		GPIOB -> ODR &= ~((1U<<0)|(1U<<1));
		_delay_ms(3000);
		LCD_Clear();

		LCD_Command(0x80);LCD_Print("Moving Backward");
		GPIOB -> ODR &= ~(1U<<0); // Direction-2
		GPIOB -> ODR |= (1U<<1); // Direction-2
		_delay_ms(3000);
		LCD_Clear();

		LCD_Command(0x80);LCD_Print("Stopped");
		GPIOB -> ODR &= ~((1U<<0)|(1U<<1));
		_delay_ms(3000);
		LCD_Clear();
	}
}
