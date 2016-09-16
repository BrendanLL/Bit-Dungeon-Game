#include "wounddef.h"
#include "player.h"
#include <iostream>
using namespace std;

WoundDef::WoundDef(){
	value=-5;
	type = "Wound Def";
}

WoundDef::~WoundDef(){}



void WoundDef::effect(Player *player){
    if(player->getname()=="drow"){
        player->changedef(value*1.5);
    }
    else{
        player->changedef(value);
    }
}

string WoundDef::getname(){
	return type;
}
