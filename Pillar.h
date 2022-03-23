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
    void setOriginPos(const Point &pos);
    void setSpeed(int speed);
    void move();
	void setInterval(int interval);
	void setWidth(int width);
    bool getDieStatus();
private:
	void randomHeight();
    void draw();

private:
	Point m_originPos;
	Point m_beforePos;
	int m_width;
	int m_interval;
	int m_height;
    int m_speed;
    bool mb_isDie;
};
#endif
