#include <avr/io.h>
#include <avr/interrupt.h>

#include "dim.h"
#include "dmx.h"



volatile uint16_t steps;
volatile uint8_t ika1;
volatile uint8_t ika2;
volatile uint8_t ika3;
volatile uint8_t ika4;


void DIM_Init()
{
	DDRD |= (1<<PD6)|(1<<PD7);
	DDRB |= (1<<PB0)|(1<<PB4);

	T_LIGHT1_OFF; T_LIGHT2_OFF; T_LIGHT3_OFF; T_LIGHT4_OFF;

	// Interrupt INT1
	EICRA |= (1<<ISC11);     // falling edge
	EIMSK |= (1<<INT1);		 // unlock INT1

	// TIMER2
#define TIMER2_START TCCR2B |= (1<<CS22) | (1<<CS20)	// prescaler=128
#define TIMER2_STOP TCCR2B &= ~( (1<<CS22) | (1<<CS20) )	// prescaler off
	TCCR2A |= (1<<WGM21);				// CTC mode
	TIMSK2 |= (1<<OCIE2A);				// unlock COMPARE MATCH
	OCR2A = __OCR_STEP;
}


ISR(INT1_vect)
{
	TIMER2_STOP;
	T_LIGHT1_OFF; T_LIGHT2_OFF; T_LIGHT3_OFF; T_LIGHT4_OFF;

	steps=STEP_VALUE;

	/* double buffering, sync to 50Hz */
	ika1=DmxRxField[0];
	ika2=DmxRxField[1];
	ika3=DmxRxField[2];
	ika4=DmxRxField[3];

	TCNT2 = 0;
	TIMER2_START;
}


ISR(TIMER2_COMPA_vect)
{
	if(ika1 && steps == ika1) T_LIGHT1_ON;
	if(ika2 && steps == ika2) T_LIGHT2_ON;
	if(ika3 && steps == ika3) T_LIGHT3_ON;
	if(ika4 && steps == ika4) T_LIGHT4_ON;
	steps--;
}
