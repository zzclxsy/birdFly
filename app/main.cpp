#include "../Framework/XCoreApplication.h"
#include "../Framework/XEvent/XTimerEvent.h"
#include <iostream>
#include<conio.h>
#include "./birdFly/OSFunc.h"
#include "./birdFly/Point.h"
#include "./birdFly/Pillar.h"
#include "./birdFly/PillarManager.h"
#include "./birdFly/Bird.h"
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
    //初始化系统
    sysInit();
    interfaceInit();

    //创建柱子
    PillarManager manager;
    manager.createPillar();
    //创建小鸟
    Bird bird(Point(20,20));

    XTimerEvent PillarCreateTimer;
    PillarCreateTimer.setTimer(3000, [&](){
        manager.createPillar();
    });
    PillarCreateTimer.start();

    XTimerEvent PillarMoveTimer;
    PillarMoveTimer.setTimer(50, [&](){
        manager.move();
    });
    PillarMoveTimer.start();

    XTimerEvent birdMoveTimer;
    birdMoveTimer.setTimer(100, [&](){
        bird.move();
        //检测碰撞
        if (manager.checkCrash(bird.getBirdRect()))
        {
            gotoxy(0,0);
            system("pause");
        }
    });
    birdMoveTimer.start();

    XTimerEvent birdSpaceCheckTimer;
    birdSpaceCheckTimer.setTimer(10, [&](){
        if (kbhit())
        {
            char ch = getch();
            if (ch == ' ')
            {
                bird.setJumpHeight(5);
            }
        }
    });
    birdSpaceCheckTimer.start();

    a.exec();
}
