#ifndef _CHECK_POSITION_H_
#define _CHECK_POSITION_H_
#pragma comment (lib, "winmm.lib")
using namespace std;
#include "Maingame.h"

class CheckPosition
{
public:
	int TURN;
	int flag[2];
	int LINE[2];
	void position(int numdice);
	void printRecentPosition(int x, int y, int comparedX, int comparedY, string player);
	void meetSnake(int& x, int& y, string player);
	bool isSnake(int& x, int& y);
	bool isLadder(int& x, int& y);
	void meetLadder(int& x, int& y, string player);
	void removeRecentPosition(int x, int y);
private:
	Draw _draw;
	player _pl1;
	player _pl2;
};
#endif