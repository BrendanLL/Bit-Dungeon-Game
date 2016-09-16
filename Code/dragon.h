#ifndef DRAGON_H
#define DRAGON_H
#include "enemy.h"
#include <iostream>



class Dragon : public Enemy{
   public:
       Dragon();
       ~Dragon();
       int drop();
};
#endif
