#ifndef PILLAR_H
#define PILLAR_H

#include "Point.h"
class Pillar
{
public:
	Pillar();
	Pillar(int width);
	Pillar(int width, int interval);
	~Pillar();
	void setPos(const Point &pos);
	void draw();
	void setInterval(int interval);
	void setWidth(int width);

private:
	void randomHeight();

private:
	Point m_originPos;
	Point m_beforePos;
	int m_width;
	int m_interval;
	int m_height;
};
#endif
