/*
 * 7segments.c
 *
 *  Created on: Oct 22, 2023
 *      Author: quoca
 */

#include "7segments.h"

void Initialize7Segments(struct Sevenled* led, GPIO_TypeDef *gpio, uint16_t pin_a, uint16_t pin_b, uint16_t pin_c, uint16_t pin_d, uint16_t pin_e, uint16_t pin_f, uint16_t pin_g)
{
	led->gpio = gpio;
	led->pin_a = pin_a;
	led->pin_b = pin_b;
	led->pin_c = pin_c;
	led->pin_d = pin_d;
	led->pin_e = pin_e;
	led->pin_f = pin_f;
	led->pin_g = pin_g;
}
void SetAndDisplay7Segments(const struct Sevenled* led, unsigned short number)
{
	switch(number)
	{
	case 0:
		HAL_GPIO_WritePin(led->gpio, led->pin_a, 0);
		HAL_GPIO_WritePin(led->gpio, led->pin_b, 0);
		HAL_GPIO_WritePin(led->gpio, led->pin_c, 0);
		HAL_GPIO_WritePin(led->gpio, led->pin_d, 0);
		HAL_GPIO_WritePin(led->gpio, led->pin_e, 0);
		HAL_GPIO_WritePin(led->gpio, led->pin_f, 0);
		HAL_GPIO_WritePin(led->gpio, led->pin_g, 1);
		break;
	case 1:
		HAL_GPIO_WritePin(led->gpio, led->pin_a, 1);
		HAL_GPIO_WritePin(led->gpio, led->pin_b, 0);
		HAL_GPIO_WritePin(led->gpio, led->pin_c, 0);
		HAL_GPIO_WritePin(led->gpio, led->pin_d, 1);
		HAL_GPIO_WritePin(led->gpio, led->pin_e, 1);
		HAL_GPIO_WritePin(led->gpio, led->pin_f, 1);
		HAL_GPIO_WritePin(led->gpio, led->pin_g, 1);
		break;
	case 2:
		HAL_GPIO_WritePin(led->gpio, led->pin_a, 0);
		HAL_GPIO_WritePin(led->gpio, led->pin_b, 0);
		HAL_GPIO_WritePin(led->gpio, led->pin_c, 1);
		HAL_GPIO_WritePin(led->gpio, led->pin_d, 0);
		HAL_GPIO_WritePin(led->gpio, led->pin_e, 0);
		HAL_GPIO_WritePin(led->gpio, led->pin_f, 1);
		HAL_GPIO_WritePin(led->gpio, led->pin_g, 0);
		break;
	case 3:
		HAL_GPIO_WritePin(led->gpio, led->pin_a, 0);
		HAL_GPIO_WritePin(led->gpio, led->pin_b, 0);
		HAL_GPIO_WritePin(led->gpio, led->pin_c, 0);
		HAL_GPIO_WritePin(led->gpio, led->pin_d, 0);
		HAL_GPIO_WritePin(led->gpio, led->pin_e, 1);
		HAL_GPIO_WritePin(led->gpio, led->pin_f, 1);
		HAL_GPIO_WritePin(led->gpio, led->pin_g, 0);
		break;
	case 4:
		HAL_GPIO_WritePin(led->gpio, led->pin_a, 1);
		HAL_GPIO_WritePin(led->gpio, led->pin_b, 0);
		HAL_GPIO_WritePin(led->gpio, led->pin_c, 0);
		HAL_GPIO_WritePin(led->gpio, led->pin_d, 1);
		HAL_GPIO_WritePin(led->gpio, led->pin_e, 1);
		HAL_GPIO_WritePin(led->gpio, led->pin_f, 0);
		HAL_GPIO_WritePin(led->gpio, led->pin_g, 0);
		break;
	case 5:
		HAL_GPIO_WritePin(led->gpio, led->pin_a, 0);
		HAL_GPIO_WritePin(led->gpio, led->pin_b, 1);
		HAL_GPIO_WritePin(led->gpio, led->pin_c, 0);
		HAL_GPIO_WritePin(led->gpio, led->pin_d, 0);
		HAL_GPIO_WritePin(led->gpio, led->pin_e, 1);
		HAL_GPIO_WritePin(led->gpio, led->pin_f, 0);
		HAL_GPIO_WritePin(led->gpio, led->pin_g, 0);
		break;
	case 6:
		HAL_GPIO_WritePin(led->gpio, led->pin_a, 0);
		HAL_GPIO_WritePin(led->gpio, led->pin_b, 1);
		HAL_GPIO_WritePin(led->gpio, led->pin_c, 0);
		HAL_GPIO_WritePin(led->gpio, led->pin_d, 0);
		HAL_GPIO_WritePin(led->gpio, led->pin_e, 0);
		HAL_GPIO_WritePin(led->gpio, led->pin_f, 0);
		HAL_GPIO_WritePin(led->gpio, led->pin_g, 0);
		break;
	case 7:
		HAL_GPIO_WritePin(led->gpio, led->pin_a, 0);
		HAL_GPIO_WritePin(led->gpio, led->pin_b, 0);
		HAL_GPIO_WritePin(led->gpio, led->pin_c, 0);
		HAL_GPIO_WritePin(led->gpio, led->pin_d, 1);
		HAL_GPIO_WritePin(led->gpio, led->pin_e, 1);
		HAL_GPIO_WritePin(led->gpio, led->pin_f, 1);
		HAL_GPIO_WritePin(led->gpio, led->pin_g, 1);
		break;
	case 8:
		HAL_GPIO_WritePin(led->gpio, led->pin_a, 0);
		HAL_GPIO_WritePin(led->gpio, led->pin_b, 0);
		HAL_GPIO_WritePin(led->gpio, led->pin_c, 0);
		HAL_GPIO_WritePin(led->gpio, led->pin_d, 0);
		HAL_GPIO_WritePin(led->gpio, led->pin_e, 0);
		HAL_GPIO_WritePin(led->gpio, led->pin_f, 0);
		HAL_GPIO_WritePin(led->gpio, led->pin_g, 0);
		break;
	case 9:
		HAL_GPIO_WritePin(led->gpio, led->pin_a, 0);
		HAL_GPIO_WritePin(led->gpio, led->pin_b, 0);
		HAL_GPIO_WritePin(led->gpio, led->pin_c, 0);
		HAL_GPIO_WritePin(led->gpio, led->pin_d, 0);
		HAL_GPIO_WritePin(led->gpio, led->pin_e, 1);
		HAL_GPIO_WritePin(led->gpio, led->pin_f, 0);
		HAL_GPIO_WritePin(led->gpio, led->pin_g, 0);
		break;
	default:
		HAL_GPIO_WritePin(led->gpio, led->pin_a, 1);
		HAL_GPIO_WritePin(led->gpio, led->pin_b, 1);
		HAL_GPIO_WritePin(led->gpio, led->pin_c, 1);
		HAL_GPIO_WritePin(led->gpio, led->pin_d, 1);
		HAL_GPIO_WritePin(led->gpio, led->pin_e, 1);
		HAL_GPIO_WritePin(led->gpio, led->pin_f, 1);
		HAL_GPIO_WritePin(led->gpio, led->pin_g, 1);
		break;
	}
}
