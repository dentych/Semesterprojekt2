#include "Menu.h"

bool Menu::run = true;

Menu::Menu(std::string title) {
	choice = 0;
	this->title = title;
}

Menu::~Menu() {
	if (choice > 0) {
		menuList.at(choice - 1).getNextMenu()();
	}
}

Menu & Menu::addMenuItem(std::string id, std::string text, fPtr nextMenu) {
	menuList.push_back(MenuItem(id, text, nextMenu));

	return *this;
}

void Menu::drawMenu() {
	system("CLS");

	setCursor(5, 1);
	std::cout << getTitle() << std::endl;
	setCursor(3, 2);
	std::cout << "----------------------" << std::endl;

	for (int i = 0; i < menuList.size(); i++) {
		setCursor(3, i + 3);
		menuList.at(i).print();
	}

	setCursor(3, menuList.size() + 4);
	std::cout << "Action: ";
}

int Menu::getChoice() {
	std::string choice;
	int menuNum;

	std::cin >> choice;

	try {
		menuNum = stoi(choice);

		if (menuNum <= menuList.size()) {
			this->choice = menuNum;
			return menuNum;
		}
	}
	catch (const std::invalid_argument & ex) {
		if (choice.compare("q") == 0 && getTitle().compare("Main menu") == 0) {
			run = false;
		}
		else {
			this->choice = menuList.size();
			return menuList.size();
		}
	}
}

std::string Menu::getTitle() const {
	return title;
}

void Menu::setCursor(int posX, int posY) {
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;
	pos.X = posX;
	pos.Y = posY;

	SetConsoleCursorPosition(handle, pos);
}

Menu & Menu::addData(const std::string & dataText) {
	data.push_back(dataText);

	return *this;
}

bool Menu::running() {
	return run;
}