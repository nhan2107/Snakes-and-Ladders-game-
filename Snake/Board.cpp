#include "Board.h"

void Board::paletteCol(int row, int col, int x, int y)
{
	_draw.gotoxy(x, y);
	_draw.colorBox(12, row, col, x, y);
	_draw.gotoxy(x, y + 3);
	_draw.colorBox(10, row, col, x, y + 3);
	_draw.gotoxy(x, y + 6);
	_draw.colorBox(15, row, col, x, y + 7);
	_draw.gotoxy(x, y + 9);
	_draw.colorBox(25, row, col, x, y + 9);
	_draw.gotoxy(x, y + 12);
	_draw.colorBox(14, row, col, x, y + 12);
}
void Board::paletteRow(int row, int col, int x, int y)
{
	_draw.gotoxy(x, y);
	_draw.colorBox(10, row, col, x, y);
	_draw.gotoxy(x + 7, y);
	_draw.colorBox(14, row, col, x + 7, y);
	_draw.gotoxy(x + 14, y);
	_draw.colorBox(15, row, col, x + 14, y);
	_draw.gotoxy(x + 21, y);
	_draw.colorBox(12, row, col, x + 21, y);
	_draw.gotoxy(x + 28, y);
	_draw.colorBox(25, row, col, x + 28, y);
}
void Board::colorboard(int row, int col)
{
	paletteCol(row, col, 1, 1);
	paletteCol(row, col, 1, 16);
	paletteCol(row, col, 8, 7);
	paletteCol(row, col, 15, 13);
	paletteCol(row, col, 22, 4);
	paletteCol(row, col, 29, 10);
	paletteCol(row, col, 36, 1);
	paletteCol(row, col, 36, 16);
	paletteCol(row, col, 43, 7);
	paletteCol(row, col, 50, 13);
	paletteCol(row, col, 57, 4);
	paletteCol(row, col, 64, 10);

	paletteRow(row, col, 15, 1);
	paletteRow(row, col, 1, 4);
	paletteRow(row, col, 36, 4);
	paletteRow(row, col, 22, 7);
	paletteRow(row, col, 8, 10);
	paletteRow(row, col, 29, 13);
	paletteRow(row, col, 15, 16);
	paletteRow(row, col, 1, 19);
	paletteRow(row, col, 36, 19);
	paletteRow(row, col, 22, 22);
	paletteRow(row, col, 8, 25);
	paletteRow(row, col, 29, 28);

	//white
	_draw.gotoxy(8, 1);
	_draw.colorBox(15, row, col, 8, 1);
	_draw.gotoxy(29, 1);
	_draw.colorBox(15, row, col, 29, 1);
	_draw.gotoxy(64, 1);
	_draw.colorBox(15, row, col, 64, 1);
	_draw.gotoxy(57, 25);
	_draw.colorBox(15, row, col, 57, 25);
	_draw.gotoxy(8, 28);
	_draw.colorBox(15, row, col, 8, 28);

	//green
	_draw.gotoxy(50, 1);
	_draw.colorBox(10, row, col, 50, 1);
	_draw.gotoxy(57, 22);
	_draw.colorBox(10, row, col, 57, 22);
	_draw.gotoxy(43, 25);
	_draw.colorBox(10, row, col, 43, 25);
	_draw.gotoxy(64, 28);
	_draw.colorBox(10, row, col, 64, 28);

	//yellow
	_draw.gotoxy(57, 1);
	_draw.colorBox(14, row, col, 57, 1);
	_draw.gotoxy(64, 7);
	_draw.colorBox(14, row, col, 64, 7);
	_draw.gotoxy(50, 10);
	_draw.colorBox(14, row, col, 50, 10);


	//blue
	_draw.gotoxy(15, 7);
	_draw.colorBox(25, row, col, 15, 7);
	_draw.gotoxy(22, 28);
	_draw.colorBox(25, row, col, 22, 28);

	//red
	_draw.gotoxy(8, 22);
	_draw.colorBox(12, row, col, 8, 22);
	_draw.gotoxy(64, 25);
	_draw.colorBox(12, row, col, 64, 25);
	_draw.gotoxy(15, 28);
	_draw.colorBox(12, row, col, 15, 28);
}