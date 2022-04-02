#include "Sound.h"
void Sound::mainsong(bool a)
{
	LPCWSTR audio = L"Bonneton.wav";
	if (a == 0)
	{
		bool play = PlaySound(audio, NULL, SND_ASYNC | SND_LOOP);
	}
	else bool play = PlaySound(audio, NULL, SND_NOSTOP| SND_ASYNC | SND_LOOP);
}
void Sound::playgamesound()
{
	LPCWSTR audio = L"Piano slam.wav";
	bool play = PlaySound(audio, NULL, SND_ASYNC);
}
void Sound::endsound()
{
	LPCWSTR audio = L"CONGRATULATIONS_.wav";
	bool play = PlaySound(audio, NULL, SND_ASYNC);
}
void Sound::BonusSound()
{
	LPCWSTR audio = L"Bonus sound.wav";
	bool play = PlaySound(audio, NULL, SND_SYNC);
}
void Sound::meetsnakesound()
{
	LPCWSTR audio = L"Ouch!!.wav";
	bool play = PlaySound(audio, NULL, SND_SYNC);
}
void Sound::meetsnakesound2()
{
	LPCWSTR audio = L"Ouch2!.wav";
	bool play = PlaySound(audio, NULL, SND_SYNC);
}
void Sound::meetladdersound()
{
	LPCWSTR audio = L"TOASTY!.wav";
	bool play = PlaySound(audio, NULL, SND_SYNC);
}
void Sound::meetladdersound2()
{
	LPCWSTR audio = L"Haha.wav";
	bool play = PlaySound(audio, NULL, SND_SYNC);
}