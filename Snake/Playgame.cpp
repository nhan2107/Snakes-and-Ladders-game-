#include "Playgame.h"
void Playgame::newgame()
{
	system("cls");
	_pl1.score = 0;
	_pl1.step = 0;
	_pl2.score = 0;
	_pl2.step = 0;
	_pl1.locate = 0;
	_pl2.locate = 0;
	_pl1.posx = 0;
	_pl1.posy = 30;
	_pl2.posx = 0;
	_pl2.posy = 30;
	_t.TURN = 1;
	_t.flag[0] = 0;
	_t.flag[1] = 0;
	_t.LINE[1] = 1;
	_t.LINE[0] = 1;
	_draw.quadrangle(1, 30, 1, 15, 15, 33, 7);
	_draw.write("Select game mode: ", 40, 8);
	_draw.quadrangle(1, 25, 1, 15, 15, 20, 10);
	_draw.write("1.Player vs computer", 23, 11);
	_draw.quadrangle(1, 25, 1, 15, 15, 60, 10);
	_draw.write("2.Player vs Player", 63, 11);
	char c = _getch();
	switch (c)
	{
	case '2':
	{
		system("cls");
		_draw.quadrangle(1, 20, 1, 15, 15, 50, 13);
		_draw.write("Player 1: ", 53, 14);
		_draw.gotoxy(62, 14);
		getline(cin, _pl1.name);
		_draw.quadrangle(1, 20, 1, 15, 15, 50, 17);
		_draw.write("Player 2: ", 53, 18);
		_draw.gotoxy(62, 18);
		getline(cin, _pl2.name);
		_fi.write("player1.dat", _pl1, _pl2,_t);
		checkplaygame("player1.dat");
		break;
	}
	case '1':
	{
		string a = "AIcomputer";
		_pl2.name = "";
		_pl2.name += a;
		system("cls");
		_draw.quadrangle(1, 20, 1, 15, 15, 50, 13);
		_draw.write("Player: ", 53, 14);
		_draw.gotoxy(62, 14);
		getline(cin, _pl1.name);
		_fi.write("player1.dat", _pl1, _pl2, _t);
		checkplaygame("player1.dat");
		break;
	}
	default:
	{
		while (true)
		{
			_draw.color(_main.dice(1, 15));
			_draw.write("Select game mode: ", 40, 8);
			_draw.write("1.Player vs computer", 23, 11);
			_draw.write("2.Player vs Player", 63, 11);
			char c1 = _getch();
			switch (c1)
			{
			case '2':
			{
				system("cls");
				_draw.quadrangle(1, 20, 1, 15, 15, 50, 13);
				_draw.write("Player 1: ", 53, 14);
				_draw.gotoxy(62, 14);
				getline(cin, _pl1.name);
				_draw.quadrangle(1, 20, 1, 15, 15, 50, 17);
				_draw.write("Player 2: ", 53, 18);
				_draw.gotoxy(62, 18);
				getline(cin, _pl2.name);
				_fi.write("player1.dat", _pl1, _pl2, _t);
				checkplaygame("player1.dat");
				break;
				break;
			}
			case '1':
			{
				string a = "AIcomputer";
				_pl2.name = "";
				_pl2.name += a;
				system("cls");
				_draw.quadrangle(1, 20, 1, 15, 15, 50, 13);
				_draw.write("Player: ", 53, 14);
				_draw.gotoxy(62, 14);
				getline(cin, _pl1.name);
				_fi.write("player1.dat", _pl1, _pl2,_t);
				checkplaygame("player1.dat");
				break;
				break;
			}
			default:
				break;
			}
		}
		break;
	}
	}
}
void Playgame::checkplaygame(string s)
{
	_fi.open(s, _pl1, _pl2,_t);
	if (_pl2.name == "AIcomputer")
	{
		_main.main(s);
		if (s == "player1.dat")
		{
			bool del = remove("player1.dat");
		}
		playgamewithcomputer();
	}
	else
	{
		_main.main(s);
		if (s == "player1.dat")
		{
			bool del = remove("player1.dat");
		}
		playgame();
	}
}
void Playgame::playgame()
{
	int choice;
	starttime();
	while (true)
	{
		checkwin();
		Sleep(600);
		for (int j = 0; j <= 6; j++)
		{
			_draw.write("           ", 87, 15 + j);
		}
		_draw.write("      ", 93, 5);
		_draw.write("      ", 85, 5);
		_draw.quadrangle(1, 31, 1, 15, 15, 76, 11);
		if (_t.TURN == 1)
		{
			_draw.write(_pl1.name, 87, 12);
		}
		else _draw.write(_pl2.name, 87, 12);
		_draw.write("Press 1 to dice", 84, 20);
		char c = _getch();
		if (c == '1')
		{
			dicen();
		}
		if (c == '2')
		{
			save();
			break;
		}
		if (c == '3')
		{
			_fi.write("player1.dat", _pl1, _pl2,_t);
			break;
		}
		if (c == '4')
		{
			system("cls");
			break;
		}
	}
}

