#ifndef _DRAW_H_
#define _DRAW_H_
#pragma comment (lib, "winmm.lib")
#define RED 12
#define YELLOW 14
#define GREEN 10
#define BLUE 25
#define WHITE 15
using namespace std;
#include <iostream>
#include <stdio.h>
#include <string>
#include <ctime>
#include <vector>
#include <Windows.h>
#include <dos.h>
#include <conio.h>
#include <fstream>
#include <stdlib.h>
#include <string>
#include <random>
#include <chrono>
class Draw
{
public:
	void gotoxy(SHORT x, SHORT y);
	void fullscreen();
	void color(int k);
	void colorBox(int clr, int row, int col, int x, int y);
	void FixConsoleWindow();
	void setFontSize(int FontSize);
	void line(short int k, int n, int clr, int& x, int& y);
	void colorbackground(int clr, int l, int w, int x, int y);
	void quadrangle(bool t, int l, int w, int clrline, int clrbackground, int x, int y);
	void write(string s, int x, int y);
	string ToStringNumber(int a);
	char helpdraw(int x, int y);
};
#endif;