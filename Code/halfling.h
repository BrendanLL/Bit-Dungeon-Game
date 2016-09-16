#ifndef HALFLING_H
#define HALFLING_H
#include "enemy.h"
#include <iostream>



class Halfling : public Enemy{
   public:
       Halfling();
       ~Halfling();
       int drop();
};
#endif
