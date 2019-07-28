#ifndef LED_PWM_H_
#define LED_PWM_H_


#define LED1_ON PORTD |= (1<<PD5)
#define LED1_OFF PORTD &= ~(1<<PD5)

#define LED2_ON PORTB |= (1<<PB2)
#define LED2_OFF PORTB &= ~(1<<PB2)

#define LED3_ON PORTB |= (1<<PB1)
#define LED3_OFF PORTB &= ~(1<<PB1)

#define LED4_ON PORTB |= (1<<PB3)
#define LED4_OFF PORTB &= ~(1<<PB3)




void LED_Init();



#endif /* LED_PWM_H_ */
