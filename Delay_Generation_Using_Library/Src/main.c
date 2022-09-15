/**
 ******************************************************************************
 * @file           : main.c
 * @author         : KARTIK
 * @brief          : LED BLINKING DELAY LIBRARY
 ******************************************************************************
 */

#include <stm32f401xe.h>
#include "delay.h"


int main(void)
{
	RCC -> AHB1ENR |= (1<<0);
	RCC -> AHB1ENR |= (1<<1);// AHB1-> GPIOB
	GPIOA -> MODER |= (1<<0);
	GPIOB -> MODER |= (1<<0);
	while(1)
	{
		// GPIOA -> ODR ^= (1<<0)
		GPIOA -> ODR |= (1<<0);
		GPIOB -> ODR &= ~(1<<0);
		// Inbuilt Delay To Be USed Here
		_delay_ms(500);
		GPIOB -> ODR |= (1<<0);
		GPIOA -> ODR &= ~(1<<0);
		// Inbuilt Delay To Be USed Here
		_delay_ms(500);
	}
}
