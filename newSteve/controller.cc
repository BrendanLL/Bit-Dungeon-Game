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


void Controller::play() {
    srand(time(NULL));
	string com;
    bool includefile = false;
	game->setmap(this);
	td->print(cout);
    cout<<"Would you like to include a file?(include \"filename\"/ else)"<<endl;
    cin>>com;
    string file ="std";
    istream* in;
    if(com=="include"){
        cin>>file;
        in = new ifstream(file.c_str());
        game->setsource(in);
        //char a;
        //*in >> a;
        //cout<<"file first :" << a<<endl;
        includefile = true;
    }
    cout << "Please select your charater to save the princess: (s/d/v/t/g) " << endl;
	cin >> com;
    if(includefile){
        game->startbyfile(this,com);
    }else{
        game->startgame(this, com);
    }
	td->print(cout);
    game->printstat();
    cout<< "Enter Command: (dir / u dir / a dir / r / q)"<<endl;
	while (cin >> com) {
		if (com == "no" || com == "so" || com == "ea" || com == "we" ||
			com == "ne" || com == "nw" || com == "se" || com == "sw") {
			game->moveplayer(com);
		}
		else if(com=="u"){
			cin >> com;
			game->use(com);
		}
		else if (com == "a") {
			cin >> com;
			game->combat(com);
		}
		else if(com == "r"){
                if(includefile)delete in;
                cout<<"Would you want to include file?(include / n)"<<endl;
                cin>>com;
                if(com=="include"){
                    cin>>file;
                    in = new ifstream(file.c_str());
                    game->setsource(in);
                    includefile = true;
                    game->clearfloor();
                    game->floor=1;
                    game->setmap(this);
                    cout << "Please selete your charater to restart: " << endl;
                    cin >> com;
                    game->startbyfile(this,com);
                }
                else{
                    cout << "Please selete your charater to restart: " << endl;
                    cin >> com;
                    game->restart(com);
                    includefile = false;
                }
        }
		else if (com == "q") {
			//game->quit();
			break;
		}
        else if(com=="lifesucks"){
            cout<<"Socore: 10000000000000000000000"<<endl;
            cout<<"You saved princess!!!! Mission complete!!!!"<<endl;
            break;
        }
        else if(com=="whoisyourdaddy"){
            game->whoisyourdaddy();
        }
        else {
			cerr << "invalid input" << endl;
		}
        if(game->Checkend()==1){
            td->print(cout);
            game->printstat();
            cout<<"Game over. Would you like to play again. (y/n)"<<endl;
            cin>>com;
            if(com=="y"){
                if(includefile)delete in;
                cout<<"Would you want to include file?(include / n)"<<endl;
                cin>>com;
                if(com=="include"){
                    cin>>file;
                    in = new ifstream(file.c_str());
                    game->setsource(in);
                    includefile = true;
                    game->clearfloor();
                    game->floor=1;
                    game->setmap(this);
                    cout << "Please selete your charater to restart: " << endl;
                    cin >> com;
                    game->startbyfile(this,com);
                }
                else{
                    cout << "Please selete your charater to restart: " << endl;
                    cin >> com;
                    game->restart(com);
                    td->print(cout);
                    game->printstat();
                    includefile = false;
                }
            }
            else {
                //game->quit();
                break;
            }
            
        }else if(game->Checkend()==2){
            td->print(cout);
            game->printstat();
            cout<<"You win but princess is not in this catsle!!!"<<endl;
            cout<<"Would you like to go to next catsle to find the princess? (y/n) :)"<<endl;
            cin >> com;
            if(com=="y"){
                if(includefile)delete in;
                cout<<"Would you want to include file?(include / n)"<<endl;
                cin>>com;
                if(com=="include"){
                    cin>>file;
                    in = new ifstream(file.c_str());
                    game->setsource(in);
                    includefile = true;
                    game->clearfloor();
                    game->floor=1;
                    game->setmap(this);
                    cout << "Please selete your charater to restart: " << endl;
                    cin >> com;
                    game->startbyfile(this,com);
                }
                else{
                    cout << "Please selete your charater to restart: " << endl;
                    cin >> com;
                    game->restart(com);
                    td->print(cout);
                    game->printstat();
                    includefile = false;
                }
            }
            else {
                //game->quit();
                break;
            }
        }
        else{
            td->print(cout);
            game->printstat();
        }
        cout<< "Enter Command: (dir / u dir / a dir / r / q)"<<endl;
	}
    if(includefile)delete in;
}
