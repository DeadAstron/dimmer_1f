#ifndef DIM_H_
#define DIM_H_


/*********************** D I M M E R  -   SETTINGS   ***************************/
#define STEP_VALUE 255 //quantity of steps

#define SPIKE_MS 0.25  // zero-cross spike lenght in ms  default: 1.8
/*********************** D I M M E R  -  SETTINGS   ***************************/

#define __OCR_STEP ((F_CPU/128)*((1000-((SPIKE_MS*100)/2))/STEP_VALUE))/100000

/*PINOUT*/
#define T_LIGHT1_ON PORTB |= (1<<PB0)
#define T_LIGHT1_OFF PORTB &= ~(1<<PB0)

#define T_LIGHT2_ON PORTD |= (1<<PD7)
#define T_LIGHT2_OFF PORTD &= ~(1<<PD7)

#define T_LIGHT3_ON PORTD |= (1<<PD6)
#define T_LIGHT3_OFF PORTD &= ~(1<<PD6)

#define T_LIGHT4_ON PORTB |= (1<<PB4)
#define T_LIGHT4_OFF PORTB &= ~(1<<PB4)

/*auxiliary variables */
volatile uint16_t steps;

volatile uint8_t ika1;
volatile uint8_t ika2;
volatile uint8_t ika3;
volatile uint8_t ika4;


void DIM_Init(); //initilization


#endif /* DIM_H_ */
