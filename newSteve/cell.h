#ifndef CELL_H
#define CELL_H
#include <string>

class Game;
class Potion;
class Enemy;
class Gold;
const int MAXNEIGHBOURS = 8;
class Cell {
	int x, y;
	bool pwalkable, ewalkable;
	char symbol,previus;
	//Cell *neighbours[MAXNEIGHBOURS];
	Enemy* ene;
	Potion* pot;
	Gold* gold;
	Game *game;

public:
	Cell();
	//virtual void getname()=0;
	void setenemy(Enemy* obj);
	void setpotion(Potion* obj);
	void setgold(Gold* obj);
	Enemy* callenemy() { return ene; }
	Potion* callpotion() { return pot; }
	Gold* callgold() { return gold; }
	void setState(char symbol);//
	void setCoords(const int row, const int column);
	void setGame(Game * game);
	//void addNeighbour(Cell *neighbour);
	void setwalkable(bool pw, bool ew); 
	//void setmap(const int row, const int column, char symbol);
	~Cell();
	void move(std::string com); // set the data the the target location
	void removeobj(); //set obj 
	bool enermywalkable() { return ewalkable; }
	bool playerwalkable() { return pwalkable; }
	char getchar() { return symbol; } //get the char of the cell
    char getpre() { return previus; }
	void notify(); //change display

	//virtual void effect() {};
	//virtual std::string getname(){}
};

#endif
