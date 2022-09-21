/**
 ******************************************************************************
 * @file           : main.c
 * @author         : KARTIK
 * @brief          : Usart-Transmitter
 ******************************************************************************
 */

#include <stm32f401xe.h>
#include "delay.h"
#include <stdio.h>

#define USART2EN	(1U<<17)
#define GPIOAEN		(1U<<0)

#define BaudRate	(115200UL)
#define F_CPU		(16000000UL)

#define TXE			(1U<<7)
#define RXNE		(1U<<5)
#define UE			(1U<<13)
#define PCE			(1U<<10)
#define PS			(1U<<9)
#define TE			(1U<<3)

void USART2_Init()
{
	///////////////// Enable the Clocks ////////////////
	RCC -> APB1ENR |= USART2EN;
	///////////////// SETUP THE GPIOs //////////////////
	GPIOA -> MODER |= (1<<7)|(1<<5); // PA3 and PA2 are Set to Alternate Functionality Mode
	GPIOA -> AFR[0] |= (1<<8)|(1<<9)|(1<<10)|(1<<12)|(1<<13)|(1<<14);
	// Set the AF mode to 7
	///////////////// Setup the USART Configurations ////////////
	USART2 -> CR1 |= TE;
	//1. Setup the Control Register
	USART2 -> BRR = ((F_CPU + (BaudRate/2U))/BaudRate);
	//2. COnfigure the Baud rate
	USART2 -> CR1 |= UE;
	//3. Enable the UART Protocol
	USART2 -> DR = 0;
}

void USART2_Transmit(char data)
{
	while (((USART2 -> SR) & TXE)==0);
	//5. Now wait for the Transmit Flag to be set
	USART2 -> DR = data;
	//3. Load the Data
	_delay_ms(100);
}

void USART2_Print(char *str)
{
	while (*str != '\0')
	{
		USART2_Transmit(*str);
		str++;
	}
	USART2_Transmit('\r');
}

int __io_putchar(int ch)
{
	USART2_Transmit(ch);
	return ch;
}

int main(void)
{
	///////////////// Enable the Clocks ////////////////
	RCC -> AHB1ENR |= GPIOAEN;
	USART2_Init();
	while(1)
	{
		//USART2_Print("RAHUL");
		//USART2_Print("SHAKUNTLA");
		//USART2_Print("ARJUN");

		printf("RAHUL: %d\r\n",20);
		_delay_ms(100);
		printf("SHAKUNTLA: %d\r\n",20);
		_delay_ms(100);
		printf("ARJUN: %d\r\n",20);
		_delay_ms(100);
	}
}
