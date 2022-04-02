#include "Maingame.h"
int Maingame::dice(int min, int max)
{
	Random& rng = Random::instance();
	int n = rng.nextInt(min, max);
	return n;
}
void Maingame::main(string s)
{
	system("cls");
	_draw.setFontSize(21);
	_draw.gotoxy(1, 1);
	_board.colorboard(10, 10);
	int a = 1;
	int b = 28;
	_ladder.ladder1();
	_ladder.ladder2();
	_ladder.ladder3();
	_ladder.ladder4();
	_snake.snake1();
	_snake.snake2();
	_snake.snake3();
	_snake.snake4();
	_snake.snake5();
	_draw.color(112);
	for (int i = 1; i <= 100; i++)
	{
		_draw.write(to_string(i), a, b);
		if (i % 10 == 0)
		{
			b = b - 3;
		}
		else if ((i % 20) <= 10)
		{
			a = a + 7;
		}
		else a = a - 7;
	}
	_draw.color(15);
	_draw.gotoxy(70, 2);
	_draw.quadrangle(1, 33, 28, 15, 15, 75, 1);
	_draw.gotoxy(74, 10);
	printf("%c", 204);
	int x = 75;
	int y = 10;
	_draw.line(3, 32, 15, x, y);
	printf("%c", 185);
	_fo.open(s, _pl1, _pl2, _t);
	_draw.write(_pl1.name, 87, 2);
	_draw.write(_pl2.name, 95, 2);
	_draw.write("Score:", 77, 3);
	_draw.write("Locate:", 77, 4);
	_draw.write(_draw.ToStringNumber(_pl1.score), 87, 3);
	_draw.write(_draw.ToStringNumber(_pl2.score), 95, 3);
	_draw.write(_draw.ToStringNumber(_pl1.locate), 87, 4);
	_draw.write(_draw.ToStringNumber(_pl2.locate), 95, 4);
	_draw.gotoxy(74, 23);
	printf("%c", 204);
	x = 75;
	y = 23;
	_draw.line(3, 32, 15, x, y);
	printf("%c", 185);
	_draw.write("->2: Save with a name and", 75, 25);
	_draw.write("return to menu", 75, 26);
	_draw.write("->3: Save and return to menu", 75, 27);
	_draw.write("->4: Return to menu without save", 75, 28);
}