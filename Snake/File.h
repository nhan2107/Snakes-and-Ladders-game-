#ifndef _FILE_H_
#define _FILE_H_
#pragma comment (lib, "winmm.lib")
using namespace std;

#include "Random.h"
struct turn
{
	int TURN;
	int flag[2];
	int LINE[2];
};
struct player
{
	string name;
	int score;
	int step;
	int locate;
	int posx, posy;
};
class File
{
public:
	void write(string s, player a, player b, turn c);
	void open(string s, player& a, player& b, turn &c);
	bool checkbinaryexist(string path);
	void deleteoneline(string path, string eraseLine);
};
#endif