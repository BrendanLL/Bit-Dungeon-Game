#ifndef ELF_H
#define ELF_H
#include "enemy.h"
#include <iostream>



class Elf : public Enemy{
   public:
       Elf();
       ~Elf();
       int drop();
};
#endif
