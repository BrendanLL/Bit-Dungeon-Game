#include "boostatk.h"
#include "player.h"
#include <iostream>
using namespace std;

BoostAtk::BoostAtk(){
	value=5;
	type = "BoostAtk";
}

BoostAtk::~BoostAtk(){}


void BoostAtk::effect(Player *player){
	player->changeatk(value);
}

string BoostAtk::getname(){
	return type;
}
