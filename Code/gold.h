#ifndef GOLD_H
#define GOLD_H
#include "cell.h"
#include <iostream>

#include "player.h"

class Gold{
	protected:
	int num;
	public:
	   virtual void effect(Player*)=0;
	   virtual std::string getname()=0;
};
#endif
