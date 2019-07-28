#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#include "dmx.h"
#include "dim.h"
#include "led_pwm.h"
#include "address.h"


void startup(); // hardware test


int main()
{
	LED_Init(); //status led init

	DIM_Init(); // dimming init

	sei(); // interrupt permission

	startup(); //intro

	getAddress(); //getting address

	USART_Init(__UBRR); // dmx uart init, baud=250k



	while(1)
	{
		/*
		for(int i =0; i < 256; i++ )
		{
			DmxRxField[0] = i;
			DmxRxField[1] = i;
			DmxRxField[2] = i;
			DmxRxField[3] = i;
			_delay_ms(5);
		}
		*/
	}

	return 0;
}


void startup()
{
	for(int i = 0; i < 4; i++)
	{
		DmxRxField[i] = 255;
		_delay_ms(500);
		DmxRxField[i] = 0;
	}
}

