#ifndef RECT_H
#define RECT_H

#include "Point.h"
class Rect
{
public:
    Rect();
    Rect(Point leftTop, int w, int h);
    Rect &operator= (const Rect &rect);

    Point getTopLeft();
    Point getBottomLeft();
    bool contain(Rect &rect);

private:
    Point m_leftTop;
    int m_w;
    int m_h;
};

#endif // RECT_H
