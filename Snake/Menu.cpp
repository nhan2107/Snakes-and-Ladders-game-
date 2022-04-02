#include "Menu.h"

void Menu::menu()
{
	system("cls");
	_sound.mainsong(1);
	_draw.setFontSize(20);
	_draw.FixConsoleWindow();
	_draw.quadrangle(1, 40, 5, 70, 70, 40, 3);
	_draw.colorbackground(30, 40, 3, 39, 4);
	_draw.color(30);
	_draw.write("SNAKES AND LADDERS", 50, 6);
	_draw.quadrangle(1, 20, 1, 15, 15, 50, 11);
	_draw.quadrangle(1, 20, 1, 15, 15, 50, 14);
	if (_fo.checkbinaryexist("player1.dat") == false)
	{
		_draw.quadrangle(1, 20, 1, 8, 8, 50, 17);
	}
	else
	{
		_draw.quadrangle(1, 20, 1, 15, 15, 50, 17);
	}
	_draw.quadrangle(1, 20, 1, 15, 15, 50, 20);
	_draw.quadrangle(1, 20, 1, 15, 15, 50, 23);
	_draw.quadrangle(1, 20, 1, 15, 15, 50, 26);
	menulist();
}

void Menu::menulist()
{
	int clr = _main.dice(1, 15);
	_draw.color(clr);
	_draw.write("1.LOAD GAME", 54, 12);
	_draw.write("2.NEW GAME", 54, 15);
	if (_fo.checkbinaryexist("player1.dat") == false)
	{
		_draw.color(8);
		_draw.write("3.RESUME", 54, 18);
		_draw.color(clr);
	}
	else
	{
		_draw.write("3.RESUME", 54, 18);
	}
	_draw.write("4.HOW TO PLAY", 54, 21);
	_draw.write("5.INFORMATION", 54, 24);
	_draw.write("6.EXIT", 54, 27);
	char choose = _getch();
	switch (choose)
	{
	case '1':
	{
		load();
		break;
	}
	case '2':
	{
		asknewgame();
		break;
	}
	case '3':
	{
		resume();
		break;
	}
	case '4':
	{
		howtoplay1();
		break;
	}
	case '5':
	{
		infor();
		break;
	}
	case '6':
	{
		exit(0);
		break;
	}
	default:
	{
		menulist();
		break;
	}
	}
}
void Menu::resume()
{
	if (_fo.checkbinaryexist("player1.dat") == false)
	{
		return menulist();
	}
	else _play.checkplaygame("player1.dat");
}

