#include "display.h"
#include <ncurses.h>
#include <iostream>
using namespace std;

Display::Display() {
	theDisplay = new char*[25];
	for (int i = 0;i < 25;i++) {
		theDisplay[i] = new char[79];
        for (int j = 0;j < 79;j++){
			theDisplay[i][j] = ' ';
	     }
     }
}

Display::~Display() {
	for (int i = 0;i < 25;i++) {
		delete[]theDisplay[i];
	}
	delete[]theDisplay;
}

void Display::notify(int row, int column, char ch) {
	theDisplay[row][column] = ch;
}

void Display::print(std::ostream &out)const {
	for (int i = 0;i < 25;i++) {
		for (int j = 0;j < 79;j++) {
			printw("%c",theDisplay[i][j]);
		}printw("\n");
	}
}
