#ifndef DISPLAY_H
#define DISPLAY_H
#include <iostream>
#include <sstream>

class Display {
	char** theDisplay;
public:
	Display();
	~Display();
	void notify(int row,int column, char ch);
	void print(std::ostream &out)const;
};
#endif
