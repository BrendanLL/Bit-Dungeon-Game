#include <ncurses.h>
#include "game.h"
#include "merchanthoard.h"
#include "potion.h"
#include "normal.h"
#include "enemy.h"
#include "gold.h"
#include "factory.h"
#include "dragon.h"
#include "player.h"
#include "cell.h"
#include "controller.h"
#include <sstream>
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

//static int roundd = 0; //round 0 stand for player round, 1 for enermy round

Game::Game() {
	floor = 1;
	theGrid = NULL;
	for (int i=0;i < 6;i++)usedpotion[i] = 0; // ab 0, db 1,
	notification = NULL;
	player = NULL;
	f = new Factory();
}

Game::~Game() {
    clearfloor();
    delete player;
    delete f;
}

int Game::Checkend(){
    if(player->gethp()<=0){
        return 1;
    }else if(floor>5){
        return 2;
    }else{
        return 3;
    }
}

void Game::clearfloor() {	
	for (int i = 0;i < 25;i++) {
		delete []theGrid[i];
     }
    delete[]theGrid;
}

void Game::setmap(Controller * notification) {
    this->notification=notification;
	theGrid = new Cell*[25];
	for (int i = 0;i < 25;i++) {
		theGrid[i] = new Cell[79];
	}
	fstream ss("q5map.txt", fstream::in);
	char m;
	for (int i = 0;i < 25;i++) {
		for (int j = 0; j < 79;j++) {					
			ss >> noskipws >> m;
            if (m == '\n') {j=0; ss >> noskipws >> m; }
            theGrid[i][j].setGame(this);
            theGrid[i][j].setCoords(i, j);
			theGrid[i][j].setState(m); // error
		}
	}
}

	

