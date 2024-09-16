#include<iostream>
#include<vector>
#include<ncurses/curses.h>
#include<filesystem>
#include<fstream>
#include<string>
#include"json.hpp"

#define rf() wrefresh(stdscr)
#define mv(x,y) wmove(stdscr,(y),(x))

#ifdef _WIN32
#include<windows.h>
#endif
using namespace std;
using namespace std::filesystem;

int main()
{
#ifdef _WIN32
    system("chcp 65001");
#endif
    initscr();
    cbreak();
    noecho();
    keypad(stdscr,TRUE);
    nodelay(stdscr,TRUE);
    for (;;)
    {
	int ch;
	if((ch=getch())!=ERR)
	{
	    // pressed something
	    switch(ch)
	    {
		case 'Q':
		    mv(0,LINES-1);
		    addstr("Do you really want to quit? Press Q again to confirm: ");
		    for(;;)
		    {
			if((ch=getch())=='Q')
			{
			    endwin();
			    return 0;
			}
			else if(ch!=ERR)
			{
			    mv(0,LINES-1);
			    addstr("Well, okay then.                       ");
			    break;
			}
		    }
		    break;
		default:
		    mv(0,LINES-1);
		    addstr("Unknown command. You typed: ");
		    addch(ch);
		    break;
	    }
	}
    }
    endwin();

    return 0;
}
