#include "Ladders.h"

void Ladders::ladder1()
{
	_draw.color(8);

	//line left
	int x = 57, y = 28;
	_draw.gotoxy(x, y);
	for (int i = 0; i < 10; i++) {
		printf("%c", 201);
		_draw.gotoxy(x + 1, y - 1);
		x++; y--;
	}

	//line right
	x = 61, y = 30;
	_draw.gotoxy(x, y);
	for (int i = 0; i < 10; i++) {
		printf("%c", 201);
		_draw.gotoxy(x + 1, y - 1);
		x++; y--;
	}

	//line middle
	x = 66, y = 21;
	_draw.gotoxy(x, y);
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 2; j++) {
			printf("%c", 177);
			_draw.gotoxy(x + 1, y + 1);
			x++; y++;
		}
		_draw.gotoxy(x - 4, y);
		x -= 4;
	}
}
void Ladders::ladder2()
{
	_draw.color(8);

	//line left
	int x = 3, y = 25;
	_draw.gotoxy(x, y);
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 2; j++) {
			printf("%c", 201);
			_draw.gotoxy(x, y - 1);
			y--;
		}
		_draw.gotoxy(x + 1, y);
		x++;
	}

	//line right
	x = 7, y = 26;
	_draw.gotoxy(x, y);
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 2; j++) {
			printf("%c", 201);
			_draw.gotoxy(x, y - 1);
			y--;
		}
		_draw.gotoxy(x + 1, y);
		x++;
	}

	//line middle
	x = 8, y = 16;
	_draw.gotoxy(x, y);
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 3; j++) {
			printf("%c", 177);
			_draw.gotoxy(x + 1, y + 1);
			x++; y++;
		}
		_draw.gotoxy(x - 4, y - 1);
		x -= 4; y--;
	}
}
void Ladders::ladder3()
{
	_draw.color(8);

	//line left
	int x = 25, y = 6;
	_draw.gotoxy(x, y);
	for (int i = 0; i < 7; i++) {
		for (int j = 0; j < 3; j++) {
			printf("%c", 187);
			_draw.gotoxy(x + 1, y);
			x++;
		}
		_draw.gotoxy(x, y + 1);
		y++;
	}

	//line right
	x = 27, y = 4;
	_draw.gotoxy(x, y);
	for (int i = 0; i < 7; i++) {
		for (int j = 0; j < 3; j++) {
			printf("%c", 187);
			_draw.gotoxy(x + 1, y);
			x++;
		}
		_draw.gotoxy(x, y + 1);
		y++;
	}

	//line middle
	x = 27, y = 5;
	_draw.gotoxy(x, y);
	for (int i = 0; i < 7; i++) {
		printf("%c", 177);
		_draw.gotoxy(x + 3, y + 1);
		x += 3; y++;
	}
}
void Ladders::ladder4()
{
	_draw.color(8);

	//line left
	int x = 30, y = 17;
	_draw.gotoxy(x, y);
	for (int i = 0; i < 8; i++) {
		printf("%c", 187);
		_draw.gotoxy(x + 1, y + 1);
		x++; y++;
	}

	//line right
	x = 33, y = 16;
	_draw.gotoxy(x, y);
	for (int i = 0; i < 8; i++) {
		printf("%c", 187);
		_draw.gotoxy(x + 1, y + 1);
		x++; y++;
	}

	//line middle
	x = 33, y = 18;
	_draw.gotoxy(x, y);
	for (int i = 0; i < 3; i++) {
		printf("%c", 177);
		_draw.gotoxy(x + 2, y + 2);
		x += 2; y += 2;
	}
}