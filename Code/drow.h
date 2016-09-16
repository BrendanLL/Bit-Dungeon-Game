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
	void combat(Human* h);
	void combat(Dwarf* w);
	void combat(Halfling* H);
	void combat(Elf* e);
	void combat(Orcs* o);
	void combat(Merchant* m);
	void combat(Dragon* d);
	void printdata(int i);
};
