/*
 * USART2.h
 *
 *  Created on: 21-Sep-2022
 *      Author: kartik.iot
 */

#ifndef USART2_H_
#define USART2_H_

#include <stm32f401xe.h>
#define USART2EN	(1U<<17)

#define BaudRate	(115200UL) // 9600 for GPS
#define F_CPU		(16000000UL)

#define TXE			(1U<<7)
#define RXNE		(1U<<5)
#define UE			(1U<<13)
#define PCE			(1U<<10)
#define PS			(1U<<9)
#define TE			(1U<<3)
#define RE			(1U<<2)

void USART2_Init();
void USART2_Transmit(char data);
char USART2_Receive();
void USART2_Print(char *str);
int __io_putchar(int ch);

#endif /* USART2_H_ */
