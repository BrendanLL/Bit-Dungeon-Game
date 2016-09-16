#ifndef WoundAtk_H
#define WoundAtk_H
#include "potion.h"
#include <iostream>


class WoundAtk : public Potion{
	int value;
	std::string type;
      public:
		  WoundAtk();
		  ~WoundAtk();
      	void effect(Player *);
      	std::string getname();
};
#endif
