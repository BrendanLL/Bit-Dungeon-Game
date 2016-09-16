#ifndef DISPLAY_H
#define DISPLAY_H
#include <iostream>
#include <sstream>

class Display {
	char** theDisplay;
public:
	Display();
	~Display();
	virtual void notify(int row,int column, char ch);
	virtual void print(std::ostream &out)const;
};
#endif
