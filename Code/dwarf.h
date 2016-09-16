#ifndef DWARF_H
#define DWARF_H
#include "enemy.h"
#include <iostream>



class Dwarf : public Enemy{
   public:
       Dwarf();
       ~Dwarf();
       int drop();
};
#endif
