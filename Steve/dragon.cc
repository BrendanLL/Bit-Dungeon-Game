#include "dragon.h"
#include "player.h"
#include <iostream>
using namespace std;



Dragon::Dragon(){
	hp=150;
	atk=20;
	def=20;
	name="Dragon";
	//hostile=true;
    moved = false;
    assigned = false;
}



Dragon::~Dragon(){}



int Dragon::drop(){
    return 0;
}


void Dragon::combat(Player *player){
    player->beattack(this);
}


void Dragon::bcombat(Player *player){
    player->attack(this);
}
