#include <iostream>
#include <cstdlib>
#include "potion.h"
#include "factory.h"
#include "boostatk.h"
#include "boostdef.h"
#include "poisonhealth.h"
#include "woundatk.h"
#include "wounddef.h"
#include "restorehealth.h"
#include "shade.h"
#include "drow.h"
#include "troll.h"
#include "vampire.h"
#include "goblin.h"
#include "normal.h"
#include "small.h"
#include "dragonhoard.h"
#include "merchanthoard.h"

Player* Factory::CreatePlayer(std::string com) {
	Player* e; //s, d, v, g, t:
	if (com == "d") {
		e = new Drow();
	}
	else if (com == "v") {
		e = new Vampire();
	}
	else if (com == "g") {
		e = new Goblin();
	}
	else if (com == "t") {
		e = new Troll();
	}
	else {
		e = new Shade();
	}
	return e;
}


Enemy* Factory::CreateEnemy() {
	int type = rand() % 18;
	Enemy* e;
	if (type <= 3) {
		e = new Human();
	}else if (type <= 6) {
		e = new Dwarf();
	}else if (type <= 11) {
		e = new Halfling();
	}else if (type <= 13) {
		e = new Elf();
	}else if (type <= 15) {
		e = new Orcs();
	}else {
		e = new Merchant();
	}
	return e;
}

Potion* Factory::CreatePotion() {
	int type = rand() % 6;
	Potion* p;
	if (type == 0) {
		p = new BoostAtk();
	}
	else if (type == 1) {
		p = new BoostDef;
	}
	else if (type == 2) {
		p = new Poisonhealth();
	}
	else if (type == 3) {
		p = new Restorehealth();
	}
	else if (type == 4) {
		p = new WoundAtk();
	}
	else {
		p = new WoundDef();
	}
	return p;
}

Gold* Factory::CreateGold() {
	int type = rand() % 8;
	Gold* g;
	if (type <= 4) {
		g = new Normal();
	}
	else if (type <= 6) {
		g = new Small();
	}
	else {
		g = new DragonHoard();
	}
	return g;
}

Factory::~Factory() {}


