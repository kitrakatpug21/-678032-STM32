/*
 * ADC.h
 *
 *  Created on: 22-Sep-2022
 *      Author: kartik.iot
 */

#ifndef ADC_H_
#define ADC_H_

#include <stm32f401xe.h>

void ADC_Init1(void);
void ADC_Init0(void);
void ADC_Regular_Start0();
void ADC_Continuous_Start0();
uint32_t ADC_Get_Result(void);

#endif /* ADC_H_ */
