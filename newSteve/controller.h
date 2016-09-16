#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <iostream>
#include "game.h"
#include "display.h"

class Display;
class Game;

class Controller {
	Display *td;
	Game *game;

public:
	Controller();
	~Controller();
	void play();
	void notify(int row, int column, char state);
};


#endif 
