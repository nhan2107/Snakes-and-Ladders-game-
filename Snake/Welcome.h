#ifndef _WELCOME_H_
#define _WELCOME_H_
#pragma comment (lib, "winmm.lib")
using namespace std;

#include "Menu.h"

class Welcome
{
public:
	void opening();
private:
	Draw _draw;
	Sound _sound;
	Maingame _main;
};

#endif