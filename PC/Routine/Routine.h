#pragma once
using namespace std;
#include <string>
#include <vector>


class Routine
{
public:
	Routine(string name);
	int setDelay(int delay);
	void setID(char ID);
	int getIDSize();
	int getIDList();
private:
	string name_;
	vector<char> modtagerID;
	int delay_;
};