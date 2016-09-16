#ifndef MERCHANT_H
#define MERCHANT_H
#include "enemy.h"
#include <iostream>


class Player;
class Merchant : public Enemy{
   public:
       Merchant();
       ~Merchant();
       int drop();
       void combat(Player*);
       void bcombat(Player*);
};
#endif
