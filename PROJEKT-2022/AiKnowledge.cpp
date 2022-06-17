#pragma once
#include "AiKnowledge.h"
#include "Game.h"

random_device randomDevice;
mt19937 randomGenerator(randomDevice());
uniform_int_distribution<int> rowGen(0, 9);
uniform_int_distribution<int> colGen(0, 9);
uniform_int_distribution<int> directionGen(0, 3);

void AiKnowledge::onHit(Game& game, int& column, int& row) {
	isHit = true;
	if (knownColumn == -1 && knownRow == -1) {
		knownColumn = column;
		knownRow = row;
	}
}

void AiKnowledge::resetData(Game& game) {
	isHit = false;
	knownColumn = -1;
	knownRow = -1;
	knownDirection = 0;
	directionCheck = 0;
}

void AiKnowledge::guessPosition(Game& game, int& column, int& row) {
	auto board = game.board1.gameBoard;
	switch (game.aiMode) {
	case HARD:
		if (!isHit)
		{
			if (game.board1.two3 == false || game.board1.three2 == false || game.board1.four1 == false)
			{
				calc = 0;
				x = 0;
				y = 0;
				for (int p = 0; p < 100; p++)
				{
					tabx[p] = 0;
					taby[p] = 0;
				}

				if (game.board1.two3 == false)
				{
					for (int p = 0; p < 10; p++)
					{
						for (int q = 0; q < 10; q++)
						{
							if (p != 0 && p != 9 && q != 0 && q != 9)
							{
								if (board[p][q] != 5 && board[p][q] != 6 && board[p + 1][q] != 5 && board[p + 1][q] != 6 && board[p - 1][q] != 5 && board[p - 1][q] != 6 && board[p][q + 1] != 5 && board[p][q + 1] != 6 && board[p][q - 1] != 5 && board[p][q - 1] != 6)
								{
									calc++;
									tabx[x] = p;
									taby[y] = q;
									x++;
									y++;

								}
							}
						}
					}

					if (calc == 0)
					{
						for (int p = 0; p < 10; p++)
						{
							for (int q = 0; q < 10; q++)
							{
								if (p == 0 && q > 0 && q < 9)
								{
									if (board[p][q] != 5 && board[p][q] != 6 && board[p + 1][q] != 5 && board[p + 1][q] != 6 && board[p][q + 1] != 5 && board[p][q + 1] != 6 && board[p][q - 1] != 5 && board[p][q - 1] != 6)
									{
										calc++;
										tabx[x] = p;
										taby[y] = q;
										x++;
										y++;

									}
								}
								else if (p == 9 && q > 0 && q < 9)
								{
									if (board[p][q] != 5 && board[p][q] != 6 && board[p - 1][q] != 5 && board[p - 1][q] != 6 && board[p][q + 1] != 5 && board[p][q + 1] != 6 && board[p][q - 1] != 5 && board[p][q - 1] != 6)
									{
										calc++;
										tabx[x] = p;
										taby[y] = q;
										x++;
										y++;

									}
								}
								else if (q == 0 && p > 0 && p < 9)
								{
									if (board[p][q] != 5 && board[p][q] != 6 && board[p + 1][q] != 5 && board[p + 1][q] != 6 && board[p - 1][q] != 5 && board[p - 1][q] != 6 && board[p][q + 1] != 5 && board[p][q + 1] != 6)
									{
										calc++;
										tabx[x] = p;
										taby[y] = q;
										x++;
										y++;

									}
								}
								else if (q == 9 && p > 0 && p < 9)
								{
									if (board[p][q] != 5 && board[p][q] != 6 && board[p + 1][q] != 5 && board[p + 1][q] != 6 && board[p - 1][q] != 5 && board[p - 1][q] != 6 && board[p][q - 1] != 5 && board[p][q - 1] != 6)
									{
										calc++;
										tabx[x] = p;
										taby[y] = q;
										x++;
										y++;

									}
								}
								if (p != 0 && p != 9 && q != 0 && q != 9)
								{
									if (board[p][q] != 5 && board[p][q] != 6 && board[p - 1][q] != 5 && board[p - 1][q] != 6 && board[p][q + 1] != 5 && board[p][q + 1] != 6 && board[p][q - 1] != 5 && board[p][q - 1] != 6)
									{
										calc++;
										tabx[x] = p;
										taby[y] = q;
										x++;
										y++;

									}
									else if (board[p][q] != 5 && board[p][q] != 6 && board[p + 1][q] != 5 && board[p + 1][q] != 6 && board[p][q + 1] != 5 && board[p][q + 1] != 6 && board[p][q - 1] != 5 && board[p][q - 1] != 6)
									{
										calc++;
										tabx[x] = p;
										taby[y] = q;
										x++;
										y++;

									}
									else if (board[p][q] != 5 && board[p][q] != 6 && board[p + 1][q] != 5 && board[p + 1][q] != 6 && board[p - 1][q] != 5 && board[p - 1][q] != 6 && board[p][q - 1] != 5 && board[p][q - 1] != 6)
									{
										calc++;
										tabx[x] = p;
										taby[y] = q;
										x++;
										y++;

									}
									else if (board[p][q] != 5 && board[p][q] != 6 && board[p + 1][q] != 5 && board[p + 1][q] != 6 && board[p - 1][q] != 5 && board[p - 1][q] != 6 && board[p][q + 1] != 5 && board[p][q + 1] != 6)
									{
										calc++;
										tabx[x] = p;
										taby[y] = q;
										x++;
										y++;

									}
								}
							}
						}
					}
					if (calc == 0)
					{
						for (int p = 0; p < 10; p++)
						{
							for (int q = 0; q < 10; q++)
							{
								if (((p == 0 && q == 0) && (board[p][q] != 5 && board[p][q] != 6 && board[p + 1][q] != 5 && board[p + 1][q] != 6 && board[p][q + 1] != 5 && board[p][q + 1] != 6))
									|| ((p == 0 && q == 9) && (board[p][q] != 5 && board[p][q] != 6 && board[p + 1][q] != 5 && board[p + 1][q] != 6 && board[p][q - 1] != 5 && board[p][q - 1] != 6))
									|| ((p == 9 && q == 0) && (board[p][q] != 5 && board[p][q] != 6 && board[p - 1][q] != 5 && board[p - 1][q] != 6 && board[p][q + 1] != 5 && board[p][q + 1] != 6))
									|| ((p == 9 && q == 9) && (board[p][q] != 5 && board[p][q] != 6 && board[p - 1][q] != 5 && board[p - 1][q] != 6 && board[p][q - 1] != 5 && board[p][q - 1] != 6)))
								{
									calc++;
									tabx[x] = p;
									taby[y] = q;
									x++;
									y++;
								}
								else if (p == 0 && q > 0 && q < 9)
								{
									if ((board[p][q] != 5 && board[p][q] != 6 && board[p][q + 1] != 5 && board[p][q + 1] != 6 && board[p][q - 1] != 5 && board[p][q - 1] != 6)
										|| (board[p][q] != 5 && board[p][q] != 6 && board[p + 1][q] != 5 && board[p + 1][q] != 6 && board[p][q - 1] != 5 && board[p][q - 1] != 6)
										|| ((board[p][q] != 5 && board[p][q] != 6 && board[p + 1][q] != 5 && board[p + 1][q] != 6 && board[p][q + 1] != 5 && board[p][q + 1] != 6)))
									{
										calc++;
										tabx[x] = p;
										taby[y] = q;
										x++;
										y++;
									}
								}
								else if (p == 9 && q > 0 && q < 9)
								{
									if ((board[p][q] != 5 && board[p][q] != 6 && board[p][q + 1] != 5 && board[p][q + 1] != 6 && board[p][q - 1] != 5 && board[p][q - 1] != 6)
										|| ((board[p][q] != 5 && board[p][q] != 6 && board[p - 1][q] != 5 && board[p - 1][q] != 6 && board[p][q - 1] != 5 && board[p][q - 1] != 6))
										|| ((board[p][q] != 5 && board[p][q] != 6 && board[p - 1][q] != 5 && board[p - 1][q] != 6 && board[p][q + 1] != 5 && board[p][q + 1] != 6)))
									{
										calc++;
										tabx[x] = p;
										taby[y] = q;
										x++;
										y++;

									}
								}
								else if (q == 0 && p > 0 && p < 9)
								{
									if ((board[p][q] != 5 && board[p][q] != 6 && board[p - 1][q] != 5 && board[p - 1][q] != 6 && board[p][q + 1] != 5 && board[p][q + 1] != 6)
										|| ((board[p][q] != 5 && board[p][q] != 6 && board[p + 1][q] != 5 && board[p + 1][q] != 6 && board[p][q + 1] != 5 && board[p][q + 1] != 6))
										|| ((board[p][q] != 5 && board[p][q] != 6 && board[p + 1][q] != 5 && board[p + 1][q] != 6 && board[p - 1][q] != 5 && board[p - 1][q] != 6)))
									{
										calc++;
										tabx[x] = p;
										taby[y] = q;
										x++;
										y++;

									}
								}
								else if (q == 9 && p > 0 && p < 9)
								{
									if ((board[p][q] != 5 && board[p][q] != 6 && board[p - 1][q] != 5 && board[p - 1][q] != 6 && board[p][q - 1] != 5 && board[p][q - 1] != 6)
										|| ((board[p][q] != 5 && board[p][q] != 6 && board[p + 1][q] != 5 && board[p + 1][q] != 6 && board[p][q - 1] != 5 && board[p][q - 1] != 6))
										|| ((board[p][q] != 5 && board[p][q] != 6 && board[p + 1][q] != 5 && board[p + 1][q] != 6 && board[p - 1][q] != 5 && board[p - 1][q] != 6)))
									{
										calc++;
										tabx[x] = p;
										taby[y] = q;
										x++;
										y++;

									}
								}
								else if (p != 0 && p != 9 && q != 0 && q != 9)
								{

									if ((board[p][q] != 5 && board[p][q] != 6 && board[p][q + 1] != 5 && board[p][q + 1] != 6 && board[p][q - 1] != 5 && board[p][q - 1] != 6)
										|| ((board[p][q] != 5 && board[p][q] != 6 && board[p - 1][q] != 5 && board[p - 1][q] != 6 && board[p][q - 1] != 5 && board[p][q - 1] != 6))
										|| ((board[p][q] != 5 && board[p][q] != 6 && board[p - 1][q] != 5 && board[p - 1][q] != 6 && board[p][q + 1] != 5 && board[p][q + 1] != 6))
										|| ((board[p][q] != 5 && board[p][q] != 6 && board[p + 1][q] != 5 && board[p + 1][q] != 6 && board[p][q - 1] != 5 && board[p][q - 1] != 6))
										|| ((board[p][q] != 5 && board[p][q] != 6 && board[p + 1][q] != 5 && board[p + 1][q] != 6 && board[p][q + 1] != 5 && board[p][q + 1] != 6))
										|| ((board[p][q] != 5 && board[p][q] != 6 && board[p + 1][q] != 5 && board[p + 1][q] != 6 && board[p - 1][q] != 5 && board[p - 1][q] != 6)))
									{
										calc++;
										tabx[x] = p;
										taby[y] = q;
										x++;
										y++;

									}
								}
							}
						}
					}
					if (calc == 0)
					{
						for (int p = 0; p < 10; p++)
						{
							for (int q = 0; q < 10; q++)
							{
								if (p == 0 && q == 0)
								{
									if ((board[p][q] != 5 && board[p][q] != 6 && board[p][q + 1] != 5 && board[p][q + 1] != 6)
										|| ((board[p][q] != 5 && board[p][q] != 6 && board[p + 1][q] != 5 && board[p + 1][q] != 6)))
									{
										calc++;
										tabx[x] = p;
										taby[y] = q;
										x++;
										y++;
									}
								}
								else if (p == 0 && q == 9)
								{
									if ((board[p][q] != 5 && board[p][q] != 6 && board[p][q - 1] != 5 && board[p][q - 1] != 6)
										|| ((board[p][q] != 5 && board[p][q] != 6 && board[p + 1][q] != 5 && board[p + 1][q] != 6)))
									{
										calc++;
										tabx[x] = p;
										taby[y] = q;
										x++;
										y++;
									}
								}
								else if (p == 9 && q == 0)
								{
									if ((board[p][q] != 5 && board[p][q] != 6 && board[p][q + 1] != 5 && board[p][q + 1] != 6)
										|| ((board[p][q] != 5 && board[p][q] != 6 && board[p - 1][q] != 5 && board[p - 1][q] != 6)))
									{
										calc++;
										tabx[x] = p;
										taby[y] = q;
										x++;
										y++;
									}
								}
								else if (p == 9 && q == 9)
								{
									if ((board[p][q] != 5 && board[p][q] != 6 && board[p][q - 1] != 5 && board[p][q - 1] != 6)
										|| ((board[p][q] != 5 && board[p][q] != 6 && board[p - 1][q] != 5 && board[p - 1][q] != 6)))
									{
										calc++;
										tabx[x] = p;
										taby[y] = q;
										x++;
										y++;
									}
								}
								else if (p == 0 && q > 0 && q < 9)
								{
									if ((board[p][q] != 5 && board[p][q] != 6 && board[p][q - 1] != 5 && board[p][q - 1] != 6)
										|| ((board[p][q] != 5 && board[p][q] != 6 && board[p + 1][q] != 5 && board[p + 1][q] != 6))
										|| ((board[p][q] != 5 && board[p][q] != 6 && board[p][q + 1] != 5 && board[p][q + 1] != 6)))
									{
										calc++;
										tabx[x] = p;
										taby[y] = q;
										x++;
										y++;
									}
								}
								else if (p == 9 && q > 0 && q < 9)
								{
									if ((board[p][q] != 5 && board[p][q] != 6 && board[p][q - 1] != 5 && board[p][q - 1] != 6)
										|| ((board[p][q] != 5 && board[p][q] != 6 && board[p - 1][q] != 5 && board[p - 1][q] != 6))
										|| ((board[p][q] != 5 && board[p][q] != 6 && board[p][q + 1] != 5 && board[p][q + 1] != 6)))
									{
										calc++;
										tabx[x] = p;
										taby[y] = q;
										x++;
										y++;
									}
								}
								else if (q == 0 && p > 0 && p < 9)
								{
									if ((board[p][q] != 5 && board[p][q] != 6 && board[p][q + 1] != 5 && board[p][q + 1] != 6)
										|| ((board[p][q] != 5 && board[p][q] != 6 && board[p + 1][q] != 5 && board[p + 1][q] != 6))
										|| ((board[p][q] != 5 && board[p][q] != 6 && board[p - 1][q] != 5 && board[p - 1][q] != 6)))
									{
										calc++;
										tabx[x] = p;
										taby[y] = q;
										x++;
										y++;

									}
								}
								else if (q == 9 && p > 0 && p < 9)
								{
									if ((board[p][q] != 5 && board[p][q] != 6 && board[p][q - 1] != 5 && board[p][q - 1] != 6)
										|| ((board[p][q] != 5 && board[p][q] != 6 && board[p + 1][q] != 5 && board[p + 1][q] != 6))
										|| ((board[p][q] != 5 && board[p][q] != 6 && board[p - 1][q] != 5 && board[p - 1][q] != 6)))
									{
										calc++;
										tabx[x] = p;
										taby[y] = q;
										x++;
										y++;
									}
								}
								else if (p != 0 && p != 9 && q != 0 && q != 9)
								{
									if ((board[p][q] != 5 && board[p][q] != 6 && board[p][q - 1] != 5 && board[p][q - 1] != 6)
										|| ((board[p][q] != 5 && board[p][q] != 6 && board[p][q + 1] != 5 && board[p][q + 1] != 6))
										|| ((board[p][q] != 5 && board[p][q] != 6 && board[p - 1][q] != 5 && board[p - 1][q] != 6))
										|| ((board[p][q] != 5 && board[p][q] != 6 && board[p + 1][q] != 5 && board[p + 1][q] != 6)))
									{
										calc++;
										tabx[x] = p;
										taby[y] = q;
										x++;
										y++;
									}
								}
							}
						}
					}
				}
				else if (game.board1.three2 == false)
				{
					for (int p = 0; p < 10; p++)
					{
						for (int q = 0; q < 10; q++)
						{
							if (p == 0 && q > 0 && q < 9)
							{
								if (board[p][q] != 5 && board[p][q] != 6 && board[p][q - 1] != 5 && board[p][q - 1] != 6 && board[p][q + 1] != 5 && board[p][q + 1] != 6 && board[p + 1][q] != 5 && board[p + 1][q] != 6 && board[p + 2][q] != 5 && board[p + 2][q] != 6)
								{
									calc++;
									tabx[x] = p;
									taby[y] = q;
									x++;
									y++;
								}
							}
							else if (p == 9 && q > 0 && q < 9)
							{
								if (board[p][q] != 5 && board[p][q] != 6 && board[p][q - 1] != 5 && board[p][q - 1] != 6 && board[p][q + 1] != 5 && board[p][q + 1] != 6 && board[p - 1][q] != 5 && board[p - 1][q] != 6 && board[p - 2][q] != 5 && board[p - 2][q] != 6)
								{
									calc++;
									tabx[x] = p;
									taby[y] = q;
									x++;
									y++;

								}
							}
							else if (q == 0 && p > 0 && p < 9)
							{
								if (board[p][q] != 5 && board[p][q] != 6 && board[p - 1][q] != 5 && board[p - 1][q] != 6 && board[p + 1][q] != 5 && board[p + 1][q] != 6 && board[p][q + 1] != 5 && board[p][q + 1] != 6 && board[p][q + 2] != 5 && board[p][q + 2] != 6)
								{
									calc++;
									tabx[x] = p;
									taby[y] = q;
									x++;
									y++;

								}
							}
							else if (q == 9 && p > 0 && p < 9)
							{
								if (board[p][q] != 5 && board[p][q] != 6 && board[p - 1][q] != 5 && board[p - 1][q] != 6 && board[p + 1][q] != 5 && board[p + 1][q] != 6 && board[p][q - 1] != 5 && board[p][q - 1] != 6 && board[p][q - 2] != 5 && board[p][q - 2] != 6)
								{
									calc++;
									tabx[x] = p;
									taby[y] = q;
									x++;
									y++;

								}
							}
							else if (p != 0 && p != 9 && q != 0 && q != 9)
							{
								if (board[p][q] != 5 && board[p][q] != 6 && board[p - 1][q] != 5 && board[p - 1][q] != 6 && board[p + 1][q] != 5 && board[p + 1][q] != 6 && board[p][q - 1] != 5 && board[p][q - 1] != 6 && board[p][q + 1] != 5 && board[p][q + 1] != 6)
								{
									calc++;
									tabx[x] = p;
									taby[y] = q;
									x++;
									y++;

								}
							}
						}
					}
					if (calc == 0)
					{
						for (int p = 0; p < 10; p++)
						{
							for (int q = 0; q < 10; q++)
							{
								if (p == 0 && q > 0 && q < 9)
								{
									if (board[p][q] != 5 && board[p][q] != 6 && board[p][q - 1] != 5 && board[p][q - 1] != 6 && board[p][q + 1] != 5 && board[p][q + 1] != 6)
									{
										calc++;
										tabx[x] = p;
										taby[y] = q;
										x++;
										y++;

									}
								}
								else if (p == 9 && q > 0 && q < 9)
								{
									if (board[p][q] != 5 && board[p][q] != 6 && board[p][q - 1] != 5 && board[p][q - 1] != 6 && board[p][q + 1] != 5 && board[p][q + 1] != 6)
									{
										calc++;
										tabx[x] = p;
										taby[y] = q;
										x++;
										y++;

									}
								}
								else if (q == 0 && p > 0 && p < 9)
								{
									if (board[p][q] != 5 && board[p][q] != 6 && board[p - 1][q] != 5 && board[p - 1][q] != 6 && board[p + 1][q] != 5 && board[p + 1][q] != 6)
									{
										calc++;
										tabx[x] = p;
										taby[y] = q;
										x++;
										y++;

									}
								}
								else if (q == 9 && p > 0 && p < 9)
								{
									if (board[p][q] != 5 && board[p][q] != 6 && board[p - 1][q] != 5 && board[p - 1][q] != 6 && board[p + 1][q] != 5 && board[p + 1][q] != 6)
									{
										calc++;
										tabx[x] = p;
										taby[y] = q;
										x++;
										y++;

									}
								}
								else if (p != 0 && p != 9 && q != 0 && q != 9)
								{
									if (board[p][q] != 5 && board[p][q] != 6 && board[p - 1][q] != 5 && board[p - 1][q] != 6 && board[p + 1][q] != 5 && board[p + 1][q] != 6)
									{
										calc++;
										tabx[x] = p;
										taby[y] = q;
										x++;
										y++;

									}
									else if (board[p][q] != 5 && board[p][q] != 6 && board[p][q - 1] != 5 && board[p][q - 1] != 6 && board[p][q + 1] != 5 && board[p][q + 1] != 6)
									{
										calc++;
										tabx[x] = p;
										taby[y] = q;
										x++;
										y++;

									}
								}
							}
						}
					}
				}
				else if (game.board1.four1 == false)
				{
					for (int p = 0; p < 10; p++)
					{
						for (int q = 0; q < 10; q++)
						{
							if (p == 0 && q > 1 && q < 8)
							{
								if (board[p][q] != 5 && board[p][q] != 6 && board[p][q - 1] != 5 && board[p][q - 1] != 6 && board[p][q + 1] != 5 && board[p][q + 1] != 6 && ((board[p][q - 2] != 5 && board[p][q - 2] != 6) || (board[p][q + 2] != 5 && board[p][q + 2] != 6)) && board[p + 1][q] != 5 && board[p + 1][q] != 6 && board[p + 2][q] != 5 && board[p + 2][q] != 6 && board[p + 3][q] != 5 && board[p + 3][q] != 6)
								{
									calc++;
									tabx[x] = p;
									taby[y] = q;
									x++;
									y++;

								}
							}
							else if (p == 9 && q > 1 && q < 8)
							{
								if (board[p][q] != 5 && board[p][q] != 6 && board[p][q - 1] != 5 && board[p][q - 1] != 6 && board[p][q + 1] != 5 && board[p][q + 1] != 6 && ((board[p][q - 2] != 5 && board[p][q - 2] != 6) || (board[p][q + 2] != 5 && board[p][q + 2] != 6)) && board[p - 1][q] != 5 && board[p - 1][q] != 6 && board[p - 2][q] != 5 && board[p - 2][q] != 6 && board[p - 3][q] != 5 && board[p - 3][q] != 6)
								{
									calc++;
									tabx[x] = p;
									taby[y] = q;
									x++;
									y++;

								}
							}
							else if (q == 0 && p > 1 && p < 8)
							{
								if (board[p][q] != 5 && board[p][q] != 6 && board[p - 1][q] != 5 && board[p - 1][q] != 6 && board[p + 1][q] != 5 && board[p + 1][q] != 6 && ((board[p - 2][q] != 5 && board[p - 2][q] != 6) || (board[p + 2][q] != 5 && board[p + 2][q] != 6)) && board[p][q + 1] != 5 && board[p][q + 1] != 6 && board[p][q + 2] != 5 && board[p][q + 2] != 6 && board[p][q + 3] != 5 && board[p][q + 3] != 6)
								{
									calc++;
									tabx[x] = p;
									taby[y] = q;
									x++;
									y++;

								}
							}
							else if (q == 9 && p > 1 && p < 8)
							{
								if (board[p][q] != 5 && board[p][q] != 6 && board[p - 1][q] != 5 && board[p - 1][q] != 6 && board[p + 1][q] != 5 && board[p + 1][q] != 6 && ((board[p - 2][q] != 5 && board[p - 2][q] != 6) || (board[p + 2][q] != 5 && board[p + 2][q] != 6)) && board[p][q - 1] != 5 && board[p][q - 1] != 6 && board[p][q - 2] != 5 && board[p][q - 2] != 6 && board[p][q - 3] != 5 && board[p][q + 3] != 6)
								{
									calc++;
									tabx[x] = p;
									taby[y] = q;
									x++;
									y++;

								}
							}
							else if (p != 0 && p != 9 && q != 0 && q != 9 && p != 1 && p != 8 && q != 1 && q != 8)
							{
								if (board[p][q] != 5 && board[p][q] != 6 && board[p][q - 1] != 5 && board[p][q - 1] != 6 && board[p][q + 1] != 5 && board[p][q + 1] != 6 && ((board[p][q - 2] != 5 && board[p][q - 2] != 6) || (board[p][q + 2] != 5 && board[p][q + 2] != 6)) && board[p - 1][q] != 5 && board[p - 1][q] != 6 && board[p + 1][q] != 5 && board[p + 1][q] != 6 && ((board[p - 2][q] != 5 && board[p - 2][q] != 6) || (board[p + 2][q] != 5 && board[p + 2][q] != 6)))
								{
									calc++;
									tabx[x] = p;
									taby[y] = q;
									x++;
									y++;

								}
							}
						}
					}
					if (calc == 0)
					{
						for (int p = 0; p < 10; p++)
						{
							for (int q = 0; q < 10; q++)
							{
								if (p == 0 && q > 1 && q < 8)
								{
									if (board[p][q] != 5 && board[p][q] != 6 && board[p][q - 1] != 5 && board[p][q - 1] != 6 && board[p][q + 1] != 5 && board[p][q + 1] != 6 && ((board[p][q - 2] != 5 && board[p][q - 2] != 6) || (board[p][q + 2] != 5 && board[p][q + 2] != 6)))
									{
										calc++;
										tabx[x] = p;
										taby[y] = q;
										x++;
										y++;

									}
								}
								else if (p == 9 && q > 1 && q < 8)
								{
									if (board[p][q] != 5 && board[p][q] != 6 && board[p][q - 1] != 5 && board[p][q - 1] != 6 && board[p][q + 1] != 5 && board[p][q + 1] != 6 && ((board[p][q - 2] != 5 && board[p][q - 2] != 6) || (board[p][q + 2] != 5 && board[p][q + 2] != 6)))
									{
										calc++;
										tabx[x] = p;
										taby[y] = q;
										x++;
										y++;

									}
								}
								else if (q == 0 && p > 1 && p < 8)
								{
									if (board[p][q] != 5 && board[p][q] != 6 && board[p - 1][q] != 5 && board[p - 1][q] != 6 && board[p + 1][q] != 5 && board[p + 1][q] != 6 && ((board[p - 2][q] != 5 && board[p - 2][q] != 6) || (board[p + 2][q] != 5 && board[p + 2][q] != 6)))
									{
										calc++;
										tabx[x] = p;
										taby[y] = q;
										x++;
										y++;

									}
								}
								else if (q == 9 && p > 1 && p < 8)
								{
									if (board[p][q] != 5 && board[p][q] != 6 && board[p - 1][q] != 5 && board[p - 1][q] != 6 && board[p + 1][q] != 5 && board[p + 1][q] != 6 && ((board[p - 2][q] != 5 && board[p - 2][q] != 6) || (board[p + 2][q] != 5 && board[p + 2][q] != 6)))
									{
										calc++;
										tabx[x] = p;
										taby[y] = q;
										x++;
										y++;

									}
								}
								else if (p != 0 && p != 9 && q != 0 && q != 9 && p != 1 && p != 8 && q != 1 && q != 8)
								{
									if (board[p][q] != 5 && board[p][q] != 6 && board[p][q - 1] != 5 && board[p][q - 1] != 6 && board[p][q + 1] != 5 && board[p][q + 1] != 6 && ((board[p][q - 2] != 5 && board[p][q - 2] != 6) || (board[p][q + 2] != 5 && board[p][q + 2] != 6)))
									{
										calc++;
										tabx[x] = p;
										taby[y] = q;
										x++;
										y++;

									}
									else if (board[p][q] != 5 && board[p][q] != 6 && board[p - 1][q] != 5 && board[p - 1][q] != 6 && board[p + 1][q] != 5 && board[p + 1][q] != 6 && ((board[p - 2][q] != 5 && board[p - 2][q] != 6) || (board[p + 2][q] != 5 && board[p + 2][q] != 6)))
									{
										calc++;
										tabx[x] = p;
										taby[y] = q;
										x++;
										y++;

									}
								}

							}
						}
					}
				}

				uniform_int_distribution<int> wsp(0, x);
				do
				{
					coord = wsp(randomGenerator);

					row = tabx[coord];
					column = taby[coord];
				} while (board[row][column] == 5 || board[row][column] == 6);
			}
			else
			{
				do
				{
					row = rowGen(randomGenerator);
					column = colGen(randomGenerator);
				} while (board[row][column] == 6 || board[row][column] == 5);

			}
		}
		else
		{
				if (directionCheck == 0)
				{
					do
					{
						knownDirection = directionGen(randomGenerator) + 1;
						if (knownRow == 0 && knownDirection == 1) knownDirection = 0;
						else if (knownRow == 9 && knownDirection == 3) knownDirection = 0;
						else if (knownColumn == 0 && knownDirection == 4) knownDirection = 0;
						else if (knownColumn == 9 && knownDirection == 2) knownDirection = 0;
						if (knownDirection == 1 && board[knownRow - 1][knownColumn] == 5) knownDirection = 0;
						else if (knownDirection == 2 && board[knownRow][knownColumn + 1] == 5) knownDirection = 0;
						else if (knownDirection == 3 && board[knownRow + 1][knownColumn] == 5) knownDirection = 0;
						else if (knownDirection == 4 && board[knownRow][knownColumn - 1] == 5) knownDirection = 0;
					} while (knownDirection == 0);
					if (knownDirection == 1)
					{
						row = knownRow - 1;
						column = knownColumn;
						if (board[row][column] == 3 || board[row][column] == 4) directionCheck = 2;

					}
					else if (knownDirection == 2)
					{
						row = knownRow;
						column = knownColumn + 1;
						if (board[row][column] == 3 || board[row][column] == 4) directionCheck = 1;

					}
					else if (knownDirection == 3)
					{
						row = knownRow + 1;
						column = knownColumn;
						if (board[row][column] == 3 || board[row][column] == 4) directionCheck = 2;

					}
					else if (knownDirection == 4)
					{
						row = knownRow;
						column = knownColumn - 1;
						if (board[row][column] == 3 || board[row][column] == 4) directionCheck = 1;

					}
				}

				else if (directionCheck == 1)
				{
					if (board[knownRow][knownColumn - 1] != 5 && board[knownRow][knownColumn - 1] != 6 && knownColumn - 1 >= 0)
					{
						row = knownRow;
						column = knownColumn - 1;
					}
					else if ((board[knownRow][knownColumn - 1] == 5 || board[knownRow][knownColumn - 1] == 6) && board[knownRow][knownColumn + 1] != 5 && board[knownRow][knownColumn + 1] != 6 && knownColumn + 1 <= 9)
					{
						row = knownRow;
						column = knownColumn + 1;
					}
					else if (board[knownRow][knownColumn - 1] == 6 && (board[knownRow][knownColumn + 1] == 5 || board[knownRow][knownColumn + 1] == 6) && board[knownRow][knownColumn - 2] != 5 && board[knownRow][knownColumn - 2] != 6 && knownColumn - 2 >= 0)
					{
						row = knownRow;
						column = knownColumn - 2;
					}
					else if ((board[knownRow][knownColumn - 1] == 5 || board[knownRow][knownColumn - 1] == 6) && board[knownRow][knownColumn + 1] == 6 && board[knownRow][knownColumn + 2] != 5 && board[knownRow][knownColumn + 2] != 6 && knownColumn + 2 <= 9)
					{
						row = knownRow;
						column = knownColumn + 2;
					}
					else if (board[knownRow][knownColumn - 1] == 6 && (board[knownRow][knownColumn + 1] == 5 || board[knownRow][knownColumn + 1] == 6) && board[knownRow][knownColumn - 2] == 6 && board[knownRow][knownColumn - 3] != 5 && board[knownRow][knownColumn - 3] != 6 && knownColumn - 3 >= 0)
					{
						row = knownRow;
						column = knownColumn - 3;
					}
					else if (board[knownRow][knownColumn - 1] == 5 && board[knownRow][knownColumn + 1] == 6 && board[knownRow][knownColumn + 2] == 6 && board[knownRow][knownColumn + 3] != 5 && board[knownRow][knownColumn + 3] != 6 && knownColumn + 3 <= 9)
					{
						row = knownRow;
						column = knownColumn + 3;
					}
				}
				else if (directionCheck == 2)
				{
					if (board[knownRow - 1][knownColumn] != 5 && board[knownRow - 1][knownColumn] != 6 && knownRow - 1 >= 0)
					{
						row = knownRow - 1;
						column = knownColumn;
					}
					else if ((board[knownRow - 1][knownColumn] == 5 || board[knownRow - 1][knownColumn] == 6) && board[knownRow + 1][knownColumn] != 5 && board[knownRow + 1][knownColumn] != 6 && knownRow + 1 <= 9)
					{
						row = knownRow + 1;
						column = knownColumn;
					}
					else if (board[knownRow - 1][knownColumn] == 6 && (board[knownRow + 1][knownColumn] == 5 || board[knownRow + 1][knownColumn] == 6) && board[knownRow - 2][knownColumn] != 5 && board[knownRow - 2][knownColumn] != 6 && knownRow - 2 >= 0)
					{
						row = knownRow - 2;
						column = knownColumn;
					}
					else if ((board[knownRow - 1][knownColumn] == 5 || board[knownRow - 1][knownColumn] == 6) && board[knownRow + 1][knownColumn] == 6 && board[knownRow + 2][knownColumn] != 5 && board[knownRow + 2][knownColumn] != 6 && knownRow + 2 <= 9)
					{
						row = knownRow + 2;
						column = knownColumn;
					}
					else if (board[knownRow - 1][knownColumn] == 6 && board[knownRow - 2][knownColumn] == 6 && board[knownRow + 1][knownColumn] == 5 && board[knownRow - 3][knownColumn] != 5 && board[knownRow - 3][knownColumn] != 6 && knownRow - 3 >= 0)
					{
						row = knownRow - 3;
						column = knownColumn;
					}
					else if (board[knownRow - 1][knownColumn] == 5 && board[knownRow + 1][knownColumn] == 6 && board[knownRow + 2][knownColumn] == 6 && board[knownRow + 3][knownColumn] != 5 && board[knownRow + 3][knownColumn] != 6 && knownRow + 3 <= 9)
					{
						row = knownRow + 3;
						column = knownColumn;
					}
				}
			}
		return;
	case MEDIUM:
		if (!isHit)
		{
			do
			{
				row = rowGen(randomGenerator);
				column = colGen(randomGenerator);
			} while (board[row][column] == 6 || board[row][column] == 5);
		}
		else
		{
			if (directionCheck == 0)
			{
				do
				{
					knownDirection = directionGen(randomGenerator) + 1;
					if (knownRow == 0 && knownDirection == 1) knownDirection = 0;
					else if (knownRow == 9 && knownDirection == 3) knownDirection = 0;
					else if (knownColumn == 0 && knownDirection == 4) knownDirection = 0;
					else if (knownColumn == 9 && knownDirection == 2) knownDirection = 0;
					if (knownDirection == 1 && board[knownRow - 1][knownColumn] == 5) knownDirection = 0;
					else if (knownDirection == 2 && board[knownRow][knownColumn + 1] == 5) knownDirection = 0;
					else if (knownDirection == 3 && board[knownRow + 1][knownColumn] == 5) knownDirection = 0;
					else if (knownDirection == 4 && board[knownRow][knownColumn - 1] == 5) knownDirection = 0;

				} while (knownDirection == 0);
				if (knownDirection == 1)
				{
					row = knownRow - 1;
					column = knownColumn;
					if (board[row][column] == 3 || board[row][column] == 4) directionCheck = 2;

				}
				else if (knownDirection == 2)
				{
					row = knownRow;
					column = knownColumn + 1;
					if (board[row][column] == 3 || board[row][column] == 4) directionCheck = 1;

				}
				else if (knownDirection == 3)
				{
					row = knownRow + 1;
					column = knownColumn;
					if (board[row][column] == 3 || board[row][column] == 4) directionCheck = 2;

				}
				else if (knownDirection == 4)
				{
					row = knownRow;
					column = knownColumn - 1;
					if (board[row][column] == 3 || board[row][column] == 4) directionCheck = 1;

				}
			}
			else if (directionCheck == 1)
			{
				if (board[knownRow][knownColumn - 1] != 5 && board[knownRow][knownColumn - 1] != 6 && knownColumn - 1 >= 0)
				{
					row = knownRow;
					column = knownColumn - 1;
				}
				else if ((board[knownRow][knownColumn - 1] == 5 || board[knownRow][knownColumn - 1] == 6) && board[knownRow][knownColumn + 1] != 5 && board[knownRow][knownColumn + 1] != 6 && knownColumn + 1 <= 9)
				{
					row = knownRow;
					column = knownColumn + 1;
				}
				else if (board[knownRow][knownColumn - 1] == 6 && (board[knownRow][knownColumn + 1] == 5 || board[knownRow][knownColumn + 1] == 6) && board[knownRow][knownColumn - 2] != 5 && board[knownRow][knownColumn - 2] != 6 && knownColumn - 2 >= 0)
				{
					row = knownRow;
					column = knownColumn - 2;
				}
				else if ((board[knownRow][knownColumn - 1] == 5 || board[knownRow][knownColumn - 1] == 6) && board[knownRow][knownColumn + 1] == 6 && board[knownRow][knownColumn + 2] != 5 && board[knownRow][knownColumn + 2] != 6 && knownColumn + 2 <= 9)
				{
					row = knownRow;
					column = knownColumn + 2;
				}
				else if (board[knownRow][knownColumn - 1] == 6 && (board[knownRow][knownColumn + 1] == 5 || board[knownRow][knownColumn + 1] == 6) && board[knownRow][knownColumn - 2] == 6 && board[knownRow][knownColumn - 3] != 5 && board[knownRow][knownColumn - 3] != 6 && knownColumn - 3 >= 0)
				{
					row = knownRow;
					column = knownColumn - 3;
				}
				else if (board[knownRow][knownColumn - 1] == 5 && board[knownRow][knownColumn + 1] == 6 && board[knownRow][knownColumn + 2] == 6 && board[knownRow][knownColumn + 3] != 5 && board[knownRow][knownColumn + 3] != 6 && knownColumn + 3 <= 9)
				{
					row = knownRow;
					column = knownColumn + 3;
				}
			}
			else if (directionCheck == 2)
			{
				if (board[knownRow - 1][knownColumn] != 5 && board[knownRow - 1][knownColumn] != 6 && knownRow - 1 >= 0)
				{
					row = knownRow - 1;
					column = knownColumn;
				}
				else if ((board[knownRow - 1][knownColumn] == 5 || board[knownRow - 1][knownColumn] == 6) && board[knownRow + 1][knownColumn] != 5 && board[knownRow + 1][knownColumn] != 6 && knownRow + 1 <= 9)
				{
					row = knownRow + 1;

				}
				else if (board[knownRow - 1][knownColumn] == 6 && (board[knownRow + 1][knownColumn] == 5 || board[knownRow + 1][knownColumn] == 6) && board[knownRow - 2][knownColumn] != 5 && board[knownRow - 2][knownColumn] != 6 && knownRow - 2 >= 0)
				{
					row = knownRow - 2;
					column = knownColumn;
				}
				else if ((board[knownRow - 1][knownColumn] == 5 || board[knownRow - 1][knownColumn] == 6) && board[knownRow + 1][knownColumn] == 6 && board[knownRow + 2][knownColumn] != 5 && board[knownRow + 2][knownColumn] != 6 && knownRow + 2 <= 9)
				{
					row = knownRow + 2;
					column = knownColumn;
				}
				else if (board[knownRow - 1][knownColumn] == 6 && board[knownRow - 2][knownColumn] == 6 && board[knownRow + 1][knownColumn] == 5 && board[knownRow - 3][knownColumn] != 5 && board[knownRow - 3][knownColumn] != 6 && knownRow - 3 >= 0)
				{
					row = knownRow - 3;
					column = knownColumn;
				}
				else if (board[knownRow - 1][knownColumn] == 5 && board[knownRow + 1][knownColumn] == 6 && board[knownRow + 2][knownColumn] == 6 && board[knownRow + 3][knownColumn] != 5 && board[knownRow + 3][knownColumn] != 6 && knownRow + 3 <= 9)
				{
					row = knownRow + 3;
					column = knownColumn;
				}
			}
		}
		return;
	case EASY:
	default:
		do
		{
			row = rowGen(randomGenerator);
			column = colGen(randomGenerator);
		} while (board[row][column] == 6 || board[row][column] == 5);
		return;
	}
}