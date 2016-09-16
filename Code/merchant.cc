#include "merchant.h"
#include <iostream>
using namespace std;



Merchant::Merchant(){
	hp=30;
	atk=70;
	def=5;
	name="MERCHANT";
	hostile=false;
}



Merchant::~Merchant(){}



int Merchant::drop(){
	return 4;
}
