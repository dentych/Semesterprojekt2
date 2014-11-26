void initLEDport(unsigned char hvilkenPort); /* 
0 = PORTA
1 = PORTB
2 = PORTC
3 = PORTD 
*/
void writeAllLEDs(unsigned char hvilkenPort, unsigned char pattern);/*
hvilkenPort: 0=A, 1=B ...
patteren: giver sig selv
*/
void turnOnLED(unsigned char hvilkenPort, unsigned char led_nr);/*
hvilkenPort: 0=A, 1=B ...
led_nr: tænder den valgte led
*/
void turnOffLED(unsigned char hvilkenPort, unsigned char led_nr);/*
hvilkenPort: 0=A, 1=B ...
led_nr: slukker den valgte led
*/
void toggleLED(unsigned char hvilkenPort, unsigned char led_nr);/*
hvilkenPort: 0=A, 1=B ...
*/