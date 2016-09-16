#include "game.h"
#include "factory.h"
#include "player.h"
#include "cell.h"
#include "controller.h"
#include <sstream>
#include <fstream>
#include <iostream>
#include <cstdlib>
using namespace std;

Game::Game(Controller * C) {
	floor = 1;
	theGrid = NULL;
	for (int i=0;i < 6;i++)usedpotion[i] = 0;
	notification = C;
	player = NULL;
	f = new Factory();
}

Game::~Game() {
	for (int i = 0; i < Row;i++) {
		delete[]theGrid[i];
	}
	delete notification;
	delete f;
}

void Game::clearfloor() {	
	for (int i = 0;i < 25;i++) {
		delete[]theGrid[i];
     }
}

void Game::setmap() {
	theGrid = new Cell*[25];
	for (int i = 0;i < 25;i++) {
		theGrid[i] = new Cell[79];
	}
	fstream ss("q5map.txt", fstream::in);
	char m;
	for (int i = 0;i < 25;i++) {
		for (int j = 0; j < 79;j++) {					
			ss >> noskipws >> m;
			//std::cout << m;
			if (m == '\n') { continue; }
			//std::cout << "Check Point1 " << endl;
			theGrid[i][j].setGame(this);
			theGrid[i][j].setCoords(i, j);
			theGrid[i][j].setState(m);
		}
	}
}

	

int* Game::getemptylocation(int room) {
	int x, y;
	if (room == 0) {             //if it's in the chamber 1 choose an available postion
		x = rand() % 6 + 2;
		y = rand() % 28 + 2;
		while (theGrid[x][y].getchar() != '.') {
			x = rand() % 6 + 2;
			y = rand() % 28 + 2;
		}
	}
	else if (room == 1) {            //if it's in the chamber 2 choose an available position
		x = rand() % 9 + 14;
		y = rand() % 23 + 3;
		while (theGrid[x][y].getchar() != '.') {
			x = rand() % 9 + 14;
			y = rand() % 23 + 3;
		}
	}
	else if (room == 2) {            //if it's in the  chamber 3 choose an available postion
		x = rand() % 5 + 9;
		y = rand() % 14 + 37;
		while (theGrid[x][y].getchar() != '.') {
			x = rand() % 5 + 9;
			y = rand() % 14 + 37;
		}
	}
	else if (room == 3) {            //if it's in the chamber 5 choose an available position
		x = rand() % 6 + 2;
		y = rand() % 39 + 38;
		while (theGrid[x][y].getchar() != '.') {
			x = rand() % 6 + 2;
			y = rand() % 39 + 38;
		}
	}
	else{            //if it's in the chamber 4 choose an available position
		x = rand() % 41 + 36;
		y = rand() % 8 + 15;
		while (theGrid[x][y].getchar() != '.') {
			x = rand() % 41 + 36;
			y = rand() % 8 + 15;
		}
	}int* pos = new int[2];
	pos[0] = x; pos[1] = y;
	return pos;
}




void Game::startgame(Controller* notification, string com) {
	//clearfloor();
	floor = 1;	
	this->notification = notification;
	setmap();

	int proom = rand() % 5;//stand for the chamber the player in 
	int sroom = rand() % 5;//stand for the chamber the stairway in 

	while (proom == proom) {
		sroom = rand() % 5;
	}//to avoid player and stairway in the same chamber

	//set player
	int* playerpos = getemptylocation(proom);
	player = f->CreatePlayer(com);
	player->setx(playerpos[0]);
	player->sety(playerpos[1]);
	theGrid[playerpos[0]][playerpos[1]].setState('@');
	delete[]playerpos;

	//set stair
	int* stairpos = getemptylocation(sroom);
	theGrid[stairpos[0]][stairpos[1]].setState('/');
	delete[]stairpos;
	//set potion
	for (int i = 1;i <= 10;i++) {
		setpotion();
	}

	//set gold
	for (int i = 1;i <= 10;i++) {
		setgold();
	}

	//set enemy
	for (int i = 1;i <= 20;i++) {
		setenemy();
	}
}

void Game::setgold() {
	int type = rand() % 8;
	Gold* g = f->CreateGold();
	int room = rand() % 5;
	int* pos = getemptylocation(room);
	theGrid[pos[0]][pos[1]].setgold(g);
	
	//check gold and create drogon ...
	delete[]pos;
}

void Game::setpotion() {
	int type = rand() % 6;
	Potion* p = f->CreatePotion();
	int room = rand() % 5;
	int* pos = getemptylocation(room);
	theGrid[pos[0]][pos[1]].setpotion(p);
	delete[]pos;
}

void Game::setenemy() {
	int room = rand() % 5;;
	int type =rand() % 18;;
	Enemy* e = f->CreateEnemy();
	int* pos = getemptylocation(room);
	theGrid[pos[0]][pos[1]].setenemy(e); //set object and change symbol
	delete[]pos;
}

void Game::restart(string chara) {
	startgame(notification,chara);
}

void Game::quit() {
	clearfloor();
	delete notification;
	delete theGrid;
	delete player;
}

void Game::remove(int x,int y) {
	theGrid[x][y].removeobj();
	theGrid[x][y].setState('.');
	theGrid[x][y].setwalkable(true, true);
}

bool Game::check(int x, int y,char s) {
	if ((s == theGrid[x - 1][y].getchar()) || (s == theGrid[x][y - 1].getchar()) ||
		(s == theGrid[x + 1][y].getchar()) || (s == theGrid[x][y + 1].getchar()) ||
		(s == theGrid[x - 1][y + 1].getchar()) || (s == theGrid[x - 1] [y - 1].getchar()) ||
		(s == theGrid[x + 1][y - 1].getchar()) || (s == theGrid[x - 1][y + 1].getchar())) {
		//print????

		return true;
	}
	return false;
}

char Game::getchar(int x, int y, string com) {
	if (com == "no") { x -= 1; }
	if (com == "so") { x += 1; }
	if (com == "ea") { y += 1; }
	if (com == "we") { y -= 1; }
	if (com == "ne") { x -= 1; y += 1; }
	if (com == "nw") { x -= 1; y -= 1; }
	if (com == "se") { x += 1; y += 1; }
	if (com == "sw") { x += 1; y -= 1; }
	return theGrid[x][y].getchar();
}

void Game::moveplayer(string com) {
	int x = player->getx();
	int y = player->gety();
	char target = getchar(x, y, com);
	player->move(com);
}

void Game::use(string com) {
	int x = player->getx();
	int y = player->gety();
	char target = getchar(x, y, com);
	if (target == 'P') {
		player->use(theGrid[x][y].callpotion());
	}
}

void Game::combat(string com) {
	int x = player->getx();
	int y = player->gety();
	char target = getchar(x, y, com);
	if (target == 'H' || target == 'W' || target == 'E' ||target == 'O' || 
		target == 'M' || target == 'D' ||target == 'L') {
		Enemy* enemy = theGrid[x][y].callenemy();
	}
	else {
		cerr << "You have to attack your enermy" << endl;
	}
}

Cell* Game::getcell(int x, int y) {
	return &theGrid[x][y];
}


void Game::notify(int x, int y, char state) {
	//std::cout << "Check Point3 " << endl;
	notification->notify(x, y, state);
}
void Game::printstat() {
	player->printdata(this->floor);
}
