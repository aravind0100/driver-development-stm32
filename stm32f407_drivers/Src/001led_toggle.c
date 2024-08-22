/*
 * 001led_toggle.c
 *
 *  Created on: Aug 6, 2024
 *      Author: crazy
 */

#include "stm32f407xx.h"

void delay(void)
{
	for(uint32_t i=0;i< 500000/2;i++);
}
int main(void)
{

	GPIO_Handle_t GpioLed;  //create a variable for gpio handle, use gpio structure

	GpioLed.pGPIOx = GPIOD; // select the port, here D port
	GpioLed.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_12; // pin configuration , include gpio driver.h file
	GpioLed.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUT; //pin mode is output
	GpioLed.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_LOW; // speed can be anything
	GpioLed.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_OD;//use case one push pull
	GpioLed.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_PIN_PU;

	GPIO_PeriClockControl(GPIOD, ENABLE);
	GPIO_Init(&GpioLed);

	while(1)
	{
		GPIO_ToggleOutputPin(GPIOD,GPIO_PIN_NO_12 );
		delay();
	}
	return 0;
}
