#ifndef _SOUND_H_
#define _SOUND_H_
#pragma comment (lib, "winmm.lib")
using namespace std;

#include "Draw.h"
class Sound
{
public:
	void mainsong(bool a);
	void playgamesound();
	void endsound();
	void BonusSound();
	void meetsnakesound();
	void meetsnakesound2();
	void meetladdersound();
	void meetladdersound2();
};
#endif