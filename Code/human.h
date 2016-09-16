#ifndef HUMAN_H
#define HUMAN_H
#include "enemy.h"
#include <iostream>



class Human : public Enemy{
   public:
       Human();
       ~Human();
       int drop();
};
#endif
