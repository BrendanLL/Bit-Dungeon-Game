#include "merchanthoard.h"
#include <iostream>
using namespace std;


MerchantHoard::MerchantHoard(){
	value=4;
	num = 1;
	name = "merchant hoard";
	getable=false;
}

MerchantHoard::~MerchantHoard(){}

void MerchantHoard::effect(Player* player){
	player->changegold(value*num);
}


string MerchantHoard::getname(){
     return name;
}
