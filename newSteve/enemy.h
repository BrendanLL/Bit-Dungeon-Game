#ifndef ENEMY_H
#define ENEMY_H
#include <iostream>


class Player;
class Enemy{
protected:
	int hp;
	int atk;
	int def;
    bool moved;
	std::string name;
	//bool hostile;
    
public:
    bool assigned;
    Enemy();
    virtual~Enemy();
    void changehp(int);
	int getdef() { return def; }
	int getatk() { return atk; }
	int gethp() { return hp; }
   // bool gethostile(){return hostile;}
   // void sethostile(){hostile=true;}
	std::string getname();
    void setmoved(bool b);
    bool getmoved(){return moved;}
	virtual int drop()=0;
    virtual void combat (Player *)=0;  //player attack
    virtual void bcombat (Player *)=0; //enemy attack
};
#endif
