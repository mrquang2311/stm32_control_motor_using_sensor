#include "Button.h"
#include "Control.h"
#include "main.h"
#define Modee 1
#define Speedd 2
__weak void Test_button()
{
	
}

__weak void Test_Mode(uint8_t mode)
{
	
}

__weak void Test_Speed(uint8_t speed)
{

}

void Button_handle(Button_t *btn, uint8_t change_button)
{
	uint8_t sta = HAL_GPIO_ReadPin(btn->port, btn->pin);	
	if(btn->btn_filter != sta)	//check if button has change the state or not
	{
		btn->btn_filter = sta;
		btn->t_debounce = HAL_GetTick();	//get the last time button has change 
	}
	if(HAL_GetTick() - btn->t_debounce >= 15)	//if the present time - the last time it change state >= 15ms it's mean the button has fully pressed
	{
		btn->btn_current = btn->btn_filter;
		if(btn->btn_current != btn->btn_last)
			{
			//check if the button is press and choosing which button to swtich
			if(btn->btn_current == 0 && change_button == Modee)			//Button use to change mode clock wise or counter clock wise
			{
				Test_button();
				if(btn->change_mode < 4)
				{
					btn->change_mode++;
					
				}else if(btn->change_mode == 4)
				{
					btn->change_mode = 1;
				}uint8_t moode =btn->change_mode;
				Test_Mode(moode);
			}else if(btn->btn_current == 0 && change_button == Speedd)//button use to change Input speed
			{
				if(btn->change_speed == 0)
				{
					btn->change_speed = 1;
				}else if(btn->change_speed == 1)
				{
					btn->change_speed = 0;
				}uint8_t speeed = btn->change_speed;
				Test_Speed(speeed);
			}
			btn->btn_last = btn->btn_current;		//RESET last
		}
	}
	change_motor(btn->change_mode,btn->change_speed, change_button);
}

void Button_init(Button_t *btn,GPIO_TypeDef *port, uint16_t pin)
{
	btn->port = port;
	btn->pin = pin;
	btn->btn_current = 0;
	btn->btn_last = 1;
	btn->btn_filter = 1;
	btn->t_debounce = 0;
	btn->change_mode = 1;
	btn->change_speed = 0;
}
