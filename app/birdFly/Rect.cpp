#include "Rect.h"

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

bool Rect::contain(Rect &rect)
{
    if ((this->m_leftTop.x()+m_w) < (rect.m_leftTop.x())
           || (this->m_leftTop.y()+m_h) > (rect.m_leftTop.y())
            ||(rect.m_leftTop.x()+rect.m_w) < (this->m_leftTop.x())
            ||(rect.m_leftTop.y()+rect.m_h) > (this->m_leftTop.y()))
    {
        return false;
    }

    return true;
}
