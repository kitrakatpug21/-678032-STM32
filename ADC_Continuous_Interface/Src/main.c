/**
 ******************************************************************************
 * @file           : main.c
 * @author         : KARTIK
 * @brief          : Analog to Digital Conversion
 ******************************************************************************
 */

#include <stm32f401xe.h>
#include "delay.h"
#include "USART2.h"
#include "ADC.h"
#include <stdio.h>

int main(void)
{
	USART2_Init();
	printf("UART Init Complete\r\n");
	int result;
	ADC_Init0();
	ADC_Continuous_Start0();
	//ADC_Regular_Start0();
	while(1)
	{
		//ADC_Regular_Start0();
		printf("\n\r\rADC0 Started.");
		//Read converted result
		result = ADC_Get_Result();
		printf("Value: %d\r",result);
		for(int i = 0; i<10000;i=i+1);
	}
}


