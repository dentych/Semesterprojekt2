#pragma once
using namespace std;
#include <string>
#include <vector>


class Routine
{
public:
	Routine(string name);
	void setDelay(int delay);
	void setID(char ID);
	char getIDSize() const;
	char getIDData(int index) const;
	char getDelay() const;
private:
	string name_;
	vector<char> modtagerID;
	int delay_;
};