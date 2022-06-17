#pragma once
#include "Game.h"
#include "AiKnowledge.h"
#include "utils/CursorUtils.h"
#include "utils/FrameUtils.h"
#include "utils/SoundUtils.h"
#include "map/MapGenerator.h"
#include <iostream>
#include <random>
#include <windows.h>
#include <conio.h>
#include <string>
#include <ctime>
#include <fstream>

using namespace std;

//todo move me
int instrukcja = 0;

random_device randDev;
mt19937 randGen(randDev());
uniform_int_distribution<int> rowL(0, 9);
uniform_int_distribution<int> colL(0, 9);
uniform_int_distribution<int> directionL(0, 3);
uniform_int_distribution<int> whoStarts(0, 1);

void Game::createGame(GameType gameType) {
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	int choose{};
	bool color{}, end{};
	switch (gameType) {
	case VERSUS_PLAYER:
		FrameUtils::createFrame("Tryb dla dwoch graczy", false, 0);
		aiMode = NONE;
		versusPlayer = true;
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
		versusPlayer = false;
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

	Game game;
	game.aiMode = aiMode;
	game.versusPlayer = versusPlayer;
	generateMap(game);
}

void Game::generateMap(Game game) {
	MapGenerator gen;
	gen.chooseGenerationType(game, board1);
	game.board1 = board1;

	if (game.versusPlayer) {
		gen.chooseGenerationType(game, board2);
	}
	else {
		gen.generateRandomMap(game, board2, true);
	}
	game.board2 = board2;

	startGame(game);
}

void gapFillers(int num)
{
	for (int a = 0; a < num; a++)
		cout << " ";
}

void setShipShotColor(bool red) {
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	if (red) {
		SetConsoleTextAttribute(hOut, FOREGROUND_RED);
	}
	else {
		SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
	}
}

void renderShipsStatusHeader(Game game) {
	// RENDER ONE SPACE SHIPS
	setShipShotColor(game.board1.one1);
	cout << "  " << game.CHECK_MARK << "  ";
	setShipShotColor(game.board1.one2);
	cout << game.CHECK_MARK << "  ";
	setShipShotColor(game.board1.one3);
	cout << game.CHECK_MARK << "  ";
	setShipShotColor(game.board1.one4);
	cout << game.CHECK_MARK;

	gapFillers(96);

	setShipShotColor(game.board2.one1);
	cout << game.CHECK_MARK << "  ";
	setShipShotColor(game.board2.one2);
	cout << game.CHECK_MARK << "  ";
	setShipShotColor(game.board2.one3);
	cout << game.CHECK_MARK << "  ";
	setShipShotColor(game.board2.one4);
	cout << game.CHECK_MARK;

	cout << endl;

	//RENDER TWO SPACE SHIPS
	setShipShotColor(game.board1.two1);
	if (!game.board1.two1) {
		cout << "  " << game.CHECK_MARK << game.CHECK_MARK << "  ";
	}
	else {
		cout << game.CHECK_MARK << game.CHECK_MARK << "  ";
	}
	setShipShotColor(game.board1.two2);
	cout << game.CHECK_MARK << game.CHECK_MARK << "  ";
	setShipShotColor(game.board1.two3);
	cout << game.CHECK_MARK << game.CHECK_MARK;

	gapFillers(96);

	setShipShotColor(game.board2.two1);
	cout << game.CHECK_MARK << game.CHECK_MARK << "  ";
	setShipShotColor(game.board2.two2);
	cout << game.CHECK_MARK << game.CHECK_MARK << "  ";
	setShipShotColor(game.board2.two3);
	cout << game.CHECK_MARK << game.CHECK_MARK;

	cout << endl;

	//RENDER THREE SPACE SHIPS FOR PLAYER 1
	setShipShotColor(game.board1.three1);
	if (!game.board1.three1) {
		cout << "  " << game.CHECK_MARK << game.CHECK_MARK << game.CHECK_MARK << "  ";
	} else {
		cout << game.CHECK_MARK << game.CHECK_MARK << game.CHECK_MARK << "  ";
	}
	setShipShotColor(game.board1.three2);
	cout << game.CHECK_MARK << game.CHECK_MARK << game.CHECK_MARK;


	//RENDER PLAYER INFO AT THE CENTER
	int who = whoStarts(randGen);
	game.playerOneTurn = (who == 0);
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	Board chosenBoard;
	if (game.playerOneTurn) {
		chosenBoard = game.board1;
		SetConsoleTextAttribute(hOut, FOREGROUND_BLUE);
	}
	else {
		chosenBoard = game.board2;
		SetConsoleTextAttribute(hOut, FOREGROUND_BLUE | FOREGROUND_RED);
	}
	gapFillers(((120 - (game.board1.getPlayerNameLength() + 26)) / 2) - 10);

	cout << chosenBoard.playerName << ", to twoja tura! Strzelaj!";
	if ((chosenBoard.playerName.length() % 2) == 1)
		gapFillers(((120 - (chosenBoard.getPlayerNameLength() + 26)) / 2) - 11);
	else
		gapFillers(((120 - (chosenBoard.getPlayerNameLength() + 26)) / 2) - 10);


	//RENDER THREE SPACE SHIPS FOR PLAYER 2
	setShipShotColor(game.board2.three1);
	cout << game.CHECK_MARK << game.CHECK_MARK << game.CHECK_MARK << "  ";
	setShipShotColor(game.board2.three2);
	cout << game.CHECK_MARK << game.CHECK_MARK << game.CHECK_MARK;

	cout << endl;

	//RENDER FOUR SPACE SHIPS
	setShipShotColor(game.board1.four1);
	if (!game.board1.four1) {
		cout << "  " << game.CHECK_MARK << game.CHECK_MARK << game.CHECK_MARK << game.CHECK_MARK;
	}
	else {
		cout << game.CHECK_MARK << game.CHECK_MARK << game.CHECK_MARK << game.CHECK_MARK;
	}

	gapFillers(108);

	setShipShotColor(game.board2.four1);
	cout << game.CHECK_MARK << game.CHECK_MARK << game.CHECK_MARK << game.CHECK_MARK;

	cout << endl;
}

void renderBoards(Game game) {
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	gapFillers((60 - (game.board1.getPlayerNameLength() + 15)) / 2);
	cout << "Plansza gracza ";
	SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
	cout << game.board1.playerName;
	SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
	gapFillers((42 - ((game.board1.getPlayerNameLength() + game.board2.getPlayerNameLength()) / 2)));
	cout << "Plansza komputera ";
	SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
	cout << game.board2.playerName;
	SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
	cout << endl << endl;
	cout << "   ";

	for (char z = 65; z <= 74; z++)
	{
		SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
		cout << "    ";
		SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY | BACKGROUND_RED);
		cout << z;

	}
	SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY);
	cout << "      " << game.LINE_MARK << "   ";
	for (char x = 65; x <= 74; x++)
	{
		SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
		cout << "    ";
		SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY | BACKGROUND_RED);
		cout << x;

	}
	SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY);

	cout << endl << "                                                           " << game.LINE_MARK << endl;
	for (int i = 1; i <= 10; i++)
	{
		cout << "  ";
		SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY | BACKGROUND_RED);
		cout << i;

		// POKAZUJE KROPKI DO GRY 
		for (int j = 1; j <= 10; j++)
		{
			if (i == 10 && j == 1)
			{
				cout.width(4);
				SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
				cout << ".";
			}
			else
			{
				cout.width(5);
				SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
				cout << ".";
			}
		}
		SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY);
		cout << "      " << game.LINE_MARK << "   ";

		// POKAZUJE KROPKI DO GRY 
		for (int q = 1; q <= 10; q++)
		{
			if (i == 10 && q == 1)
			{
				cout.width(5);
				SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
				cout << ".";
			}
			else
			{
				cout.width(5);
				SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
				cout << ".";
			}
		}
		SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
		cout << "    ";
		SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY | BACKGROUND_RED);
		cout << i;
		SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY);


		cout << endl << "                                                           ";
		if (i != 10)
			cout << game.LINE_MARK;
		cout << endl;
	}
}

void getGameTime(Game game)
{
	HANDLE hOut;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	double czas = (game.stop - game.start) / 1000;
	int sekundy{};
	int minuty{};
	int godziny{};
	while (czas >= 60)
	{
		minuty += 1;
		czas -= 60;
	}
	while (minuty > 60)
	{
		godziny += 1;
		minuty -= 60;
	}
	sekundy = static_cast<int>(czas);
	SetConsoleTextAttribute(hOut, FOREGROUND_GREEN);
	cout << "Gra trwala ";
	if (godziny != 0)
	{
		cout << godziny;
		if (godziny == 0)
			cout << " godzin, ";
		else
			cout << " godzin, ";
	}
	cout << minuty;
	if (minuty == 0)
		cout << " minut i ";
	else if (minuty == 1)
		cout << " minute i ";
	else if (minuty == 2 || minuty == 3 || minuty == 4)
		cout << " minuty i ";
	else
		cout << " minut i ";
	cout << sekundy;
	if (sekundy == 0)
		cout << " sekund. ";
	else if (sekundy == 1)
		cout << " sekunde. ";
	else if (sekundy == 2 || sekundy == 3 || sekundy == 4)
		cout << " sekundy. ";
	else
		cout << " sekund. ";
	Sleep(8000);
	system("cls");

}

