#include "boostatk.h"
#include "player.h"
#include <iostream>
using namespace std;

BoostAtk::BoostAtk(){
	value=5;
	type = "Boost Atk";
}

BoostAtk::~BoostAtk(){}


void BoostAtk::effect(Player *player){
    if(player->getname()=="drow"){
       player->changeatk(value*1.5);
    }
    else{
        player->changeatk(value);
    }
}

string BoostAtk::getname(){
	return type;
}