void Playgame::dicen()
{
	int n;
	_draw.write("               ", 84, 20);
	_draw.write("               ", 84, 22);
	n = _main.dice(1,6);
	_draw.color(_main.dice(1,15));
	switch (n)
	{
	case 1:
	{
		for (int i = 0; i <= 4; i++)
		{
			_draw.write("1", 90, 15 + i);
		}
		break;
	}
	case 2:
	{
		_draw.write("22222", 88, 15);
		_draw.write("2", 92, 16);
		_draw.write("22222", 88, 17);
		_draw.write("2", 88, 18);
		_draw.write("22222", 88, 19);
		break;
	}
	case 3:
	{
		_draw.write("33333", 88, 15);
		_draw.write("3", 92, 16);
		_draw.write("33333", 88, 17);
		_draw.write("3", 92, 18);
		_draw.write("33333", 88, 19);
		break;
	}
	case 4:
	{
		_draw.write("4   4", 88, 15);
		_draw.write("4   4", 88, 16);
		_draw.write("44444", 88, 17);
		_draw.write("4", 92, 18);
		_draw.write("4", 92, 19);
		break;
	}
	case 5:
	{
		_draw.write("55555", 88, 15);
		_draw.write("5", 88, 16);
		_draw.write("55555", 88, 17);
		_draw.write("5", 92, 18);
		_draw.write("55555", 88, 19);
		break;
	}
	case 6:
	{
		_draw.write("66666", 88, 15);
		_draw.write("6", 88, 16);
		_draw.write("66666", 88, 17);
		_draw.write("6   6", 88, 18);
		_draw.write("66666", 88, 19);
		break;
	}
	default:
		break;
	}
	_draw.color(15);
	position(n);
}
void Playgame::starttime()
{
	for (int t = 3; t >= 0; t--)
	{
		_draw.color(_main.dice(1, 15));
		switch (t)
		{
		case 1:
		{
			for (int i = 0; i <= 4; i++)
			{
				_draw.write("1", 90, 15 + i);
			}
			Beep(650, 100);
			Sleep(900);
			for (int j = 0; j <= 6; j++)
			{
				_draw.write("           ", 87, 15 + j);
			}
			break;
		}
		case 2:
		{
			_draw.write("22222", 88, 15);
			_draw.write("2", 92, 16);
			_draw.write("22222", 88, 17);
			_draw.write("2", 88, 18);
			_draw.write("22222", 88, 19);
			Beep(650, 100);
			Sleep(900);
			for (int j = 0; j <= 6; j++)
			{
				_draw.write("           ", 87, 15 + j);
			}
			break;
		}
		case 3:
		{
			_draw.write("33333", 88, 15);
			_draw.write("3", 92, 16);
			_draw.write("33333", 88, 17);
			_draw.write("3", 92, 18);
			_draw.write("33333", 88, 19);
			Beep(650, 100);
			Sleep(900);
			for (int j = 0; j <= 6; j++)
			{
				_draw.write("           ", 87, 15 + j);
			}
			break;
		}
		default:
		{
			_draw.write("00000", 88, 15);
			_draw.write("0   0", 88, 16);
			_draw.write("0   0", 88, 17);
			_draw.write("0   0", 88, 18);
			_draw.write("00000", 88, 19);
			break;
		}
		}
	}
	_sound.playgamesound();
}
void Playgame::playgamewithcomputer()
{
	int choice;
	starttime();
	while(true)
	{
		checkwin();
		Sleep(600);
		for (int i = 0; i <= 6; i++)
		{
			_draw.write("           ", 87, 15 + i);
		}
		_draw.write("      ", 93, 5);
		_draw.write("      ", 85, 5);
		_draw.quadrangle(1, 31, 1, 15, 15, 76, 11);
		_draw.write("Press 1 to dice", 84, 20);
		if (_t.TURN == 1)
		{
			_draw.write(_pl1.name, 87, 12);
			char c = _getch();
			if (c == '1')
			{
				dicen();
			}
			if (c == '2')
			{
				save();
				break;
			}
			if (c == '3')
			{
				_fi.write("player1.dat", _pl1, _pl2,_t);
				break;
			}
			if (c == '4')
			{
				system("cls");
				break;
			}
		}
		else
		{
			_draw.write(_pl2.name, 87, 12);
			Sleep(300);
			dicen();
		}
	}
}

