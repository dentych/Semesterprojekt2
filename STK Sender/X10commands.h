#ifndef X10COMMANDS_H_
#define X10COMMANDS_H_

#include <avr/interrupt.h>
#include <util/delay.h>

void startBurst(void);

void startKommando(	unsigned char* unitCode, unsigned char* command);

void X10turnOff(unsigned char);

void X10turnOn(unsigned char);

#endif /* X10COMMANDS_H_ */