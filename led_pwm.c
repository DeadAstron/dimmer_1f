#include <avr/io.h>
#include <avr/interrupt.h>

#include "led_pwm.h"
#include "dmx.h"

void LED_Init()
{
	DDRD |= (1<<PD5); //LED1
	DDRB |= (1<<PB2) | (1<<PB1) | (1<<PB3); //LED 2, 3, 4

	/*TIMER0*/
	TCCR0A |= (1<<WGM01); // CTC mode
	TCCR0B |= (1<<CS00); //prescaler = 1
	OCR0A |= 199; //divide by 200
	TIMSK0 |= (1<<OCIE0A); // Compare Match permission

	LED1_OFF;
	LED2_OFF;
	LED3_OFF;
	LED4_OFF;
}

ISR(TIMER0_COMPA_vect)
{
	static uint8_t cnt = 0;

	if(cnt<DmxRxField[0]) LED1_ON; else LED1_OFF;
	if(cnt<DmxRxField[1]) LED2_ON; else LED2_OFF;
	if(cnt<DmxRxField[2]) LED3_ON; else LED3_OFF;
	if(cnt<DmxRxField[3]) LED4_ON; else LED4_OFF;

	cnt++;
	if(cnt >= 255) cnt = 0;
}

