#ifndef DWARF_H
#define DWARF_H
#include "enemy.h"
#include <iostream>


class Player;
class Dwarf : public Enemy{
   public:
       Dwarf();
       ~Dwarf();
       int drop();
       void combat(Player*);
       void bcombat(Player*);
};
#endif
