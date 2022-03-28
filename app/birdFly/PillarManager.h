#ifndef PILLARMANAGER_H
#define PILLARMANAGER_H
#include <vector>
#include "Pillar.h"
#include "Rect.h"
class PillarManager
{
public:
	PillarManager();
    ~PillarManager();
    void createPillar();
    void move();
    bool checkCrash(Rect birdRect);
    void clear();

private:
    std::vector<Pillar *> m_allPillar;
};
#endif
