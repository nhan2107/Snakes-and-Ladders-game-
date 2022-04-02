#include "Welcome.h"
void Welcome::opening()
{
	system("cls");
	_sound.mainsong(0);
	_draw.fullscreen();
	_draw.setFontSize(20);
	_draw.quadrangle(1, 40, 5, 70, 70, 40, 5);
	_draw.colorbackground(30, 40, 3, 39, 6);
	_draw.color(30);
	_draw.write("SNAKES AND LADDERS", 50, 8);
	_draw.quadrangle(1, 44, 1, 15, 15, 38, 16);
	_draw.write("Loading...", 55, 20);
	_draw.gotoxy(38, 17);
	for (int i = 1; i <= 43; i++)
	{
		_draw.color(32);
		cout << " ";
		int t = _main.dice(0, 220);
		Sleep(t);
	}
	_draw.gotoxy(45, 20);
	_draw.color(15);
	system("pause");
}