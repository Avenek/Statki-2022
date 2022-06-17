#include "../utils/CursorUtils.h"
#include "../utils/FrameUtils.h"
#include "MapGenerator.h"
#include "../Board.h"
#include "../Game.h"
#include <random>

using namespace std;



void MapGenerator::doGenerateRandomMap(int board[10][10])
{
	random_device rd;
	mt19937 generator(rd());
	uniform_int_distribution<int> rowL(0, 9);
	uniform_int_distribution<int> columnL(0, 9);
	uniform_int_distribution<int> directionL(0, 3);
	for (int c = 0; c <= 9; c++)
	{
		for (int d = 0; d <= 9; d++)
		{
			board[c][d] = 0;
		}
	}

	int row = 0;
	int column = 0;
	int direction = 0;

	do
	{
		row = rowL(generator);
		column = columnL(generator);
		direction = directionL(generator);


		// 0 - góra, 1 - dó³, 2 - prawo, 3 - lewo

		if (direction == 0 && row - 3 >= 0 && board[row][column] == 0 && board[row - 1][column] == 0 && board[row - 2][column] == 0 && board[row - 3][column] == 0)
		{
			for (int i = 0; i < 4; i++)
				board[row - i][column] = 4;

			for (int a = 0; a < 3; a++)
			{
				for (int b = 0; b < 6; b++)
				{
					if (column - 1 + a >= 0 && column - 1 + a <= 9 && row + 1 - b >= 0 && row + 1 - b <= 9 && board[row + 1 - b][column - 1 + a] == 0)
						board[row + 1 - b][column - 1 + a] = -1;
				}


			}
		}
		if (direction == 1 && row + 3 <= 9 && board[row][column] == 0 && board[row + 1][column] == 0 && board[row + 2][column] == 0 && board[row + 3][column] == 0)
		{
			for (int i = 0; i < 4; i++)
				board[row + i][column] = 4;

			for (int a = 0; a < 3; a++)
			{
				for (int b = 0; b < 6; b++)
				{
					if (column - 1 + a >= 0 && column - 1 + a <= 9 && row - 1 + b >= 0 && row - 1 + b <= 9 && board[row - 1 + b][column - 1 + a] == 0)
						board[row - 1 + b][column - 1 + a] = -1;
				}
			}
		}
		if (direction == 2 && column + 3 <= 9 && board[row][column] == 0 && board[row][column + 1] == 0 && board[row][column + 2] == 0 && board[row][column + 3] == 0)
		{
			for (int i = 0; i < 4; i++)
				board[row][column + i] = 4;

			for (int a = 0; a < 3; a++)
			{
				for (int b = 0; b < 6; b++)
				{
					if (row - 1 + a >= 0 && row - 1 + a <= 9 && column - 1 + b >= 0 && column - 1 + b <= 9 && board[row - 1 + a][column - 1 + b] == 0)
						board[row - 1 + a][column - 1 + b] = -1;
				}
			}
		}
		if (direction == 3 && column - 3 >= 0 && board[row][column] == 0 && board[row][column - 1] == 0 && board[row][column - 2] == 0 && board[row][column - 3] == 0)
		{
			for (int i = 0; i < 4; i++)
				board[row][column - i] = 4;

			for (int a = 0; a < 3; a++)
			{
				for (int b = 0; b < 6; b++)
				{
					if (row - 1 + a >= 0 && row - 1 + a <= 9 && column + 1 - b >= 0 && column + 1 - b <= 9 && board[row - 1 + a][column + 1 - b] == 0)
						board[row - 1 + a][column + 1 - b] = -1;
				}
			}
		}

	} while (board[row][column] != 4);

	do
	{
		row = rowL(generator);
		column = columnL(generator);
		direction = directionL(generator);

		// 0 - góra, 1 - dó³, 2 - prawo, 3 - lewo

		if (direction == 0 && row - 2 >= 0 && board[row][column] == 0 && board[row - 1][column] == 0 && board[row - 2][column] == 0)
		{
			for (int i = 0; i < 3; i++)
				board[row - i][column] = 3;

			for (int a = 0; a < 3; a++)
			{
				for (int b = 0; b < 5; b++)
				{
					if (column - 1 + a >= 0 && column - 1 + a <= 9 && row + 1 - b >= 0 && row + 1 - b <= 9 && board[row + 1 - b][column - 1 + a] == 0)
						board[row + 1 - b][column - 1 + a] = -1;
				}
			}
		}
		if (direction == 1 && row + 2 <= 9 && board[row][column] == 0 && board[row + 1][column] == 0 && board[row + 2][column] == 0)
		{
			for (int i = 0; i < 3; i++)
				board[row + i][column] = 3;

			for (int a = 0; a < 3; a++)
			{
				for (int b = 0; b < 5; b++)
				{
					if (column - 1 + a >= 0 && column - 1 + a <= 9 && row - 1 + b >= 0 && row - 1 + b <= 9 && board[row - 1 + b][column - 1 + a] == 0)
						board[row - 1 + b][column - 1 + a] = -1;
				}
			}
		}
		if (direction == 2 && column + 2 <= 9 && board[row][column] == 0 && board[row][column + 1] == 0 && board[row][column + 2] == 0)
		{
			for (int i = 0; i < 3; i++)
				board[row][column + i] = 3;

			for (int a = 0; a < 3; a++)
			{
				for (int b = 0; b < 5; b++)
				{
					if (row - 1 + a >= 0 && row - 1 + a <= 9 && column - 1 + b >= 0 && column - 1 + b <= 9 && board[row - 1 + a][column - 1 + b] == 0)
						board[row - 1 + a][column - 1 + b] = -1;
				}
			}
		}
		if (direction == 3 && column - 2 >= 0 && board[row][column] == 0 && board[row][column - 1] == 0 && board[row][column - 2] == 0)
		{
			for (int i = 0; i < 3; i++)
				board[row][column - i] = 3;

			for (int a = 0; a < 3; a++)
			{
				for (int b = 0; b < 5; b++)
				{
					if (row - 1 + a >= 0 && row - 1 + a <= 9 && column + 1 - b >= 0 && column + 1 - b <= 9 && board[row - 1 + a][column + 1 - b] == 0)
						board[row - 1 + a][column + 1 - b] = -1;
				}
			}
		}

	} while (board[row][column] != 3);

	do
	{
		row = rowL(generator);
		column = columnL(generator);
		direction = directionL(generator);

		// 0 - góra, 1 - dó³, 2 - prawo, 3 - lewo

		if (direction == 0 && row - 2 >= 0 && board[row][column] == 0 && board[row - 1][column] == 0 && board[row - 2][column] == 0)
		{
			for (int i = 0; i < 3; i++)
				board[row - i][column] = 3;

			for (int a = 0; a < 3; a++)
			{
				for (int b = 0; b < 5; b++)
				{
					if (column - 1 + a >= 0 && column - 1 + a <= 9 && row + 1 - b >= 0 && row + 1 - b <= 9 && board[row + 1 - b][column - 1 + a] == 0)
						board[row + 1 - b][column - 1 + a] = -1;
				}
			}
		}
		if (direction == 1 && row + 2 <= 9 && board[row][column] == 0 && board[row + 1][column] == 0 && board[row + 2][column] == 0)
		{
			for (int i = 0; i < 3; i++)
				board[row + i][column] = 3;

			for (int a = 0; a < 3; a++)
			{
				for (int b = 0; b < 5; b++)
				{
					if (column - 1 + a >= 0 && column - 1 + a <= 9 && row - 1 + b >= 0 && row - 1 + b <= 9 && board[row - 1 + b][column - 1 + a] == 0)
						board[row - 1 + b][column - 1 + a] = -1;
				}
			}
		}
		if (direction == 2 && column + 2 <= 9 && board[row][column] == 0 && board[row][column + 1] == 0 && board[row][column + 2] == 0)
		{
			for (int i = 0; i < 3; i++)
				board[row][column + i] = 3;

			for (int a = 0; a < 3; a++)
			{
				for (int b = 0; b < 5; b++)
				{
					if (row - 1 + a >= 0 && row - 1 + a <= 9 && column - 1 + b >= 0 && column - 1 + b <= 9 && board[row - 1 + a][column - 1 + b] == 0)
						board[row - 1 + a][column - 1 + b] = -1;
				}
			}
		}
		if (direction == 3 && column - 2 >= 0 && board[row][column] == 0 && board[row][column - 1] == 0 && board[row][column - 2] == 0)
		{
			for (int i = 0; i < 3; i++)
				board[row][column - i] = 3;

			for (int a = 0; a < 3; a++)
			{
				for (int b = 0; b < 5; b++)
				{
					if (row - 1 + a >= 0 && row - 1 + a <= 9 && column + 1 - b >= 0 && column + 1 - b <= 9 && board[row - 1 + a][column + 1 - b] == 0)
						board[row - 1 + a][column + 1 - b] = -1;
				}
			}
		}

	} while (board[row][column] != 3);

	do
	{
		row = rowL(generator);
		column = columnL(generator);
		direction = directionL(generator);

		// 0 - góra, 1 - dó³, 2 - prawo, 3 - lewo

		if (direction == 0 && row - 1 >= 0 && board[row][column] == 0 && board[row - 1][column] == 0)
		{
			for (int i = 0; i < 2; i++)
				board[row - i][column] = 2;

			for (int a = 0; a < 3; a++)
			{
				for (int b = 0; b < 4; b++)
				{
					if (column - 1 + a >= 0 && column - 1 + a <= 9 && row + 1 - b >= 0 && row + 1 - b <= 9 && board[row + 1 - b][column - 1 + a] == 0)
						board[row + 1 - b][column - 1 + a] = -1;
				}
			}
		}
		if (direction == 1 && row + 1 <= 9 && board[row][column] == 0 && board[row + 1][column] == 0)
		{
			for (int i = 0; i < 2; i++)
				board[row + i][column] = 2;

			for (int a = 0; a < 3; a++)
			{
				for (int b = 0; b < 4; b++)
				{
					if (column - 1 + a >= 0 && column - 1 + a <= 9 && row - 1 + b >= 0 && row - 1 + b <= 9 && board[row - 1 + b][column - 1 + a] == 0)
						board[row - 1 + b][column - 1 + a] = -1;
				}
			}
		}
		if (direction == 2 && column + 1 <= 9 && board[row][column] == 0 && board[row][column + 1] == 0)
		{
			for (int i = 0; i < 2; i++)
				board[row][column + i] = 2;

			for (int a = 0; a < 3; a++)
			{
				for (int b = 0; b < 4; b++)
				{
					if (row - 1 + a >= 0 && row - 1 + a <= 9 && column - 1 + b >= 0 && column - 1 + b <= 9 && board[row - 1 + a][column - 1 + b] == 0)
						board[row - 1 + a][column - 1 + b] = -1;
				}
			}
		}
		if (direction == 3 && column - 1 >= 0 && board[row][column] == 0 && board[row][column - 1] == 0)
		{
			for (int i = 0; i < 2; i++)
				board[row][column - i] = 2;

			for (int a = 0; a < 3; a++)
			{
				for (int b = 0; b < 4; b++)
				{
					if (row - 1 + a >= 0 && row - 1 + a <= 9 && column + 1 - b >= 0 && column + 1 - b <= 9 && board[row - 1 + a][column + 1 - b] == 0)
						board[row - 1 + a][column + 1 - b] = -1;
				}
			}
		}

	} while (board[row][column] != 2);

	do
	{
		row = rowL(generator);
		column = columnL(generator);
		direction = directionL(generator);

		// 0 - góra, 1 - dó³, 2 - prawo, 3 - lewo

		if (direction == 0 && row - 1 >= 0 && board[row][column] == 0 && board[row - 1][column] == 0)
		{
			for (int i = 0; i < 2; i++)
				board[row - i][column] = 2;

			for (int a = 0; a < 3; a++)
			{
				for (int b = 0; b < 4; b++)
				{
					if (column - 1 + a >= 0 && column - 1 + a <= 9 && row + 1 - b >= 0 && row + 1 - b <= 9 && board[row + 1 - b][column - 1 + a] == 0)
						board[row + 1 - b][column - 1 + a] = -1;
				}
			}
		}
		if (direction == 1 && row + 1 <= 9 && board[row][column] == 0 && board[row + 1][column] == 0)
		{
			for (int i = 0; i < 2; i++)
				board[row + i][column] = 2;

			for (int a = 0; a < 3; a++)
			{
				for (int b = 0; b < 4; b++)
				{
					if (column - 1 + a >= 0 && column - 1 + a <= 9 && row - 1 + b >= 0 && row - 1 + b <= 9 && board[row - 1 + b][column - 1 + a] == 0)
						board[row - 1 + b][column - 1 + a] = -1;
				}
			}
		}
		if (direction == 2 && column + 1 <= 9 && board[row][column] == 0 && board[row][column + 1] == 0)
		{
			for (int i = 0; i < 2; i++)
				board[row][column + i] = 2;

			for (int a = 0; a < 3; a++)
			{
				for (int b = 0; b < 4; b++)
				{
					if (row - 1 + a >= 0 && row - 1 + a <= 9 && column - 1 + b >= 0 && column - 1 + b <= 9 && board[row - 1 + a][column - 1 + b] == 0)
						board[row - 1 + a][column - 1 + b] = -1;
				}
			}
		}
		if (direction == 3 && column - 1 >= 0 && board[row][column] == 0 && board[row][column - 1] == 0)
		{
			for (int i = 0; i < 2; i++)
				board[row][column - i] = 2;

			for (int a = 0; a < 3; a++)
			{
				for (int b = 0; b < 4; b++)
				{
					if (row - 1 + a >= 0 && row - 1 + a <= 9 && column + 1 - b >= 0 && column + 1 - b <= 9 && board[row - 1 + a][column + 1 - b] == 0)
						board[row - 1 + a][column + 1 - b] = -1;
				}
			}
		}

	} while (board[row][column] != 2);

	do
	{
		row = rowL(generator);
		column = columnL(generator);
		direction = directionL(generator);

		// 0 - góra, 1 - dó³, 2 - prawo, 3 - lewo

		if (direction == 0 && row - 1 >= 0 && board[row][column] == 0 && board[row - 1][column] == 0)
		{
			for (int i = 0; i < 2; i++)
				board[row - i][column] = 2;

			for (int a = 0; a < 3; a++)
			{
				for (int b = 0; b < 4; b++)
				{
					if (column - 1 + a >= 0 && column - 1 + a <= 9 && row + 1 - b >= 0 && row + 1 - b <= 9 && board[row + 1 - b][column - 1 + a] == 0)
						board[row + 1 - b][column - 1 + a] = -1;
				}
			}
		}
		if (direction == 1 && row + 1 <= 9 && board[row][column] == 0 && board[row + 1][column] == 0)
		{
			for (int i = 0; i < 2; i++)
				board[row + i][column] = 2;

			for (int a = 0; a < 3; a++)
			{
				for (int b = 0; b < 4; b++)
				{
					if (column - 1 + a >= 0 && column - 1 + a <= 9 && row - 1 + b >= 0 && row - 1 + b <= 9 && board[row - 1 + b][column - 1 + a] == 0)
						board[row - 1 + b][column - 1 + a] = -1;
				}
			}
		}
		if (direction == 2 && column + 1 <= 9 && board[row][column] == 0 && board[row][column + 1] == 0)
		{
			for (int i = 0; i < 2; i++)
				board[row][column + i] = 2;

			for (int a = 0; a < 3; a++)
			{
				for (int b = 0; b < 4; b++)
				{
					if (row - 1 + a >= 0 && row - 1 + a <= 9 && column - 1 + b >= 0 && column - 1 + b <= 9 && board[row - 1 + a][column - 1 + b] == 0)
						board[row - 1 + a][column - 1 + b] = -1;
				}
			}
		}
		if (direction == 3 && column - 1 >= 0 && board[row][column] == 0 && board[row][column - 1] == 0)
		{
			for (int i = 0; i < 2; i++)
				board[row][column - i] = 2;

			for (int a = 0; a < 3; a++)
			{
				for (int b = 0; b < 4; b++)
				{
					if (row - 1 + a >= 0 && row - 1 + a <= 9 && column + 1 - b >= 0 && column + 1 - b <= 9 && board[row - 1 + a][column + 1 - b] == 0)
						board[row - 1 + a][column + 1 - b] = -1;
				}
			}
		}

	} while (board[row][column] != 2);


	do
	{
		row = rowL(generator);
		column = columnL(generator);

		if (board[row][column] == 0)
		{
			board[row][column] = 1;

			for (int a = 0; a < 3; a++)
			{
				for (int b = 0; b < 3; b++)
				{
					if (column - 1 + a >= 0 && column - 1 + a <= 9 && row + 1 - b >= 0 && row + 1 - b <= 9 && board[row + 1 - b][column - 1 + a] == 0)
						board[row + 1 - b][column - 1 + a] = -1;
				}
			}
		}

	} while (board[row][column] != 1);

	do
	{
		row = rowL(generator);
		column = columnL(generator);

		if (board[row][column] == 0)
		{
			board[row][column] = 1;

			for (int a = 0; a < 3; a++)
			{
				for (int b = 0; b < 3; b++)
				{
					if (column - 1 + a >= 0 && column - 1 + a <= 9 && row + 1 - b >= 0 && row + 1 - b <= 9 && board[row + 1 - b][column - 1 + a] == 0)
						board[row + 1 - b][column - 1 + a] = -1;
				}
			}
		}

	} while (board[row][column] != 1);

	do
	{
		row = rowL(generator);
		column = columnL(generator);

		if (board[row][column] == 0)
		{
			board[row][column] = 1;

			for (int a = 0; a < 3; a++)
			{
				for (int b = 0; b < 3; b++)
				{
					if (column - 1 + a >= 0 && column - 1 + a <= 9 && row + 1 - b >= 0 && row + 1 - b <= 9 && board[row + 1 - b][column - 1 + a] == 0)
						board[row + 1 - b][column - 1 + a] = -1;
				}
			}
		}

	} while (board[row][column] != 1);

	do
	{
		row = rowL(generator);
		column = columnL(generator);

		if (board[row][column] == 0)
		{
			board[row][column] = 1;

			for (int a = 0; a < 3; a++)
			{
				for (int b = 0; b < 3; b++)
				{
					if (column - 1 + a >= 0 && column - 1 + a <= 9 && row + 1 - b >= 0 && row + 1 - b <= 9 && board[row + 1 - b][column - 1 + a] == 0)
						board[row + 1 - b][column - 1 + a] = -1;
				}
			}
		}

	} while (board[row][column] != 1);
}
void spaces(int num)
{
	for (int a = 0; a < num; a++)
		cout << " ";
}
void deleteShip(int w, int k, int board[10][10])
{
	for (int a = 0; a < 3; a++)
	{
		for (int b = 0; b < 3; b++)
		{
			if (w > 1 && k > 1 && w < 8 && k < 8 && board[w - 1 + a][k - 1 + b] == -1)
			{
				if (board[w - 2 + a][k - 2 + b] < 1 && board[w - 2 + a][k - 1 + b] < 1 && board[w - 2 + a][k + b] < 1 && board[w - 1 + a][k - 2 + b] < 1 && board[w - 1 + a][k + b] < 1 && board[w + a][k - 2 + b] < 1 && board[w + a][k - 1 + b] < 1 && board[w + a][k + b] < 1)
				{
					board[w - 1 + a][k - 1 + b] = 0;

				}
			}
			else if (((w == 1 && k != 0 && k != 9) || (w == 8 && k != 0 && k != 9) || (k == 1 && w != 0 && w != 9) || (k == 8 && w != 0 && w != 9)))
			{
				if (w == 1 && k > 1 && k < 8)
				{
					if (a == 0)
					{
						if (board[w - 1 + a][k - 2 + b] < 1 && board[w - 1 + a][k + b] < 1 && board[w + a][k - 2 + b] < 1 && board[w + a][k - 1 + b] < 1 && board[w + a][k + b] < 1)
						{
							board[w - 1 + a][k - 1 + b] = 0;

						}
					}
					else
					{
						if (board[w - 2 + a][k - 2 + b] < 1 && board[w - 2 + a][k - 1 + b] < 1 && board[w - 2 + a][k + b] < 1 && board[w - 1 + a][k - 2 + b] < 1 && board[w - 1 + a][k + b] < 1 && board[w + a][k - 2 + b] < 1 && board[w + a][k - 1 + b] < 1 && board[w + a][k + b] < 1)
						{
							board[w - 1 + a][k - 1 + b] = 0;

						}
					}

				}
				else if (w == 8 && k > 1 && k < 8)
				{
					if (a == 2)
					{
						if (board[w - 2 + a][k - 2 + b] < 1 && board[w - 2 + a][k - 1 + b] < 1 && board[w - 2 + a][k + b] < 1 && board[w - 1 + a][k - 2 + b] < 1 && board[w - 1 + a][k + b] < 1)
						{
							board[w - 1 + a][k - 1 + b] = 0;

						}
					}
					else
					{
						if (board[w - 2 + a][k - 2 + b] < 1 && board[w - 2 + a][k - 1 + b] < 1 && board[w - 2 + a][k + b] < 1 && board[w - 1 + a][k - 2 + b] < 1 && board[w - 1 + a][k + b] < 1 && board[w + a][k - 2 + b] < 1 && board[w + a][k - 1 + b] < 1 && board[w + a][k + b] < 1)
						{
							board[w - 1 + a][k - 1 + b] = 0;

						}
					}

				}
				else if (k == 1 && w > 1 && w < 8)
				{
					if (b == 0)
					{
						if (board[w - 2 + a][k - 1 + b] < 1 && board[w - 2 + a][k + b] < 1 && board[w - 1 + a][k + b] < 1 && board[w + a][k - 1 + b] < 1 && board[w + a][k + b] < 1)
						{
							board[w - 1 + a][k - 1 + b] = 0;

						}

					}
					else
					{
						if (board[w - 2 + a][k - 2 + b] < 1 && board[w - 2 + a][k - 1 + b] < 1 && board[w - 2 + a][k + b] < 1 && board[w - 1 + a][k - 2 + b] < 1 && board[w - 1 + a][k + b] < 1 && board[w + a][k - 2 + b] < 1 && board[w + a][k - 1 + b] < 1 && board[w + a][k + b] < 1)
						{
							board[w - 1 + a][k - 1 + b] = 0;

						}

					}

				}
				else if (k == 8 && w > 1 && w < 8)
				{
					if (b == 2)
					{
						if (board[w - 2 + a][k - 2 + b] < 1 && board[w - 2 + a][k - 1 + b] < 1 && board[w - 1 + a][k - 2 + b] < 1 && board[w + a][k - 2 + b] < 1 && board[w + a][k - 1 + b] < 1)
						{
							board[w - 1 + a][k - 1 + b] = 0;

						}

					}
					else
					{
						if (board[w - 2 + a][k - 2 + b] < 1 && board[w - 2 + a][k - 1 + b] < 1 && board[w - 2 + a][k + b] < 1 && board[w - 1 + a][k - 2 + b] < 1 && board[w - 1 + a][k + b] < 1 && board[w + a][k - 2 + b] < 1 && board[w + a][k - 1 + b] < 1 && board[w + a][k + b] < 1)
						{
							board[w - 1 + a][k - 1 + b] = 0;

						}

					}

				}
				else if (w == 1 && k == 1)
				{
					if (a == 0 && b == 0)
						board[w - 1 + a][k - 1 + b] = 0;

					else if (a == 0 && b != 0)
					{
						if (board[w - 1 + a][k - 2 + b] < 1 && board[w - 1 + a][k + b] < 1 && board[w + a][k - 2 + b] < 1 && board[w + a][k - 1 + b] < 1 && board[w + a][k + b] < 1)
						{
							board[w - 1 + a][k - 1 + b] = 0;

						}
					}
					else if (a != 0 && b == 0)
					{
						if (board[w - 2 + a][k - 1 + b] < 1 && board[w - 2 + a][k + b] < 1 && board[w - 1 + a][k + b] < 1 && board[w + a][k - 1 + b] < 1 && board[w + a][k + b] < 1)
						{
							board[w - 1 + a][k - 1 + b] = 0;

						}
					}

					else
					{
						if (board[w - 2 + a][k - 2 + b] < 1 && board[w - 2 + a][k - 1 + b] < 1 && board[w - 2 + a][k + b] < 1 && board[w - 1 + a][k - 2 + b] < 1 && board[w - 1 + a][k + b] < 1 && board[w + a][k - 2 + b] < 1 && board[w + a][k - 1 + b] < 1 && board[w + a][k + b] < 1)
						{
							board[w - 1 + a][k - 1 + b] = 0;

						}
					}


				}
				else if (w == 1 && k == 8)
				{
					if (a == 0 && b == 2)
						board[w - 1 + a][k - 1 + b] = 0;

					else if (a == 0 && b != 2)
					{
						if (board[w - 1 + a][k - 2 + b] < 1 && board[w - 1 + a][k + b] < 1 && board[w + a][k - 2 + b] < 1 && board[w + a][k - 1 + b] < 1 && board[w + a][k + b] < 1)
						{
							board[w - 1 + a][k - 1 + b] = 0;

						}
					}
					else if (a != 0 && b == 2)
					{
						if (board[w - 2 + a][k - 2 + b] < 1 && board[w - 2 + a][k - 1 + b] < 1 && board[w - 1 + a][k - 2 + b] < 1 && board[w + a][k - 2 + b] < 1 && board[w + a][k - 1 + b] < 1)
						{
							board[w - 1 + a][k - 1 + b] = 0;

						}

					}

					else
					{
						if (board[w - 2 + a][k - 2 + b] < 1 && board[w - 2 + a][k - 1 + b] < 1 && board[w - 2 + a][k + b] < 1 && board[w - 1 + a][k - 2 + b] < 1 && board[w - 1 + a][k + b] < 1 && board[w + a][k - 2 + b] < 1 && board[w + a][k - 1 + b] < 1 && board[w + a][k + b] < 1)
						{
							board[w - 1 + a][k - 1 + b] = 0;

						}
					}

				}
				else if (w == 8 && k == 1)
				{
					if (a == 2 && b == 0)
						board[w - 1 + a][k - 1 + b] = 0;

					else if (a == 2 && b != 0)
					{
						if (board[w - 2 + a][k - 2 + b] < 1 && board[w - 2 + a][k - 1 + b] < 1 && board[w - 2 + a][k + b] < 1 && board[w - 1 + a][k - 2 + b] < 1 && board[w - 1 + a][k + b] < 1)
						{
							board[w - 1 + a][k - 1 + b] = 0;

						}
					}
					else if (a != 0 && b == 0)
					{
						if (board[w - 2 + a][k - 1 + b] < 1 && board[w - 2 + a][k + b] < 1 && board[w - 1 + a][k + b] < 1 && board[w + a][k - 1 + b] < 1 && board[w + a][k + b] < 1)
						{
							board[w - 1 + a][k - 1 + b] = 0;

						}
					}

					else if (a != 2 && b != 0)
					{
						if (board[w - 2 + a][k - 1 + b] < 1 && board[w - 2 + a][k + b] < 1 && board[w - 1 + a][k - 2 + b] < 1 && board[w - 1 + a][k + b] < 1 && board[w + a][k - 2 + b] < 1 && board[w + a][k - 1 + b] < 1 && board[w + a][k + b] < 1)
						{
							board[w - 1 + a][k - 1 + b] = 0;

						}
					}
					else
					{
						if (board[w - 2 + a][k - 1 + b] < 1 && board[w - 2 + a][k + b] < 1 && board[w - 1 + a][k + b] < 1)
						{
							board[w - 1 + a][k - 1 + b] = 0;

						}
					}

				}
				else if (w == 8 && k == 8)
				{
					if (a == 2 && b == 2)
						board[w - 1 + a][k - 1 + b] = 0;

					else if (a == 2 && b != 2)
					{
						if (board[w - 2 + a][k - 2 + b] < 1 && board[w - 2 + a][k - 1 + b] < 1 && board[w - 2 + a][k + b] < 1 && board[w - 1 + a][k - 2 + b] < 1 && board[w - 1 + a][k + b] < 1)
						{
							board[w - 1 + a][k - 1 + b] = 0;

						}
					}
					else if (a != 2 && b == 2)
					{
						if (board[w - 2 + a][k - 2 + b] < 1 && board[w - 2 + a][k - 1 + b] < 1 && board[w - 1 + a][k - 2 + b] < 1 && board[w + a][k - 2 + b] < 1 && board[w + a][k - 1 + b] < 1)
						{
							board[w - 1 + a][k - 1 + b] = 0;

						}

					}
					else
					{
						if (board[w - 2 + a][k - 2 + b] < 1 && board[w - 2 + a][k - 1 + b] < 1 && board[w - 2 + a][k + b] < 1 && board[w - 1 + a][k - 2 + b] < 1 && board[w - 1 + a][k + b] < 1 && board[w + a][k - 2 + b] < 1 && board[w + a][k - 1 + b] < 1 && board[w + a][k + b] < 1)
						{
							board[w - 1 + a][k - 1 + b] = 0;

						}
					}

				}

			}
			else if ((w == 0 && k != 0 && k != 9) || (w == 9 && k != 0 && k != 9) || (k == 0 && w != 0 && w != 9) || (k == 9 && w != 0 && w != 9))
			{
				if (w == 0 && k == 1)
				{
					if (a == 1 && b != 0)
					{

						if (board[w - 1 + a][k - 2 + b] < 1 && board[w - 1 + a][k + b] < 1 && board[w + a][k - 2 + b] < 1 && board[w + a][k - 1 + b] < 1 && board[w + a][k + b] < 1)
						{
							board[w - 1 + a][k - 1 + b] = 0;

						}
					}
					else if (a == 2 && b != 0)
					{
						if (board[w - 2 + a][k - 2 + b] < 1 && board[w - 2 + a][k - 1 + b] < 1 && board[w - 2 + a][k + b] < 1 && board[w - 1 + a][k - 2 + b] < 1 && board[w - 1 + a][k + b] < 1 && board[w + a][k - 2 + b] < 1 && board[w + a][k - 1 + b] < 1 && board[w + a][k + b] < 1)
						{
							board[w - 1 + a][k - 1 + b] = 0;

						}
					}
					else if (a == 1 && b == 0)
					{
						if (board[w - 1 + a][k + b] < 1 && board[w + a][k - 1 + b] < 1 && board[w + a][k + b] < 1)
						{
							board[w - 1 + a][k - 1 + b] = 0;
						}
					}
					else if (a == 2 && b == 0)
					{
						if (board[w - 2 + a][k - 1 + b] < 1 && board[w - 2 + a][k + b] < 1 && board[w - 1 + a][k + b] < 1 && board[w + a][k - 1 + b] < 1 && board[w + a][k + b] < 1)
						{
							board[w - 1 + a][k - 1 + b] = 0;

						}

					}
				}
				else if (w == 0 && k == 8)
				{
					if (a == 1 && b != 2)
					{
						if (board[w - 1 + a][k - 2 + b] < 1 && board[w - 1 + a][k + b] < 1 && board[w + a][k - 2 + b] < 1 && board[w + a][k - 1 + b] < 1 && board[w + a][k + b] < 1)
						{
							board[w - 1 + a][k - 1 + b] = 0;

						}
					}
					else if (a == 2 && b != 2)
					{
						if (board[w - 2 + a][k - 2 + b] < 1 && board[w - 2 + a][k - 1 + b] < 1 && board[w - 2 + a][k + b] < 1 && board[w - 1 + a][k - 2 + b] < 1 && board[w - 1 + a][k + b] < 1 && board[w + a][k - 2 + b] < 1 && board[w + a][k - 1 + b] < 1 && board[w + a][k + b] < 1)
						{
							board[w - 1 + a][k - 1 + b] = 0;

						}
					}
					else if (a == 1 && b == 2)
					{
						if (board[w - 1 + a][k - 2 + b] < 1 && board[w + a][k - 2 + b] < 1 && board[w + a][k - 1 + b] < 1)
						{
							board[w - 1 + a][k - 1 + b] = 0;
						}
					}
					else if (a == 2 && b == 2)
					{
						if (board[w - 2 + a][k - 2 + b] < 1 && board[w - 2 + a][k - 1 + b] < 1 && board[w - 1 + a][k - 2 + b] < 1 && board[w + a][k - 2 + b] < 1 && board[w + a][k - 1 + b] < 1)
						{
							board[w - 1 + a][k - 1 + b] = 0;

						}

					}

				}
				else if (w == 0 && k > 1 && k < 8)
				{
					if (a == 1)
					{
						if (board[w - 1 + a][k - 2 + b] < 1 && board[w - 1 + a][k + b] < 1 && board[w + a][k - 2 + b] < 1 && board[w + a][k - 1 + b] < 1 && board[w + a][k + b] < 1)
						{
							board[w - 1 + a][k - 1 + b] = 0;

						}
					}
					else if (a == 2)
					{
						if (board[w - 2 + a][k - 2 + b] < 1 && board[w - 2 + a][k - 1 + b] < 1 && board[w - 2 + a][k + b] < 1 && board[w - 1 + a][k - 2 + b] < 1 && board[w - 1 + a][k + b] < 1 && board[w + a][k - 2 + b] < 1 && board[w + a][k - 1 + b] < 1 && board[w + a][k + b] < 1)
						{
							board[w - 1 + a][k - 1 + b] = 0;

						}
					}

				}
				else if (w == 9 && k > 1 && k < 8)
				{
					if (a == 1)
					{
						if (board[w - 2 + a][k - 2 + b] < 1 && board[w - 2 + a][k - 1 + b] < 1 && board[w - 2 + a][k + b] < 1 && board[w - 1 + a][k - 2 + b] < 1 && board[w - 1 + a][k + b] < 1)
						{
							board[w - 1 + a][k - 1 + b] = 0;

						}
					}
					else if (a == 0)
					{
						if (board[w - 2 + a][k - 2 + b] < 1 && board[w - 2 + a][k - 1 + b] < 1 && board[w - 2 + a][k + b] < 1 && board[w - 1 + a][k - 2 + b] < 1 && board[w - 1 + a][k + b] < 1 && board[w + a][k - 2 + b] < 1 && board[w + a][k - 1 + b] < 1 && board[w + a][k + b] < 1)
						{
							board[w - 1 + a][k - 1 + b] = 0;

						}
					}


				}
				else if (w == 9 && k == 1)
				{
					if (a == 0 && b != 0)
					{
						if (board[w - 2 + a][k - 2 + b] < 1 && board[w - 2 + a][k - 1 + b] < 1 && board[w - 2 + a][k + b] < 1 && board[w - 1 + a][k - 2 + b] < 1 && board[w - 1 + a][k + b] < 1 && board[w + a][k - 2 + b] < 1 && board[w + a][k - 1 + b] < 1 && board[w + a][k + b] < 1)
						{
							board[w - 1 + a][k - 1 + b] = 0;

						}
					}
					else if (a == 1 && b != 0)
					{
						if (board[w - 2 + a][k - 2 + b] < 1 && board[w - 2 + a][k - 1 + b] < 1 && board[w - 2 + a][k + b] < 1 && board[w - 1 + a][k - 2 + b] < 1 && board[w - 1 + a][k + b] < 1)
						{
							board[w - 1 + a][k - 1 + b] = 0;

						}
					}
					else if (a == 0 && b == 0)
					{
						if (board[w - 2 + a][k - 1 + b] < 1 && board[w - 2 + a][k + b] < 1 && board[w - 1 + a][k + b] < 1 && board[w + a][k - 1 + b] < 1 && board[w + a][k + b] < 1)
						{
							board[w - 1 + a][k - 1 + b] = 0;
						}
					}
					else if (a == 1 && b == 0)
					{
						if (board[w - 1 + a][k + b] < 1 && board[w + a][k - 1 + b] < 1 && board[w + a][k + b] < 1)
						{
							board[w - 1 + a][k - 1 + b] = 0;

						}

					}

				}
				else if (w == 9 && k == 8)
				{

					if (a == 0 && b != 2)
					{
						if (board[w - 2 + a][k - 2 + b] < 1 && board[w - 2 + a][k - 1 + b] < 1 && board[w - 2 + a][k + b] < 1 && board[w - 1 + a][k - 2 + b] < 1 && board[w - 1 + a][k + b] < 1 && board[w + a][k - 2 + b] < 1 && board[w + a][k - 1 + b] < 1 && board[w + a][k + b] < 1)
						{
							board[w - 1 + a][k - 1 + b] = 0;

						}
					}
					else if (a == 1 && b != 2)
					{
						if (board[w - 2 + a][k - 2 + b] < 1 && board[w - 2 + a][k - 1 + b] < 1 && board[w - 2 + a][k + b] < 1 && board[w - 1 + a][k - 2 + b] < 1 && board[w - 1 + a][k + b] < 1)
						{
							board[w - 1 + a][k - 1 + b] = 0;

						}
					}
					else if (a == 0 && b == 2)
					{
						if (board[w - 2 + a][k - 2 + b] < 1 && board[w - 2 + a][k - 1 + b] < 1 && board[w - 1 + a][k - 2 + b] < 1 && board[w + a][k - 2 + b] < 1 && board[w + a][k - 1 + b] < 1)
						{
							board[w - 1 + a][k - 1 + b] = 0;
						}
					}
					else if (a == 1 && b == 2)
					{
						if (board[w - 2 + a][k - 2 + b] < 1 && board[w - 2 + a][k - 1 + b] < 1 && board[w - 1 + a][k - 2 + b] < 1 && board[w - 1 + a][k + b] < 1)
						{
							board[w - 1 + a][k - 1 + b] = 0;

						}

					}
				}
				else if (k == 0 && w > 1 && w < 8)
				{
					if (b == 1)
					{
						if (board[w - 2 + a][k - 1 + b] < 1 && board[w - 2 + a][k + b] < 1 && board[w - 1 + a][k + b] < 1 && board[w + a][k - 1 + b] < 1 && board[w + a][k + b] < 1)
						{
							board[w - 1 + a][k - 1 + b] = 0;

						}

					}
					else if (b == 2)
					{
						if (board[w - 2 + a][k - 2 + b] < 1 && board[w - 2 + a][k - 1 + b] < 1 && board[w - 2 + a][k + b] < 1 && board[w - 1 + a][k - 2 + b] < 1 && board[w - 1 + a][k + b] < 1 && board[w + a][k - 2 + b] < 1 && board[w + a][k - 1 + b] < 1 && board[w + a][k + b] < 1)
						{
							board[w - 1 + a][k - 1 + b] = 0;

						}

					}

				}
				else if (k == 0 && w == 1)
				{

					if (a == 0 && b == 1)
					{
						board[w - 1 + a][k - 1 + b] = 0;
					}
					else if (b == 2 && a != 0)
					{
						if (board[w - 2 + a][k - 2 + b] < 1 && board[w - 2 + a][k - 1 + b] < 1 && board[w - 2 + a][k + b] < 1 && board[w - 1 + a][k - 2 + b] < 1 && board[w - 1 + a][k + b] < 1 && board[w + a][k - 2 + b] < 1 && board[w + a][k - 1 + b] < 1 && board[w + a][k + b] < 1)
						{
							board[w - 1 + a][k - 1 + b] = 0;
						}
					}
					else if (b == 2 && a == 0)
					{
						if (board[w - 1 + a][k - 2 + b] < 1 && board[w - 1 + a][k + b] < 1 && board[w + a][k - 2 + b] < 1 && board[w + a][k - 1 + b] < 1 && board[w + a][k + b] < 1)
						{
							board[w - 1 + a][k - 1 + b] = 0;
						}
					}
					else if (b == 1 && a == 2)
					{
						if (board[w - 2 + a][k - 1 + b] < 1 && board[w - 2 + a][k + b] < 1 && board[w - 1 + a][k + b] < 1 && board[w + a][k - 1 + b] < 1 && board[w + a][k + b] < 1)
						{
							board[w - 1 + a][k - 1 + b] = 0;
						}
					}
				}
				else if (k == 0 && w == 8)
				{

					if (a == 2 && b == 1)
					{
						board[w - 1 + a][k - 1 + b] = 0;
					}
					else if (b == 2 && a != 2)
					{
						if (board[w - 2 + a][k - 2 + b] < 1 && board[w - 2 + a][k - 1 + b] < 1 && board[w - 2 + a][k + b] < 1 && board[w - 1 + a][k - 2 + b] < 1 && board[w - 1 + a][k + b] < 1 && board[w + a][k - 2 + b] < 1 && board[w + a][k - 1 + b] < 1 && board[w + a][k + b] < 1)
						{
							board[w - 1 + a][k - 1 + b] = 0;
						}
					}
					else if (b == 1 && a == 0)
					{
						if (board[w - 2 + a][k - 1 + b] < 1 && board[w - 2 + a][k + b] < 1 && board[w - 1 + a][k + b] < 1 && board[w + a][k - 1 + b] < 1 && board[w + a][k + b] < 1)
						{
							board[w - 1 + a][k - 1 + b] = 0;
						}
					}
					else if (b == 2 && a == 2)
					{
						if (board[w - 2 + a][k - 2 + b] < 1 && board[w - 2 + a][k - 1 + b] < 1 && board[w - 2 + a][k + b] < 1 && board[w - 1 + a][k - 2 + b] < 1 && board[w - 1 + a][k + b] < 1)
						{
							board[w - 1 + a][k - 1 + b] = 0;
						}
					}
				}
				else if (k == 9 && w > 1 && w < 8)
				{
					if (b == 1)
					{
						if (board[w - 2 + a][k - 2 + b] < 1 && board[w - 2 + a][k - 1 + b] < 1 && board[w - 1 + a][k - 2 + b] < 1 && board[w + a][k - 2 + b] < 1 && board[w + a][k - 1 + b] < 1)
						{
							board[w - 1 + a][k - 1 + b] = 0;

						}

					}
					else if (b == 0)
					{
						if (board[w - 2 + a][k - 2 + b] < 1 && board[w - 2 + a][k - 1 + b] < 1 && board[w - 2 + a][k + b] < 1 && board[w - 1 + a][k - 2 + b] < 1 && board[w - 1 + a][k + b] < 1 && board[w + a][k - 2 + b] < 1 && board[w + a][k - 1 + b] < 1 && board[w + a][k + b] < 1)
						{
							board[w - 1 + a][k - 1 + b] = 0;

						}

					}
				}
				else if (k == 9 && w == 1)
				{

					if (a == 0 && b == 1)
					{
						board[w - 1 + a][k - 1 + b] = 0;
					}
					else if (b == 0 && a != 0)
					{
						if (board[w - 2 + a][k - 2 + b] < 1 && board[w - 2 + a][k - 1 + b] < 1 && board[w - 2 + a][k + b] < 1 && board[w - 1 + a][k - 2 + b] < 1 && board[w - 1 + a][k + b] < 1 && board[w + a][k - 2 + b] < 1 && board[w + a][k - 1 + b] < 1 && board[w + a][k + b] < 1)
						{
							board[w - 1 + a][k - 1 + b] = 0;
						}
					}
					else if (b == 0 && a == 0)
					{
						if (board[w - 1 + a][k - 2 + b] < 1 && board[w - 1 + a][k + b] < 1 && board[w + a][k - 2 + b] < 1 && board[w + a][k - 1 + b] < 1 && board[w + a][k + b] < 1)
						{
							board[w - 1 + a][k - 1 + b] = 0;
						}
					}
					else if (b == 1 && a == 2)
					{
						if (board[w - 2 + a][k - 2 + b] < 1 && board[w - 2 + a][k - 1 + b] < 1 && board[w - 1 + a][k - 2 + b] < 1 && board[w + a][k - 2 + b] < 1 && board[w + a][k - 1 + b] < 1)
						{
							board[w - 1 + a][k - 1 + b] = 0;
						}
					}
				}
				else if (k == 9 && w == 8)
				{
					// board[w - 2 + a][k - 2 + b] < 1 && board[w - 2 + a][k - 1 + b] < 1 && board[w - 2 + a][k + b] < 1 && board[w - 1 + a][k - 2 + b] < 1 && board[w - 1 + a][k + b] < 1 && board[w + a][k - 2 + b] < 1 && board[w + a][k - 1 + b] < 1 && board[w + a][k + b] < 1
					if (a == 2 && b == 1)
					{
						board[w - 1 + a][k - 1 + b] = 0;
					}
					else if (b == 0 && a != 2)
					{
						if (board[w - 2 + a][k - 2 + b] < 1 && board[w - 2 + a][k - 1 + b] < 1 && board[w - 2 + a][k + b] < 1 && board[w - 1 + a][k - 2 + b] < 1 && board[w - 1 + a][k + b] < 1 && board[w + a][k - 2 + b] < 1 && board[w + a][k - 1 + b] < 1 && board[w + a][k + b] < 1)
						{
							board[w - 1 + a][k - 1 + b] = 0;
						}
					}
					else if (b == 1 && a == 0)
					{
						if (board[w - 2 + a][k - 2 + b] < 1 && board[w - 2 + a][k - 1 + b] < 1 && board[w - 1 + a][k - 2 + b] < 1 && board[w + a][k - 2 + b] < 1 && board[w + a][k - 1 + b] < 1)
						{
							board[w - 1 + a][k - 1 + b] = 0;
						}
					}
					else if (b == 0 && a == 2)
					{
						if (board[w - 2 + a][k - 2 + b] < 1 && board[w - 2 + a][k - 1 + b] < 1 && board[w - 2 + a][k + b] < 1 && board[w - 1 + a][k - 2 + b] < 1 && board[w - 1 + a][k + b] < 1)
						{
							board[w - 1 + a][k - 1 + b] = 0;
						}
					}
				}
			}
			else if (w == 0 && k == 0)
			{
				if (a == 1 && b == 2)
				{
					if (board[w - 1 + a][k - 2 + b] < 1 && board[w - 1 + a][k + b] < 1 && board[w + a][k - 2 + b] < 1 && board[w + a][k - 1 + b] < 1 && board[w + a][k + b] < 1)
					{
						board[w - 1 + a][k - 1 + b] = 0;
					}
				}
				else if (b == 2 && a == 2)
				{
					if (board[w - 2 + a][k - 2 + b] < 1 && board[w - 2 + a][k - 1 + b] < 1 && board[w - 2 + a][k + b] < 1 && board[w - 1 + a][k - 2 + b] < 1 && board[w - 1 + a][k + b] < 1 && board[w + a][k - 2 + b] < 1 && board[w + a][k - 1 + b] < 1 && board[w + a][k + b] < 1)
					{
						board[w - 1 + a][k - 1 + b] = 0;
					}
				}
				else if (b == 1 && a == 2)
				{
					if (board[w - 2 + a][k - 1 + b] < 1 && board[w - 2 + a][k + b] < 1 && board[w - 1 + a][k + b] < 1 && board[w + a][k - 1 + b] < 1 && board[w + a][k + b] < 1)
					{
						board[w - 1 + a][k - 1 + b] = 0;
					}
				}
			}
			else if (w == 0 && k == 9)
			{
				if (b == 0 && a == 2)
				{
					if (board[w - 2 + a][k - 2 + b] < 1 && board[w - 2 + a][k - 1 + b] < 1 && board[w - 2 + a][k + b] < 1 && board[w - 1 + a][k - 2 + b] < 1 && board[w - 1 + a][k + b] < 1 && board[w + a][k - 2 + b] < 1 && board[w + a][k - 1 + b] < 1 && board[w + a][k + b] < 1)
					{
						board[w - 1 + a][k - 1 + b] = 0;
					}
				}
				else if (a == 1 && b == 0)
				{
					if (board[w - 1 + a][k - 2 + b] < 1 && board[w - 1 + a][k + b] < 1 && board[w + a][k - 2 + b] < 1 && board[w + a][k - 1 + b] < 1 && board[w + a][k + b] < 1)
					{
						board[w - 1 + a][k - 1 + b] = 0;
					}
				}
				else if (b == 1 && a == 2)
				{
					if (board[w - 2 + a][k - 2 + b] < 1 && board[w - 2 + a][k - 1 + b] < 1 && board[w - 1 + a][k - 2 + b] < 1 && board[w + a][k - 2 + b] < 1 && board[w + a][k - 1 + b] < 1)
					{
						board[w - 1 + a][k - 1 + b] = 0;
					}
				}
			}
			else if (w == 9 && k == 0)
			{
				if (b == 2 && a == 0)
				{
					if (board[w - 2 + a][k - 2 + b] < 1 && board[w - 2 + a][k - 1 + b] < 1 && board[w - 2 + a][k + b] < 1 && board[w - 1 + a][k - 2 + b] < 1 && board[w - 1 + a][k + b] < 1 && board[w + a][k - 2 + b] < 1 && board[w + a][k - 1 + b] < 1 && board[w + a][k + b] < 1)
					{
						board[w - 1 + a][k - 1 + b] = 0;
					}
				}
				else if (b == 1 && a == 0)
				{
					if (board[w - 2 + a][k - 1 + b] < 1 && board[w - 2 + a][k + b] < 1 && board[w - 1 + a][k + b] < 1 && board[w + a][k - 1 + b] < 1 && board[w + a][k + b] < 1)
					{
						board[w - 1 + a][k - 1 + b] = 0;
					}
				}
				else if (b == 2 && a == 1)
				{
					if (board[w - 2 + a][k - 2 + b] < 1 && board[w - 2 + a][k - 1 + b] < 1 && board[w - 2 + a][k + b] < 1 && board[w - 1 + a][k - 2 + b] < 1 && board[w - 1 + a][k + b] < 1)
					{
						board[w - 1 + a][k - 1 + b] = 0;
					}
				}
			}
			else if (w == 9 && k == 9)
			{
				if (b == 0 && a == 0)
				{
					if (board[w - 2 + a][k - 2 + b] < 1 && board[w - 2 + a][k - 1 + b] < 1 && board[w - 2 + a][k + b] < 1 && board[w - 1 + a][k - 2 + b] < 1 && board[w - 1 + a][k + b] < 1 && board[w + a][k - 2 + b] < 1 && board[w + a][k - 1 + b] < 1 && board[w + a][k + b] < 1)
					{
						board[w - 1 + a][k - 1 + b] = 0;
					}
				}
				else if (a == 1 && b == 0)
				{
					if (board[w - 2 + a][k - 2 + b] < 1 && board[w - 2 + a][k - 1 + b] < 1 && board[w - 2 + a][k + b] < 1 && board[w - 1 + a][k - 2 + b] < 1 && board[w - 1 + a][k + b] < 1)
					{
						board[w - 1 + a][k - 1 + b] = 0;
					}
				}
				else if (b == 1 && a == 0)
				{
					if (board[w - 2 + a][k - 2 + b] < 1 && board[w - 2 + a][k - 1 + b] < 1 && board[w - 1 + a][k - 2 + b] < 1 && board[w + a][k - 2 + b] < 1 && board[w + a][k - 1 + b] < 1)
					{
						board[w - 1 + a][k - 1 + b] = 0;
					}
				}
			}
		}
	}
}

