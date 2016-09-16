#include "goblin.h"
#include "math.h"
#include <sstream>
#include <cstdlib>
Goblin::Goblin() {
	hp = 110;
	atk = 15;
	def = 20;
    maxhp = 110;
    name="goblin";
	gold = 0;
}

void Goblin::attack(Human* e) {
    ncombat(e);
}
void Goblin::attack(Dwarf* e) {
    ncombat(e);
}
void Goblin::attack(Halfling* e) {
    ncombat(e);
}
void Goblin::attack(Elf* e) {
    ncombat(e);
}
void Goblin::attack(Orcs* e) {
    ncombat(e);
}
void Goblin::attack(Merchant* e) {
    ncombat(e);
}
void Goblin::attack(Dragon* e) {
    ncombat(e);
}
void Goblin::beattack(Human* e) {
    bncombat(e);
}
void Goblin::beattack(Dwarf* e) {
    bncombat(e);
}
void Goblin::beattack(Halfling* e) {
    bncombat(e);
}
void Goblin::beattack(Elf* e) {
    bncombat(e);
}
void Goblin::beattack(Orcs* e) {
    double result2=((100.0 / (100.0 + def))*e->getatk())*1.5;
    int r2 = -ceil(result2);
    string B;ostringstream b;b<<-r2;B=b.str();
    int hit = rand()%2;
    if(hit==1){
        changehp(r2);
        action +=  e->getname() + " deals " + B + " damage to you. ";
    }else{
        //print miss
        action += e->getname() + " miss the attack. ";
    }
}
void Goblin::beattack(Merchant* e) {
    bncombat(e);
}
void Goblin::beattack(Dragon* e) {
    bncombat(e);
}
void Goblin::printdata(int i) {
	cout <<"Race: Goblin Gold: "<<gold<<"Floor "<< i <<endl;
	printstat();
}
