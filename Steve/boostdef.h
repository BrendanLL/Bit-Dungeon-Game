#ifndef BOOSTDEF_H
#define BOOSTDEF_H
#include "potion.h"
#include <iostream>

class Player;
class BoostDef : public Potion{
	int value;
	std::string type;
      public:
		  BoostDef();
		  ~BoostDef();
      	void effect(Player *);
      	std::string getname();
};
#endif
