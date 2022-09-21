/**
 ******************************************************************************
 * @file           : main.c
 * @author         : KARTIK
 * @brief          : LCD Code for 8 Bit
 ******************************************************************************
 */

#include <stm32f401xe.h>
#include "delay.h"
#include "LCD_4BIT.h"

#define GPIOAEN		(1U<<0)

int main(void)
{
	RCC -> AHB1ENR |= GPIOAEN;
	// SETUP PA0 to PA5 as OUTPUT
	GPIOA -> MODER |= (1U<<0)|(1U<<2)|(1U<<4)|(1U<<6)|(1U<<8)|(1U<<10);
	GPIOA -> MODER &= ~((1U<<1)|(1U<<3)|(1U<<5)|(1U<<7)|(1U<<9)|(1U<<11));

	LCD4_Initialize();
	while(1)
	{
		LCD4_Command(0x80);LCD4_Print("~~~~LCD~~~~");_delay_ms(1000);
		LCD4_Command(0xC0);LCD4_Print("4-Bit-Mode");_delay_ms(1000);
		LCD4_Command(0x90);LCD4_Print("Hello Rahul");_delay_ms(1000);
		LCD4_Command(0xD0);LCD4_Print("Hello Shakuntala");_delay_ms(1000);
		LCD4_Clear();
	}
}
