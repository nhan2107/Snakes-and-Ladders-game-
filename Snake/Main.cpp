#include "Welcome.h"

int main()
{
    Draw draw;
    Welcome Wel;
    Menu menu;
    Wel.opening();
    while (true)
    {
        menu.menu();
    }
    draw.gotoxy(35, 33);
    system("pause");
    return 0;
}