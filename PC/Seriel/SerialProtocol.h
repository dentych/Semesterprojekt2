#pragma once
#include "Serial.h"
#include "../Routine/Routine.h"

class SerialProtocol{

public:
	/*!
	* Open connection to Serial COM port
	* 
	* @param baudRate	The baudRate.
	* @returns true or false. True for successful connection, false otherwise.
	*/
	bool openConnection(int baudRate);

	/*!
	* Check if the STK controller is unlocked (Protocol(1)).
	* 
	* @return True if unlocked, false if locked.
	*/
	bool isUnlocked();

	/*!
	Start routine and send the Routine object's data to the STK
	over Serial communication (Protocol(2)).

	@return True if routine was successfully started, false otherwise
	*/
	bool startRoutine(Routine & routine);

	/*!
	Stop the routine that is currently going. If no routine is active,
	it will still attempt to stop it, though the STK will figure out that
	the no routine is active and simply do nothing.

	@return True if the routine was successfully stopped (or no active routine is going),
	false otherwise.
	*/
	bool stopRoutine();
private:
	CSerial cs;
	int sendChar(char data);
	char readData();
};