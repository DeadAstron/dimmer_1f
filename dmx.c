#include <avr/io.h>
#include <avr/interrupt.h>

#include "dmx.h"
#include "dim.h"



volatile uint8_t  DmxRxField[4]; //array of DMX vals (raw)  DMX Max:255 Min:0
volatile uint16_t DmxAddress;    //start address
enum {
  IDLE, BREAK, STARTB, STARTADR}; //DMX states
volatile uint8_t gDmxState;


void USART_Init( uint16_t baud ) {
	/* baud rate speed */
	UBRR0H = (uint8_t)(baud>>8);
	UBRR0L = (uint8_t)baud;

	/* receiver on */
	UCSR0B = (1<<RXEN0) | (1<<RXCIE0);

	/* Frame format: 8bits data, 1 bit stop */
	UCSR0C = (3<<UCSZ00);

	gDmxState = IDLE;
}


ISR(USART_RX_vect) {
  static  uint16_t DmxCount;
  uint8_t  USARTstate= UCSR0A;    //get state before data!
  uint8_t  DmxByte   = UDR0;          //get data
  uint8_t  DmxState  = gDmxState; //just load once from SRAM to increase speed

  if (DmxState == STARTADR)
  {
    DmxRxField[DmxCount++]= DmxByte;        //get channel
    if (DmxCount >= sizeof(DmxRxField)) //all ch received?
    {
      gDmxState= IDLE;        //wait for next break
    }
  }
  else if (USARTstate &(1<<FE0))               //check for break
  {
    DmxCount =  DmxAddress;         //reset channel counter (count channels before start address)
    gDmxState= BREAK;
  }

  else if (DmxState == BREAK)
  {
    if (DmxByte == 0) gDmxState= STARTB;  //normal start code detected
    else                      gDmxState= IDLE;
  }

  else if (DmxState == STARTB)
  {
    if (--DmxCount == 0)    //start address reached?
    {
      DmxCount= 1;            //set up counter for required channels
      DmxRxField[0]= DmxByte; //get 1st DMX channel of device
      gDmxState= STARTADR;
    }
  }
}