int columnToNumber(char col) {
	int column;
	if (col >= 65 && col <= 74)
	{
		column = static_cast<int>(col);
		column = column - 65;
	}
	else if (col >= 97 && col <= 106)
	{
		column = static_cast<int>(col);
		column = column - 97;
	}
	else
		column = static_cast<int>(col);
	return column;
}

void askForInput(Game game) {
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
	int czworka = 0;
	int czworka2 = 0;
	int playRow{};
	int playColumn{};
	bool koniec_gry = false;
	AiKnowledge ai = AiKnowledge();

	while (koniec_gry == false)
	{
		if (game.playerOneTurn)
		{
			cout << "  Podaj kolumne (A-J), a nastepnie wiersz(1-10): ";
			char ch;
			cin >> ch;
			playColumn = columnToNumber(ch);

			gapFillers(48);
			cin >> playRow;
			playRow = playRow - 1;
		}
		else
		{

			gapFillers(65);
			cout << "  Podaj kolumne (A-J), a nastepnie wiersz(1-10): ";

			if (!game.versusPlayer)
			{
				ai.guessPosition(game, playColumn, playRow);

				if (playColumn == 0) cout << "A";
				else if (playColumn == 1) cout << "B";
				else if (playColumn == 2) cout << "C";
				else if (playColumn == 3) cout << "D";
				else if (playColumn == 4) cout << "E";
				else if (playColumn == 5) cout << "F";
				else if (playColumn == 6) cout << "G";
				else if (playColumn == 7) cout << "H";
				else if (playColumn == 8) cout << "I";
				else if (playColumn == 9) cout << "J";
				Sleep(1000);
				cout << playRow + 1;
				Sleep(1500);
			}
			else {
				char ch;
				cin >> ch;
				playColumn = columnToNumber(ch);

				gapFillers(48);
				cin >> playRow;
				playRow = playRow - 1;
			}
		}

		system("cls");

		if (!game.playerOneTurn)
		{
			if (playRow > 9 || playColumn > 9 || playRow < 0 || playColumn < 0)
			{
				setShipShotColor(game.board1.one1);
				cout << "  " << game.CHECK_MARK << "  ";
				setShipShotColor(game.board1.one2);
				cout << game.CHECK_MARK << "  ";
				setShipShotColor(game.board1.one3);
				cout << game.CHECK_MARK << "  ";
				setShipShotColor(game.board1.one4);
				cout << game.CHECK_MARK;

				SetConsoleTextAttribute(hOut, FOREGROUND_RED);
				gapFillers(5);
				cout << "Dokonales zlego wyboru! Nie przechodz na ciemna strone mocy i wybierz wlasciwa cyfre!";
				cin.clear();
				cin.ignore(100, '\n');
				gapFillers(6);
				SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
			}
			else if (game.board1.gameBoard[playRow][playColumn] == 5 || game.board1.gameBoard[playRow][playColumn] == 6)
			{
				setShipShotColor(game.board1.one1);
				cout << "  " << game.CHECK_MARK << "  ";
				setShipShotColor(game.board1.one2);
				cout << game.CHECK_MARK << "  ";
				setShipShotColor(game.board1.one3);
				cout << game.CHECK_MARK << "  ";
				setShipShotColor(game.board1.one4);
				cout << game.CHECK_MARK;

				SetConsoleTextAttribute(hOut, FOREGROUND_RED);
				gapFillers(22);
				cout << "Przeciez juz tutaj strzelales! Sprobuj jeszcze raz.";
				gapFillers(23);
				SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
			}
			else
			{
				if (game.board1.gameBoard[playRow][playColumn] != 1)
				{
					setShipShotColor(game.board1.one1);
					cout << "  " << game.CHECK_MARK << "  ";
					setShipShotColor(game.board1.one2);
					cout << game.CHECK_MARK << "  ";
					setShipShotColor(game.board1.one3);
					cout << game.CHECK_MARK << "  ";
					setShipShotColor(game.board1.one4);
					cout << game.CHECK_MARK;
				}

				if (game.board1.gameBoard[playRow][playColumn] == -1 || game.board1.gameBoard[playRow][playColumn] == 0)
				{
					if (game.effects)
						SoundUtils::playSound("empty");
					game.board1.gameBoard[playRow][playColumn] = 5;
					SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
					gapFillers(17);
					cout << "PUSTO ;c";
					gapFillers(71);
				}
				else if (game.board1.gameBoard[playRow][playColumn] == 1)
				{
					game.board1.gameBoard[playRow][playColumn] = 6;
					for (int a = 0; a < 3; a++)
					{
						for (int b = 0; b < 3; b++)
						{
							if (playColumn - 1 + a >= 0 && playColumn - 1 + a <= 9 && playRow - 1 + b >= 0 && playRow - 1 + b <= 9 && game.board1.gameBoard[playRow - 1 + b][playColumn - 1 + a] == -1)
								game.board1.gameBoard[playRow - 1 + b][playColumn - 1 + a] = 5;
						}
					}
					if (game.board1.one1 == false) game.board1.one1 = true;
					else if (game.board1.one1 == true && game.board1.one2 == false) game.board1.one2 = true;
					else if (game.board1.one1 == true && game.board1.one2 == true && game.board1.one3 == false) game.board1.one3 = true;
					else if (game.board1.one1 == true && game.board1.one2 == true && game.board1.one3 == true) game.board1.one4 = true;

					setShipShotColor(game.board1.one1);
					cout << "  " << game.CHECK_MARK << "  ";
					setShipShotColor(game.board1.one2);
					cout << game.CHECK_MARK << "  ";
					setShipShotColor(game.board1.one3);
					cout << game.CHECK_MARK << "  ";
					setShipShotColor(game.board1.one4);
					cout << game.CHECK_MARK;

					SetConsoleTextAttribute(hOut, FOREGROUND_GREEN);
					gapFillers(11);
					cout << "TRAFIONY, ZATOPIONY!";
					if (game.effects)
						SoundUtils::playSound("hit");
					gapFillers(65);

				}
				else if (game.board1.gameBoard[playRow][playColumn] == 2)
				{
					game.board1.gameBoard[playRow][playColumn] = 6;

					if (game.board1.gameBoard[playRow + 1][playColumn] != 6 && game.board1.gameBoard[playRow - 1][playColumn] != 6 && game.board1.gameBoard[playRow][playColumn + 1] != 6 && game.board1.gameBoard[playRow][playColumn - 1] != 6)
					{

						SetConsoleTextAttribute(hOut, FOREGROUND_RED);
						gapFillers(17);
						cout << "TRAFIONY!";
						if (game.effects)
							SoundUtils::playSound("hit");
						ai.onHit(game, playColumn, playRow);
						gapFillers(70);
					}
					else if (game.board1.gameBoard[playRow + 1][playColumn] == 6)
					{
						for (int a = 0; a < 3; a++)
						{
							for (int b = 0; b < 4; b++)
							{
								if (playColumn - 1 + a >= 0 && playColumn - 1 + a <= 9 && playRow - 1 + b >= 0 && playRow - 1 + b <= 9 && game.board1.gameBoard[playRow - 1 + b][playColumn - 1 + a] == -1)
									game.board1.gameBoard[playRow - 1 + b][playColumn - 1 + a] = 5;
							}
						}

						SetConsoleTextAttribute(hOut, FOREGROUND_GREEN);
						gapFillers(11);
						cout << "TRAFIONY, ZATOPIONY!";
						if (game.effects)
							SoundUtils::playSound("sunk");
						ai.resetData(game);
						gapFillers(65);
						if (game.board1.two1 == false) game.board1.two1 = true;
						else if (game.board1.two1 == true && game.board1.two2 == false) game.board1.two2 = true;
						else if (game.board1.two1 == true && game.board1.two2 == true) game.board1.two3 = true;

					}
					else if (game.board1.gameBoard[playRow][playColumn + 1] == 6)
					{
						for (int a = 0; a < 3; a++)
						{
							for (int b = 0; b < 4; b++)
							{
								if (playRow - 1 + a >= 0 && playRow - 1 + a <= 9 && playColumn - 1 + b >= 0 && playColumn - 1 + b <= 9 && game.board1.gameBoard[playRow - 1 + a][playColumn - 1 + b] == -1)
									game.board1.gameBoard[playRow - 1 + a][playColumn - 1 + b] = 5;
							}
						}

						SetConsoleTextAttribute(hOut, FOREGROUND_GREEN);
						gapFillers(11);
						cout << "TRAFIONY, ZATOPIONY!";
						if (game.effects)
							SoundUtils::playSound("sunk");
						ai.resetData(game);
						gapFillers(65);
						if (game.board1.two1 == false) game.board1.two1 = true;
						else if (game.board1.two1 == true && game.board1.two2 == false) game.board1.two2 = true;
						else if (game.board1.two1 == true && game.board1.two2 == true) game.board1.two3 = true;
					}
					else if (game.board1.gameBoard[playRow - 1][playColumn] == 6)
					{
						for (int a = 0; a < 3; a++)
						{
							for (int b = 0; b < 4; b++)
							{
								if (playColumn - 1 + a >= 0 && playColumn - 1 + a <= 9 && playRow + 1 - b >= 0 && playRow + 1 - b <= 9 && game.board1.gameBoard[playRow + 1 - b][playColumn - 1 + a] == -1)
									game.board1.gameBoard[playRow + 1 - b][playColumn - 1 + a] = 5;
							}
						}

						SetConsoleTextAttribute(hOut, FOREGROUND_GREEN);
						gapFillers(11);
						cout << "TRAFIONY, ZATOPIONY!";
						if (game.effects)
							SoundUtils::playSound("sunk");
						ai.resetData(game);
						gapFillers(65);
						if (game.board1.two1 == false) game.board1.two1 = true;
						else if (game.board1.two1 == true && game.board1.two2 == false) game.board1.two2 = true;
						else if (game.board1.two1 == true && game.board1.two2 == true) game.board1.two3 = true;
					}
					else if (game.board1.gameBoard[playRow][playColumn - 1] == 6)
					{
						for (int a = 0; a < 3; a++)
						{
							for (int b = 0; b < 4; b++)
							{
								if (playRow - 1 + a >= 0 && playRow - 1 + a <= 9 && playColumn + 1 - b >= 0 && playColumn + 1 - b <= 9 && game.board1.gameBoard[playRow - 1 + a][playColumn + 1 - b] == -1)
									game.board1.gameBoard[playRow - 1 + a][playColumn + 1 - b] = 5;
							}
						}

						SetConsoleTextAttribute(hOut, FOREGROUND_GREEN);
						gapFillers(11);
						cout << "TRAFIONY, ZATOPIONY!";
						if (game.effects)
							SoundUtils::playSound("sunk");
						ai.resetData(game);
						gapFillers(65);
						if (game.board1.two1 == false) game.board1.two1 = true;
						else if (game.board1.two1 == true && game.board1.two2 == false) game.board1.two2 = true;
						else if (game.board1.two1 == true && game.board1.two2 == true) game.board1.two3 = true;
					}
				}
				else if (game.board1.gameBoard[playRow][playColumn] == 3)
				{
					game.board1.gameBoard[playRow][playColumn] = 6;

					if (game.board1.gameBoard[playRow - 1][playColumn] == 3 && game.board1.gameBoard[playRow - 2][playColumn] == 3
						|| game.board1.gameBoard[playRow - 1][playColumn] == 6 && game.board1.gameBoard[playRow - 2][playColumn] == 3
						|| game.board1.gameBoard[playRow - 1][playColumn] == 3 && game.board1.gameBoard[playRow - 2][playColumn] == 6)
					{

						SetConsoleTextAttribute(hOut, FOREGROUND_RED);
						gapFillers(17);
						cout << "TRAFIONY!";
						if (game.effects)
							SoundUtils::playSound("hit");
						ai.onHit(game, playColumn, playRow);
						gapFillers(70);
					}
					else if (game.board1.gameBoard[playRow - 1][playColumn] == 6 && game.board1.gameBoard[playRow - 2][playColumn] == 6)
					{
						for (int a = 0; a < 3; a++)
						{
							for (int b = 0; b < 5; b++)
							{
								if (playColumn - 1 + a >= 0 && playColumn - 1 + a <= 9 && playRow + 1 - b >= 0 && playRow + 1 - b <= 9 && game.board1.gameBoard[playRow + 1 - b][playColumn - 1 + a] == -1)
									game.board1.gameBoard[playRow + 1 - b][playColumn - 1 + a] = 5;
							}


						}

						SetConsoleTextAttribute(hOut, FOREGROUND_GREEN);
						gapFillers(11);
						cout << "TRAFIONY, ZATOPIONY!";
						if (game.effects)
							SoundUtils::playSound("hit");
						ai.resetData(game);
						gapFillers(65);
						if (game.board1.three1 == false) game.board1.three1 = true;
						else if (game.board1.three1 == true) game.board1.three2 = true;
					}

					else if ((game.board1.gameBoard[playRow - 1][playColumn] == 3 && game.board1.gameBoard[playRow + 1][playColumn] == 3)
						|| (game.board1.gameBoard[playRow - 1][playColumn] == 6 && game.board1.gameBoard[playRow + 1][playColumn] == 3)
						|| (game.board1.gameBoard[playRow - 1][playColumn] == 3 && game.board1.gameBoard[playRow + 1][playColumn] == 6))
					{

						SetConsoleTextAttribute(hOut, FOREGROUND_RED);
						gapFillers(17);
						cout << "TRAFIONY!";
						if (game.effects)
							SoundUtils::playSound("hit");
						ai.onHit(game, playColumn, playRow);
						gapFillers(70);
					}
					else if (game.board1.gameBoard[playRow - 1][playColumn] == 6 && game.board1.gameBoard[playRow + 1][playColumn] == 6)
					{
						for (int a = 0; a < 3; a++)
						{
							for (int b = 0; b < 5; b++)
							{
								if (playColumn - 1 + a >= 0 && playColumn - 1 + a <= 9 && playRow + 2 - b >= 0 && playRow + 2 - b <= 9 && game.board1.gameBoard[playRow + 2 - b][playColumn - 1 + a] == -1)
									game.board1.gameBoard[playRow + 2 - b][playColumn - 1 + a] = 5;
							}
						}

						SetConsoleTextAttribute(hOut, FOREGROUND_GREEN);
						gapFillers(11);
						cout << "TRAFIONY, ZATOPIONY!";
						if (game.effects)
							SoundUtils::playSound("sunk");
						ai.resetData(game);
						gapFillers(65);
						if (game.board1.three1 == false) game.board1.three1 = true;
						else if (game.board1.three1 == true) game.board1.three2 = true;
					}
					else if ((game.board1.gameBoard[playRow + 1][playColumn] == 3 && game.board1.gameBoard[playRow + 2][playColumn] == 3)
						|| (game.board1.gameBoard[playRow + 1][playColumn] == 6 && game.board1.gameBoard[playRow + 2][playColumn] == 3)
						|| (game.board1.gameBoard[playRow + 1][playColumn] == 3 && game.board1.gameBoard[playRow + 2][playColumn] == 6))
					{

						SetConsoleTextAttribute(hOut, FOREGROUND_RED);
						gapFillers(17);
						cout << "TRAFIONY!";
						if (game.effects)
							SoundUtils::playSound("hit");
						ai.onHit(game, playColumn, playRow);
						gapFillers(70);
					}
					else if (game.board1.gameBoard[playRow + 1][playColumn] == 6 && game.board1.gameBoard[playRow + 2][playColumn] == 6)
					{
						for (int a = 0; a < 3; a++)
						{
							for (int b = 0; b < 5; b++)
							{
								if (playColumn - 1 + a >= 0 && playColumn - 1 + a <= 9 && playRow - 1 + b >= 0 && playRow - 1 + b <= 9 && game.board1.gameBoard[playRow - 1 + b][playColumn - 1 + a] == -1)
									game.board1.gameBoard[playRow - 1 + b][playColumn - 1 + a] = 5;
							}
						}

						SetConsoleTextAttribute(hOut, FOREGROUND_GREEN);
						gapFillers(11);
						cout << "TRAFIONY, ZATOPIONY!";
						if (game.effects)
							SoundUtils::playSound("sunk");
						ai.resetData(game);
						gapFillers(65);
						if (game.board1.three1 == false) game.board1.three1 = true;
						else if (game.board1.three1 == true) game.board1.three2 = true;
					}

					else if ((game.board1.gameBoard[playRow][playColumn + 1] == 3 && game.board1.gameBoard[playRow][playColumn + 2] == 3)
						|| (game.board1.gameBoard[playRow][playColumn + 1] == 6 && game.board1.gameBoard[playRow][playColumn + 2] == 3)
						|| (game.board1.gameBoard[playRow][playColumn + 1] == 3 && game.board1.gameBoard[playRow][playColumn + 2] == 6))
					{

						SetConsoleTextAttribute(hOut, FOREGROUND_RED);
						gapFillers(17);
						cout << "TRAFIONY!";
						if (game.effects)
							SoundUtils::playSound("hit");
						ai.onHit(game, playColumn, playRow);
						gapFillers(70);
					}
					else if (game.board1.gameBoard[playRow][playColumn + 1] == 6 && game.board1.gameBoard[playRow][playColumn + 2] == 6)
					{
						for (int a = 0; a < 3; a++)
						{
							for (int b = 0; b < 5; b++)
							{
								if (playColumn - 1 + b >= 0 && playColumn - 1 + b <= 9 && playRow - 1 + a >= 0 && playRow - 1 + a <= 9 && game.board1.gameBoard[playRow - 1 + a][playColumn - 1 + b] == -1)
									game.board1.gameBoard[playRow - 1 + a][playColumn - 1 + b] = 5;
							}
						}

						SetConsoleTextAttribute(hOut, FOREGROUND_GREEN);
						gapFillers(11);
						cout << "TRAFIONY, ZATOPIONY!";
						if (game.effects)
							SoundUtils::playSound("sunk");
						ai.resetData(game);
						gapFillers(65);
						if (game.board1.three1 == false) game.board1.three1 = true;
						else if (game.board1.three1 == true) game.board1.three2 = true;
					}

					else if ((game.board1.gameBoard[playRow][playColumn - 1] == 3 && game.board1.gameBoard[playRow][playColumn + 1] == 3)
						|| (game.board1.gameBoard[playRow][playColumn - 1] == 6 && game.board1.gameBoard[playRow][playColumn + 1] == 3)
						|| (game.board1.gameBoard[playRow][playColumn - 1] == 3 && game.board1.gameBoard[playRow][playColumn + 1] == 6))
					{

						SetConsoleTextAttribute(hOut, FOREGROUND_RED);
						gapFillers(17);
						cout << "TRAFIONY!";
						if (game.effects)
							SoundUtils::playSound("hit");
						ai.onHit(game, playColumn, playRow);
						gapFillers(70);
					}
					else if (game.board1.gameBoard[playRow][playColumn - 1] == 6 && game.board1.gameBoard[playRow][playColumn + 1] == 6)
					{
						for (int a = 0; a < 3; a++)
						{
							for (int b = 0; b < 5; b++)
							{
								if (playColumn - 2 + b >= 0 && playColumn - 2 + b <= 9 && playRow - 1 + a >= 0 && playRow - 1 + a <= 9 && game.board1.gameBoard[playRow - 1 + a][playColumn - 2 + b] == -1)
									game.board1.gameBoard[playRow - 1 + a][playColumn - 2 + b] = 5;
							}
						}

						SetConsoleTextAttribute(hOut, FOREGROUND_GREEN);
						gapFillers(11);
						cout << "TRAFIONY, ZATOPIONY!";
						if (game.effects)
							SoundUtils::playSound("sunk");
						ai.resetData(game);
						gapFillers(65);
						if (game.board1.three1 == false) game.board1.three1 = true;
						else if (game.board1.three1 == true) game.board1.three2 = true;
					}
					else if ((game.board1.gameBoard[playRow][playColumn - 1] == 3 && game.board1.gameBoard[playRow][playColumn - 2] == 3)
						|| (game.board1.gameBoard[playRow][playColumn - 1] == 6 && game.board1.gameBoard[playRow][playColumn - 2] == 3)
						|| (game.board1.gameBoard[playRow][playColumn - 1] == 3 && game.board1.gameBoard[playRow][playColumn - 2] == 6))
					{

						SetConsoleTextAttribute(hOut, FOREGROUND_RED);
						gapFillers(17);
						cout << "TRAFIONY!";
						if (game.effects)
							SoundUtils::playSound("hit");
						ai.onHit(game, playColumn, playRow);
						gapFillers(70);
					}
					else if (game.board1.gameBoard[playRow][playColumn - 1] == 6 && game.board1.gameBoard[playRow][playColumn - 2] == 6)
					{
						for (int a = 0; a < 3; a++)
						{
							for (int b = 0; b < 5; b++)
							{
								if (playColumn - 3 + b >= 0 && playColumn - 3 + b <= 9 && playRow - 1 + a >= 0 && playRow - 1 + a <= 9 && game.board1.gameBoard[playRow - 1 + a][playColumn - 3 + b] == -1)
									game.board1.gameBoard[playRow - 1 + a][playColumn - 3 + b] = 5;
							}
						}

						SetConsoleTextAttribute(hOut, FOREGROUND_GREEN);
						gapFillers(11);
						cout << "TRAFIONY, ZATOPIONY!";
						if (game.effects)
							SoundUtils::playSound("sunk");
						ai.resetData(game);
						gapFillers(65);
						if (game.board1.three1 == false) game.board1.three1 = true;
						else if (game.board1.three1 == true) game.board1.three2 = true;
					}

				}
				else if (game.board1.gameBoard[playRow][playColumn] == 4)
				{
					game.board1.gameBoard[playRow][playColumn] = 6;
					czworka++;
					if (czworka != 4)
					{

						SetConsoleTextAttribute(hOut, FOREGROUND_RED);
						gapFillers(17);
						cout << "TRAFIONY!";
						if (game.effects)
							SoundUtils::playSound("hit");
						ai.onHit(game, playColumn, playRow);
						gapFillers(70);
					}
					else if (czworka == 4)
					{
						if (game.board1.gameBoard[playRow][playColumn + 1] == 6 && game.board1.gameBoard[playRow][playColumn + 2] == 6 && game.board1.gameBoard[playRow][playColumn + 3] == 6)
						{
							for (int a = 0; a < 3; a++)
							{
								for (int b = 0; b < 6; b++)
								{
									if (playRow - 1 + a >= 0 && playRow - 1 + a <= 9 && playColumn - 1 + b >= 0 && playColumn - 1 + b <= 9 && game.board1.gameBoard[playRow - 1 + a][playColumn - 1 + b] == -1)
										game.board1.gameBoard[playRow - 1 + a][playColumn - 1 + b] = 5;
								}
							}

							SetConsoleTextAttribute(hOut, FOREGROUND_GREEN);
							gapFillers(11);
							cout << "TRAFIONY, ZATOPIONY!";
							if (game.effects)
								SoundUtils::playSound("sunk");
							ai.resetData(game);
							gapFillers(65);
							game.board1.four1 = true;
						}
						else if (game.board1.gameBoard[playRow][playColumn - 1] == 6 && game.board1.gameBoard[playRow][playColumn + 1] == 6 && game.board1.gameBoard[playRow][playColumn + 2] == 6)
						{
							for (int a = 0; a < 3; a++)
							{
								for (int b = 0; b < 6; b++)
								{
									if (playRow - 1 + a >= 0 && playRow - 1 + a <= 9 && playColumn - 2 + b >= 0 && playColumn - 2 + b <= 9 && game.board1.gameBoard[playRow - 1 + a][playColumn - 2 + b] == -1)
										game.board1.gameBoard[playRow - 1 + a][playColumn - 2 + b] = 5;
								}
							}

							SetConsoleTextAttribute(hOut, FOREGROUND_GREEN);
							gapFillers(11);
							cout << "TRAFIONY, ZATOPIONY!";
							if (game.effects)
								SoundUtils::playSound("sunk");
							ai.resetData(game);
							gapFillers(65);
							game.board1.four1 = true;
						}
						else if (game.board1.gameBoard[playRow][playColumn - 1] == 6 && game.board1.gameBoard[playRow][playColumn - 2] == 6 && game.board1.gameBoard[playRow][playColumn - 3] == 6)
						{
							for (int a = 0; a < 3; a++)
							{
								for (int b = 0; b < 6; b++)
								{
									if (playRow - 1 + a >= 0 && playRow - 1 + a <= 9 && playColumn + 1 - b >= 0 && playColumn + 1 - b <= 9 && game.board1.gameBoard[playRow - 1 + a][playColumn + 1 - b] == -1)
										game.board1.gameBoard[playRow - 1 + a][playColumn + 1 - b] = 5;
								}
							}

							SetConsoleTextAttribute(hOut, FOREGROUND_GREEN);
							gapFillers(11);
							cout << "TRAFIONY, ZATOPIONY!";
							if (game.effects)
								SoundUtils::playSound("sunk");
							ai.resetData(game);
							gapFillers(65);
							game.board1.four1 = true;
						}
						else if (game.board1.gameBoard[playRow][playColumn - 1] == 6 && game.board1.gameBoard[playRow][playColumn + 1] == 6 && game.board1.gameBoard[playRow][playColumn - 2] == 6)
						{
							for (int a = 0; a < 3; a++)
							{
								for (int b = 0; b < 6; b++)
								{
									if (playRow - 1 + a >= 0 && playRow - 1 + a <= 9 && playColumn + 2 - b >= 0 && playColumn + 2 - b <= 9 && game.board1.gameBoard[playRow - 1 + a][playColumn + 2 - b] == -1)
										game.board1.gameBoard[playRow - 1 + a][playColumn + 2 - b] = 5;
								}
							}

							SetConsoleTextAttribute(hOut, FOREGROUND_GREEN);
							gapFillers(11);
							cout << "TRAFIONY, ZATOPIONY!";
							if (game.effects)
								SoundUtils::playSound("sunk");
							ai.resetData(game);
							gapFillers(65);
							game.board1.four1 = true;
						}
						else if (game.board1.gameBoard[playRow + 1][playColumn] == 6 && game.board1.gameBoard[playRow + 2][playColumn] == 6 && game.board1.gameBoard[playRow + 3][playColumn] == 6)
						{
							for (int a = 0; a < 3; a++)
							{
								for (int b = 0; b < 6; b++)
								{
									if (playColumn - 1 + a >= 0 && playColumn - 1 + a <= 9 && playRow - 1 + b >= 0 && playRow - 1 + b <= 9 && game.board1.gameBoard[playRow - 1 + b][playColumn - 1 + a] == -1)
										game.board1.gameBoard[playRow - 1 + b][playColumn - 1 + a] = 5;
								}
							}

							SetConsoleTextAttribute(hOut, FOREGROUND_GREEN);
							gapFillers(11);
							cout << "TRAFIONY, ZATOPIONY!";
							if (game.effects)
								SoundUtils::playSound("sunk");
							ai.resetData(game);
							gapFillers(65);
							game.board1.four1 = true;
						}
						else if (game.board1.gameBoard[playRow + 1][playColumn] == 6 && game.board1.gameBoard[playRow - 1][playColumn] == 6 && game.board1.gameBoard[playRow + 2][playColumn] == 6)
						{
							for (int a = 0; a < 3; a++)
							{
								for (int b = 0; b < 6; b++)
								{
									if (playColumn - 1 + a >= 0 && playColumn - 1 + a <= 9 && playRow - 2 + b >= 0 && playRow - 2 + b <= 9 && game.board1.gameBoard[playRow - 2 + b][playColumn - 1 + a] == -1)
										game.board1.gameBoard[playRow - 2 + b][playColumn - 1 + a] = 5;
								}
							}

							SetConsoleTextAttribute(hOut, FOREGROUND_GREEN);
							gapFillers(11);
							cout << "TRAFIONY, ZATOPIONY!";
							if (game.effects)
								SoundUtils::playSound("sunk");
							ai.resetData(game);
							gapFillers(65);
							game.board1.four1 = true;
						}
						else if (game.board1.gameBoard[playRow - 1][playColumn] == 6 && game.board1.gameBoard[playRow - 2][playColumn] == 6 && game.board1.gameBoard[playRow - 3][playColumn] == 6)
						{
							for (int a = 0; a < 3; a++)
							{
								for (int b = 0; b < 6; b++)
								{
									if (playColumn - 1 + a >= 0 && playColumn - 1 + a <= 9 && playRow + 1 - b >= 0 && playRow + 1 - b <= 9 && game.board1.gameBoard[playRow + 1 - b][playColumn - 1 + a] == -1)
										game.board1.gameBoard[playRow + 1 - b][playColumn - 1 + a] = 5;
								}
							}

							SetConsoleTextAttribute(hOut, FOREGROUND_GREEN);
							gapFillers(11);
							cout << "TRAFIONY, ZATOPIONY!";
							if (game.effects)
								SoundUtils::playSound("sunk");
							ai.resetData(game);
							gapFillers(65);
							game.board1.four1 = true;
						}
						else if (game.board1.gameBoard[playRow + 1][playColumn] == 6 && game.board1.gameBoard[playRow - 1][playColumn] == 6 && game.board1.gameBoard[playRow - 2][playColumn] == 6)
						{
							for (int a = 0; a < 3; a++)
							{
								for (int b = 0; b < 6; b++)
								{
									if (playColumn - 1 + a >= 0 && playColumn - 1 + a <= 9 && playRow + 2 - b >= 0 && playRow + 2 - b <= 9 && game.board1.gameBoard[playRow + 2 - b][playColumn - 1 + a] == -1)
										game.board1.gameBoard[playRow + 2 - b][playColumn - 1 + a] = 5;
								}
							}

							SetConsoleTextAttribute(hOut, FOREGROUND_GREEN);
							gapFillers(11);
							cout << "TRAFIONY, ZATOPIONY!";
							if (game.effects)
								SoundUtils::playSound("sunk");
							ai.resetData(game);
							gapFillers(65);
							game.board1.four1 = true;
						}
					}
				}

				if (game.board1.gameBoard[playRow][playColumn] == 6)
					game.playerOneTurn = false;
				else
					game.playerOneTurn = true;;
			}
		}
		else
		{
			if (playRow > 9 || playColumn > 9 || playRow < 0 || playColumn < 0)
			{
				setShipShotColor(game.board1.one1);
				cout << "  " << game.CHECK_MARK << "  ";
				setShipShotColor(game.board1.one2);
				cout << game.CHECK_MARK << "  ";
				setShipShotColor(game.board1.one3);
				cout << game.CHECK_MARK << "  ";
				setShipShotColor(game.board1.one4);
				cout << game.CHECK_MARK;

				SetConsoleTextAttribute(hOut, FOREGROUND_RED);
				gapFillers(5);
				cout << "Dokonales zlego wyboru! Nie przechodz na ciemna strone mocy i wybierz wlasciwa cyfre!";
				cin.clear();
				cin.ignore(100, '\n');
				gapFillers(6);
				SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
			}
			else if (game.board2.gameBoard[playRow][playColumn] == 5 || game.board2.gameBoard[playRow][playColumn] == 6)
			{
				setShipShotColor(game.board1.one1);
				cout << "  " << game.CHECK_MARK << "  ";
				setShipShotColor(game.board1.one2);
				cout << game.CHECK_MARK << "  ";
				setShipShotColor(game.board1.one3);
				cout << game.CHECK_MARK << "  ";
				setShipShotColor(game.board1.one4);
				cout << game.CHECK_MARK;

				SetConsoleTextAttribute(hOut, FOREGROUND_RED);
				gapFillers(22);
				cout << "Przeciez juz tutaj strzelales! Sprobuj jeszcze raz.";
				gapFillers(23);
				SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
			}
			else
			{
				setShipShotColor(game.board1.one1);
				cout << "  " << game.CHECK_MARK << "  ";
				setShipShotColor(game.board1.one2);
				cout << game.CHECK_MARK << "  ";
				setShipShotColor(game.board1.one3);
				cout << game.CHECK_MARK << "  ";
				setShipShotColor(game.board1.one4);
				cout << game.CHECK_MARK;

				if (game.board2.gameBoard[playRow][playColumn] == -1 || game.board2.gameBoard[playRow][playColumn] == 0)
				{
					if (game.effects)
						SoundUtils::playSound("empty");
					game.board2.gameBoard[playRow][playColumn] = 5;

					SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
					gapFillers(77);
					cout << "PUSTO ;c";
					gapFillers(11);
				}
				else if (game.board2.gameBoard[playRow][playColumn] == 1)
				{
					game.board2.gameBoard[playRow][playColumn] = 6;
					for (int a = 0; a < 3; a++)
					{
						for (int b = 0; b < 3; b++)
						{
							if (playColumn - 1 + a >= 0 && playColumn - 1 + a <= 9 && playRow - 1 + b >= 0 && playRow - 1 + b <= 9 && game.board2.gameBoard[playRow - 1 + b][playColumn - 1 + a] == -1)
								game.board2.gameBoard[playRow - 1 + b][playColumn - 1 + a] = 5;
						}
					}

					SetConsoleTextAttribute(hOut, FOREGROUND_GREEN);
					gapFillers(71);
					cout << "TRAFIONY, ZATOPIONY!";
					if (game.effects)
						SoundUtils::playSound("sunk");
					gapFillers(5);
					if (game.board2.one1 == false) game.board2.one1 = true;
					else if (game.board2.one1 == true && game.board2.one2 == false) game.board2.one2 = true;
					else if (game.board2.one1 == true && game.board2.one2 == true && game.board2.one3 == false) game.board2.one3 = true;
					else if (game.board2.one1 == true && game.board2.one2 == true && game.board2.one3 == true) game.board2.one4 = true;
				}
				else if (game.board2.gameBoard[playRow][playColumn] == 2)
				{
					game.board2.gameBoard[playRow][playColumn] = 6;

					if (game.board2.gameBoard[playRow + 1][playColumn] != 6 && game.board2.gameBoard[playRow - 1][playColumn] != 6 && game.board2.gameBoard[playRow][playColumn + 1] != 6 && game.board2.gameBoard[playRow][playColumn - 1] != 6)
					{
						SetConsoleTextAttribute(hOut, FOREGROUND_RED);
						gapFillers(77);
						cout << "TRAFIONY!";
						if (game.effects)
							SoundUtils::playSound("hit");
						gapFillers(10);
					}
					else if (game.board2.gameBoard[playRow + 1][playColumn] == 6)
					{
						for (int a = 0; a < 3; a++)
						{
							for (int b = 0; b < 4; b++)
							{
								if (playColumn - 1 + a >= 0 && playColumn - 1 + a <= 9 && playRow - 1 + b >= 0 && playRow - 1 + b <= 9 && game.board2.gameBoard[playRow - 1 + b][playColumn - 1 + a] == -1)
									game.board2.gameBoard[playRow - 1 + b][playColumn - 1 + a] = 5;
							}
						}

						SetConsoleTextAttribute(hOut, FOREGROUND_GREEN);
						gapFillers(71);
						cout << "TRAFIONY, ZATOPIONY!";
						if (game.effects)
							SoundUtils::playSound("sunk");
						gapFillers(5);
						if (game.board2.two1 == false) game.board2.two1 = true;
						else if (game.board2.two1 == true && game.board2.two2 == false) game.board2.two2 = true;
						else if (game.board2.two1 == true && game.board2.two2 == true) game.board2.two3 = true;
					}
					else if (game.board2.gameBoard[playRow][playColumn + 1] == 6)
					{
						for (int a = 0; a < 3; a++)
						{
							for (int b = 0; b < 4; b++)
							{
								if (playRow - 1 + a >= 0 && playRow - 1 + a <= 9 && playColumn - 1 + b >= 0 && playColumn - 1 + b <= 9 && game.board2.gameBoard[playRow - 1 + a][playColumn - 1 + b] == -1)
									game.board2.gameBoard[playRow - 1 + a][playColumn - 1 + b] = 5;
							}
						}

						SetConsoleTextAttribute(hOut, FOREGROUND_GREEN);
						gapFillers(71);
						cout << "TRAFIONY, ZATOPIONY!";
						if (game.effects)
							SoundUtils::playSound("sunk");
						gapFillers(5);
						if (game.board2.two1 == false) game.board2.two1 = true;
						else if (game.board2.two1 == true && game.board2.two2 == false) game.board2.two2 = true;
						else if (game.board2.two1 == true && game.board2.two2 == true) game.board2.two3 = true;
					}
					else if (game.board2.gameBoard[playRow - 1][playColumn] == 6)
					{
						for (int a = 0; a < 3; a++)
						{
							for (int b = 0; b < 4; b++)
							{
								if (playColumn - 1 + a >= 0 && playColumn - 1 + a <= 9 && playRow + 1 - b >= 0 && playRow + 1 - b <= 9 && game.board2.gameBoard[playRow + 1 - b][playColumn - 1 + a] == -1)
									game.board2.gameBoard[playRow + 1 - b][playColumn - 1 + a] = 5;
							}
						}

						SetConsoleTextAttribute(hOut, FOREGROUND_GREEN);
						gapFillers(71);
						cout << "TRAFIONY, ZATOPIONY!";
						if (game.effects)
							SoundUtils::playSound("sunk");
						gapFillers(5);
						if (game.board2.two1 == false) game.board2.two1 = true;
						else if (game.board2.two1 == true && game.board2.two2 == false) game.board2.two2 = true;
						else if (game.board2.two1 == true && game.board2.two2 == true) game.board2.two3 = true;
					}
					else if (game.board2.gameBoard[playRow][playColumn - 1] == 6)
					{
						for (int a = 0; a < 3; a++)
						{
							for (int b = 0; b < 4; b++)
							{
								if (playRow - 1 + a >= 0 && playRow - 1 + a <= 9 && playColumn + 1 - b >= 0 && playColumn + 1 - b <= 9 && game.board2.gameBoard[playRow - 1 + a][playColumn + 1 - b] == -1)
									game.board2.gameBoard[playRow - 1 + a][playColumn + 1 - b] = 5;
							}
						}

						SetConsoleTextAttribute(hOut, FOREGROUND_GREEN);
						gapFillers(71);
						cout << "TRAFIONY, ZATOPIONY!";
						if (game.effects)
							SoundUtils::playSound("sunk");
						gapFillers(5);
						if (game.board2.two1 == false) game.board2.two1 = true;
						else if (game.board2.two1 == true && game.board2.two2 == false) game.board2.two2 = true;
						else if (game.board2.two1 == true && game.board2.two2 == true) game.board2.two3 = true;
					}
				}
				else if (game.board2.gameBoard[playRow][playColumn] == 3)
				{
					game.board2.gameBoard[playRow][playColumn] = 6;

					if ((game.board2.gameBoard[playRow - 1][playColumn] == 3 && game.board2.gameBoard[playRow - 2][playColumn] == 3)
						|| (game.board2.gameBoard[playRow - 1][playColumn] == 6 && game.board2.gameBoard[playRow - 2][playColumn] == 3)
						|| (game.board2.gameBoard[playRow - 1][playColumn] == 3 && game.board2.gameBoard[playRow - 2][playColumn] == 6))
					{

						SetConsoleTextAttribute(hOut, FOREGROUND_RED);
						gapFillers(77);
						cout << "TRAFIONY!";
						if (game.effects)
							SoundUtils::playSound("hit");
						gapFillers(10);
					}
					else if (game.board2.gameBoard[playRow - 1][playColumn] == 6 && game.board2.gameBoard[playRow - 2][playColumn] == 6)
					{
						for (int a = 0; a < 3; a++)
						{
							for (int b = 0; b < 5; b++)
							{
								if (playColumn - 1 + a >= 0 && playColumn - 1 + a <= 9 && playRow + 1 - b >= 0 && playRow + 1 - b <= 9 && game.board2.gameBoard[playRow + 1 - b][playColumn - 1 + a] == -1)
									game.board2.gameBoard[playRow + 1 - b][playColumn - 1 + a] = 5;
							}


						}

						SetConsoleTextAttribute(hOut, FOREGROUND_GREEN);
						gapFillers(71);
						cout << "TRAFIONY, ZATOPIONY!";
						if (game.effects)
							SoundUtils::playSound("sunk");
						gapFillers(5);
						if (game.board2.three1 == false) game.board2.three1 = true;
						else if (game.board2.three1 == true) game.board2.three2 = true;

					}

					else if ((game.board2.gameBoard[playRow - 1][playColumn] == 3 && game.board2.gameBoard[playRow + 1][playColumn] == 3)
						|| (game.board2.gameBoard[playRow - 1][playColumn] == 6 && game.board2.gameBoard[playRow + 1][playColumn] == 3)
						|| (game.board2.gameBoard[playRow - 1][playColumn] == 3 && game.board2.gameBoard[playRow + 1][playColumn] == 6))
					{

						SetConsoleTextAttribute(hOut, FOREGROUND_RED);
						gapFillers(77);
						cout << "TRAFIONY!";
						if (game.effects)
							SoundUtils::playSound("hit");
						gapFillers(10);
					}
					else if (game.board2.gameBoard[playRow - 1][playColumn] == 6 && game.board2.gameBoard[playRow + 1][playColumn] == 6)
					{
						for (int a = 0; a < 3; a++)
						{
							for (int b = 0; b < 5; b++)
							{
								if (playColumn - 1 + a >= 0 && playColumn - 1 + a <= 9 && playRow + 2 - b >= 0 && playRow + 2 - b <= 9 && game.board2.gameBoard[playRow + 2 - b][playColumn - 1 + a] == -1)
									game.board2.gameBoard[playRow + 2 - b][playColumn - 1 + a] = 5;
							}
						}

						SetConsoleTextAttribute(hOut, FOREGROUND_GREEN);
						gapFillers(71);
						cout << "TRAFIONY, ZATOPIONY!";
						if (game.effects)
							SoundUtils::playSound("sunk");
						gapFillers(5);
						if (game.board2.three1 == false) game.board2.three1 = true;
						else if (game.board2.three1 == true) game.board2.three2 = true;
					}
					else if ((game.board2.gameBoard[playRow + 1][playColumn] == 3 && game.board2.gameBoard[playRow + 2][playColumn] == 3)
						|| (game.board2.gameBoard[playRow + 1][playColumn] == 6 && game.board2.gameBoard[playRow + 2][playColumn] == 3)
						|| (game.board2.gameBoard[playRow + 1][playColumn] == 3 && game.board2.gameBoard[playRow + 2][playColumn] == 6))
					{

						SetConsoleTextAttribute(hOut, FOREGROUND_RED);
						gapFillers(77);
						cout << "TRAFIONY!";
						if (game.effects)
							SoundUtils::playSound("hit");
						gapFillers(10);
					}
					else if (game.board2.gameBoard[playRow + 1][playColumn] == 6 && game.board2.gameBoard[playRow + 2][playColumn] == 6)
					{
						for (int a = 0; a < 3; a++)
						{
							for (int b = 0; b < 5; b++)
							{
								if (playColumn - 1 + a >= 0 && playColumn - 1 + a <= 9 && playRow - 1 + b >= 0 && playRow - 1 + b <= 9 && game.board2.gameBoard[playRow - 1 + b][playColumn - 1 + a] == -1)
									game.board2.gameBoard[playRow - 1 + b][playColumn - 1 + a] = 5;
							}
						}

						SetConsoleTextAttribute(hOut, FOREGROUND_GREEN);
						gapFillers(71);
						cout << "TRAFIONY, ZATOPIONY!";
						if (game.effects)
							SoundUtils::playSound("sunk");
						gapFillers(5);
						if (game.board2.three1 == false) game.board2.three1 = true;
						else if (game.board2.three1 == true) game.board2.three2 = true;
					}
					else if ((game.board2.gameBoard[playRow][playColumn + 1] == 3 && game.board2.gameBoard[playRow][playColumn + 2] == 3)
						|| (game.board2.gameBoard[playRow][playColumn + 1] == 6 && game.board2.gameBoard[playRow][playColumn + 2] == 3)
						|| (game.board2.gameBoard[playRow][playColumn + 1] == 3 && game.board2.gameBoard[playRow][playColumn + 2] == 6))
					{

						SetConsoleTextAttribute(hOut, FOREGROUND_RED);
						gapFillers(77);
						cout << "TRAFIONY!";
						if (game.effects)
							SoundUtils::playSound("hit");
						gapFillers(10);
					}
					else if (game.board2.gameBoard[playRow][playColumn + 1] == 6 && game.board2.gameBoard[playRow][playColumn + 2] == 6)
					{
						for (int a = 0; a < 3; a++)
						{
							for (int b = 0; b < 5; b++)
							{
								if (playColumn - 1 + b >= 0 && playColumn - 1 + b <= 9 && playRow - 1 + a >= 0 && playRow - 1 + a <= 9 && game.board2.gameBoard[playRow - 1 + a][playColumn - 1 + b] == -1)
									game.board2.gameBoard[playRow - 1 + a][playColumn - 1 + b] = 5;
							}
						}

						SetConsoleTextAttribute(hOut, FOREGROUND_GREEN);
						gapFillers(71);
						cout << "TRAFIONY, ZATOPIONY!";
						if (game.effects)
							SoundUtils::playSound("sunk");
						gapFillers(5);
						if (game.board2.three1 == false) game.board2.three1 = true;
						else if (game.board2.three1 == true) game.board2.three2 = true;
					}

					else if ((game.board2.gameBoard[playRow][playColumn - 1] == 3 && game.board2.gameBoard[playRow][playColumn + 1] == 3)
						|| (game.board2.gameBoard[playRow][playColumn - 1] == 6 && game.board2.gameBoard[playRow][playColumn + 1] == 3)
						|| (game.board2.gameBoard[playRow][playColumn - 1] == 3 && game.board2.gameBoard[playRow][playColumn + 1] == 6))
					{

						SetConsoleTextAttribute(hOut, FOREGROUND_RED);
						gapFillers(77);
						cout << "TRAFIONY!";
						if (game.effects)
							SoundUtils::playSound("hit");
						gapFillers(10);
					}
					else if (game.board2.gameBoard[playRow][playColumn - 1] == 6 && game.board2.gameBoard[playRow][playColumn + 1] == 6)
					{
						for (int a = 0; a < 3; a++)
						{
							for (int b = 0; b < 5; b++)
							{
								if (playColumn - 2 + b >= 0 && playColumn - 2 + b <= 9 && playRow - 1 + a >= 0 && playRow - 1 + a <= 9 && game.board2.gameBoard[playRow - 1 + a][playColumn - 2 + b] == -1)
									game.board2.gameBoard[playRow - 1 + a][playColumn - 2 + b] = 5;
							}
						}

						SetConsoleTextAttribute(hOut, FOREGROUND_GREEN);
						gapFillers(71);
						cout << "TRAFIONY, ZATOPIONY!";
						if (game.effects)
							SoundUtils::playSound("sunk");
						gapFillers(5);
						if (game.board2.three1 == false) game.board2.three1 = true;
						else if (game.board2.three1 == true) game.board2.three2 = true;
					}
					else if ((game.board2.gameBoard[playRow][playColumn - 1] == 3 && game.board2.gameBoard[playRow][playColumn - 2] == 3)
						|| (game.board2.gameBoard[playRow][playColumn - 1] == 6 && game.board2.gameBoard[playRow][playColumn - 2] == 3)
						|| (game.board2.gameBoard[playRow][playColumn - 1] == 3 && game.board2.gameBoard[playRow][playColumn - 2] == 6))
					{

						SetConsoleTextAttribute(hOut, FOREGROUND_RED);
						gapFillers(77);
						cout << "TRAFIONY!";
						if (game.effects)
							SoundUtils::playSound("hit");
						gapFillers(10);
					}
					else if (game.board2.gameBoard[playRow][playColumn - 1] == 6 && game.board2.gameBoard[playRow][playColumn - 2] == 6)
					{
						for (int a = 0; a < 3; a++)
						{
							for (int b = 0; b < 5; b++)
							{
								if (playColumn - 3 + b >= 0 && playColumn - 3 + b <= 9 && playRow - 1 + a >= 0 && playRow - 1 + a <= 9 && game.board2.gameBoard[playRow - 1 + a][playColumn - 3 + b] == -1)
									game.board2.gameBoard[playRow - 1 + a][playColumn - 3 + b] = 5;
							}
						}

						SetConsoleTextAttribute(hOut, FOREGROUND_GREEN);
						gapFillers(71);
						cout << "TRAFIONY, ZATOPIONY!";
						if (game.effects)
							SoundUtils::playSound("sunk");
						gapFillers(5);
						if (game.board2.three1 == false) game.board2.three1 = true;
						else if (game.board2.three1 == true) game.board2.three2 = true;
					}

				}
				else if (game.board2.gameBoard[playRow][playColumn] == 4)
				{
					game.board2.gameBoard[playRow][playColumn] = 6;
					czworka2++;
					if (czworka2 != 4)
					{
						SetConsoleTextAttribute(hOut, FOREGROUND_RED);
						gapFillers(77);
						cout << "TRAFIONY!";
						if (game.effects)
							SoundUtils::playSound("hit");
						gapFillers(10);
					}
					else if (czworka2 == 4)
					{
						if (game.board2.gameBoard[playRow][playColumn + 1] == 6 && game.board2.gameBoard[playRow][playColumn + 2] == 6 && game.board2.gameBoard[playRow][playColumn + 3] == 6)
						{
							for (int a = 0; a < 3; a++)
							{
								for (int b = 0; b < 6; b++)
								{
									if (playRow - 1 + a >= 0 && playRow - 1 + a <= 9 && playColumn - 1 + b >= 0 && playColumn - 1 + b <= 9 && game.board2.gameBoard[playRow - 1 + a][playColumn - 1 + b] == -1)
										game.board2.gameBoard[playRow - 1 + a][playColumn - 1 + b] = 5;
								}
							}

							SetConsoleTextAttribute(hOut, FOREGROUND_GREEN);
							gapFillers(71);
							cout << "TRAFIONY, ZATOPIONY!";
							if (game.effects)
								SoundUtils::playSound("sunk");
							gapFillers(5);
							if (game.board2.four1 == false) game.board2.four1 = true;


						}
						else if (game.board2.gameBoard[playRow][playColumn - 1] == 6 && game.board2.gameBoard[playRow][playColumn + 1] == 6 && game.board2.gameBoard[playRow][playColumn + 2] == 6)
						{
							for (int a = 0; a < 3; a++)
							{
								for (int b = 0; b < 6; b++)
								{
									if (playRow - 1 + a >= 0 && playRow - 1 + a <= 9 && playColumn - 2 + b >= 0 && playColumn - 2 + b <= 9 && game.board2.gameBoard[playRow - 1 + a][playColumn - 2 + b] == -1)
										game.board2.gameBoard[playRow - 1 + a][playColumn - 2 + b] = 5;
								}
							}

							SetConsoleTextAttribute(hOut, FOREGROUND_GREEN);
							gapFillers(71);
							cout << "TRAFIONY, ZATOPIONY!";
							if (game.effects)
								SoundUtils::playSound("sunk");
							gapFillers(5);
							if (game.board2.four1 == false) game.board2.four1 = true;
						}
						else if (game.board2.gameBoard[playRow][playColumn - 1] == 6 && game.board2.gameBoard[playRow][playColumn - 2] == 6 && game.board2.gameBoard[playRow][playColumn - 3] == 6)
						{
							for (int a = 0; a < 3; a++)
							{
								for (int b = 0; b < 6; b++)
								{
									if (playRow - 1 + a >= 0 && playRow - 1 + a <= 9 && playColumn + 1 - b >= 0 && playColumn + 1 - b <= 9 && game.board2.gameBoard[playRow - 1 + a][playColumn + 1 - b] == -1)
										game.board2.gameBoard[playRow - 1 + a][playColumn + 1 - b] = 5;
								}
							}

							SetConsoleTextAttribute(hOut, FOREGROUND_GREEN);
							gapFillers(71);
							cout << "TRAFIONY, ZATOPIONY!";
							if (game.effects)
								SoundUtils::playSound("sunk");
							gapFillers(5);
							if (game.board2.four1 == false) game.board2.four1 = true;
						}
						else if (game.board2.gameBoard[playRow][playColumn - 1] == 6 && game.board2.gameBoard[playRow][playColumn + 1] == 6 && game.board2.gameBoard[playRow][playColumn - 2] == 6)
						{
							for (int a = 0; a < 3; a++)
							{
								for (int b = 0; b < 6; b++)
								{
									if (playRow - 1 + a >= 0 && playRow - 1 + a <= 9 && playColumn + 2 - b >= 0 && playColumn + 2 - b <= 9 && game.board2.gameBoard[playRow - 1 + a][playColumn + 2 - b] == -1)
										game.board2.gameBoard[playRow - 1 + a][playColumn + 2 - b] = 5;
								}
							}

							SetConsoleTextAttribute(hOut, FOREGROUND_GREEN);
							gapFillers(71);
							cout << "TRAFIONY, ZATOPIONY!";
							if (game.effects)
								SoundUtils::playSound("sunk");
							gapFillers(5);
							if (game.board2.four1 == false) game.board2.four1 = true;
						}
						else if (game.board2.gameBoard[playRow + 1][playColumn] == 6 && game.board2.gameBoard[playRow + 2][playColumn] == 6 && game.board2.gameBoard[playRow + 3][playColumn] == 6)
						{
							for (int a = 0; a < 3; a++)
							{
								for (int b = 0; b < 6; b++)
								{
									if (playColumn - 1 + a >= 0 && playColumn - 1 + a <= 9 && playRow - 1 + b >= 0 && playRow - 1 + b <= 9 && game.board2.gameBoard[playRow - 1 + b][playColumn - 1 + a] == -1)
										game.board2.gameBoard[playRow - 1 + b][playColumn - 1 + a] = 5;
								}
							}

							SetConsoleTextAttribute(hOut, FOREGROUND_GREEN);
							gapFillers(71);
							cout << "TRAFIONY, ZATOPIONY!";
							if (game.effects)
								SoundUtils::playSound("sunk");
							gapFillers(5);
							if (game.board2.four1 == false) game.board2.four1 = true;
						}
						else if (game.board2.gameBoard[playRow + 1][playColumn] == 6 && game.board2.gameBoard[playRow - 1][playColumn] == 6 && game.board2.gameBoard[playRow + 2][playColumn] == 6)
						{
							for (int a = 0; a < 3; a++)
							{
								for (int b = 0; b < 6; b++)
								{
									if (playColumn - 1 + a >= 0 && playColumn - 1 + a <= 9 && playRow - 2 + b >= 0 && playRow - 2 + b <= 9 && game.board2.gameBoard[playRow - 2 + b][playColumn - 1 + a] == -1)
										game.board2.gameBoard[playRow - 2 + b][playColumn - 1 + a] = 5;
								}
							}

							SetConsoleTextAttribute(hOut, FOREGROUND_GREEN);
							gapFillers(71);
							cout << "TRAFIONY, ZATOPIONY!";
							if (game.effects)
								SoundUtils::playSound("sunk");
							gapFillers(5);
							if (game.board2.four1 == false) game.board2.four1 = true;
						}
						else if (game.board2.gameBoard[playRow - 1][playColumn] == 6 && game.board2.gameBoard[playRow - 2][playColumn] == 6 && game.board2.gameBoard[playRow - 3][playColumn] == 6)
						{
							for (int a = 0; a < 3; a++)
							{
								for (int b = 0; b < 6; b++)
								{
									if (playColumn - 1 + a >= 0 && playColumn - 1 + a <= 9 && playRow + 1 - b >= 0 && playRow + 1 - b <= 9 && game.board2.gameBoard[playRow + 1 - b][playColumn - 1 + a] == -1)
										game.board2.gameBoard[playRow + 1 - b][playColumn - 1 + a] = 5;
								}
							}

							SetConsoleTextAttribute(hOut, FOREGROUND_GREEN);
							gapFillers(71);
							cout << "TRAFIONY, ZATOPIONY!";
							if (game.effects)
								SoundUtils::playSound("sunk");
							gapFillers(5);
							if (game.board2.four1 == false) game.board2.four1 = true;
						}
						else if (game.board2.gameBoard[playRow + 1][playColumn] == 6 && game.board2.gameBoard[playRow - 1][playColumn] == 6 && game.board2.gameBoard[playRow - 2][playColumn] == 6)
						{
							for (int a = 0; a < 3; a++)
							{
								for (int b = 0; b < 6; b++)
								{
									if (playColumn - 1 + a >= 0 && playColumn - 1 + a <= 9 && playRow + 2 - b >= 0 && playRow + 2 - b <= 9 && game.board2.gameBoard[playRow + 2 - b][playColumn - 1 + a] == -1)
										game.board2.gameBoard[playRow + 2 - b][playColumn - 1 + a] = 5;
								}
							}

							SetConsoleTextAttribute(hOut, FOREGROUND_GREEN);
							gapFillers(71);
							cout << "TRAFIONY, ZATOPIONY!";
							if (game.effects)
								SoundUtils::playSound("sunk");
							gapFillers(5);
							if (game.board2.four1 == false) game.board2.four1 = true;
						}
					}
				}
				if (game.board2.gameBoard[playRow][playColumn] == 6)
					game.playerOneTurn = true;
				else
					game.playerOneTurn = false;
			}
		}
		setShipShotColor(game.board2.one1);
		cout << game.CHECK_MARK << "  ";
		setShipShotColor(game.board2.one2);
		cout << game.CHECK_MARK << "  ";
		setShipShotColor(game.board2.one3);
		cout << game.CHECK_MARK << "  ";
		setShipShotColor(game.board2.one4);
		cout << game.CHECK_MARK << "  ";

		cout << endl;

		setShipShotColor(game.board1.two1);
		cout << "  " << game.CHECK_MARK << game.CHECK_MARK << "  ";
		setShipShotColor(game.board1.two2);
		cout << game.CHECK_MARK << game.CHECK_MARK << "  ";
		setShipShotColor(game.board1.two3);
		cout << game.CHECK_MARK << game.CHECK_MARK;

		gapFillers(96);

		setShipShotColor(game.board2.two1);
		cout << game.CHECK_MARK << game.CHECK_MARK << "  ";
		setShipShotColor(game.board2.two2);
		cout << game.CHECK_MARK << game.CHECK_MARK << "  ";
		setShipShotColor(game.board2.two3);
		if (!game.board2.two3) {
			cout << game.CHECK_MARK << game.CHECK_MARK;
		}
		else {
			cout << game.CHECK_MARK << game.CHECK_MARK << "  ";
		}

		cout << endl;

		setShipShotColor(game.board1.three1);
		cout << "  " << game.CHECK_MARK << game.CHECK_MARK << game.CHECK_MARK << "  ";
		setShipShotColor(game.board1.three2);
		cout << game.CHECK_MARK << game.CHECK_MARK << game.CHECK_MARK;

		Board chosenBoard;
		if (game.playerOneTurn)
		{
			SetConsoleTextAttribute(hOut, FOREGROUND_BLUE);
			chosenBoard = game.board1;
		}
		else
		{
			SetConsoleTextAttribute(hOut, FOREGROUND_BLUE | FOREGROUND_RED);
			chosenBoard = game.board2;
		}
		gapFillers(((120 - (chosenBoard.getPlayerNameLength() + 26)) / 2) - 10);

		cout << chosenBoard.playerName << ", to twoja tura! Strzelaj!";
		if ((chosenBoard.playerName.length() % 2) == 1)
			gapFillers(((120 - (chosenBoard.getPlayerNameLength() + 26)) / 2) - 11);
		else
			gapFillers(((120 - (chosenBoard.getPlayerNameLength() + 26)) / 2) - 10);

		setShipShotColor(game.board2.three1);
		cout << game.CHECK_MARK << game.CHECK_MARK << game.CHECK_MARK << "  ";
		setShipShotColor(game.board2.three2);
		cout << game.CHECK_MARK << game.CHECK_MARK << game.CHECK_MARK;

		cout << endl;

		setShipShotColor(game.board1.four1);
		cout << "  " << game.CHECK_MARK << game.CHECK_MARK << game.CHECK_MARK << game.CHECK_MARK;
		gapFillers(108);
		setShipShotColor(game.board2.four1);
		cout << game.CHECK_MARK << game.CHECK_MARK << game.CHECK_MARK << game.CHECK_MARK;

		cout << endl;

		SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
		for (int a = 0; a < (60 - (game.board1.getPlayerNameLength() + 15)) / 2; a++)
			cout << " ";
		cout << "Plansza gracza ";
		SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
		cout << game.board1.playerName;
		SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
		for (int a = 0; a < (45 - ((game.board1.getPlayerNameLength() + game.board2.getPlayerNameLength()) / 2)); a++)
			cout << " ";
		cout << "Plansza gracza ";
		SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
		cout << game.board2.playerName;
		SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
		cout << endl << endl;
		cout << "   ";

		for (char z = 65; z <= 74; z++)
		{
			SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
			cout << "    ";
			SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY | BACKGROUND_RED);
			cout << z;

		}
		SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY);
		cout << "      " << game.LINE_MARK << "   ";
		for (char x = 65; x <= 74; x++)
		{
			SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
			cout << "    ";
			SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY | BACKGROUND_RED);
			cout << x;

		}
		SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY);


		cout << endl << "                                                           " << game.LINE_MARK << endl;
		for (int i = 0; i <= 9; i++)
		{
			cout << "  ";
			SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY | BACKGROUND_RED);
			cout << (i + 1);

			// POKAZuJE u£O¯ON¼ PLANSZÊ
			for (int j = 0; j <= 9; j++)
			{
				int widthLen = (i == 9 && j == 0) ? 4 : 5;
				if (game.board1.gameBoard[i][j] == 5)
				{
					cout.width(widthLen);
					SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
					cout << "o";
				}
				else if (game.board1.gameBoard[i][j] == 6)
				{
					cout.width(widthLen);
					SetConsoleTextAttribute(hOut, FOREGROUND_RED);
					cout << "x";
				}
				else {
					cout.width(widthLen);
					SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
					cout << ".";
				}
			}
			SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY);
			cout << "      " << game.LINE_MARK << "   ";

			for (int q = 0; q <= 9; q++)
			{
				if (game.board2.gameBoard[i][q] == 5)
				{
					cout.width(5);
					SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
					cout << "o";
				}
				else if (game.board2.gameBoard[i][q] == 6)
				{
					cout.width(5);
					SetConsoleTextAttribute(hOut, FOREGROUND_RED);
					cout << "x";
				}
				else {
					cout.width(5);
					SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
					cout << ".";
				}
			}
			SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
			cout << "    ";
			SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY | BACKGROUND_RED);
			cout << i + 1;
			SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY);

			cout << endl << "                                                           ";
			if (i != 9)
				cout << game.LINE_MARK;
			cout << endl;
		}
		SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);

		int licznik = 0;
		int licznik2 = 0;
		for (int s = 0; s <= 9; s++)
		{
			for (int t = 0; t <= 9; t++)
			{
				if (game.board1.gameBoard[s][t] == 6 || game.board1.gameBoard[s][t] == 5 || game.board1.gameBoard[s][t] == 0 || game.board1.gameBoard[s][t] == -1)
				{
					licznik++;
				}
			}
		}
		for (int s = 0; s <= 9; s++)
		{
			for (int t = 0; t <= 9; t++)
			{
				if (game.board2.gameBoard[s][t] == 6 || game.board2.gameBoard[s][t] == 5 || game.board2.gameBoard[s][t] == 0 || game.board2.gameBoard[s][t] == -1)
				{
					licznik2++;
				}
			}
		}
		if (licznik == 100 || licznik2 == 100)
		{
			string winner = licznik == 100 ? game.board2.playerName : game.board1.playerName;
			koniec_gry = true;
			SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
			cout << "GRATULACJE! TO JUZ KONIEC GRY!";
			Sleep(2000);
			system("cls");
			if (game.effects) {
				if (licznik == 100) 
					SoundUtils::playSound("loseC");
				else 
					SoundUtils::playSound("winP");
			}
			cout << "GRATULACJE! TO JUZ KONIEC GRY! Wygral ";
			SetConsoleTextAttribute(hOut, FOREGROUND_RED);
			cout << winner;
			SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
			cout << endl << endl;
			game.stop = clock();
			getGameTime(game);
			instrukcja = 0;
		}
	}
}

void Game::startGame(Game game) {
	game.start = clock();
	if (game.music) {
		SoundUtils::playSound("mute");
	}

	renderShipsStatusHeader(game);
	renderBoards(game);
	askForInput(game);
}