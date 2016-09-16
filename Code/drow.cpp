#include "drow.h"

Drow::Drow() {
	hp = 150;
	atk = 25;
	def = 15;
	gold = 0;
}


void Drow::combat(Human* e) {
	ncombat(e);
}
void Drow::combat(Dwarf* e) {
	ncombat(e);
}
void Drow::combat(Halfling* e) {
	ncombat(e);
}
void Drow::combat(Elf* e) {
	ncombat(e);
}
void Drow::combat(Orcs* e) {
	ncombat(e);
}
void Drow::combat(Merchant* e) {
	ncombat(e);
}
void Drow::combat(Dragon* e) {
	ncombat(e);
}
void Drow::printdata(int i) {
	cout << endl;
	printstat();
}
