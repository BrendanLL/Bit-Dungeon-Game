#include "woundatk.h"
#include "player.h"
#include <iostream>
using namespace std;

WoundAtk::WoundAtk(){
	value=-5;
	type = "WoundAtk";
}

WoundAtk::~WoundAtk(){}



void WoundAtk::effect(Player *player){
	player->changeatk(value);
}

string WoundAtk::getname(){
	return type;
}
