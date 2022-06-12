#include "Game.h"
#include "CursorUtils.h"
#include <iostream>
#include <random>
#include <windows.h>
#include <conio.h>
#include <string>
#include <ctime>
#include <fstream>

using namespace std;

void Game::createGame(GameType gameType, void(*frame)(string, bool, int), void(*moving)(int&, bool&, int n)) {
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	int choose{};
	bool color{}, end{};
	switch (gameType) {
	case VERSUS_PLAYER:
		frame("Tryb dla dwoch graczy", false, 0);
		aiMode = NONE;
		break;
	case VERSUS_COMPUTER:
		while (end == false) {
			CursorUtils::setCursor(1, 1);                                                //Wyœwietlenie menu g³ównego, poruszanie siê za pomoc¹ strza³ek, akcept enterem
			cout << endl << endl;
			choose == 0 ? color = true : color = false;
			frame("Powrot do menu", color, 0);
			choose == 1 ? color = true : color = false;
			frame("Tryb latwy", color, 1);
			choose == 2 ? color = true : color = false;
			frame("Tryb normalny", color, 2);
			choose == 3 ? color = true : color = false;
			frame("Tryb trudny", color, 3);
			moving(choose, end, 3);
		}
		//koniec funkcji, powrot do menu
		if (choose == 0) {
			return;
		}
		switch (choose) {
		case 3:
			aiMode = HARD;
			break;
		case 2:
			aiMode = MEDIUM;
			break;
		case 1:
		default:
			aiMode = EASY;
			break;
		}
		break;
	}

	SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
	string imie1, imie2;
	cout << "Podaj imie pierwszego gracza: ";
	cin >> imie1;														// Tryb dwuosobowy, podanie imion graczy.
	cout << endl;
	cout << "Podaj imie drugiego gracza: ";
	if (gameType == VERSUS_COMPUTER) {
		switch (aiMode) {
		case HARD:
			cout << "K";
			Sleep(300);
			cout << "a";
			Sleep(300);
			cout << "p";
			Sleep(300);
			cout << "i";
			Sleep(300);
			cout << "t";
			Sleep(300);
			cout << "a";
			Sleep(300);
			cout << "n";
			Sleep(1000);
			imie2 = "Kapitan";
			break;
		case MEDIUM:
			cout << "O";
			Sleep(300);
			cout << "m";
			Sleep(300);
			cout << "n";
			Sleep(300);
			cout << "i";
			Sleep(300);
			cout << "b";
			Sleep(300);
			cout << "u";
			Sleep(300);
			cout << "s";
			Sleep(1000);
			imie2 = "Omnibus";
			break;
		case EASY:
		default:
			cout << "K";
			Sleep(300);
			cout << "l";
			Sleep(300);
			cout << "o";
			Sleep(300);
			cout << "d";
			Sleep(300);
			cout << "n";
			Sleep(300);
			cout << "i";
			Sleep(300);
			cout << "c";
			Sleep(300);
			cout << "a";
			Sleep(1000);
			imie2 = "Klodnica";
			break;
		}
	}
	else {
		cin >> imie2;
	}
	system("cls");
}