#include "Draw.h"
void Draw::gotoxy(SHORT x, SHORT y)
{
	static HANDLE h = NULL;
	if (!h)
		h = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD c = { x, y };
	SetConsoleCursorPosition(h, c);
}
void Draw::fullscreen()
{
	FixConsoleWindow();
	system("mode con COLS=700");
	ShowWindow(GetConsoleWindow(), SW_MAXIMIZE);
	SendMessage(GetConsoleWindow(), WM_SYSKEYDOWN, VK_RETURN, 0x20000000);
}
void Draw::color(int k)
{
	HANDLE hConsoleColor;
	hConsoleColor = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsoleColor, k);
}
void Draw::colorBox(int clr, int row, int col, int x, int y)
{
	color(clr);
	for (int i = 0; i <= 3; i++) {
		printf("%c%c%c%c%c%c%c", 219, 219, 219, 219, 219, 219, 219);
		gotoxy(x, y++);
	}
}
void Draw::FixConsoleWindow()
{
	HWND consoleWindow = GetConsoleWindow();
	LONG style = GetWindowLong(consoleWindow, GWL_STYLE);
	style = style & ~(WS_MAXIMIZEBOX) & ~(WS_THICKFRAME);
	SetWindowLong(consoleWindow, GWL_STYLE, style);
}
void Draw::setFontSize(int FontSize)
{
	CONSOLE_FONT_INFOEX info = { 0 };
	info.cbSize = sizeof(info);
	info.dwFontSize.Y = FontSize;
	info.FontWeight = FW_NORMAL;
	SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), NULL, &info);
}
void Draw::line(short int k, int n, int clr, int& x, int& y)
{
	gotoxy(x, y);
	color(clr);
	if (k == 1)
	{
		for (int i = 1; i <= n; i++)
		{
			printf("%c", 196);
			x++;
		}
	}
	else if (k == 2)
	{
		for (int i = 1; i <= n; i++)
		{
			printf("%c", 179);
			y++;
			gotoxy(x, y);
		}
	}
	else if (k == 3)
	{
		for (int i = 1; i <= n; i++)
		{
			printf("%c", 205);
			x++;
		}
	}
	else
	{
		for (int i = 1; i <= n; i++)
		{
			printf("%c", 186);
			y++;
			gotoxy(x, y);
		}
	}
}
void Draw::colorbackground(int clr, int l, int w, int x, int y)
{
	color(clr);
	x = x + 1;
	y = y + 1;
	for (int i = 1; i <= l - 1; i++)
	{
		gotoxy(x, y);
		for (int j = 1; j <= w; j++)
		{
			cout << " ";
			y = y + 1;
			gotoxy(x, y);
		}
		x = x + 1;
		y = y - w;
	}
}
void Draw::quadrangle(bool t, int l, int w, int clrline, int clrbackground, int x, int y)
{
	if (t == 0)
	{
		line(1, l - 1, clrline, x, y);
		printf("%c", 191);
		y++;
		line(2, w, clrline, x, y);
		printf("%c", 217);
		x = x - l;
		line(1, l, clrline, x, y);
		x = x - l;
		y = y - w;
		line(2, w, clrline, x, y);
		printf("%c", 192);
		y = y - w - 1;
		gotoxy(x, y);
		printf("%c", 218);
		colorbackground(clrbackground, l, w, x, y);
	}
	else
	{
		line(3, l - 1, clrline, x, y);
		printf("%c", 187);
		y++;
		line(4, w, clrline, x, y);
		printf("%c", 188);
		x = x - l;
		line(3, l, clrline, x, y);
		x = x - l;
		y = y - w;
		line(4, w, clrline, x, y);
		printf("%c", 200);
		y = y - w - 1;
		gotoxy(x, y);
		printf("%c", 201);
		colorbackground(clrbackground, l, w, x, y);
	}
}
void Draw::write(string s, int x, int y)
{
	gotoxy(x, y);
	cout << s;
}
string Draw::ToStringNumber(int a)
{
	string t = "";
	if (a < 10)
	{
		t = "0" + to_string(a);
	}
	else t = to_string(a);
	return t;
}
char Draw::helpdraw(int x, int y)
{
	Draw a;
	char c = 219;
	if (30 == y || 15 == y)
	{
		switch (x)
		{
		case 35:case 70:
		{
			a.color(10);
			c = 219;
			break;
		}
		case 14:case 49:
		{
			a.color(15);
			c = 219;
			break;
		}
		case 21:case 56:
		{
			a.color(12);
			c = 219;
			break;
		}
		case 28:case 63:
		{
			a.color(9);
			c = 219;
			break;
		}
		case 7:case 42:
			a.color(14);
			c = 219;
			break;
		}
	}
	else if (27 == y || 12 == y)
	{
		switch (x)
		{
		case 14:case 49:
		{
			a.color(10);
			c = 219;
			break;
		}
		case 28:case 63:
		{
			if (28 == x && y == 27)
			{
				a.color(13);
				c = 178;
			}
			else
			{
				a.color(15);
				c = 219;
			}
			break;
		}
		case 35:case 70:
		{
			a.color(12);
			c = 219;
			break;
		}
		case 42:case 7:
		{
			a.color(9);
			c = 219;
			break;
		}
		case 21:case 56:
			a.color(14);
			c = 219;
			break;
		}
	}
	else if (24 == y || 9 == y)
	{
		switch (x)
		{
		case 28:case 63:
		{
			a.color(10);
			c = 219;
			break;
		}
		case 7:case 42:
		{
			if (24 == y && 7 == x)
			{
				a.color(8);
				c = 178;
			}
			else if (42 == x && 9 == y)
			{
				a.color(8);
				c = 187;
			}
			else
			{
				a.color(15);
				c = 219;
			}
			break;
		}
		case 14:case 49:
		{
			a.color(12);
			c = 219;
			break;
		}
		case 21:case 56:
		{
			a.color(9);
			c = 219;
			break;
		}
		case 70:case 35:
			if (9 == y && 35 == x)
			{
				a.color(8);
				c = 187;
			}
			else
			{
				a.color(14);
				c = 219;
			}
			break;
		}
	}
	else if (21 == y || 6 == y)
	{
		switch (x)
		{
		case 7:case 42:
		{
			if (21 == y && 7 == x)
			{
				a.color(8);
				c = 178;
			}
			else
			{
				a.color(10);
				c = 219;
			}
			break;
		}
		case 21:case 56:
		{
			if (56 == x && 6 == y)
			{
				a.color(13);
				c = 178;
			}
			else
			{
				a.color(15);
				c = 219;
			}
			break;
		}
		case 28:case 63:
		{
			a.color(12);
			c = 219;
			break;
		}
		case 35:case 70:
		{
			if (21 == y && 70 == x)
			{
				a.color(8);
				c = 201;
			}
			else if (7 == x && 6 == y)
			{
				a.color(8);
				c = 187;
			}
			else {
				a.color(9);
				c = 219;
			}
			break;
		}
		case 14:case 49:
			a.color(14);
			c = 219;
			break;
		}
	}
	else if (18 == y)
	{
		switch (x)
		{
		case 21:case 56:
		{
			a.color(10);
			c = 219;
			break;
		}
		case 70:case 35:
		{
			if (35 == x)
			{
				a.color(8);
				c = 187;
			}
			else
			{
				a.color(15);
				c = 219;
			}
			break;
		}
		case 7:case 42:
		{
			if (7 == x)
			{
				a.color(8);
				c = 178;
			}
			else
			{
				a.color(12);
				c = 219;
			}
			break;
		}
		case 49:case 14:
		{
			a.color(9);
			c = 219;
			break;
		}
		case 28:case 63:
			a.color(14);
			c = 219;
			break;
		}
	}
	else if (3 == y)
	{
		switch (x)
		{
		case 21:case 56:
		{
			a.color(10);
			c = 219;
			break;
		}
		case 70:case 35: case 14:
		{
			a.color(15);
			c = 219;
			break;
		}
		case 7:case 42:
		{
			a.color(12);
			c = 219;
			break;
		}
		case 49:
		{
			a.color(9);
			c = 219;
			break;
		}
		case 28:case 63:
			a.color(14);
			c = 219;
			break;
		}
	}
	return c;
}