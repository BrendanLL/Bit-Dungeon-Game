#include "normal.h"
#include <iostream>
using namespace std;


Normal::Normal(){
	value=2;
	num = 1;
	name = "normal hoard";
	getable=true;
    D = NULL;
}

Normal::~Normal(){}

void Normal::effect(Player* player){
	player->changegold(value*num);
}


string Normal::getname(){
     return name;
}
