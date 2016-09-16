#include <ncurses.h>
#include "controller.h"
#include "display.h"
#include "game.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>


using namespace std;
Controller::Controller() {
	td = new Display();
	game = new Game();
}

void Controller::notify(int row, int column, char symbol) { //call scoreboard to change
	td->notify(row, column, symbol);
}

Controller::~Controller() {
	delete game;
	delete td;
}


string transf(char c) {
	string com = "ce";
	if (c == 'w')com = "no";
	if (c == 'a')com = "we";
	if (c == 's')com = "so";
	if (c == 'd')com = "ea";
	if (c == 'q')com = "nw";
	if (c == 'e')com = "ne";
	if (c == 'z')com = "sw";
	if (c == 'c')com = "se";
	return com;
}

void cleanx() {
	for (int i = 0; i < 40;i++) {
		move(i, 0);
		printw("                                                                                 ");
		refresh();
	}
	move(0, 0);
}

void Controller::play() {

	initscr();

    srand(time(NULL));
	int c;
	string com;
	stringstream ss;
    bool includefile = false;
	game->setmap(this);
	td->print(cout);
    printw("Would you like to include a file?(y / n)\n");
	refresh();
	c = getch();
	printw("\n");
	//refresh();
    char file[30];
    istream* in;
    if(c=='y'){
		refresh();
		getstr(file);
	//	refresh();
		string files(file);
        in = new ifstream(files.c_str());
        game->setsource(in);
        //char a;
        //*in >> a;
        //cout<<"file first :" << a<<endl;
        includefile = true;
    }
	printw("Please select your charater to save the princess: (s/d/v/t/g) \n"); 
	refresh();
	c = getch();
	printw("\n");
	//refresh();
	char cc = c;
	ss << cc;
	ss >> com;
    if(includefile){
        game->startbyfile(this,com);
    }else{
        game->startgame(this, com);
    }
	cleanx();
	//printw("\nYou enter %s\n", com.c_str());
	td->print(cout);
    game->printstat();
	printw("Enter Command: (dir / u dir / f dir / r / esc)\n");refresh();


	while (1) {
		refresh();
		c = getch();
		printw("\n");
		printw("you enter %c\n",c);
		if (c == 'w' || c == 'a' || c == 's' || c == 'd' ||
			c == 'q' || c == 'e' || c == 'z' || c == 'c') {
			cleanx();
			com = transf(c);
			game->moveplayer(com);
		}
		else if(c=='u'){
			printw("direction?\n");refresh();
			c = getch();
			cleanx();
			com = transf(c);
			game->use(com);
		}
		else if (c == 'f') {
			printw("direction?\n");refresh();
			c = getch();
			cleanx();
			com = transf(c);
			game->combat(com);
		}
		else if(c == 'r'){
			refresh();
                if(includefile)delete in;
				printw("Would you want to include file?(y / n)\n");refresh();
				c = getch();
				printw("\n");
                if(c == 'y'){
					printw("file name?\n");refresh();
					getstr(file);
					string files(file);
                    in = new ifstream(files.c_str());
                    game->setsource(in);
                    includefile = true;
                    game->clearfloor();
                    game->floor=1;
                    game->setmap(this);
					cleanx();
					td->print(cout);
					printw("Please selete your charater to restart: \n");refresh();
					c = getch();
					char cc = c;
					ss << cc;
					ss >> com;
                    game->startbyfile(this,com);
					/*td->print(cout);
					game->printstat();
					refresh();*/
                }
                else{
					printw("Please selete your charater to restart: \n");
					refresh();
					c = getch();
					char cc = c;
					ss << cc;
					ss >> com;
                    game->restart(com);
                    includefile = false;
					/*td->print(cout);
					game->printstat();
					refresh();*/
					cleanx();
					printw("\nchara: %s\n",com.c_str());
                }
        }
		else if (c == 27) {
			//game->quit();
			break;
		}
        else if(c=='m'){
			printw("Socore: 10000000000000000000000\n");
			printw("You saved princess!!!! Mission complete!!!!\n");
            break;
        }
        else if(c=='n'){
            game->whoisyourdaddy();
        }
        else {
			printw("invalid input\n"); 
		}
		refresh();
        if(game->Checkend()==1){
			cleanx();
            td->print(cout);
            game->printstat();
			printw("Game over. Would you like to play again. (y/n)\n"); refresh();
			c = getch();
            if(c=='y'){
				refresh();
				if (includefile)delete in;
				printw("Would you want to include file?(y / n)\n");refresh();
				c = getch();
				refresh();
				if (c == 'y') {
					printw("file name ? \n");refresh();
					getstr(file);
					string files(file);
					in = new ifstream(files.c_str());
					game->setsource(in);
					includefile = true;
					game->clearfloor();
					game->floor = 1;
					game->setmap(this);
					cleanx();
					td->print(cout);
					printw("Please selete your charater to restart: \n");refresh();
					c = getch();
					char cc = c;
					ss << cc;
					ss >> com;
					game->startbyfile(this, com);
					/*td->print(cout);
					game->printstat();
					refresh();*/
				}
				else {
					printw("Please selete your charater to restart: \n");refresh();
					c = getch();
					char cc = c;
					ss << cc;
					ss >> com;
					game->restart(com);
					cleanx();
					td->print(cout);
					includefile = false;
					/*td->print(cout);
					game->printstat();
					refresh();*/
				}
            }
            else{
                //game->quit();
                break;
            }
            
        }else if(game->Checkend()==2){
            td->print(cout);
            game->printstat();
			printw("You win but princess is not in this catsle!!!\n");refresh();
			printw("Would you like to go to next catsle to find the princess? (y/n) :)\n");refresh();
			c = getch();
            if(c=='y'){
				if (includefile)delete in;
				printw("Would you want to include file?(y / n)\n");refresh();
				c = getch();
				if (c == 'y') {
					printw("file name?)\n");refresh();
					getstr(file);
					string files(file);
					in = new ifstream(files.c_str());
					game->setsource(in);
					includefile = true;
					game->clearfloor();
					game->floor = 1;
					game->setmap(this);
					cleanx();
					td->print(cout);
					printw("Please selete your charater to restart: \n");refresh();
					c = getch();
					char cc = c;
					ss << cc;
					ss >> com;
					game->startbyfile(this, com);
					/*td->print(cout);
					game->printstat();
					refresh();*/
					cleanx();
				}
				else {
					printw("Please selete your charater to restart:  \n");refresh();
					c = getch();
					char cc = c;
					ss << cc;
					ss >> com;
					game->restart(com);
					cleanx();
					td->print(cout);
					includefile = false;
					/*td->print(cout);
					game->printstat();
					refresh();*/
				}
            }
            else {
                //game->quit();
                break;
            }
        }
        else{
			cleanx();
            td->print(cout);
            game->printstat();
        }
		printw("Enter Command: (dir / u dir / f dir / r / esc)\n");refresh();
		refresh();
		//printw("\nchara: %s\n", com.c_str());
	}
	endwin();
    if(includefile)delete in;
}
