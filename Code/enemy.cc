#include "enemy.h"
#include <iostream>
using namespace std;

Enemy::Enemy(){
	hp=0;
	atk=0;
	def=0;
	name="";
	hostile=true;
}


Enemy::~Enemy(){}


void Enemy::changehp(int value){
	hp+=value;
}


string Enemy::getname(){
	return name;
}
