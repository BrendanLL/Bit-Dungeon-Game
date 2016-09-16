
#include <ncurses.h>			/* ncurses.h includes stdio.h */  
#include <string.h> 
 
int main()
{
  initscr();
  int c;
  printw("write somthing");
  while((c=getch())!=27){
	  printw("Keycode: %d , charater: %c",c,c);
	  move(0,0);
	  printw("write somthing (ESC to escape))");
	  refresh();
  }


 return 0;
 
}