void Playgame::save()
{
	string name;
	system("cls");
	ifstream fo("Data.txt", ios::in);
	string dataall;
	string line;
	while (!fo.eof())
	{
		getline(fo, line);
		dataall += "\n";
		dataall += line;
	}
	fo.close();
	_draw.write("Save as: ", 40, 14);
	_draw.gotoxy(49, 14);
	getline(cin, name);
	ofstream f("Data.txt", ios::out | ios::app);
	int search_index = dataall.find(name);
	if (search_index == -1)
	{
		string data;
		data += "\n";
		data += name;
		f << data;
		f.close();
		name += ".dat";
		_fi.write(name, _pl1, _pl2, _t);
	}
	else
	{
		name += ".dat";
		_fi.write(name, _pl1, _pl2, _t);
	}
}

void Playgame::checkwin()
{
	if (_pl1.locate >= 100)
	{
		endgame(_pl1, _pl2);
	}
	if (_pl2.locate >= 100)
	{
		endgame(_pl2, _pl1);
	}
}

void Playgame::endgame(player& playerWin, player& playerLose)
{
	system("cls");
	_sound.endsound();
	int x1 = 0;
	int x2 = 40;
	int y = 10;
	while (x1!=x2)
	{
		_draw.setFontSize(35);
		_draw.color(_main.dice(1, 15));
		system("cls");
		_draw.write(playerWin.name + " WIN", x1, y);
		_draw.write(playerLose.name + " LOSE", x2, y + 2);
		x1++;
		x2--;
		Sleep(18);
		if (x1 == x2)
		{
			system("cls");
			for (int i = 0; i <= 20; i++)
			{
				_draw.color(_main.dice(1, 15));
				_draw.write(playerWin.name + " WIN", x1, y);
				_draw.write(playerLose.name + " LOSE", x2, y + 2);
				Sleep(45);
			}
		}
	}
	askwin(playerWin, playerLose);
}

