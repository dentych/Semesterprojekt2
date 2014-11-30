#pragma once
#include <string>
#include <vector>

using namespace std;

class Routine {
public:
	void setName(string name);
	void setDelay(int delay);
	void addID(int ID);
	string getName() const;
	int getIDSize() const;
	int getIDData(int index) const;
	int getDelay() const;
private:
	string name_;
	vector<char> modtagerID;
	int delay_;
};