void Menu::asknewgame()
{
	system("cls");
	_draw.quadrangle(1, 40, 1, 15, 15, 40, 10);
	_draw.color(_main.dice(1,15));
	_draw.write("Do you want to play a new game? (y/n)", 41, 11);
	char key = _getch();
	switch (key)
	{
	case 'n':
	{
		menu();
		break;
	}
	case 'y':
	{
		_play.newgame();
		menu();
		break;
	}
	default:
	{
		while (true)
		{
			_draw.color(_main.dice(1, 15));
			_draw.write("Do you want to play a new game? (y/n)", 41, 11);
			char key2 = _getch();
			switch (key2)
			{
			case 'n':
			{
				menu();
				break;
			}
			case 'y':
			{
				_play.newgame();
				menu();
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

void Menu::load()
{
	system("cls");
	ifstream fo("Data.txt", ios::in);
	string data;
	string line;
	while (!fo.eof())
	{
		getline(fo, line);
		data += "\n";
		data += line;
	}
	fo.close();
	_draw.write("List of main game you saved: ", 30, 2);
	_draw.write("->Press 1 to open saved game ", 30, 21);
	_draw.write("->Press 2 to delete saved game ", 30, 22);
	_draw.write("->Press 3 to return to the menu ", 30, 23);
	_draw.write(data, 3, 4);
	char g = _getch();
	if (g == '1')
	{
		string c;
		_draw.write("Open saved game:", 30, 25);
		_draw.write("Enter a name: ", 30, 26);
		_draw.gotoxy(44, 26);
		getline(cin, c);
		int search_index = data.find(c);
		if (search_index == -1)
		{
			data = "";
			_draw.write("This saved game is not found... ", 30, 27);
			Sleep(600);
			load();
		}
		else
		{
			c += ".dat";
			_play.checkplaygame(c);
			menu();
		}
	}
	else if (g == '2')
	{
		string c;
		_draw.write("Delete saved game:", 30, 25);
		_draw.write("Enter a name: ", 30, 26);
		getline(cin, c);
		int32_t search_index = data.find(c);
		if (search_index == -1)
		{
			data = "";
			_draw.write("Can't delete this saved game. Please try again :) :) ", 30, 27);
			Sleep(1000);
			load();
		}
		else
		{
			string n = c;
			c += ".dat";
			bool del = remove(c.c_str());
			if (del != 0)
			{
				_draw.write("Can't delete this saved game. ", 30, 27);
				data = "";
				Sleep(1000);
				load();
			}
			else
			{
				_fo.deleteoneline("Data.txt", n);
				_draw.write("Successfully completed. Please wait...", 30, 27);
				data = "";
				Sleep(1000);
				load();
			}
		}
	}
	else if (g == '3')
	{
		menu();
	}
	else
	{
		_draw.color(_main.dice(1,15));
		load();
	}
}

void Menu::infor()
{
	system("cls");
	_draw.FixConsoleWindow();
	_draw.quadrangle(1, 40, 5, 70, 70, 40, 3);
	_draw.colorbackground(30, 40, 3, 39, 4);
	_draw.color(30);
	_draw.write("SNAKES AND LADDERS", 50, 6);
	_draw.quadrangle(1, 38, 14, 15, 15, 41, 10);
	_draw.color(_main.dice(1, 15));
	_draw.write("List of group members:", 47, 11);
	_draw.write("19127230: Nguyen Tri Nhan (Leader)", 43, 12);
	_draw.write("19127304: Tran Khai Truc", 43, 13);
	_draw.write("19127577: Pham Duy Tien", 43, 14);
	_draw.write("Press 1 to return to the menu", 44, 26);
	_draw.write("Press any key to change color", 44, 27);
	char c = _getch();
	if (c == '1')
	{
		menu();
	}
	else
	{
		while (true)
		{
			_draw.color(_main.dice(1, 15));
			_draw.write("List of group members:", 47, 11);
			_draw.write("19127230: Nguyen Tri Nhan (Leader)", 43, 12);
			_draw.write("19127304: Tran Khai Truc", 43, 13);
			_draw.write("19127577: Pham Duy Tien", 43, 14);
			_draw.write("Press 1 to return to the menu", 44, 26);
			_draw.write("Press any key to change color", 44, 27);
			char c1 = _getch();
			if (c1 == '1')
			{
				menu();
				break;
			}
		}
	}
}


void Menu::howtoplay1()
{
	system("cls");
	_draw.FixConsoleWindow();
	_draw.quadrangle(1, 40, 5, 70, 70, 40, 3);
	_draw.colorbackground(30, 40, 3, 39, 4);
	_draw.color(30);
	_draw.write("SNAKES AND LADDERS", 50, 6);
	_draw.quadrangle(1, 65, 22, 15, 15, 27, 10);
	_draw.gotoxy(26, 28);
	printf("%c", 204);
	int x = 27;
	int y = 28;
	_draw.line(3, 64, 15, x, y);
	printf("%c", 185);
	int t = _main.dice(1, 15);
	_draw.color(t);
	_draw.write("*HOW TO PLAY THIS GAME*", 47, 11);
	_draw.write("+ Play +", 54, 12);
	_draw.quadrangle(1, 4, 1, t, t, 37, 13);
	_draw.write("1", 37, 14);
	_draw.write("Press 1: Roll the dice from 1 to 6", 41, 14);
	_draw.write("=>The player teleports according to the number", 37, 16);
	_draw.write("of the dice they get after rolling the dice", 37, 17);
	_draw.write("=>Your locate score can be increased, decreased or", 34, 19);
	_draw.write("kept the same depending on the square you are in.", 34, 20);
	_draw.write("->Press 0 to return to the menu<-", 43, 29);
	_draw.write("->Press 1 to go to the next page<-", 43, 30);
	_draw.write("->Press any key to change color<-", 43, 31);
	char c = _getch();
	switch (c)
	{
	case '0':
	{
		menu();
		break;
	}
	case '1':
	{
		howtoplay2();
		break;
	}
	default:
	{
		while (true)
		{
			int t = _main.dice(1, 15);
			_draw.color(t);
			_draw.write("*HOW TO PLAY THIS GAME*", 47, 11);
			_draw.write("+ Play +", 54, 12);
			_draw.quadrangle(1, 4, 1, t, t, 37, 13);
			_draw.write("1", 37, 14);
			_draw.write("Press 1: Roll the dice from 1 to 6", 41, 14);
			_draw.write("=>The player teleports according to the number", 37, 16);
			_draw.write("of the dice they get after rolling the dice", 37, 17);
			_draw.write("=>Your locate score can be increased, decreased or", 34, 19);
			_draw.write("kept the same depending on the square you are in.", 34, 20);
			_draw.write("->Press 0 to return to the menu<-", 43, 29);
			_draw.write("->Press 1 to go to the next page<-", 43, 30);
			_draw.write("->Press any key to change color<-", 43, 31);
			char c = _getch();
			switch (c)
			{
			case '0':
			{
				menu();
				break;
			}
			case '1':
			{
				howtoplay2();
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

void Menu::howtoplay2()
{
	system("cls");
	_draw.FixConsoleWindow();
	_draw.quadrangle(1, 40, 5, 70, 70, 40, 3);
	_draw.colorbackground(30, 40, 3, 39, 4);
	_draw.color(30);
	_draw.write("SNAKES AND LADDERS", 50, 6);
	_draw.quadrangle(1, 65, 22, 15, 15, 27, 10);
	_draw.gotoxy(26, 28);
	printf("%c", 204);
	int x = 27;
	int y = 28;
	_draw.line(3, 64, 15, x, y);
	printf("%c", 185);
	int t = _main.dice(1, 15);
	_draw.color(t);
	_draw.write("*HOW TO PLAY THIS GAME*", 47, 11);
	_draw.write("+ Rule +", 54, 12);
	_draw.write("- Locate scores are numbered on the squares on the board.", 30, 13);
	_draw.write("- If you get 100 points in locate first, you will win, your", 30, 14);
	_draw.write("score will increase by 1 point and you will play first if", 30, 15);
	_draw.write("you want to play again.", 30, 16);
	_draw.write("- If you get 6 when rolling the dice, you will be rolled", 30, 17);
	_draw.write("again after moving 6 squares, increasing 6 points in", 30, 18);
	_draw.write("position scores and moving down or moving up if you are", 30, 19);
	_draw.write("on a square with the snake head or the ladder foot.", 30, 20);
	_draw.write("- If you are on a square with the snake head, you will move", 30, 21);
	_draw.write("down to a square with a snake's tail that has a lower locate", 30, 22);
	_draw.write("score.", 30, 23);
	_draw.write("- If you are on a square with the ladder foot, you will move", 30, 24);
	_draw.write("onto a square with another ladder leg that has a higher", 30, 25);
	_draw.write("locate score.", 30, 26);
	_draw.write("GOOD LUCK :3 :3", 50, 27);
	_draw.write("->Press 0 to return to the menu<-", 43, 29);
	_draw.write("->Press 1 to go to the previous page<-", 41, 30);
	_draw.write("->Press any key to change color<-", 43, 31);
	char c = _getch();
	switch (c)
	{
	case '0':
	{
		menu();
		break;
	}
	case '1':
	{
		howtoplay1();
		break;
	}
	default:
	{
		while (true)
		{
			int t = _main.dice(1, 15);
			_draw.color(t);
			_draw.write("*HOW TO PLAY THIS GAME*", 47, 11);
			_draw.write("+ Rule +", 54, 12);
			_draw.write("- Locate scores are numbered on the squares on the board.", 30, 13);
			_draw.write("- If you get 100 points in locate first, you will win, your", 30, 14);
			_draw.write("score will increase by 1 point and you will play first if", 30, 15);
			_draw.write("you want to play again.", 30, 16);
			_draw.write("- If you get 6 when rolling the dice, you will be rolled", 30, 17);
			_draw.write("again after moving 6 squares, increasing 6 points in", 30, 18);
			_draw.write("position scores and moving down or moving up if you are", 30, 19);
			_draw.write("on a square with the snake head or the ladder foot.", 30, 20);
			_draw.write("- If you are on a square with the snake head, you will move", 30, 21);
			_draw.write("down to a square with a snake's tail that has a lower locate", 30, 22);
			_draw.write("score.", 30, 23);
			_draw.write("- If you are on a square with the ladder foot, you will move", 30, 24);
			_draw.write("onto a square with another ladder leg that has a higher", 30, 25);
			_draw.write("locate score.", 30, 26);
			_draw.write("GOOD LUCK :3 :3", 50, 27);
			_draw.write("->Press 0 to return to the menu<-", 43, 29);
			_draw.write("->Press 1 to go to the previous page<-", 41, 30);
			_draw.write("->Press any key to change color<-", 43, 31);
			char c1 = _getch();
			switch (c1)
			{
			case '0':
			{
				menu();
				break;
			}
			case '1':
			{
				howtoplay1();
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