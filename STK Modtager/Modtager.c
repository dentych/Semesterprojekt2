#include "Modtager.h"

void receiveBitSequence(unsigned char * outputReceivedBits) {
	// ** Globale variabler til funktionen ** //
	// Mængde af bits indlæst. Bruges til at vælge næste plads i outputReceivedBits der skal læses ind på.
	unsigned char readBits = 0;
	// Variabel til at holde den sidst læste bit.
	unsigned char lastBit;
	// Styrer while loopet, som kører, så længe der ikke er indlæst en hel X10 streng på 20 bit.
	unsigned char correctlyRead = 0;
	// ** ** ** ** ** ** ** ** ** ** ** ** ** //
	
	unsigned char i;
	
	while (correctlyRead == 0) {
		// Wait until interrupt to read data
		// For loopet til aflæsning af startbit sekvensen (1110).
		for (i = 0; i < 4; i++) {
			waitForInterrupt();
			lastBit = readBit();
			if (i < 3 && lastBit == 0) {
				// Starter forfra hvis en af de første tre bit i startsekvensen er 0
				i = -1;
			}
			else if (i == 3 && lastBit == 1) {
				// Starter forfra hvis en af de første tre bit i startsekvensen er 1
				i = -1;
			}
		}
		
		toggleLED(ledPort, 7);
		
		for (i = 0; i < 16; i++) {
			waitForInterrupt();
			lastBit = readBit();
			outputReceivedBits[i] = lastBit;
		}
		
		//for (i = 0; i < 8; i++) {
			//if (outputReceivedBits[i*2] == 0 && outputReceivedBits[i*2+1] == 1) {
				//toggleLED(ledPort, i);
			//}
			//else if (outputReceivedBits[i*2] == 1 && outputReceivedBits[i*2+1] == 0) {
				//toggleLED(ledPort, i);
			//}
			//_delay_ms(200);
		//}
		
		correctlyRead = 1;
	}
	
	for (i = 0; i < 6; i++) {
		waitForInterrupt();
	}
	
	toggleLED(ledPort, 0);
	toggleLED(ledPort, 1);
	toggleLED(ledPort, 2);
}

void waitForInterrupt() {
	while (interrupt == 0)
	{
		_delay_us(1);
	}
	
	interrupt = 0;
}

unsigned char readBit() {
	if (PIND & (1<<6)) {
		return 1;
	}
	else {
		return 0;
	}
}
