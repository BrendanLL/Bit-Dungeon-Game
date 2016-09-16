#include "elf.h"
#include "player.h"
#include <iostream>
using namespace std;



Elf::Elf(){
	hp=140;
	atk=30;
	def=10;
	name="Elf";
	//hostile=true;
    moved = false;
    assigned = false;
}



Elf::~Elf(){}


int Elf::drop(){
    return 0;
}


void Elf::combat(Player *player){
    if(player->getname()=="drow"){
        player->beattack(this);
    }
    else{
        player->beattack(this);
        player->beattack(this);
    }

}


void Elf::bcombat(Player *player){
    player->attack(this);
}
