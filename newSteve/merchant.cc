#include "merchant.h"
#include "player.h"
#include <iostream>
using namespace std;



Merchant::Merchant(){
	hp=30;
	atk=70;
	def=5;
	name="Merchant";
	//hostile=false;
    moved = false;
    assigned = false;
}



Merchant::~Merchant(){}



int Merchant::drop(){
	return 4;
}


void Merchant::combat(Player *player){
    player->beattack(this);
}


void Merchant::bcombat(Player *player){
    player->attack(this);
}
