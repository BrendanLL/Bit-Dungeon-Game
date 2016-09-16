#ifndef FACTORY_H
#define FACTORY_H

#include <string>
#include <iostream>

class Enemy;
class Potion;
class Gold;
class Player;
class Factory {
public:
	Player* CreatePlayer(std::string com);
	Enemy* CreateEnemy();
	Potion* CreatePotion();
	Gold* CreateGold();
    Enemy* CreateEnemy(int);
    Potion* CreatePotion(int);
    Gold* CreateGold(int);
	~Factory();
};

#endif
