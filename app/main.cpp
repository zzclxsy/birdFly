#include "../Framework/XCoreApplication.h"
#include "../Framework/XEvent/XTimerEvent.h"
#include <iostream>
#include "./birdFly/OSFunc.h"
#include "./birdFly/Point.h"
#include "./birdFly/Pillar.h"
#include "./birdFly/PillarManager.h"
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

int main(int argc, char *argv[])
{
    XCoreApplication a(argc, argv);

    sysInit();
    interfaceInit();

    PillarManager manager;
    manager.createPillar();

    XTimerEvent PillarCreateTimer;
    PillarCreateTimer.setTimer(3000, [&](){
        manager.createPillar();
    });
    PillarCreateTimer.start();


    XTimerEvent PillarMoveTimer;
    PillarMoveTimer.setTimer(100, [&](){
        manager.move();
    });
    PillarMoveTimer.start();


    a.exec();
}
