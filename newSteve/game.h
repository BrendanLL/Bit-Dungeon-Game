#ifndef GAME_H
#define GAME_H
#include <iostream>

class Controller;
class Cell;
class Player;
class Factory;
using namespace std;

const int Row = 25;
class Game {
	
	Cell** theGrid;
	Controller * notification;
	Player* player;
	Factory* f;
	int usedpotion[6]; //check a potion is used or not
    istream *source;
    bool includeornot;
	
public:
    int floor;
	Game();
	~Game();
    int Checkend();
    void clearfloor(); //Free the grid and replace the object
    void startbyfile(Controller* notification,string com);
	void startgame(Controller* notification,string com); // place the map in the cell
	void setplayer(Player* p) { player = p; }
	void setmap(Controller*); //create a empty map
	void setgold(); //create a treasure
	void setpotion();//create a potion
	void setenemy();//create a enemy
	Cell* getcell(int x, int y,string com);//return the cell
	char getchar(int x, int y, string com);//retrun the target cell symbol
	bool check(int x, int y, char state);
	int* getemptylocation(int room);//find empty space in the map to place object
	void restart(string);
	void moveplayer(string com); //call player move and change the cell
	void use(string com);
	void combat(string com);
	void remove(int x, int y);
	void notify(int x, int y, char state);
	void printstat();
	void moveenemy(); //move enemy and combat
    void whoisyourdaddy();
    void setsource(istream *in){source = in; includeornot=true;}
};

#endif
