#pragma once
#include "../utils/CursorUtils.h"
#include "../utils/FrameUtils.h"
#include "MapGenerator.h"
#include "../Board.h"
#include "../Game.h"
#include "../Ship.h"
#include <random>

using namespace std;

void MapGenerator::doGenerateRandomMap(Board &board)
{
	random_device rd;
	mt19937 generator(rd());
	uniform_int_distribution<int> random_line(0, 9);
	uniform_int_distribution<int> random_column(0, 9);
	uniform_int_distribution<int> random_direction(0, 3);				// 0 - góra, 1 - dó³, 2 - prawo, 3 - lewo

	int line{}, column{}, direction{};
	Ship ship4_1(0,0,0,0, false, false);
	for (int c = 0; c <= 9; c++)
	{
		for (int d = 0; d <= 9; d++)
		{
			board.gameBoard[c][d] = {};
			board.shipBoard[c][d] = {};
		}
	}
	
	do {
		
		line = random_line(generator);
		column = random_column(generator);
		direction = random_direction(generator);

		if (direction == 0 && line - 3 >= 0 && board.gameBoard[line][column] == 0 && board.gameBoard[line - 1][column] == 0 && board.gameBoard[line - 2][column] == 0 && board.gameBoard[line - 3][column] == 0)
		{
			ship4_1.load(4, line, column, direction);
			for (int i = 0; i < 4; i++)
			{
				board.gameBoard[line - i][column] = 1;
				board.shipBoard[line - i][column] = ship4_1;
			}

			for (int a = 0; a < 3; a++)
			{
				for (int b = 0; b < 6; b++)
				{
					if (column - 1 + a >= 0 && column - 1 + a <= 9 && line + 1 - b >= 0 && line + 1 - b <= 9 && board.gameBoard[line + 1 - b][column - 1 + a] == 0)
						board.gameBoard[line + 1 - b][column - 1 + a] = -1;
				}


			}
		}
		else if (direction == 1 && line + 3 <= 9 && board.gameBoard[line][column] == 0 && board.gameBoard[line + 1][column] == 0 && board.gameBoard[line + 2][column] == 0 && board.gameBoard[line + 3][column] == 0)
		{
			ship4_1.load(4, line, column, direction);
			for (int i = 0; i < 4; i++)
			{
				board.gameBoard[line + i][column] = 1;
				board.shipBoard[line + i][column] = ship4_1;
			}

			for (int a = 0; a < 3; a++)
			{
				for (int b = 0; b < 6; b++)
				{
					if (column - 1 + a >= 0 && column - 1 + a <= 9 && line - 1 + b >= 0 && line - 1 + b <= 9 && board.gameBoard[line - 1 + b][column - 1 + a] == 0)
						board.gameBoard[line - 1 + b][column - 1 + a] = -1;
				}


			}
		}
		else if (direction == 2 && column + 3 <= 9 && board.gameBoard[line][column] == 0 && board.gameBoard[line][column + 1] == 0 && board.gameBoard[line][column + 2] == 0 && board.gameBoard[line][column + 3] == 0)
		{
			ship4_1.load(4, line, column, direction);
			for (int i = 0; i < 4; i++)
			{
				board.gameBoard[line][column + i] = 1;
				board.shipBoard[line][column + i] = ship4_1;
			}

			for (int a = 0; a < 3; a++)
			{
				for (int b = 0; b < 6; b++)
				{
					if (line - 1 + a >= 0 && line - 1 + a <= 9 && column - 1 + b >= 0 && column - 1 + b <= 9 && board.gameBoard[line - 1 + a][column - 1 + b] == 0)
						board.gameBoard[line - 1 + a][column - 1 + b] = -1;
				}


			}
		}
		else if (direction == 3 && column - 3 >= 0 && board.gameBoard[line][column] == 0 && board.gameBoard[line][column - 1] == 0 && board.gameBoard[line][column - 2] == 0 && board.gameBoard[line][column - 3] == 0)
		{
			ship4_1.load(4, line, column, direction);
			for (int i = 0; i < 4; i++)
			{
				board.gameBoard[line][column - i] = 1;
				board.shipBoard[line][column - i] = ship4_1;
			}

			for (int a = 0; a < 3; a++)
			{
				for (int b = 0; b < 6; b++)
				{
					if (line - 1 + a >= 0 && line - 1 + a <= 9 && column + 1 - b >= 0 && column + 1 - b <= 9 && board.gameBoard[line - 1 + a][column + 1 - b] == 0)
						board.gameBoard[line - 1 + a][column + 1 - b] = -1;
				}


			}
		}

	} while (ship4_1.if_onBoard==false);

	Ship ship3_1(0, 0, 0, 0, false, false);
	Ship ship3_2(0, 0, 0, 0, false, false);
	bool check = false;

	for (int a = 1; a <=2; a++)
	{
		check = true;
		do
		{
			line = random_line(generator);
			column = random_column(generator);
			direction = random_direction(generator);

			// 0 - góra, 1 - dó³, 2 - prawo, 3 - lewo

			if (direction == 0 && line - 2 >= 0 && board.gameBoard[line][column] == 0 && board.gameBoard[line - 1][column] == 0 && board.gameBoard[line - 2][column] == 0)
			{
				if (a == 1) ship3_1.load(3, line, column, direction);
				else if (a==2) ship3_2.load(3, line, column, direction);
				for (int i = 0; i < 3; i++)
				{
					board.gameBoard[line - i][column] = 1;
					if (a == 1) board.shipBoard[line-i][column] = ship3_1;
					else if (a == 2) board.shipBoard[line-i][column] = ship3_2;
				}

				for (int a = 0; a < 3; a++)
				{
					for (int b = 0; b < 5; b++)
					{
						if (column - 1 + a >= 0 && column - 1 + a <= 9 && line + 1 - b >= 0 && line + 1 - b <= 9 && board.gameBoard[line + 1 - b][column - 1 + a] == 0)
							board.gameBoard[line + 1 - b][column - 1 + a] = -1;
					}


				}
			}
			else if (direction == 1 && line + 2 <= 9 && board.gameBoard[line][column] == 0 && board.gameBoard[line + 1][column] == 0 && board.gameBoard[line + 2][column] == 0)
			{
				if (a == 1) ship3_1.load(3, line, column, direction);
				else if (a == 2) ship3_2.load(3, line, column, direction);
				for (int i = 0; i < 3; i++)
				{
					board.gameBoard[line + i][column] = 1;
					if (a == 1) board.shipBoard[line + i][column] = ship3_1;
					else if (a == 2) board.shipBoard[line + i][column] = ship3_2;
				}

				for (int a = 0; a < 3; a++)
				{
					for (int b = 0; b < 5; b++)
					{
						if (column - 1 + a >= 0 && column - 1 + a <= 9 && line - 1 + b >= 0 && line - 1 + b <= 9 && board.gameBoard[line - 1 + b][column - 1 + a] == 0)
							board.gameBoard[line - 1 + b][column - 1 + a] = -1;
					}


				}
			}
			else if (direction == 2 && column + 2 <= 9 && board.gameBoard[line][column] == 0 && board.gameBoard[line][column + 1] == 0 && board.gameBoard[line][column + 2] == 0)
			{
				if (a == 1) ship3_1.load(3, line, column, direction);
				else if (a == 2) ship3_2.load(3, line, column, direction);
				for (int i = 0; i < 3; i++)
				{
					board.gameBoard[line][column + i] = 1;
					if (a == 1) board.shipBoard[line][column + i] = ship3_1;
					else if (a == 2) board.shipBoard[line][column + i] = ship3_2;
				}

				for (int a = 0; a < 3; a++)
				{
					for (int b = 0; b < 5; b++)
					{
						if (line - 1 + a >= 0 && line - 1 + a <= 9 && column - 1 + b >= 0 && column - 1 + b <= 9 && board.gameBoard[line - 1 + a][column - 1 + b] == 0)
							board.gameBoard[line - 1 + a][column - 1 + b] = -1;
					}


				}
			}
			else if (direction == 3 && column - 2 >= 0 && board.gameBoard[line][column] == 0 && board.gameBoard[line][column - 1] == 0 && board.gameBoard[line][column - 2] == 0)
			{
				if (a == 1) ship3_1.load(3, line, column, direction);
				else if (a == 2) ship3_2.load(3, line, column, direction);
				for (int i = 0; i < 3; i++)
				{
					board.gameBoard[line][column - i] = 1;
					if (a == 1) board.shipBoard[line][column - i] = ship3_1;
					else if (a == 2) board.shipBoard[line][column - i] = ship3_2;
				}

				for (int a = 0; a < 3; a++)
				{
					for (int b = 0; b < 5; b++)
					{
						if (line - 1 + a >= 0 && line - 1 + a <= 9 && column + 1 - b >= 0 && column + 1 - b <= 9 && board.gameBoard[line - 1 + a][column + 1 - b] == 0)
							board.gameBoard[line - 1 + a][column + 1 - b] = -1;
					}


				}
			}
			if (a == 1 && ship3_1.if_onBoard == true) check = false;
			else if (a == 2 && ship3_2.if_onBoard == true) check = false;
		} while (check);
	}
	Ship ship2_1(0, 0, 0, 0, false, false);
	Ship ship2_2(0, 0, 0, 0, false, false);
	Ship ship2_3(0, 0, 0, 0, false, false);
	for (int a = 1; a <= 3; a++)
	{
		check = true;
		do
		{
			line = random_line(generator);
			column = random_column(generator);
			direction = random_direction(generator);

			// 0 - góra, 1 - dó³, 2 - prawo, 3 - lewo

			if (direction == 0 && line - 1 >= 0 && board.gameBoard[line][column] == 0 && board.gameBoard[line - 1][column] == 0)
			{
				if (a == 1) ship2_1.load(2, line, column, direction);
				else if (a == 2) ship2_2.load(2, line, column, direction);
				else if (a == 3) ship2_3.load(2, line, column, direction);
				for (int i = 0; i < 2; i++)
				{
					board.gameBoard[line - i][column] = 1;
					if (a == 1) board.shipBoard[line-i][column] = ship2_1;
					else if (a == 2) board.shipBoard[line-i][column] = ship2_2;
					else if (a == 3) board.shipBoard[line-i][column] = ship2_3;
				}

				for (int a = 0; a < 3; a++)
				{
					for (int b = 0; b < 4; b++)
					{
						if (column - 1 + a >= 0 && column - 1 + a <= 9 && line + 1 - b >= 0 && line + 1 - b <= 9 && board.gameBoard[line + 1 - b][column - 1 + a] == 0)
							board.gameBoard[line + 1 - b][column - 1 + a] = -1;
					}


				}
			}
			else if (direction == 1 && line + 1 <= 9 && board.gameBoard[line][column] == 0 && board.gameBoard[line + 1][column] == 0)
			{
				if (a == 1) ship2_1.load(2, line, column, direction);
				else if (a == 2) ship2_2.load(2, line, column, direction);
				else if (a == 3) ship2_3.load(2, line, column, direction);
				for (int i = 0; i < 2; i++)
				{
					board.gameBoard[line + i][column] = 1;
					if (a == 1) board.shipBoard[line + i][column] = ship2_1;
					else if (a == 2) board.shipBoard[line + i][column] = ship2_2;
					else if (a == 3) board.shipBoard[line + i][column] = ship2_3;
				}

				for (int a = 0; a < 3; a++)
				{
					for (int b = 0; b < 4; b++)
					{
						if (column - 1 + a >= 0 && column - 1 + a <= 9 && line - 1 + b >= 0 && line - 1 + b <= 9 && board.gameBoard[line - 1 + b][column - 1 + a] == 0)
							board.gameBoard[line - 1 + b][column - 1 + a] = -1;
					}


				}
			}
			if (direction == 2 && column + 1 <= 9 && board.gameBoard[line][column] == 0 && board.gameBoard[line][column + 1] == 0)
			{
				if (a == 1) ship2_1.load(2, line, column, direction);
				else if (a == 2) ship2_2.load(2, line, column, direction);
				else if (a == 3) ship2_3.load(2, line, column, direction);
				for (int i = 0; i < 2; i++)
				{
					board.gameBoard[line][column + i] = 1;
					if (a == 1) board.shipBoard[line][column + i] = ship2_1;
					else if (a == 2) board.shipBoard[line][column + i] = ship2_2;
					else if (a == 3) board.shipBoard[line][column + i] = ship2_3;
				}

				for (int a = 0; a < 3; a++)
				{
					for (int b = 0; b < 4; b++)
					{
						if (line - 1 + a >= 0 && line - 1 + a <= 9 && column - 1 + b >= 0 && column - 1 + b <= 9 && board.gameBoard[line - 1 + a][column - 1 + b] == 0)
							board.gameBoard[line - 1 + a][column - 1 + b] = -1;
					}


				}
			}
			if (direction == 3 && column - 1 >= 0 && board.gameBoard[line][column] == 0 && board.gameBoard[line][column - 1] == 0)
			{
				if (a == 1) ship2_1.load(2, line, column, direction);
				else if (a == 2) ship2_2.load(2, line, column, direction);
				else if (a == 3) ship2_3.load(2, line, column, direction);
				for (int i = 0; i < 2; i++)
				{
					board.gameBoard[line][column - i] = 1;
					if (a == 1) board.shipBoard[line][column - i] = ship2_1;
					else if (a == 2) board.shipBoard[line][column - i] = ship2_2;
					else if (a == 3) board.shipBoard[line][column - i] = ship2_3;
				}

				for (int a = 0; a < 3; a++)
				{
					for (int b = 0; b < 4; b++)
					{
						if (line - 1 + a >= 0 && line - 1 + a <= 9 && column + 1 - b >= 0 && column + 1 - b <= 9 && board.gameBoard[line - 1 + a][column + 1 - b] == 0)
							board.gameBoard[line - 1 + a][column + 1 - b] = -1;
					}


				}
			}
			if (a == 1 && ship2_1.if_onBoard == true) check = false;
			else if (a == 2 && ship2_2.if_onBoard == true) check = false;
			else if (a == 3 && ship2_3.if_onBoard == true) check = false;
		} while (check);
	}
	Ship ship1_1(0, 0, 0, 0, false, false);
	Ship ship1_2(0, 0, 0, 0, false, false);
	Ship ship1_3(0, 0, 0, 0, false, false);
	Ship ship1_4(0, 0, 0, 0, false, false);
	for (int a = 1; a <= 4; a++)
	{
		check = true;
		do
		{
			line = random_line(generator);
			column = random_column(generator);
			direction = 0;

			if (board.gameBoard[line][column] == 0)
			{
				if (a == 1) ship1_1.load(1, line, column, direction);
				else if (a == 2) ship1_2.load(1, line, column, direction);
				else if (a == 3) ship1_3.load(1, line, column, direction);
				else if (a == 4) ship1_4.load(1, line, column, direction);
				board.gameBoard[line][column] = 1;
				if (a == 1) board.shipBoard[line][column] = ship1_1;
				else if (a == 2) board.shipBoard[line][column] = ship1_2;
				else if (a == 3) board.shipBoard[line][column] = ship1_3;
				else if (a == 4) board.shipBoard[line][column] = ship1_4;

				for (int a = 0; a < 3; a++)
				{
					for (int b = 0; b < 3; b++)
					{
						if (column - 1 + a >= 0 && column - 1 + a <= 9 && line + 1 - b >= 0 && line + 1 - b <= 9 && board.gameBoard[line + 1 - b][column - 1 + a] == 0)
							board.gameBoard[line + 1 - b][column - 1 + a] = -1;
					}


				}
			}
			if (a == 1 && ship1_1.if_onBoard == true) check = false;
			else if (a == 2 && ship1_2.if_onBoard == true) check = false;
			else if (a == 3 && ship1_3.if_onBoard == true) check = false;
			else if (a == 4 && ship1_4.if_onBoard == true) check = false;
		} while (check);
	}
}

