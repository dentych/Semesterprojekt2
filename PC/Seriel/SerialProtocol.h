#pragma once
#include "Serial.h"
#include "../Routine/Routine.h"

class SerialProtocol{

public:
	bool checkLockStatus();
	void sendRoutine();
private:
	bool initSerial();
};