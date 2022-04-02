#ifndef _PLAYGAME_H_
#define _PLAYGAME_H_
#pragma comment (lib, "winmm.lib")
using namespace std;

#include "Maingame.h"
class Playgame
{
public:
	void newgame();
	void checkplaygame(string s);
	void playgame();
	void dicen();
	void starttime();
	void playgamewithcomputer();
	void checkwin();
	void endgame(player& playerWin, player& playerLose);
	void askwin(player& playerWin, player& playerLose);
	void save();
	void position(int numdice);
	void printRecentPosition(int x, int y, int comparedX, int comparedY, string player);
	void meetSnake(int& x, int& y, string player);
	bool isSnake(int& x, int& y);
	bool isLadder(int& x, int& y);
	void meetLadder(int& x, int& y, string player);
	void removeRecentPosition(int x, int y);
private:
	turn _t;
	Draw _draw;
	File _fi;
	player _pl1;
	player _pl2;
	Maingame _main;
	Sound _sound;
};

#endif