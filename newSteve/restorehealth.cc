#include "restorehealth.h"
#include "player.h"
#include <iostream>
using namespace std;

Restorehealth::Restorehealth(){
	value=10;
	type = "Restore Health";
}

Restorehealth::~Restorehealth(){}



void Restorehealth::effect(Player *player){
    if(player->getname()=="drow"){
        player->changehp(value*1.5);
    }
    else{
        player->changehp(value);
    }
}

string Restorehealth::getname(){
	return type;
}
