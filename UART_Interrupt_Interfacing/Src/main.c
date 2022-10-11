/**
 ******************************************************************************
 * @file           : main.c
 * @author         : KARTIK
 * @brief          : USART With Interrupt
 ******************************************************************************
 */

#include <stm32f401xe.h>
#include "delay.h"
#include "USART2.h"

int main(void)
{

	USART2_Init_Intp();
	//USART2_Init();
	GPIOA -> MODER |= (1U<<2);
	while(1)
	{
		USART2_Transmit(USART2_Receive());
	}
}

void USART2_IRQHandler()	// ISR()
{
	if (USART2 -> SR & RXNE)
	{
		GPIOA -> ODR ^= (1U<<1);
		for(long i = 0; i < 100000; i = i+1);
	}
}

