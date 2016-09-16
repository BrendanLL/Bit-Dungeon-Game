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
    if(obj==NULL){
        setState('.');
        return;
    }
    string sb=obj->getname();
    char cap;
    if(sb=="Human"){
        cap='H';
    }
    else if(sb=="Dwarf"){
        cap='W';
    }
    else if(sb=="Elf"){
        cap='E';
    }
    else if(sb=="Orcs"){
        cap='O';
    }
    else if(sb=="Merchant"){
        cap='M';
    }
    else if(sb=="Dragon"){
        cap='D';
    }
    else if(sb=="Halfling"){
        cap='L';
    }
    else{
        cap='l';
    }
	setState(cap);
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
	if (symbol == '+' || symbol == '#' || symbol == 'G' || symbol == '\\') { setwalkable(true, false); }
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
    Cell* target = game->getcell(x, y, com);
    target->setState(getchar());
    target->setenemy(this->ene); //error?
	setState('.');
    removeobj();
}

void Cell::removeobj() {
    //if(ene!=NULL)delete ene;
    //if(pot!=NULL)delete pot;
    //if(gold!=NULL)delete gold;
	ene = NULL;
	pot = NULL;
	gold = NULL;
	//setState(this->previus);
}


void Cell::notify() {
	game->notify(x, y, symbol);
}
