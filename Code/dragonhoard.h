#ifndef DRAGONHOARD_H
#define DRAGONHOARD_H
#include "gold.h"
#include <iostream>


class DragonHoard: public Gold{
	int value;
	bool getable;
	std::string name;
    public:
       DragonHoard();
       ~DragonHoard();
       void effect(Player*);
       std::string getname();
};
#endif
