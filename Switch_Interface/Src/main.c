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

	GPIOA -> MODER &= ~((1U<<0)|(1U<<1)|(1U<<2)|(1U<<3)|(1U<<4)|(1U<<5)|(1U<<6)|(1U<<7)|(1U<<8)|(1U<<9)|(1U<<10)|(1U<<11)|(1U<<12)|(1U<<13)|(1U<<14)|(1U<<15));
	GPIOB -> MODER |= (1U<<0)|(1U<<2)|(1U<<4)|(1U<<6)|(1U<<8)|(1U<<10)|(1U<<12)|(1U<<14);
	GPIOB -> MODER &= ~((1U<<1)|(1U<<3)|(1U<<5)|(1U<<7)|(1U<<9)|(1U<<11)|(1U<<13)|(1U<<15));

	while(1)
	{
		if (GPIOA -> IDR & 0x00000001)
		{
			// Button - 1 is pressed
			GPIOB -> ODR |= (PB0_LED | PB1_LED);
			GPIOB -> ODR &= ~(PB2_LED | PB3_LED | PB4_LED | PB5_LED | PB6_LED | PB7_LED);
		}
		else if (GPIOA -> IDR & 0x00000002)
		{
			// Button - 1 is pressed
			GPIOB -> ODR |= (PB2_LED | PB3_LED);
			GPIOB -> ODR &= ~(PB0_LED | PB1_LED | PB4_LED | PB5_LED | PB6_LED | PB7_LED);
		}
		else if (GPIOA -> IDR & 0x00000004)
		{
			// Button - 1 is pressed
			GPIOB -> ODR |= (PB4_LED | PB5_LED);
			GPIOB -> ODR &= ~(PB0_LED | PB1_LED | PB2_LED | PB3_LED | PB6_LED | PB7_LED);
		}
		else if (GPIOA -> IDR & 0x00000008)
		{
			// Button - 1 is pressed
			GPIOB -> ODR |= (PB6_LED | PB7_LED);
			GPIOB -> ODR &= ~(PB0_LED | PB1_LED | PB2_LED | PB3_LED | PB4_LED | PB5_LED);
		}
		else
		{
			GPIOB -> ODR &= ~(PB0_LED | PB1_LED | PB2_LED | PB3_LED | PB4_LED | PB5_LED | PB6_LED | PB7_LED);
		}
		_delay_ms(100);
	}
}
