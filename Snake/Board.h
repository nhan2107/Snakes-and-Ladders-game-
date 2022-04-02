#ifndef _BOARD_H_
#define _BOARD_H_
#pragma comment (lib, "winmm.lib")
using namespace std;

#include "Sound.h"

class Board
{
public:
	void paletteCol(int row, int col, int x, int y);
	void paletteRow(int row, int col, int x, int y);
	void colorboard(int row, int col);
private:
	Draw _draw;
};

#endif