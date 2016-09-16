#include "vampire.h"

Vampire::Vampire() {
	hp = 150;
	atk = 25;
	def = 15;
	gold = 0;
}


void Vampire::combat(Human* e) {
	ncombat(e);
}
void Vampire::combat(Dwarf* e) {
	ncombat(e);
}
void Vampire::combat(Halfling* e) {
	ncombat(e);
}
void Vampire::combat(Elf* e) {
	ncombat(e);
}
void Vampire::combat(Orcs* e) {
	ncombat(e);
}
void Vampire::combat(Merchant* e) {
	ncombat(e);
}
void Vampire::combat(Dragon* e) {
	ncombat(e);
}
void Vampire::printdata(int i) {
	cout << endl;
	printstat();
}
