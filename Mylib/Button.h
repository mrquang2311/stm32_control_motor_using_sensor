#ifndef __BUTTON_H__
#define	__BUTTON_H__
#include "main.h"
typedef struct
{
	GPIO_TypeDef *port;
	uint16_t pin;
	uint8_t btn_current;
	uint8_t btn_last;
	uint8_t btn_filter;
	uint32_t t_debounce;
	uint8_t change_mode;
	uint8_t change_speed;
}Button_t;

void Button_handle(Button_t *btn, uint8_t change_button);
void Button_init(Button_t *btn,GPIO_TypeDef *port, uint16_t pin);

#endif