void MapGenerator::doGenerateHandMap(int board[10][10], void (*deleteShip)(int, int, int[10][10]))
{
	bool prawda;
	HANDLE hOut;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	unsigned char file = 254;
	bool one1_1 = false;
	bool one2_1 = false;
	bool one3_1 = false;
	bool one4_1 = false;
	bool two1_1 = false;
	bool two2_1 = false;
	bool two3_1 = false;
	bool three1_1 = false;
	bool three2_1 = false;
	bool four1_1 = false;

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
			board[i][j] = 0;
	}
	string ifReady1{};
	int ship1{};
	int row1{};
	int column1{};
	char column{};
	int direction1{};
	bool ship = false;


	while (ifReady1 != "OK" && ifReady1 != "ok" && ifReady1 != "oK" && ifReady1 != "Ok" && ifReady1 != "POWROT" && ifReady1 != "Powrot" && ifReady1 != "powrot")
	{
		system("cls");

		cout << endl;
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

			for (int j = 0; j <= 9; j++)
			{
				if (i == 9 && j == 0)
				{
					cout.width(4);
					if (board[i][j] == 0)
					{
						SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
						cout << ".";
					}
					else if (board[i][j] == -1)
					{
						SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
						cout << "o";
					}
					else
					{
						SetConsoleTextAttribute(hOut, FOREGROUND_RED);
						cout << file;
					}
				}
				else
				{
					cout.width(5);
					if (board[i][j] == 0)
					{
						SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
						cout << ".";
					}
					else if (board[i][j] == -1)
					{
						SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
						cout << "o";
					}
					else
					{
						SetConsoleTextAttribute(hOut, FOREGROUND_RED);
						cout << file;
					}
				}

			}
			if (i == 1)
			{
				spaces(20);

				if (one1_1 == false)
				{
					SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
					cout << file << "   ";
				}

				if (one2_1 == false)
				{
					SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
					cout << file << "   ";
				}

				if (one3_1 == false)
				{
					SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
					cout << file << "   ";
				}

				if (one4_1 == false)
				{
					SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
					cout << file;
				}
			}
			if (i == 3)
			{
				spaces(20);

				if (two1_1 == false)
				{
					SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
					cout << file << file << "   ";
				}

				if (two2_1 == false)
				{
					SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
					cout << file << file << "   ";
				}

				if (two3_1 == false)
				{
					SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
					cout << file << file << "   ";
				}
			}
			if (i == 5)
			{
				spaces(20);

				if (three1_1 == false)
				{
					SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
					cout << file << file << file << "   ";
				}

				if (three2_1 == false)
				{
					SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
					cout << file << file << file << "   ";
				}
			}
			if (i == 7)
			{
				spaces(20);

				if (four1_1 == false)
				{
					SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
					cout << file << file << file << file << "   ";
				}
			}
			cout << endl << endl;

		}
		SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
		cout << "Podaj dlugosc statku: ";
		bool poprawne = false;
		cin >> ifReady1;
		if (ifReady1 != "OK" && ifReady1 != "ok" && ifReady1 != "oK" && ifReady1 != "Ok" && ifReady1 != "POWROT" && ifReady1 != "Powrot" && ifReady1 != "powrot")
		{
			while (poprawne == false)
			{
				if (!(ifReady1.compare("1")) || !(ifReady1.compare("2")) || !(ifReady1.compare("3")) || !(ifReady1.compare("4")))
				{
					ship1 = stoi(ifReady1);
					poprawne = true;
				}
				else
				{
					SetConsoleTextAttribute(hOut, FOREGROUND_RED);
					cout << "Podano zle dane";
					Sleep(3000);
					SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
					cout << endl << "Podaj dlugosc statku: ";
					cin >> ifReady1;

				}
			}

			cout << "Podaj kolumne (A-J) oraz wiersz (1-10): ";
			cin >> column;
			cin >> row1;
			prawda = cin.good();
			if (prawda == 0)
			{
				cin.clear();
				cin.ignore(100, '\n');
				SetConsoleTextAttribute(hOut, FOREGROUND_RED);
				cout << "Podano zle dane";
				SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
			}
			if (row1 != 0 && column != 0 && ship1 != 1)
			{
				cout << "Podaj kierunek (1 - w gore, 2 - w prawo, 3 - w dol, 4 - w lewo): ";
				cin >> direction1;
				if (direction1 != 1 && direction1 != 2 && direction1 != 3 && direction1 != 4)
				{
					SetConsoleTextAttribute(hOut, FOREGROUND_RED);
					cout << "Podano zly kierunek.";
					Sleep(3000);
					continue;
				}
			}



			row1 = row1 - 1;
			if (column >= 65 && column <= 74)
			{
				column1 = static_cast<int>(column);
				column1 = column1 - 65;
			}
			else if (column >= 97 && column <= 106)
			{
				column1 = static_cast<int>(column);
				column1 = column1 - 97;
			}
			else
			{
				column1 = -1;
			}

			if (row1 >= -1 && row1 < 10 && column1 >= -1 && column1 < 10)
			{

				if (ship1 == 1)
				{
					if (one4_1 == false && row1 != -1)
					{
						if (board[row1][column1] == 0)
						{
							board[row1][column1] = 1;

							for (int a = 0; a < 3; a++)
							{
								for (int b = 0; b < 3; b++)
								{
									if (row1 - 1 + a >= 0 && row1 - 1 + a <= 9 && column1 - 1 + b >= 0 && column1 - 1 + b <= 9 && board[row1 - 1 + a][column1 - 1 + b] == 0)
										board[row1 - 1 + a][column1 - 1 + b] = -1;
								}


							}
							if (one1_1 == false) one1_1 = true;
							else if (one1_1 == true && one2_1 == false) one2_1 = true;
							else if (one1_1 == true && one2_1 == true && one3_1 == false) one3_1 = true;
							else if (one1_1 == true && one2_1 == true && one3_1 == true) one4_1 = true;

						}
						else
						{
							SetConsoleTextAttribute(hOut, FOREGROUND_RED);
							cout << "Nie mozesz tutaj umiescic statku!";
							Sleep(3000);
						}


					}
					else if (one4_1 == true && row1 != -1)
					{
						SetConsoleTextAttribute(hOut, FOREGROUND_RED);
						cout << "Rozmiesciles juz wszystkie jednomasztowce!";
						Sleep(3000);

					}
					else if (one1_1 == true && row1 == -1)
					{
						int w = -1;
						int k = -1;
						for (int p = 0; p < 10; p++)
						{
							for (int q = 0; q < 10; q++)
							{
								if (board[p][q] == 1)
								{
									if (w == -1 && k == -1)
									{
										w = p;
										k = q;
									}
								}
							}
						}
						board[w][k] = 9;

						string ifNext1 = "NIE";
						do
						{
							system("cls");
							cout << endl << endl;
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

								for (int j = 0; j <= 9; j++)
								{
									if (i == 9 && j == 0)
									{
										cout.width(4);
										if (board[i][j] == 0)
										{
											SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
											cout << ".";
										}
										else if (board[i][j] == -1)
										{
											SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
											cout << "o";
										}
										else if (board[i][j] == 9)
										{
											SetConsoleTextAttribute(hOut, FOREGROUND_GREEN);
											cout << file;
										}
										else
										{
											SetConsoleTextAttribute(hOut, FOREGROUND_RED);
											cout << file;
										}
									}
									else
									{
										cout.width(5);
										if (board[i][j] == 0)
										{
											SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
											cout << ".";
										}
										else if (board[i][j] == -1)
										{
											SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
											cout << "o";
										}
										else if (board[i][j] == 9)
										{
											SetConsoleTextAttribute(hOut, FOREGROUND_GREEN);
											cout << file;
										}
										else
										{
											SetConsoleTextAttribute(hOut, FOREGROUND_RED);
											cout << file;
										}
									}

								}
								if (i == 1)
								{
									spaces(20);

									if (one1_1 == false)
									{
										SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
										cout << file << "   ";
									}

									if (one2_1 == false)
									{
										SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
										cout << file << "   ";
									}

									if (one3_1 == false)
									{
										SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
										cout << file << "   ";
									}

									if (one4_1 == false)
									{
										SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
										cout << file;
									}
								}
								if (i == 3)
								{
									spaces(20);

									if (two1_1 == false)
									{
										SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
										cout << file << file << "   ";
									}

									if (two2_1 == false)
									{
										SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
										cout << file << file << "   ";
									}

									if (two3_1 == false)
									{
										SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
										cout << file << file << "   ";
									}
								}
								if (i == 5)
								{
									spaces(20);

									if (three1_1 == false)
									{
										SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
										cout << file << file << file << "   ";
									}

									if (three2_1 == false)
									{
										SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
										cout << file << file << file << "   ";
									}
								}
								if (i == 7)
								{
									spaces(20);

									if (four1_1 == false)
									{
										SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
										cout << file << file << file << file << "   ";
									}
								}
								cout << endl << endl;

							}
							SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN);
							cout << "Czy chcesz zdjac ship zaznaczony na zielono?" << endl;
							SetConsoleTextAttribute(hOut, FOREGROUND_RED);
							cout << "[TAK]";
							SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN);
							cout << " - sciaga ship" << endl;
							SetConsoleTextAttribute(hOut, FOREGROUND_RED);
							cout << "[NIE]";
							SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN);
							cout << " - przechodzi do kolejnego statku" << endl;
							SetConsoleTextAttribute(hOut, FOREGROUND_RED);
							cout << "[COFNIJ]";
							SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN);
							cout << " - wraca do ukladania statkow" << endl;
							SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN);
							cin >> ifNext1;
							if (ifNext1 == "TAK" || ifNext1 == "tak" || ifNext1 == "Tak")
							{
								board[w][k] = 0;
								deleteShip(w, k, board);
								if (one4_1 == true) one4_1 = false;
								else if (one3_1 == true) one3_1 = false;
								else if (one2_1 == true) one2_1 = false;
								else if (one1_1 == true) one1_1 = false;
							}
							else if (ifNext1 == "NIE" || ifNext1 == "nie" || ifNext1 == "Nie")
							{

								board[w][k] = 1;
								for (int c = 0; c < 10; c++)
								{
									for (int d = 0; d < 10; d++)
									{
										if (board[c][d] == 1)
										{
											if (c > w || (c == w && d > k))
											{
												w = c;
												k = d;
												c = 11;
												d = 11;



											}
										}
									}
								}
								board[w][k] = 9;


							}
							else
							{
								SetConsoleTextAttribute(hOut, FOREGROUND_RED);
								cout << endl << "Podano zla odpowiedz" << endl;
								Sleep(3000);
							}

						} while (ifNext1 == "NIE" || ifNext1 == "nie" || ifNext1 == "Nie");

					}
					else if (one1_1 == false && row1 == -1)
					{
						SetConsoleTextAttribute(hOut, FOREGROUND_RED);
						Sleep(3000);
						cout << "Nie mozesz sciagnac statku, ktory nie jest na planszy!";
					}



				}
				else if (ship1 == 2)
				{
					if (two3_1 == false && row1 != -1)
					{
						if (board[row1][column1] == 0)
						{

							if (direction1 == 1 && row1 - 1 >= 0 && board[row1][column1] == 0 && board[row1 - 1][column1] == 0)
							{
								for (int i = 0; i < 2; i++)
									board[row1 - i][column1] = 2;

								for (int a = 0; a < 3; a++)
								{
									for (int b = 0; b < 4; b++)
									{
										if (column1 - 1 + a >= 0 && column1 - 1 + a <= 9 && row1 + 1 - b >= 0 && row1 + 1 - b <= 9 && board[row1 + 1 - b][column1 - 1 + a] == 0)
											board[row1 + 1 - b][column1 - 1 + a] = -1;
									}


								}
								if (two1_1 == false) two1_1 = true;
								else if (two1_1 == true && two2_1 == false) two2_1 = true;
								else if (two1_1 == true && two2_1 == true && two3_1 == false) two3_1 = true;
							}

							else if (direction1 == 2 && column1 + 1 <= 9 && board[row1][column1] == 0 && board[row1][column1 + 1] == 0)
							{
								for (int i = 0; i < 2; i++)
									board[row1][column1 + i] = 2;

								for (int a = 0; a < 3; a++)
								{
									for (int b = 0; b < 4; b++)
									{
										if (row1 - 1 + a >= 0 && row1 - 1 + a <= 9 && column1 - 1 + b >= 0 && column1 - 1 + b <= 9 && board[row1 - 1 + a][column1 - 1 + b] == 0)
											board[row1 - 1 + a][column1 - 1 + b] = -1;
									}


								}
								if (two1_1 == false) two1_1 = true;
								else if (two1_1 == true && two2_1 == false) two2_1 = true;
								else if (two1_1 == true && two2_1 == true && two3_1 == false) two3_1 = true;
							}
							else if (direction1 == 3 && row1 + 1 <= 9 && board[row1][column1] == 0 && board[row1 + 1][column1] == 0)
							{
								for (int i = 0; i < 2; i++)
									board[row1 + i][column1] = 2;

								for (int a = 0; a < 3; a++)
								{
									for (int b = 0; b < 4; b++)
									{
										if (column1 - 1 + a >= 0 && column1 - 1 + a <= 9 && row1 - 1 + b >= 0 && row1 - 1 + b <= 9 && board[row1 - 1 + b][column1 - 1 + a] == 0)
											board[row1 - 1 + b][column1 - 1 + a] = -1;
									}


								}
								if (two1_1 == false) two1_1 = true;
								else if (two1_1 == true && two2_1 == false) two2_1 = true;
								else if (two1_1 == true && two2_1 == true && two3_1 == false) two3_1 = true;
							}
							else if (direction1 == 4 && column1 - 1 >= 0 && board[row1][column1] == 0 && board[row1][column1 - 1] == 0)
							{
								for (int i = 0; i < 2; i++)
									board[row1][column1 - i] = 2;

								for (int a = 0; a < 3; a++)
								{
									for (int b = 0; b < 4; b++)
									{
										if (row1 - 1 + a >= 0 && row1 - 1 + a <= 9 && column1 + 1 - b >= 0 && column1 + 1 - b <= 9 && board[row1 - 1 + a][column1 + 1 - b] == 0)
											board[row1 - 1 + a][column1 + 1 - b] = -1;
									}


								}
								if (two1_1 == false) two1_1 = true;
								else if (two1_1 == true && two2_1 == false) two2_1 = true;
								else if (two1_1 == true && two2_1 == true && two3_1 == false) two3_1 = true;
							}
							else
							{
								SetConsoleTextAttribute(hOut, FOREGROUND_RED);
								cout << "Nie mozesz tutaj umiescic statku!";
								Sleep(3000);
							}


						}

						else
						{
							SetConsoleTextAttribute(hOut, FOREGROUND_RED);
							cout << "Nie mozesz tutaj umiescic statku!";
							Sleep(3000);
						}


					}
					else if (two3_1 == true && row1 != -1)
					{
						SetConsoleTextAttribute(hOut, FOREGROUND_RED);
						cout << "Rozmiesciles juz wszystkie dwumasztowce!";
						Sleep(3000);

					}
					else if (two1_1 == true && row1 == -1)
					{
						int w = -1;
						int k = -1;
						int w1 = -1;
						int k1 = -1;



						for (int p = 0; p < 10; p++)
						{
							for (int q = 0; q < 10; q++)
							{
								if (board[p][q] == 2)
								{
									if (w == -1 && k == -1)
									{
										w = p;
										k = q;
									}
								}
							}
						}
						if (board[w - 1][k] == 2 && w - 1 >= 0)
						{
							w1 = w - 1;
							k1 = k;
						}
						else if (board[w + 1][k] == 2 && w + 1 <= 9)
						{
							w1 = w + 1;
							k1 = k;
						}
						else if (board[w][k - 1] == 2 && k - 1 >= 0)
						{
							w1 = w;
							k1 = k - 1;
						}
						else if (board[w][k + 1] == 2 && k + 1 <= 9)
						{
							w1 = w;
							k1 = k + 1;
						}

						board[w][k] = 9;
						board[w1][k1] = 9;

						string ifNext1 = "NIE";
						do
						{
							system("cls");
							cout << endl << endl;
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

								for (int j = 0; j <= 9; j++)
								{
									if (i == 9 && j == 0)
									{
										cout.width(4);
										if (board[i][j] == 0)
										{
											SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
											cout << ".";
										}
										else if (board[i][j] == -1)
										{
											SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
											cout << "o";
										}
										else if (board[i][j] == 9)
										{
											SetConsoleTextAttribute(hOut, FOREGROUND_GREEN);
											cout << file;
										}
										else
										{
											SetConsoleTextAttribute(hOut, FOREGROUND_RED);
											cout << file;
										}
									}
									else
									{
										cout.width(5);
										if (board[i][j] == 0)
										{
											SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
											cout << ".";
										}
										else if (board[i][j] == -1)
										{
											SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
											cout << "o";
										}
										else if (board[i][j] == 9)
										{
											SetConsoleTextAttribute(hOut, FOREGROUND_GREEN);
											cout << file;
										}
										else
										{
											SetConsoleTextAttribute(hOut, FOREGROUND_RED);
											cout << file;
										}
									}

								}
								if (i == 1)
								{
									spaces(20);

									if (one1_1 == false)
									{
										SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
										cout << file << "   ";
									}

									if (one2_1 == false)
									{
										SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
										cout << file << "   ";
									}

									if (one3_1 == false)
									{
										SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
										cout << file << "   ";
									}

									if (one4_1 == false)
									{
										SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
										cout << file;
									}
								}
								if (i == 3)
								{
									spaces(20);

									if (two1_1 == false)
									{
										SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
										cout << file << file << "   ";
									}

									if (two2_1 == false)
									{
										SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
										cout << file << file << "   ";
									}

									if (two3_1 == false)
									{
										SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
										cout << file << file << "   ";
									}
								}
								if (i == 5)
								{
									spaces(20);

									if (three1_1 == false)
									{
										SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
										cout << file << file << file << "   ";
									}

									if (three2_1 == false)
									{
										SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
										cout << file << file << file << "   ";
									}
								}
								if (i == 7)
								{
									spaces(20);

									if (four1_1 == false)
									{
										SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
										cout << file << file << file << file << "   ";
									}
								}
								cout << endl << endl;

							}
							SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN);
							cout << "Czy chcesz zdjac ship zaznaczony na zielono?" << endl;
							SetConsoleTextAttribute(hOut, FOREGROUND_RED);
							cout << "[TAK]";
							SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN);
							cout << " - sciaga ship" << endl;
							SetConsoleTextAttribute(hOut, FOREGROUND_RED);
							cout << "[NIE]";
							SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN);
							cout << " - przechodzi do kolejnego statku" << endl;
							SetConsoleTextAttribute(hOut, FOREGROUND_RED);
							cout << "[COFNIJ]";
							SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN);
							cout << " - wraca do ukladania statkow" << endl;
							SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN);
							cin >> ifNext1;
							if (ifNext1 == "TAK" || ifNext1 == "tak" || ifNext1 == "Tak")
							{
								board[w][k] = 0;
								board[w1][k1] = 0;
								deleteShip(w, k, board);
								deleteShip(w1, k1, board);
								if (two3_1 == true) two3_1 = false;
								else if (two2_1 == true) two2_1 = false;
								else if (two1_1 == true) two1_1 = false;

							}
							else if (ifNext1 == "NIE" || ifNext1 == "nie" || ifNext1 == "Nie")
							{

								board[w][k] = 2;
								board[w1][k1] = 2;
								for (int c = 0; c < 10; c++)
								{
									for (int d = 0; d < 10; d++)
									{
										if (board[c][d] == 2)
										{
											if ((c > w || (c == w && d > k)) && (c != w1 || (c == w1 && d > k1)))
											{
												w = c;
												k = d;
												c = 11;
												d = 11;



											}
										}
									}
								}
								if (board[w - 1][k] == 2 && w - 1 >= 0)
								{
									w1 = w - 1;
									k1 = k;
								}
								else if (board[w + 1][k] == 2 && w + 1 <= 9)
								{
									w1 = w + 1;
									k1 = k;
								}
								else if (board[w][k - 1] == 2 && k - 1 >= 0)
								{
									w1 = w;
									k1 = k - 1;
								}
								else if (board[w][k + 1] == 2 && k + 1 <= 9)
								{
									w1 = w;
									k1 = k + 1;
								}
								board[w][k] = 9;
								board[w1][k1] = 9;


							}
							else
							{
								SetConsoleTextAttribute(hOut, FOREGROUND_RED);
								cout << endl << "Podano zla odpowiedz" << endl;
								Sleep(3000);
							}

						} while (ifNext1 == "NIE" || ifNext1 == "nie" || ifNext1 == "Nie");

					}
					else if (two1_1 == false && row1 == -1)
					{
						SetConsoleTextAttribute(hOut, FOREGROUND_RED);
						Sleep(3000);
						cout << "Nie mozesz sciagnac statku, ktory nie jest na planszy!";
					}


				}

				else if (ship1 == 3)
				{
					if (three2_1 == false && row1 != -1)
					{
						if (board[row1][column1] == 0)
						{

							if (direction1 == 1 && row1 - 2 >= 0 && board[row1][column1] == 0 && board[row1 - 1][column1] == 0 && board[row1 - 2][column1] == 0)
							{
								for (int i = 0; i < 3; i++)
									board[row1 - i][column1] = 3;

								for (int a = 0; a < 3; a++)
								{
									for (int b = 0; b < 5; b++)
									{
										if (column1 - 1 + a >= 0 && column1 - 1 + a <= 9 && row1 + 1 - b >= 0 && row1 + 1 - b <= 9 && board[row1 + 1 - b][column1 - 1 + a] == 0)
											board[row1 + 1 - b][column1 - 1 + a] = -1;
									}


								}
								if (three1_1 == false) three1_1 = true;
								else if (three1_1 == true && three2_1 == false) three2_1 = true;
							}
							else if (direction1 == 2 && column1 + 2 <= 9 && board[row1][column1] == 0 && board[row1][column1 + 1] == 0 && board[row1][column1 + 2] == 0)
							{
								for (int i = 0; i < 3; i++)
									board[row1][column1 + i] = 3;

								for (int a = 0; a < 3; a++)
								{
									for (int b = 0; b < 5; b++)
									{
										if (row1 - 1 + a >= 0 && row1 - 1 + a <= 9 && column1 - 1 + b >= 0 && column1 - 1 + b <= 9 && board[row1 - 1 + a][column1 - 1 + b] == 0)
											board[row1 - 1 + a][column1 - 1 + b] = -1;
									}


								}
								if (three1_1 == false) three1_1 = true;
								else if (three1_1 == true && three2_1 == false) three2_1 = true;
							}
							else if (direction1 == 3 && row1 + 2 <= 9 && board[row1][column1] == 0 && board[row1 + 1][column1] == 0 && board[row1 + 2][column1] == 0)
							{
								for (int i = 0; i < 3; i++)
									board[row1 + i][column1] = 3;

								for (int a = 0; a < 3; a++)
								{
									for (int b = 0; b < 5; b++)
									{
										if (column1 - 1 + a >= 0 && column1 - 1 + a <= 9 && row1 - 1 + b >= 0 && row1 - 1 + b <= 9 && board[row1 - 1 + b][column1 - 1 + a] == 0)
											board[row1 - 1 + b][column1 - 1 + a] = -1;
									}


								}
								if (three1_1 == false) three1_1 = true;
								else if (three1_1 == true && three2_1 == false) three2_1 = true;
							}
							else if (direction1 == 4 && column1 - 2 >= 0 && board[row1][column1] == 0 && board[row1][column1 - 1] == 0 && board[row1][column1 - 2] == 0)
							{
								for (int i = 0; i < 3; i++)
									board[row1][column1 - i] = 3;

								for (int a = 0; a < 3; a++)
								{
									for (int b = 0; b < 5; b++)
									{
										if (row1 - 1 + a >= 0 && row1 - 1 + a <= 9 && column1 + 1 - b >= 0 && column1 + 1 - b <= 9 && board[row1 - 1 + a][column1 + 1 - b] == 0)
											board[row1 - 1 + a][column1 + 1 - b] = -1;
									}


								}
								if (three1_1 == false) three1_1 = true;
								else if (three1_1 == true && three2_1 == false) three2_1 = true;
							}
							else
							{
								SetConsoleTextAttribute(hOut, FOREGROUND_RED);
								cout << "Nie mozesz tutaj umiescic statku!";
								Sleep(3000);
							}


						}

						else
						{
							SetConsoleTextAttribute(hOut, FOREGROUND_RED);
							cout << "Nie mozesz tutaj umiescic statku!";
							Sleep(3000);
						}


					}
					else if (three2_1 == true && row1 != -1)
					{
						SetConsoleTextAttribute(hOut, FOREGROUND_RED);
						cout << "Rozmiesciles juz wszystkie trzymasztowce!";
						Sleep(3000);

					}
					else if (three1_1 == true && row1 == -1)
					{
						int w = -1;
						int k = -1;
						int w1 = -1;
						int k1 = -1;
						int w2 = -1;
						int k2 = -1;



						for (int p = 0; p < 10; p++)
						{
							for (int q = 0; q < 10; q++)
							{
								if (board[p][q] == 3)
								{
									if (w == -1 && k == -1)
									{
										w = p;
										k = q;
									}
								}
							}
						}

						if (board[w + 1][k] == 3 && w + 1 <= 9)
						{
							w1 = w + 1;
							k1 = k;
							w2 = w + 2;
							k2 = k;
						}

						else if (board[w][k + 1] == 3 && k + 1 <= 9)
						{
							w1 = w;
							k1 = k + 1;
							w2 = w;
							k2 = k + 2;
						}

						board[w][k] = 9;
						board[w1][k1] = 9;
						board[w2][k2] = 9;

						string ifNext1 = "NIE";
						do
						{
							system("cls");
							cout << endl << endl;
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

								for (int j = 0; j <= 9; j++)
								{
									if (i == 9 && j == 0)
									{
										cout.width(4);
										if (board[i][j] == 0)
										{
											SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
											cout << ".";
										}
										else if (board[i][j] == -1)
										{
											SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
											cout << "o";
										}
										else if (board[i][j] == 9)
										{
											SetConsoleTextAttribute(hOut, FOREGROUND_GREEN);
											cout << file;
										}
										else
										{
											SetConsoleTextAttribute(hOut, FOREGROUND_RED);
											cout << file;
										}
									}
									else
									{
										cout.width(5);
										if (board[i][j] == 0)
										{
											SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
											cout << ".";
										}
										else if (board[i][j] == -1)
										{
											SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
											cout << "o";
										}
										else if (board[i][j] == 9)
										{
											SetConsoleTextAttribute(hOut, FOREGROUND_GREEN);
											cout << file;
										}
										else
										{
											SetConsoleTextAttribute(hOut, FOREGROUND_RED);
											cout << file;
										}
									}

								}
								if (i == 1)
								{
									spaces(20);

									if (one1_1 == false)
									{
										SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
										cout << file << "   ";
									}

									if (one2_1 == false)
									{
										SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
										cout << file << "   ";
									}

									if (one3_1 == false)
									{
										SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
										cout << file << "   ";
									}

									if (one4_1 == false)
									{
										SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
										cout << file;
									}
								}
								if (i == 3)
								{
									spaces(20);

									if (two1_1 == false)
									{
										SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
										cout << file << file << "   ";
									}

									if (two2_1 == false)
									{
										SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
										cout << file << file << "   ";
									}

									if (two3_1 == false)
									{
										SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
										cout << file << file << "   ";
									}
								}
								if (i == 5)
								{
									spaces(20);

									if (three1_1 == false)
									{
										SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
										cout << file << file << file << "   ";
									}

									if (three2_1 == false)
									{
										SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
										cout << file << file << file << "   ";
									}
								}
								if (i == 7)
								{
									spaces(20);

									if (four1_1 == false)
									{
										SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
										cout << file << file << file << file << "   ";
									}
								}
								cout << endl << endl;

							}
							SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN);
							cout << "Czy chcesz zdjac ship zaznaczony na zielono?" << endl;
							SetConsoleTextAttribute(hOut, FOREGROUND_RED);
							cout << "[TAK]";
							SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN);
							cout << " - sciaga ship" << endl;
							SetConsoleTextAttribute(hOut, FOREGROUND_RED);
							cout << "[NIE]";
							SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN);
							cout << " - przechodzi do kolejnego statku" << endl;
							SetConsoleTextAttribute(hOut, FOREGROUND_RED);
							cout << "[COFNIJ]";
							SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN);
							cout << " - wraca do ukladania statkow" << endl;
							SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN);
							cin >> ifNext1;
							if (ifNext1 == "TAK" || ifNext1 == "tak" || ifNext1 == "Tak")
							{
								board[w][k] = 0;
								board[w1][k1] = 0;
								board[w2][k2] = 0;
								deleteShip(w, k, board);
								deleteShip(w1, k1, board);
								deleteShip(w2, k2, board);
								if (three2_1 == true) three2_1 = false;
								else if (three1_1 == true) three1_1 = false;

							}
							else if (ifNext1 == "NIE" || ifNext1 == "nie" || ifNext1 == "Nie")
							{

								board[w][k] = 3;
								board[w1][k1] = 3;
								board[w2][k2] = 3;
								for (int c = 0; c < 10; c++)
								{
									for (int d = 0; d < 10; d++)
									{
										if (board[c][d] == 3)
										{
											if ((c > w || (c == w && d > k)) && (c != w1 || (c == w1 && d != k1)) && (c != w2 || (c == w2 && d != k2)))
											{
												w = c;
												k = d;
												c = 11;
												d = 11;

											}
										}
									}
								}
								if (board[w + 1][k] == 3 && w + 1 <= 9)
								{
									w1 = w + 1;
									k1 = k;
									w2 = w + 2;
									k2 = k;
								}

								else if (board[w][k + 1] == 3 && k + 1 <= 9)
								{
									w1 = w;
									k1 = k + 1;
									w2 = w;
									k2 = k + 2;
								}
								board[w][k] = 9;
								board[w1][k1] = 9;
								board[w2][k2] = 9;


							}
							else
							{
								SetConsoleTextAttribute(hOut, FOREGROUND_RED);
								cout << endl << "Podano zla odpowiedz" << endl;
								Sleep(3000);
							}

						} while (ifNext1 == "NIE" || ifNext1 == "nie" || ifNext1 == "Nie");

					}
					else if (three1_1 == false && row1 == -1)
					{
						SetConsoleTextAttribute(hOut, FOREGROUND_RED);
						Sleep(3000);
						cout << "Nie mozesz sciagnac statku, ktory nie jest na planszy!";
					}


				}
				else if (ship1 == 4)
				{
					if (four1_1 == false && row1 != -1)
					{
						if (board[row1][column1] == 0)
						{

							if (direction1 == 1 && row1 - 3 >= 0 && board[row1][column1] == 0 && board[row1 - 1][column1] == 0 && board[row1 - 2][column1] == 0 && board[row1 - 3][column1] == 0)
							{
								for (int i = 0; i < 4; i++)
									board[row1 - i][column1] = 4;

								for (int a = 0; a < 3; a++)
								{
									for (int b = 0; b < 6; b++)
									{
										if (column1 - 1 + a >= 0 && column1 - 1 + a <= 9 && row1 + 1 - b >= 0 && row1 + 1 - b <= 9 && board[row1 + 1 - b][column1 - 1 + a] == 0)
											board[row1 + 1 - b][column1 - 1 + a] = -1;
									}


								}
								four1_1 = true;
							}

							else if (direction1 == 2 && column1 + 3 <= 9 && board[row1][column1] == 0 && board[row1][column1 + 1] == 0 && board[row1][column1 + 2] == 0 && board[row1][column1 + 3] == 0)
							{
								for (int i = 0; i < 4; i++)
									board[row1][column1 + i] = 4;

								for (int a = 0; a < 3; a++)
								{
									for (int b = 0; b < 6; b++)
									{
										if (row1 - 1 + a >= 0 && row1 - 1 + a <= 9 && column1 - 1 + b >= 0 && column1 - 1 + b <= 9 && board[row1 - 1 + a][column1 - 1 + b] == 0)
											board[row1 - 1 + a][column1 - 1 + b] = -1;
									}


								}
								four1_1 = true;
							}
							else if (direction1 == 3 && row1 + 3 <= 9 && board[row1][column1] == 0 && board[row1 + 1][column1] == 0 && board[row1 + 2][column1] == 0 && board[row1 + 3][column1] == 0)
							{
								for (int i = 0; i < 4; i++)
									board[row1 + i][column1] = 4;

								for (int a = 0; a < 3; a++)
								{
									for (int b = 0; b < 6; b++)
									{
										if (column1 - 1 + a >= 0 && column1 - 1 + a <= 9 && row1 - 1 + b >= 0 && row1 - 1 + b <= 9 && board[row1 - 1 + b][column1 - 1 + a] == 0)
											board[row1 - 1 + b][column1 - 1 + a] = -1;
									}


								}
								four1_1 = true;
							}
							else if (direction1 == 4 && column1 - 3 >= 0 && board[row1][column1] == 0 && board[row1][column1 - 1] == 0 && board[row1][column1 - 2] == 0 && board[row1][column1 - 3] == 0)
							{
								for (int i = 0; i < 4; i++)
									board[row1][column1 - i] = 4;

								for (int a = 0; a < 3; a++)
								{
									for (int b = 0; b < 6; b++)
									{
										if (row1 - 1 + a >= 0 && row1 - 1 + a <= 9 && column1 + 1 - b >= 0 && column1 + 1 - b <= 9 && board[row1 - 1 + a][column1 + 1 - b] == 0)
											board[row1 - 1 + a][column1 + 1 - b] = -1;
									}


								}
								four1_1 = true;
							}
							else
							{
								SetConsoleTextAttribute(hOut, FOREGROUND_RED);
								cout << "Nie mozesz tutaj umiescic statku!";
								Sleep(3000);
							}


						}

						else
						{
							SetConsoleTextAttribute(hOut, FOREGROUND_RED);
							cout << "Nie mozesz tutaj umiescic statku!";
							Sleep(3000);
						}


					}
					else if (four1_1 == true && row1 != -1)
					{
						SetConsoleTextAttribute(hOut, FOREGROUND_RED);
						cout << "Rozmiesciles juz czteromasztowiec!";
						Sleep(3000);

					}
					else if (four1_1 == true && row1 == -1)
					{
						int w = -1;
						int k = -1;
						int w1 = -1;
						int k1 = -1;
						int w2 = -1;
						int k2 = -1;
						int w3 = -1;
						int k3 = -1;



						for (int p = 0; p < 10; p++)
						{
							for (int q = 0; q < 10; q++)
							{
								if (board[p][q] == 4)
								{
									if (w == -1 && k == -1)
									{
										w = p;
										k = q;
									}
								}
							}
						}

						if (board[w + 1][k] == 4 && w + 1 <= 9)
						{
							w1 = w + 1;
							k1 = k;
							w2 = w + 2;
							k2 = k;
							w3 = w + 3;
							k3 = k;
						}

						else if (board[w][k + 1] == 4 && k + 1 <= 9)
						{
							w1 = w;
							k1 = k + 1;
							w2 = w;
							k2 = k + 2;
							w3 = w;
							k3 = k + 3;
						}

						board[w][k] = 9;
						board[w1][k1] = 9;
						board[w2][k2] = 9;
						board[w3][k3] = 9;

						string ifNext1 = "NIE";
						do
						{
							system("cls");
							cout << endl << endl;
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

								for (int j = 0; j <= 9; j++)
								{
									if (i == 9 && j == 0)
									{
										cout.width(4);
										if (board[i][j] == 0)
										{
											SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
											cout << ".";
										}
										else if (board[i][j] == -1)
										{
											SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
											cout << "o";
										}
										else if (board[i][j] == 9)
										{
											SetConsoleTextAttribute(hOut, FOREGROUND_GREEN);
											cout << file;
										}
										else
										{
											SetConsoleTextAttribute(hOut, FOREGROUND_RED);
											cout << file;
										}
									}
									else
									{
										cout.width(5);
										if (board[i][j] == 0)
										{
											SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
											cout << ".";
										}
										else if (board[i][j] == -1)
										{
											SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
											cout << "o";
										}
										else if (board[i][j] == 9)
										{
											SetConsoleTextAttribute(hOut, FOREGROUND_GREEN);
											cout << file;
										}
										else
										{
											SetConsoleTextAttribute(hOut, FOREGROUND_RED);
											cout << file;
										}
									}

								}
								if (i == 1)
								{
									spaces(20);

									if (one1_1 == false)
									{
										SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
										cout << file << "   ";
									}

									if (one2_1 == false)
									{
										SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
										cout << file << "   ";
									}

									if (one3_1 == false)
									{
										SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
										cout << file << "   ";
									}

									if (one4_1 == false)
									{
										SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
										cout << file;
									}
								}
								if (i == 3)
								{
									spaces(20);

									if (two1_1 == false)
									{
										SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
										cout << file << file << "   ";
									}

									if (two2_1 == false)
									{
										SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
										cout << file << file << "   ";
									}

									if (two3_1 == false)
									{
										SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
										cout << file << file << "   ";
									}
								}
								if (i == 5)
								{
									spaces(20);

									if (three1_1 == false)
									{
										SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
										cout << file << file << file << "   ";
									}

									if (three2_1 == false)
									{
										SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
										cout << file << file << file << "   ";
									}
								}
								if (i == 7)
								{
									spaces(20);

									if (four1_1 == false)
									{
										SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
										cout << file << file << file << file << "   ";
									}
								}
								cout << endl << endl;

							}
							SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN);
							cout << "Czy chcesz zdjac ship zaznaczony na zielono?" << endl;
							SetConsoleTextAttribute(hOut, FOREGROUND_RED);
							cout << "[TAK]";
							SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN);
							cout << " - sciaga ship" << endl;
							SetConsoleTextAttribute(hOut, FOREGROUND_RED);
							cout << "[NIE]";
							SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN);
							cout << " - przechodzi do kolejnego statku" << endl;
							SetConsoleTextAttribute(hOut, FOREGROUND_RED);
							cout << "[COFNIJ]";
							SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN);
							cout << " - wraca do ukladania statkow" << endl;
							SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN);
							cin >> ifNext1;
							if (ifNext1 == "TAK" || ifNext1 == "tak" || ifNext1 == "Tak")
							{
								board[w][k] = 0;
								board[w1][k1] = 0;
								board[w2][k2] = 0;
								board[w3][k3] = 0;
								deleteShip(w, k, board);
								deleteShip(w1, k1, board);
								deleteShip(w2, k2, board);
								deleteShip(w3, k3, board);
								if (four1_1 == true) four1_1 = false;


							}
							else
							{
								SetConsoleTextAttribute(hOut, FOREGROUND_RED);
								cout << endl << "Podano zla odpowiedz" << endl;
								Sleep(3000);
							}

						} while (ifNext1 == "NIE" || ifNext1 == "nie" || ifNext1 == "Nie");

					}
					else if (four1_1 == false && row1 == -1)
					{
						SetConsoleTextAttribute(hOut, FOREGROUND_RED);
						Sleep(3000);
						cout << "Nie mozesz sciagnac statku, ktory nie jest na planszy!";
					}



				}
				else
				{
					SetConsoleTextAttribute(hOut, FOREGROUND_RED);
					cout << "Taki ship nie istnieje!";
					Sleep(3000);
				}
			}
			else
			{
				SetConsoleTextAttribute(hOut, FOREGROUND_RED);
				cout << "Podano bledne wspolrzedne!";
				Sleep(3000);
			}

		}
		else if (ifReady1 == "OK" || ifReady1 == "ok" || ifReady1 == "Ok" || ifReady1 == "oK")
		{
			bool checker = true;
			while (checker == true)
			{
				int check[4] = { 0, 0, 0, 0 };
				for (int p = 0; p <= 9; p++)
				{
					for (int q = 0; q <= 9; q++)
					{
						if (board[p][q] == 1)
							check[0] += 1;
						else if (board[p][q] == 2)
							check[1] += 1;
						else if (board[p][q] == 3)
							check[2] += 1;
						else if (board[p][q] == 4)
							check[3] += 1;
					}
				}

				if (check[0] == 4 && check[1] == 6 && check[2] == 6 && check[3] == 4)
				{
					checker = false;
				}
				else
				{
					ifReady1 = "pudlo";
					SetConsoleTextAttribute(hOut, FOREGROUND_RED);
					cout << "Nie wylozono wszystkich statkow!";
					Sleep(3000);
					checker = false;
				}
			}
		}


	}


	system("cls");
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

