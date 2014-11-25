#include "Routine.h"
#include <iostream>

Routine::Routine(string name){
	name_ = name;
}

int Routine::setDelay(int delay){
	delay_ = delay;
}
void Routine::setID(char ID){
	modtagerID.push_back(ID);
}

int Routine::getIDSize(){
	return modtagerID.size();
}

int Routine::getIDList(){
	for (unsigned int i = 0; i < modtagerID.size(); i++)
		cout << modtagerID[i] << endl;
}