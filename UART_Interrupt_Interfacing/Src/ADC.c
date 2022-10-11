/*
 * ADC.c
 *
 *  Created on: 22-Sep-2022
 *      Author: kartik.iot
 */


#include "ADC.h"

#define GPIOAEN		    (1U<<0)
#define ADC1EN			(1U<<8)

#define ADC_CH1			(1U<<0)
#define ADC_SEQ_LEN_1	 0x00
#define CR2_AD0N		(1U<<0)
#define CR2_SWSTART		(1U<<30)
#define SR_EOC			(1U<<1)
#define CR2_CONT		(1U<<1)

void ADC_Init0(void)
{
	/***Configure the ADC GPIO pin ***/
	/*Enable clock access to GPIOA*/
	RCC->AHB1ENR |= GPIOAEN;
	/*Set the mode of PA0 to analog*/
	GPIOA -> MODER |= (1U<<0)|(1U<<1);
	/***Configure the ADC module***/
	/*Enable clock access to ADC */
	RCC -> APB2ENR |= ADC1EN;
	/*Conversion sequence start*/
	ADC1->SQR3 = 0;// channel 0
	/*Conversion sequence length*/
	ADC1->SQR1 = 0; // length = 1
	/*Enable ADC module*/
	ADC1->CR2 |= CR2_AD0N;
}
void ADC_Init1(void)
{
	/***Configure the ADC GPIO pin ***/
	/*Enable clock access to GPIOA*/
	RCC -> AHB1ENR |= GPIOAEN;
	/*Set the mode of PA1 to analog*/
	GPIOA -> MODER |= (1U<<2)|(1U<<3);
	/***Configure the ADC module***/
	/*Enable clock access to ADC */
	RCC -> APB2ENR |= ADC1EN;
	/*Conversion sequence start*/
	ADC1->SQR3 = (1U<<0);//channel 1
	/*Conversion sequence length*/
	ADC1->SQR1 = 0; // length = 1
	/*Enable ADC module*/
	ADC1->CR2 |= CR2_AD0N;
}

void ADC_Regular_Start0()
{
	/*Start adc conversion*/
	ADC1->CR2 |= CR2_SWSTART;
}

void ADC_Continuous_Start0()
{
	ADC1->CR2 |=CR2_CONT;
	/*Enable ADC module*/
	ADC1->CR2 |= CR2_AD0N;
}

uint32_t ADC_Get_Result(void)
{
	/*Wait for conversion to be complete*/
	while(!(ADC1->SR & SR_EOC)){}
	//ADC1->CR2 &= ~CR2_AD0N;
	/*Read converted result*/
	return (ADC1->DR);
}
