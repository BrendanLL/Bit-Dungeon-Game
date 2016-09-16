#include "halfling.h"
#include <iostream>
using namespace std;



Halfling::Halfling(){
	hp=100;
	atk=15;
	def=20;
	name="Halfling";
	hostile=true;
}



Halfling::~Halfling(){}



int Halfling::drop(){}
