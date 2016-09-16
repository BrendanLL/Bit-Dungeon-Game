#include "goblin.h"

Goblin::Goblin() {
	hp = 110;
	atk = 15;
	def = 20;
	gold = 0;
}

void Goblin::combat(Human* e) {
	ncombat(e);
}
void Goblin::combat(Dwarf* e) {
	ncombat(e);
}
void Goblin::combat(Halfling* e) {
	ncombat(e);
}
void Goblin::combat(Elf* e) {
	ncombat(e);
}
void Goblin::combat(Orcs* e) {
	ncombat(e);
}
void Goblin::combat(Merchant* e) {
	ncombat(e);
}
void Goblin::combat(Dragon* e) {
	ncombat(e);
}
void Goblin::printdata(int i) {
	cout << endl;
	printstat();
}
