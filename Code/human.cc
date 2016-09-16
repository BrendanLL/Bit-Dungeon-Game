#include "human.h"
#include <iostream>
using namespace std;



Human::Human(){
	hp=140;
	atk=20;
	def=20;
	name="Human";
	hostile=true;
}



Human::~Human(){}



int Human::drop(){
	return 4;
}
