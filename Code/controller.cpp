#include "controller.h"
#include "display.h"
#include "game.h"

using namespace std;
Controller::Controller() {
	td = new Display();
	game = new Game(this);
}

void Controller::notify(int row, int column, char symbol) { //call scoreboard to change
	td->notify(row, column, symbol);
}

Controller::~Controller() {
	delete game;
	delete td;
}


void Controller::play() {
	string com;
	game->setmap();
	td->print(cout);
	cout << "Please select your charater to save the princess: (s/d/v/t/g) " << endl;
	cin >> com;
	game->startgame(this, com);
	td->print(cout);

	while (cin >> com) {
		if (com == "no" || com == "so" || com == "ea" || com == "we" ||
			com == "ne" || com == "nw" || com == "se" || com == "sw") {
			//game->checkvalid();
			game->moveplayer(com);
		}
		else if(com=="u"){
			cin >> com;
			//game->checkvalid();
			game->use(com);
		}
		else if (com == "a") {
			cin >> com;
			//game->checkvalid();
			game->combat(com);
		}
		else if(com == "r"){
			cout << "Please selete your charater: " << endl;
			cin >> com;
			game->restart(com);
		}
		else if (com == "q") {
			game->quit();
			break;
		}
		else {
			cerr << "invalid input" << endl;
		}
		td->print(cout);
		game->printstat();
	}
}
