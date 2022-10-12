#ifndef __AD_convert_H__
#define	__AD_convert_H__
#include "main.h"

typedef struct
{
	ADC_HandleTypeDef* ADCp;
}ADC_t;

uint16_t ADC(ADC_HandleTypeDef* ADCp);
void ADC_init(ADC_t *Port,ADC_HandleTypeDef* ADCp);

#endif
