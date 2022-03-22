#include <iostream>
#include "OSFunc.h"
#include "Point.h"
#include "Pillar.h"

void interfaceInit()
{
	auto printFrame = []() {
		for (int i = 0; i <= WIDTH; i++)
		{
			std::cout << "=";
		}
		std::cout << "\n";
	};
	printFrame();
	gotoxy(0, 1);
	printFrame();
	gotoxy(0, HEIGHT - 2);
	printFrame();
	gotoxy(0, HEIGHT - 1);
	printFrame();
	gotoxy(0, 0);
}
int main()
{
    sysInit();
    interfaceInit();

    Pillar p;
    Point pos(WIDTH, 2);
    p.setInterval(5);
    p.setPos(pos);
    p.draw();

    while (1)
    {
        msleep(1000);
        pos = Point(pos.x() - 1, pos.y());
        p.setPos(pos);
        p.draw();
    }
}
