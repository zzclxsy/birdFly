#ifndef POINT_H
#define POINT_H
#include<iostream>
class Point
{
public:
	Point();
	Point(const Point &pos);
	Point(int x, int y);
	~Point();

	Point &operator=(const Point &pos);
	Point &operator+(const Point &pos);
	Point &operator-(const Point &pos);
	bool operator==(const Point &pos);
    bool operator<(const Point &pos);
	friend std::ostream & operator<< (std::ostream & os, const Point & a);    // PointÊä³öÖØÔØ 
	
	int x() { return m_x;}
	int y() { return m_y;}

	void setY(int y) { m_y = y;}
	void setX(int x) { m_x = x;}
private:
	int m_x;
	int m_y;
};
#endif