int* Game::getemptylocation(int room) {
	int x, y;
	if (room == 0) {             //if it's in the chamber 1 choose an available postion
		x = rand() % 6 + 3;
		y = rand() % 27 + 3;
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
	else if (room == 3) {            //if it's in the chamber 4 choose an available position
        while(1){
            x = rand() % 9 + 3;
            y = rand() % 37 + 39;
            if(y < 60){
                if(x<8)break;
                continue;
            }
            else{
                break;
            }
        }
		while (theGrid[x][y].getchar() != '.') {
            while(1){
                x = rand() % 9 + 3;
                y = rand() % 37 + 39;
                if(y < 60){
                    if(x<8)break;
                    continue;
                }
                else{
                    break;
                }
            }
		}
	}
	else{            //if it's in the chamber 5 choose an available position
		x = rand() % 6 + 16;
		y = rand() % 38 + 37;
		while (theGrid[x][y].getchar() != '.') {
			x = rand() % 6 + 16;
			y = rand() % 38 + 37;
		}
	}int* pos = new int[2];
	pos[0] = x; pos[1] = y;
	return pos;
}

void Game::startbyfile(Controller* notification, string com){
    char dot;
    Enemy* ene;
    Potion* pot;
    Gold* gold;
    delete player;
    player = f->CreatePlayer(com);
    this->notification = notification;
    //int count =0 ;
    for (int i = 0;i < 25;i++) {
        for (int j = 0; j < 79;j++) {
            *source >> noskipws >>dot;
            //count++;
            if(dot=='\n'){*source>>dot;}
            if(dot=='0'){
                pot =  f->CreatePotion(3);  //RH
                theGrid[i][j].setpotion(pot);
                theGrid[i][j].setState('P');
            }
            else if(dot=='1'){
                pot =  f->CreatePotion(0); //BA
                theGrid[i][j].setpotion(pot);
                theGrid[i][j].setState('P');
            }
            else if(dot=='2'){
                pot =  f->CreatePotion(1);//BD
                theGrid[i][j].setpotion(pot);
                theGrid[i][j].setState('P');
            }
            else if(dot=='3'){
                pot =  f->CreatePotion(2);//PH
                theGrid[i][j].setpotion(pot);
                theGrid[i][j].setState('P');
            }
            else if(dot=='4'){
                pot =  f->CreatePotion(4);//WA
                theGrid[i][j].setpotion(pot);
                theGrid[i][j].setState('P');
            }
            else if(dot=='5'){
                pot =  f->CreatePotion(5);//WD
                theGrid[i][j].setpotion(pot);
                theGrid[i][j].setState('P');
            }
            else if(dot=='6'){
                gold =  f->CreateGold(0);
                theGrid[i][j].setgold(gold);
                theGrid[i][j].setState('G');
            }
            else if(dot=='7'){
                gold =  f->CreateGold(1);
                theGrid[i][j].setgold(gold);
                theGrid[i][j].setState('G');
            }
            else if(dot=='8'){
                gold =  f->CreateGold(2);
                theGrid[i][j].setgold(gold);
                theGrid[i][j].setState('G');
            }
            else if(dot=='9'){ //dragonhorad
                gold =  f->CreateGold(4);
                theGrid[i][j].setgold(gold);
                theGrid[i][j].setState('G');
                for(int a=-1; a<2;a++){
                    for(int b = -1;b<2;b++){
                        if(theGrid[i+a][j+b].getchar()=='D' && !theGrid[i+a][j+b].callenemy()->assigned){
                            gold->setDragon(theGrid[i+a][j+b].callenemy());
                            theGrid[i+a][j+b].callenemy()->assigned = true;
                        }
                    }
                }
            }
            
            else if(dot=='D'){  //dragon
                ene =  f->CreateEnemy(6);
                theGrid[i][j].setenemy(ene);
                theGrid[i][j].setState('D');
                for(int a=-1; a<2;a++){
                    for(int b = -1;b<2;b++){
                        if(theGrid[i+a][j+b].getchar()=='G' &&
                           theGrid[i+a][j+b].callgold()->getname()=="dragon hoard" &&
                           theGrid[i+a][j+b].callgold()->getDragon()==NULL){
                            ene->assigned=true;
                            theGrid[i+a][j+b].callgold()->setDragon(ene);
                            break;
                        }
                    }
                }
            }
            else if(dot=='O'){
                ene =  f->CreateEnemy(5);
                theGrid[i][j].setenemy(ene);
                theGrid[i][j].setState('O');
            }
            else if(dot=='E'){
                ene =  f->CreateEnemy(4);
                theGrid[i][j].setenemy(ene);
                theGrid[i][j].setState('E');
            }
            else if(dot=='L'){
                ene =  f->CreateEnemy(3);
                theGrid[i][j].setenemy(ene);
                theGrid[i][j].setState('L');
            }
            else if(dot=='W'){
                ene =  f->CreateEnemy(2);
                theGrid[i][j].setenemy(ene);
                theGrid[i][j].setState('W');
            }
            else if(dot=='H'){
                ene =  f->CreateEnemy(1);
                theGrid[i][j].setenemy(ene);
                theGrid[i][j].setState('H');
            }
            else if(dot=='M'){
                ene =  f->CreateEnemy(7);
                theGrid[i][j].setenemy(ene);
                theGrid[i][j].setState('M');
            }else if(dot=='@'){
                theGrid[i][j].setState('@');
                player->setx(i);
                player->sety(j);
            }else if(dot=='\\'){
                theGrid[i][j].setState('\\');
            }
        }
    }
}


void Game::startgame(Controller* notification, string com) {
	this->notification = notification;
	int proom = rand() % 5;//stand for the chamber the player in 
	int sroom = rand() % 5;//stand for the chamber the stairway in 

	while (proom == sroom) {
		sroom = rand() % 5;
	}//to avoid player and stairway in the same chamber

	//set player
    delete player;
	int* playerpos = getemptylocation(proom);
	player = f->CreatePlayer(com);
	player->setx(playerpos[0]);
	player->sety(playerpos[1]);
	theGrid[playerpos[0]][playerpos[1]].setState('@');
	delete[]playerpos;
    player->addmsg("You are spwaned. ");
	//set stair
	int* stairpos = getemptylocation(sroom);
	theGrid[stairpos[0]][stairpos[1]].setState('\\');
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
	//int type = rand() % 8;
	Gold* g = f->CreateGold();
	int room = rand() % 5;
	int* pos = getemptylocation(room);
    int x1=0;
    int y1=0;
	//check gold and create drogon ...
    //cout<<g->getname()<<endl;
    if (g->getname()=="dragon hoard"){
      //  cout<<"Dragon!!!!!!!"<<endl;
        while(x1==0 and y1==0){
            x1 = rand()%3-1;
            y1 = rand()%3-1;
        }
        for(;;){
            if(theGrid[pos[0]+x1][pos[1]+y1].getchar()=='.')break;
            x1 = rand()%3-1;
            y1 = rand()%3-1;
        }
        Enemy * D =new Dragon();
        g->setDragon(D);
        theGrid[pos[0]+x1][pos[1]+y1].setenemy(D);
    }
    theGrid[pos[0]][pos[1]].setgold(g);
	delete[]pos;
}

void Game::setpotion() {
	//int type = rand() % 6;
	Potion* p = f->CreatePotion();
	int room = rand() % 5;
	int* pos = getemptylocation(room);
	theGrid[pos[0]][pos[1]].setpotion(p);
	delete[]pos;
}

void Game::setenemy() {
	int room = rand() % 5;;
	//int type =rand() % 18;;
	Enemy* e = f->CreateEnemy();
	int* pos = getemptylocation(room);
	theGrid[pos[0]][pos[1]].setenemy(e); //set object and change symbol
	delete[]pos;
}

void Game::restart(string chara) {
    clearfloor();
    floor=1;
    setmap(notification);
	startgame(notification,chara);
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
		(s == theGrid[x + 1][y - 1].getchar()) || (s == theGrid[x + 1][y + 1].getchar())) {
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
    //cout << "call move"<<endl;
    int x = player->getx();
    int y = player->gety();
    Cell* target= getcell(x, y, com);
    if (!target->playerwalkable()) {
        player->addmsg("This is not a valid move");
        return;
    }
    player->move(com);
    
    //check  gold on target
    if (target->getchar() == 'G') {
        Gold* G =target->callgold();
        string num; ostringstream ss;
        ss << G->getnum();
        num = ss.str();
        if(G->getDragon()!=NULL){
            if(G->getDragon()->gethp()<=0){
                delete G->getDragon();
                G->setDragon(NULL);
                player->addmsg("You found the " + G->getname() + "x" + num + ". ");
                G->effect(player);
                delete G;
                target->removeobj();
                target->setState('.');
                target->setState('.');
            }else{
                player->addmsg("You found a " + G->getname() + " with a Dragon. Kill him and get gold! ");
            }
        }else{
            player->addmsg("You found the " + G->getname() + "x" + num + ". ");
            G->effect(player);
            delete G;
            target->removeobj();
            target->setState('.');
            target->setState('.');
        }
    }
    //check stair
    if (target->getchar() == '\\') {
        floor++;
        if(floor>5)return;
        int hp = player->gethp();
        int gold = player->getgold();
        bool ht = player->hostile;
        char name = player->getname()[0];
        string sname;
        stringstream ss;
        ss<<name;
        ss>>sname;
        clearfloor();
        setmap(notification);
        if(includeornot==false){
            startgame(notification, sname);
        }else{
            startbyfile(notification, sname);
        }
        player->changehp(hp-player->gethp());
        player->changegold(gold);
        player->cleanmsg();
        player->hostile = ht;
        player->addmsg("You move to " + com + " and go to next floor. ");
        return;
    }
    //check sounding potion and drogon hoard
    int newx = player->getx();
    int newy = player->gety();
    //int ccount = 0;
    for(int i = -1; i<2;i++){
            for(int j = -1; j<2;j++){
                if(check(newx,newy,'P')){
                    if(theGrid[newx+i][newy+j].callpotion()!=NULL){
                        string posname =theGrid[newx+i][newy+j].callpotion()->getname();
                        if((posname=="Restore Health" and usedpotion[0]==1)||
                           (posname=="Boost Atk" and usedpotion[1]==1)||
                           (posname=="Boost Def" and usedpotion[2]==1)||
                           (posname=="Poison health" and usedpotion[3]==1)||
                           (posname=="Wound Atk" and usedpotion[4]==1)||
                           (posname=="Wound Def" and usedpotion[5]==1)){
                            player->addmsg("You fonud a "+ posname + " potion. ");
                        }else{
                            player->addmsg("You fonud a unknown potion. ");
                        }
                    }
                }if(theGrid[newx+i][newy+j].callgold()!=NULL and theGrid[newx+i][newy+j].callgold()->getname()=="dragon hoard" and theGrid[newx+i][newy+j].callgold()->getDragon()->gethp()>0){
                    player->addmsg("The Dragon found you!!! ");
                    theGrid[newx+i][newy+j].callgold()->getDragon()->combat(player);
                    theGrid[newx+i][newy+j].callgold()->getDragon()->setmoved(true);
                }
                
        }
    }
    
    
    target->setState(theGrid[x][y].getchar());
    theGrid[x][y].setState(theGrid[x][y].getpre());
    moveenemy();
}

void Game::use(string com) {
	int x = player->getx();
	int y = player->gety();
	char target = getchar(x, y, com);
	if (target == 'P') {
        Potion * p = getcell(x, y, com)->callpotion();
		player->use(p);
        if(p->getname()=="Restore Health")usedpotion[0]=1;
        if(p->getname()=="Boost Atk")usedpotion[1]=1;
        if(p->getname()=="Boost Def")usedpotion[2]=1;
        if(p->getname()=="Poison health")usedpotion[3]=1;
        if(p->getname()=="Wound Atk")usedpotion[4]=1;
        if(p->getname()=="Wound Def")usedpotion[5]=1;
        delete p;
        getcell(x, y, com)->removeobj();
        getcell(x, y, com)->setState('.');
        getcell(x, y, com)->setState('.');
    }else{
        player->addmsg("There is no Potion ");
    }
    moveenemy();
}

void Game::combat(string com) {
	int x = player->getx();
	int y = player->gety();
    Cell* t =getcell(x, y, com);
	char target = t->getchar();
	if (target == 'H' || target == 'W' || target == 'E' ||target == 'O' || 
		target == 'M' || target == 'D' ||target == 'L') {
		Enemy* enemy = t->callenemy();
        enemy->bcombat(player);
        if(enemy->gethp()<=0){
            if(enemy->getname()=="Merchant"){
                delete enemy;
                t->removeobj();
                t->setgold(new MerchantHoard);
                t->setState('G');
            }
            else if(enemy->getname()=="Human"){
                delete enemy;
                t->removeobj();
                Gold * g = new Normal();
                g->setnum(2);
                t->setgold(g);
                t->setState('G');
            }else if(enemy->getname()=="Dragon"){
                t->removeobj();
                t->setState('.');
            }else{
                delete enemy;
                t->removeobj();
                t->setState('.');
            }
        }
        moveenemy();
	}
	else {
		player->addmsg("There is no enemy. ");
	}
}

Cell* Game::getcell(int x, int y,string com = "ce") {
    if (com == "no") { x -= 1; }
    if (com == "so") { x += 1; }
    if (com == "ea") { y += 1; }
    if (com == "we") { y -= 1; }
    if (com == "ne") { x -= 1; y += 1; }
    if (com == "nw") { x -= 1; y -= 1; }
    if (com == "se") { x += 1; y += 1; }
    if (com == "sw") { x += 1; y -= 1; }
	return &theGrid[x][y];
}


void Game::notify(int x, int y, char state) {
	notification->notify(x, y, state);
}
void Game::printstat() {
    
    if(Checkend()==1){
        player->addmsg("You are dead. ");
        player->printdata(this->floor);
        cout<<"Score: "<<player->getgold()<<endl;
    }else if(Checkend()==1){
        player->printdata(this->floor);
        cout<<"Score: "<<player->getgold()<<endl;
    }
    else{
        player->printdata(this->floor);
    }
}

void Game::moveenemy() {
   // int count = 0;
	for (int i = 0;i < 25;i++) {
		for (int j = 0;j < 79;j++) {
            Enemy* e = theGrid[i][j].callenemy();
			if ((e != NULL) && e->getmoved()==false) {
				if (check(i, j, '@')) {
                    if(theGrid[i][j].getchar()=='M'){
                        if(player->hostile){
                            theGrid[i][j].callenemy()->combat(player);
                        }
                    }
                    else{
                        theGrid[i][j].callenemy()->combat(player);
                    }
				}
				else if(theGrid[i][j].getchar()!='D'){
					string com = "ce";
					while (1) {						
						int dir = rand() % 8;
						if (dir == 0)  com = "no";
						if (dir == 1)  com = "so";
						if (dir == 2)  com = "ea";
						if (dir == 3)  com = "we";
						if (dir == 4)  com = "ne";
						if (dir == 5)  com = "nw";
                        if (dir == 6)  com = "se";
						if (dir == 7)  com = "sw";
                        //cout << "the " << theGrid[i][j].callenemy()->getname() << " move: "<< com << " ";
                        if (getchar(i, j, com) == '.'){e->setmoved(true); break;}
                        //cout<<"fail"<<endl;
					}
					theGrid[i][j].move(com);
                }
			}
		}
	}
    for (int i = 0;i < 25;i++) {
        for (int j = 0;j < 79;j++) {
            Enemy* e = theGrid[i][j].callenemy();
            if ((e != NULL)) e->setmoved(false);
        }
    }
}

void Game::whoisyourdaddy(){
    player->changehp(1000);
    player->changedef(1000);
    player->changeatk(1000);
}
