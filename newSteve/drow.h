#include "player.h"
#include "dragon.h"
#include "orcs.h"
#include "merchant.h"
#include "halfling.h"
#include "human.h"
#include "dwarf.h"
#include "elf.h"

class Drow :public Player {
public:
	Drow();
	~Drow(){}
	void attack(Human* h);
	void attack(Dwarf* w);
	void attack(Halfling* H);
	void attack(Elf* e);
	void attack(Orcs* o);
	void attack(Merchant* m);
	void attack(Dragon* d);
    void beattack(Human* h);
    void beattack(Dwarf* w);
    void beattack(Halfling* H);
    void beattack(Elf* e);
    void beattack(Orcs* o);
    void beattack(Merchant* m);
    void beattack(Dragon* d);
	void printdata(int i);
};
