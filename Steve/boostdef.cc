#include "boostdef.h"
#include "player.h"
#include <iostream>
using namespace std;

BoostDef::BoostDef(){
	value=5;
	type = "Boost Def";
}

BoostDef::~BoostDef(){}



void BoostDef::effect(Player *player){
    if(player->getname()=="drow"){
        player->changedef(value*1.5);
    }
    else{
        player->changedef(value);
    }
}

string BoostDef::getname(){
	return type;
}
