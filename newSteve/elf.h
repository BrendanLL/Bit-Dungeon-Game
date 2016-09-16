#ifndef ELF_H
#define ELF_H
#include "enemy.h"
#include <iostream>


class Player;
class Elf : public Enemy{
   public:
       Elf();
       ~Elf();
       int drop();
       void combat(Player*);
       void bcombat(Player*);
};
#endif
