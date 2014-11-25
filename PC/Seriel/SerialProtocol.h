#pragma once
#include "Serial.h"
#include "../Routine/Routine.h"

class SerialProtocol{

public:
	bool openConnection(int baudRate);
	bool isUnlocked();
	bool startRoutine(Routine & routine);
	bool stopRoutine();
private:
	CSerial cs;
	int sendChar(char data);
	char readData();
};