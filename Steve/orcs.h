#ifndef ORCF_H
#define ORCF_H
#include "enemy.h"
#include <iostream>


class Player;
class Orcs : public Enemy{
   public:
       Orcs();
       ~Orcs();
       int drop();
       void combat(Player*);
       void bcombat(Player*);
};
#endif
