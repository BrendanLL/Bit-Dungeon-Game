#ifndef NORMAL_H
#define NORMAL_H
#include "gold.h"
#include <iostream>


class Normal: public Gold{
	int value;
	bool getable;
	std::string name;
    public:
       Normal();
       ~Normal();
       void effect(Player*);
       std::string getname();
};
#endif
