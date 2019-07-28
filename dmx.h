#ifndef DMX_H_
#define DMX_H_



#define UART_BAUD 250000		// baud rate definition
#define __UBRR (F_CPU/(16UL*UART_BAUD)-1) //baud rate value

extern volatile uint8_t  DmxRxField[4]; //array of DMX vals (raw)  DMX Max:255 Min:0
extern volatile uint16_t DmxAddress;    //start address


volatile uint8_t gDmxState;


void USART_Init( uint16_t baud ); // initilization



#endif /* DMX_H_ */
