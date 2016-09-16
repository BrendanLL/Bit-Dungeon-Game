#include "human.h"
#include "player.h"
#include <iostream>
using namespace std;



Human::Human(){
	hp=140;
	atk=20;
	def=20;
	name="Human";
	//hostile=true;
    moved = false;
    assigned = false;
}



Human::~Human(){}



int Human::drop(){
	return 4;
}

void Human::combat(Player *player){
    player->beattack(this);
}

void Human::bcombat(Player *player){
    player->attack(this);
}

