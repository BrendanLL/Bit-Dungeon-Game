#ifndef ORCF_H
#define ORCF_H
#include "enemy.h"
#include <iostream>



class Orcs : public Enemy{
   public:
       Orcs();
       ~Orcs();
       int drop();
};
#endif
