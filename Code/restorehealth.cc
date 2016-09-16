#include "restorehealth.h"
#include "player.h"
#include <iostream>
using namespace std;

Restorehealth::Restorehealth(){
	value=10;
	type = "RH";
}

Restorehealth::~Restorehealth(){}



void Restorehealth::effect(Player *player){
	player->changehp(value);
}

string Restorehealth::getname(){
	return type;
}
