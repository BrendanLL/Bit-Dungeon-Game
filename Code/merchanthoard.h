#ifndef MERCHANTHOARD_H
#define MERCHANTHOARD_H
#include "gold.h"
#include <iostream>


class MerchantHoard: public Gold{
	int value;
	bool getable;
	std::string name;
    public:
       MerchantHoard();
       ~MerchantHoard();
       void effect(Player*);
       std::string getname();
};
#endif
