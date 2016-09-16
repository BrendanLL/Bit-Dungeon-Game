#ifndef RESTOREHEALTH_H
#define RESTOREHEALTH_H
#include "potion.h"
#include <iostream>


class Restorehealth : public Potion{
	int value;
	std::string type;
      public:
		  Restorehealth();
		  ~Restorehealth();
      	void effect(Player *);
      	std::string getname();
};
#endif
