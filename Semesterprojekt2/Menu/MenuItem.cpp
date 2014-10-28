#include "MenuItem.h"

MenuItem::MenuItem(std::string id, std::string text, fPtr nextMenu) {
	this->id = id;
	this->text = text;
	this->nextMenu = nextMenu;
}

std::string MenuItem::getText() const {
	return text;
}

fPtr MenuItem::getNextMenu() const {
	return nextMenu;
}

void MenuItem::print() const {
	try {
		int iID = stoi(id);
		std::cout << (iID < 10 ? " " : "") << id
			<< ".\t" << text << std::endl;
	}
	catch (const std::invalid_argument & ex) {
		std::cout << " " << id << ".\t" << text << std::endl;
	}
}