#include "Modtager.h"

void waitForStartNibble(void){
	// Alle LED'er er slukket
	writeAllLEDs(ledPort, 0);

	// Finding first startbit //////////////////
while (interrupt == 0){}
if (PIND & (1 << 6) == 0) {
	// move along sir!
	startNipple[0] = 0;
}
else if (PIND & (1 << 6)) {
	// first one ok!
	startNipple[0] = 1;
	// turning on LED0
	turnOnLED(ledPort, 0);
}
// reset interrupt flag
interrupt = 0;

// Finding second startbit //////////////////
	while (interrupt == 0){}
	if (PIND & (1 << 6) == 0) {
		// move along sir!
		startNipple[0] = 0;
	}
	else if (PIND & (1 << 6)) {
		// second one ok!
		startNipple[1] = 1;
		// turning on LED1
		turnOnLED(ledPort, 1);
	}
	// reset interrupt flag
	interrupt = 0;

// Finding thrid startbit //////////////////
	while (interrupt == 0){}
	if (PIND & (1 << 6) == 0) {
		// move along sir!
		startNipple[0] = 0;
	}
	else if (PIND & (1 << 6)) {
		// thrid one ok!
		startNipple[2] = 1;
		// turning on LED2
		turnOnLED(ledPort, 2);
	}
	// reset interrupt flag
	interrupt = 0;

// Finding fourth startbit //////////////////
	while (interrupt == 0){}
	if (PIND & (1 << 6) == 0) {
		// fourth one ok!
		startNipple[3] = 0;
		// turning on LED3
		turnOnLED(ledPort, 3);
	}
	else if (PIND & (1 << 6)) {
		// move along sir!
		startNipple[0] = 0;
	}
	// reset interrupt flag
	interrupt = 0;
}
