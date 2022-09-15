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
#define GPIOBEN		(1U<<1)

#define PB0_LED		(1U<<0)
#define PB1_LED		(1U<<1)
#define PB2_LED		(1U<<2)
#define PB3_LED		(1U<<3)
#define PB4_LED		(1U<<4)
#define PB5_LED		(1U<<5)
#define PB6_LED		(1U<<6)
#define PB7_LED		(1U<<7)

int main(void)
{
	//RCC -> AHB1ENR |= (1<<0); // GPIOA-EN
	//RCC -> AHB1ENR |= (1<<1); // GPIOB-EN
	RCC -> AHB1ENR |= GPIOAEN | GPIOBEN;

	GPIOA -> MODER &= ~((1U<<0)|(1U<<1)|(1U<<2)|(1U<<3));
	GPIOB -> MODER |= (1U<<0)|(1U<<2)|(1U<<4)|(1U<<6)|(1U<<8)|(1U<<10)|(1U<<12);
	GPIOB -> MODER &= ~((1U<<1)|(1U<<3)|(1U<<5)|(1U<<7)|(1U<<9)|(1U<<11)|(1U<<13));

	int count = 0;

	/*
	 * uint8_t segment[10] = {};
	 * */
	while(1)
	{
		if (GPIOA -> IDR & 0x00000001)
		{
			// Button - 1 is pressed
			while (GPIOA -> IDR & 0x00000001)
			{
				// wait for debouncer to release the button
				_delay_ms(10);
			}
			if (count == 9)
				count = 0;
			else
				count = count + 1;
		}
		else if (GPIOA -> IDR & 0x00000002)
		{
			// Button - 2 is pressed
			while (GPIOA -> IDR & 0x00000002)
			{
				// wait for debouncer to release the button
				_delay_ms(10);
			}
			if (count == 0)
				count = 9;
			else
				count = count - 1;
		}
		if (count == 0)
		{
			GPIOB -> ODR |= (1U<<0)|(1U<<1)|(1U<<2)|(1U<<3)|(1U<<4)|(1U<<5);//segment[0];
			GPIOB -> ODR &= ~(1U<<6);//segment[0];
		}
		else if (count == 1)
		{
			GPIOB -> ODR |= (1U<<1)|(1U<<2);
			GPIOB -> ODR &= ~((1U<<0)|(1U<<3)|(1U<<4)|(1U<<5)|(1U<<6));
		}
		else if (count == 2)
		{
			GPIOB -> ODR |= (1U<<0)|(1U<<1)|(1U<<3)|(1U<<4)|(1U<<6);
			GPIOB -> ODR &= ~((1U<<2)|(1U<<5));
		}
		else if (count == 3)
		{
			GPIOB -> ODR |= (1U<<0)|(1U<<1)|(1U<<2)|(1U<<3)|(1U<<6);
			GPIOB -> ODR &= ~((1U<<4)|(1U<<5));
		}
		else if (count == 4)
		{
			GPIOB -> ODR |= (1U<<1)|(1U<<2)|(1U<<5)|(1U<<6);
			GPIOB -> ODR &= ~((1U<<0)|(1U<<3)|(1U<<4));
		}
		else if (count == 5)
		{
			GPIOB -> ODR |= (1U<<0)|(1U<<2)|(1U<<3)|(1U<<5)|(1U<<6);
			GPIOB -> ODR &= ~((1U<<1)|(1U<<4));
		}
		else if (count == 6)
		{
			GPIOB -> ODR |= (1U<<0)|(1U<<6)|(1U<<2)|(1U<<3)|(1U<<4)|(1U<<5);
			GPIOB -> ODR &= ~(1U<<1);
		}
		else if (count == 7)
		{
			GPIOB -> ODR |= (1U<<0)|(1U<<1)|(1U<<2);
			GPIOB -> ODR &= ~((1U<<3)|(1U<<4)|(1U<<5)|(1U<<6));
		}
		else if (count == 8)
		{
			GPIOB -> ODR |= (1U<<0)|(1U<<1)|(1U<<2)|(1U<<3)|(1U<<4)|(1U<<5)|(1U<<6);
		}
		else if (count == 9)
		{
			GPIOB -> ODR |= (1U<<0)|(1U<<1)|(1U<<2)|(1U<<3)|(1U<<5)|(1U<<6);
			GPIOB -> ODR &= ~(1U<<4);
		}
		_delay_ms(100);
	}
}
