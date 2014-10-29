#include <iostream>
#include "Menu\Menu.h"
#include "Routine\Routine.h"
#include "Menuer.h"

using namespace std;

int main() {
	cout << "Welcome to the CK Home Automation System v1.0" << endl << endl;
	cout << "Press enter to continue..." << endl << endl;

	while (!_kbhit()); while (_kbhit()) getch(); fflush(stdin);

	while (Menu::running()) {
		MainMenu();
	}

	return 0;
}