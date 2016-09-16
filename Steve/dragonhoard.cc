#include "dragonhoard.h"
#include "player.h"
#include "enemy.h"
#include <iostream>
using namespace std;


DragonHoard::DragonHoard(){
	value=6;
	num = 1;
	name = "dragon hoard";
	getable=false;
    D = NULL;
}

DragonHoard::~DragonHoard(){}

void DragonHoard::effect(Player* player){
	player->changegold(value*num);
}


string DragonHoard::getname(){
     return name;
}
