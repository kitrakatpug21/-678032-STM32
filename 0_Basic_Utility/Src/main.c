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

#define MODER_OFFSET					(0x00000000UL)
#define GPIOA_MODER						*(volatile uint32_t*)(AHB1_GPIOA + MODER_OFFSET)

#define ODR_OFFSET						(0x00000014UL)
#define GPIOA_ODR						*(volatile uint32_t*)(AHB1_GPIOA + ODR_OFFSET)
// CLOCK ADDRESS CONFIG
#define RCC_OFFSET						(0x00003800UL)
#define AHB1_RCC						(AHB1_BaseAddress + RCC_OFFSET)

#define AHB1ENR_OFFSET					(0x00000030UL)
#define RCC_AHB1ENR						*(volatile uint32_t*)(AHB1_RCC + AHB1ENR_OFFSET)

int main(void)
{
	RCC_AHB1ENR |= (1U<<0);// We enabled the AHB1 Clock Access for GPIO A
	GPIOA_MODER |= (1U<<0);// We setup PA0 as OUTPUT
	while(1)
	{
		GPIOA_ODR ^= (1U<<0);
		for(long i = 0; i<800000; i = i+1);
	}
}
