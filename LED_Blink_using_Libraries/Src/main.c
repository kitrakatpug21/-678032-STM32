/**
 ******************************************************************************
 * @file           : main.c
 * @author         : KARTIK
 * @brief          : LED BLINKING CODE USING STM32F4XX.H LIBRARY
 ******************************************************************************
 */

#include <stm32f401xe.h>

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
		for(long delay = 0; delay <= 400000; delay = delay + 1);
		GPIOB -> ODR |= (1<<0);
		GPIOA -> ODR &= ~(1<<0);
		for(long delay = 0; delay <= 400000; delay = delay + 1);
	}

}
