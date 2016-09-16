#ifndef GOLD_H
#define GOLD_H
#include "cell.h"
#include <iostream>

#include "player.h"
class Enemy;
class Gold{
	protected:
	int num;
    Enemy* D;
	public:
    void setnum(int i){num=i;}
    int getnum(){return num;}
    virtual ~Gold(){}
        void setDragon(Enemy* d){D=d;}
        Enemy* getDragon(){return D;}
	   virtual void effect(Player*)=0;
	   virtual std::string getname()=0;
};
#endif
