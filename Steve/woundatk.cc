#include "woundatk.h"
#include "player.h"
#include <iostream>
using namespace std;

WoundAtk::WoundAtk(){
	value=-5;
	type = "Wound Atk";
}

WoundAtk::~WoundAtk(){}



void WoundAtk::effect(Player *player){
    if(player->getname()=="drow"){
        player->changeatk(value*1.5);
    }
    else{
        player->changeatk(value);
    }
}

string WoundAtk::getname(){
	return type;
}
