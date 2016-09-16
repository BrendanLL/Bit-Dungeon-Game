#ifndef PLAYER_H
#define PLAYER_H
#include "game.h"

class Enemy;
class Human;
class Dwarf;
class Halfling;
class Elf;
class Orcs;
class Merchant;
class Dragon;
class Potion;

class Player{
protected:
	int x;
	int y; //localtion of player
	int hp;
	int atk;
	int def;
	int gold;
	
public:
	Player();
	~Player();
	void ncombat(Enemy* e);
	virtual void combat(Human* e)= 0;
	virtual void combat(Dwarf* e)=0;
	virtual void combat(Halfling* e) =0;
	virtual void combat(Elf* e)=0;
	virtual void combat(Orcs* e)=0;
	virtual void combat(Merchant* e)=0;
	virtual void combat(Dragon* e)=0;
	virtual void printdata(int i)= 0;
	void printstat();
	void setx(int i) { x = i; }
	void sety(int i) { y = i; }
	int getx() { return x; }
	int gety() { return y; }
	int getdef() { return def; }
	int getatk() { return atk; }
	int gethp() { return hp; }
	void move(std::string com);
	void use(Potion*);
	void changegold(int value) {
		gold += value;
	}
	void changehp(int value) {
		hp += value;
	}
	void changeatk(int value) {
		atk += value;
	}
	void changedef(int value) {
		def += value;
	}
};


#endif 
