#include "PillarManager.h"
#include "./birdFly/OSFunc.h"

PillarManager::PillarManager()
{
}


PillarManager::~PillarManager()
{
}

void PillarManager::createPillar()
{
    Pillar *pill = new Pillar(8,8);
    Point pos(WIDTH, 2);
    pill->setOriginPos(pos);

    m_allPillar.push_back(pill);
}

void PillarManager::move()
{
    //判断首个柱子是否死亡，死亡则删除;
    if (m_allPillar.front()->getDieStatus())
    {
        Pillar *pill = m_allPillar.front();
        m_allPillar.erase(m_allPillar.begin());
        delete pill;
    }

    for(Pillar *pill:m_allPillar)
    {
        pill->move();
    }
}

bool PillarManager::checkCrash(Rect birdRect)
{
    for(Pillar *pill:m_allPillar)
    {
        if (pill->getRectBottom().contain(birdRect) ||
                pill->getRectTop().contain(birdRect))
        {
            return true;
        }
    }

    return false;
}

void PillarManager::clear()
{
    for(Pillar *pill:m_allPillar)
    {
        delete pill;
    }
    m_allPillar.clear();
}