void Playgame::askwin(player& playerWin, player& playerLose)
{
	system("cls");
	_draw.FixConsoleWindow();
	_draw.setFontSize(21);
	_draw.color(_main.dice(1, 15));
	_draw.write(playerWin.name + " WIN", 40, 10);
	int i;
	int j;
	for (i = 0; i <= 100; i++)
	{
		_draw.write(to_string(i), (playerWin.name + " WIN").size() + 41, 10);
		Sleep(25);
	}
	_draw.write(playerLose.name + " LOSE", 40, 12);
	for (j = 0; j <= playerLose.locate; j++)
	{
		_draw.write(to_string(j), (playerLose.name + " LOSE").size() + 41, 12);
		Sleep(25);
	}
	string f = "player1.dat";
	_draw.write("Do you want to play this game again (y/n)", 40, 20);
	char key = _getch();
	switch (key)
	{
	case 'n':
	{
		bool del = remove(f.c_str());
		exit(0);
		break;
	}
	case 'y':
	{
		if (playerWin.locate == _pl1.locate)
		{
			_t.TURN = 1;
		}
		else _t.TURN = 2;
		playerWin.score++;
		playerWin.step = 0;
		playerWin.locate = 0;
		playerLose.step = 0;
		playerLose.locate = 0;
		playerWin.posx = 0;
		playerLose.posx = 0;
		playerWin.posy = 30;
		playerLose.posy = 30;
		_t.flag[0] = 0;
		_t.flag[1] = 0;
		_t.LINE[0] = 1;
		_t.LINE[1] = 1;
		bool del = remove(f.c_str());
		_fi.write(f, _pl1, _pl2,_t);
		checkplaygame(f);
		break;
	}
	default:
	{
		while (true)
		{
			_draw.setFontSize(21);
			_draw.color(_main.dice(1, 15));
			_draw.write(playerWin.name + " WIN", 40, 10);
			_draw.write("100", (playerWin.name + " WIN").size() + 41, 10);
			_draw.write(playerLose.name + " LOSE", 40, 12);
			_draw.write(to_string(j-1), (playerLose.name + " LOSE").size() + 41, 12);
			_draw.write("Do you want to play this game again (y/n)", 40, 20);
			char key2 = _getch();
			switch (key2)
			{
			case 'n':
			{
				bool del = remove(f.c_str());
				exit(0);
				break;
			}
			case 'y':
			{
				if (playerWin.locate == _pl1.locate)
				{
					_t.TURN = 1;
				}
				else _t.TURN = 2;
				playerWin.score++;
				playerWin.step = 0;
				playerWin.locate = 0;
				playerLose.step = 0;
				playerLose.locate = 0;
				playerWin.posx = 0;
				playerLose.posx = 0;
				playerWin.posy = 30;
				playerLose.posy = 30;
				_t.flag[0] = 0;
				_t.flag[1] = 0;
				_t.LINE[0] = 1;
				_t.LINE[1] = 1;
				bool del = remove(f.c_str());
				_fi.write(f, _pl1, _pl2,_t);
				checkplaygame(f);
				break;
				break;
			}
			default:
				break;
			}
		}
		break;
	}
	}
}

void Playgame::position(int numdice)
{
	if (1 == _t.TURN)
	{
		_pl1.locate += numdice;
		_draw.write(_draw.ToStringNumber(_pl1.locate), 87, 4);
		if (_pl1.step > 0)
		{
			removeRecentPosition(_pl1.posx, _pl1.posy);
		}
		if (_t.LINE[0] % 2 == 0)
		{
			_pl1.posx -= numdice * 7;
			if (_pl1.posx < 1)
			{
				_pl1.posx = -_pl1.posx + 7;
				_pl1.posy -= 3;
				_t.LINE[0]++;
			}
		}
		else
		{
			_pl1.posx += numdice * 7;
			if (_pl1.posx > 70)
			{
				_pl1.posx = _pl1.posx - 70;
				_pl1.posx = 70 - _pl1.posx + 7;
				_pl1.posy -= 3;
				_t.LINE[0]++;
			}
		}
		meetSnake(_pl1.posx, _pl1.posy, "1");
		meetLadder(_pl1.posx, _pl1.posy, "1");
		printRecentPosition(_pl1.posx, _pl1.posy, _pl2.posx, _pl2.posy, "1");
		_draw.color(15);
		_draw.write(_pl1.name, 87, 2);
		_draw.write(_draw.ToStringNumber(_pl1.score), 87, 3);
		_draw.write(_draw.ToStringNumber(_pl1.locate), 87, 4);
		if (numdice == 6)
		{
			_t.TURN = 1;
			_draw.color(9);
			_draw.write("BONUS!!!!", 87, 22);
			_draw.write(_pl1.name, 87, 2);
			_draw.write(_draw.ToStringNumber(_pl1.score), 87, 3);
			_draw.write(_draw.ToStringNumber(_pl1.locate), 87, 4);
			_sound.BonusSound();
			_draw.color(15);
			_pl1.step++;
		}
		else
		{
			_t.TURN = 2;
			_pl1.step++;
		}
	}
	else if (2 == _t.TURN)
	{
		_pl2.locate += numdice;
		_draw.write(_draw.ToStringNumber(_pl2.locate), 95, 4);
		if (_pl2.step > 0)
		{
			removeRecentPosition(_pl2.posx, _pl2.posy);
		}
		if (_t.LINE[1] % 2 == 0)
		{
			_pl2.posx -= numdice * 7;
			if (_pl2.posx < 1)
			{
				_pl2.posx = -_pl2.posx + 7;
				_pl2.posy -= 3;
				_t.LINE[1]++;
			}
		}
		else
		{
			_pl2.posx += numdice * 7;
			if (_pl2.posx > 70)
			{
				_pl2.posx = _pl2.posx - 70;
				_pl2.posx = 70 - _pl2.posx + 7;
				_pl2.posy -= 3;
				_t.LINE[1]++;
			}
		}
		meetSnake(_pl2.posx, _pl2.posy, "2");
		meetLadder(_pl2.posx, _pl2.posy, "2");
		printRecentPosition(_pl2.posx, _pl2.posy, _pl1.posx, _pl1.posy, "2");
		_draw.color(15);
		_draw.write(_pl2.name, 95, 2);
		_draw.write(_draw.ToStringNumber(_pl2.score), 95, 3);
		_draw.write(_draw.ToStringNumber(_pl2.locate), 95, 4);
		if (numdice == 6)
		{
			_t.TURN = 2;
			_draw.color(9);
			_draw.write("BONUS!!!!", 87, 22);
			_draw.write(_pl2.name, 95, 2);
			_draw.write(_draw.ToStringNumber(_pl2.score), 95, 3);
			_draw.write(_draw.ToStringNumber(_pl2.locate), 95, 4);
			_sound.BonusSound();
			_draw.color(15);
			_pl2.step++;
		}
		else
		{
			_t.TURN = 1;
			_pl2.step++;
		}
	}
}

