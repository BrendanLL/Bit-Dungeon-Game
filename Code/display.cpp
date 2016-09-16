#include "display.h"
#include <iostream>
using namespace std;

Display::Display() {
	theDisplay = new char*[25];
	for (int i = 0;i < 25;i++) {
		theDisplay[i] = new char[79];
		for (int j = 0;j < 79;j++)
			theDisplay[i][j] = ' ';
	}
}

Display::~Display() {
	for (int i = 0;i < 25;i++) {
		delete[]theDisplay[i];
	}
	delete[]theDisplay;
}

void Display::notify(int row, int column, char ch) {
	//std::cout << "Check Point4 " << row <<" " << column <<endl;
	theDisplay[row][column] = ch;
	//std::cout << "Check Point5 " << endl;
}

void Display::print(std::ostream &out)const {
	for (int i = 0;i < 25;i++) {
		for (int j = 0;j < 79;j++) {
			out << theDisplay[i][j];
		}out << std::endl;
	}
}
