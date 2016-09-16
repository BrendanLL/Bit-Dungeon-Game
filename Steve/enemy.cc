#include "enemy.h"
#include <iostream>
using namespace std;

Enemy::Enemy(){
	hp=0;
	atk=0;
	def=0;
	name="";
	//hostile=true;
    moved = false;
    assigned = false;
}


Enemy::~Enemy(){}


void Enemy::changehp(int value){
	hp+=value;
    if(hp<=0){
        hp=0;
    }
}

void Enemy::setmoved(bool b){
    moved = b;
}


string Enemy::getname(){
	return name;
}
