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
	GPIOA -> MODER |= (1<<0)|(1<<2)|(1<<4)|(1<<6)|(1<<8)|(1<<10)|(1<<12);
//	GPIOA -> MODER |= (1<<0);// PA0
//	GPIOA -> MODER |= (1<<2);// PA1
//	GPIOA -> MODER |= (1<<4);// PA2
//	GPIOA -> MODER |= (1<<6);// PA3
//	GPIOA -> MODER |= (1<<8);// PA4
//	GPIOA -> MODER |= (1<<10);// PA5
//	GPIOA -> MODER |= (1<<12);// PA6
//	GPIOA -> MODER = 0b00000000000000000001010101010101;
//	GPIOA -> MODER = 0x00001555;
	while(1)
	{
		// for digit 0
		GPIOA -> ODR |= (1<<0)|(1<<1)|(1<<2)|(1<<3)|(1<<4)|(1<<5);
		GPIOA -> ODR &= ~(1<<6);
		for(long delay = 0; delay <= 800000; delay = delay + 1);

		// for digit 1
		GPIOA -> ODR |= (1<<1)|(1<<2);
		GPIOA -> ODR &= ~((1<<0)|(1<<3)|(1<<4)|(1<<5)|(1<<6));
		for(long delay = 0; delay <= 800000; delay = delay + 1);
	}
}
