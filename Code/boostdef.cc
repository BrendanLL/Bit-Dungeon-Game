#include "boostdef.h"
#include "player.h"
#include <iostream>
using namespace std;

BoostDef::BoostDef(){
	value=5;
	type = "BoostDef";
}

BoostDef::~BoostDef(){}



void BoostDef::effect(Player *player){
	player->changedef(value);
}

string BoostDef::getname(){
	return type;
}
