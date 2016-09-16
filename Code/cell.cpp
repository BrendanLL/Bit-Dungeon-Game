#include "cell.h"
#include "game.h"
#include "potion.h"
#include "gold.h"
#include "enemy.h"
#include <iostream>
using namespace std;


Cell::Cell() {
	x = 0;
	y = 0;
	pwalkable = false;
	ewalkable = false;
	symbol = ' ';
	previus = ' ';
	ene = NULL;
	pot = NULL;
	gold = NULL;
	game = NULL;
}


void Cell::setenemy(Enemy* obj) {
	this->ene = obj;
	setState('e');
}
void Cell::setpotion(Potion* obj) {
	this->pot = obj;
	setState('P');
}
void Cell::setgold(Gold* obj) {
	this->gold = obj;
	setState('G');
}

void Cell::setState(char symbol) {
	this->previus = this->symbol;
	this->symbol = symbol;
	if (symbol == '+' || symbol == '#' || symbol == 'G') { setwalkable(true, false); }
	else if(symbol=='.'){ setwalkable(true, true); }
	else{ setwalkable(false, false); }
	notify();
}

void Cell::setCoords(const int row, const int column) {
	x = row;
	y = column;
}
void Cell::setGame(Game * game) {
	this->game = game;
}
void Cell::setwalkable(bool pw, bool ew) {
	pwalkable = pw;
	ewalkable = ew;
}

Cell::~Cell() {
	delete ene;
	delete pot;
	delete gold;
}

void Cell::move(std::string com) {
	int row = x; int column = y;
	if (com == "no") { row -= 1; }
	if (com == "so") { row += 1; }
	if (com == "ea") { column += 1; }
	if (com == "we") { column -= 1; }
	if (com == "ne") { row -= 1; column += 1; }
	if (com == "nw") { row -= 1; column -= 1; }
	if (com == "se") { row += 1; column += 1; }
	if (com == "sw") { row += 1; column -= 1; }
	Cell* target = game->getcell(x, y);
	target->setState(this->symbol);
	target->setenemy(this->ene);
	removeobj();
}

void Cell::removeobj() {
	ene = NULL;
	pot = NULL;
	gold = NULL;
	setState(this->previus);
}


void Cell::notify() {
	std::cout << "Check Point2 " << x << y << symbol << endl;
	game->notify(x, y, symbol);
}
