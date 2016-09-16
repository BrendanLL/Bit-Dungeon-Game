#include <ncurses.h>
#include "player.h"
#include "enemy.h"
#include "potion.h"
#include <cstring>
#include <cstdlib>
#include <math.h>
#include <sstream>
using namespace std;

Player::Player():x(0),y(0),hp(0),atk(0), def(0), gold(0),action("Action: "){}

Player::~Player(){}

void Player::printstat() {
	printw("HP: %d\n",hp);
	printw("Atk: %d\n",atk);
	printw("Def: %d\n",def);
	char Act[500];
	strcpy(Act, action.c_str());
	printw("%s\n",Act);
    cleanmsg();
}

void Player::move(string com) {
	if (com == "no") { x -= 1; }
	if (com == "so") { x += 1; }
	if (com == "ea") { y += 1; }
	if (com == "we") { y -= 1; }
	if (com == "ne") { x -= 1; y += 1; }
	if (com == "nw") { x -= 1; y -= 1; }
	if (com == "se") { x += 1; y += 1; }
	if (com == "sw") { x += 1; y -= 1; }
    action += "You move to " + com + ". ";
    if(name=="troll")changehp(5);
}


void Player::ncombat(Enemy* e) {
    if(e->getname()=="Merchant")hostile=true;
    double result1=(100.0 /(100.0 + e->getdef()))*atk;
    double result2=(100.0 / (100.0 + def))*e->getatk();
    int r1 = -ceil(result1);
    int r2 = -ceil(result2);
    int golld=0;
	e->changehp(r1);
    string A,B,C;
    ostringstream a,b,c;
    a<<-r1;b<<-r2;c<<e->gethp();
    A = a.str();B = b.str();C = c.str();
    action += "You deals " + A + " damage to " + e->getname()+ "("+C+")" + ". ";
    if(e->gethp()<=0){
        if(name=="goblin")changegold(5);
        action += "You slaved the " + e->getname() + ". ";
        if(e->getname()!="Merchant" and e->getname()!="Dragon" and e->getname()!="Human"){
            golld = rand()%2+1;
            this->changegold(golld);
        }
    }
    if(name=="troll")changehp(5);
    /*else{
        
        if(hit==1){
            changehp(r2);
            action += "You deals " + A + " damage to " + e->getname()+ "("+C+")" + ". "
            + e->getname() + " deals " + B + " damage to you. ";
        }else{
            //print miss
            action += "You deals " + A + " damage to " + e->getname()+ "("+C+")" + ". "
            + e->getname() + " miss the attack. ";
        }
    }*/
}

void Player::bncombat(Enemy* e){
    double result2=(100.0 / (100.0 + def))*e->getatk();
    int r2 = -ceil(result2);
    string B;ostringstream b;b<<-r2;B=b.str();
    int hit = rand()%2;
    if(hit==1){
        changehp(r2);
        action +=  e->getname() + " deals " + B + " damage to you. ";
    }else{
        //print miss
        action += e->getname() + " miss the attack. ";
    }

}

void Player::addmsg(string s){
    action += s;
}

void Player::use(Potion* p) {
	p->effect(this);
    action += "You used " + p->getname() +". ";
    if(name=="troll")changehp(5);
}

void Player::changegold(int value){
    gold += value;
    string D;ostringstream d;
    d<<value; D = d.str();
    action += "You found " + D + " gold. ";
}

