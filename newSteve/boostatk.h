#ifndef BOOSTATK_H
#define BOOSTATK_H
#include "potion.h"
#include <iostream>


class BoostAtk : public Potion{
	int value;
	std::string type;
      public:
		  BoostAtk();
		  ~BoostAtk();
      	void effect(Player *);
      	std::string getname();
};
#endif
