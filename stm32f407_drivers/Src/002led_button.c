/*
 * 002led_button.c
 *
 *  Created on: Aug 13, 2024
 *      Author: crazy
 */


#include "stm32f407xx.h"

#define HIGH 1
#define BTN_PRESSED HIGH

void delay(void)
{
	for(uint32_t i=0;i< 500000/2;i++);
}
int main(void)
{

	GPIO_Handle_t GpioLed,GPIOBtn;  //create a variable for gpio handle, use gpio structure

	GpioLed.pGPIOx = GPIOD; // select the port, here D port
	GpioLed.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_12; // pin configuration , include gpio driver.h file
	GpioLed.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUT; //pin mode is output
	GpioLed.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST; // speed can be anything
	GpioLed.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_PP;//use case one push pull
	GpioLed.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_NO_PUPD;

	GPIO_PeriClockControl(GPIOD, ENABLE);
	GPIO_Init(&GpioLed);

	GPIOBtn.pGPIOx = GPIOA; // select the port, here D port
	GPIOBtn.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_0; // pin configuration , include gpio driver.h file
	GPIOBtn.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_IN; //pin mode is output
	GPIOBtn.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST; // speed can be anything
	GPIOBtn.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_NO_PUPD;

	GPIO_PeriClockControl(GPIOA, ENABLE);
	GPIO_Init(&GPIOBtn);
	while(1)
	{
		if(GPIO_ReadFromInputPin(GPIOA, GPIO_PIN_NO_0)== BTN_PRESSED)
		{
			delay();
			GPIO_ToggleOutputPin(GPIOD,GPIO_PIN_NO_12 );
		}


	}
	return 0;
}
