/*
 * USART2.c
 *
 *  Created on: 21-Sep-2022
 *      Author: kartik.iot
 */

#include "USART2.h"

#define GPIOAEN		    (1U<<0)

void USART2_Init()
{
	///////////////// Enable the Clocks ////////////////
	RCC -> AHB1ENR |= GPIOAEN;
	RCC -> APB1ENR |= USART2EN;
	///////////////// SETUP THE GPIOs //////////////////
	GPIOA -> MODER |= (1<<7)|(1<<5); // PA3 and PA2 are Set to Alternate Functionality Mode
	GPIOA -> AFR[0] |= (1<<8)|(1<<9)|(1<<10)|(1<<12)|(1<<13)|(1<<14);
	// Set the AF mode to 7
	///////////////// Setup the USART Configurations ////////////
	USART2 -> CR1 |= TE|RE;
	//1. Setup the Control Register
	USART2 -> BRR = ((F_CPU + (BaudRate/2U))/BaudRate);
	//2. COnfigure the Baud rate
	USART2 -> CR1 |= UE;
	//3. Enable the UART Protocol
	USART2 -> DR = 0;
}

void USART2_Init_Intp()
{
	///////////////// Enable the Clocks ////////////////
	RCC -> AHB1ENR |= GPIOAEN;
	RCC -> APB1ENR |= USART2EN;
	///////////////// SETUP THE GPIOs //////////////////
	GPIOA -> MODER |= (1<<7)|(1<<5); // PA3 and PA2 are Set to Alternate Functionality Mode
	GPIOA -> AFR[0] |= (1<<8)|(1<<9)|(1<<10)|(1<<12)|(1<<13)|(1<<14);
	// Set the AF mode to 7
	///////////////// Setup the USART Configurations ////////////
	USART2 -> CR1 |= TE|RE;
	//1. Setup the Control Register
	USART2 -> CR1 |= RXNEIE;
	//2. Set the Interrupt Bits
	USART2 -> BRR = ((F_CPU + (BaudRate/2U))/BaudRate);
	//3. COnfigure the Baud rate
	NVIC_EnableIRQ(USART2_IRQn);// sei();
	//4. Initialize the NVIC
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
}

char USART2_Receive()
{
	while (((USART2 -> SR) & RXNE)==0);
	//5. Now wait for the Receive Flag to be set
	return USART2 -> DR;
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
