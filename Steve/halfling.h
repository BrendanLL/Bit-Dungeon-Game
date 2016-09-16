#ifndef HALFLING_H
#define HALFLING_H
#include "enemy.h"
#include <iostream>


class Player;
class Halfling : public Enemy{
   public:
       Halfling();
       ~Halfling();
       int drop();
       void combat(Player*);
       void bcombat(Player*);
};
#endif
