#ifndef SENDER_H_
#define SENDER_H_

#define F_CPU 3686400
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include "UART.h"
#include "Led.h"
#include "Switch.h"
#include "X10commands.h"


// LED og Switch porte erklæres
unsigned char ledPort;
unsigned char switchPort;

// globale konstanter
unsigned char receivedFromPc;	// latest char received from PC
unsigned char locked;		// 0 = unlocked

// Routine data
unsigned char lysStatus;
unsigned char ID_size;
unsigned char ID_list[16];
unsigned char delay;

int checkForQ(char checkThis);

void startRoutine(void);

void stopRoutine(void);

void confirmingLights(void);

void showoff(void);

void chtobin(char toBeConverted, char * bitwise);

#endif /* SENDER_H_ */
