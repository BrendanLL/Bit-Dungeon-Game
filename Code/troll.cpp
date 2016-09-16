#include "troll.h"

Troll::Troll() {
	hp = 120;
	atk = 25;
	def = 15;
	gold = 0;
}


void Troll::combat(Human* e) {
	ncombat(e);
}

void Troll::combat(Dwarf* e) {
	ncombat(e);
}

void Troll::combat(Halfling* e) {
	ncombat(e);
}

void Troll::combat(Elf* e) {
	ncombat(e);
}

void Troll::combat(Orcs* e) {
	ncombat(e);
}

void Troll::combat(Merchant* e) {
	ncombat(e);
}

void Troll::combat(Dragon* e) {
	ncombat(e);
}

void Troll::printdata(int i) {
	cout << endl;
	printstat();
}