void Playgame::printRecentPosition(int x, int y, int comparedX, int comparedY, string player)
{
	if (x == comparedX && y == comparedY)
	{
		_draw.write(player, x - 1, y);
		if (2 == _t.TURN) _t.flag[1] = 1;
		if (1 == _t.TURN) _t.flag[0] = 1;
	}
	else {
		_draw.write(player, x, y);
	}
}

void Playgame::meetSnake(int& x, int& y, string player)
{
	int tempx = x, tempy = y;
	if (isSnake(x, y) == true)
	{
		_draw.write(player, tempx, tempy);
		Sleep(900);
		removeRecentPosition(tempx, tempy);
	}
}

bool Playgame::isSnake(int& x, int& y)
{
	bool isTrue = false;
	if (x == 56 && y == 3)
	{
		x = 70; y = 9;
		if (1 == _t.TURN)
		{
			_t.LINE[0] = 8;
			_pl1.locate = 71;
			_draw.color(12);
			_draw.write(_pl1.name, 87, 2);
			_draw.write(_draw.ToStringNumber(_pl1.score), 87, 3);
			_draw.write(_draw.ToStringNumber(_pl1.locate), 87, 4);
			_draw.write("SNAKE", 85, 5);
			_sound.meetsnakesound();
		}
		else if (2 == _t.TURN) {
			_t.LINE[1] = 8;
			_pl2.locate = 71;
			_draw.color(12);
			_draw.write(_pl2.name, 95, 2);
			_draw.write(_draw.ToStringNumber(_pl2.score), 95, 3);
			_draw.write(_draw.ToStringNumber(_pl2.locate), 95, 4);
			_draw.write("SNAKE", 93, 5);
			_sound.meetsnakesound2();
		}
		isTrue = true;
	}
	else if (x == 35 && y == 12)
	{
		x = 21; y = 21;
		if (1 == _t.TURN)
		{
			_t.LINE[0] = 4;
			_pl1.locate = 38;
			_draw.color(12);
			_draw.write(_pl1.name, 87, 2);
			_draw.write(_draw.ToStringNumber(_pl1.score), 87, 3);
			_draw.write(_draw.ToStringNumber(_pl1.locate), 87, 4);
			_draw.write("SNAKE", 85, 5);
			_sound.meetsnakesound();
		}
		else if (2 == _t.TURN) 
		{
			_t.LINE[1] = 4;
			_pl2.locate = 38;
			_draw.color(12);
			_draw.write(_pl2.name, 95, 2);
			_draw.write(_draw.ToStringNumber(_pl2.score), 95, 3);
			_draw.write(_draw.ToStringNumber(_pl2.locate), 95, 4);
			_draw.write("SNAKE", 93, 5);
			_sound.meetsnakesound2();
		}
		isTrue = true;
	}
	else if (x == 28 && y == 24)
	{
		x = 49; y = 30;
		if (1 == _t.TURN)
		{
			_t.LINE[0] = 1;
			_pl1.locate = 7;
			_draw.color(12);
			_draw.write(_pl1.name, 87, 2);
			_draw.write(_draw.ToStringNumber(_pl1.score), 87, 3);
			_draw.write(_draw.ToStringNumber(_pl1.locate), 87, 4);
			_draw.write("SNAKE", 85, 5);
			_sound.meetsnakesound();
		}
		else if (2 == _t.TURN) {
			_t.LINE[1] = 1;
			_pl2.locate = 7;
			_draw.color(12);
			_draw.write(_pl2.name, 95, 2);
			_draw.write(_draw.ToStringNumber(_pl2.score), 95, 3);
			_draw.write(_draw.ToStringNumber(_pl2.locate), 95, 4);
			_draw.write("SNAKE", 93, 5);
			_sound.meetsnakesound2();
		}
		isTrue = true;
	}
	else if (x == 56 && y == 9)
	{
		x = 63; y = 18;
		if (1 == _t.TURN) 
		{
			_t.LINE[0] = 5;
			_pl1.locate = 49;
			_draw.color(12);
			_draw.write(_pl1.name, 87, 2);
			_draw.write(_draw.ToStringNumber(_pl1.score), 87, 3);
			_draw.write(_draw.ToStringNumber(_pl1.locate), 87, 4);
			_draw.write("SNAKE", 85, 5);
			_sound.meetsnakesound();
		}
		else if (2 == _t.TURN)
		{
			_t.LINE[1] = 5;
			_pl2.locate = 49;
			_draw.color(12);
			_draw.write(_pl2.name, 95, 2);
			_draw.write(_draw.ToStringNumber(_pl2.score), 95, 3);
			_draw.write(_draw.ToStringNumber(_pl2.locate), 95, 4);
			_draw.write("SNAKE", 93, 5);
			_sound.meetsnakesound2();
		}
		isTrue = true;
	}
	else if (x == 21 && y == 3)
	{
		x = 7; y = 12;
		if (1 == _t.TURN)
		{
			_t.LINE[0] = 7;
			_pl1.locate = 61;
			_draw.color(12);
			_draw.write(_pl1.name, 87, 2);
			_draw.write(_draw.ToStringNumber(_pl1.score), 87, 3);
			_draw.write(_draw.ToStringNumber(_pl1.locate), 87, 4);
			_draw.write("SNAKE", 85, 5);
			_sound.meetsnakesound();
		}
		else if (2 == _t.TURN) 
		{
			_t.LINE[1] = 7;
			_pl2.locate = 61;
			_draw.color(12);
			_draw.write(_pl2.name, 95, 2);
			_draw.write(_draw.ToStringNumber(_pl2.score), 95, 3);
			_draw.write(_draw.ToStringNumber(_pl2.locate), 95, 4);
			_draw.write("SNAKE", 93, 5);
			_sound.meetsnakesound2();
		}isTrue = true;
	}
	return isTrue;
}

