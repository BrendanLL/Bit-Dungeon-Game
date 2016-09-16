#include "shade.h"
#include <iomanip>

Shade::Shade() {
	hp = 125;
	atk = 25;
	def = 25;
    maxhp = 125;
    name="shade";
	gold = 0;
}
void Shade::attack(Human* e) {
    ncombat(e);
}
void Shade::attack(Dwarf* e) {
    ncombat(e);
}
void Shade::attack(Halfling* e) {
    ncombat(e);
}
void Shade::attack(Elf* e) {
    ncombat(e);
}
void Shade::attack(Orcs* e) {
    ncombat(e);
}
void Shade::attack(Merchant* e) {
    ncombat(e);
}
void Shade::attack(Dragon* e) {
    ncombat(e);
}
void Shade::beattack(Human* e) {
    bncombat(e);
}
void Shade::beattack(Dwarf* e) {
    bncombat(e);
}
void Shade::beattack(Halfling* e) {
    bncombat(e);
}
void Shade::beattack(Elf* e) {
    bncombat(e);
}
void Shade::beattack(Orcs* e) {
    bncombat(e);
}
void Shade::beattack(Merchant* e) {
    bncombat(e);
}
void Shade::beattack(Dragon* e) {
    bncombat(e);
}
void Shade::printdata(int i) {
    cout <<"Race: Shade Gold: "<<gold<<setfill(' ')<<setw(40)<<"Floor "<< i <<endl;
	printstat();
}