void MapGenerator::chooseGenerationType(Game& game, Board& board)
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
		if (!generateRandomMap(game, board, false)) chooseGenerationType(game, board);
		break;
	case 1:
		if (!generateHandMap(game, board, false)) chooseGenerationType(game, board);
		break;
	}
}

bool MapGenerator::generateRandomMap(Game &game, Board &board, bool forceSet = false)
{
	int ulozenie1 = 1;
	do
	{
		if (ulozenie1 == 1)
		{
			doGenerateRandomMap(board.gameBoard);
			bool checker = true;

			while (checker == true)
			{
				int check[4] = { 0, 0, 0, 0 };
				for (int p = 0; p <= 9; p++)
				{
					for (int q = 0; q <= 9; q++)
					{
						if (board.gameBoard[p][q] == 1)                          // Losowanie planszszy a nastêpnie sprawdzenie,
							check[0] += 1;                           // czy jest poprawnie ulozona, poprzez policzenie ilosci statkow.
						else if (board.gameBoard[p][q] == 2)
							check[1] += 1;
						else if (board.gameBoard[p][q] == 3)
							check[2] += 1;
						else if (board.gameBoard[p][q] == 4)
							check[3] += 1;
					}
				}

				if (check[0] == 4 && check[1] == 6 && check[2] == 6 && check[3] == 4)
					checker = false;
				else
					doGenerateRandomMap(board.gameBoard);
			}
		}
		doShowDots(board.gameBoard);
		if (forceSet) {
			game.state = START_GAME;
			break;
		}
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
		void(*funkcja)(int, int, int[10][10]) = &deleteShip;
		if (ulozenie1 == 3) break;
		if (ulozenie1 == 2) game.state = START_GAME;
	} while ((ulozenie1 != 2 && ulozenie1 != 0));
	system("cls");

	return ulozenie1 != 3;
}

bool MapGenerator::generateHandMap(Game& game, Board& board, bool forceSet = false)
{
	int ulozenie1 = 1;
	void(*funkcja)(int, int, int[10][10]) = &deleteShip;
		doGenerateHandMap(board.gameBoard, funkcja);
		bool checker = true;
		while (checker == true)
		{
			int check[4] = { 0, 0, 0, 0 };
			for (int p = 0; p <= 9; p++)
			{
				for (int q = 0; q <= 9; q++)
				{
					if (board.gameBoard[p][q] == 1)                          // Losowanie planszszy a nastêpnie sprawdzenie,
						check[0] += 1;                           // czy jest poprawnie ulozona, poprzez policzenie ilosci statkow.
					else if (board.gameBoard[p][q] == 2)
						check[1] += 1;
					else if (board.gameBoard[p][q] == 3)
						check[2] += 1;
					else if (board.gameBoard[p][q] == 4)
						check[3] += 1;
				}
			}

			if (check[0] == 4 && check[1] == 6 && check[2] == 6 && check[3] == 4)
			{
				checker = false;
				game.state = START_GAME;
				system("cls");
				return true;
			}

			else
				system("cls");
				return false;
		}
	
	

}