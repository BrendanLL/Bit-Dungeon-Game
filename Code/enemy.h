#ifndef ENEMY_H
#define ENEMY_H
#include <iostream>



class Enemy{
protected:
	int hp;
	int atk;
	int def;
	std::string name;
	bool hostile;
public:
    Enemy();
    ~Enemy();
    void changehp(int);
	int getdef() { return def; }
	int getatk() { return atk; }
	int gethp() { return hp; }
	std::string getname();
	virtual int drop()=0;
};
#endif
