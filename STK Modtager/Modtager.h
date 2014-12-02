#include "Switch.h"
#include <avr/io.h>
#define MAX_SWITCH_NR 7

void initSwitchPort(unsigned char hvilkenPort){
	if(hvilkenPort == 0){
		DDRA = 0x00;
	}
	else if(hvilkenPort == 1){
		DDRB = 0x00;
	}
	else if(hvilkenPort == 2){
		DDRC = 0x00;
	}
	else if(hvilkenPort == 3){
		DDRD = 0x00;
	}
}
unsigned char switchStatus(unsigned char hvilkenPort){
	if(hvilkenPort == 0){
		return ~PINA;
	}
	else if(hvilkenPort == 1){
		return ~PINB;
	}
	else if(hvilkenPort == 2){
		return ~PINC;
	}
	else if(hvilkenPort == 3){
		return ~PIND;
	}
}
unsigned char switchOn(unsigned char hvilkenPort, unsigned char switch_nr){
	if(hvilkenPort == 0){
		if(switch_nr <= MAX_SWITCH_NR){
			unsigned char mask = ~(PINA | ~(1<<switch_nr));
			return mask;
		}
	}
	else if(hvilkenPort == 1){
		if(switch_nr <= MAX_SWITCH_NR){
			unsigned char mask = ~(PINB | ~(1<<switch_nr));
			return mask;
		}
	}
	else if(hvilkenPort == 2){
		if(switch_nr <= MAX_SWITCH_NR){
			unsigned char mask = ~(PINC | ~(1<<switch_nr));
			return mask;
		}
	}
	else if(hvilkenPort == 3){
		if(switch_nr <= MAX_SWITCH_NR){
			unsigned char mask = ~(PIND | ~(1<<switch_nr));
			return mask;
		}
	}
}
