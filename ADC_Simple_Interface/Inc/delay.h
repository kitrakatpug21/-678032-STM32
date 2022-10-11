/*
 * delay.h
 *
 *  Created on: 13-Sep-2022
 *      Author: kartik.iot
 */

#ifndef DELAY_H_
#define DELAY_H_

// Include all the dependent libraries
#include <stm32f401xe.h>

// Create Prototypes of the functions available in the .c file
void _delay_ms(int delay);
void _delay_us(int delay);


#endif /* DELAY_H_ */
