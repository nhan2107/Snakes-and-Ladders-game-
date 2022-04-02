#include "Snakes.h"
void Snakes::snake1()
{
	_draw.color(13);

	int x = 23, y = 23;
	_draw.gotoxy(x, y);
	printf("%c", 178); y++;
	_draw.gotoxy(x, y);
	for (int i = 0; i < 3; i++) {
		printf("%c", 178);
		_draw.gotoxy(x + 1, y + 1);
		x++; y++;
	}
	for (int i = 0; i < 3; i++) {
		printf("%c", 178);
		_draw.gotoxy(x + 1, y);
		x++;
	}
	_draw.gotoxy(x, y - 1); y--;
	printf("%c", 178);
	_draw.gotoxy(x + 1, y - 1);
	x++; y--;
	for (int i = 0; i < 2; i++) {
		printf("%c", 178);
		_draw.gotoxy(x + 1, y);
		x++;
	}
	for (int i = 0; i < 3; i++) {
		printf("%c", 178);
		_draw.gotoxy(x + 1, y + 1);
		x++; y++;
	}
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			printf("%c", 178);
			_draw.gotoxy(x + 1, y);
			x++;
		}
		_draw.gotoxy(x + 4, y);
		x += 4;
	}
	_draw.gotoxy(x - 11, y - 1);
	x -= 11; y--;
	for (int i = 0; i < 4; i++)
	{
		printf("%c", 178);
		_draw.gotoxy(x + 1, y);
		x++;
	}
	_draw.gotoxy(x + 3, y + 2);
	printf("%c", 178);
}

void Snakes::snake2()
{
	_draw.color(13);

	int x = 52, y = 9;
	_draw.gotoxy(x, y);
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			printf("%c", 178);
			_draw.gotoxy(x, y + 1);
			y++;
		}
		_draw.gotoxy(x + 3, y + 1);
		x += 3; y++;
	}

	x = 53, y = 12;
	_draw.gotoxy(x, y);
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			printf("%c", 178);
			_draw.gotoxy(x + 1, y);
			x++;
		}
		_draw.gotoxy(x + 1, y + 4);
		x++; y += 4;
	}
}

void Snakes::snake3()
{
	_draw.color(13);

	int x = 15, y = 3;
	_draw.gotoxy(x, y);
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			printf("%c", 178);
			_draw.gotoxy(x + 1, y);
			x++;
		}
		_draw.gotoxy(x - 7, y + 3);
		x -= 7; y += 3;
	}

	x = 14, y = 4;
	_draw.gotoxy(x, y);
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			printf("%c", 178);
			_draw.gotoxy(x, y + 1);
			y++;
		}
		_draw.gotoxy(x - 4, y + 1);
		x -= 4; y++;
	}
}

void Snakes::snake4()
{
	_draw.color(13);
	int x = 31, y = 11;
	_draw.gotoxy(x, y);
	for (int i = 0; i < 3; i++)
	{
		printf("%c", 178);
		_draw.gotoxy(x, ++y);
	}
	_draw.gotoxy(--x, y);
	for (int i = 0; i < 4; i++)
	{
		printf("%c", 178);
		_draw.gotoxy(--x, y);
	}
	for (int i = 0; i < 2; i++)
	{
		printf("%c", 178);
		_draw.gotoxy(--x, ++y);
	}
	for (int i = 0; i < 3; i++)
	{
		printf("%c", 178);
		_draw.gotoxy(++x, ++y);
	}
	_draw.gotoxy(x - 2, y);
	x -= 2;
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			printf("%c", 178);
			_draw.gotoxy(--x, y);
		}
		_draw.gotoxy(x, ++y);
	}
}
void Snakes::snake5()
{
	_draw.color(13);
	int x = 53, y = 2;
	_draw.gotoxy(x, y);
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			printf("%c", 178);
			_draw.gotoxy(x, ++y);
		}
		_draw.gotoxy(x + 12, y + 3);
		x += 12; y += 3;
	}
	x = 56, y = 6;
	_draw.gotoxy(x, y);
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 3; j++) {
			printf("%c", 178);
			_draw.gotoxy(++x, y);
		}
		_draw.gotoxy(++x, y - 2);
		y -= 2;
	}
	x = 54, y = 4;
	_draw.gotoxy(x, y);
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			printf("%c", 178);
			_draw.gotoxy(++x, ++y);
		}
		_draw.gotoxy(x + 7, --y);
		x += 7;
	}
	_draw.gotoxy(59, 5);
	printf("%c", 178);
}