#include "Game.h"
#include "utils/CursorUtils.h"
#include "utils/FrameUtils.h"
#include "map/MapGenerator.h"
#include <iostream>
#include <random>
#include <windows.h>
#include <conio.h>
#include <string>
#include <ctime>
#include <fstream>

using namespace std;

void Game::createGame(GameType gameType) {
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	int choose{};
	bool color{}, end{};
	switch (gameType) {
	case VERSUS_PLAYER:
		FrameUtils::createFrame("Tryb dla dwoch graczy", false, 0);
		aiMode = NONE;
		break;
	case VERSUS_COMPUTER:
		while (end == false) {
			CursorUtils::setCursor(1, 1);                                                //Wyœwietlenie menu g³ównego, poruszanie siê za pomoc¹ strza³ek, akcept enterem
			cout << endl << endl;
			FrameUtils::createFrame("Powrot do menu", choose == 0, 0);
			FrameUtils::createFrame("Tryb latwy", choose == 1, 1);
			FrameUtils::createFrame("Tryb normalny", choose == 2, 2);
			FrameUtils::createFrame("Tryb trudny", choose == 3, 3);
			FrameUtils::createMovementListener(choose, end, 3);
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
	cout << "Podaj imie pierwszego gracza: ";
	cin >> board1.playerName;														// Tryb dwuosobowy, podanie imion graczy.
	cout << endl;
	cout << "Podaj imie drugiego gracza: ";
	if (gameType == VERSUS_COMPUTER) {
		string names[3] = { "Kapitan", "Omnibus", "Klodnica" };
		string chosen;
		switch (aiMode) {
		case HARD:
			chosen = names[0];
			break;
		case MEDIUM:
			chosen = names[1];
			break;
		case EASY:
		default:
			chosen = names[2];
			break;
		}
		for (char ch : chosen) {
			cout << ch;
			Sleep(300);
		}
		Sleep(1000);
		board2.playerName = chosen;
	}
	else {
		cin >> board2.playerName;
	}
	system("cls");

	generateMap();
}

void Game::generateMap() {
	MapGenerator gen;
	gen.generateRandomMap(board1);
}