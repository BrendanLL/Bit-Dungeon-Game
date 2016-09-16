#ifndef Poisonhealth_H
#define Poisonhealth_H
#include "potion.h"
#include <iostream>


class Poisonhealth : public Potion{
	int value;
	std::string type;
      public:
		  Poisonhealth();
		  ~Poisonhealth();
      	void effect(Player *);
      	std::string getname();
};
#endif
