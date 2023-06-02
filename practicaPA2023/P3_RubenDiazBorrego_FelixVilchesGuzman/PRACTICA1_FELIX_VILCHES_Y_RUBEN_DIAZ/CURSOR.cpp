#include "CURSOR.h"
#include <windows.h>


void situarCursor(int x, int y)
{
	HANDLE hCon;
	hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD cPunto;
	cPunto.X = x;
	cPunto.Y = y;
	SetConsoleCursorPosition(hCon, cPunto);
}

void ocultarCursor()
{
	HANDLE hCon;
	hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cInfo;
	cInfo.dwSize = 2;
	cInfo.bVisible = FALSE;
	SetConsoleCursorInfo(hCon, &cInfo);
}