#include "wounddef.h"
#include "player.h"
#include <iostream>
using namespace std;

WoundDef::WoundDef(){
	value=-5;
	type = "WoundDef";
}

WoundDef::~WoundDef(){}



void WoundDef::effect(Player *player){
	player->changedef(value);
}

string WoundDef::getname(){
	return type;
}
