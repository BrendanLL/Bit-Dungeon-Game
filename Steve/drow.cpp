#include "drow.h"

Drow::Drow() {
	hp = 150;
	atk = 25;
	def = 15;
    maxhp = 150;
	gold = 0;
    name="drow";
}


void Drow::attack(Human* e) {
	ncombat(e);
}
void Drow::attack(Dwarf* e) {
	ncombat(e);
}
void Drow::attack(Halfling* e) {
	ncombat(e);
}
void Drow::attack(Elf* e) {
	ncombat(e);
}
void Drow::attack(Orcs* e) {
	ncombat(e);
}
void Drow::attack(Merchant* e) {
	ncombat(e);
}
void Drow::attack(Dragon* e) {
	ncombat(e);
}
void Drow::beattack(Human* e) {
    bncombat(e);
}
void Drow::beattack(Dwarf* e) {
    bncombat(e);
}
void Drow::beattack(Halfling* e) {
    bncombat(e);
}
void Drow::beattack(Elf* e) {
    bncombat(e);
}
void Drow::beattack(Orcs* e) {
    bncombat(e);
}
void Drow::beattack(Merchant* e) {
    bncombat(e);
}
void Drow::beattack(Dragon* e) {
    bncombat(e);
}
void Drow::printdata(int i) {
	printw("Race: Drow Gold: %d Floor: %d\n", gold, i);
	printstat();
}
