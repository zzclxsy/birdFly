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
    m_score = 0;
}

void GameCtrl::init()
{
    sysInit();
    interfaceInit();

    //柱子3秒产生一个
    m_PillarCreateTimer.setTimer(3000,std::bind(&GameCtrl::createPillar,this));
    m_PillarCreateTimer.start();

    //50ms 移动一格
    m_PillarMoveTimer.setTimer(50,std::bind(&GameCtrl::movePillar,this));
    m_PillarMoveTimer.start();

    //100ms 移动小鸟，并碰撞检测
    m_birdMoveTimer.setTimer(100, std::bind(&GameCtrl::moveBird,this));
    m_birdMoveTimer.start();

    //键盘检测
    m_birdSpaceCheckTimer.setTimer(10, std::bind(&GameCtrl::keyboardCheck,this));
    m_birdSpaceCheckTimer.start();
}

void GameCtrl::gameOver()
{
    m_score = 0;
    m_PillarCreateTimer.stop();
    m_PillarMoveTimer.stop();
    m_birdMoveTimer.stop();
    m_birdSpaceCheckTimer.stop();

    gotoxy(0,0);
    setConsoleCursor(true);
    std::cout <<"You have died, do you want to restart the game\n";
    std::cout <<"input y to restart and n to end the game:";

    INPUT:
    char ch;
    scanf("%c",&ch);
    if (ch == 'y')
    {
        m_bird.setOriginPos(Point(20,20));
        clear();
        interfaceInit();
        m_manager.clear();
        m_PillarCreateTimer.start();
        m_PillarMoveTimer.start();
        m_birdMoveTimer.start();
        m_birdSpaceCheckTimer.start();
        setConsoleCursor(false);
    }
    else if (ch == 'n')
    {
        XCoreApplication::instant()->quit();
    }
    else
        goto INPUT;
}

void GameCtrl::createPillar()
{
    m_manager.createPillar();
}

void GameCtrl::movePillar()
{
    m_manager.move();
}

void GameCtrl::moveBird()
{
    m_bird.move();
    //检测碰撞
    if (m_manager.checkCrash(m_bird.getBirdRect()))
        gameOver();

    //上下墙壁
    if (m_bird.getBirdRect().getBottomLeft().y() >= HEIGHT - 2
            || m_bird.getBirdRect().getTopLeft().y() <= 1)
        gameOver();

    m_manager.calcScore(m_score);
    //显示分数
    gotoxy(WIDTH/2,0);
    std::cout << "score:"<<m_score;
}

void GameCtrl::keyboardCheck()
{
    if (kbhit())
    {
        char ch = getch();
        if (ch == ' ')
        {
            m_bird.setJumpHeight(5);
        }
    }
}
