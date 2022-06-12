#include "../utils/CursorUtils.h"
#include "../utils/FrameUtils.h"
#include "MapGenerator.h"
#include "../Board.h"
#include "../Game.h"
#include <random>

using namespace std;

random_device rd;
mt19937 generator(rd());
uniform_int_distribution<int> wierszL(0, 9);
uniform_int_distribution<int> kolumnaL(0, 9);
uniform_int_distribution<int> kierunekL(0, 3);

void MapGenerator::doGenerateRandomMap(int board[10][10])
{
	for (int c = 0; c <= 9; c++)
	{
		for (int d = 0; d <= 9; d++)
		{
			board[c][d] = 0;
		}
	}

	int wiersz = 0;
	int kolumna = 0;
	int kierunek = 0;

	do
	{
		wiersz = wierszL(generator);
		kolumna = kolumnaL(generator);
		kierunek = kierunekL(generator);


		// 0 - góra, 1 - dó³, 2 - prawo, 3 - lewo

		if (kierunek == 0 && wiersz - 3 >= 0 && board[wiersz][kolumna] == 0 && board[wiersz - 1][kolumna] == 0 && board[wiersz - 2][kolumna] == 0 && board[wiersz - 3][kolumna] == 0)
		{
			for (int i = 0; i < 4; i++)
				board[wiersz - i][kolumna] = 4;

			for (int a = 0; a < 3; a++)
			{
				for (int b = 0; b < 6; b++)
				{
					if (kolumna - 1 + a >= 0 && kolumna - 1 + a <= 9 && wiersz + 1 - b >= 0 && wiersz + 1 - b <= 9 && board[wiersz + 1 - b][kolumna - 1 + a] == 0)
						board[wiersz + 1 - b][kolumna - 1 + a] = -1;
				}


			}
		}
		if (kierunek == 1 && wiersz + 3 <= 9 && board[wiersz][kolumna] == 0 && board[wiersz + 1][kolumna] == 0 && board[wiersz + 2][kolumna] == 0 && board[wiersz + 3][kolumna] == 0)
		{
			for (int i = 0; i < 4; i++)
				board[wiersz + i][kolumna] = 4;

			for (int a = 0; a < 3; a++)
			{
				for (int b = 0; b < 6; b++)
				{
					if (kolumna - 1 + a >= 0 && kolumna - 1 + a <= 9 && wiersz - 1 + b >= 0 && wiersz - 1 + b <= 9 && board[wiersz - 1 + b][kolumna - 1 + a] == 0)
						board[wiersz - 1 + b][kolumna - 1 + a] = -1;
				}
			}
		}
		if (kierunek == 2 && kolumna + 3 <= 9 && board[wiersz][kolumna] == 0 && board[wiersz][kolumna + 1] == 0 && board[wiersz][kolumna + 2] == 0 && board[wiersz][kolumna + 3] == 0)
		{
			for (int i = 0; i < 4; i++)
				board[wiersz][kolumna + i] = 4;

			for (int a = 0; a < 3; a++)
			{
				for (int b = 0; b < 6; b++)
				{
					if (wiersz - 1 + a >= 0 && wiersz - 1 + a <= 9 && kolumna - 1 + b >= 0 && kolumna - 1 + b <= 9 && board[wiersz - 1 + a][kolumna - 1 + b] == 0)
						board[wiersz - 1 + a][kolumna - 1 + b] = -1;
				}
			}
		}
		if (kierunek == 3 && kolumna - 3 >= 0 && board[wiersz][kolumna] == 0 && board[wiersz][kolumna - 1] == 0 && board[wiersz][kolumna - 2] == 0 && board[wiersz][kolumna - 3] == 0)
		{
			for (int i = 0; i < 4; i++)
				board[wiersz][kolumna - i] = 4;

			for (int a = 0; a < 3; a++)
			{
				for (int b = 0; b < 6; b++)
				{
					if (wiersz - 1 + a >= 0 && wiersz - 1 + a <= 9 && kolumna + 1 - b >= 0 && kolumna + 1 - b <= 9 && board[wiersz - 1 + a][kolumna + 1 - b] == 0)
						board[wiersz - 1 + a][kolumna + 1 - b] = -1;
				}
			}
		}

	} while (board[wiersz][kolumna] != 4);

	do
	{
		wiersz = wierszL(generator);
		kolumna = kolumnaL(generator);
		kierunek = kierunekL(generator);

		// 0 - góra, 1 - dó³, 2 - prawo, 3 - lewo

		if (kierunek == 0 && wiersz - 2 >= 0 && board[wiersz][kolumna] == 0 && board[wiersz - 1][kolumna] == 0 && board[wiersz - 2][kolumna] == 0)
		{
			for (int i = 0; i < 3; i++)
				board[wiersz - i][kolumna] = 3;

			for (int a = 0; a < 3; a++)
			{
				for (int b = 0; b < 5; b++)
				{
					if (kolumna - 1 + a >= 0 && kolumna - 1 + a <= 9 && wiersz + 1 - b >= 0 && wiersz + 1 - b <= 9 && board[wiersz + 1 - b][kolumna - 1 + a] == 0)
						board[wiersz + 1 - b][kolumna - 1 + a] = -1;
				}
			}
		}
		if (kierunek == 1 && wiersz + 2 <= 9 && board[wiersz][kolumna] == 0 && board[wiersz + 1][kolumna] == 0 && board[wiersz + 2][kolumna] == 0)
		{
			for (int i = 0; i < 3; i++)
				board[wiersz + i][kolumna] = 3;

			for (int a = 0; a < 3; a++)
			{
				for (int b = 0; b < 5; b++)
				{
					if (kolumna - 1 + a >= 0 && kolumna - 1 + a <= 9 && wiersz - 1 + b >= 0 && wiersz - 1 + b <= 9 && board[wiersz - 1 + b][kolumna - 1 + a] == 0)
						board[wiersz - 1 + b][kolumna - 1 + a] = -1;
				}
			}
		}
		if (kierunek == 2 && kolumna + 2 <= 9 && board[wiersz][kolumna] == 0 && board[wiersz][kolumna + 1] == 0 && board[wiersz][kolumna + 2] == 0)
		{
			for (int i = 0; i < 3; i++)
				board[wiersz][kolumna + i] = 3;

			for (int a = 0; a < 3; a++)
			{
				for (int b = 0; b < 5; b++)
				{
					if (wiersz - 1 + a >= 0 && wiersz - 1 + a <= 9 && kolumna - 1 + b >= 0 && kolumna - 1 + b <= 9 && board[wiersz - 1 + a][kolumna - 1 + b] == 0)
						board[wiersz - 1 + a][kolumna - 1 + b] = -1;
				}
			}
		}
		if (kierunek == 3 && kolumna - 2 >= 0 && board[wiersz][kolumna] == 0 && board[wiersz][kolumna - 1] == 0 && board[wiersz][kolumna - 2] == 0)
		{
			for (int i = 0; i < 3; i++)
				board[wiersz][kolumna - i] = 3;

			for (int a = 0; a < 3; a++)
			{
				for (int b = 0; b < 5; b++)
				{
					if (wiersz - 1 + a >= 0 && wiersz - 1 + a <= 9 && kolumna + 1 - b >= 0 && kolumna + 1 - b <= 9 && board[wiersz - 1 + a][kolumna + 1 - b] == 0)
						board[wiersz - 1 + a][kolumna + 1 - b] = -1;
				}
			}
		}

	} while (board[wiersz][kolumna] != 3);

	do
	{
		wiersz = wierszL(generator);
		kolumna = kolumnaL(generator);
		kierunek = kierunekL(generator);

		// 0 - góra, 1 - dó³, 2 - prawo, 3 - lewo

		if (kierunek == 0 && wiersz - 2 >= 0 && board[wiersz][kolumna] == 0 && board[wiersz - 1][kolumna] == 0 && board[wiersz - 2][kolumna] == 0)
		{
			for (int i = 0; i < 3; i++)
				board[wiersz - i][kolumna] = 3;

			for (int a = 0; a < 3; a++)
			{
				for (int b = 0; b < 5; b++)
				{
					if (kolumna - 1 + a >= 0 && kolumna - 1 + a <= 9 && wiersz + 1 - b >= 0 && wiersz + 1 - b <= 9 && board[wiersz + 1 - b][kolumna - 1 + a] == 0)
						board[wiersz + 1 - b][kolumna - 1 + a] = -1;
				}
			}
		}
		if (kierunek == 1 && wiersz + 2 <= 9 && board[wiersz][kolumna] == 0 && board[wiersz + 1][kolumna] == 0 && board[wiersz + 2][kolumna] == 0)
		{
			for (int i = 0; i < 3; i++)
				board[wiersz + i][kolumna] = 3;

			for (int a = 0; a < 3; a++)
			{
				for (int b = 0; b < 5; b++)
				{
					if (kolumna - 1 + a >= 0 && kolumna - 1 + a <= 9 && wiersz - 1 + b >= 0 && wiersz - 1 + b <= 9 && board[wiersz - 1 + b][kolumna - 1 + a] == 0)
						board[wiersz - 1 + b][kolumna - 1 + a] = -1;
				}
			}
		}
		if (kierunek == 2 && kolumna + 2 <= 9 && board[wiersz][kolumna] == 0 && board[wiersz][kolumna + 1] == 0 && board[wiersz][kolumna + 2] == 0)
		{
			for (int i = 0; i < 3; i++)
				board[wiersz][kolumna + i] = 3;

			for (int a = 0; a < 3; a++)
			{
				for (int b = 0; b < 5; b++)
				{
					if (wiersz - 1 + a >= 0 && wiersz - 1 + a <= 9 && kolumna - 1 + b >= 0 && kolumna - 1 + b <= 9 && board[wiersz - 1 + a][kolumna - 1 + b] == 0)
						board[wiersz - 1 + a][kolumna - 1 + b] = -1;
				}
			}
		}
		if (kierunek == 3 && kolumna - 2 >= 0 && board[wiersz][kolumna] == 0 && board[wiersz][kolumna - 1] == 0 && board[wiersz][kolumna - 2] == 0)
		{
			for (int i = 0; i < 3; i++)
				board[wiersz][kolumna - i] = 3;

			for (int a = 0; a < 3; a++)
			{
				for (int b = 0; b < 5; b++)
				{
					if (wiersz - 1 + a >= 0 && wiersz - 1 + a <= 9 && kolumna + 1 - b >= 0 && kolumna + 1 - b <= 9 && board[wiersz - 1 + a][kolumna + 1 - b] == 0)
						board[wiersz - 1 + a][kolumna + 1 - b] = -1;
				}
			}
		}

	} while (board[wiersz][kolumna] != 3);

	do
	{
		wiersz = wierszL(generator);
		kolumna = kolumnaL(generator);
		kierunek = kierunekL(generator);

		// 0 - góra, 1 - dó³, 2 - prawo, 3 - lewo

		if (kierunek == 0 && wiersz - 1 >= 0 && board[wiersz][kolumna] == 0 && board[wiersz - 1][kolumna] == 0)
		{
			for (int i = 0; i < 2; i++)
				board[wiersz - i][kolumna] = 2;

			for (int a = 0; a < 3; a++)
			{
				for (int b = 0; b < 4; b++)
				{
					if (kolumna - 1 + a >= 0 && kolumna - 1 + a <= 9 && wiersz + 1 - b >= 0 && wiersz + 1 - b <= 9 && board[wiersz + 1 - b][kolumna - 1 + a] == 0)
						board[wiersz + 1 - b][kolumna - 1 + a] = -1;
				}
			}
		}
		if (kierunek == 1 && wiersz + 1 <= 9 && board[wiersz][kolumna] == 0 && board[wiersz + 1][kolumna] == 0)
		{
			for (int i = 0; i < 2; i++)
				board[wiersz + i][kolumna] = 2;

			for (int a = 0; a < 3; a++)
			{
				for (int b = 0; b < 4; b++)
				{
					if (kolumna - 1 + a >= 0 && kolumna - 1 + a <= 9 && wiersz - 1 + b >= 0 && wiersz - 1 + b <= 9 && board[wiersz - 1 + b][kolumna - 1 + a] == 0)
						board[wiersz - 1 + b][kolumna - 1 + a] = -1;
				}
			}
		}
		if (kierunek == 2 && kolumna + 1 <= 9 && board[wiersz][kolumna] == 0 && board[wiersz][kolumna + 1] == 0)
		{
			for (int i = 0; i < 2; i++)
				board[wiersz][kolumna + i] = 2;

			for (int a = 0; a < 3; a++)
			{
				for (int b = 0; b < 4; b++)
				{
					if (wiersz - 1 + a >= 0 && wiersz - 1 + a <= 9 && kolumna - 1 + b >= 0 && kolumna - 1 + b <= 9 && board[wiersz - 1 + a][kolumna - 1 + b] == 0)
						board[wiersz - 1 + a][kolumna - 1 + b] = -1;
				}
			}
		}
		if (kierunek == 3 && kolumna - 1 >= 0 && board[wiersz][kolumna] == 0 && board[wiersz][kolumna - 1] == 0)
		{
			for (int i = 0; i < 2; i++)
				board[wiersz][kolumna - i] = 2;

			for (int a = 0; a < 3; a++)
			{
				for (int b = 0; b < 4; b++)
				{
					if (wiersz - 1 + a >= 0 && wiersz - 1 + a <= 9 && kolumna + 1 - b >= 0 && kolumna + 1 - b <= 9 && board[wiersz - 1 + a][kolumna + 1 - b] == 0)
						board[wiersz - 1 + a][kolumna + 1 - b] = -1;
				}
			}
		}

	} while (board[wiersz][kolumna] != 2);

	do
	{
		wiersz = wierszL(generator);
		kolumna = kolumnaL(generator);
		kierunek = kierunekL(generator);

		// 0 - góra, 1 - dó³, 2 - prawo, 3 - lewo

		if (kierunek == 0 && wiersz - 1 >= 0 && board[wiersz][kolumna] == 0 && board[wiersz - 1][kolumna] == 0)
		{
			for (int i = 0; i < 2; i++)
				board[wiersz - i][kolumna] = 2;

			for (int a = 0; a < 3; a++)
			{
				for (int b = 0; b < 4; b++)
				{
					if (kolumna - 1 + a >= 0 && kolumna - 1 + a <= 9 && wiersz + 1 - b >= 0 && wiersz + 1 - b <= 9 && board[wiersz + 1 - b][kolumna - 1 + a] == 0)
						board[wiersz + 1 - b][kolumna - 1 + a] = -1;
				}
			}
		}
		if (kierunek == 1 && wiersz + 1 <= 9 && board[wiersz][kolumna] == 0 && board[wiersz + 1][kolumna] == 0)
		{
			for (int i = 0; i < 2; i++)
				board[wiersz + i][kolumna] = 2;

			for (int a = 0; a < 3; a++)
			{
				for (int b = 0; b < 4; b++)
				{
					if (kolumna - 1 + a >= 0 && kolumna - 1 + a <= 9 && wiersz - 1 + b >= 0 && wiersz - 1 + b <= 9 && board[wiersz - 1 + b][kolumna - 1 + a] == 0)
						board[wiersz - 1 + b][kolumna - 1 + a] = -1;
				}
			}
		}
		if (kierunek == 2 && kolumna + 1 <= 9 && board[wiersz][kolumna] == 0 && board[wiersz][kolumna + 1] == 0)
		{
			for (int i = 0; i < 2; i++)
				board[wiersz][kolumna + i] = 2;

			for (int a = 0; a < 3; a++)
			{
				for (int b = 0; b < 4; b++)
				{
					if (wiersz - 1 + a >= 0 && wiersz - 1 + a <= 9 && kolumna - 1 + b >= 0 && kolumna - 1 + b <= 9 && board[wiersz - 1 + a][kolumna - 1 + b] == 0)
						board[wiersz - 1 + a][kolumna - 1 + b] = -1;
				}
			}
		}
		if (kierunek == 3 && kolumna - 1 >= 0 && board[wiersz][kolumna] == 0 && board[wiersz][kolumna - 1] == 0)
		{
			for (int i = 0; i < 2; i++)
				board[wiersz][kolumna - i] = 2;

			for (int a = 0; a < 3; a++)
			{
				for (int b = 0; b < 4; b++)
				{
					if (wiersz - 1 + a >= 0 && wiersz - 1 + a <= 9 && kolumna + 1 - b >= 0 && kolumna + 1 - b <= 9 && board[wiersz - 1 + a][kolumna + 1 - b] == 0)
						board[wiersz - 1 + a][kolumna + 1 - b] = -1;
				}
			}
		}

	} while (board[wiersz][kolumna] != 2);

	do
	{
		wiersz = wierszL(generator);
		kolumna = kolumnaL(generator);
		kierunek = kierunekL(generator);

		// 0 - góra, 1 - dó³, 2 - prawo, 3 - lewo

		if (kierunek == 0 && wiersz - 1 >= 0 && board[wiersz][kolumna] == 0 && board[wiersz - 1][kolumna] == 0)
		{
			for (int i = 0; i < 2; i++)
				board[wiersz - i][kolumna] = 2;

			for (int a = 0; a < 3; a++)
			{
				for (int b = 0; b < 4; b++)
				{
					if (kolumna - 1 + a >= 0 && kolumna - 1 + a <= 9 && wiersz + 1 - b >= 0 && wiersz + 1 - b <= 9 && board[wiersz + 1 - b][kolumna - 1 + a] == 0)
						board[wiersz + 1 - b][kolumna - 1 + a] = -1;
				}
			}
		}
		if (kierunek == 1 && wiersz + 1 <= 9 && board[wiersz][kolumna] == 0 && board[wiersz + 1][kolumna] == 0)
		{
			for (int i = 0; i < 2; i++)
				board[wiersz + i][kolumna] = 2;

			for (int a = 0; a < 3; a++)
			{
				for (int b = 0; b < 4; b++)
				{
					if (kolumna - 1 + a >= 0 && kolumna - 1 + a <= 9 && wiersz - 1 + b >= 0 && wiersz - 1 + b <= 9 && board[wiersz - 1 + b][kolumna - 1 + a] == 0)
						board[wiersz - 1 + b][kolumna - 1 + a] = -1;
				}
			}
		}
		if (kierunek == 2 && kolumna + 1 <= 9 && board[wiersz][kolumna] == 0 && board[wiersz][kolumna + 1] == 0)
		{
			for (int i = 0; i < 2; i++)
				board[wiersz][kolumna + i] = 2;

			for (int a = 0; a < 3; a++)
			{
				for (int b = 0; b < 4; b++)
				{
					if (wiersz - 1 + a >= 0 && wiersz - 1 + a <= 9 && kolumna - 1 + b >= 0 && kolumna - 1 + b <= 9 && board[wiersz - 1 + a][kolumna - 1 + b] == 0)
						board[wiersz - 1 + a][kolumna - 1 + b] = -1;
				}
			}
		}
		if (kierunek == 3 && kolumna - 1 >= 0 && board[wiersz][kolumna] == 0 && board[wiersz][kolumna - 1] == 0)
		{
			for (int i = 0; i < 2; i++)
				board[wiersz][kolumna - i] = 2;

			for (int a = 0; a < 3; a++)
			{
				for (int b = 0; b < 4; b++)
				{
					if (wiersz - 1 + a >= 0 && wiersz - 1 + a <= 9 && kolumna + 1 - b >= 0 && kolumna + 1 - b <= 9 && board[wiersz - 1 + a][kolumna + 1 - b] == 0)
						board[wiersz - 1 + a][kolumna + 1 - b] = -1;
				}
			}
		}

	} while (board[wiersz][kolumna] != 2);


	do
	{
		wiersz = wierszL(generator);
		kolumna = kolumnaL(generator);

		if (board[wiersz][kolumna] == 0)
		{
			board[wiersz][kolumna] = 1;

			for (int a = 0; a < 3; a++)
			{
				for (int b = 0; b < 3; b++)
				{
					if (kolumna - 1 + a >= 0 && kolumna - 1 + a <= 9 && wiersz + 1 - b >= 0 && wiersz + 1 - b <= 9 && board[wiersz + 1 - b][kolumna - 1 + a] == 0)
						board[wiersz + 1 - b][kolumna - 1 + a] = -1;
				}
			}
		}

	} while (board[wiersz][kolumna] != 1);

	do
	{
		wiersz = wierszL(generator);
		kolumna = kolumnaL(generator);

		if (board[wiersz][kolumna] == 0)
		{
			board[wiersz][kolumna] = 1;

			for (int a = 0; a < 3; a++)
			{
				for (int b = 0; b < 3; b++)
				{
					if (kolumna - 1 + a >= 0 && kolumna - 1 + a <= 9 && wiersz + 1 - b >= 0 && wiersz + 1 - b <= 9 && board[wiersz + 1 - b][kolumna - 1 + a] == 0)
						board[wiersz + 1 - b][kolumna - 1 + a] = -1;
				}
			}
		}

	} while (board[wiersz][kolumna] != 1);

	do
	{
		wiersz = wierszL(generator);
		kolumna = kolumnaL(generator);

		if (board[wiersz][kolumna] == 0)
		{
			board[wiersz][kolumna] = 1;

			for (int a = 0; a < 3; a++)
			{
				for (int b = 0; b < 3; b++)
				{
					if (kolumna - 1 + a >= 0 && kolumna - 1 + a <= 9 && wiersz + 1 - b >= 0 && wiersz + 1 - b <= 9 && board[wiersz + 1 - b][kolumna - 1 + a] == 0)
						board[wiersz + 1 - b][kolumna - 1 + a] = -1;
				}
			}
		}

	} while (board[wiersz][kolumna] != 1);

	do
	{
		wiersz = wierszL(generator);
		kolumna = kolumnaL(generator);

		if (board[wiersz][kolumna] == 0)
		{
			board[wiersz][kolumna] = 1;

			for (int a = 0; a < 3; a++)
			{
				for (int b = 0; b < 3; b++)
				{
					if (kolumna - 1 + a >= 0 && kolumna - 1 + a <= 9 && wiersz + 1 - b >= 0 && wiersz + 1 - b <= 9 && board[wiersz + 1 - b][kolumna - 1 + a] == 0)
						board[wiersz + 1 - b][kolumna - 1 + a] = -1;
				}
			}
		}

	} while (board[wiersz][kolumna] != 1);
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

bool MapGenerator::generateRandomMap(Board board)
{
	int ulozenie1 = 1;
	do
	{
		if (ulozenie1 == 1)
		{
			doGenerateRandomMap(board.gameBoard);
			bool check = true;

			while (check == true)
			{
				int sprawdzam[4] = { 0, 0, 0, 0 };
				for (int p = 0; p <= 9; p++)
				{
					for (int q = 0; q <= 9; q++)
					{
						if (board.gameBoard[p][q] == 1)                          // Losowanie planszszy a nastêpnie sprawdzenie,
							sprawdzam[0] += 1;                           // czy jest poprawnie ulozona, poprzez policzenie ilosci statkow.
						else if (board.gameBoard[p][q] == 2)
							sprawdzam[1] += 1;
						else if (board.gameBoard[p][q] == 3)
							sprawdzam[2] += 1;
						else if (board.gameBoard[p][q] == 4)
							sprawdzam[3] += 1;
					}
				}

				if (sprawdzam[0] == 4 && sprawdzam[1] == 6 && sprawdzam[2] == 6 && sprawdzam[3] == 4)
					check = false;
				else
					doGenerateRandomMap(board.gameBoard);
			}
		}
		doShowDots(board.gameBoard);
		int choose = 1;
		bool end = false;
		char ch = 171;
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