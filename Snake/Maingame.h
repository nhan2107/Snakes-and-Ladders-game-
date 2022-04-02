#ifndef _MAINGAME_H_
#define _MAINGAME_H_
#pragma comment (lib, "winmm.lib")
using namespace std;

#include "File.h"
class Maingame
{
public:
	int dice(int min, int max);
	void main(string s);
private:
	turn _t;
	Draw _draw;
	Snakes _snake;
	Ladders _ladder;
	Board _board;
	File _fo;
	player _pl1;
	player _pl2;
};
#endif