#ifndef _MENU_H_
#define _MENU_H_
#pragma comment (lib, "winmm.lib")
using namespace std;

#include "Playgame.h"

class Menu
{
public:
	void menu();
	void menulist();
	void resume();
	void asknewgame();
	void load();
	void infor();
	void howtoplay1();
	void howtoplay2();
private:
	Sound _sound;
	Draw _draw;
	File _fo;
	Playgame _play;
	Maingame _main;
};

#endif
