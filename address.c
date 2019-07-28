#include <avr/io.h>
#include <avr/interrupt.h>

#include "address.h"
#include "dmx.h"


void getAddress()
{
	//setup as input
	DDRB &= ~(DIP8_PIN);
	DDRD &= ~(DIP6_PIN | DIP7_PIN);
	DDRC &= ~(DIP5_PIN | DIP4_PIN | DIP3_PIN | DIP2_PIN | DIP1_PIN | DIP0_PIN);

	//unlock pull-up resistors
	PORTB |= DIP8_PIN;
	PORTD |= DIP6_PIN | DIP7_PIN;
	PORTC |= DIP5_PIN | DIP4_PIN | DIP3_PIN | DIP2_PIN | DIP1_PIN | DIP0_PIN;

	//start from 0
	DmxAddress = 0;

	//count binary value
	if(ADR_DIP0) DmxAddress += 1;
	if(ADR_DIP1) DmxAddress += 2;
	if(ADR_DIP2) DmxAddress += 4;
	if(ADR_DIP3) DmxAddress += 8;
	if(ADR_DIP4) DmxAddress += 16;
	if(ADR_DIP5) DmxAddress += 32;
	if(ADR_DIP6) DmxAddress += 64;
	if(ADR_DIP7) DmxAddress += 128;
	if(ADR_DIP8) DmxAddress += 256;

	if(DmxAddress == 0) DmxAddress = 1;
	if(DmxAddress > 509) DmxAddress = 509;
}
