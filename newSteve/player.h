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
    int maxhp;
    string name;
	int atk;
	int def;
	int gold;
    string action;
	
public:
    bool hostile;
	Player();
	virtual ~Player();
	void ncombat(Enemy* e);
    void bncombat(Enemy* e);
    void addmsg(string);
    void cleanmsg(){action="Action: ";}
	virtual void attack(Human* e)= 0;
	virtual void attack(Dwarf* e)=0;
	virtual void attack(Halfling* e) =0;
	virtual void attack(Elf* e)=0;
	virtual void attack(Orcs* e)=0;
	virtual void attack(Merchant* e)=0;
	virtual void attack(Dragon* e)=0;
	virtual void printdata(int i)= 0;
    virtual void beattack(Human* e)= 0;
    virtual void beattack(Dwarf* e)=0;
    virtual void beattack(Halfling* e) =0;
    virtual void beattack(Elf* e)=0;
    virtual void beattack(Orcs* e)=0;
    virtual void beattack(Merchant* e)=0;
    virtual void beattack(Dragon* e)=0;
    //virtual void printdata(int i)= 0;
	void printstat();
	void setx(int i) { x = i; }
	void sety(int i) { y = i; }
	int getx() { return x; }
	int gety() { return y; }
	int getdef() { return def; }
	int getatk() { return atk; }
	int gethp() { return hp; }
    int getgold(){return gold;}
    string getname(){return name;}
	void move(std::string com);
	void use(Potion*);
    void changegold(int value);
	void changehp(int value) {
		hp += value;
        if(hp<=0){
            hp=0;
        }
        if(hp>=maxhp){
            hp=maxhp;
        }
	}
	void changeatk(int value) {
		atk += value;
        if(atk<=0){
            atk=0;
        }
	}
	void changedef(int value) {
		def += value;
        if(def<=0){
            def=0;
        }
	}
};


#endif 
