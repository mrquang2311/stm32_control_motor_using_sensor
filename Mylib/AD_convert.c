#include "AD_convert.h"
#include "main.h"

uint16_t ADC(ADC_HandleTypeDef* ADCp)
{
	HAL_ADC_Start(ADCp);
	HAL_ADC_PollForConversion(ADCp,10);
	uint16_t adc = HAL_ADC_GetValue(ADCp);
	HAL_ADC_Stop(ADCp);
	return adc;
}

void ADC_init(ADC_t *Port,ADC_HandleTypeDef* ADCp)
{
	Port->ADCp = ADCp;
}
