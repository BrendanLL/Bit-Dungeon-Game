#include "dragonhoard.h"
#include "player.h"
#include <iostream>
using namespace std;


DragonHoard::DragonHoard(){
	value=6;
	num = 1;
	name = "dragon hoard";
	getable=false;
}

DragonHoard::~DragonHoard(){}

void DragonHoard::effect(Player* player){
	player->changegold(value*num);
}


string DragonHoard::getname(){
     return name;
}
