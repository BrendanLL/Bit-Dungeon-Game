#include "shade.h"

Shade::Shade() {
	hp = 125;
	atk = 25;
	def = 25;
	gold = 0;
}

void Shade::combat(Human* e) {
	ncombat(e);
}
void Shade::combat(Dwarf* e) {
	ncombat(e);
}
void Shade::combat(Halfling* e) {
	ncombat(e);
}
void Shade::combat(Elf* e) {
	ncombat(e);
}
void Shade::combat(Orcs* e) {
	ncombat(e);
}
void Shade::combat(Merchant* e) {
	ncombat(e);
}
void Shade::combat(Dragon* e) {
	ncombat(e);
}
void Shade::printdata(int i) {
	cout << endl;
	printstat();
}
