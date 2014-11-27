#include <vector>
#include "Routine.h"

class RoutineList {
public:
	void addRoutine(Routine & routine);
	void removeRoutine(int index);
	Routine & getRoutine(int index);
	bool saveRoutines();
	bool loadRoutines();
	int getListSize() const;
private:
	vector<Routine> list;
};
