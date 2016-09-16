#include "poisonhealth.h"
#include "player.h"
#include <iostream>
using namespace std;

class Player;

Poisonhealth::Poisonhealth(){
	value=-10;
	type = "Poison health";
}

Poisonhealth::~Poisonhealth(){}



void Poisonhealth::effect(Player *player){
    if(player->getname()=="drow"){
        player->changehp(value*1.5);
    }
    else{
        player->changehp(value);
    }
}

string Poisonhealth::getname(){
	return type;
}
