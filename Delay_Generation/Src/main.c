/**
 ******************************************************************************
 * @file           : main.c
 * @author         : KARTIK
 * @brief          : LED BLINKING WITH CUSTOM DELAY
 ******************************************************************************
 */

#include <stm32f401xe.h>

#define ENABLE 			(1U<<0)
#define CLKSOURCE		(1U<<2)
#define COUNTFLAG		(1U<<16)

#define F_CPU 			16000000UL
#define ONE_US_COUNT	F_CPU / 1000000UL
#define ONE_MS_COUNT	F_CPU / 1000UL
#define ONE_S_COUNT		F_CPU


void _delay_ms(int delay)
{
	for (int i = 0; i < delay; i = i+1)
	{
		/* Setup the Reload Register Value */
		/*
		 * CTRL == CSR
		 * LOAD == RVR
		 * VAL  == CVR
		 * */
		SysTick -> LOAD = ONE_MS_COUNT;
		// we reduce one value as the counter travels from reload value to zero
		/* Clear the current Value register */
		SysTick -> VAL = 0;
		/* Select the Clock Source */
		SysTick -> CTRL |= CLKSOURCE;
		//SysTick -> CTRL &= ~CLKSOURCE;
		//SysTick -> CTRL |= (1<<2);
		//SysTick -> CTRL &= ~(1<<2);
		// if external clock is used, use 0 in CLK SOURCE
		// if internal clock is used, use 1 in CLK SOURCE
		/* Enable the system Tick  */
		SysTick -> CTRL |= ENABLE;
		/* NOw we will wait for count flag to turn on */
		while ((SysTick -> CTRL & COUNTFLAG) == 0)
		{
			// wait here
		}

		// once count flag is generated, we stop the counter
		SysTick -> CTRL &= ~ENABLE;
	}
}


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
		_delay_ms(1000);
		GPIOB -> ODR |= (1<<0);
		GPIOA -> ODR &= ~(1<<0);
		// Inbuilt Delay To Be USed Here
		_delay_ms(1000);
	}
}
