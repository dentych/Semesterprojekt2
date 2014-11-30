#ifndef MODTAGER_H_
#define MODTAGER_H_

#include <avr/io.h>

unsigned char interrupt;
unsigned char startNipple[4];
unsigned char ledPort;

void waitForStartNibble(void);

#endif /* MODTAGER_H_ */