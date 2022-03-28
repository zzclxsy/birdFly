#include "Rect.h"
#include <iostream>
#include "OSFunc.h"
Rect::Rect()
{

}

Rect::Rect(Point leftTop, int w, int h)
{
    m_leftTop = leftTop;
    m_w = w;
    m_h = h;
}

Rect &Rect::operator=(const Rect &rect)
{
    this->m_leftTop = rect.m_leftTop;
    this->m_h = rect.m_h;
    this->m_w = rect.m_w;

    return *this;
}

Point Rect::getTopLeft()
{
    return m_leftTop;
}

Point Rect::getBottomLeft()
{
    return Point(m_leftTop.x(),m_leftTop.y() + m_h);
}

bool Rect::contain(Rect &rect)
{
    Point p1(rect.m_leftTop);
    Point p2(rect.m_leftTop.x() + rect.m_w, rect.m_leftTop.y() +rect.m_h);

    Point p3(this->m_leftTop);
    Point p4(this->m_leftTop.x() + this->m_w, this->m_leftTop.y() +this->m_h);

    Point pM((p1.x() > p3.x()?p1.x():p3.x()),
             (p1.y() > p3.y()?p1.y():p3.y()));

    Point pN((p2.x() < p4.x()?p2.x():p4.x()),
             (p2.y() < p4.y()?p2.y():p4.y()));


    return pM < pN;
}
