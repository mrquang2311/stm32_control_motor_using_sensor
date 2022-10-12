#ifndef __SET_DUTY_H__
#define	__SET_DUTY_H__
#include "main.h"

void pwm_set_duty(uint8_t duty,TIM_HandleTypeDef *htim, uint32_t Channel);
#endif
