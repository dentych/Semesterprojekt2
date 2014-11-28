#pragma once
#include <string>
#include <iostream>

typedef void(*fPtr)();

class MenuItem {
	friend class Menu;
private:
	// Methods
	MenuItem(std::string id, std::string text, fPtr nextMenu);
	std::string getText() const;
	fPtr getNextMenu() const;
	void print() const;

	// Variables
	std::string id;
	std::string text;
	fPtr nextMenu;
};
