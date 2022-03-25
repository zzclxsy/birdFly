#include "Bird.h"
#include "OSFunc.h"
#include <iostream>
Bird::Bird(Point originPos)
{
    m_originPos = originPos;
    m_jumpHeight = 5;
}

void Bird::setOriginPos(Point originPos)
{
    m_originPos = originPos;
}

void Bird::setJumpHeight(int height)
{
    m_jumpHeight = height;
}

void Bird::move()
{
    if (m_jumpHeight != 0)
    {
        m_originPos.setY(m_originPos.y() - 1);
        m_jumpHeight --;
    }
    else if (m_jumpHeight == 0)
    {
        m_originPos.setY(m_originPos.y() + 1);
    }
    draw();
}

Rect Bird::getBirdRect()
{
    return Rect(m_originPos, 5,3);
}

void Bird::draw()
{
    //清除
    static Point beforePos;
    if (!(beforePos == Point(0,0)))
    {
        gotoxy(beforePos.x() + 1, beforePos.y());
        std::cout << " ";
        gotoxy(beforePos.x() + 1, beforePos.y() + 2);
        std::cout << " ";
        gotoxy(beforePos.x() + 1, beforePos.y() + 1);
        std::cout << "    ";
        gotoxy(beforePos.x() + 0, beforePos.y() + 1);
        std::cout << " ";
    }
    beforePos = m_originPos;
    gotoxy(m_originPos.x() + 1, m_originPos.y());
    std::cout << "$";
    gotoxy(m_originPos.x() + 1, m_originPos.y() + 2);
    std::cout << "$";
    gotoxy(m_originPos.x() + 1, m_originPos.y() + 1);
    std::cout << "#@3>";
    gotoxy(m_originPos.x() + 0, m_originPos.y() + 1);
    std::cout << ">";
}
