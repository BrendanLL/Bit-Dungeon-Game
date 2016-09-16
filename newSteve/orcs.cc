#include "orcs.h"
#include "player.h"
#include <iostream>
using namespace std;



Orcs::Orcs(){
	hp=180;
	atk=30;
	def=25;
	name="Orcs";
	//hostile=true;
    moved = false;
    assigned = false;
}



Orcs::~Orcs(){}



int Orcs::drop(){
    return 0;
}


void Orcs::combat(Player *player){
    player->beattack(this);
}

void Orcs::bcombat(Player *player){
    player->attack(this);
}
