#include "troll.h"

Troll::Troll() {
	hp = 120;
    maxhp = 120;
	atk = 25;
	def = 15;
    name="troll";
	gold = 0;
}


void Troll::attack(Human* e) {
    ncombat(e);
}
void Troll::attack(Dwarf* e) {
    ncombat(e);
}
void Troll::attack(Halfling* e) {
    ncombat(e);
}
void Troll::attack(Elf* e) {
    ncombat(e);
}
void Troll::attack(Orcs* e) {
    ncombat(e);
}
void Troll::attack(Merchant* e) {
    ncombat(e);
}
void Troll::attack(Dragon* e) {
    ncombat(e);
}
void Troll::beattack(Human* e) {
    bncombat(e);
}
void Troll::beattack(Dwarf* e) {
    bncombat(e);
}
void Troll::beattack(Halfling* e) {
    bncombat(e);
}
void Troll::beattack(Elf* e) {
    bncombat(e);
}
void Troll::beattack(Orcs* e) {
    bncombat(e);
}
void Troll::beattack(Merchant* e) {
    bncombat(e);
}
void Troll::beattack(Dragon* e) {
    bncombat(e);
}

void Troll::printdata(int i) {
	printw("Race: Troll Gold: %d Floor: %d\n", gold, i);
	printstat();
}
