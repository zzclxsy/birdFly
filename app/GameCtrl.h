#ifndef GAMECTRL_H
#define GAMECTRL_H

#include "../Framework/XCoreApplication.h"
#include "../Framework/XEvent/XTimerEvent.h"
#include "./birdFly/OSFunc.h"
#include "./birdFly/Point.h"
#include "./birdFly/Pillar.h"
#include "./birdFly/PillarManager.h"
#include "./birdFly/Bird.h"

class GameCtrl
{
public:
    GameCtrl();
    void init();

private:
    void gameOver();

private:
    XTimerEvent m_PillarCreateTimer;
    XTimerEvent m_PillarMoveTimer;
    XTimerEvent m_birdMoveTimer;
    XTimerEvent m_birdSpaceCheckTimer;

    //��������
    PillarManager m_manager;
    //����С��
    Bird m_bird;
};

#endif // GAMECTRL_H
