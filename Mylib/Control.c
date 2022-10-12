#include "Control.h"
#include "AD_convert.h"
#include "Set_duty.h"
#include "main.h"
#define Modee 1
#define Speedd 2

uint8_t duty;
extern ADC_HandleTypeDef hadc1;
extern ADC_HandleTypeDef hadc2;
extern TIM_HandleTypeDef htim1;
extern TIM_HandleTypeDef htim2;
__weak void Test_Duty(uint8_t Duty)
{
	
}

//arduino library map
long map(long x, long in_min, long in_max, long out_min, long out_max) {
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

void change_motor(uint8_t state,uint8_t speed, uint8_t Button_change)
{
	if(Button_change == Modee)	//change the mode
	{
		if(state <= 4)
		{
			switch(state)
			{
				//stop
				case 1:																
					pwm_set_duty(0,&htim1,TIM_CHANNEL_1);
					pwm_set_duty(0,&htim2,TIM_CHANNEL_2);
				break;
				
				//clock wise
				case 2:
					pwm_set_duty(duty,&htim1,TIM_CHANNEL_1);
					pwm_set_duty(0,&htim2,TIM_CHANNEL_2);
				break;
				
				//stop
				case 3:
					pwm_set_duty(0,&htim1,TIM_CHANNEL_1);
					pwm_set_duty(0,&htim2,TIM_CHANNEL_2);
				break;
				
				//counter clock wise
				case 4:
					pwm_set_duty(0,&htim1,TIM_CHANNEL_1);
					pwm_set_duty(duty,&htim2,TIM_CHANNEL_2);
				break;
				
			}
		}
	}else if(Button_change == Speedd)	//change the speed
	{
		if(speed == 1)
		{
			duty = map(ADC(&hadc2),1200,4090,100,0);	//using the rheostat
			Test_Duty(duty);
		}else if(speed == 0)
		{
			duty = map(ADC(&hadc1),0,4095,0,100);			//using the photodiode sensor
			Test_Duty(duty);
		}
	}
}
