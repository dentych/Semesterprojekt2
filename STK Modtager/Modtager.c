#include "Modtager.h"
#include "Led.h"
#include "LysTilTest.h"

unsigned char ledPort;

void modtagerMain(void){
	ledPort = 0;
	initLEDport(ledPort);
	
	
}

void waitForStartbit(void){
	
}