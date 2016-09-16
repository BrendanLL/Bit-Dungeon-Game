#ifndef WOUNDDEF_H
#define WOUNDDEF_H
#include "potion.h"
#include <iostream>


class WoundDef : public Potion{
	int value;
	std::string type;
      public:
		  WoundDef();
		  ~WoundDef();
      	void effect(Player *);
      	std::string getname();
};
#endif
