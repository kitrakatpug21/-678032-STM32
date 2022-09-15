/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Kartik
 * @brief          : Main program body
 ******************************************************************************
 **/

#include <stdint.h>
// Identify the base of Programmable memory
#define PeripheralBaseAddress			(0x40000000UL)
// Identify the address of BUS
#define AHB1_OFFSET						(0x00020000UL)
#define AHB1_BaseAddress				(PeripheralBaseAddress + AHB1_OFFSET)
// GPIO ADDRESS CONFIG
#define GPIOA_OFFSET					(0x00000000UL)
#define AHB1_GPIOA						(AHB1_BaseAddress + GPIOA_OFFSET)

// CLOCK ADDRESS CONFIG
#define RCC_OFFSET						(0x00003800UL)
#define AHB1_RCC						(AHB1_BaseAddress + RCC_OFFSET)

typedef struct{
	uint32_t MODER;
	uint32_t OTYPER;
	uint32_t OSPEEDR;
	uint32_t PUPDR;
	uint32_t IDR;
	uint32_t ODR;
	uint32_t BSRR;
	uint32_t LCKR;
	uint32_t AFRL;
	uint32_t AFRH;
} GPIO_REGISTER;

typedef struct{
	uint32_t CR;
	uint32_t PLLCFGR;
	uint32_t CFGR;
	uint32_t CIR;
	uint32_t AHB1RSTR;
	uint32_t AHB2RSTR;
	uint32_t RESERVED1[2];
	uint32_t APB1RSTR;
	uint32_t APB2RSTR;
	uint32_t RESERVED2[2];
	uint32_t AHB1ENR;
	uint32_t AHB2ENR;
	uint32_t RESERVED3[2];
	uint32_t APB1ENR;
	uint32_t APB2ENR;
	uint32_t RESERVED4[16];
} RCC_REGISTER;


#define GPIOA 			((GPIO_REGISTER*) AHB1_GPIOA)
#define RCC 			((RCC_REGISTER*) AHB1_RCC)

int main(void)
{
	RCC -> AHB1ENR |= (1U<<0);// We enabled the AHB1 Clock Access for GPIO A
	GPIOA -> MODER |= (1U<<0);// We setup PA0 as OUTPUT
	GPIOA -> MODER |= (1U<<4);// We setup PA2 as OUTPUT
	GPIOA -> MODER |= (1U<<8);// We setup PA4 as OUTPUT
	GPIOA -> MODER |= (1U<<12);// We setup PA6 as OUTPUT
	while(1)
	{
		GPIOA -> ODR ^= (1U<<0);
		for(long i = 0; i<800000; i = i+1);
		GPIOA -> ODR ^= (1U<<2);
		for(long i = 0; i<800000; i = i+1);
		GPIOA -> ODR ^= (1U<<4);
		for(long i = 0; i<800000; i = i+1);
		GPIOA -> ODR ^= (1U<<6);
		for(long i = 0; i<800000; i = i+1);
	}
}
/*
 * Q1. Make LED Pattern using GPIOA0 to GPIOA7
 * 	a) in downwards direction
 * 	b) in upwards direction
 * 	c) curtain in
 * 	d) curtain out
 * 	e) all blinking
 * */
