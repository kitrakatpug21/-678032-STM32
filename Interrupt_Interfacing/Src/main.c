/**
 ******************************************************************************
 * @file           : main.c
 * @author         : KARTIK
 * @brief          : Analog to Digital Conversion
 ******************************************************************************
 */

#include <stm32f401xe.h>
#include "delay.h"

int main(void)
{
	// 1. to disable all the pre-initialised interrupts
	__disable_irq(); // disable the interrupt requests

	RCC -> AHB1ENR |= (1U<<0);// GPIOAEN
	GPIOA -> MODER |= (1U<<2); // SETUP PA0 as Input, PA1 as OUTPUT for LED

	RCC -> APB2ENR |= (1U<<14);// SYSCFG CLOCK Interrupt clocks
	SYSCFG -> EXTICR[0] = 0;
	EXTI -> IMR |= (1U<<0);	// enable INT0 at PA0
	EXTI -> RTSR |= (1U<<0); // detect rising Edge

	NVIC_EnableIRQ(EXTI0_IRQn);// sei();
	GPIOA -> ODR = 0;
	__enable_irq(); // enable the interrupt requests
	while (1)
	{}
}

void EXTI0_IRQHandler()	// ISR()
{
	GPIOA -> ODR ^= (1U<<1);
	for(long i = 0; i < 100000; i = i+1);
}

