#include "Point.h"



Point::Point()
{
	m_y = 0;
	m_x = 0;
}

Point::Point(const Point & pos)
{
	m_y = pos.m_y;
	m_x = pos.m_x;
}

Point::Point(int x, int y)
{
	m_y = y;
	m_x = x;
}


Point::~Point()
{
}

Point & Point::operator=(const Point & pos)
{
	this->m_y = pos.m_y;
	this->m_x = pos.m_x;

	return *this;
}

Point & Point::operator+(const Point & pos)
{
	this->m_x = this->m_x + pos.m_x;
	this->m_y = this->m_y + pos.m_y;
	return *this;
}

Point & Point::operator-(const Point & pos)
{
	this->m_x = this->m_x - pos.m_x;
	this->m_y = this->m_y - pos.m_y;
	return *this;
}

bool Point::operator==(const Point & pos)
{
	if (this->m_x == pos.m_x && this->m_y == pos.m_y)
		return true;
    return false;
}

bool Point::operator<(const Point &pos)
{
    if (this->m_x < pos.m_x && this->m_y < pos.m_y)
        return true;

    return false;
}

std::ostream & operator<<(std::ostream & os, const Point & a)
{
	os << "(" << a.m_x << "," << a.m_y << ")";
	return os;
}
