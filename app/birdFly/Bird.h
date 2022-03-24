#ifndef BIRD_H
#define BIRD_H

#include "Point.h"

class Bird
{
public:
    Bird(Point originPos);
    void setJumpHeight(int height);
    void move();

private:
    void draw();

private:
    Point m_originPos;
    int m_jumpHeight;
};

#endif // BIRD_H
