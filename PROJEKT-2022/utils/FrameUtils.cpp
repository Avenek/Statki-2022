#include "FrameUtils.h"
#include "CursorUtils.h"
#include <iostream>
#include <conio.h>
#include <windows.h>

using namespace std;

void FrameUtils::createFrame(string text, bool color = false, int n = 0) {
	createFrame(text, color, n, 0, 0);
}

void FrameUtils::createFrame(string text, bool color = false, int n = 0, int offsetX = 0, int offsetY = 0)
{
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);

	//RAMECZKOWE ZMIENNE//
	unsigned char LG = 201;
	unsigned char poziom = 205;
	unsigned char pion = 186;
	unsigned char LD = 200;
	unsigned char PG = 187;
	unsigned char PD = 188;
	int len = text.length();
	CursorUtils::setCursor(42 + offsetX, 1 + 6 * n + offsetY);
	if (color == false)
		SetConsoleTextAttribute(hOut, FOREGROUND_RED);
	else
		SetConsoleTextAttribute(hOut, FOREGROUND_GREEN);
	cout << LG;
	for (int a = 0; a < 30; a++)
		cout << poziom;
	cout << PG << endl;
	CursorUtils::setCursor(42 + offsetX, 2 + 6 * n + offsetY);
	cout << pion;
	CursorUtils::setCursor(73 + offsetX, 2 + 6 * n + offsetY);
	cout << pion << endl;
	CursorUtils::setCursor(42 + offsetX, 3 + 6 * n + offsetY);
	if (color == false)
		SetConsoleTextAttribute(hOut, FOREGROUND_RED);
	else
		SetConsoleTextAttribute(hOut, FOREGROUND_GREEN);
	cout << pion;
	if (color == false)
		SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_GREEN);
	else
		SetConsoleTextAttribute(hOut, FOREGROUND_BLUE);
	CursorUtils::setCursor(43 + offsetX + (31 - len) / 2, 3 + 6 * n + offsetY);
	cout << text;
	CursorUtils::setCursor(42 + offsetX + (30 - len) / 2, 3 + 6 * n + offsetY);
	if (color == false)
		SetConsoleTextAttribute(hOut, FOREGROUND_RED);
	else
		SetConsoleTextAttribute(hOut, FOREGROUND_GREEN);
	CursorUtils::setCursor(73 + offsetX, 3 + 6 * n + offsetY);
	cout << pion << endl;
	CursorUtils::setCursor(42 + offsetX, 4 + 6 * n + offsetY);
	cout << pion;
	CursorUtils::setCursor(73 + offsetX, 4 + 6 * n + offsetY);
	cout << pion << endl;
	CursorUtils::setCursor(42 + offsetX, 5 + 6 * n + offsetY);
	cout << LD;
	for (int a = 0; a < 30; a++)
		cout << poziom;
	cout << PD << endl;
	SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
}

void FrameUtils::createMovementListener(int& choose, bool& end, int number)
{
	unsigned char sign = 224;
	switch (sign)
	{
	case 0: //klawisze specjalne (czasem zero, czasem 224 - zale¿ne od pc'ta chyba)
	case 224: //klawisze specjalne
	{
		sign = _getch();
		if (sign == 72 && choose > 0 && number != 0) //strza³ka w górê
			choose -= 1;

		else if (sign == 80 && choose < number) //strza³ka w dó³
			choose += 1;
		else if (sign == 13) //ENTER
		{
			end = true;
			system("cls");
		}
	}
	}
}
