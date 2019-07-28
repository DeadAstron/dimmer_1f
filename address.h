#ifndef ADDRESS_H_
#define ADDRESS_H_


//pins for dip-switch

#define DIP0_PIN (1<<PC5)
#define DIP1_PIN (1<<PC4)
#define DIP2_PIN (1<<PC3)
#define DIP3_PIN (1<<PC2)
#define DIP4_PIN (1<<PC1)
#define DIP5_PIN (1<<PC0)
#define DIP6_PIN (1<<PD2)
#define DIP7_PIN (1<<PD4)
#define DIP8_PIN (1<<PB5)

//reading procedure
#define ADR_DIP0 !(PINC & DIP0_PIN)
#define ADR_DIP1 !(PINC & DIP1_PIN)
#define ADR_DIP2 !(PINC & DIP2_PIN)
#define ADR_DIP3 !(PINC & DIP3_PIN)
#define ADR_DIP4 !(PINC & DIP4_PIN)
#define ADR_DIP5 !(PINC & DIP5_PIN)
#define ADR_DIP6 !(PIND & DIP6_PIN)
#define ADR_DIP7 !(PIND & DIP7_PIN)
#define ADR_DIP8 !(PINB & DIP8_PIN)

//address getter
void getAddress();


#endif /* ADDRESS_H_ */
