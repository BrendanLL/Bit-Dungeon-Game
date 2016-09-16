#ifndef POTION_H
#define POTION_H
#include "cell.h"
#include "game.h"
#include <iostream>


class Potion{
	public:
		~Potion() {}
		virtual void effect(Player *player) = 0;
		virtual std::string getname() = 0;
};
#endif
