#ifndef PILLARMANAGER_H
#define PILLARMANAGER_H
#include <vector>
#include "Pillar.h"
class PillarManager
{
public:
	PillarManager();
    ~PillarManager();
    void createPillar();
    void move();

private:
    std::vector<Pillar *> m_allPillar;
};
#endif
