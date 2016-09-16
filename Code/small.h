#ifndef SMALL_H
#define SMALL_H
#include "gold.h"
#include <iostream>


class Small: public Gold{
	int value;
	bool getable;
	std::string name;
    public:
       Small();
       ~Small();
       void effect(Player*);
       std::string getname();
};
#endif
