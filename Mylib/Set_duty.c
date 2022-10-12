#include "Set_duty.h"
#include "main.h"

void pwm_set_duty(uint8_t duty,TIM_HandleTypeDef *htim, uint32_t Channel)
{
	uint16_t ccr = duty*htim->Instance->ARR/100;
	switch(Channel)
	{
		case TIM_CHANNEL_1:
			htim->Instance->CCR1 = ccr;
		break;
		
		case TIM_CHANNEL_2:
			htim->Instance->CCR2 = ccr;
		break;
	}
}
