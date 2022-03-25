#include "GameCtrl.h"
#include<conio.h>

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

GameCtrl::GameCtrl()
{
    m_manager.createPillar();
    m_bird.setOriginPos(Point(20,20));
}

void GameCtrl::init()
{
    sysInit();
    interfaceInit();

    //柱子3秒产生一个
    m_PillarCreateTimer.setTimer(3000, [&](){
        m_manager.createPillar();
    });
    m_PillarCreateTimer.start();

    //50ms 移动一格
    m_PillarMoveTimer.setTimer(50, [&](){
        m_manager.move();
    });
    m_PillarMoveTimer.start();

    //100ms 移动小鸟，并碰撞检测
    m_birdMoveTimer.setTimer(100, [&](){
        m_bird.move();
        //检测碰撞
        if (m_manager.checkCrash(m_bird.getBirdRect()))
            gameOver();
    });
    m_birdMoveTimer.start();

    m_birdSpaceCheckTimer.setTimer(10, [&](){
        if (kbhit())
        {
            char ch = getch();
            if (ch == ' ')
            {
                m_bird.setJumpHeight(5);
            }
        }
    });
    m_birdSpaceCheckTimer.start();
}

void GameCtrl::gameOver()
{
    m_PillarCreateTimer.stop();
    m_PillarMoveTimer.stop();
    m_birdMoveTimer.stop();
    m_birdSpaceCheckTimer.stop();

    clear();

}
