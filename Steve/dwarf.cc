#include "dwarf.h"
#include "player.h"
#include <iostream>
using namespace std;



Dwarf::Dwarf(){
	hp=100;
	atk=20;
	def=30;
	name="Dwarf";
	//hostile=true;
    moved = false;
    assigned = false;
}



Dwarf::~Dwarf(){}



int Dwarf::drop(){
    return 0;
}


void Dwarf::combat(Player *player){
    player->beattack(this);
}

void Dwarf::bcombat(Player *player){
    player->attack(this);
}