bool Playgame::isLadder(int& x, int& y)
{
	bool isTrue = false;
	if (x == 42 && y == 24)
	{
		x = 35; y = 15;
		if (1 == _t.TURN)
		{
			_t.LINE[0] = 6;
			_pl1.locate = 56;
			_draw.color(10);
			_draw.write(_pl1.name, 87, 2);
			_draw.write(_draw.ToStringNumber(_pl1.score), 87, 3);
			_draw.write(_draw.ToStringNumber(_pl1.locate), 87, 4);
			_draw.write("LADDER", 85, 5);
			_sound.meetladdersound();
		}
		else if (2 == _t.TURN)
		{
			_t.LINE[1] = 6;
			_pl2.locate = 56;
			_draw.color(10);
			_draw.write(_pl2.name, 95, 2);
			_draw.write(_draw.ToStringNumber(_pl2.score), 95, 3);
			_draw.write(_draw.ToStringNumber(_pl2.locate), 95, 4);
			_draw.write("LADDER", 93, 5);
			_sound.meetladdersound2();
		}
		isTrue = true;
	}
	else if (x == 7 && y == 27)
	{
		x = 14; y = 15;
		if (1 == _t.TURN)
		{
			_t.LINE[0] = 6;
			_pl1.locate = 59;
			_draw.color(10);
			_draw.write(_pl1.name, 87, 2);
			_draw.write(_draw.ToStringNumber(_pl1.score), 87, 3);
			_draw.write(_draw.ToStringNumber(_pl1.locate), 87, 4);
			_draw.write("LADDER", 85, 5);
			_sound.meetladdersound();
		}
		else if (2 == _t.TURN) {
			_t.LINE[1] = 6;
			_pl2.locate = 59;
			_draw.color(10);
			_draw.write(_pl2.name, 95, 2);
			_draw.write(_draw.ToStringNumber(_pl2.score), 95, 3);
			_draw.write(_draw.ToStringNumber(_pl2.locate), 95, 4);
			_draw.write("LADDER", 93, 5);
			_sound.meetladdersound2();
		}
		isTrue = true;
	}
	else if (x == 63 && y == 30)
	{
		x = 70; y = 21;
		if (1 == _t.TURN) {
			_t.LINE[0] = 4;
			_pl1.locate = 31;
			_draw.color(10);
			_draw.write(_pl1.name, 87, 2);
			_draw.write(_draw.ToStringNumber(_pl1.score), 87, 3);
			_draw.write(_draw.ToStringNumber(_pl1.locate), 87, 4);
			_draw.write("LADDER", 85, 5);
			_sound.meetladdersound();
		}
		else if (2 == _t.TURN) {
			_t.LINE[1] = 4;
			_pl2.locate = 31;
			_draw.color(10);
			_draw.write(_pl2.name, 95, 2);
			_draw.write(_draw.ToStringNumber(_pl2.score), 95, 3);
			_draw.write(_draw.ToStringNumber(_pl2.locate), 95, 4);
			_draw.write("LADDER", 93, 5);
			_sound.meetladdersound2();
		}
		isTrue = true;
	}
	else if (x == 49 && y == 12)
	{
		x = 28; y = 6;
		if (1 == _t.TURN) {
			_t.LINE[0] = 9;
			_pl1.locate = 84;
			_draw.color(10);
			_draw.write(_pl1.name, 87, 2);
			_draw.write(_draw.ToStringNumber(_pl1.score), 87, 3);
			_draw.write(_draw.ToStringNumber(_pl1.locate), 87, 4);
			_draw.write("LADDER", 85, 5);
			_sound.meetladdersound();
		}
		else if (2 == _t.TURN)
		{
			_t.LINE[1] = 9;
			_pl2.locate = 84;
			_draw.color(10);
			_draw.write(_pl2.name, 95, 2);
			_draw.write(_draw.ToStringNumber(_pl2.score), 95, 3);
			_draw.write(_draw.ToStringNumber(_pl2.locate), 95, 4);
			_draw.write("LADDER", 93, 5);
			_sound.meetladdersound2();
		}
		isTrue = true;
	}
	return isTrue;
}

void Playgame::meetLadder(int& x, int& y, string player)
{
	int tempx = x, tempy = y;
	if (isLadder(x, y) == true)
	{
		_draw.write(player, tempx, tempy);
		Sleep(1000);
		removeRecentPosition(tempx, tempy);
	}
}

void Playgame::removeRecentPosition(int x, int y)
{
	int index=0;
	if (1 == _t.TURN) index = 0;
	else if (2 == _t.TURN) index = 1;
	if (*(_t.flag+index) != 1)
	{
		string s(1, _draw.helpdraw(x, y));
		_draw.write(s, x, y);
	}
	else
	{
		string s(1, _draw.helpdraw(x, y));
		_draw.write(s, x - 1, y);
		_t.flag[index] = 0;
	}
}