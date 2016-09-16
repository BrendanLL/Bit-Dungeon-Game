#include "vampire.h"

Vampire::Vampire() {
	hp = 50;
    maxhp = 99999;
	atk = 25;
	def = 25;
    name="vampire";
	gold = 0;
}


void Vampire::attack(Human* e) {
    ncombat(e);
    this->changehp(5);
}
void Vampire::attack(Dwarf* e) {
    ncombat(e);
    this->changehp(-5);
}
void Vampire::attack(Halfling* e) {
    ncombat(e);
    this->changehp(5);
}
void Vampire::attack(Elf* e) {
    ncombat(e);
    this->changehp(5);
}
void Vampire::attack(Orcs* e) {
    ncombat(e);
    this->changehp(5);
}
void Vampire::attack(Merchant* e) {
    ncombat(e);
    this->changehp(5);
}
void Vampire::attack(Dragon* e) {
    ncombat(e);
    this->changehp(5);
}
void Vampire::beattack(Human* e) {
    bncombat(e);
}
void Vampire::beattack(Dwarf* e) {
    bncombat(e);
}
void Vampire::beattack(Halfling* e) {
    bncombat(e);
}
void Vampire::beattack(Elf* e) {
    bncombat(e);
}
void Vampire::beattack(Orcs* e) {
    bncombat(e);
}
void Vampire::beattack(Merchant* e) {
    bncombat(e);
}
void Vampire::beattack(Dragon* e) {
    bncombat(e);
}
void Vampire::printdata(int i) {
	printw("Race: Vampire Gold: %d Floor: %d\n", gold, i);
	printstat();
}
