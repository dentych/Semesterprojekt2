#ifndef MODTAGER_H_
#define MODTAGER_H_

#define F_CPU 3686000
#include <util/delay.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include "LysTilTest.h"

// Globale variabler
unsigned char interrupt;

// Funktioner til modtageren
// Venter på at der er modtaget en bitsekvens på 20 bits, og sørger for at tjekke, at den er korrekt formarteret.
void receiveBitSequence(unsigned char * outputReceivedBits);

void waitForInterrupt();

// Læser, hvad der står på PORTD6
unsigned char readBit();

#endif