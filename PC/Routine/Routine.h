#pragma once
#include <string>
#include <vector>

using namespace std;

class Routine {
public:
	Routine(string name);
	void setDelay(int delay);
	void addID(char ID);
	char getIDSize() const;
	char getIDData(int index) const;
	char getDelay() const;
private:
	string name_;
	vector<char> modtagerID;
	int delay_;
};