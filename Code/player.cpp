#include "player.h"
#include "enemy.h"
#include "potion.h"
#include <math.h>
using namespace std;

Player::Player():x(0),y(0),hp(0),atk(0), def(0), gold(0){}

Player::~Player(){}

void Player::printstat() {
	cout << "HP: " << hp << endl;
	cout << "Atk: " << atk << endl;
	cout << "Def: " << def << endl;
}

void Player::move(string com) {
	if (com == "no") { x -= 1; }
	if (com == "so") { x += 1; }
	if (com == "ea") { y += 1; }
	if (com == "we") { y -= 1; }
	if (com == "ne") { x -= 1; y += 1; }
	if (com == "nw") { x -= 1; y -= 1; }
	if (com == "se") { x += 1; y += 1; }
	if (com == "sw") { x += 1; y -= 1; }
}
void Player::ncombat(Enemy* e) {
	e->changehp(ceil((100 / (100 + e->getdef()))*atk));
	changehp(ceil((100 / (100 + def))*e->getatk()));
}

void Player::use(Potion* p) {
	p->effect(this);
}

