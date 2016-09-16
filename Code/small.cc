#include "small.h"
#include <iostream>
using namespace std;


Small::Small(){
	num = 1;
	value=1;
	name = "small hoard";
	getable=true;
}

Small::~Small(){}

void Small::effect(Player* player){
	player->changegold(value*num);
}


string Small::getname(){
     return name;
}
