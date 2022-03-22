#include "OSFunc.h"
#include <windows.h>

#ifdef _WIN32   

void modeset(int w, int h) {
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD size = { w, h };
	SetConsoleScreenBufferSize(hOut, size);
	SMALL_RECT rc = { 1,1, w, h };
	SetConsoleWindowInfo(hOut, true, &rc);
	system("cls");
	return;
}
void sysInit()
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO CursorInfo;
	GetConsoleCursorInfo(handle, &CursorInfo);//��ȡ����̨�����Ϣ
	CursorInfo.bVisible = 0; //���ؿ���̨���
	SetConsoleCursorInfo(handle, &CursorInfo);//���ÿ���̨���״̬
	modeset(WIDTH, HEIGHT);
	system("cls");
}

void gotoxy(int x, int y)
{
	COORD c;
	c.X = x;
	c.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

void msleep(int ms)
{
	Sleep(ms);
}
#elif _UNIX
#endif 

