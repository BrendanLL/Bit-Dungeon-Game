#ifndef MERCHANT_H
#define MERCHANT_H
#include "enemy.h"
#include <iostream>



class Merchant : public Enemy{
   public:
       Merchant();
       ~Merchant();
       int drop();
};
#endif
