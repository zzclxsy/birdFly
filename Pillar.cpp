#include "Pillar.h"
#include "OSFunc.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

#define PIRINT_BARRIER(width)	    \
for (int i = 0; i < width; i++)		\
{									\
	std::cout << "*";				\
}									\
std::cout << "\n";					\

#define CLS_BARRIER(width)	        \
for (int i = 0; i < width; i++)		\
{									\
	std::cout << " ";				\
}									\
std::cout << "\n";					\

#define random(x) rand()%(x)

Pillar::Pillar()
{
	m_width = 5;
    m_speed = 1;
    mb_isDie = false;
}

Pillar::Pillar(int width)
{
	m_width = width;
    m_speed = 1;
    mb_isDie = false;
}

Pillar::Pillar(int width, int interval)
{
	m_width = width;
	m_interval = interval;
    m_speed = 1;
    mb_isDie = false;
	randomHeight();
}


Pillar::~Pillar()
{
}

void Pillar::setOriginPos(const Point &pos)
{
    m_originPos = pos;
}

void Pillar::setSpeed(int speed)
{
    m_speed = speed;
}

void Pillar::move()
{
    m_originPos = m_originPos - Point(m_speed, 0);
    draw();
}

void Pillar::draw()
{
    if (mb_isDie)
        return;

	//�������
	int heightTop = m_height;
	Point beforePosTop = m_beforePos;
	if (!(beforePosTop == Point(0,0)))
	{
		gotoxy(beforePosTop.x(), beforePosTop.y());

		while (heightTop)
		{
			CLS_BARRIER(m_width)

			beforePosTop.setY(beforePosTop.y() + 1);
			gotoxy(beforePosTop.x(), beforePosTop.y());
			heightTop--;
		}

		int heightBottom = HEIGHT - m_interval - m_height - 4;
		Point beforePosBottom = Point(m_beforePos.x(), m_beforePos.y() + m_interval + m_height);
		gotoxy(beforePosBottom.x(), beforePosBottom.y());
		while (heightBottom)
		{
			CLS_BARRIER(m_width)

			beforePosBottom.setY(beforePosBottom.y() + 1);
			gotoxy(beforePosBottom.x(), beforePosBottom.y());
			heightBottom--;
		}
	}

	//�ƶ�����
    //�ж��Ƿ������ߣ�����������٣�ֱ��Ϊ0
    if (m_originPos.x() < 0)
    {
        if (m_width + m_originPos.x() <= 0)
        {
            mb_isDie = true;
            return;
        }
        m_width = m_width + m_originPos.x();
        m_originPos.setX(0);
    }
    //���Ӵ����ұ߲���, ����������ֱ��Ŀ�Ŀ��
    static int recordWidth = m_width;
    if (WIDTH - m_originPos.x() <= recordWidth)
    {
        m_width = WIDTH - m_originPos.x();
    }

	heightTop = m_height;
	Point originPosTop = m_originPos;
	gotoxy(originPosTop.x(), originPosTop.y());
	m_beforePos = originPosTop;
	while (heightTop)
	{
        PIRINT_BARRIER(m_width);

		originPosTop.setY(originPosTop.y() + 1);
		gotoxy(originPosTop.x(), originPosTop.y());
		heightTop--;
	}

	int heightBottom = HEIGHT - m_interval - m_height - 4;
	Point originPosBotttom = Point(m_originPos.x(), m_originPos.y() + m_interval + m_height);
	gotoxy(originPosBotttom.x(), originPosBotttom.y());
	while (heightBottom)
	{
        PIRINT_BARRIER(m_width);
		originPosBotttom.setY(originPosBotttom.y() + 1);
		gotoxy(originPosBotttom.x(), originPosBotttom.y());
		heightBottom--;
	}

}

void Pillar::setInterval(int interval)
{
	m_interval = interval;
	randomHeight();
}

void Pillar::setWidth(int width)
{
    m_width = width;
}

bool Pillar::getDieStatus()
{
    return mb_isDie;
}

void Pillar::randomHeight()
{
	srand((int)time(0));
	m_height = random(HEIGHT - m_interval - 5);
}

