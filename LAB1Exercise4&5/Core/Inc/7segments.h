/*
 * 7segments.h
 *
 *  Created on: Oct 22, 2023
 *      Author: quoca
 */

#ifndef INC_7SEGMENTS_H_
#define INC_7SEGMENTS_H_

#include <stdint.h>
#include "main.h"
struct Sevenled {
	GPIO_TypeDef *gpio;
	uint16_t pin_a;
	uint16_t pin_b;
	uint16_t pin_c;
	uint16_t pin_d;
	uint16_t pin_e;
	uint16_t pin_f;
	uint16_t pin_g;
};
void Initialize7Segments(struct Sevenled* led, GPIO_TypeDef *gpio, uint16_t pin_a, uint16_t pin_b, uint16_t pin_c, uint16_t pin_d, uint16_t pin_e, uint16_t pin_f, uint16_t pin_g);
void SetAndDisplay7Segments(const struct Sevenled* led, unsigned short number);

#endif /* INC_7SEGMENTS_H_ */
