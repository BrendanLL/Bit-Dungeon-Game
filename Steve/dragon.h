#ifndef DRAGON_H
#define DRAGON_H
#include "enemy.h"
#include <iostream>


class Player;
class Dragon : public Enemy{
   public:
       Dragon();
       ~Dragon();
       int drop();
       void combat(Player*);
       void bcombat (Player *);
};
#endif
