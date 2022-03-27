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
using nlohmann::json;
using namespace std::filesystem;

// !!! RUN `chcp 65001` on windows before running this program !!!

class Map
{
    int number_of_lines;
	/* 1,2,3,4,5,6,7,8,9,10,11,13,14,15,16,17,19,s1,cp,sdjc,dxjc,  yz,  fs,  yf, 23 in all
	 * 1,2,3,4,5,6,7,8,9,10,11,13,14,15,16,17,19,26,27,1001,1002,1003,1004,1005.           */
    int number_of_stations;
    string filename;
    string faas; //File As A String
    json faaj; //File As A Json
public:
    Map(string filename)
    {
        ifstream fmapin(filename.append(".json"));
		char thisch;
        while(!fmapin.eof())
        {
            fmapin>>thisch;
			faas.append(1,thisch);
        }
		faas.erase(faas.length()-1);
        faas.append("\n");
		try
		{
			faaj=json::parse(faas);
		}
		catch(...)
		{
			cerr<<"Error while trying to parse the map file "<<filename<<".json"<<endl;
		}
	}
	string raw_contents()
	{
		return faas;
	}
};

vector<Map> maps;

int main()
{
	#ifdef _WIN32
		system("chcp 65001");
	#endif
    path map_path="map";
	Map bj("beijing");

	//yee (start)
	
	initscr();
	cbreak();
	noecho();
	keypad(stdscr,TRUE);
	nodelay(stdscr,TRUE);
	mv(0,(LINES-7)/2-1);
	for(int _=0;_<COLS;_++)
	{
		addch('=');
	}
	mv(0,(LINES-7)/2+1);
	for(int _=0;_<COLS;_++)
	{
		addch('=');
	}
    for (;;)
	{
		int ch;
		if((ch=getch())==ERR)
		{
			// didn't respond, this part of code is not yet ready
		}
		else
		{
			// pressed something
			switch(ch)
			{
				case KEY_UP:case KEY_DOWN:case KEY_LEFT:case KEY_RIGHT:
					mv(0,LINES-7);
					addstr("Sorry, the game currently does not support "
						"\narrow keys. Use hjkl and yubn instead:\n"
						"y k u\n"
						" \\|/ \n"
						"h-@-l\n"
						" /|\\\n"
						"b j n\n");
					rf();
					break;
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

	//yee (end)
    
	return 0;
}