void MapGenerator::doShowDots(int board[10][10])
{
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	cout << " ";

	for (char z = 65; z <= 74; z++)
	{
		SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
		cout << "    ";
		SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY | BACKGROUND_RED);
		cout << z;
	}

	SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
	cout << endl << endl;
	for (int i = 0; i <= 9; i++)
	{
		SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY | BACKGROUND_RED);
		cout << i + 1;

		// POKAZUJE KROPKI DO GRY 
		for (int j = 0; j <= 9; j++)
		{
			if (i == 9 && j == 0)
				cout.width(4);
			else
				cout.width(5);	
			if (board[i][j] == 0 || board[i][j] == -1)
			{
				SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
				cout << ".";
			}
			else
			{
				SetConsoleTextAttribute(hOut, FOREGROUND_RED);
				cout << "x";
			}

		}
		cout << endl << endl;
	}
}

void MapGenerator::chooseGenerationType(Game game, Board board)
{
	int choose = 0;
	bool end = false;
	while (end == false)
	{
		CursorUtils::setCursor(1, 1);
		cout << endl << endl;
		CursorUtils::setCursor(30, 3);
		HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
		cout << board.playerName;
		SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
		cout << ", wybierz w jaki sposob chcesz wygenerowac plansze";

		if (game.versusPlayer) {
			CursorUtils::setCursor(25, 4);
			SetConsoleTextAttribute(hOut, FOREGROUND_RED);
			cout << "PAMIETAJ, ABY NIE POKAZYWAC ROZLOSOWANEJ PLANSZY SWOJEMY OPONENTOWI!" << endl;
		}
		FrameUtils::createFrame("Losowe generowanie", choose == 0, 1);
		FrameUtils::createFrame("Reczne generowanie", choose == 1, 2);
		FrameUtils::createMovementListener(choose, end, 2);
	}
	switch (choose) {
	case 0:
		if (!generateRandomMap(board)) chooseGenerationType(game, board);
		break;
	case 1:
	default:
		cout << "err" << endl;
		break;
	}
}

bool MapGenerator::generateRandomMap(Board &board)
{
	int ulozenie1 = 1;
	do
	{
		if (ulozenie1 == 1)
		{
			doGenerateRandomMap(board);
		}
		doShowDots(board.gameBoard);
		int choose = 1;
		bool end = false;
		unsigned char ch = 171;
		while (end == false)
		{
			CursorUtils::setCursor(1, 1);
			cout << endl << endl;
			FrameUtils::createFrame("Rozlosuj jeszcze raz", choose == 1, 1, 20, -4);
			FrameUtils::createFrame("Super ulozenie, gramy", choose == 2, 2, 20, -4);
			FrameUtils::createFrame("Powrot", choose == 3, 3, 20, -4);
			FrameUtils::createMovementListener(choose, end, 3);
		}
		ulozenie1 = choose;
		if (ulozenie1 == 3) break;
		if (ulozenie1 == 2) board.state = START_GAME;
	} while ((ulozenie1 != 2 && ulozenie1 != 0));
	system("cls");

	return ulozenie1 != 3;
}