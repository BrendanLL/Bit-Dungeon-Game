#include "halfling.h"
#include "player.h"
#include <iostream>
using namespace std;
#include <cstdlib>


Halfling::Halfling(){
	hp=100;
	atk=15;
	def=20;
	name="Halfling";
	//hostile=true;
    moved = false;
    assigned = false;
}



Halfling::~Halfling(){}



int Halfling::drop(){
    return 0;
}


void Halfling::combat(Player *player){
         player->beattack(this);
}


void Halfling::bcombat(Player *player){
    int hit = rand()%2;
    if(hit==1){
        player->attack(this);
    }else{
        player->addmsg("You miss the attack. ");
    }
}
