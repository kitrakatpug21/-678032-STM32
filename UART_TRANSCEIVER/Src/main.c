/**
 ******************************************************************************
 * @file           : main.c
 * @author         : KARTIK
 * @brief          : Usart-Transmitter
 ******************************************************************************
 */

#include <stm32f401xe.h>
#include "delay.h"
#include "USART2.h"
#include <stdio.h>

#define GPIOAEN		(1U<<0)

int main(void)
{
	///////////////// Enable the Clocks ////////////////
	RCC -> AHB1ENR |= GPIOAEN;
	USART2_Init();
	while(1)
	{
		USART2_Transmit(USART2_Receive());
	}
}
