#include <iostream>
#include <random>
#include <windows.h>
#include <string>
#include <ctime>
#include <fstream>

using namespace std;

random_device rd;
mt19937 generator(rd());
uniform_int_distribution<int> wierszL(0, 9);
uniform_int_distribution<int> kolumnaL(0, 9);
uniform_int_distribution<int> kierunekL(0, 3);
uniform_int_distribution<int> ktoZaczyna1(0, 1);

fstream plik;

void ramka(string napis, void(*spacje)(int))
{
	HANDLE hOut;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);

	//RAMECZKOWE ZMIENNE//
	unsigned char LG = 201;
	unsigned char poziom = 205;
	unsigned char pion = 186;
	unsigned char LD = 200;
	unsigned char PG = 187;
	unsigned char PD = 188;
	int dl_napisu = napis.length() - (napis.length() % 2);
	int dl = napis.length();
	spacje((114 - dl_napisu) / 2);
	SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE);
	cout << LG;
	for (int a = 0; a < dl + 4; a++)
		cout << poziom;
	cout << PG << endl;
	spacje((114 - dl_napisu) / 2);
	cout << pion;
	spacje(dl + 4);
	cout << pion << endl;
	spacje((114 - dl_napisu) / 2);
	SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE);
	cout << pion;
	SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
	cout << "  " << napis << "  ";
	SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE);
	cout << pion << endl;
	spacje((114 - dl_napisu) / 2);
	cout << pion;
	spacje(dl + 4);
	cout << pion << endl;
	spacje((114 - dl_napisu) / 2);
	cout << LD;
	for (int a = 0; a < dl + 4; a++)
		cout << poziom;
	cout << PD << endl << endl;
	SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);


}

void usun(int w, int k, int plansza[10][10])
{
	for (int a = 0; a < 3; a++)
	{
		for (int b = 0; b < 3; b++)
		{
			if (w > 1 && k > 1 && w < 8 && k < 8 && plansza[w - 1 + a][k - 1 + b] == -1)
			{
				if (plansza[w - 2 + a][k - 2 + b] < 1 && plansza[w - 2 + a][k - 1 + b] < 1 && plansza[w - 2 + a][k + b] < 1 && plansza[w - 1 + a][k - 2 + b] < 1 && plansza[w - 1 + a][k + b] < 1 && plansza[w + a][k - 2 + b] < 1 && plansza[w + a][k - 1 + b] < 1 && plansza[w + a][k + b] < 1)
				{
					plansza[w - 1 + a][k - 1 + b] = 0;

				}
			}
			else if (((w == 1 && k != 0 && k != 9) || (w == 8 && k != 0 && k != 9) || (k == 1 && w != 0 && w != 9) || (k == 8 && w != 0 && w != 9)))
			{
				if (w == 1 && k > 1 && k < 8)
				{
					if (a == 0)
					{
						if (plansza[w - 1 + a][k - 2 + b] < 1 && plansza[w - 1 + a][k + b] < 1 && plansza[w + a][k - 2 + b] < 1 && plansza[w + a][k - 1 + b] < 1 && plansza[w + a][k + b] < 1)
						{
							plansza[w - 1 + a][k - 1 + b] = 0;

						}
					}
					else
					{
						if (plansza[w - 2 + a][k - 2 + b] < 1 && plansza[w - 2 + a][k - 1 + b] < 1 && plansza[w - 2 + a][k + b] < 1 && plansza[w - 1 + a][k - 2 + b] < 1 && plansza[w - 1 + a][k + b] < 1 && plansza[w + a][k - 2 + b] < 1 && plansza[w + a][k - 1 + b] < 1 && plansza[w + a][k + b] < 1)
						{
							plansza[w - 1 + a][k - 1 + b] = 0;

						}
					}

				}
				else if (w == 8 && k > 1 && k < 8)
				{
					if (a == 2)
					{
						if (plansza[w - 2 + a][k - 2 + b] < 1 && plansza[w - 2 + a][k - 1 + b] < 1 && plansza[w - 2 + a][k + b] < 1 && plansza[w - 1 + a][k - 2 + b] < 1 && plansza[w - 1 + a][k + b] < 1)
						{
							plansza[w - 1 + a][k - 1 + b] = 0;

						}
					}
					else
					{
						if (plansza[w - 2 + a][k - 2 + b] < 1 && plansza[w - 2 + a][k - 1 + b] < 1 && plansza[w - 2 + a][k + b] < 1 && plansza[w - 1 + a][k - 2 + b] < 1 && plansza[w - 1 + a][k + b] < 1 && plansza[w + a][k - 2 + b] < 1 && plansza[w + a][k - 1 + b] < 1 && plansza[w + a][k + b] < 1)
						{
							plansza[w - 1 + a][k - 1 + b] = 0;

						}
					}

				}
				else if (k == 1 && w > 1 && w < 8)
				{
					if (b == 0)
					{
						if (plansza[w - 2 + a][k - 1 + b] < 1 && plansza[w - 2 + a][k + b] < 1 && plansza[w - 1 + a][k + b] < 1 && plansza[w + a][k - 1 + b] < 1 && plansza[w + a][k + b] < 1)
						{
							plansza[w - 1 + a][k - 1 + b] = 0;

						}

					}
					else
					{
						if (plansza[w - 2 + a][k - 2 + b] < 1 && plansza[w - 2 + a][k - 1 + b] < 1 && plansza[w - 2 + a][k + b] < 1 && plansza[w - 1 + a][k - 2 + b] < 1 && plansza[w - 1 + a][k + b] < 1 && plansza[w + a][k - 2 + b] < 1 && plansza[w + a][k - 1 + b] < 1 && plansza[w + a][k + b] < 1)
						{
							plansza[w - 1 + a][k - 1 + b] = 0;

						}

					}

				}
				else if (k == 8 && w > 1 && w < 8)
				{
					if (b == 2)
					{
						if (plansza[w - 2 + a][k - 2 + b] < 1 && plansza[w - 2 + a][k - 1 + b] < 1 && plansza[w - 1 + a][k - 2 + b] < 1 && plansza[w + a][k - 2 + b] < 1 && plansza[w + a][k - 1 + b] < 1)
						{
							plansza[w - 1 + a][k - 1 + b] = 0;

						}

					}
					else
					{
						if (plansza[w - 2 + a][k - 2 + b] < 1 && plansza[w - 2 + a][k - 1 + b] < 1 && plansza[w - 2 + a][k + b] < 1 && plansza[w - 1 + a][k - 2 + b] < 1 && plansza[w - 1 + a][k + b] < 1 && plansza[w + a][k - 2 + b] < 1 && plansza[w + a][k - 1 + b] < 1 && plansza[w + a][k + b] < 1)
						{
							plansza[w - 1 + a][k - 1 + b] = 0;

						}

					}

				}
				else if (w == 1 && k == 1)
				{
					if (a == 0 && b == 0)
						plansza[w - 1 + a][k - 1 + b] = 0;

					else if (a == 0 && b != 0)
					{
						if (plansza[w - 1 + a][k - 2 + b] < 1 && plansza[w - 1 + a][k + b] < 1 && plansza[w + a][k - 2 + b] < 1 && plansza[w + a][k - 1 + b] < 1 && plansza[w + a][k + b] < 1)
						{
							plansza[w - 1 + a][k - 1 + b] = 0;

						}
					}
					else if (a != 0 && b == 0)
					{
						if (plansza[w - 2 + a][k - 1 + b] < 1 && plansza[w - 2 + a][k + b] < 1 && plansza[w - 1 + a][k + b] < 1 && plansza[w + a][k - 1 + b] < 1 && plansza[w + a][k + b] < 1)
						{
							plansza[w - 1 + a][k - 1 + b] = 0;

						}
					}

					else
					{
						if (plansza[w - 2 + a][k - 2 + b] < 1 && plansza[w - 2 + a][k - 1 + b] < 1 && plansza[w - 2 + a][k + b] < 1 && plansza[w - 1 + a][k - 2 + b] < 1 && plansza[w - 1 + a][k + b] < 1 && plansza[w + a][k - 2 + b] < 1 && plansza[w + a][k - 1 + b] < 1 && plansza[w + a][k + b] < 1)
						{
							plansza[w - 1 + a][k - 1 + b] = 0;

						}
					}


				}
				else if (w == 1 && k == 8)
				{
					if (a == 0 && b == 2)
						plansza[w - 1 + a][k - 1 + b] = 0;

					else if (a == 0 && b != 2)
					{
						if (plansza[w - 1 + a][k - 2 + b] < 1 && plansza[w - 1 + a][k + b] < 1 && plansza[w + a][k - 2 + b] < 1 && plansza[w + a][k - 1 + b] < 1 && plansza[w + a][k + b] < 1)
						{
							plansza[w - 1 + a][k - 1 + b] = 0;

						}
					}
					else if (a != 0 && b == 2)
					{
						if (plansza[w - 2 + a][k - 2 + b] < 1 && plansza[w - 2 + a][k - 1 + b] < 1 && plansza[w - 1 + a][k - 2 + b] < 1 && plansza[w + a][k - 2 + b] < 1 && plansza[w + a][k - 1 + b] < 1)
						{
							plansza[w - 1 + a][k - 1 + b] = 0;

						}

					}

					else
					{
						if (plansza[w - 2 + a][k - 2 + b] < 1 && plansza[w - 2 + a][k - 1 + b] < 1 && plansza[w - 2 + a][k + b] < 1 && plansza[w - 1 + a][k - 2 + b] < 1 && plansza[w - 1 + a][k + b] < 1 && plansza[w + a][k - 2 + b] < 1 && plansza[w + a][k - 1 + b] < 1 && plansza[w + a][k + b] < 1)
						{
							plansza[w - 1 + a][k - 1 + b] = 0;

						}
					}

				}
				else if (w == 8 && k == 1)
				{
					if (a == 2 && b == 0)
						plansza[w - 1 + a][k - 1 + b] = 0;

					else if (a == 2 && b != 0)
					{
						if (plansza[w - 2 + a][k - 2 + b] < 1 && plansza[w - 2 + a][k - 1 + b] < 1 && plansza[w - 2 + a][k + b] < 1 && plansza[w - 1 + a][k - 2 + b] < 1 && plansza[w - 1 + a][k + b] < 1)
						{
							plansza[w - 1 + a][k - 1 + b] = 0;

						}
					}
					else if (a != 0 && b == 0)
					{
						if (plansza[w - 2 + a][k - 1 + b] < 1 && plansza[w - 2 + a][k + b] < 1 && plansza[w - 1 + a][k + b] < 1 && plansza[w + a][k - 1 + b] < 1 && plansza[w + a][k + b] < 1)
						{
							plansza[w - 1 + a][k - 1 + b] = 0;

						}
					}

					else if (a != 2 && b != 0)
					{
						if (plansza[w - 2 + a][k - 1 + b] < 1 && plansza[w - 2 + a][k + b] < 1 && plansza[w - 1 + a][k - 2 + b] < 1 && plansza[w - 1 + a][k + b] < 1 && plansza[w + a][k - 2 + b] < 1 && plansza[w + a][k - 1 + b] < 1 && plansza[w + a][k + b] < 1)
						{
							plansza[w - 1 + a][k - 1 + b] = 0;

						}
					}
					else
					{
						if (plansza[w - 2 + a][k - 1 + b] < 1 && plansza[w - 2 + a][k + b] < 1 && plansza[w - 1 + a][k + b] < 1)
						{
							plansza[w - 1 + a][k - 1 + b] = 0;

						}
					}

				}
				else if (w == 8 && k == 8)
				{
					if (a == 2 && b == 2)
						plansza[w - 1 + a][k - 1 + b] = 0;

					else if (a == 2 && b != 2)
					{
						if (plansza[w - 2 + a][k - 2 + b] < 1 && plansza[w - 2 + a][k - 1 + b] < 1 && plansza[w - 2 + a][k + b] < 1 && plansza[w - 1 + a][k - 2 + b] < 1 && plansza[w - 1 + a][k + b] < 1)
						{
							plansza[w - 1 + a][k - 1 + b] = 0;

						}
					}
					else if (a != 2 && b == 2)
					{
						if (plansza[w - 2 + a][k - 2 + b] < 1 && plansza[w - 2 + a][k - 1 + b] < 1 && plansza[w - 1 + a][k - 2 + b] < 1 && plansza[w + a][k - 2 + b] < 1 && plansza[w + a][k - 1 + b] < 1)
						{
							plansza[w - 1 + a][k - 1 + b] = 0;

						}

					}
					else
					{
						if (plansza[w - 2 + a][k - 2 + b] < 1 && plansza[w - 2 + a][k - 1 + b] < 1 && plansza[w - 2 + a][k + b] < 1 && plansza[w - 1 + a][k - 2 + b] < 1 && plansza[w - 1 + a][k + b] < 1 && plansza[w + a][k - 2 + b] < 1 && plansza[w + a][k - 1 + b] < 1 && plansza[w + a][k + b] < 1)
						{
							plansza[w - 1 + a][k - 1 + b] = 0;

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

						if (plansza[w - 1 + a][k - 2 + b] < 1 && plansza[w - 1 + a][k + b] < 1 && plansza[w + a][k - 2 + b] < 1 && plansza[w + a][k - 1 + b] < 1 && plansza[w + a][k + b] < 1)
						{
							plansza[w - 1 + a][k - 1 + b] = 0;

						}
					}
					else if (a == 2 && b != 0)
					{
						if (plansza[w - 2 + a][k - 2 + b] < 1 && plansza[w - 2 + a][k - 1 + b] < 1 && plansza[w - 2 + a][k + b] < 1 && plansza[w - 1 + a][k - 2 + b] < 1 && plansza[w - 1 + a][k + b] < 1 && plansza[w + a][k - 2 + b] < 1 && plansza[w + a][k - 1 + b] < 1 && plansza[w + a][k + b] < 1)
						{
							plansza[w - 1 + a][k - 1 + b] = 0;

						}
					}
					else if (a == 1 && b == 0)
					{
						if (plansza[w - 1 + a][k + b] < 1 && plansza[w + a][k - 1 + b] < 1 && plansza[w + a][k + b] < 1)
						{
							plansza[w - 1 + a][k - 1 + b] = 0;
						}
					}
					else if (a == 2 && b == 0)
					{
						if (plansza[w - 2 + a][k - 1 + b] < 1 && plansza[w - 2 + a][k + b] < 1 && plansza[w - 1 + a][k + b] < 1 && plansza[w + a][k - 1 + b] < 1 && plansza[w + a][k + b] < 1)
						{
							plansza[w - 1 + a][k - 1 + b] = 0;

						}

					}
				}
				else if (w == 0 && k == 8)
				{
					if (a == 1 && b != 2)
					{
						if (plansza[w - 1 + a][k - 2 + b] < 1 && plansza[w - 1 + a][k + b] < 1 && plansza[w + a][k - 2 + b] < 1 && plansza[w + a][k - 1 + b] < 1 && plansza[w + a][k + b] < 1)
						{
							plansza[w - 1 + a][k - 1 + b] = 0;

						}
					}
					else if (a == 2 && b != 2)
					{
						if (plansza[w - 2 + a][k - 2 + b] < 1 && plansza[w - 2 + a][k - 1 + b] < 1 && plansza[w - 2 + a][k + b] < 1 && plansza[w - 1 + a][k - 2 + b] < 1 && plansza[w - 1 + a][k + b] < 1 && plansza[w + a][k - 2 + b] < 1 && plansza[w + a][k - 1 + b] < 1 && plansza[w + a][k + b] < 1)
						{
							plansza[w - 1 + a][k - 1 + b] = 0;

						}
					}
					else if (a == 1 && b == 2)
					{
						if (plansza[w - 1 + a][k - 2 + b] < 1 && plansza[w + a][k - 2 + b] < 1 && plansza[w + a][k - 1 + b] < 1)
						{
							plansza[w - 1 + a][k - 1 + b] = 0;
						}
					}
					else if (a == 2 && b == 2)
					{
						if (plansza[w - 2 + a][k - 2 + b] < 1 && plansza[w - 2 + a][k - 1 + b] < 1 && plansza[w - 1 + a][k - 2 + b] < 1 && plansza[w + a][k - 2 + b] < 1 && plansza[w + a][k - 1 + b] < 1)
						{
							plansza[w - 1 + a][k - 1 + b] = 0;

						}

					}

				}
				else if (w == 0 && k > 1 && k < 8)
				{
					if (a == 1)
					{
						if (plansza[w - 1 + a][k - 2 + b] < 1 && plansza[w - 1 + a][k + b] < 1 && plansza[w + a][k - 2 + b] < 1 && plansza[w + a][k - 1 + b] < 1 && plansza[w + a][k + b] < 1)
						{
							plansza[w - 1 + a][k - 1 + b] = 0;

						}
					}
					else if (a == 2)
					{
						if (plansza[w - 2 + a][k - 2 + b] < 1 && plansza[w - 2 + a][k - 1 + b] < 1 && plansza[w - 2 + a][k + b] < 1 && plansza[w - 1 + a][k - 2 + b] < 1 && plansza[w - 1 + a][k + b] < 1 && plansza[w + a][k - 2 + b] < 1 && plansza[w + a][k - 1 + b] < 1 && plansza[w + a][k + b] < 1)
						{
							plansza[w - 1 + a][k - 1 + b] = 0;

						}
					}

				}
				else if (w == 9 && k > 1 && k < 8)
				{
					if (a == 1)
					{
						if (plansza[w - 2 + a][k - 2 + b] < 1 && plansza[w - 2 + a][k - 1 + b] < 1 && plansza[w - 2 + a][k + b] < 1 && plansza[w - 1 + a][k - 2 + b] < 1 && plansza[w - 1 + a][k + b] < 1)
						{
							plansza[w - 1 + a][k - 1 + b] = 0;

						}
					}
					else if (a == 0)
					{
						if (plansza[w - 2 + a][k - 2 + b] < 1 && plansza[w - 2 + a][k - 1 + b] < 1 && plansza[w - 2 + a][k + b] < 1 && plansza[w - 1 + a][k - 2 + b] < 1 && plansza[w - 1 + a][k + b] < 1 && plansza[w + a][k - 2 + b] < 1 && plansza[w + a][k - 1 + b] < 1 && plansza[w + a][k + b] < 1)
						{
							plansza[w - 1 + a][k - 1 + b] = 0;

						}
					}


				}
				else if (w == 9 && k == 1)
				{
					if (a == 0 && b != 0)
					{
						if (plansza[w - 2 + a][k - 2 + b] < 1 && plansza[w - 2 + a][k - 1 + b] < 1 && plansza[w - 2 + a][k + b] < 1 && plansza[w - 1 + a][k - 2 + b] < 1 && plansza[w - 1 + a][k + b] < 1 && plansza[w + a][k - 2 + b] < 1 && plansza[w + a][k - 1 + b] < 1 && plansza[w + a][k + b] < 1)
						{
							plansza[w - 1 + a][k - 1 + b] = 0;

						}
					}
					else if (a == 1 && b != 0)
					{
						if (plansza[w - 2 + a][k - 2 + b] < 1 && plansza[w - 2 + a][k - 1 + b] < 1 && plansza[w - 2 + a][k + b] < 1 && plansza[w - 1 + a][k - 2 + b] < 1 && plansza[w - 1 + a][k + b] < 1)
						{
							plansza[w - 1 + a][k - 1 + b] = 0;

						}
					}
					else if (a == 0 && b == 0)
					{
						if (plansza[w - 2 + a][k - 1 + b] < 1 && plansza[w - 2 + a][k + b] < 1 && plansza[w - 1 + a][k + b] < 1 && plansza[w + a][k - 1 + b] < 1 && plansza[w + a][k + b] < 1)
						{
							plansza[w - 1 + a][k - 1 + b] = 0;
						}
					}
					else if (a == 1 && b == 0)
					{
						if (plansza[w - 1 + a][k + b] < 1 && plansza[w + a][k - 1 + b] < 1 && plansza[w + a][k + b] < 1)
						{
							plansza[w - 1 + a][k - 1 + b] = 0;

						}

					}

				}
				else if (w == 9 && k == 8)
				{

					if (a == 0 && b != 2)
					{
						if (plansza[w - 2 + a][k - 2 + b] < 1 && plansza[w - 2 + a][k - 1 + b] < 1 && plansza[w - 2 + a][k + b] < 1 && plansza[w - 1 + a][k - 2 + b] < 1 && plansza[w - 1 + a][k + b] < 1 && plansza[w + a][k - 2 + b] < 1 && plansza[w + a][k - 1 + b] < 1 && plansza[w + a][k + b] < 1)
						{
							plansza[w - 1 + a][k - 1 + b] = 0;

						}
					}
					else if (a == 1 && b != 2)
					{
						if (plansza[w - 2 + a][k - 2 + b] < 1 && plansza[w - 2 + a][k - 1 + b] < 1 && plansza[w - 2 + a][k + b] < 1 && plansza[w - 1 + a][k - 2 + b] < 1 && plansza[w - 1 + a][k + b] < 1)
						{
							plansza[w - 1 + a][k - 1 + b] = 0;

						}
					}
					else if (a == 0 && b == 2)
					{
						if (plansza[w - 2 + a][k - 2 + b] < 1 && plansza[w - 2 + a][k - 1 + b] < 1 && plansza[w - 1 + a][k - 2 + b] < 1 && plansza[w + a][k - 2 + b] < 1 && plansza[w + a][k - 1 + b] < 1)
						{
							plansza[w - 1 + a][k - 1 + b] = 0;
						}
					}
					else if (a == 1 && b == 2)
					{
						if (plansza[w - 2 + a][k - 2 + b] < 1 && plansza[w - 2 + a][k - 1 + b] < 1 && plansza[w - 1 + a][k - 2 + b] < 1 && plansza[w - 1 + a][k + b] < 1)
						{
							plansza[w - 1 + a][k - 1 + b] = 0;

						}

					}
				}
				else if (k == 0 && w > 1 && w < 8)
				{
					if (b == 1)
					{
						if (plansza[w - 2 + a][k - 1 + b] < 1 && plansza[w - 2 + a][k + b] < 1 && plansza[w - 1 + a][k + b] < 1 && plansza[w + a][k - 1 + b] < 1 && plansza[w + a][k + b] < 1)
						{
							plansza[w - 1 + a][k - 1 + b] = 0;

						}

					}
					else if (b == 2)
					{
						if (plansza[w - 2 + a][k - 2 + b] < 1 && plansza[w - 2 + a][k - 1 + b] < 1 && plansza[w - 2 + a][k + b] < 1 && plansza[w - 1 + a][k - 2 + b] < 1 && plansza[w - 1 + a][k + b] < 1 && plansza[w + a][k - 2 + b] < 1 && plansza[w + a][k - 1 + b] < 1 && plansza[w + a][k + b] < 1)
						{
							plansza[w - 1 + a][k - 1 + b] = 0;

						}

					}

				}
				else if (k == 0 && w == 1)
				{

					if (a == 0 && b == 1)
					{
						plansza[w - 1 + a][k - 1 + b] = 0;
					}
					else if (b == 2 && a != 0)
					{
						if (plansza[w - 2 + a][k - 2 + b] < 1 && plansza[w - 2 + a][k - 1 + b] < 1 && plansza[w - 2 + a][k + b] < 1 && plansza[w - 1 + a][k - 2 + b] < 1 && plansza[w - 1 + a][k + b] < 1 && plansza[w + a][k - 2 + b] < 1 && plansza[w + a][k - 1 + b] < 1 && plansza[w + a][k + b] < 1)
						{
							plansza[w - 1 + a][k - 1 + b] = 0;
						}
					}
					else if (b == 2 && a == 0)
					{
						if (plansza[w - 1 + a][k - 2 + b] < 1 && plansza[w - 1 + a][k + b] < 1 && plansza[w + a][k - 2 + b] < 1 && plansza[w + a][k - 1 + b] < 1 && plansza[w + a][k + b] < 1)
						{
							plansza[w - 1 + a][k - 1 + b] = 0;
						}
					}
					else if (b == 1 && a == 2)
					{
						if (plansza[w - 2 + a][k - 1 + b] < 1 && plansza[w - 2 + a][k + b] < 1 && plansza[w - 1 + a][k + b] < 1 && plansza[w + a][k - 1 + b] < 1 && plansza[w + a][k + b] < 1)
						{
							plansza[w - 1 + a][k - 1 + b] = 0;
						}
					}
				}
				else if (k == 0 && w == 8)
				{

					if (a == 2 && b == 1)
					{
						plansza[w - 1 + a][k - 1 + b] = 0;
					}
					else if (b == 2 && a != 2)
					{
						if (plansza[w - 2 + a][k - 2 + b] < 1 && plansza[w - 2 + a][k - 1 + b] < 1 && plansza[w - 2 + a][k + b] < 1 && plansza[w - 1 + a][k - 2 + b] < 1 && plansza[w - 1 + a][k + b] < 1 && plansza[w + a][k - 2 + b] < 1 && plansza[w + a][k - 1 + b] < 1 && plansza[w + a][k + b] < 1)
						{
							plansza[w - 1 + a][k - 1 + b] = 0;
						}
					}
					else if (b == 1 && a == 0)
					{
						if (plansza[w - 2 + a][k - 1 + b] < 1 && plansza[w - 2 + a][k + b] < 1 && plansza[w - 1 + a][k + b] < 1 && plansza[w + a][k - 1 + b] < 1 && plansza[w + a][k + b] < 1)
						{
							plansza[w - 1 + a][k - 1 + b] = 0;
						}
					}
					else if (b == 2 && a == 2)
					{
						if (plansza[w - 2 + a][k - 2 + b] < 1 && plansza[w - 2 + a][k - 1 + b] < 1 && plansza[w - 2 + a][k + b] < 1 && plansza[w - 1 + a][k - 2 + b] < 1 && plansza[w - 1 + a][k + b] < 1)
						{
							plansza[w - 1 + a][k - 1 + b] = 0;
						}
					}
				}
				else if (k == 9 && w > 1 && w < 8)
				{
					if (b == 1)
					{
						if (plansza[w - 2 + a][k - 2 + b] < 1 && plansza[w - 2 + a][k - 1 + b] < 1 && plansza[w - 1 + a][k - 2 + b] < 1 && plansza[w + a][k - 2 + b] < 1 && plansza[w + a][k - 1 + b] < 1)
						{
							plansza[w - 1 + a][k - 1 + b] = 0;

						}

					}
					else if (b == 0)
					{
						if (plansza[w - 2 + a][k - 2 + b] < 1 && plansza[w - 2 + a][k - 1 + b] < 1 && plansza[w - 2 + a][k + b] < 1 && plansza[w - 1 + a][k - 2 + b] < 1 && plansza[w - 1 + a][k + b] < 1 && plansza[w + a][k - 2 + b] < 1 && plansza[w + a][k - 1 + b] < 1 && plansza[w + a][k + b] < 1)
						{
							plansza[w - 1 + a][k - 1 + b] = 0;

						}

					}
				}
				else if (k == 9 && w == 1)
				{

					if (a == 0 && b == 1)
					{
						plansza[w - 1 + a][k - 1 + b] = 0;
					}
					else if (b == 0 && a != 0)
					{
						if (plansza[w - 2 + a][k - 2 + b] < 1 && plansza[w - 2 + a][k - 1 + b] < 1 && plansza[w - 2 + a][k + b] < 1 && plansza[w - 1 + a][k - 2 + b] < 1 && plansza[w - 1 + a][k + b] < 1 && plansza[w + a][k - 2 + b] < 1 && plansza[w + a][k - 1 + b] < 1 && plansza[w + a][k + b] < 1)
						{
							plansza[w - 1 + a][k - 1 + b] = 0;
						}
					}
					else if (b == 0 && a == 0)
					{
						if (plansza[w - 1 + a][k - 2 + b] < 1 && plansza[w - 1 + a][k + b] < 1 && plansza[w + a][k - 2 + b] < 1 && plansza[w + a][k - 1 + b] < 1 && plansza[w + a][k + b] < 1)
						{
							plansza[w - 1 + a][k - 1 + b] = 0;
						}
					}
					else if (b == 1 && a == 2)
					{
						if (plansza[w - 2 + a][k - 2 + b] < 1 && plansza[w - 2 + a][k - 1 + b] < 1 && plansza[w - 1 + a][k - 2 + b] < 1 && plansza[w + a][k - 2 + b] < 1 && plansza[w + a][k - 1 + b] < 1)
						{
							plansza[w - 1 + a][k - 1 + b] = 0;
						}
					}
				}
				else if (k == 9 && w == 8)
				{
					// plansza[w - 2 + a][k - 2 + b] < 1 && plansza[w - 2 + a][k - 1 + b] < 1 && plansza[w - 2 + a][k + b] < 1 && plansza[w - 1 + a][k - 2 + b] < 1 && plansza[w - 1 + a][k + b] < 1 && plansza[w + a][k - 2 + b] < 1 && plansza[w + a][k - 1 + b] < 1 && plansza[w + a][k + b] < 1
					if (a == 2 && b == 1)
					{
						plansza[w - 1 + a][k - 1 + b] = 0;
					}
					else if (b == 0 && a != 2)
					{
						if (plansza[w - 2 + a][k - 2 + b] < 1 && plansza[w - 2 + a][k - 1 + b] < 1 && plansza[w - 2 + a][k + b] < 1 && plansza[w - 1 + a][k - 2 + b] < 1 && plansza[w - 1 + a][k + b] < 1 && plansza[w + a][k - 2 + b] < 1 && plansza[w + a][k - 1 + b] < 1 && plansza[w + a][k + b] < 1)
						{
							plansza[w - 1 + a][k - 1 + b] = 0;
						}
					}
					else if (b == 1 && a == 0)
					{
						if (plansza[w - 2 + a][k - 2 + b] < 1 && plansza[w - 2 + a][k - 1 + b] < 1 && plansza[w - 1 + a][k - 2 + b] < 1 && plansza[w + a][k - 2 + b] < 1 && plansza[w + a][k - 1 + b] < 1)
						{
							plansza[w - 1 + a][k - 1 + b] = 0;
						}
					}
					else if (b == 0 && a == 2)
					{
						if (plansza[w - 2 + a][k - 2 + b] < 1 && plansza[w - 2 + a][k - 1 + b] < 1 && plansza[w - 2 + a][k + b] < 1 && plansza[w - 1 + a][k - 2 + b] < 1 && plansza[w - 1 + a][k + b] < 1)
						{
							plansza[w - 1 + a][k - 1 + b] = 0;
						}
					}

				}
			}
			else if (w == 0 && k == 0)
			{
				if (a == 1 && b == 2)
				{
					if (plansza[w - 1 + a][k - 2 + b] < 1 && plansza[w - 1 + a][k + b] < 1 && plansza[w + a][k - 2 + b] < 1 && plansza[w + a][k - 1 + b] < 1 && plansza[w + a][k + b] < 1)
					{
						plansza[w - 1 + a][k - 1 + b] = 0;
					}
				}
				else if (b == 2 && a == 2)
				{
					if (plansza[w - 2 + a][k - 2 + b] < 1 && plansza[w - 2 + a][k - 1 + b] < 1 && plansza[w - 2 + a][k + b] < 1 && plansza[w - 1 + a][k - 2 + b] < 1 && plansza[w - 1 + a][k + b] < 1 && plansza[w + a][k - 2 + b] < 1 && plansza[w + a][k - 1 + b] < 1 && plansza[w + a][k + b] < 1)
					{
						plansza[w - 1 + a][k - 1 + b] = 0;
					}
				}
				else if (b == 1 && a == 2)
				{
					if (plansza[w - 2 + a][k - 1 + b] < 1 && plansza[w - 2 + a][k + b] < 1 && plansza[w - 1 + a][k + b] < 1 && plansza[w + a][k - 1 + b] < 1 && plansza[w + a][k + b] < 1)
					{
						plansza[w - 1 + a][k - 1 + b] = 0;
					}
				}


			}
			else if (w == 0 && k == 9)
			{
				if (b == 0 && a == 2)
				{
					if (plansza[w - 2 + a][k - 2 + b] < 1 && plansza[w - 2 + a][k - 1 + b] < 1 && plansza[w - 2 + a][k + b] < 1 && plansza[w - 1 + a][k - 2 + b] < 1 && plansza[w - 1 + a][k + b] < 1 && plansza[w + a][k - 2 + b] < 1 && plansza[w + a][k - 1 + b] < 1 && plansza[w + a][k + b] < 1)
					{
						plansza[w - 1 + a][k - 1 + b] = 0;
					}
				}
				else if (a == 1 && b == 0)
				{
					if (plansza[w - 1 + a][k - 2 + b] < 1 && plansza[w - 1 + a][k + b] < 1 && plansza[w + a][k - 2 + b] < 1 && plansza[w + a][k - 1 + b] < 1 && plansza[w + a][k + b] < 1)
					{
						plansza[w - 1 + a][k - 1 + b] = 0;
					}
				}
				else if (b == 1 && a == 2)
				{
					if (plansza[w - 2 + a][k - 2 + b] < 1 && plansza[w - 2 + a][k - 1 + b] < 1 && plansza[w - 1 + a][k - 2 + b] < 1 && plansza[w + a][k - 2 + b] < 1 && plansza[w + a][k - 1 + b] < 1)
					{
						plansza[w - 1 + a][k - 1 + b] = 0;
					}
				}

			}
			else if (w == 9 && k == 0)
			{
				if (b == 2 && a == 0)
				{
					if (plansza[w - 2 + a][k - 2 + b] < 1 && plansza[w - 2 + a][k - 1 + b] < 1 && plansza[w - 2 + a][k + b] < 1 && plansza[w - 1 + a][k - 2 + b] < 1 && plansza[w - 1 + a][k + b] < 1 && plansza[w + a][k - 2 + b] < 1 && plansza[w + a][k - 1 + b] < 1 && plansza[w + a][k + b] < 1)
					{
						plansza[w - 1 + a][k - 1 + b] = 0;
					}
				}
				else if (b == 1 && a == 0)
				{
					if (plansza[w - 2 + a][k - 1 + b] < 1 && plansza[w - 2 + a][k + b] < 1 && plansza[w - 1 + a][k + b] < 1 && plansza[w + a][k - 1 + b] < 1 && plansza[w + a][k + b] < 1)
					{
						plansza[w - 1 + a][k - 1 + b] = 0;
					}
				}
				else if (b == 2 && a == 1)
				{
					if (plansza[w - 2 + a][k - 2 + b] < 1 && plansza[w - 2 + a][k - 1 + b] < 1 && plansza[w - 2 + a][k + b] < 1 && plansza[w - 1 + a][k - 2 + b] < 1 && plansza[w - 1 + a][k + b] < 1)
					{
						plansza[w - 1 + a][k - 1 + b] = 0;
					}
				}



			}
			else if (w == 9 && k == 9)
			{
				if (b == 0 && a == 0)
				{
					if (plansza[w - 2 + a][k - 2 + b] < 1 && plansza[w - 2 + a][k - 1 + b] < 1 && plansza[w - 2 + a][k + b] < 1 && plansza[w - 1 + a][k - 2 + b] < 1 && plansza[w - 1 + a][k + b] < 1 && plansza[w + a][k - 2 + b] < 1 && plansza[w + a][k - 1 + b] < 1 && plansza[w + a][k + b] < 1)
					{
						plansza[w - 1 + a][k - 1 + b] = 0;
					}
				}
				else if (a == 1 && b == 0)
				{
					if (plansza[w - 2 + a][k - 2 + b] < 1 && plansza[w - 2 + a][k - 1 + b] < 1 && plansza[w - 2 + a][k + b] < 1 && plansza[w - 1 + a][k - 2 + b] < 1 && plansza[w - 1 + a][k + b] < 1)
					{
						plansza[w - 1 + a][k - 1 + b] = 0;
					}
				}
				else if (b == 1 && a == 0)
				{
					if (plansza[w - 2 + a][k - 2 + b] < 1 && plansza[w - 2 + a][k - 1 + b] < 1 && plansza[w - 1 + a][k - 2 + b] < 1 && plansza[w + a][k - 2 + b] < 1 && plansza[w + a][k - 1 + b] < 1)
					{
						plansza[w - 1 + a][k - 1 + b] = 0;
					}
				}


			}




		}


	}
}

void uloz_plansze(int plansza[10][10])
{

	for (int c = 0; c <= 9; c++)
	{
		for (int d = 0; d <= 9; d++)
		{
			plansza[c][d] = 0;
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

		if (kierunek == 0 && wiersz - 3 >= 0 && plansza[wiersz][kolumna] == 0 && plansza[wiersz - 1][kolumna] == 0 && plansza[wiersz - 2][kolumna] == 0 && plansza[wiersz - 3][kolumna] == 0)
		{
			for (int i = 0; i < 4; i++)
				plansza[wiersz - i][kolumna] = 4;

			for (int a = 0; a < 3; a++)
			{
				for (int b = 0; b < 6; b++)
				{
					if (kolumna - 1 + a >= 0 && kolumna - 1 + a <= 9 && wiersz + 1 - b >= 0 && wiersz + 1 - b <= 9 && plansza[wiersz + 1 - b][kolumna - 1 + a] == 0)
						plansza[wiersz + 1 - b][kolumna - 1 + a] = -1;
				}


			}
		}
		if (kierunek == 1 && wiersz + 3 <= 9 && plansza[wiersz][kolumna] == 0 && plansza[wiersz + 1][kolumna] == 0 && plansza[wiersz + 2][kolumna] == 0 && plansza[wiersz + 3][kolumna] == 0)
		{
			for (int i = 0; i < 4; i++)
				plansza[wiersz + i][kolumna] = 4;

			for (int a = 0; a < 3; a++)
			{
				for (int b = 0; b < 6; b++)
				{
					if (kolumna - 1 + a >= 0 && kolumna - 1 + a <= 9 && wiersz - 1 + b >= 0 && wiersz - 1 + b <= 9 && plansza[wiersz - 1 + b][kolumna - 1 + a] == 0)
						plansza[wiersz - 1 + b][kolumna - 1 + a] = -1;
				}


			}
		}
		if (kierunek == 2 && kolumna + 3 <= 9 && plansza[wiersz][kolumna] == 0 && plansza[wiersz][kolumna + 1] == 0 && plansza[wiersz][kolumna + 2] == 0 && plansza[wiersz][kolumna + 3] == 0)
		{
			for (int i = 0; i < 4; i++)
				plansza[wiersz][kolumna + i] = 4;

			for (int a = 0; a < 3; a++)
			{
				for (int b = 0; b < 6; b++)
				{
					if (wiersz - 1 + a >= 0 && wiersz - 1 + a <= 9 && kolumna - 1 + b >= 0 && kolumna - 1 + b <= 9 && plansza[wiersz - 1 + a][kolumna - 1 + b] == 0)
						plansza[wiersz - 1 + a][kolumna - 1 + b] = -1;
				}


			}
		}
		if (kierunek == 3 && kolumna - 3 >= 0 && plansza[wiersz][kolumna] == 0 && plansza[wiersz][kolumna - 1] == 0 && plansza[wiersz][kolumna - 2] == 0 && plansza[wiersz][kolumna - 3] == 0)
		{
			for (int i = 0; i < 4; i++)
				plansza[wiersz][kolumna - i] = 4;

			for (int a = 0; a < 3; a++)
			{
				for (int b = 0; b < 6; b++)
				{
					if (wiersz - 1 + a >= 0 && wiersz - 1 + a <= 9 && kolumna + 1 - b >= 0 && kolumna + 1 - b <= 9 && plansza[wiersz - 1 + a][kolumna + 1 - b] == 0)
						plansza[wiersz - 1 + a][kolumna + 1 - b] = -1;
				}


			}
		}

	} while (plansza[wiersz][kolumna] != 4);

	do
	{
		wiersz = wierszL(generator);
		kolumna = kolumnaL(generator);
		kierunek = kierunekL(generator);

		// 0 - góra, 1 - dó³, 2 - prawo, 3 - lewo

		if (kierunek == 0 && wiersz - 2 >= 0 && plansza[wiersz][kolumna] == 0 && plansza[wiersz - 1][kolumna] == 0 && plansza[wiersz - 2][kolumna] == 0)
		{
			for (int i = 0; i < 3; i++)
				plansza[wiersz - i][kolumna] = 3;

			for (int a = 0; a < 3; a++)
			{
				for (int b = 0; b < 5; b++)
				{
					if (kolumna - 1 + a >= 0 && kolumna - 1 + a <= 9 && wiersz + 1 - b >= 0 && wiersz + 1 - b <= 9 && plansza[wiersz + 1 - b][kolumna - 1 + a] == 0)
						plansza[wiersz + 1 - b][kolumna - 1 + a] = -1;
				}


			}
		}
		if (kierunek == 1 && wiersz + 2 <= 9 && plansza[wiersz][kolumna] == 0 && plansza[wiersz + 1][kolumna] == 0 && plansza[wiersz + 2][kolumna] == 0)
		{
			for (int i = 0; i < 3; i++)
				plansza[wiersz + i][kolumna] = 3;

			for (int a = 0; a < 3; a++)
			{
				for (int b = 0; b < 5; b++)
				{
					if (kolumna - 1 + a >= 0 && kolumna - 1 + a <= 9 && wiersz - 1 + b >= 0 && wiersz - 1 + b <= 9 && plansza[wiersz - 1 + b][kolumna - 1 + a] == 0)
						plansza[wiersz - 1 + b][kolumna - 1 + a] = -1;
				}


			}
		}
		if (kierunek == 2 && kolumna + 2 <= 9 && plansza[wiersz][kolumna] == 0 && plansza[wiersz][kolumna + 1] == 0 && plansza[wiersz][kolumna + 2] == 0)
		{
			for (int i = 0; i < 3; i++)
				plansza[wiersz][kolumna + i] = 3;

			for (int a = 0; a < 3; a++)
			{
				for (int b = 0; b < 5; b++)
				{
					if (wiersz - 1 + a >= 0 && wiersz - 1 + a <= 9 && kolumna - 1 + b >= 0 && kolumna - 1 + b <= 9 && plansza[wiersz - 1 + a][kolumna - 1 + b] == 0)
						plansza[wiersz - 1 + a][kolumna - 1 + b] = -1;
				}


			}
		}
		if (kierunek == 3 && kolumna - 2 >= 0 && plansza[wiersz][kolumna] == 0 && plansza[wiersz][kolumna - 1] == 0 && plansza[wiersz][kolumna - 2] == 0)
		{
			for (int i = 0; i < 3; i++)
				plansza[wiersz][kolumna - i] = 3;

			for (int a = 0; a < 3; a++)
			{
				for (int b = 0; b < 5; b++)
				{
					if (wiersz - 1 + a >= 0 && wiersz - 1 + a <= 9 && kolumna + 1 - b >= 0 && kolumna + 1 - b <= 9 && plansza[wiersz - 1 + a][kolumna + 1 - b] == 0)
						plansza[wiersz - 1 + a][kolumna + 1 - b] = -1;
				}


			}
		}

	} while (plansza[wiersz][kolumna] != 3);

	do
	{
		wiersz = wierszL(generator);
		kolumna = kolumnaL(generator);
		kierunek = kierunekL(generator);

		// 0 - góra, 1 - dó³, 2 - prawo, 3 - lewo

		if (kierunek == 0 && wiersz - 2 >= 0 && plansza[wiersz][kolumna] == 0 && plansza[wiersz - 1][kolumna] == 0 && plansza[wiersz - 2][kolumna] == 0)
		{
			for (int i = 0; i < 3; i++)
				plansza[wiersz - i][kolumna] = 3;

			for (int a = 0; a < 3; a++)
			{
				for (int b = 0; b < 5; b++)
				{
					if (kolumna - 1 + a >= 0 && kolumna - 1 + a <= 9 && wiersz + 1 - b >= 0 && wiersz + 1 - b <= 9 && plansza[wiersz + 1 - b][kolumna - 1 + a] == 0)
						plansza[wiersz + 1 - b][kolumna - 1 + a] = -1;
				}


			}
		}
		if (kierunek == 1 && wiersz + 2 <= 9 && plansza[wiersz][kolumna] == 0 && plansza[wiersz + 1][kolumna] == 0 && plansza[wiersz + 2][kolumna] == 0)
		{
			for (int i = 0; i < 3; i++)
				plansza[wiersz + i][kolumna] = 3;

			for (int a = 0; a < 3; a++)
			{
				for (int b = 0; b < 5; b++)
				{
					if (kolumna - 1 + a >= 0 && kolumna - 1 + a <= 9 && wiersz - 1 + b >= 0 && wiersz - 1 + b <= 9 && plansza[wiersz - 1 + b][kolumna - 1 + a] == 0)
						plansza[wiersz - 1 + b][kolumna - 1 + a] = -1;
				}


			}
		}
		if (kierunek == 2 && kolumna + 2 <= 9 && plansza[wiersz][kolumna] == 0 && plansza[wiersz][kolumna + 1] == 0 && plansza[wiersz][kolumna + 2] == 0)
		{
			for (int i = 0; i < 3; i++)
				plansza[wiersz][kolumna + i] = 3;

			for (int a = 0; a < 3; a++)
			{
				for (int b = 0; b < 5; b++)
				{
					if (wiersz - 1 + a >= 0 && wiersz - 1 + a <= 9 && kolumna - 1 + b >= 0 && kolumna - 1 + b <= 9 && plansza[wiersz - 1 + a][kolumna - 1 + b] == 0)
						plansza[wiersz - 1 + a][kolumna - 1 + b] = -1;
				}


			}
		}
		if (kierunek == 3 && kolumna - 2 >= 0 && plansza[wiersz][kolumna] == 0 && plansza[wiersz][kolumna - 1] == 0 && plansza[wiersz][kolumna - 2] == 0)
		{
			for (int i = 0; i < 3; i++)
				plansza[wiersz][kolumna - i] = 3;

			for (int a = 0; a < 3; a++)
			{
				for (int b = 0; b < 5; b++)
				{
					if (wiersz - 1 + a >= 0 && wiersz - 1 + a <= 9 && kolumna + 1 - b >= 0 && kolumna + 1 - b <= 9 && plansza[wiersz - 1 + a][kolumna + 1 - b] == 0)
						plansza[wiersz - 1 + a][kolumna + 1 - b] = -1;
				}


			}
		}

	} while (plansza[wiersz][kolumna] != 3);

	do
	{
		wiersz = wierszL(generator);
		kolumna = kolumnaL(generator);
		kierunek = kierunekL(generator);

		// 0 - góra, 1 - dó³, 2 - prawo, 3 - lewo

		if (kierunek == 0 && wiersz - 1 >= 0 && plansza[wiersz][kolumna] == 0 && plansza[wiersz - 1][kolumna] == 0)
		{
			for (int i = 0; i < 2; i++)
				plansza[wiersz - i][kolumna] = 2;

			for (int a = 0; a < 3; a++)
			{
				for (int b = 0; b < 4; b++)
				{
					if (kolumna - 1 + a >= 0 && kolumna - 1 + a <= 9 && wiersz + 1 - b >= 0 && wiersz + 1 - b <= 9 && plansza[wiersz + 1 - b][kolumna - 1 + a] == 0)
						plansza[wiersz + 1 - b][kolumna - 1 + a] = -1;
				}


			}
		}
		if (kierunek == 1 && wiersz + 1 <= 9 && plansza[wiersz][kolumna] == 0 && plansza[wiersz + 1][kolumna] == 0)
		{
			for (int i = 0; i < 2; i++)
				plansza[wiersz + i][kolumna] = 2;

			for (int a = 0; a < 3; a++)
			{
				for (int b = 0; b < 4; b++)
				{
					if (kolumna - 1 + a >= 0 && kolumna - 1 + a <= 9 && wiersz - 1 + b >= 0 && wiersz - 1 + b <= 9 && plansza[wiersz - 1 + b][kolumna - 1 + a] == 0)
						plansza[wiersz - 1 + b][kolumna - 1 + a] = -1;
				}


			}
		}
		if (kierunek == 2 && kolumna + 1 <= 9 && plansza[wiersz][kolumna] == 0 && plansza[wiersz][kolumna + 1] == 0)
		{
			for (int i = 0; i < 2; i++)
				plansza[wiersz][kolumna + i] = 2;

			for (int a = 0; a < 3; a++)
			{
				for (int b = 0; b < 4; b++)
				{
					if (wiersz - 1 + a >= 0 && wiersz - 1 + a <= 9 && kolumna - 1 + b >= 0 && kolumna - 1 + b <= 9 && plansza[wiersz - 1 + a][kolumna - 1 + b] == 0)
						plansza[wiersz - 1 + a][kolumna - 1 + b] = -1;
				}


			}
		}
		if (kierunek == 3 && kolumna - 1 >= 0 && plansza[wiersz][kolumna] == 0 && plansza[wiersz][kolumna - 1] == 0)
		{
			for (int i = 0; i < 2; i++)
				plansza[wiersz][kolumna - i] = 2;

			for (int a = 0; a < 3; a++)
			{
				for (int b = 0; b < 4; b++)
				{
					if (wiersz - 1 + a >= 0 && wiersz - 1 + a <= 9 && kolumna + 1 - b >= 0 && kolumna + 1 - b <= 9 && plansza[wiersz - 1 + a][kolumna + 1 - b] == 0)
						plansza[wiersz - 1 + a][kolumna + 1 - b] = -1;
				}


			}
		}

	} while (plansza[wiersz][kolumna] != 2);

	do
	{
		wiersz = wierszL(generator);
		kolumna = kolumnaL(generator);
		kierunek = kierunekL(generator);

		// 0 - góra, 1 - dó³, 2 - prawo, 3 - lewo

		if (kierunek == 0 && wiersz - 1 >= 0 && plansza[wiersz][kolumna] == 0 && plansza[wiersz - 1][kolumna] == 0)
		{
			for (int i = 0; i < 2; i++)
				plansza[wiersz - i][kolumna] = 2;

			for (int a = 0; a < 3; a++)
			{
				for (int b = 0; b < 4; b++)
				{
					if (kolumna - 1 + a >= 0 && kolumna - 1 + a <= 9 && wiersz + 1 - b >= 0 && wiersz + 1 - b <= 9 && plansza[wiersz + 1 - b][kolumna - 1 + a] == 0)
						plansza[wiersz + 1 - b][kolumna - 1 + a] = -1;
				}


			}
		}
		if (kierunek == 1 && wiersz + 1 <= 9 && plansza[wiersz][kolumna] == 0 && plansza[wiersz + 1][kolumna] == 0)
		{
			for (int i = 0; i < 2; i++)
				plansza[wiersz + i][kolumna] = 2;

			for (int a = 0; a < 3; a++)
			{
				for (int b = 0; b < 4; b++)
				{
					if (kolumna - 1 + a >= 0 && kolumna - 1 + a <= 9 && wiersz - 1 + b >= 0 && wiersz - 1 + b <= 9 && plansza[wiersz - 1 + b][kolumna - 1 + a] == 0)
						plansza[wiersz - 1 + b][kolumna - 1 + a] = -1;
				}


			}
		}
		if (kierunek == 2 && kolumna + 1 <= 9 && plansza[wiersz][kolumna] == 0 && plansza[wiersz][kolumna + 1] == 0)
		{
			for (int i = 0; i < 2; i++)
				plansza[wiersz][kolumna + i] = 2;

			for (int a = 0; a < 3; a++)
			{
				for (int b = 0; b < 4; b++)
				{
					if (wiersz - 1 + a >= 0 && wiersz - 1 + a <= 9 && kolumna - 1 + b >= 0 && kolumna - 1 + b <= 9 && plansza[wiersz - 1 + a][kolumna - 1 + b] == 0)
						plansza[wiersz - 1 + a][kolumna - 1 + b] = -1;
				}


			}
		}
		if (kierunek == 3 && kolumna - 1 >= 0 && plansza[wiersz][kolumna] == 0 && plansza[wiersz][kolumna - 1] == 0)
		{
			for (int i = 0; i < 2; i++)
				plansza[wiersz][kolumna - i] = 2;

			for (int a = 0; a < 3; a++)
			{
				for (int b = 0; b < 4; b++)
				{
					if (wiersz - 1 + a >= 0 && wiersz - 1 + a <= 9 && kolumna + 1 - b >= 0 && kolumna + 1 - b <= 9 && plansza[wiersz - 1 + a][kolumna + 1 - b] == 0)
						plansza[wiersz - 1 + a][kolumna + 1 - b] = -1;
				}


			}
		}

	} while (plansza[wiersz][kolumna] != 2);

	do
	{
		wiersz = wierszL(generator);
		kolumna = kolumnaL(generator);
		kierunek = kierunekL(generator);

		// 0 - góra, 1 - dó³, 2 - prawo, 3 - lewo

		if (kierunek == 0 && wiersz - 1 >= 0 && plansza[wiersz][kolumna] == 0 && plansza[wiersz - 1][kolumna] == 0)
		{
			for (int i = 0; i < 2; i++)
				plansza[wiersz - i][kolumna] = 2;

			for (int a = 0; a < 3; a++)
			{
				for (int b = 0; b < 4; b++)
				{
					if (kolumna - 1 + a >= 0 && kolumna - 1 + a <= 9 && wiersz + 1 - b >= 0 && wiersz + 1 - b <= 9 && plansza[wiersz + 1 - b][kolumna - 1 + a] == 0)
						plansza[wiersz + 1 - b][kolumna - 1 + a] = -1;
				}


			}
		}
		if (kierunek == 1 && wiersz + 1 <= 9 && plansza[wiersz][kolumna] == 0 && plansza[wiersz + 1][kolumna] == 0)
		{
			for (int i = 0; i < 2; i++)
				plansza[wiersz + i][kolumna] = 2;

			for (int a = 0; a < 3; a++)
			{
				for (int b = 0; b < 4; b++)
				{
					if (kolumna - 1 + a >= 0 && kolumna - 1 + a <= 9 && wiersz - 1 + b >= 0 && wiersz - 1 + b <= 9 && plansza[wiersz - 1 + b][kolumna - 1 + a] == 0)
						plansza[wiersz - 1 + b][kolumna - 1 + a] = -1;
				}


			}
		}
		if (kierunek == 2 && kolumna + 1 <= 9 && plansza[wiersz][kolumna] == 0 && plansza[wiersz][kolumna + 1] == 0)
		{
			for (int i = 0; i < 2; i++)
				plansza[wiersz][kolumna + i] = 2;

			for (int a = 0; a < 3; a++)
			{
				for (int b = 0; b < 4; b++)
				{
					if (wiersz - 1 + a >= 0 && wiersz - 1 + a <= 9 && kolumna - 1 + b >= 0 && kolumna - 1 + b <= 9 && plansza[wiersz - 1 + a][kolumna - 1 + b] == 0)
						plansza[wiersz - 1 + a][kolumna - 1 + b] = -1;
				}


			}
		}
		if (kierunek == 3 && kolumna - 1 >= 0 && plansza[wiersz][kolumna] == 0 && plansza[wiersz][kolumna - 1] == 0)
		{
			for (int i = 0; i < 2; i++)
				plansza[wiersz][kolumna - i] = 2;

			for (int a = 0; a < 3; a++)
			{
				for (int b = 0; b < 4; b++)
				{
					if (wiersz - 1 + a >= 0 && wiersz - 1 + a <= 9 && kolumna + 1 - b >= 0 && kolumna + 1 - b <= 9 && plansza[wiersz - 1 + a][kolumna + 1 - b] == 0)
						plansza[wiersz - 1 + a][kolumna + 1 - b] = -1;
				}


			}
		}

	} while (plansza[wiersz][kolumna] != 2);


	do
	{
		wiersz = wierszL(generator);
		kolumna = kolumnaL(generator);

		if (plansza[wiersz][kolumna] == 0)
		{
			plansza[wiersz][kolumna] = 1;

			for (int a = 0; a < 3; a++)
			{
				for (int b = 0; b < 3; b++)
				{
					if (kolumna - 1 + a >= 0 && kolumna - 1 + a <= 9 && wiersz + 1 - b >= 0 && wiersz + 1 - b <= 9 && plansza[wiersz + 1 - b][kolumna - 1 + a] == 0)
						plansza[wiersz + 1 - b][kolumna - 1 + a] = -1;
				}


			}
		}

	} while (plansza[wiersz][kolumna] != 1);

	do
	{
		wiersz = wierszL(generator);
		kolumna = kolumnaL(generator);

		if (plansza[wiersz][kolumna] == 0)
		{
			plansza[wiersz][kolumna] = 1;

			for (int a = 0; a < 3; a++)
			{
				for (int b = 0; b < 3; b++)
				{
					if (kolumna - 1 + a >= 0 && kolumna - 1 + a <= 9 && wiersz + 1 - b >= 0 && wiersz + 1 - b <= 9 && plansza[wiersz + 1 - b][kolumna - 1 + a] == 0)
						plansza[wiersz + 1 - b][kolumna - 1 + a] = -1;
				}


			}
		}

	} while (plansza[wiersz][kolumna] != 1);

	do
	{
		wiersz = wierszL(generator);
		kolumna = kolumnaL(generator);

		if (plansza[wiersz][kolumna] == 0)
		{
			plansza[wiersz][kolumna] = 1;

			for (int a = 0; a < 3; a++)
			{
				for (int b = 0; b < 3; b++)
				{
					if (kolumna - 1 + a >= 0 && kolumna - 1 + a <= 9 && wiersz + 1 - b >= 0 && wiersz + 1 - b <= 9 && plansza[wiersz + 1 - b][kolumna - 1 + a] == 0)
						plansza[wiersz + 1 - b][kolumna - 1 + a] = -1;
				}


			}
		}

	} while (plansza[wiersz][kolumna] != 1);

	do
	{
		wiersz = wierszL(generator);
		kolumna = kolumnaL(generator);

		if (plansza[wiersz][kolumna] == 0)
		{
			plansza[wiersz][kolumna] = 1;

			for (int a = 0; a < 3; a++)
			{
				for (int b = 0; b < 3; b++)
				{
					if (kolumna - 1 + a >= 0 && kolumna - 1 + a <= 9 && wiersz + 1 - b >= 0 && wiersz + 1 - b <= 9 && plansza[wiersz + 1 - b][kolumna - 1 + a] == 0)
						plansza[wiersz + 1 - b][kolumna - 1 + a] = -1;
				}


			}
		}

	} while (plansza[wiersz][kolumna] != 1);

}

void spacje(int ilosc)
{
	for (int a = 0; a < ilosc; a++)
		cout << " ";
}

void komputer()
{
	unsigned char LG = 201;
	unsigned char poziom = 205;
	unsigned char pion = 186;
	unsigned char LD = 200;
	unsigned char PG = 187;
	unsigned char PD = 188;


	cout << endl << endl;
	spacje(54);
	cout << LG << poziom << poziom << poziom << poziom << poziom << poziom << poziom << poziom << poziom << poziom << poziom << poziom << poziom << poziom << poziom << poziom << PG << endl;
	spacje(54);
	cout << pion;
	spacje(16);
	cout << pion << endl;
	spacje(54);
	cout << pion;
	cout << "    -      -    " << pion << endl;
	spacje(54);
	cout << pion;
	spacje(16);
	cout << pion << endl;
	spacje(54);
	cout << pion;
	spacje(16);
	cout << pion << endl;
	spacje(54);
	cout << pion;
	spacje(16);
	cout << pion << endl;
	spacje(54);
	cout << pion << "    ________    ";
	cout << pion << endl;
	spacje(54);
	cout << pion;
	spacje(16);
	cout << pion << endl;
	spacje(54);
	cout << LD << poziom << poziom << poziom << poziom << poziom << poziom << poziom << poziom << poziom << poziom << poziom << poziom << poziom << poziom << poziom << poziom << PD << endl << endl;
	Sleep(1000);



}

void sprawdzCin(bool prawda)
{
	HANDLE hOut;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	if (prawda == 0)
	{
		cin.clear();
		cin.ignore(100, '\n');										// Sprawdzanie poprawnosci wpisanych danych
		SetConsoleTextAttribute(hOut, FOREGROUND_RED);
		cout << endl << "Dokonales zlego wyboru! Nie przechodz na ciemna strone mocy i wybierz wlasciwa cyfre!";
		SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
		Sleep(2000);

	}

}

void kropki(int plansza[10][10])
{
	HANDLE hOut;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
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
			{
				cout.width(4);
				if (plansza[i][j] == 0 || plansza[i][j] == -1)
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
			else
			{
				cout.width(5);
				if (plansza[i][j] == 0 || plansza[i][j] == -1)
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

		}
		cout << endl << endl;

	}
}

void recznieUloz(int plansza[10][10], bool zacznij_gre)
{
	HANDLE hOut;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	unsigned char kratka = 254;
	bool jedynka1_1 = false;
	bool jedynka2_1 = false;
	bool jedynka3_1 = false;
	bool jedynka4_1 = false;
	bool dwojka1_1 = false;
	bool dwojka2_1 = false;
	bool dwojka3_1 = false;
	bool trojka1_1 = false;
	bool trojka2_1 = false;
	bool czworka1_1 = false;

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
			plansza[i][j] = 0;
	}
	string czyGotowy1{};
	int statek1{};
	int wiersz1{};
	int kolumna1{};
	char kolumna{};
	int kierunek1{};
	bool statek = false;


	while (czyGotowy1 != "OK" && czyGotowy1 != "ok" && czyGotowy1 != "oK" && czyGotowy1 != "Ok" && czyGotowy1 != "POWROT" && czyGotowy1 != "Powrot" && czyGotowy1 != "powrot")
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
					if (plansza[i][j] == 0)
					{
						SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
						cout << ".";
					}
					else if (plansza[i][j] == -1)
					{
						SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
						cout << "o";
					}
					else
					{
						SetConsoleTextAttribute(hOut, FOREGROUND_RED);
						cout << kratka;
					}
				}
				else
				{
					cout.width(5);
					if (plansza[i][j] == 0)
					{
						SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
						cout << ".";
					}
					else if (plansza[i][j] == -1)
					{
						SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
						cout << "o";
					}
					else
					{
						SetConsoleTextAttribute(hOut, FOREGROUND_RED);
						cout << kratka;
					}
				}

			}
			if (i == 1)
			{
				spacje(20);

				if (jedynka1_1 == false)
				{
					SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
					cout << kratka << "   ";
				}

				if (jedynka2_1 == false)
				{
					SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
					cout << kratka << "   ";
				}

				if (jedynka3_1 == false)
				{
					SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
					cout << kratka << "   ";
				}

				if (jedynka4_1 == false)
				{
					SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
					cout << kratka;
				}
			}
			if (i == 3)
			{
				spacje(20);

				if (dwojka1_1 == false)
				{
					SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
					cout << kratka << kratka << "   ";
				}

				if (dwojka2_1 == false)
				{
					SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
					cout << kratka << kratka << "   ";
				}

				if (dwojka3_1 == false)
				{
					SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
					cout << kratka << kratka << "   ";
				}
			}
			if (i == 5)
			{
				spacje(20);

				if (trojka1_1 == false)
				{
					SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
					cout << kratka << kratka << kratka << "   ";
				}

				if (trojka2_1 == false)
				{
					SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
					cout << kratka << kratka << kratka << "   ";
				}
			}
			if (i == 7)
			{
				spacje(20);

				if (czworka1_1 == false)
				{
					SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
					cout << kratka << kratka << kratka << kratka << "   ";
				}
			}
			cout << endl << endl;

		}
		SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
		cout << "Podaj dlugosc statku: ";
		bool poprawne = false;
		cin >> czyGotowy1;
		if (czyGotowy1 != "OK" && czyGotowy1 != "ok" && czyGotowy1 != "oK" && czyGotowy1 != "Ok" && czyGotowy1 != "POWROT" && czyGotowy1 != "Powrot" && czyGotowy1 != "powrot")
		{
			while (poprawne == false)
			{
				if (!(czyGotowy1.compare("1")) || !(czyGotowy1.compare("2")) || !(czyGotowy1.compare("3")) || !(czyGotowy1.compare("4")))
				{
					statek1 = stoi(czyGotowy1);
					poprawne = true;
				}
				else
				{
					SetConsoleTextAttribute(hOut, FOREGROUND_RED);
					cout << "Podano zle dane";
					Sleep(3000);
					SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
					cout << endl << "Podaj dlugosc statku: ";
					cin >> czyGotowy1;

				}
			}




			cout << "Podaj kolumne (A-J) oraz wiersz (1-10): ";
			cin >> kolumna;
			cin >> wiersz1;
			if (wiersz1 != 0 && kolumna != 0 && statek1 != 1)
			{
				cout << "Podaj kierunek (1 - w gore, 2 - w prawo, 3 - w dol, 4 - w lewo): ";
				cin >> kierunek1;
				if (kierunek1 != 1 && kierunek1 != 2 && kierunek1 != 3 && kierunek1 != 4)
				{
					SetConsoleTextAttribute(hOut, FOREGROUND_RED);
					cout << "Podano zly kierunek.";
					Sleep(3000);
					continue;
				}
			}



			wiersz1 = wiersz1 - 1;
			if (kolumna >= 65 && kolumna <= 74)
			{
				kolumna1 = static_cast<int>(kolumna);
				kolumna1 = kolumna1 - 65;
			}
			else if (kolumna >= 97 && kolumna <= 106)
			{
				kolumna1 = static_cast<int>(kolumna);
				kolumna1 = kolumna1 - 97;
			}
			else
			{
				kolumna1 = -1;
			}

			if (wiersz1 >= -1 && wiersz1 < 10 && kolumna1 >= -1 && kolumna1 < 10)
			{

				if (statek1 == 1)
				{
					if (jedynka4_1 == false && wiersz1 != -1)
					{
						if (plansza[wiersz1][kolumna1] == 0)
						{
							plansza[wiersz1][kolumna1] = 1;

							for (int a = 0; a < 3; a++)
							{
								for (int b = 0; b < 3; b++)
								{
									if (wiersz1 - 1 + a >= 0 && wiersz1 - 1 + a <= 9 && kolumna1 - 1 + b >= 0 && kolumna1 - 1 + b <= 9 && plansza[wiersz1 - 1 + a][kolumna1 - 1 + b] == 0)
										plansza[wiersz1 - 1 + a][kolumna1 - 1 + b] = -1;
								}


							}
							if (jedynka1_1 == false) jedynka1_1 = true;
							else if (jedynka1_1 == true && jedynka2_1 == false) jedynka2_1 = true;
							else if (jedynka1_1 == true && jedynka2_1 == true && jedynka3_1 == false) jedynka3_1 = true;
							else if (jedynka1_1 == true && jedynka2_1 == true && jedynka3_1 == true) jedynka4_1 = true;

						}
						else
						{
							SetConsoleTextAttribute(hOut, FOREGROUND_RED);
							cout << "Nie mozesz tutaj umiescic statku!";
							Sleep(3000);
						}


					}
					else if (jedynka4_1 == true && wiersz1 != -1)
					{
						SetConsoleTextAttribute(hOut, FOREGROUND_RED);
						cout << "Rozmiesciles juz wszystkie jednomasztowce!";
						Sleep(3000);

					}
					else if (jedynka1_1 == true && wiersz1 == -1)
					{
						int w = -1;
						int k = -1;
						for (int p = 0; p < 10; p++)
						{
							for (int q = 0; q < 10; q++)
							{
								if (plansza[p][q] == 1)
								{
									if (w == -1 && k == -1)
									{
										w = p;
										k = q;
									}
								}
							}
						}
						plansza[w][k] = 9;

						string czyDalej1 = "NIE";
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
										if (plansza[i][j] == 0)
										{
											SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
											cout << ".";
										}
										else if (plansza[i][j] == -1)
										{
											SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
											cout << "o";
										}
										else if (plansza[i][j] == 9)
										{
											SetConsoleTextAttribute(hOut, FOREGROUND_GREEN);
											cout << kratka;
										}
										else
										{
											SetConsoleTextAttribute(hOut, FOREGROUND_RED);
											cout << kratka;
										}
									}
									else
									{
										cout.width(5);
										if (plansza[i][j] == 0)
										{
											SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
											cout << ".";
										}
										else if (plansza[i][j] == -1)
										{
											SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
											cout << "o";
										}
										else if (plansza[i][j] == 9)
										{
											SetConsoleTextAttribute(hOut, FOREGROUND_GREEN);
											cout << kratka;
										}
										else
										{
											SetConsoleTextAttribute(hOut, FOREGROUND_RED);
											cout << kratka;
										}
									}

								}
								if (i == 1)
								{
									spacje(20);

									if (jedynka1_1 == false)
									{
										SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
										cout << kratka << "   ";
									}

									if (jedynka2_1 == false)
									{
										SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
										cout << kratka << "   ";
									}

									if (jedynka3_1 == false)
									{
										SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
										cout << kratka << "   ";
									}

									if (jedynka4_1 == false)
									{
										SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
										cout << kratka;
									}
								}
								if (i == 3)
								{
									spacje(20);

									if (dwojka1_1 == false)
									{
										SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
										cout << kratka << kratka << "   ";
									}

									if (dwojka2_1 == false)
									{
										SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
										cout << kratka << kratka << "   ";
									}

									if (dwojka3_1 == false)
									{
										SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
										cout << kratka << kratka << "   ";
									}
								}
								if (i == 5)
								{
									spacje(20);

									if (trojka1_1 == false)
									{
										SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
										cout << kratka << kratka << kratka << "   ";
									}

									if (trojka2_1 == false)
									{
										SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
										cout << kratka << kratka << kratka << "   ";
									}
								}
								if (i == 7)
								{
									spacje(20);

									if (czworka1_1 == false)
									{
										SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
										cout << kratka << kratka << kratka << kratka << "   ";
									}
								}
								cout << endl << endl;

							}
							SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN);
							cout << "Czy chcesz zdjac statek zaznaczony na zielono?" << endl;
							SetConsoleTextAttribute(hOut, FOREGROUND_RED);
							cout << "[TAK]";
							SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN);
							cout << " - sciaga statek" << endl;
							SetConsoleTextAttribute(hOut, FOREGROUND_RED);
							cout << "[NIE]";
							SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN);
							cout << " - przechodzi do kolejnego statku" << endl;
							SetConsoleTextAttribute(hOut, FOREGROUND_RED);
							cout << "[COFNIJ]";
							SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN);
							cout << " - wraca do ukladania statkow" << endl;
							SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN);
							cin >> czyDalej1;
							if (czyDalej1 == "TAK" || czyDalej1 == "tak" || czyDalej1 == "Tak")
							{
								plansza[w][k] = 0;
								usun(w, k, plansza);
								if (jedynka4_1 == true) jedynka4_1 = false;
								else if (jedynka3_1 == true) jedynka3_1 = false;
								else if (jedynka2_1 == true) jedynka2_1 = false;
								else if (jedynka1_1 == true) jedynka1_1 = false;
							}
							else if (czyDalej1 == "NIE" || czyDalej1 == "nie" || czyDalej1 == "Nie")
							{

								plansza[w][k] = 1;
								for (int c = 0; c < 10; c++)
								{
									for (int d = 0; d < 10; d++)
									{
										if (plansza[c][d] == 1)
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
								plansza[w][k] = 9;


							}
							else
							{
								SetConsoleTextAttribute(hOut, FOREGROUND_RED);
								cout << endl << "Podano zla odpowiedz" << endl;
								Sleep(3000);
							}

						} while (czyDalej1 == "NIE" || czyDalej1 == "nie" || czyDalej1 == "Nie");

					}
					else if (jedynka1_1 == false && wiersz1 == -1)
					{
						SetConsoleTextAttribute(hOut, FOREGROUND_RED);
						Sleep(3000);
						cout << "Nie mozesz sciagnac statku, ktory nie jest na planszy!";
					}



				}
				else if (statek1 == 2)
				{
					if (dwojka3_1 == false && wiersz1 != -1)
					{
						if (plansza[wiersz1][kolumna1] == 0)
						{

							if (kierunek1 == 1 && wiersz1 - 1 >= 0 && plansza[wiersz1][kolumna1] == 0 && plansza[wiersz1 - 1][kolumna1] == 0)
							{
								for (int i = 0; i < 2; i++)
									plansza[wiersz1 - i][kolumna1] = 2;

								for (int a = 0; a < 3; a++)
								{
									for (int b = 0; b < 4; b++)
									{
										if (kolumna1 - 1 + a >= 0 && kolumna1 - 1 + a <= 9 && wiersz1 + 1 - b >= 0 && wiersz1 + 1 - b <= 9 && plansza[wiersz1 + 1 - b][kolumna1 - 1 + a] == 0)
											plansza[wiersz1 + 1 - b][kolumna1 - 1 + a] = -1;
									}


								}
								if (dwojka1_1 == false) dwojka1_1 = true;
								else if (dwojka1_1 == true && dwojka2_1 == false) dwojka2_1 = true;
								else if (dwojka1_1 == true && dwojka2_1 == true && dwojka3_1 == false) dwojka3_1 = true;
							}

							else if (kierunek1 == 2 && kolumna1 + 1 <= 9 && plansza[wiersz1][kolumna1] == 0 && plansza[wiersz1][kolumna1 + 1] == 0)
							{
								for (int i = 0; i < 2; i++)
									plansza[wiersz1][kolumna1 + i] = 2;

								for (int a = 0; a < 3; a++)
								{
									for (int b = 0; b < 4; b++)
									{
										if (wiersz1 - 1 + a >= 0 && wiersz1 - 1 + a <= 9 && kolumna1 - 1 + b >= 0 && kolumna1 - 1 + b <= 9 && plansza[wiersz1 - 1 + a][kolumna1 - 1 + b] == 0)
											plansza[wiersz1 - 1 + a][kolumna1 - 1 + b] = -1;
									}


								}
								if (dwojka1_1 == false) dwojka1_1 = true;
								else if (dwojka1_1 == true && dwojka2_1 == false) dwojka2_1 = true;
								else if (dwojka1_1 == true && dwojka2_1 == true && dwojka3_1 == false) dwojka3_1 = true;
							}
							else if (kierunek1 == 3 && wiersz1 + 1 <= 9 && plansza[wiersz1][kolumna1] == 0 && plansza[wiersz1 + 1][kolumna1] == 0)
							{
								for (int i = 0; i < 2; i++)
									plansza[wiersz1 + i][kolumna1] = 2;

								for (int a = 0; a < 3; a++)
								{
									for (int b = 0; b < 4; b++)
									{
										if (kolumna1 - 1 + a >= 0 && kolumna1 - 1 + a <= 9 && wiersz1 - 1 + b >= 0 && wiersz1 - 1 + b <= 9 && plansza[wiersz1 - 1 + b][kolumna1 - 1 + a] == 0)
											plansza[wiersz1 - 1 + b][kolumna1 - 1 + a] = -1;
									}


								}
								if (dwojka1_1 == false) dwojka1_1 = true;
								else if (dwojka1_1 == true && dwojka2_1 == false) dwojka2_1 = true;
								else if (dwojka1_1 == true && dwojka2_1 == true && dwojka3_1 == false) dwojka3_1 = true;
							}
							else if (kierunek1 == 4 && kolumna1 - 1 >= 0 && plansza[wiersz1][kolumna1] == 0 && plansza[wiersz1][kolumna1 - 1] == 0)
							{
								for (int i = 0; i < 2; i++)
									plansza[wiersz1][kolumna1 - i] = 2;

								for (int a = 0; a < 3; a++)
								{
									for (int b = 0; b < 4; b++)
									{
										if (wiersz1 - 1 + a >= 0 && wiersz1 - 1 + a <= 9 && kolumna1 + 1 - b >= 0 && kolumna1 + 1 - b <= 9 && plansza[wiersz1 - 1 + a][kolumna1 + 1 - b] == 0)
											plansza[wiersz1 - 1 + a][kolumna1 + 1 - b] = -1;
									}


								}
								if (dwojka1_1 == false) dwojka1_1 = true;
								else if (dwojka1_1 == true && dwojka2_1 == false) dwojka2_1 = true;
								else if (dwojka1_1 == true && dwojka2_1 == true && dwojka3_1 == false) dwojka3_1 = true;
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
					else if (dwojka3_1 == true && wiersz1 != -1)
					{
						SetConsoleTextAttribute(hOut, FOREGROUND_RED);
						cout << "Rozmiesciles juz wszystkie dwumasztowce!";
						Sleep(3000);

					}
					else if (dwojka1_1 == true && wiersz1 == -1)
					{
						int w = -1;
						int k = -1;
						int w1 = -1;
						int k1 = -1;



						for (int p = 0; p < 10; p++)
						{
							for (int q = 0; q < 10; q++)
							{
								if (plansza[p][q] == 2)
								{
									if (w == -1 && k == -1)
									{
										w = p;
										k = q;
									}
								}
							}
						}
						if (plansza[w - 1][k] == 2 && w - 1 >= 0)
						{
							w1 = w - 1;
							k1 = k;
						}
						else if (plansza[w + 1][k] == 2 && w + 1 <= 9)
						{
							w1 = w + 1;
							k1 = k;
						}
						else if (plansza[w][k - 1] == 2 && k - 1 >= 0)
						{
							w1 = w;
							k1 = k - 1;
						}
						else if (plansza[w][k + 1] == 2 && k + 1 <= 9)
						{
							w1 = w;
							k1 = k + 1;
						}

						plansza[w][k] = 9;
						plansza[w1][k1] = 9;

						string czyDalej1 = "NIE";
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
										if (plansza[i][j] == 0)
										{
											SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
											cout << ".";
										}
										else if (plansza[i][j] == -1)
										{
											SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
											cout << "o";
										}
										else if (plansza[i][j] == 9)
										{
											SetConsoleTextAttribute(hOut, FOREGROUND_GREEN);
											cout << kratka;
										}
										else
										{
											SetConsoleTextAttribute(hOut, FOREGROUND_RED);
											cout << kratka;
										}
									}
									else
									{
										cout.width(5);
										if (plansza[i][j] == 0)
										{
											SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
											cout << ".";
										}
										else if (plansza[i][j] == -1)
										{
											SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
											cout << "o";
										}
										else if (plansza[i][j] == 9)
										{
											SetConsoleTextAttribute(hOut, FOREGROUND_GREEN);
											cout << kratka;
										}
										else
										{
											SetConsoleTextAttribute(hOut, FOREGROUND_RED);
											cout << kratka;
										}
									}

								}
								if (i == 1)
								{
									spacje(20);

									if (jedynka1_1 == false)
									{
										SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
										cout << kratka << "   ";
									}

									if (jedynka2_1 == false)
									{
										SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
										cout << kratka << "   ";
									}

									if (jedynka3_1 == false)
									{
										SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
										cout << kratka << "   ";
									}

									if (jedynka4_1 == false)
									{
										SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
										cout << kratka;
									}
								}
								if (i == 3)
								{
									spacje(20);

									if (dwojka1_1 == false)
									{
										SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
										cout << kratka << kratka << "   ";
									}

									if (dwojka2_1 == false)
									{
										SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
										cout << kratka << kratka << "   ";
									}

									if (dwojka3_1 == false)
									{
										SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
										cout << kratka << kratka << "   ";
									}
								}
								if (i == 5)
								{
									spacje(20);

									if (trojka1_1 == false)
									{
										SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
										cout << kratka << kratka << kratka << "   ";
									}

									if (trojka2_1 == false)
									{
										SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
										cout << kratka << kratka << kratka << "   ";
									}
								}
								if (i == 7)
								{
									spacje(20);

									if (czworka1_1 == false)
									{
										SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
										cout << kratka << kratka << kratka << kratka << "   ";
									}
								}
								cout << endl << endl;

							}
							SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN);
							cout << "Czy chcesz zdjac statek zaznaczony na zielono?" << endl;
							SetConsoleTextAttribute(hOut, FOREGROUND_RED);
							cout << "[TAK]";
							SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN);
							cout << " - sciaga statek" << endl;
							SetConsoleTextAttribute(hOut, FOREGROUND_RED);
							cout << "[NIE]";
							SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN);
							cout << " - przechodzi do kolejnego statku" << endl;
							SetConsoleTextAttribute(hOut, FOREGROUND_RED);
							cout << "[COFNIJ]";
							SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN);
							cout << " - wraca do ukladania statkow" << endl;
							SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN);
							cin >> czyDalej1;
							if (czyDalej1 == "TAK" || czyDalej1 == "tak" || czyDalej1 == "Tak")
							{
								plansza[w][k] = 0;
								plansza[w1][k1] = 0;
								usun(w, k, plansza);
								usun(w1, k1, plansza);
								if (dwojka3_1 == true) dwojka3_1 = false;
								else if (dwojka2_1 == true) dwojka2_1 = false;
								else if (dwojka1_1 == true) dwojka1_1 = false;

							}
							else if (czyDalej1 == "NIE" || czyDalej1 == "nie" || czyDalej1 == "Nie")
							{

								plansza[w][k] = 2;
								plansza[w1][k1] = 2;
								for (int c = 0; c < 10; c++)
								{
									for (int d = 0; d < 10; d++)
									{
										if (plansza[c][d] == 2)
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
								if (plansza[w - 1][k] == 2 && w - 1 >= 0)
								{
									w1 = w - 1;
									k1 = k;
								}
								else if (plansza[w + 1][k] == 2 && w + 1 <= 9)
								{
									w1 = w + 1;
									k1 = k;
								}
								else if (plansza[w][k - 1] == 2 && k - 1 >= 0)
								{
									w1 = w;
									k1 = k - 1;
								}
								else if (plansza[w][k + 1] == 2 && k + 1 <= 9)
								{
									w1 = w;
									k1 = k + 1;
								}
								plansza[w][k] = 9;
								plansza[w1][k1] = 9;


							}
							else
							{
								SetConsoleTextAttribute(hOut, FOREGROUND_RED);
								cout << endl << "Podano zla odpowiedz" << endl;
								Sleep(3000);
							}

						} while (czyDalej1 == "NIE" || czyDalej1 == "nie" || czyDalej1 == "Nie");

					}
					else if (dwojka1_1 == false && wiersz1 == -1)
					{
						SetConsoleTextAttribute(hOut, FOREGROUND_RED);
						Sleep(3000);
						cout << "Nie mozesz sciagnac statku, ktory nie jest na planszy!";
					}


				}

				else if (statek1 == 3)
				{
					if (trojka2_1 == false && wiersz1 != -1)
					{
						if (plansza[wiersz1][kolumna1] == 0)
						{

							if (kierunek1 == 1 && wiersz1 - 2 >= 0 && plansza[wiersz1][kolumna1] == 0 && plansza[wiersz1 - 1][kolumna1] == 0 && plansza[wiersz1 - 2][kolumna1] == 0)
							{
								for (int i = 0; i < 3; i++)
									plansza[wiersz1 - i][kolumna1] = 3;

								for (int a = 0; a < 3; a++)
								{
									for (int b = 0; b < 5; b++)
									{
										if (kolumna1 - 1 + a >= 0 && kolumna1 - 1 + a <= 9 && wiersz1 + 1 - b >= 0 && wiersz1 + 1 - b <= 9 && plansza[wiersz1 + 1 - b][kolumna1 - 1 + a] == 0)
											plansza[wiersz1 + 1 - b][kolumna1 - 1 + a] = -1;
									}


								}
								if (trojka1_1 == false) trojka1_1 = true;
								else if (trojka1_1 == true && trojka2_1 == false) trojka2_1 = true;
							}
							else if (kierunek1 == 2 && kolumna1 + 2 <= 9 && plansza[wiersz1][kolumna1] == 0 && plansza[wiersz1][kolumna1 + 1] == 0 && plansza[wiersz1][kolumna1 + 2] == 0)
							{
								for (int i = 0; i < 3; i++)
									plansza[wiersz1][kolumna1 + i] = 3;

								for (int a = 0; a < 3; a++)
								{
									for (int b = 0; b < 5; b++)
									{
										if (wiersz1 - 1 + a >= 0 && wiersz1 - 1 + a <= 9 && kolumna1 - 1 + b >= 0 && kolumna1 - 1 + b <= 9 && plansza[wiersz1 - 1 + a][kolumna1 - 1 + b] == 0)
											plansza[wiersz1 - 1 + a][kolumna1 - 1 + b] = -1;
									}


								}
								if (trojka1_1 == false) trojka1_1 = true;
								else if (trojka1_1 == true && trojka2_1 == false) trojka2_1 = true;
							}
							else if (kierunek1 == 3 && wiersz1 + 2 <= 9 && plansza[wiersz1][kolumna1] == 0 && plansza[wiersz1 + 1][kolumna1] == 0 && plansza[wiersz1 + 2][kolumna1] == 0)
							{
								for (int i = 0; i < 3; i++)
									plansza[wiersz1 + i][kolumna1] = 3;

								for (int a = 0; a < 3; a++)
								{
									for (int b = 0; b < 5; b++)
									{
										if (kolumna1 - 1 + a >= 0 && kolumna1 - 1 + a <= 9 && wiersz1 - 1 + b >= 0 && wiersz1 - 1 + b <= 9 && plansza[wiersz1 - 1 + b][kolumna1 - 1 + a] == 0)
											plansza[wiersz1 - 1 + b][kolumna1 - 1 + a] = -1;
									}


								}
								if (trojka1_1 == false) trojka1_1 = true;
								else if (trojka1_1 == true && trojka2_1 == false) trojka2_1 = true;
							}
							else if (kierunek1 == 4 && kolumna1 - 2 >= 0 && plansza[wiersz1][kolumna1] == 0 && plansza[wiersz1][kolumna1 - 1] == 0 && plansza[wiersz1][kolumna1 - 2] == 0)
							{
								for (int i = 0; i < 3; i++)
									plansza[wiersz1][kolumna1 - i] = 3;

								for (int a = 0; a < 3; a++)
								{
									for (int b = 0; b < 5; b++)
									{
										if (wiersz1 - 1 + a >= 0 && wiersz1 - 1 + a <= 9 && kolumna1 + 1 - b >= 0 && kolumna1 + 1 - b <= 9 && plansza[wiersz1 - 1 + a][kolumna1 + 1 - b] == 0)
											plansza[wiersz1 - 1 + a][kolumna1 + 1 - b] = -1;
									}


								}
								if (trojka1_1 == false) trojka1_1 = true;
								else if (trojka1_1 == true && trojka2_1 == false) trojka2_1 = true;
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
					else if (trojka2_1 == true && wiersz1 != -1)
					{
						SetConsoleTextAttribute(hOut, FOREGROUND_RED);
						cout << "Rozmiesciles juz wszystkie trzymasztowce!";
						Sleep(3000);

					}
					else if (trojka1_1 == true && wiersz1 == -1)
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
								if (plansza[p][q] == 3)
								{
									if (w == -1 && k == -1)
									{
										w = p;
										k = q;
									}
								}
							}
						}

						if (plansza[w + 1][k] == 3 && w + 1 <= 9)
						{
							w1 = w + 1;
							k1 = k;
							w2 = w + 2;
							k2 = k;
						}

						else if (plansza[w][k + 1] == 3 && k + 1 <= 9)
						{
							w1 = w;
							k1 = k + 1;
							w2 = w;
							k2 = k + 2;
						}

						plansza[w][k] = 9;
						plansza[w1][k1] = 9;
						plansza[w2][k2] = 9;

						string czyDalej1 = "NIE";
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
										if (plansza[i][j] == 0)
										{
											SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
											cout << ".";
										}
										else if (plansza[i][j] == -1)
										{
											SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
											cout << "o";
										}
										else if (plansza[i][j] == 9)
										{
											SetConsoleTextAttribute(hOut, FOREGROUND_GREEN);
											cout << kratka;
										}
										else
										{
											SetConsoleTextAttribute(hOut, FOREGROUND_RED);
											cout << kratka;
										}
									}
									else
									{
										cout.width(5);
										if (plansza[i][j] == 0)
										{
											SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
											cout << ".";
										}
										else if (plansza[i][j] == -1)
										{
											SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
											cout << "o";
										}
										else if (plansza[i][j] == 9)
										{
											SetConsoleTextAttribute(hOut, FOREGROUND_GREEN);
											cout << kratka;
										}
										else
										{
											SetConsoleTextAttribute(hOut, FOREGROUND_RED);
											cout << kratka;
										}
									}

								}
								if (i == 1)
								{
									spacje(20);

									if (jedynka1_1 == false)
									{
										SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
										cout << kratka << "   ";
									}

									if (jedynka2_1 == false)
									{
										SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
										cout << kratka << "   ";
									}

									if (jedynka3_1 == false)
									{
										SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
										cout << kratka << "   ";
									}

									if (jedynka4_1 == false)
									{
										SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
										cout << kratka;
									}
								}
								if (i == 3)
								{
									spacje(20);

									if (dwojka1_1 == false)
									{
										SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
										cout << kratka << kratka << "   ";
									}

									if (dwojka2_1 == false)
									{
										SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
										cout << kratka << kratka << "   ";
									}

									if (dwojka3_1 == false)
									{
										SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
										cout << kratka << kratka << "   ";
									}
								}
								if (i == 5)
								{
									spacje(20);

									if (trojka1_1 == false)
									{
										SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
										cout << kratka << kratka << kratka << "   ";
									}

									if (trojka2_1 == false)
									{
										SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
										cout << kratka << kratka << kratka << "   ";
									}
								}
								if (i == 7)
								{
									spacje(20);

									if (czworka1_1 == false)
									{
										SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
										cout << kratka << kratka << kratka << kratka << "   ";
									}
								}
								cout << endl << endl;

							}
							SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN);
							cout << "Czy chcesz zdjac statek zaznaczony na zielono?" << endl;
							SetConsoleTextAttribute(hOut, FOREGROUND_RED);
							cout << "[TAK]";
							SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN);
							cout << " - sciaga statek" << endl;
							SetConsoleTextAttribute(hOut, FOREGROUND_RED);
							cout << "[NIE]";
							SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN);
							cout << " - przechodzi do kolejnego statku" << endl;
							SetConsoleTextAttribute(hOut, FOREGROUND_RED);
							cout << "[COFNIJ]";
							SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN);
							cout << " - wraca do ukladania statkow" << endl;
							SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN);
							cin >> czyDalej1;
							if (czyDalej1 == "TAK" || czyDalej1 == "tak" || czyDalej1 == "Tak")
							{
								plansza[w][k] = 0;
								plansza[w1][k1] = 0;
								plansza[w2][k2] = 0;
								usun(w, k, plansza);
								usun(w1, k1, plansza);
								usun(w2, k2, plansza);
								if (trojka2_1 == true) trojka2_1 = false;
								else if (trojka1_1 == true) trojka1_1 = false;

							}
							else if (czyDalej1 == "NIE" || czyDalej1 == "nie" || czyDalej1 == "Nie")
							{

								plansza[w][k] = 3;
								plansza[w1][k1] = 3;
								plansza[w2][k2] = 3;
								for (int c = 0; c < 10; c++)
								{
									for (int d = 0; d < 10; d++)
									{
										if (plansza[c][d] == 3)
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
								if (plansza[w + 1][k] == 3 && w + 1 <= 9)
								{
									w1 = w + 1;
									k1 = k;
									w2 = w + 2;
									k2 = k;
								}

								else if (plansza[w][k + 1] == 3 && k + 1 <= 9)
								{
									w1 = w;
									k1 = k + 1;
									w2 = w;
									k2 = k + 2;
								}
								plansza[w][k] = 9;
								plansza[w1][k1] = 9;
								plansza[w2][k2] = 9;


							}
							else
							{
								SetConsoleTextAttribute(hOut, FOREGROUND_RED);
								cout << endl << "Podano zla odpowiedz" << endl;
								Sleep(3000);
							}

						} while (czyDalej1 == "NIE" || czyDalej1 == "nie" || czyDalej1 == "Nie");

					}
					else if (trojka1_1 == false && wiersz1 == -1)
					{
						SetConsoleTextAttribute(hOut, FOREGROUND_RED);
						Sleep(3000);
						cout << "Nie mozesz sciagnac statku, ktory nie jest na planszy!";
					}


				}
				else if (statek1 == 4)
				{
					if (czworka1_1 == false && wiersz1 != -1)
					{
						if (plansza[wiersz1][kolumna1] == 0)
						{

							if (kierunek1 == 1 && wiersz1 - 3 >= 0 && plansza[wiersz1][kolumna1] == 0 && plansza[wiersz1 - 1][kolumna1] == 0 && plansza[wiersz1 - 2][kolumna1] == 0 && plansza[wiersz1 - 3][kolumna1] == 0)
							{
								for (int i = 0; i < 4; i++)
									plansza[wiersz1 - i][kolumna1] = 4;

								for (int a = 0; a < 3; a++)
								{
									for (int b = 0; b < 6; b++)
									{
										if (kolumna1 - 1 + a >= 0 && kolumna1 - 1 + a <= 9 && wiersz1 + 1 - b >= 0 && wiersz1 + 1 - b <= 9 && plansza[wiersz1 + 1 - b][kolumna1 - 1 + a] == 0)
											plansza[wiersz1 + 1 - b][kolumna1 - 1 + a] = -1;
									}


								}
								czworka1_1 = true;
							}

							else if (kierunek1 == 2 && kolumna1 + 3 <= 9 && plansza[wiersz1][kolumna1] == 0 && plansza[wiersz1][kolumna1 + 1] == 0 && plansza[wiersz1][kolumna1 + 2] == 0 && plansza[wiersz1][kolumna1 + 3] == 0)
							{
								for (int i = 0; i < 4; i++)
									plansza[wiersz1][kolumna1 + i] = 4;

								for (int a = 0; a < 3; a++)
								{
									for (int b = 0; b < 6; b++)
									{
										if (wiersz1 - 1 + a >= 0 && wiersz1 - 1 + a <= 9 && kolumna1 - 1 + b >= 0 && kolumna1 - 1 + b <= 9 && plansza[wiersz1 - 1 + a][kolumna1 - 1 + b] == 0)
											plansza[wiersz1 - 1 + a][kolumna1 - 1 + b] = -1;
									}


								}
								czworka1_1 = true;
							}
							else if (kierunek1 == 3 && wiersz1 + 3 <= 9 && plansza[wiersz1][kolumna1] == 0 && plansza[wiersz1 + 1][kolumna1] == 0 && plansza[wiersz1 + 2][kolumna1] == 0 && plansza[wiersz1 + 3][kolumna1] == 0)
							{
								for (int i = 0; i < 4; i++)
									plansza[wiersz1 + i][kolumna1] = 4;

								for (int a = 0; a < 3; a++)
								{
									for (int b = 0; b < 6; b++)
									{
										if (kolumna1 - 1 + a >= 0 && kolumna1 - 1 + a <= 9 && wiersz1 - 1 + b >= 0 && wiersz1 - 1 + b <= 9 && plansza[wiersz1 - 1 + b][kolumna1 - 1 + a] == 0)
											plansza[wiersz1 - 1 + b][kolumna1 - 1 + a] = -1;
									}


								}
								czworka1_1 = true;
							}
							else if (kierunek1 == 4 && kolumna1 - 3 >= 0 && plansza[wiersz1][kolumna1] == 0 && plansza[wiersz1][kolumna1 - 1] == 0 && plansza[wiersz1][kolumna1 - 2] == 0 && plansza[wiersz1][kolumna1 - 3] == 0)
							{
								for (int i = 0; i < 4; i++)
									plansza[wiersz1][kolumna1 - i] = 4;

								for (int a = 0; a < 3; a++)
								{
									for (int b = 0; b < 6; b++)
									{
										if (wiersz1 - 1 + a >= 0 && wiersz1 - 1 + a <= 9 && kolumna1 + 1 - b >= 0 && kolumna1 + 1 - b <= 9 && plansza[wiersz1 - 1 + a][kolumna1 + 1 - b] == 0)
											plansza[wiersz1 - 1 + a][kolumna1 + 1 - b] = -1;
									}


								}
								czworka1_1 = true;
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
					else if (czworka1_1 == true && wiersz1 != -1)
					{
						SetConsoleTextAttribute(hOut, FOREGROUND_RED);
						cout << "Rozmiesciles juz czteromasztowiec!";
						Sleep(3000);

					}
					else if (czworka1_1 == true && wiersz1 == -1)
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
								if (plansza[p][q] == 4)
								{
									if (w == -1 && k == -1)
									{
										w = p;
										k = q;
									}
								}
							}
						}

						if (plansza[w + 1][k] == 4 && w + 1 <= 9)
						{
							w1 = w + 1;
							k1 = k;
							w2 = w + 2;
							k2 = k;
							w3 = w + 3;
							k3 = k;
						}

						else if (plansza[w][k + 1] == 4 && k + 1 <= 9)
						{
							w1 = w;
							k1 = k + 1;
							w2 = w;
							k2 = k + 2;
							w3 = w;
							k3 = k + 3;
						}

						plansza[w][k] = 9;
						plansza[w1][k1] = 9;
						plansza[w2][k2] = 9;
						plansza[w3][k3] = 9;

						string czyDalej1 = "NIE";
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
										if (plansza[i][j] == 0)
										{
											SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
											cout << ".";
										}
										else if (plansza[i][j] == -1)
										{
											SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
											cout << "o";
										}
										else if (plansza[i][j] == 9)
										{
											SetConsoleTextAttribute(hOut, FOREGROUND_GREEN);
											cout << kratka;
										}
										else
										{
											SetConsoleTextAttribute(hOut, FOREGROUND_RED);
											cout << kratka;
										}
									}
									else
									{
										cout.width(5);
										if (plansza[i][j] == 0)
										{
											SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
											cout << ".";
										}
										else if (plansza[i][j] == -1)
										{
											SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
											cout << "o";
										}
										else if (plansza[i][j] == 9)
										{
											SetConsoleTextAttribute(hOut, FOREGROUND_GREEN);
											cout << kratka;
										}
										else
										{
											SetConsoleTextAttribute(hOut, FOREGROUND_RED);
											cout << kratka;
										}
									}

								}
								if (i == 1)
								{
									spacje(20);

									if (jedynka1_1 == false)
									{
										SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
										cout << kratka << "   ";
									}

									if (jedynka2_1 == false)
									{
										SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
										cout << kratka << "   ";
									}

									if (jedynka3_1 == false)
									{
										SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
										cout << kratka << "   ";
									}

									if (jedynka4_1 == false)
									{
										SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
										cout << kratka;
									}
								}
								if (i == 3)
								{
									spacje(20);

									if (dwojka1_1 == false)
									{
										SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
										cout << kratka << kratka << "   ";
									}

									if (dwojka2_1 == false)
									{
										SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
										cout << kratka << kratka << "   ";
									}

									if (dwojka3_1 == false)
									{
										SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
										cout << kratka << kratka << "   ";
									}
								}
								if (i == 5)
								{
									spacje(20);

									if (trojka1_1 == false)
									{
										SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
										cout << kratka << kratka << kratka << "   ";
									}

									if (trojka2_1 == false)
									{
										SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
										cout << kratka << kratka << kratka << "   ";
									}
								}
								if (i == 7)
								{
									spacje(20);

									if (czworka1_1 == false)
									{
										SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
										cout << kratka << kratka << kratka << kratka << "   ";
									}
								}
								cout << endl << endl;

							}
							SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN);
							cout << "Czy chcesz zdjac statek zaznaczony na zielono?" << endl;
							SetConsoleTextAttribute(hOut, FOREGROUND_RED);
							cout << "[TAK]";
							SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN);
							cout << " - sciaga statek" << endl;
							SetConsoleTextAttribute(hOut, FOREGROUND_RED);
							cout << "[NIE]";
							SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN);
							cout << " - przechodzi do kolejnego statku" << endl;
							SetConsoleTextAttribute(hOut, FOREGROUND_RED);
							cout << "[COFNIJ]";
							SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN);
							cout << " - wraca do ukladania statkow" << endl;
							SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN);
							cin >> czyDalej1;
							if (czyDalej1 == "TAK" || czyDalej1 == "tak" || czyDalej1 == "Tak")
							{
								plansza[w][k] = 0;
								plansza[w1][k1] = 0;
								plansza[w2][k2] = 0;
								plansza[w3][k3] = 0;
								usun(w, k, plansza);
								usun(w1, k1, plansza);
								usun(w2, k2, plansza);
								usun(w3, k3, plansza);
								if (czworka1_1 == true) czworka1_1 = false;


							}
							else
							{
								SetConsoleTextAttribute(hOut, FOREGROUND_RED);
								cout << endl << "Podano zla odpowiedz" << endl;
								Sleep(3000);
							}

						} while (czyDalej1 == "NIE" || czyDalej1 == "nie" || czyDalej1 == "Nie");

					}
					else if (czworka1_1 == false && wiersz1 == -1)
					{
						SetConsoleTextAttribute(hOut, FOREGROUND_RED);
						Sleep(3000);
						cout << "Nie mozesz sciagnac statku, ktory nie jest na planszy!";
					}



				}
				else
				{
					SetConsoleTextAttribute(hOut, FOREGROUND_RED);
					cout << "Taki statek nie istnieje!";
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
		else if (czyGotowy1 == "OK" || czyGotowy1 == "ok" || czyGotowy1 == "Ok" || czyGotowy1 == "oK")
		{
			bool sprawdzacz = true;
			while (sprawdzacz == true)
			{
				int sprawdzam[4] = { 0, 0, 0, 0 };
				for (int p = 0; p <= 9; p++)
				{
					for (int q = 0; q <= 9; q++)
					{
						if (plansza[p][q] == 1)
							sprawdzam[0] += 1;
						else if (plansza[p][q] == 2)
							sprawdzam[1] += 1;
						else if (plansza[p][q] == 3)
							sprawdzam[2] += 1;
						else if (plansza[p][q] == 4)
							sprawdzam[3] += 1;
					}
				}

				if (sprawdzam[0] == 4 && sprawdzam[1] == 6 && sprawdzam[2] == 6 && sprawdzam[3] == 4)
				{
					sprawdzacz = false;
					zacznij_gre = true;
				}
				else
				{
					czyGotowy1 = "pudlo";
					SetConsoleTextAttribute(hOut, FOREGROUND_RED);
					cout << "Nie wylozono wszystkich statkow!";
					Sleep(3000);
					sprawdzacz = false;
				}
			}
		}


	}


	system("cls");
}

void czas(clock_t start, clock_t stop)
{
	HANDLE hOut;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	double czas = (stop - start) / 1000;
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

int main()
{
	// ZMIENNE USTAWIENIA i poborowe pliku//
	bool ekran_powitalny = true;
	bool muzyka = true;
	bool efekty = true;
	int nr_linii = 1;
	int sprawdz{};
	string linia{};


	// CZAS//
	clock_t start, stop;

	//ROZMIARY//
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD c2;
	c2.X = 120;
	c2.Y = 30;
	SetConsoleScreenBufferSize(handle, c2);

	SMALL_RECT sr;
	sr.Left = 0;
	sr.Top = 0;
	sr.Right = c2.X - 1;
	sr.Bottom = c2.Y - 1;
	SetConsoleWindowInfo(handle, true, &sr);

	//ZMIENNE pozosta³e//
	HANDLE hOut;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	int plansza[10][10]{};
	int plansza2[10][10]{};
	string imie1;
	string imie2;
	bool ekran = true;
	bool prawda;
	unsigned char kreska = 179;


	//Wskaznik do funkcji//

	void(*wsk)(int) = nullptr;
	wsk = &spacje;

	int instrukcja = 0;

	//ZMIENNE STATECZKOWE
	unsigned char kratka = 254;
	bool jedynka1_1 = false;
	bool jedynka2_1 = false;
	bool jedynka3_1 = false;
	bool jedynka4_1 = false;
	bool dwojka1_1 = false;
	bool dwojka2_1 = false;
	bool dwojka3_1 = false;
	bool trojka1_1 = false;
	bool trojka2_1 = false;
	bool czworka1_1 = false;

	bool jedynka1_2 = false;
	bool jedynka2_2 = false;
	bool jedynka3_2 = false;
	bool jedynka4_2 = false;
	bool dwojka1_2 = false;
	bool dwojka2_2 = false;
	bool dwojka3_2 = false;
	bool trojka1_2 = false;
	bool trojka2_2 = false;
	bool czworka1_2 = false;

	//Pobranie ustawien z pliku//
	plik.open("ustawienia.txt", ios::in);
	if (plik.good() == false)
	{
		plik.close();
		plik.open("ustawienia.txt", ios::out);
		plik << "1" << endl << "1" << endl << "1";                   // W przypadku problemów z otwarciem pliku
		plik.close();                                                // tworzy siê nowy plik i ustawienia domyœlnie s¹ w³¹czone.
		ekran_powitalny = true;
		muzyka = true;
		efekty = true;

		Sleep(3000);

	}
	else
	{
		while (getline(plik, linia))
		{

			if (nr_linii == 1)
			{
				sprawdz = atoi(linia.c_str());
				if (sprawdz == 1)
					ekran_powitalny = true;
				else if (sprawdz == 0)                              // Pobiera dane z pliku i ustawia ustawienia do stanu z poprzedniego
					ekran_powitalny = false;                        // korzystania z aplikacji
				else
					ekran_powitalny = true;
			}
			else if (nr_linii == 2)
			{
				sprawdz = atoi(linia.c_str());
				if (sprawdz == 1)
					muzyka = true;
				else if (sprawdz == 0)
					muzyka = false;
				else
					muzyka = true;
			}
			else if (nr_linii == 3)
			{
				sprawdz = atoi(linia.c_str());
				if (sprawdz == 1)
					efekty = true;
				else if (sprawdz == 0)
					efekty = false;
				else
					efekty = true;
			}

			nr_linii++;
		}

		plik.close();
	}

	if (muzyka == true)
	{
		PlaySound(L"gra.wav", NULL, SND_ASYNC | SND_LOOP);                   // Wlaczenie muzyczki
	}
	if (ekran_powitalny == true)
	{
		SetConsoleTextAttribute(hOut, FOREGROUND_RED);
		spacje(26);																					// Ekran startowy      
		cout << "Statek w porcie jest bezpieczny, ale nie po to buduje sie statki..." << endl;
		Sleep(5000);
		SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE);
		cout << endl << "_____________¶¶¶¶¶¶¶¶¶¶¶¶¶";
		Sleep(100);
		cout << endl << "_____________¶¶___________¶¶";
		Sleep(100);
		cout << endl << "______________¶____________¶";
		Sleep(100);
		cout << endl << "______________¶_____________¶";
		Sleep(100);
		cout << endl << "_______________¶____________¶";
		Sleep(100);
		cout << endl << "_______________¶____________¶_¶¶";
		Sleep(100);
		cout << endl << "_______________¶__¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶";
		Sleep(100);
		cout << endl << "_____¶¶¶¶¶¶¶¶¶¶¶¶¶¶______________¶";
		Sleep(100);
		cout << endl << "_____¶____________¶¶_____________¶¶____¶";
		Sleep(100);
		cout << endl << "_____¶¶____________¶_____¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶";
		Sleep(100);
		cout << endl << "______¶______¶¶¶¶¶¶¶¶¶¶¶¶¶¶______________¶";
		Sleep(100);
		cout << endl << "______¶¶_____¶¶___________¶______________¶¶";
		Sleep(100);
		cout << endl << "_______¶______¶____________¶______________¶";
		Sleep(100);
		cout << endl << "_______¶______¶¶___________¶_____________¶¶";
		Sleep(100);
		cout << endl << "_______¶_______¶___________¶_____________¶¶";
		Sleep(100);
		cout << endl << "______¶¶_______¶___________¶¶____________¶";
		Sleep(100);
		cout << endl << "______¶¶¶¶¶¶¶¶¶¶¶__________¶¶___________¶¶";
		Sleep(100);
		cout << endl << "___________¶_¶_¶¶________¶¶¶_____¶¶¶¶¶¶¶¶_____¶¶¶";
		Sleep(100);
		cout << endl << "___________¶_¶_¶¶¶¶¶¶¶¶¶¶¶_¶¶¶¶¶¶¶_______¶¶¶¶¶__¶¶";
		Sleep(100);
		cout << endl << "¶¶¶¶¶¶_____¶_¶______¶¶_¶_______¶_¶¶¶¶¶¶¶¶¶___¶¶¶¶¶";
		Sleep(100);
		cout << endl << "¶¶___¶¶¶¶¶¶¶¶¶______¶¶_¶____¶¶¶¶¶¶¶________¶¶";
		Sleep(100);
		cout << endl << "__¶¶________¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶____¶¶______¶";
		Sleep(100);
		cout << endl << "____¶____________________________¶¶_¶____¶";
		Sleep(100);
		cout << endl << "_____¶_____¶¶¶_____¶¶_____¶¶¶_____¶¶¶___¶¶";
		Sleep(100);
		cout << endl << "______¶___¶¶_¶¶___¶¶_¶____¶_¶¶__________¶";
		Sleep(100);
		cout << endl << "______¶¶____¶¶_____¶¶¶_____¶¶__________¶¶";
		Sleep(100);
		cout << endl << "_______¶¶_____________________________¶¶";
		Sleep(100);
		cout << endl << "________¶¶___________________________¶¶";
		Sleep(100);
		cout << endl << "_________¶¶________________________¶¶¶";
		Sleep(100);
		cout << endl << "___________¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶";
		Sleep(3000);
	}



	//WYŒWIETLANIE EKRANU STARTOWEGO//
	while (ekran == true)
	{
		if (instrukcja == 0)
		{
			if (muzyka == true)
			{
				PlaySound(L"gra.wav", NULL, SND_ASYNC | SND_LOOP | SND_NOSTOP);
			}
			system("cls");
			ramka("STATKI", wsk);
			SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
			cout.width(53);
			SetConsoleTextAttribute(hOut, FOREGROUND_RED);                                          // Menu glowne
			cout << "[1]";
			SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
			cout << " Tryb dla dwoch graczy" << endl << endl;
			cout.width(53);
			SetConsoleTextAttribute(hOut, FOREGROUND_RED);
			cout << "[2]";
			SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
			cout << " Gra z komputerem" << endl << endl;
			cout.width(53);
			SetConsoleTextAttribute(hOut, FOREGROUND_RED);
			cout << "[3]";
			SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
			cout << " Instrukcja" << endl << endl;
			cout.width(53);
			SetConsoleTextAttribute(hOut, FOREGROUND_RED);
			cout << "[4]";
			SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
			cout << " Ustawienia" << endl << endl;
			cout.width(53);

			cout << "Wybierz numerek, aby przejsc do odpowiedniej sekcji: ";
			cin >> instrukcja;

			prawda = cin.good();
			sprawdzCin(prawda);
		}


		else if (instrukcja == 1)
		{
			system("cls");
			cin.ignore(100, '\n');
			ramka("Tryb dla dwoch graczy", wsk);
			SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
			cout << "Podaj imie pierwszego gracza: ";
			cin >> imie1;														// Tryb dwuosobywy, podanie imion graczy.
			cout << endl;
			cout << "Podaj imie drugiego gracza: ";
			cin >> imie2;
			system("cls");

			int dl_imie1 = imie1.length() - (imie1.length() % 2);
			int dl_imie2 = imie2.length() - (imie2.length() % 2);
			int ulozenie1;
			int ulozenie2;
			bool blad = false;
			bool zacznij_gre = false;
			while (zacznij_gre == false)
			{
				do
				{
					system("cls");
					SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
					cout << imie1;
					SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
					cout << ", jezeli chcesz losowo ulozyc plansze - kliknij";                               // Wybor sposobu ukladania statkow
					SetConsoleTextAttribute(hOut, FOREGROUND_GREEN);
					cout << " [1]";
					SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
					cout << endl << "Jezeli chcesz samodzielnie ulozyc plansze (zalecane zapoznanie sie najpierw z instrukcja) - kliknij";
					SetConsoleTextAttribute(hOut, FOREGROUND_GREEN);
					cout << " [2]" << endl << endl;
					SetConsoleTextAttribute(hOut, FOREGROUND_RED);
					cout << "PAMIETAJ, ABY NIE POKAZYWAC ROZLOSOWANEJ PLANSZY SWOJEMY OPONENTOWI!" << endl;
					SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
					cin >> ulozenie1;
					prawda = cin.good();
					sprawdzCin(prawda);
					if (ulozenie1 != 1 && ulozenie1 != 2)
					{
						system("cls");
						SetConsoleTextAttribute(hOut, FOREGROUND_RED);
						cout << endl << "Dokonales zlego wyboru! Nie przechodz na ciemna strone mocy i wybierz wlasciwa cyfre!";
					}
				} while (prawda == 0 || (ulozenie1 != 1 && ulozenie1 != 2));
				system("cls");

				if (ulozenie1 == 1)
				{
					do
					{

						if (ulozenie1 == 1)
						{
							uloz_plansze(plansza);

							bool sprawdzacz = true;

							while (sprawdzacz == true)
							{
								int sprawdzam[4] = { 0, 0, 0, 0 };
								for (int p = 0; p <= 9; p++)
								{
									for (int q = 0; q <= 9; q++)
									{
										if (plansza[p][q] == 1)                          // Losowanie planszszy a nastêpnie sprawdzenie,
											sprawdzam[0] += 1;                           // czy jest poprawnie ulozona, poprzez policzenie ilosci statkow.
										else if (plansza[p][q] == 2)
											sprawdzam[1] += 1;
										else if (plansza[p][q] == 3)
											sprawdzam[2] += 1;
										else if (plansza[p][q] == 4)
											sprawdzam[3] += 1;
									}
								}

								if (sprawdzam[0] == 4 && sprawdzam[1] == 6 && sprawdzam[2] == 6 && sprawdzam[3] == 4)
								{
									sprawdzacz = false;
								}
								else
									uloz_plansze(plansza);
							}
						}
						do
						{
							kropki(plansza);

							if (ulozenie1 != 1 && ulozenie1 != 0)
							{
								SetConsoleTextAttribute(hOut, FOREGROUND_RED);
								cout << "Dokonales zlego wyboru! Nie przechodz na ciemna strone mocy i wybierz wlasciwa cyfre!" << endl << endl;
								cin.clear();
								cin.ignore(100, '\n');
							}
							SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
							cout << "        " << endl << endl << "Jezeli chcesz rozlosowac jeszcze raz - wcisnij";
							SetConsoleTextAttribute(hOut, FOREGROUND_GREEN);                                            // Pytanie czy dalej losowac
							cout << " [1]";
							SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
							cout << ", jezeli takie ulozenie ci odpowiada - wcisnij";
							SetConsoleTextAttribute(hOut, FOREGROUND_GREEN);
							cout << " [2]" << endl;
							SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);

							cin >> ulozenie1;
							prawda = cin.good();
							sprawdzCin(prawda);
							if (prawda == 0) system("cls");
						} while (prawda == 0);
						system("cls");
						if (ulozenie1 == 2) zacznij_gre = true;
					} while ((ulozenie1 != 2 && ulozenie1 != 0));
					system("cls");
				}



				else if (ulozenie1 == 2)
				{
					recznieUloz(plansza, zacznij_gre);
				}
			}
			bool zacznij_gre2 = false;
			while (zacznij_gre2 == false)
			{
				do
				{
					system("cls");
					SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
					cout << imie2;
					SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
					cout << ", jezeli chcesz losowo ulozyc plansze - kliknij";
					SetConsoleTextAttribute(hOut, FOREGROUND_GREEN);
					cout << " [1]";
					SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
					cout << endl << "Jezeli chcesz samodzielnie ulozyc plansze (zalecane zapoznanie sie najpierw z instrukcja) - kliknij";
					SetConsoleTextAttribute(hOut, FOREGROUND_GREEN);
					cout << " [2]" << endl << endl;
					SetConsoleTextAttribute(hOut, FOREGROUND_RED);
					cout << "PAMIETAJ, ABY NIE POKAZYWAC ROZLOSOWANEJ PLANSZY SWOJEMY OPONENTOWI!" << endl;
					SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
					cin >> ulozenie2;
					prawda = cin.good();
					sprawdzCin(prawda);
					if (ulozenie2 != 1 && ulozenie2 != 2)
					{
						system("cls");
						SetConsoleTextAttribute(hOut, FOREGROUND_RED);
						cout << "Dokonales zlego wyboru! Nie przechodz na ciemna strone mocy i wybierz wlasciwa cyfre!" << endl << endl;
					}
				} while (prawda == 0 || (ulozenie2 != 1 && ulozenie2 != 2));
				system("cls");
				if (ulozenie2 == 1)
				{
					do
					{
						if (ulozenie2 == 1)
						{
							uloz_plansze(plansza2);
							bool sprawdzacz2 = true;

							while (sprawdzacz2 == true)
							{
								int sprawdzam2[4] = { 0, 0, 0, 0 };
								for (int p = 0; p <= 9; p++)
								{
									for (int q = 0; q <= 9; q++)
									{
										if (plansza2[p][q] == 1)
											sprawdzam2[0] += 1;
										else if (plansza2[p][q] == 2)
											sprawdzam2[1] += 1;
										else if (plansza2[p][q] == 3)
											sprawdzam2[2] += 1;
										else if (plansza2[p][q] == 4)
											sprawdzam2[3] += 1;
									}
								}
								if (sprawdzam2[0] == 4 && sprawdzam2[1] == 6 && sprawdzam2[2] == 6 && sprawdzam2[3] == 4)
								{
									sprawdzacz2 = false;
								}
								else
									uloz_plansze(plansza2);
							}
						}
						do {
							kropki(plansza2);
							if (ulozenie2 != 1 && ulozenie2 != 0)
							{
								SetConsoleTextAttribute(hOut, FOREGROUND_RED);
								cout << "Dokonales zlego wyboru! Nie przechodz na ciemna strone mocy i wybierz wlasciwa cyfre!" << endl << endl;
								cin.clear();
								cin.ignore(100, '\n');
							}
							SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
							cout << "        " << endl << endl << "Jezeli chcesz rozlosowac jeszcze raz - wcisnij";
							SetConsoleTextAttribute(hOut, FOREGROUND_GREEN);
							cout << " [1]";
							SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
							cout << ", jezeli takie ulozenie ci odpowiada - wcisnij";
							SetConsoleTextAttribute(hOut, FOREGROUND_GREEN);
							cout << " [2]" << endl;
							SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
							cin >> ulozenie2;
							prawda = cin.good();
							sprawdzCin(prawda);
							if (prawda == 0) system("cls");
						} while (prawda == 0);

						system("cls");
						if (ulozenie2 == 2) zacznij_gre2 = true;
					} while (ulozenie2 != 2 && ulozenie2 != 0);
					system("cls");
					cin.ignore(100, '\n');
				}
				else if (ulozenie2 == 2)
				{
					recznieUloz(plansza2, zacznij_gre2);
					system("cls");

				}
			}
			start = clock();
			if (muzyka == true)
				PlaySound(L"wyciszenie.wav", NULL, SND_ASYNC);

			if (jedynka1_1 == false)
			{
				SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
				cout << "  " << kratka << "  ";
			}
			else
			{
				SetConsoleTextAttribute(hOut, FOREGROUND_RED);
				cout << "  " << kratka << "  ";
			}
			if (jedynka2_1 == false)
			{
				SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
				cout << kratka << "  ";
			}
			else
			{
				SetConsoleTextAttribute(hOut, FOREGROUND_RED);
				cout << kratka << "  ";
			}
			if (jedynka3_1 == false)
			{
				SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
				cout << kratka << "  ";
			}
			else
			{
				SetConsoleTextAttribute(hOut, FOREGROUND_RED);
				cout << kratka << "  ";
			}
			if (jedynka4_1 == false)
			{
				SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
				cout << kratka;
			}
			else
			{
				SetConsoleTextAttribute(hOut, FOREGROUND_RED);
				cout << kratka;
			}

			spacje(96);

			if (jedynka1_2 == false)
			{
				SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
				cout << kratka << "  ";
			}
			else
			{
				SetConsoleTextAttribute(hOut, FOREGROUND_RED);
				cout << kratka << "  ";
			}
			if (jedynka2_2 == false)
			{
				SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
				cout << kratka << "  ";
			}
			else
			{
				SetConsoleTextAttribute(hOut, FOREGROUND_RED);
				cout << kratka << "  ";
			}
			if (jedynka3_2 == false)
			{
				SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
				cout << kratka << "  ";
			}
			else
			{
				SetConsoleTextAttribute(hOut, FOREGROUND_RED);
				cout << kratka << "  ";
			}
			if (jedynka4_2 == false)
			{
				SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
				cout << kratka;
			}
			else
			{
				SetConsoleTextAttribute(hOut, FOREGROUND_RED);
				cout << kratka;
			}
			cout << endl;
			if (dwojka1_1 == false)
			{
				SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
				cout << "  " << kratka << kratka << "  ";
			}
			else
			{
				SetConsoleTextAttribute(hOut, FOREGROUND_RED);
				cout << kratka << kratka << "  ";
			}
			if (dwojka2_1 == false)
			{
				SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
				cout << kratka << kratka << "  ";
			}
			else
			{
				SetConsoleTextAttribute(hOut, FOREGROUND_RED);
				cout << kratka << kratka << "  ";
			}
			if (dwojka3_1 == false)
			{
				SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
				cout << kratka << kratka;
			}
			else
			{
				SetConsoleTextAttribute(hOut, FOREGROUND_RED);
				cout << kratka << kratka;
			}

			spacje(96);

			if (dwojka1_2 == false)
			{
				SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
				cout << kratka << kratka << "  ";
			}
			else
			{
				SetConsoleTextAttribute(hOut, FOREGROUND_RED);
				cout << kratka << kratka << "  ";
			}
			if (dwojka2_2 == false)
			{
				SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
				cout << kratka << kratka << "  ";
			}
			else
			{
				SetConsoleTextAttribute(hOut, FOREGROUND_RED);
				cout << kratka << kratka << "  ";
			}
			if (dwojka3_2 == false)
			{
				SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
				cout << kratka << kratka;
			}
			else
			{
				SetConsoleTextAttribute(hOut, FOREGROUND_RED);
				cout << kratka;
			}
			cout << endl;

			if (trojka1_1 == false)
			{
				SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
				cout << "  " << kratka << kratka << kratka << "  ";
			}
			else
			{
				SetConsoleTextAttribute(hOut, FOREGROUND_RED);
				cout << kratka << kratka << kratka << "  ";
			}
			if (trojka2_1 == false)
			{
				SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
				cout << kratka << kratka << kratka;
			}
			else
			{
				SetConsoleTextAttribute(hOut, FOREGROUND_RED);
				cout << kratka << kratka << kratka;
			}
			bool kolejGracza1;
			int ktoZaczyna = ktoZaczyna1(generator);
			if (ktoZaczyna == 0)
			{
				SetConsoleTextAttribute(hOut, FOREGROUND_BLUE);
				spacje(((120 - (dl_imie1 + 26)) / 2) - 10);

				cout << imie1 << ", to twoja tura! Strzelaj!";
				kolejGracza1 = true;
				if ((imie1.length() % 2) == 1)
					spacje(((120 - (dl_imie1 + 26)) / 2) - 11);
				else
					spacje(((120 - (dl_imie1 + 26)) / 2) - 10);
			}
			else
			{
				SetConsoleTextAttribute(hOut, FOREGROUND_BLUE | FOREGROUND_RED);
				spacje(((120 - (dl_imie2 + 26)) / 2) - 10);
				cout << imie2 << ", to twoja tura! Strzelaj!";
				kolejGracza1 = false;
				if ((imie2.length() % 2) == 1)
					spacje(((120 - (dl_imie2 + 26)) / 2) - 11);
				else
					spacje(((120 - (dl_imie2 + 26)) / 2) - 10);
			}

			if (trojka1_2 == false)
			{
				SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
				cout << kratka << kratka << kratka << "  ";
			}
			else
			{
				SetConsoleTextAttribute(hOut, FOREGROUND_RED);
				cout << kratka << kratka << kratka << "  ";
			}
			if (trojka2_2 == false)
			{
				SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
				cout << kratka << kratka << kratka;
			}
			else
			{
				SetConsoleTextAttribute(hOut, FOREGROUND_RED);
				cout << kratka << kratka << kratka;
			}
			cout << endl;

			if (czworka1_1 == false)
			{
				SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
				cout << "  " << kratka << kratka << kratka << kratka;
			}
			else
			{
				SetConsoleTextAttribute(hOut, FOREGROUND_RED);
				cout << kratka << kratka << kratka << kratka;
			}
			spacje(108);
			if (czworka1_2 == false)
			{
				SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
				cout << kratka << kratka << kratka << kratka;
			}
			else
			{
				SetConsoleTextAttribute(hOut, FOREGROUND_RED);
				cout << kratka << kratka << kratka << kratka;
			}

			cout << endl;

			SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
			spacje((60 - (dl_imie1 + 15)) / 2);
			cout << "Plansza gracza ";
			SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
			cout << imie1;
			SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
			spacje((45 - ((dl_imie1 + dl_imie2) / 2)));
			cout << "Plansza gracza ";
			SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
			cout << imie2;
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
			cout << "      " << kreska << "   ";
			for (char x = 65; x <= 74; x++)
			{
				SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
				cout << "    ";
				SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY | BACKGROUND_RED);
				cout << x;

			}
			SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY);


			cout << endl << "                                                           " << kreska << endl;
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
				cout << "      " << kreska << "   ";

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
					cout << kreska;
				cout << endl;
			}
			SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
			int czworka = 0;
			int czworka2 = 0;
			int graczw{};
			char graczkol{};
			int graczk{};
			bool koniec_gry = false;
			while (koniec_gry == false)
			{

				if (kolejGracza1 == true)
					cout << "  Podaj kolumne (A-J), a nastepnie wiersz(1-10): ";
				else
				{
					spacje(68);
					cout << "Podaj kolumne (A-J), a nastepnie wiersz(1-10): ";
				}

				cin >> graczkol;
				if (kolejGracza1 == true)
				{
					spacje(48);
				}
				else
				{
					spacje(107);
				}
				cin >> graczw;
				graczw = graczw - 1;
				if (graczkol >= 65 && graczkol <= 74)
				{
					graczk = static_cast<int>(graczkol);
					graczk = graczk - 65;
				}
				else if (graczkol >= 97 && graczkol <= 106)
				{
					graczk = static_cast<int>(graczkol);
					graczk = graczk - 97;
				}
				else
					graczk = static_cast<int>(graczkol);

				system("cls");


				if (kolejGracza1 == false)
				{
					if (graczw > 9 || graczk > 9 || graczw < 0 || graczk < 0)
					{
						if (jedynka1_1 == false)
						{
							SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
							cout << "  " << kratka << "  ";
						}
						else
						{
							SetConsoleTextAttribute(hOut, FOREGROUND_RED);
							cout << "  " << kratka << "  ";
						}
						if (jedynka2_1 == false)
						{
							SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
							cout << kratka << "  ";
						}
						else
						{
							SetConsoleTextAttribute(hOut, FOREGROUND_RED);
							cout << kratka << "  ";
						}
						if (jedynka3_1 == false)
						{
							SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
							cout << kratka << "  ";
						}
						else
						{
							SetConsoleTextAttribute(hOut, FOREGROUND_RED);
							cout << kratka << "  ";
						}
						if (jedynka4_1 == false)
						{
							SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
							cout << kratka;
						}
						else
						{
							SetConsoleTextAttribute(hOut, FOREGROUND_RED);
							cout << kratka;
						}
						SetConsoleTextAttribute(hOut, FOREGROUND_RED);
						spacje(5);
						cout << "Dokonales zlego wyboru! Nie przechodz na ciemna strone mocy i wybierz wlasciwa cyfre!";
						cin.clear();
						cin.ignore(100, '\n');
						spacje(6);
						SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
					}
					else if (plansza[graczw][graczk] == 5 || plansza[graczw][graczk] == 6)
					{
						if (jedynka1_1 == false)
						{
							SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
							cout << "  " << kratka << "  ";
						}
						else
						{
							SetConsoleTextAttribute(hOut, FOREGROUND_RED);
							cout << "  " << kratka << "  ";
						}
						if (jedynka2_1 == false)
						{
							SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
							cout << kratka << "  ";
						}
						else
						{
							SetConsoleTextAttribute(hOut, FOREGROUND_RED);
							cout << kratka << "  ";
						}
						if (jedynka3_1 == false)
						{
							SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
							cout << kratka << "  ";
						}
						else
						{
							SetConsoleTextAttribute(hOut, FOREGROUND_RED);
							cout << kratka << "  ";
						}
						if (jedynka4_1 == false)
						{
							SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
							cout << kratka;
						}
						else
						{
							SetConsoleTextAttribute(hOut, FOREGROUND_RED);
							cout << kratka;
						}
						SetConsoleTextAttribute(hOut, FOREGROUND_RED);
						spacje(22);
						cout << "Przeciez juz tutaj strzelales! Sprobuj jeszcze raz.";
						spacje(23);
						SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
					}

					else
					{
						if (plansza[graczw][graczk] != 1)
						{
							if (jedynka1_1 == false)
							{
								SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
								cout << "  " << kratka << "  ";
							}
							else
							{
								SetConsoleTextAttribute(hOut, FOREGROUND_RED);
								cout << "  " << kratka << "  ";
							}
							if (jedynka2_1 == false)
							{
								SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
								cout << kratka << "  ";
							}
							else
							{
								SetConsoleTextAttribute(hOut, FOREGROUND_RED);
								cout << kratka << "  ";
							}
							if (jedynka3_1 == false)
							{
								SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
								cout << kratka << "  ";
							}
							else
							{
								SetConsoleTextAttribute(hOut, FOREGROUND_RED);
								cout << kratka << "  ";
							}
							if (jedynka4_1 == false)
							{
								SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
								cout << kratka;
							}
							else
							{
								SetConsoleTextAttribute(hOut, FOREGROUND_RED);
								cout << kratka;
							}
						}

						if (plansza[graczw][graczk] == -1 || plansza[graczw][graczk] == 0)
						{
							if (efekty == true)
								PlaySound(L"pusty.wav", NULL, SND_ASYNC);
							plansza[graczw][graczk] = 5;
							SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
							spacje(17);
							cout << "PUSTO ;c";
							spacje(71);
						}
						else if (plansza[graczw][graczk] == 1)
						{
							plansza[graczw][graczk] = 6;
							for (int a = 0; a < 3; a++)
							{
								for (int b = 0; b < 3; b++)
								{
									if (graczk - 1 + a >= 0 && graczk - 1 + a <= 9 && graczw - 1 + b >= 0 && graczw - 1 + b <= 9 && plansza[graczw - 1 + b][graczk - 1 + a] == -1)
										plansza[graczw - 1 + b][graczk - 1 + a] = 5;
								}
							}
							if (jedynka1_1 == false) jedynka1_1 = true;
							else if (jedynka1_1 == true && jedynka2_1 == false) jedynka2_1 = true;
							else if (jedynka1_1 == true && jedynka2_1 == true && jedynka3_1 == false) jedynka3_1 = true;
							else if (jedynka1_1 == true && jedynka2_1 == true && jedynka3_1 == true) jedynka4_1 = true;
							if (jedynka1_1 == false)
							{
								SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
								cout << "  " << kratka << "  ";
							}
							else
							{
								SetConsoleTextAttribute(hOut, FOREGROUND_RED);
								cout << "  " << kratka << "  ";
							}
							if (jedynka2_1 == false)
							{
								SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
								cout << kratka << "  ";
							}
							else
							{
								SetConsoleTextAttribute(hOut, FOREGROUND_RED);
								cout << kratka << "  ";
							}
							if (jedynka3_1 == false)
							{
								SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
								cout << kratka << "  ";
							}
							else
							{
								SetConsoleTextAttribute(hOut, FOREGROUND_RED);
								cout << kratka << "  ";
							}
							if (jedynka4_1 == false)
							{
								SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
								cout << kratka;
							}
							else
							{
								SetConsoleTextAttribute(hOut, FOREGROUND_RED);
								cout << kratka;
							}
							SetConsoleTextAttribute(hOut, FOREGROUND_GREEN);
							spacje(11);
							cout << "TRAFIONY, ZATOPIONY!";
							if (efekty == true)
								PlaySound(L"zatopiony.wav", NULL, SND_ASYNC);
							spacje(65);

						}
						else if (plansza[graczw][graczk] == 2)
						{
							plansza[graczw][graczk] = 6;

							if (plansza[graczw + 1][graczk] != 6 && plansza[graczw - 1][graczk] != 6 && plansza[graczw][graczk + 1] != 6 && plansza[graczw][graczk - 1] != 6)
							{

								SetConsoleTextAttribute(hOut, FOREGROUND_RED);
								spacje(17);
								cout << "TRAFIONY!";
								if (efekty == true)
									PlaySound(L"trafiony.wav", NULL, SND_ASYNC);
								spacje(70);
							}
							else if (plansza[graczw + 1][graczk] == 6)
							{
								for (int a = 0; a < 3; a++)
								{
									for (int b = 0; b < 4; b++)
									{
										if (graczk - 1 + a >= 0 && graczk - 1 + a <= 9 && graczw - 1 + b >= 0 && graczw - 1 + b <= 9 && plansza[graczw - 1 + b][graczk - 1 + a] == -1)
											plansza[graczw - 1 + b][graczk - 1 + a] = 5;
									}


								}

								SetConsoleTextAttribute(hOut, FOREGROUND_GREEN);
								spacje(11);
								cout << "TRAFIONY, ZATOPIONY!";
								if (efekty == true)
									PlaySound(L"zatopiony.wav", NULL, SND_ASYNC);
								spacje(65);
								if (dwojka1_1 == false) dwojka1_1 = true;
								else if (dwojka1_1 == true && dwojka2_1 == false) dwojka2_1 = true;
								else if (dwojka1_1 == true && dwojka2_1 == true) dwojka3_1 = true;

							}
							else if (plansza[graczw][graczk + 1] == 6)
							{
								for (int a = 0; a < 3; a++)
								{
									for (int b = 0; b < 4; b++)
									{
										if (graczw - 1 + a >= 0 && graczw - 1 + a <= 9 && graczk - 1 + b >= 0 && graczk - 1 + b <= 9 && plansza[graczw - 1 + a][graczk - 1 + b] == -1)
											plansza[graczw - 1 + a][graczk - 1 + b] = 5;
									}
								}

								SetConsoleTextAttribute(hOut, FOREGROUND_GREEN);
								spacje(11);
								cout << "TRAFIONY, ZATOPIONY!";
								if (efekty == true)
									PlaySound(L"zatopiony.wav", NULL, SND_ASYNC);
								spacje(65);
								if (dwojka1_1 == false) dwojka1_1 = true;
								else if (dwojka1_1 == true && dwojka2_1 == false) dwojka2_1 = true;
								else if (dwojka1_1 == true && dwojka2_1 == true) dwojka3_1 = true;
							}
							else if (plansza[graczw - 1][graczk] == 6)
							{
								for (int a = 0; a < 3; a++)
								{
									for (int b = 0; b < 4; b++)
									{
										if (graczk - 1 + a >= 0 && graczk - 1 + a <= 9 && graczw + 1 - b >= 0 && graczw + 1 - b <= 9 && plansza[graczw + 1 - b][graczk - 1 + a] == -1)
											plansza[graczw + 1 - b][graczk - 1 + a] = 5;
									}
								}

								SetConsoleTextAttribute(hOut, FOREGROUND_GREEN);
								spacje(11);
								cout << "TRAFIONY, ZATOPIONY!";
								if (efekty == true)
									PlaySound(L"zatopiony.wav", NULL, SND_ASYNC);
								spacje(65);
								if (dwojka1_1 == false) dwojka1_1 = true;
								else if (dwojka1_1 == true && dwojka2_1 == false) dwojka2_1 = true;
								else if (dwojka1_1 == true && dwojka2_1 == true) dwojka3_1 = true;
							}
							else if (plansza[graczw][graczk - 1] == 6)
							{
								for (int a = 0; a < 3; a++)
								{
									for (int b = 0; b < 4; b++)
									{
										if (graczw - 1 + a >= 0 && graczw - 1 + a <= 9 && graczk + 1 - b >= 0 && graczk + 1 - b <= 9 && plansza[graczw - 1 + a][graczk + 1 - b] == -1)
											plansza[graczw - 1 + a][graczk + 1 - b] = 5;
									}
								}

								SetConsoleTextAttribute(hOut, FOREGROUND_GREEN);
								spacje(11);
								cout << "TRAFIONY, ZATOPIONY!";
								if (efekty == true)
									PlaySound(L"zatopiony.wav", NULL, SND_ASYNC);
								spacje(65);
								if (dwojka1_1 == false) dwojka1_1 = true;
								else if (dwojka1_1 == true && dwojka2_1 == false) dwojka2_1 = true;
								else if (dwojka1_1 == true && dwojka2_1 == true) dwojka3_1 = true;
							}
						}
						else if (plansza[graczw][graczk] == 3)
						{
							plansza[graczw][graczk] = 6;

							if (plansza[graczw - 1][graczk] == 3 && plansza[graczw - 2][graczk] == 3)
							{

								SetConsoleTextAttribute(hOut, FOREGROUND_RED);
								spacje(17);
								cout << "TRAFIONY!";
								if (efekty == true)
									PlaySound(L"trafiony.wav", NULL, SND_ASYNC);
								spacje(70);
							}
							else if (plansza[graczw - 1][graczk] == 6 && plansza[graczw - 2][graczk] == 3)
							{

								SetConsoleTextAttribute(hOut, FOREGROUND_RED);
								spacje(17);
								cout << "TRAFIONY!";
								if (efekty == true)
									PlaySound(L"trafiony.wav", NULL, SND_ASYNC);
								spacje(70);
							}
							else if (plansza[graczw - 1][graczk] == 3 && plansza[graczw - 2][graczk] == 6)
							{

								SetConsoleTextAttribute(hOut, FOREGROUND_RED);
								spacje(17);
								cout << "TRAFIONY!";
								if (efekty == true)
									PlaySound(L"trafiony.wav", NULL, SND_ASYNC);
								spacje(70);
							}
							else if (plansza[graczw - 1][graczk] == 6 && plansza[graczw - 2][graczk] == 6)
							{
								for (int a = 0; a < 3; a++)
								{
									for (int b = 0; b < 5; b++)
									{
										if (graczk - 1 + a >= 0 && graczk - 1 + a <= 9 && graczw + 1 - b >= 0 && graczw + 1 - b <= 9 && plansza[graczw + 1 - b][graczk - 1 + a] == -1)
											plansza[graczw + 1 - b][graczk - 1 + a] = 5;
									}


								}

								SetConsoleTextAttribute(hOut, FOREGROUND_GREEN);
								spacje(11);
								cout << "TRAFIONY, ZATOPIONY!";
								if (efekty == true)
									PlaySound(L"zatopiony.wav", NULL, SND_ASYNC);
								spacje(65);
								if (trojka1_1 == false) trojka1_1 = true;
								else if (trojka1_1 == true) trojka2_1 = true;
							}

							else if (plansza[graczw - 1][graczk] == 3 && plansza[graczw + 1][graczk] == 3)
							{

								SetConsoleTextAttribute(hOut, FOREGROUND_RED);
								spacje(17);
								cout << "TRAFIONY!";
								if (efekty == true)
									PlaySound(L"trafiony.wav", NULL, SND_ASYNC);
								spacje(70);
							}
							else if (plansza[graczw - 1][graczk] == 6 && plansza[graczw + 1][graczk] == 3)
							{

								SetConsoleTextAttribute(hOut, FOREGROUND_RED);
								spacje(17);
								cout << "TRAFIONY!";
								if (efekty == true)
									PlaySound(L"trafiony.wav", NULL, SND_ASYNC);
								spacje(70);
							}
							else if (plansza[graczw - 1][graczk] == 3 && plansza[graczw + 1][graczk] == 6)
							{

								SetConsoleTextAttribute(hOut, FOREGROUND_RED);
								spacje(17);
								cout << "TRAFIONY!";
								if (efekty == true)
									PlaySound(L"trafiony.wav", NULL, SND_ASYNC);
								spacje(70);
							}
							else if (plansza[graczw - 1][graczk] == 6 && plansza[graczw + 1][graczk] == 6)
							{
								for (int a = 0; a < 3; a++)
								{
									for (int b = 0; b < 5; b++)
									{
										if (graczk - 1 + a >= 0 && graczk - 1 + a <= 9 && graczw + 2 - b >= 0 && graczw + 2 - b <= 9 && plansza[graczw + 2 - b][graczk - 1 + a] == -1)
											plansza[graczw + 2 - b][graczk - 1 + a] = 5;
									}


								}

								SetConsoleTextAttribute(hOut, FOREGROUND_GREEN);
								spacje(11);
								cout << "TRAFIONY, ZATOPIONY!";
								if (efekty == true)
									PlaySound(L"zatopiony.wav", NULL, SND_ASYNC);
								spacje(65);
								if (trojka1_1 == false) trojka1_1 = true;
								else if (trojka1_1 == true) trojka2_1 = true;
							}
							else if (plansza[graczw + 1][graczk] == 3 && plansza[graczw + 2][graczk] == 3)
							{

								SetConsoleTextAttribute(hOut, FOREGROUND_RED);
								spacje(17);
								cout << "TRAFIONY!";
								if (efekty == true)
									PlaySound(L"trafiony.wav", NULL, SND_ASYNC);
								spacje(70);
							}
							else if (plansza[graczw + 1][graczk] == 6 && plansza[graczw + 2][graczk] == 3)
							{

								SetConsoleTextAttribute(hOut, FOREGROUND_RED);
								spacje(17);
								cout << "TRAFIONY!";
								if (efekty == true)
									PlaySound(L"trafiony.wav", NULL, SND_ASYNC);
								spacje(70);
							}
							else if (plansza[graczw + 1][graczk] == 3 && plansza[graczw + 2][graczk] == 6)
							{

								SetConsoleTextAttribute(hOut, FOREGROUND_RED);
								spacje(17);
								cout << "TRAFIONY!";
								if (efekty == true)
									PlaySound(L"trafiony.wav", NULL, SND_ASYNC);
								spacje(70);
							}
							else if (plansza[graczw + 1][graczk] == 6 && plansza[graczw + 2][graczk] == 6)
							{
								for (int a = 0; a < 3; a++)
								{
									for (int b = 0; b < 5; b++)
									{
										if (graczk - 1 + a >= 0 && graczk - 1 + a <= 9 && graczw - 1 + b >= 0 && graczw - 1 + b <= 9 && plansza[graczw - 1 + b][graczk - 1 + a] == -1)
											plansza[graczw - 1 + b][graczk - 1 + a] = 5;
									}


								}

								SetConsoleTextAttribute(hOut, FOREGROUND_GREEN);
								spacje(11);
								cout << "TRAFIONY, ZATOPIONY!";
								if (efekty == true)
									PlaySound(L"zatopiony.wav", NULL, SND_ASYNC);
								spacje(65);
								if (trojka1_1 == false) trojka1_1 = true;
								else if (trojka1_1 == true) trojka2_1 = true;
							}

							else if (plansza[graczw][graczk + 1] == 3 && plansza[graczw][graczk + 2] == 3)
							{

								SetConsoleTextAttribute(hOut, FOREGROUND_RED);
								spacje(17);
								cout << "TRAFIONY!";
								if (efekty == true)
									PlaySound(L"trafiony.wav", NULL, SND_ASYNC);
								spacje(70);
							}
							else if (plansza[graczw][graczk + 1] == 6 && plansza[graczw][graczk + 2] == 3)
							{

								SetConsoleTextAttribute(hOut, FOREGROUND_RED);
								spacje(17);
								cout << "TRAFIONY!";
								if (efekty == true)
									PlaySound(L"trafiony.wav", NULL, SND_ASYNC);
								spacje(70);
							}
							else if (plansza[graczw][graczk + 1] == 3 && plansza[graczw][graczk + 2] == 6)
							{

								SetConsoleTextAttribute(hOut, FOREGROUND_RED);
								spacje(17);
								cout << "TRAFIONY!";
								if (efekty == true)
									PlaySound(L"trafiony.wav", NULL, SND_ASYNC);
								spacje(70);
							}
							else if (plansza[graczw][graczk + 1] == 6 && plansza[graczw][graczk + 2] == 6)
							{
								for (int a = 0; a < 3; a++)
								{
									for (int b = 0; b < 5; b++)
									{
										if (graczk - 1 + b >= 0 && graczk - 1 + b <= 9 && graczw - 1 + a >= 0 && graczw - 1 + a <= 9 && plansza[graczw - 1 + a][graczk - 1 + b] == -1)
											plansza[graczw - 1 + a][graczk - 1 + b] = 5;
									}
								}

								SetConsoleTextAttribute(hOut, FOREGROUND_GREEN);
								spacje(11);
								cout << "TRAFIONY, ZATOPIONY!";
								if (efekty == true)
									PlaySound(L"zatopiony.wav", NULL, SND_ASYNC);
								spacje(65);
								if (trojka1_1 == false) trojka1_1 = true;
								else if (trojka1_1 == true) trojka2_1 = true;
							}

							else if (plansza[graczw][graczk - 1] == 3 && plansza[graczw][graczk + 1] == 3)
							{

								SetConsoleTextAttribute(hOut, FOREGROUND_RED);
								spacje(17);
								cout << "TRAFIONY!";
								if (efekty == true)
									PlaySound(L"trafiony.wav", NULL, SND_ASYNC);
								spacje(70);
							}
							else if (plansza[graczw][graczk - 1] == 6 && plansza[graczw][graczk + 1] == 3)
							{

								SetConsoleTextAttribute(hOut, FOREGROUND_RED);
								spacje(17);
								cout << "TRAFIONY!";
								if (efekty == true)
									PlaySound(L"trafiony.wav", NULL, SND_ASYNC);
								spacje(70);
							}
							else if (plansza[graczw][graczk - 1] == 3 && plansza[graczw][graczk + 1] == 6)
							{

								SetConsoleTextAttribute(hOut, FOREGROUND_RED);
								spacje(17);
								cout << "TRAFIONY!";
								if (efekty == true)
									PlaySound(L"trafiony.wav", NULL, SND_ASYNC);
								spacje(70);
							}
							else if (plansza[graczw][graczk - 1] == 6 && plansza[graczw][graczk + 1] == 6)
							{
								for (int a = 0; a < 3; a++)
								{
									for (int b = 0; b < 5; b++)
									{
										if (graczk - 2 + b >= 0 && graczk - 2 + b <= 9 && graczw - 1 + a >= 0 && graczw - 1 + a <= 9 && plansza[graczw - 1 + a][graczk - 2 + b] == -1)
											plansza[graczw - 1 + a][graczk - 2 + b] = 5;
									}
								}

								SetConsoleTextAttribute(hOut, FOREGROUND_GREEN);
								spacje(11);
								cout << "TRAFIONY, ZATOPIONY!";
								if (efekty == true)
									PlaySound(L"zatopiony.wav", NULL, SND_ASYNC);
								spacje(65);
								if (trojka1_1 == false) trojka1_1 = true;
								else if (trojka1_1 == true) trojka2_1 = true;
							}
							else if (plansza[graczw][graczk - 1] == 3 && plansza[graczw][graczk - 2] == 3)
							{

								SetConsoleTextAttribute(hOut, FOREGROUND_RED);
								spacje(17);
								cout << "TRAFIONY!";
								if (efekty == true)
									PlaySound(L"trafiony.wav", NULL, SND_ASYNC);
								spacje(70);
							}
							else if (plansza[graczw][graczk - 1] == 6 && plansza[graczw][graczk - 2] == 3)
							{

								SetConsoleTextAttribute(hOut, FOREGROUND_RED);
								spacje(17);
								cout << "TRAFIONY!";
								if (efekty == true)
									PlaySound(L"trafiony.wav", NULL, SND_ASYNC);
								spacje(70);
							}
							else if (plansza[graczw][graczk - 1] == 3 && plansza[graczw][graczk - 2] == 6)
							{

								SetConsoleTextAttribute(hOut, FOREGROUND_RED);
								spacje(17);
								cout << "TRAFIONY!";
								if (efekty == true)
									PlaySound(L"trafiony.wav", NULL, SND_ASYNC);
								spacje(70);
							}
							else if (plansza[graczw][graczk - 1] == 6 && plansza[graczw][graczk - 2] == 6)
							{
								for (int a = 0; a < 3; a++)
								{
									for (int b = 0; b < 5; b++)
									{
										if (graczk - 3 + b >= 0 && graczk - 3 + b <= 9 && graczw - 1 + a >= 0 && graczw - 1 + a <= 9 && plansza[graczw - 1 + a][graczk - 3 + b] == -1)
											plansza[graczw - 1 + a][graczk - 3 + b] = 5;
									}
								}

								SetConsoleTextAttribute(hOut, FOREGROUND_GREEN);
								spacje(11);
								cout << "TRAFIONY, ZATOPIONY!";
								if (efekty == true)
									PlaySound(L"zatopiony.wav", NULL, SND_ASYNC);
								spacje(65);
								if (trojka1_1 == false) trojka1_1 = true;
								else if (trojka1_1 == true) trojka2_1 = true;
							}

						}
						else if (plansza[graczw][graczk] == 4)
						{
							plansza[graczw][graczk] = 6;
							czworka++;
							if (czworka != 4)
							{

								SetConsoleTextAttribute(hOut, FOREGROUND_RED);
								spacje(17);
								cout << "TRAFIONY!";
								if (efekty == true)
									PlaySound(L"trafiony.wav", NULL, SND_ASYNC);
								spacje(70);
							}
							else if (czworka == 4)
							{
								if (plansza[graczw][graczk + 1] == 6 && plansza[graczw][graczk + 2] == 6 && plansza[graczw][graczk + 3] == 6)
								{
									for (int a = 0; a < 3; a++)
									{
										for (int b = 0; b < 6; b++)
										{
											if (graczw - 1 + a >= 0 && graczw - 1 + a <= 9 && graczk - 1 + b >= 0 && graczk - 1 + b <= 9 && plansza[graczw - 1 + a][graczk - 1 + b] == -1)
												plansza[graczw - 1 + a][graczk - 1 + b] = 5;
										}
									}

									SetConsoleTextAttribute(hOut, FOREGROUND_GREEN);
									spacje(11);
									cout << "TRAFIONY, ZATOPIONY!";
									if (efekty == true)
										PlaySound(L"zatopiony.wav", NULL, SND_ASYNC);
									spacje(65);
									czworka1_1 = true;
								}
								else if (plansza[graczw][graczk - 1] == 6 && plansza[graczw][graczk + 1] == 6 && plansza[graczw][graczk + 2] == 6)
								{
									for (int a = 0; a < 3; a++)
									{
										for (int b = 0; b < 6; b++)
										{
											if (graczw - 1 + a >= 0 && graczw - 1 + a <= 9 && graczk - 2 + b >= 0 && graczk - 2 + b <= 9 && plansza[graczw - 1 + a][graczk - 2 + b] == -1)
												plansza[graczw - 1 + a][graczk - 2 + b] = 5;
										}
									}

									SetConsoleTextAttribute(hOut, FOREGROUND_GREEN);
									spacje(11);
									cout << "TRAFIONY, ZATOPIONY!";
									if (efekty == true)
										PlaySound(L"zatopiony.wav", NULL, SND_ASYNC);
									spacje(65);
									czworka1_1 = true;
								}
								else if (plansza[graczw][graczk - 1] == 6 && plansza[graczw][graczk - 2] == 6 && plansza[graczw][graczk - 3] == 6)
								{
									for (int a = 0; a < 3; a++)
									{
										for (int b = 0; b < 6; b++)
										{
											if (graczw - 1 + a >= 0 && graczw - 1 + a <= 9 && graczk + 1 - b >= 0 && graczk + 1 - b <= 9 && plansza[graczw - 1 + a][graczk + 1 - b] == -1)
												plansza[graczw - 1 + a][graczk + 1 - b] = 5;
										}
									}

									SetConsoleTextAttribute(hOut, FOREGROUND_GREEN);
									spacje(11);
									cout << "TRAFIONY, ZATOPIONY!";
									if (efekty == true)
										PlaySound(L"zatopiony.wav", NULL, SND_ASYNC);
									spacje(65);
									czworka1_1 = true;
								}
								else if (plansza[graczw][graczk - 1] == 6 && plansza[graczw][graczk + 1] == 6 && plansza[graczw][graczk - 2] == 6)
								{
									for (int a = 0; a < 3; a++)
									{
										for (int b = 0; b < 6; b++)
										{
											if (graczw - 1 + a >= 0 && graczw - 1 + a <= 9 && graczk + 2 - b >= 0 && graczk + 2 - b <= 9 && plansza[graczw - 1 + a][graczk + 2 - b] == -1)
												plansza[graczw - 1 + a][graczk + 2 - b] = 5;
										}
									}

									SetConsoleTextAttribute(hOut, FOREGROUND_GREEN);
									spacje(11);
									cout << "TRAFIONY, ZATOPIONY!";
									if (efekty == true)
										PlaySound(L"zatopiony.wav", NULL, SND_ASYNC);
									spacje(65);
									czworka1_1 = true;
								}
								else if (plansza[graczw + 1][graczk] == 6 && plansza[graczw + 2][graczk] == 6 && plansza[graczw + 3][graczk] == 6)
								{
									for (int a = 0; a < 3; a++)
									{
										for (int b = 0; b < 6; b++)
										{
											if (graczk - 1 + a >= 0 && graczk - 1 + a <= 9 && graczw - 1 + b >= 0 && graczw - 1 + b <= 9 && plansza[graczw - 1 + b][graczk - 1 + a] == -1)
												plansza[graczw - 1 + b][graczk - 1 + a] = 5;
										}
									}

									SetConsoleTextAttribute(hOut, FOREGROUND_GREEN);
									spacje(11);
									cout << "TRAFIONY, ZATOPIONY!";
									if (efekty == true)
										PlaySound(L"zatopiony.wav", NULL, SND_ASYNC);
									spacje(65);
									czworka1_1 = true;
								}
								else if (plansza[graczw + 1][graczk] == 6 && plansza[graczw - 1][graczk] == 6 && plansza[graczw + 2][graczk] == 6)
								{
									for (int a = 0; a < 3; a++)
									{
										for (int b = 0; b < 6; b++)
										{
											if (graczk - 1 + a >= 0 && graczk - 1 + a <= 9 && graczw - 2 + b >= 0 && graczw - 2 + b <= 9 && plansza[graczw - 2 + b][graczk - 1 + a] == -1)
												plansza[graczw - 2 + b][graczk - 1 + a] = 5;
										}
									}

									SetConsoleTextAttribute(hOut, FOREGROUND_GREEN);
									spacje(11);
									cout << "TRAFIONY, ZATOPIONY!";
									if (efekty == true)
										PlaySound(L"zatopiony.wav", NULL, SND_ASYNC);
									spacje(65);
									czworka1_1 = true;
								}
								else if (plansza[graczw - 1][graczk] == 6 && plansza[graczw - 2][graczk] == 6 && plansza[graczw - 3][graczk] == 6)
								{
									for (int a = 0; a < 3; a++)
									{
										for (int b = 0; b < 6; b++)
										{
											if (graczk - 1 + a >= 0 && graczk - 1 + a <= 9 && graczw + 1 - b >= 0 && graczw + 1 - b <= 9 && plansza[graczw + 1 - b][graczk - 1 + a] == -1)
												plansza[graczw + 1 - b][graczk - 1 + a] = 5;
										}
									}

									SetConsoleTextAttribute(hOut, FOREGROUND_GREEN);
									spacje(11);
									cout << "TRAFIONY, ZATOPIONY!";
									if (efekty == true)
										PlaySound(L"zatopiony.wav", NULL, SND_ASYNC);
									spacje(65);
									czworka1_1 = true;
								}
								else if (plansza[graczw + 1][graczk] == 6 && plansza[graczw - 1][graczk] == 6 && plansza[graczw - 2][graczk] == 6)
								{
									for (int a = 0; a < 3; a++)
									{
										for (int b = 0; b < 6; b++)
										{
											if (graczk - 1 + a >= 0 && graczk - 1 + a <= 9 && graczw + 2 - b >= 0 && graczw + 2 - b <= 9 && plansza[graczw + 2 - b][graczk - 1 + a] == -1)
												plansza[graczw + 2 - b][graczk - 1 + a] = 5;
										}
									}

									SetConsoleTextAttribute(hOut, FOREGROUND_GREEN);
									spacje(11);
									cout << "TRAFIONY, ZATOPIONY!";
									if (efekty == true)
										PlaySound(L"zatopiony.wav", NULL, SND_ASYNC);
									spacje(65);
									czworka1_1 = true;
								}
							}
						}
						if (plansza[graczw][graczk] == 6)
							kolejGracza1 = false;
						else
							kolejGracza1 = true;

					}

				}
				else
				{
					if (graczw > 9 || graczk > 9 || graczw < 0 || graczk < 0)
					{
						if (jedynka1_1 == false)
						{
							SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
							cout << "  " << kratka << "  ";
						}
						else
						{
							SetConsoleTextAttribute(hOut, FOREGROUND_RED);
							cout << "  " << kratka << "  ";
						}
						if (jedynka2_1 == false)
						{
							SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
							cout << kratka << "  ";
						}
						else
						{
							SetConsoleTextAttribute(hOut, FOREGROUND_RED);
							cout << kratka << "  ";
						}
						if (jedynka3_1 == false)
						{
							SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
							cout << kratka << "  ";
						}
						else
						{
							SetConsoleTextAttribute(hOut, FOREGROUND_RED);
							cout << kratka << "  ";
						}
						if (jedynka4_1 == false)
						{
							SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
							cout << kratka;
						}
						else
						{
							SetConsoleTextAttribute(hOut, FOREGROUND_RED);
							cout << kratka;
						}
						SetConsoleTextAttribute(hOut, FOREGROUND_RED);
						spacje(5);
						cout << "Dokonales zlego wyboru! Nie przechodz na ciemna strone mocy i wybierz wlasciwa cyfre!";
						cin.clear();
						cin.ignore(100, '\n');
						spacje(6);
						SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
					}
					else if (plansza2[graczw][graczk] == 5 || plansza2[graczw][graczk] == 6)
					{
						if (jedynka1_1 == false)
						{
							SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
							cout << "  " << kratka << "  ";
						}
						else
						{
							SetConsoleTextAttribute(hOut, FOREGROUND_RED);
							cout << "  " << kratka << "  ";
						}
						if (jedynka2_1 == false)
						{
							SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
							cout << kratka << "  ";
						}
						else
						{
							SetConsoleTextAttribute(hOut, FOREGROUND_RED);
							cout << kratka << "  ";
						}
						if (jedynka3_1 == false)
						{
							SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
							cout << kratka << "  ";
						}
						else
						{
							SetConsoleTextAttribute(hOut, FOREGROUND_RED);
							cout << kratka << "  ";
						}
						if (jedynka4_1 == false)
						{
							SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
							cout << kratka;
						}
						else
						{
							SetConsoleTextAttribute(hOut, FOREGROUND_RED);
							cout << kratka;
						}
						SetConsoleTextAttribute(hOut, FOREGROUND_RED);
						spacje(22);
						cout << "Przeciez juz tutaj strzelales! Sprobuj jeszcze raz.";
						spacje(23);
						SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
					}

					else
					{
						if (jedynka1_1 == false)
						{
							SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
							cout << "  " << kratka << "  ";
						}
						else
						{
							SetConsoleTextAttribute(hOut, FOREGROUND_RED);
							cout << "  " << kratka << "  ";
						}
						if (jedynka2_1 == false)
						{
							SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
							cout << kratka << "  ";
						}
						else
						{
							SetConsoleTextAttribute(hOut, FOREGROUND_RED);
							cout << kratka << "  ";
						}
						if (jedynka3_1 == false)
						{
							SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
							cout << kratka << "  ";
						}
						else
						{
							SetConsoleTextAttribute(hOut, FOREGROUND_RED);
							cout << kratka << "  ";
						}
						if (jedynka4_1 == false)
						{
							SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
							cout << kratka;
						}
						else
						{
							SetConsoleTextAttribute(hOut, FOREGROUND_RED);
							cout << kratka;
						}
						if (plansza2[graczw][graczk] == -1 || plansza2[graczw][graczk] == 0)
						{
							if (efekty == true)
								PlaySound(L"pusty.wav", NULL, SND_ASYNC);
							plansza2[graczw][graczk] = 5;

							SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
							spacje(77);
							cout << "PUSTO ;c";
							spacje(11);
						}
						else if (plansza2[graczw][graczk] == 1)
						{
							plansza2[graczw][graczk] = 6;
							for (int a = 0; a < 3; a++)
							{
								for (int b = 0; b < 3; b++)
								{
									if (graczk - 1 + a >= 0 && graczk - 1 + a <= 9 && graczw - 1 + b >= 0 && graczw - 1 + b <= 9 && plansza2[graczw - 1 + b][graczk - 1 + a] == -1)
										plansza2[graczw - 1 + b][graczk - 1 + a] = 5;
								}
							}

							SetConsoleTextAttribute(hOut, FOREGROUND_GREEN);
							spacje(71);
							cout << "TRAFIONY, ZATOPIONY!";
							if (efekty == true)
								PlaySound(L"zatopiony.wav", NULL, SND_ASYNC);
							spacje(5);
							if (jedynka1_2 == false) jedynka1_2 = true;
							else if (jedynka1_2 == true && jedynka2_2 == false) jedynka2_2 = true;
							else if (jedynka1_2 == true && jedynka2_2 == true && jedynka3_2 == false) jedynka3_2 = true;
							else if (jedynka1_2 == true && jedynka2_2 == true && jedynka3_2 == true) jedynka4_2 = true;
						}
						else if (plansza2[graczw][graczk] == 2)
						{
							plansza2[graczw][graczk] = 6;

							if (plansza2[graczw + 1][graczk] != 6 && plansza2[graczw - 1][graczk] != 6 && plansza2[graczw][graczk + 1] != 6 && plansza2[graczw][graczk - 1] != 6)
							{

								SetConsoleTextAttribute(hOut, FOREGROUND_RED);
								spacje(77);
								cout << "TRAFIONY!";
								if (efekty == true)
									PlaySound(L"trafiony.wav", NULL, SND_ASYNC);
								spacje(10);
							}
							else if (plansza2[graczw + 1][graczk] == 6)
							{
								for (int a = 0; a < 3; a++)
								{
									for (int b = 0; b < 4; b++)
									{
										if (graczk - 1 + a >= 0 && graczk - 1 + a <= 9 && graczw - 1 + b >= 0 && graczw - 1 + b <= 9 && plansza2[graczw - 1 + b][graczk - 1 + a] == -1)
											plansza2[graczw - 1 + b][graczk - 1 + a] = 5;
									}


								}

								SetConsoleTextAttribute(hOut, FOREGROUND_GREEN);
								spacje(71);
								cout << "TRAFIONY, ZATOPIONY!";
								if (efekty == true)
									PlaySound(L"zatopiony.wav", NULL, SND_ASYNC);
								spacje(5);
								if (dwojka1_2 == false) dwojka1_2 = true;
								else if (dwojka1_2 == true && dwojka2_2 == false) dwojka2_2 = true;
								else if (dwojka1_2 == true && dwojka2_2 == true) dwojka3_2 = true;
							}
							else if (plansza2[graczw][graczk + 1] == 6)
							{
								for (int a = 0; a < 3; a++)
								{
									for (int b = 0; b < 4; b++)
									{
										if (graczw - 1 + a >= 0 && graczw - 1 + a <= 9 && graczk - 1 + b >= 0 && graczk - 1 + b <= 9 && plansza2[graczw - 1 + a][graczk - 1 + b] == -1)
											plansza2[graczw - 1 + a][graczk - 1 + b] = 5;
									}
								}

								SetConsoleTextAttribute(hOut, FOREGROUND_GREEN);
								spacje(71);
								cout << "TRAFIONY, ZATOPIONY!";
								if (efekty == true)
									PlaySound(L"zatopiony.wav", NULL, SND_ASYNC);
								spacje(5);
								if (dwojka1_2 == false) dwojka1_2 = true;
								else if (dwojka1_2 == true && dwojka2_2 == false) dwojka2_2 = true;
								else if (dwojka1_2 == true && dwojka2_2 == true) dwojka3_2 = true;
							}
							else if (plansza2[graczw - 1][graczk] == 6)
							{
								for (int a = 0; a < 3; a++)
								{
									for (int b = 0; b < 4; b++)
									{
										if (graczk - 1 + a >= 0 && graczk - 1 + a <= 9 && graczw + 1 - b >= 0 && graczw + 1 - b <= 9 && plansza2[graczw + 1 - b][graczk - 1 + a] == -1)
											plansza2[graczw + 1 - b][graczk - 1 + a] = 5;
									}
								}

								SetConsoleTextAttribute(hOut, FOREGROUND_GREEN);
								spacje(71);
								cout << "TRAFIONY, ZATOPIONY!";
								if (efekty == true)
									PlaySound(L"zatopiony.wav", NULL, SND_ASYNC);
								spacje(5);
								if (dwojka1_2 == false) dwojka1_2 = true;
								else if (dwojka1_2 == true && dwojka2_2 == false) dwojka2_2 = true;
								else if (dwojka1_2 == true && dwojka2_2 == true) dwojka3_2 = true;
							}
							else if (plansza2[graczw][graczk - 1] == 6)
							{
								for (int a = 0; a < 3; a++)
								{
									for (int b = 0; b < 4; b++)
									{
										if (graczw - 1 + a >= 0 && graczw - 1 + a <= 9 && graczk + 1 - b >= 0 && graczk + 1 - b <= 9 && plansza2[graczw - 1 + a][graczk + 1 - b] == -1)
											plansza2[graczw - 1 + a][graczk + 1 - b] = 5;
									}
								}

								SetConsoleTextAttribute(hOut, FOREGROUND_GREEN);
								spacje(71);
								cout << "TRAFIONY, ZATOPIONY!";
								if (efekty == true)
									PlaySound(L"zatopiony.wav", NULL, SND_ASYNC);
								spacje(5);
								if (dwojka1_2 == false) dwojka1_2 = true;
								else if (dwojka1_2 == true && dwojka2_2 == false) dwojka2_2 = true;
								else if (dwojka1_2 == true && dwojka2_2 == true) dwojka3_2 = true;
							}
						}
						else if (plansza2[graczw][graczk] == 3)
						{
							plansza2[graczw][graczk] = 6;

							if (plansza2[graczw - 1][graczk] == 3 && plansza2[graczw - 2][graczk] == 3)
							{

								SetConsoleTextAttribute(hOut, FOREGROUND_RED);
								spacje(77);
								cout << "TRAFIONY!";
								if (efekty == true)
									PlaySound(L"trafiony.wav", NULL, SND_ASYNC);
								spacje(10);
							}
							else if (plansza2[graczw - 1][graczk] == 6 && plansza2[graczw - 2][graczk] == 3)
							{

								SetConsoleTextAttribute(hOut, FOREGROUND_RED);
								spacje(77);
								cout << "TRAFIONY!";
								if (efekty == true)
									PlaySound(L"trafiony.wav", NULL, SND_ASYNC);
								spacje(10);
							}
							else if (plansza2[graczw - 1][graczk] == 3 && plansza2[graczw - 2][graczk] == 6)
							{

								SetConsoleTextAttribute(hOut, FOREGROUND_RED);
								spacje(77);
								cout << "TRAFIONY!";
								if (efekty == true)
									PlaySound(L"trafiony.wav", NULL, SND_ASYNC);
								spacje(10);
							}
							else if (plansza2[graczw - 1][graczk] == 6 && plansza2[graczw - 2][graczk] == 6)
							{
								for (int a = 0; a < 3; a++)
								{
									for (int b = 0; b < 5; b++)
									{
										if (graczk - 1 + a >= 0 && graczk - 1 + a <= 9 && graczw + 1 - b >= 0 && graczw + 1 - b <= 9 && plansza2[graczw + 1 - b][graczk - 1 + a] == -1)
											plansza2[graczw + 1 - b][graczk - 1 + a] = 5;
									}


								}

								SetConsoleTextAttribute(hOut, FOREGROUND_GREEN);
								spacje(71);
								cout << "TRAFIONY, ZATOPIONY!";
								if (efekty == true)
									PlaySound(L"zatopiony.wav", NULL, SND_ASYNC);
								spacje(5);
								if (trojka1_2 == false) trojka1_2 = true;
								else if (trojka1_2 == true) trojka2_2 = true;

							}

							else if (plansza2[graczw - 1][graczk] == 3 && plansza2[graczw + 1][graczk] == 3)
							{

								SetConsoleTextAttribute(hOut, FOREGROUND_RED);
								spacje(77);
								cout << "TRAFIONY!";
								if (efekty == true)
									PlaySound(L"trafiony.wav", NULL, SND_ASYNC);
								spacje(10);
							}
							else if (plansza2[graczw - 1][graczk] == 6 && plansza2[graczw + 1][graczk] == 3)
							{

								SetConsoleTextAttribute(hOut, FOREGROUND_RED);
								spacje(77);
								cout << "TRAFIONY!";
								if (efekty == true)
									PlaySound(L"trafiony.wav", NULL, SND_ASYNC);
								spacje(10);
							}
							else if (plansza2[graczw - 1][graczk] == 3 && plansza2[graczw + 1][graczk] == 6)
							{

								SetConsoleTextAttribute(hOut, FOREGROUND_RED);
								spacje(77);
								cout << "TRAFIONY!";
								if (efekty == true)
									PlaySound(L"trafiony.wav", NULL, SND_ASYNC);
								spacje(10);
							}
							else if (plansza2[graczw - 1][graczk] == 6 && plansza2[graczw + 1][graczk] == 6)
							{
								for (int a = 0; a < 3; a++)
								{
									for (int b = 0; b < 5; b++)
									{
										if (graczk - 1 + a >= 0 && graczk - 1 + a <= 9 && graczw + 2 - b >= 0 && graczw + 2 - b <= 9 && plansza2[graczw + 2 - b][graczk - 1 + a] == -1)
											plansza2[graczw + 2 - b][graczk - 1 + a] = 5;
									}


								}

								SetConsoleTextAttribute(hOut, FOREGROUND_GREEN);
								spacje(71);
								cout << "TRAFIONY, ZATOPIONY!";
								if (efekty == true)
									PlaySound(L"zatopiony.wav", NULL, SND_ASYNC);
								spacje(5);
								if (trojka1_2 == false) trojka1_2 = true;
								else if (trojka1_2 == true) trojka2_2 = true;
							}
							else if (plansza2[graczw + 1][graczk] == 3 && plansza2[graczw + 2][graczk] == 3)
							{

								SetConsoleTextAttribute(hOut, FOREGROUND_RED);
								spacje(77);
								cout << "TRAFIONY!";
								if (efekty == true)
									PlaySound(L"trafiony.wav", NULL, SND_ASYNC);
								spacje(10);
							}
							else if (plansza2[graczw + 1][graczk] == 6 && plansza2[graczw + 2][graczk] == 3)
							{

								SetConsoleTextAttribute(hOut, FOREGROUND_RED);
								spacje(77);
								cout << "TRAFIONY!";
								if (efekty == true)
									PlaySound(L"trafiony.wav", NULL, SND_ASYNC);
								spacje(10);
							}
							else if (plansza2[graczw + 1][graczk] == 3 && plansza2[graczw + 2][graczk] == 6)
							{

								SetConsoleTextAttribute(hOut, FOREGROUND_RED);
								spacje(77);
								cout << "TRAFIONY!";
								if (efekty == true)
									PlaySound(L"trafiony.wav", NULL, SND_ASYNC);
								spacje(10);
							}
							else if (plansza2[graczw + 1][graczk] == 6 && plansza2[graczw + 2][graczk] == 6)
							{
								for (int a = 0; a < 3; a++)
								{
									for (int b = 0; b < 5; b++)
									{
										if (graczk - 1 + a >= 0 && graczk - 1 + a <= 9 && graczw - 1 + b >= 0 && graczw - 1 + b <= 9 && plansza2[graczw - 1 + b][graczk - 1 + a] == -1)
											plansza2[graczw - 1 + b][graczk - 1 + a] = 5;
									}


								}

								SetConsoleTextAttribute(hOut, FOREGROUND_GREEN);
								spacje(71);
								cout << "TRAFIONY, ZATOPIONY!";
								if (efekty == true)
									PlaySound(L"zatopiony.wav", NULL, SND_ASYNC);
								spacje(5);
								if (trojka1_2 == false) trojka1_2 = true;
								else if (trojka1_2 == true) trojka2_2 = true;
							}

							else if (plansza2[graczw][graczk + 1] == 3 && plansza2[graczw][graczk + 2] == 3)
							{

								SetConsoleTextAttribute(hOut, FOREGROUND_RED);
								spacje(77);
								cout << "TRAFIONY!";
								if (efekty == true)
									PlaySound(L"trafiony.wav", NULL, SND_ASYNC);
								spacje(10);
							}
							else if (plansza2[graczw][graczk + 1] == 6 && plansza2[graczw][graczk + 2] == 3)
							{

								SetConsoleTextAttribute(hOut, FOREGROUND_RED);
								spacje(77);
								cout << "TRAFIONY!";
								if (efekty == true)
									PlaySound(L"trafiony.wav", NULL, SND_ASYNC);
								spacje(10);
							}
							else if (plansza2[graczw][graczk + 1] == 3 && plansza2[graczw][graczk + 2] == 6)
							{

								SetConsoleTextAttribute(hOut, FOREGROUND_RED);
								spacje(77);
								cout << "TRAFIONY!";
								if (efekty == true)
									PlaySound(L"trafiony.wav", NULL, SND_ASYNC);
								spacje(10);
							}
							else if (plansza2[graczw][graczk + 1] == 6 && plansza2[graczw][graczk + 2] == 6)
							{
								for (int a = 0; a < 3; a++)
								{
									for (int b = 0; b < 5; b++)
									{
										if (graczk - 1 + b >= 0 && graczk - 1 + b <= 9 && graczw - 1 + a >= 0 && graczw - 1 + a <= 9 && plansza2[graczw - 1 + a][graczk - 1 + b] == -1)
											plansza2[graczw - 1 + a][graczk - 1 + b] = 5;
									}
								}

								SetConsoleTextAttribute(hOut, FOREGROUND_GREEN);
								spacje(71);
								cout << "TRAFIONY, ZATOPIONY!";
								if (efekty == true)
									PlaySound(L"zatopiony.wav", NULL, SND_ASYNC);
								spacje(5);
								if (trojka1_2 == false) trojka1_2 = true;
								else if (trojka1_2 == true) trojka2_2 = true;
							}

							else if (plansza2[graczw][graczk - 1] == 3 && plansza2[graczw][graczk + 1] == 3)
							{

								SetConsoleTextAttribute(hOut, FOREGROUND_RED);
								spacje(77);
								cout << "TRAFIONY!";
								if (efekty == true)
									PlaySound(L"trafiony.wav", NULL, SND_ASYNC);
								spacje(10);
							}
							else if (plansza2[graczw][graczk - 1] == 6 && plansza2[graczw][graczk + 1] == 3)
							{

								SetConsoleTextAttribute(hOut, FOREGROUND_RED);
								spacje(77);
								cout << "TRAFIONY!";
								if (efekty == true)
									PlaySound(L"trafiony.wav", NULL, SND_ASYNC);
								spacje(10);
							}
							else if (plansza2[graczw][graczk - 1] == 3 && plansza2[graczw][graczk + 1] == 6)
							{

								SetConsoleTextAttribute(hOut, FOREGROUND_RED);
								spacje(77);
								cout << "TRAFIONY!";
								if (efekty == true)
									PlaySound(L"trafiony.wav", NULL, SND_ASYNC);
								spacje(10);
							}
							else if (plansza2[graczw][graczk - 1] == 6 && plansza2[graczw][graczk + 1] == 6)
							{
								for (int a = 0; a < 3; a++)
								{
									for (int b = 0; b < 5; b++)
									{
										if (graczk - 2 + b >= 0 && graczk - 2 + b <= 9 && graczw - 1 + a >= 0 && graczw - 1 + a <= 9 && plansza2[graczw - 1 + a][graczk - 2 + b] == -1)
											plansza2[graczw - 1 + a][graczk - 2 + b] = 5;
									}
								}

								SetConsoleTextAttribute(hOut, FOREGROUND_GREEN);
								spacje(71);
								cout << "TRAFIONY, ZATOPIONY!";
								if (efekty == true)
									PlaySound(L"zatopiony.wav", NULL, SND_ASYNC);
								spacje(5);
								if (trojka1_2 == false) trojka1_2 = true;
								else if (trojka1_2 == true) trojka2_2 = true;
							}
							else if (plansza2[graczw][graczk - 1] == 3 && plansza2[graczw][graczk - 2] == 3)
							{

								SetConsoleTextAttribute(hOut, FOREGROUND_RED);
								spacje(77);
								cout << "TRAFIONY!";
								if (efekty == true)
									PlaySound(L"trafiony.wav", NULL, SND_ASYNC);
								spacje(10);
							}
							else if (plansza2[graczw][graczk - 1] == 6 && plansza2[graczw][graczk - 2] == 3)
							{

								SetConsoleTextAttribute(hOut, FOREGROUND_RED);
								spacje(77);
								cout << "TRAFIONY!";
								if (efekty == true)
									PlaySound(L"trafiony.wav", NULL, SND_ASYNC);
								spacje(10);
							}
							else if (plansza2[graczw][graczk - 1] == 3 && plansza2[graczw][graczk - 2] == 6)
							{

								SetConsoleTextAttribute(hOut, FOREGROUND_RED);
								spacje(77);
								cout << "TRAFIONY!";
								if (efekty == true)
									PlaySound(L"trafiony.wav", NULL, SND_ASYNC);
								spacje(10);
							}
							else if (plansza2[graczw][graczk - 1] == 6 && plansza2[graczw][graczk - 2] == 6)
							{
								for (int a = 0; a < 3; a++)
								{
									for (int b = 0; b < 5; b++)
									{
										if (graczk - 3 + b >= 0 && graczk - 3 + b <= 9 && graczw - 1 + a >= 0 && graczw - 1 + a <= 9 && plansza2[graczw - 1 + a][graczk - 3 + b] == -1)
											plansza2[graczw - 1 + a][graczk - 3 + b] = 5;
									}
								}

								SetConsoleTextAttribute(hOut, FOREGROUND_GREEN);
								spacje(71);
								cout << "TRAFIONY, ZATOPIONY!";
								if (efekty == true)
									PlaySound(L"zatopiony.wav", NULL, SND_ASYNC);
								spacje(5);
								if (trojka1_2 == false) trojka1_2 = true;
								else if (trojka1_2 == true) trojka2_2 = true;
							}

						}
						else if (plansza2[graczw][graczk] == 4)
						{
							plansza2[graczw][graczk] = 6;
							czworka2++;
							if (czworka2 != 4)
							{

								SetConsoleTextAttribute(hOut, FOREGROUND_RED);
								spacje(77);
								cout << "TRAFIONY!";
								if (efekty == true)
									PlaySound(L"trafiony.wav", NULL, SND_ASYNC);
								spacje(10);
							}
							else if (czworka2 == 4)
							{
								if (plansza2[graczw][graczk + 1] == 6 && plansza2[graczw][graczk + 2] == 6 && plansza2[graczw][graczk + 3] == 6)
								{
									for (int a = 0; a < 3; a++)
									{
										for (int b = 0; b < 6; b++)
										{
											if (graczw - 1 + a >= 0 && graczw - 1 + a <= 9 && graczk - 1 + b >= 0 && graczk - 1 + b <= 9 && plansza2[graczw - 1 + a][graczk - 1 + b] == -1)
												plansza2[graczw - 1 + a][graczk - 1 + b] = 5;
										}
									}

									SetConsoleTextAttribute(hOut, FOREGROUND_GREEN);
									spacje(71);
									cout << "TRAFIONY, ZATOPIONY!";
									if (efekty == true)
										PlaySound(L"zatopiony.wav", NULL, SND_ASYNC);
									spacje(5);
									if (czworka1_2 == false) czworka1_2 = true;


								}
								else if (plansza2[graczw][graczk - 1] == 6 && plansza2[graczw][graczk + 1] == 6 && plansza2[graczw][graczk + 2] == 6)
								{
									for (int a = 0; a < 3; a++)
									{
										for (int b = 0; b < 6; b++)
										{
											if (graczw - 1 + a >= 0 && graczw - 1 + a <= 9 && graczk - 2 + b >= 0 && graczk - 2 + b <= 9 && plansza2[graczw - 1 + a][graczk - 2 + b] == -1)
												plansza2[graczw - 1 + a][graczk - 2 + b] = 5;
										}
									}

									SetConsoleTextAttribute(hOut, FOREGROUND_GREEN);
									spacje(71);
									cout << "TRAFIONY, ZATOPIONY!";
									if (efekty == true)
										PlaySound(L"zatopiony.wav", NULL, SND_ASYNC);
									spacje(5);
									if (czworka1_2 == false) czworka1_2 = true;
								}
								else if (plansza2[graczw][graczk - 1] == 6 && plansza2[graczw][graczk - 2] == 6 && plansza2[graczw][graczk - 3] == 6)
								{
									for (int a = 0; a < 3; a++)
									{
										for (int b = 0; b < 6; b++)
										{
											if (graczw - 1 + a >= 0 && graczw - 1 + a <= 9 && graczk + 1 - b >= 0 && graczk + 1 - b <= 9 && plansza2[graczw - 1 + a][graczk + 1 - b] == -1)
												plansza2[graczw - 1 + a][graczk + 1 - b] = 5;
										}
									}

									SetConsoleTextAttribute(hOut, FOREGROUND_GREEN);
									spacje(71);
									cout << "TRAFIONY, ZATOPIONY!";
									if (efekty == true)
										PlaySound(L"zatopiony.wav", NULL, SND_ASYNC);
									spacje(5);
									if (czworka1_2 == false) czworka1_2 = true;
								}
								else if (plansza2[graczw][graczk - 1] == 6 && plansza2[graczw][graczk + 1] == 6 && plansza2[graczw][graczk - 2] == 6)
								{
									for (int a = 0; a < 3; a++)
									{
										for (int b = 0; b < 6; b++)
										{
											if (graczw - 1 + a >= 0 && graczw - 1 + a <= 9 && graczk + 2 - b >= 0 && graczk + 2 - b <= 9 && plansza2[graczw - 1 + a][graczk + 2 - b] == -1)
												plansza2[graczw - 1 + a][graczk + 2 - b] = 5;
										}
									}

									SetConsoleTextAttribute(hOut, FOREGROUND_GREEN);
									spacje(71);
									cout << "TRAFIONY, ZATOPIONY!";
									if (efekty == true)
										PlaySound(L"zatopiony.wav", NULL, SND_ASYNC);
									spacje(5);
									if (czworka1_2 == false) czworka1_2 = true;
								}
								else if (plansza2[graczw + 1][graczk] == 6 && plansza2[graczw + 2][graczk] == 6 && plansza2[graczw + 3][graczk] == 6)
								{
									for (int a = 0; a < 3; a++)
									{
										for (int b = 0; b < 6; b++)
										{
											if (graczk - 1 + a >= 0 && graczk - 1 + a <= 9 && graczw - 1 + b >= 0 && graczw - 1 + b <= 9 && plansza2[graczw - 1 + b][graczk - 1 + a] == -1)
												plansza2[graczw - 1 + b][graczk - 1 + a] = 5;
										}
									}

									SetConsoleTextAttribute(hOut, FOREGROUND_GREEN);
									spacje(71);
									cout << "TRAFIONY, ZATOPIONY!";
									if (efekty == true)
										PlaySound(L"zatopiony.wav", NULL, SND_ASYNC);
									spacje(5);
									if (czworka1_2 == false) czworka1_2 = true;
								}
								else if (plansza2[graczw + 1][graczk] == 6 && plansza2[graczw - 1][graczk] == 6 && plansza2[graczw + 2][graczk] == 6)
								{
									for (int a = 0; a < 3; a++)
									{
										for (int b = 0; b < 6; b++)
										{
											if (graczk - 1 + a >= 0 && graczk - 1 + a <= 9 && graczw - 2 + b >= 0 && graczw - 2 + b <= 9 && plansza2[graczw - 2 + b][graczk - 1 + a] == -1)
												plansza2[graczw - 2 + b][graczk - 1 + a] = 5;
										}
									}

									SetConsoleTextAttribute(hOut, FOREGROUND_GREEN);
									spacje(71);
									cout << "TRAFIONY, ZATOPIONY!";
									if (efekty == true)
										PlaySound(L"zatopiony.wav", NULL, SND_ASYNC);
									spacje(5);
									if (czworka1_2 == false) czworka1_2 = true;
								}
								else if (plansza2[graczw - 1][graczk] == 6 && plansza2[graczw - 2][graczk] == 6 && plansza2[graczw - 3][graczk] == 6)
								{
									for (int a = 0; a < 3; a++)
									{
										for (int b = 0; b < 6; b++)
										{
											if (graczk - 1 + a >= 0 && graczk - 1 + a <= 9 && graczw + 1 - b >= 0 && graczw + 1 - b <= 9 && plansza2[graczw + 1 - b][graczk - 1 + a] == -1)
												plansza2[graczw + 1 - b][graczk - 1 + a] = 5;
										}
									}

									SetConsoleTextAttribute(hOut, FOREGROUND_GREEN);
									spacje(71);
									cout << "TRAFIONY, ZATOPIONY!";
									if (efekty == true)
										PlaySound(L"zatopiony.wav", NULL, SND_ASYNC);
									spacje(5);
									if (czworka1_2 == false) czworka1_2 = true;
								}
								else if (plansza2[graczw + 1][graczk] == 6 && plansza2[graczw - 1][graczk] == 6 && plansza2[graczw - 2][graczk] == 6)
								{
									for (int a = 0; a < 3; a++)
									{
										for (int b = 0; b < 6; b++)
										{
											if (graczk - 1 + a >= 0 && graczk - 1 + a <= 9 && graczw + 2 - b >= 0 && graczw + 2 - b <= 9 && plansza2[graczw + 2 - b][graczk - 1 + a] == -1)
												plansza2[graczw + 2 - b][graczk - 1 + a] = 5;
										}
									}

									SetConsoleTextAttribute(hOut, FOREGROUND_GREEN);
									spacje(71);
									cout << "TRAFIONY, ZATOPIONY!";
									if (efekty == true)
										PlaySound(L"zatopiony.wav", NULL, SND_ASYNC);
									spacje(5);
									if (czworka1_2 == false) czworka1_2 = true;
								}
							}
						}
						if (plansza2[graczw][graczk] == 6)
							kolejGracza1 = true;
						else
							kolejGracza1 = false;

					}

				}
				if (jedynka1_2 == false)
				{
					SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
					cout << kratka << "  ";
				}
				else
				{
					SetConsoleTextAttribute(hOut, FOREGROUND_RED);
					cout << kratka << "  ";
				}
				if (jedynka2_2 == false)
				{
					SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
					cout << kratka << "  ";
				}
				else
				{
					SetConsoleTextAttribute(hOut, FOREGROUND_RED);
					cout << kratka << "  ";
				}
				if (jedynka3_2 == false)
				{
					SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
					cout << kratka << "  ";
				}
				else
				{
					SetConsoleTextAttribute(hOut, FOREGROUND_RED);
					cout << kratka << "  ";
				}
				if (jedynka4_2 == false)
				{
					SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
					cout << kratka << "  ";
				}
				else
				{
					SetConsoleTextAttribute(hOut, FOREGROUND_RED);
					cout << kratka << "  ";
				}
				cout << endl;

				if (dwojka1_1 == false)
				{
					SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
					cout << "  " << kratka << kratka << "  ";
				}
				else
				{
					SetConsoleTextAttribute(hOut, FOREGROUND_RED);
					cout << "  " << kratka << kratka << "  ";
				}
				if (dwojka2_1 == false)
				{
					SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
					cout << kratka << kratka << "  ";
				}
				else
				{
					SetConsoleTextAttribute(hOut, FOREGROUND_RED);
					cout << kratka << kratka << "  ";
				}
				if (dwojka3_1 == false)
				{
					SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
					cout << kratka << kratka;
				}
				else
				{
					SetConsoleTextAttribute(hOut, FOREGROUND_RED);
					cout << kratka << kratka;
				}

				spacje(96);

				if (dwojka1_2 == false)
				{
					SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
					cout << kratka << kratka << "  ";
				}
				else
				{
					SetConsoleTextAttribute(hOut, FOREGROUND_RED);
					cout << kratka << kratka << "  ";
				}
				if (dwojka2_2 == false)
				{
					SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
					cout << kratka << kratka << "  ";
				}
				else
				{
					SetConsoleTextAttribute(hOut, FOREGROUND_RED);
					cout << kratka << kratka << "  ";
				}
				if (dwojka3_2 == false)
				{
					SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
					cout << kratka << kratka;
				}
				else
				{
					SetConsoleTextAttribute(hOut, FOREGROUND_RED);
					cout << kratka << kratka << "  ";
				}
				cout << endl;
				if (trojka1_1 == false)
				{
					SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
					cout << "  " << kratka << kratka << kratka << "  ";
				}
				else
				{
					SetConsoleTextAttribute(hOut, FOREGROUND_RED);
					cout << "  " << kratka << kratka << kratka << "  ";
				}
				if (trojka2_1 == false)
				{
					SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
					cout << kratka << kratka << kratka;
				}
				else
				{
					SetConsoleTextAttribute(hOut, FOREGROUND_RED);
					cout << kratka << kratka << kratka;
				}

				if (kolejGracza1 == true)
				{
					SetConsoleTextAttribute(hOut, FOREGROUND_BLUE);
					spacje(((120 - (dl_imie1 + 26)) / 2) - 10);

					cout << imie1 << ", to twoja tura! Strzelaj!";
					if ((imie1.length() % 2) == 1)
						spacje(((120 - (dl_imie1 + 26)) / 2) - 11);
					else
						spacje(((120 - (dl_imie1 + 26)) / 2) - 10);
				}
				else
				{
					SetConsoleTextAttribute(hOut, FOREGROUND_BLUE | FOREGROUND_RED);
					spacje(((120 - (dl_imie2 + 26)) / 2) - 10);
					cout << imie2 << ", to twoja tura! Strzelaj!";
					if ((imie2.length() % 2) == 1)
						spacje(((120 - (dl_imie2 + 26)) / 2) - 11);
					else
						spacje(((120 - (dl_imie2 + 26)) / 2) - 10);
				}
				if (trojka1_2 == false)
				{
					SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
					cout << kratka << kratka << kratka << "  ";
				}
				else
				{
					SetConsoleTextAttribute(hOut, FOREGROUND_RED);
					cout << kratka << kratka << kratka << "  ";
				}
				if (trojka2_2 == false)
				{
					SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
					cout << kratka << kratka << kratka;
				}
				else
				{
					SetConsoleTextAttribute(hOut, FOREGROUND_RED);
					cout << kratka << kratka << kratka;
				}
				cout << endl;
				if (czworka1_1 == false)
				{
					SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
					cout << "  " << kratka << kratka << kratka << kratka;
				}
				else
				{
					SetConsoleTextAttribute(hOut, FOREGROUND_RED);
					cout << "  " << kratka << kratka << kratka << kratka;
				}
				spacje(108);
				if (czworka1_2 == false)
				{
					SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
					cout << kratka << kratka << kratka << kratka;
				}
				else
				{
					SetConsoleTextAttribute(hOut, FOREGROUND_RED);
					cout << kratka << kratka << kratka << kratka;
				}

				cout << endl;



				SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
				for (int a = 0; a < (60 - (dl_imie1 + 15)) / 2; a++)
					cout << " ";
				cout << "Plansza gracza ";
				SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
				cout << imie1;
				SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
				for (int a = 0; a < (45 - ((dl_imie1 + dl_imie2) / 2)); a++)
					cout << " ";
				cout << "Plansza gracza ";
				SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
				cout << imie2;
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
				cout << "      " << kreska << "   ";
				for (char x = 65; x <= 74; x++)
				{
					SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
					cout << "    ";
					SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY | BACKGROUND_RED);
					cout << x;

				}
				SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY);


				cout << endl << "                                                           " << kreska << endl;
				for (int i = 0; i <= 9; i++)
				{
					cout << "  ";
					SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY | BACKGROUND_RED);
					cout << (i + 1);

					// POKAZuJE u£O¯ON¥ PLANSZÊ
					for (int j = 0; j <= 9; j++)
					{
						if (i == 9 && j == 0)
						{
							if (plansza[i][j] == -1)
							{
								cout.width(4);
								SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
								cout << ".";
							}
							else if (plansza[i][j] == 0)
							{
								cout.width(4);
								SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
								cout << ".";
							}
							else if (plansza[i][j] == 1 || plansza[i][j] == 2 || plansza[i][j] == 3 || plansza[i][j] == 4)
							{
								cout.width(4);
								SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
								cout << ".";
							}
							else if (plansza[i][j] == 5)
							{
								cout.width(4);
								SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
								cout << "o";
							}
							else if (plansza[i][j] == 6)
							{
								cout.width(4);
								SetConsoleTextAttribute(hOut, FOREGROUND_RED);
								cout << "x";
							}
						}
						else
						{
							if (plansza[i][j] == -1)
							{
								cout.width(5);
								SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
								cout << ".";
							}
							else if (plansza[i][j] == 0)
							{
								cout.width(5);
								SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
								cout << ".";
							}
							else if (plansza[i][j] == 1 || plansza[i][j] == 2 || plansza[i][j] == 3 || plansza[i][j] == 4)
							{
								cout.width(5);
								SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
								cout << ".";
							}
							else if (plansza[i][j] == 5)
							{
								cout.width(5);
								SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
								cout << "o";
							}
							else if (plansza[i][j] == 6)
							{
								cout.width(5);
								SetConsoleTextAttribute(hOut, FOREGROUND_RED);
								cout << "x";
							}
						}
					}
					SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY);
					cout << "      " << kreska << "   ";

					for (int q = 0; q <= 9; q++)
					{
						if (i == 9 && q == 0)
						{
							if (plansza2[i][q] == -1)
							{
								cout.width(5);
								SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
								cout << ".";
							}
							else if (plansza2[i][q] == 0)
							{
								cout.width(5);
								SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
								cout << ".";
							}
							else if (plansza2[i][q] == 1 || plansza2[i][q] == 2 || plansza2[i][q] == 3 || plansza2[i][q] == 4)
							{
								cout.width(5);
								SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
								cout << ".";
							}
							else if (plansza2[i][q] == 5)
							{
								cout.width(5);
								SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
								cout << "o";
							}
							else if (plansza2[i][q] == 6)
							{
								cout.width(5);
								SetConsoleTextAttribute(hOut, FOREGROUND_RED);
								cout << "x";
							}
						}
						else
						{
							if (plansza2[i][q] == -1)
							{
								cout.width(5);
								SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
								cout << ".";
							}
							else if (plansza2[i][q] == 0)
							{
								cout.width(5);
								SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
								cout << ".";
							}
							else if (plansza2[i][q] == 1 || plansza2[i][q] == 2 || plansza2[i][q] == 3 || plansza2[i][q] == 4)
							{
								cout.width(5);
								SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
								cout << ".";
							}
							else if (plansza2[i][q] == 5)
							{
								cout.width(5);
								SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
								cout << "o";
							}
							else if (plansza2[i][q] == 6)
							{
								cout.width(5);
								SetConsoleTextAttribute(hOut, FOREGROUND_RED);
								cout << "x";
							}
						}

					}
					SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
					cout << "    ";
					SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY | BACKGROUND_RED);
					cout << i + 1;
					SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY);


					cout << endl << "                                                           ";
					if (i != 9)
						cout << kreska;
					cout << endl;
				}

				SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);

				int licznik = 0;
				int licznik2 = 0;
				for (int s = 0; s <= 9; s++)
				{
					for (int t = 0; t <= 9; t++)
					{

						if (plansza[s][t] == 6 || plansza[s][t] == 5 || plansza[s][t] == 0 || plansza[s][t] == -1)
						{
							licznik++;
						}


					}
				}
				for (int s = 0; s <= 9; s++)
				{
					for (int t = 0; t <= 9; t++)
					{

						if (plansza2[s][t] == 6 || plansza2[s][t] == 5 || plansza2[s][t] == 0 || plansza2[s][t] == -1)
						{
							licznik2++;
						}


					}
				}
				if (licznik == 100)
				{
					koniec_gry = true;
					SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
					cout << "GRATULACJE! TO JUZ KONIEC GRY!";
					Sleep(2000);
					system("cls");
					if (efekty == true)
						PlaySound(L"wygranaG.wav", NULL, SND_ASYNC);
					cout << "GRATULACJE! TO JUZ KONIEC GRY! Wygral ";
					SetConsoleTextAttribute(hOut, FOREGROUND_RED);
					cout << imie2;
					SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
					cout << endl << endl;
					stop = clock();
					czas(start, stop);
					instrukcja = 0;
				}


				else if (licznik2 == 100)
				{
					koniec_gry = true;
					SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
					cout << "GRATULACJE! TO JUZ KONIEC GRY!";
					Sleep(2000);
					system("cls");
					cout << "GRATULACJE! TO JUZ KONIEC GRY! Wygral ";
					SetConsoleTextAttribute(hOut, FOREGROUND_RED);
					cout << imie1;
					SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
					cout << endl << endl;
					stop = clock();
					czas(start, stop);
				}
			}
		}
		else if (instrukcja == 2)
		{
			int wybor{};
			system("cls");
			cin.ignore(100, '\n');
			do
			{

				ramka("Tryb dla jednego gracza", wsk);
				SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
				spacje(48);
				cout << "Poziom latwy - wcisnij ";
				SetConsoleTextAttribute(hOut, FOREGROUND_RED);
				cout << "[1]" << endl << endl;
				SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
				spacje(48);
				cout << "Poziom normalny - wcisnij ";
				SetConsoleTextAttribute(hOut, FOREGROUND_RED);
				cout << "[2]" << endl << endl;
				SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
				spacje(48);
				cout << "Poziom trudny - wcisnij ";
				SetConsoleTextAttribute(hOut, FOREGROUND_RED);
				cout << "[3] " << endl << endl << endl;
				SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
				spacje(48);
				cout << "Twoj wybor: ";
				cin >> wybor;
				system("cls");

				prawda = cin.good();
				sprawdzCin(prawda);
			} while ((wybor != 1 && wybor != 2 && wybor != 3) || prawda == 0);
			if (wybor == 1 || wybor == 2 || wybor == 3)
			{
				spacje(48);
				SetConsoleTextAttribute(hOut, FOREGROUND_BLUE);
				cout << "Tryb dla jednego gracza" << endl << endl;
				SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
				cout << "Podaj imie pierwszego gracza: ";
				cin >> imie1;
				cout << endl;
				cout << "Podaj imie drugiego gracza: ";
				if (wybor == 1)
				{
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
				}
				else if (wybor == 2)
				{
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
				}
				else if (wybor == 3)
				{
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

				}

				system("cls");

				int dl_imie1 = imie1.length() - (imie1.length() % 2);
				int dl_imie2 = imie2.length() - (imie2.length() % 2);
				int ulozenie1;

				bool blad = false;
				bool zacznij_gre3 = false;
				while (zacznij_gre3 == false)
				{
					do
					{
						system("cls");
						SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
						cout << imie1;
						SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
						cout << ", jezeli chcesz losowo ulozyc plansze - kliknij";
						SetConsoleTextAttribute(hOut, FOREGROUND_GREEN);
						cout << " [1]";
						SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
						cout << endl << "Jezeli chcesz samodzielnie ulozyc plansze (zalecane zapoznanie sie najpierw z instrukcja) - kliknij";
						SetConsoleTextAttribute(hOut, FOREGROUND_GREEN);
						cout << " [2]" << endl << endl;
						SetConsoleTextAttribute(hOut, FOREGROUND_RED);
						cout << "Two wybor: ";
						SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
						cin >> ulozenie1;
						prawda = cin.good();
						sprawdzCin(prawda);
						if (ulozenie1 != 1 && ulozenie1 != 2)
						{
							system("cls");
							SetConsoleTextAttribute(hOut, FOREGROUND_RED);
							cout << "Dokonales zlego wyboru! Nie przechodz na ciemna strone mocy i wybierz wlasciwa cyfre!" << endl << endl;
						}
					} while (prawda == 0 || (ulozenie1 != 1 && ulozenie1 != 2));
					system("cls");

					if (ulozenie1 == 1)
					{
						do
						{

							if (ulozenie1 == 1)
							{
								uloz_plansze(plansza);

								bool sprawdzacz = true;

								while (sprawdzacz == true)
								{
									int sprawdzam[4] = { 0, 0, 0, 0 };
									for (int p = 0; p <= 9; p++)
									{
										for (int q = 0; q <= 9; q++)
										{
											if (plansza[p][q] == 1)
												sprawdzam[0] += 1;
											else if (plansza[p][q] == 2)
												sprawdzam[1] += 1;
											else if (plansza[p][q] == 3)
												sprawdzam[2] += 1;
											else if (plansza[p][q] == 4)
												sprawdzam[3] += 1;
										}
									}

									if (sprawdzam[0] == 4 && sprawdzam[1] == 6 && sprawdzam[2] == 6 && sprawdzam[3] == 4)
									{
										sprawdzacz = false;
									}
									else
										uloz_plansze(plansza);
								}
							}
							do
							{
								kropki(plansza);

								if (ulozenie1 != 1 && ulozenie1 != 0)
								{
									SetConsoleTextAttribute(hOut, FOREGROUND_RED);
									cout << "Dokonales zlego wyboru! Nie przechodz na ciemna strone mocy i wybierz wlasciwa cyfre!" << endl << endl;
									cin.clear();
									cin.ignore(100, '\n');
								}
								SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
								cout << "        " << endl << endl << "Jezeli chcesz rozlosowac jeszcze raz - wcisnij";
								SetConsoleTextAttribute(hOut, FOREGROUND_GREEN);
								cout << " [1]";
								SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
								cout << ", jezeli takie ulozenie ci odpowiada - wcisnij";
								SetConsoleTextAttribute(hOut, FOREGROUND_GREEN);
								cout << " [2]" << endl;
								SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
								cin >> ulozenie1;
								prawda = cin.good();
								sprawdzCin(prawda);
								if (prawda == 0) system("cls");
							} while (prawda == 0);
							system("cls");
							if (ulozenie1 == 2) zacznij_gre3 = true;
						} while (ulozenie1 != 2 && ulozenie1 != 0);
						system("cls");
					}



					else if (ulozenie1 == 2)
					{
						bool zacznij_gre = false;
						recznieUloz(plansza, zacznij_gre);
					}
				}
				system("cls");

				uloz_plansze(plansza2);
				bool sprawdzacz2 = true;

				while (sprawdzacz2 == true)
				{
					int sprawdzam2[4] = { 0, 0, 0, 0 };
					for (int p = 0; p <= 9; p++)
					{
						for (int q = 0; q <= 9; q++)
						{
							if (plansza2[p][q] == 1)
								sprawdzam2[0] += 1;
							else if (plansza2[p][q] == 2)
								sprawdzam2[1] += 1;
							else if (plansza2[p][q] == 3)
								sprawdzam2[2] += 1;
							else if (plansza2[p][q] == 4)
								sprawdzam2[3] += 1;
						}
					}
					if (sprawdzam2[0] == 4 && sprawdzam2[1] == 6 && sprawdzam2[2] == 6 && sprawdzam2[3] == 4)
					{
						sprawdzacz2 = false;
					}
					else
						uloz_plansze(plansza2);
				}
				start = clock();
				if (muzyka == true)
					PlaySound(L"wyciszenie.wav", NULL, SND_ASYNC);

				if (jedynka1_1 == false)
				{
					SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
					cout << "  " << kratka << "  ";
				}
				else
				{
					SetConsoleTextAttribute(hOut, FOREGROUND_RED);
					cout << "  " << kratka << "  ";
				}
				if (jedynka2_1 == false)
				{
					SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
					cout << kratka << "  ";
				}
				else
				{
					SetConsoleTextAttribute(hOut, FOREGROUND_RED);
					cout << kratka << "  ";
				}
				if (jedynka3_1 == false)
				{
					SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
					cout << kratka << "  ";
				}
				else
				{
					SetConsoleTextAttribute(hOut, FOREGROUND_RED);
					cout << kratka << "  ";
				}
				if (jedynka4_1 == false)
				{
					SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
					cout << kratka;
				}
				else
				{
					SetConsoleTextAttribute(hOut, FOREGROUND_RED);
					cout << kratka;
				}

				spacje(96);

				if (jedynka1_2 == false)
				{
					SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
					cout << kratka << "  ";
				}
				else
				{
					SetConsoleTextAttribute(hOut, FOREGROUND_RED);
					cout << kratka << "  ";
				}
				if (jedynka2_2 == false)
				{
					SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
					cout << kratka << "  ";
				}
				else
				{
					SetConsoleTextAttribute(hOut, FOREGROUND_RED);
					cout << kratka << "  ";
				}
				if (jedynka3_2 == false)
				{
					SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
					cout << kratka << "  ";
				}
				else
				{
					SetConsoleTextAttribute(hOut, FOREGROUND_RED);
					cout << kratka << "  ";
				}
				if (jedynka4_2 == false)
				{
					SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
					cout << kratka;
				}
				else
				{
					SetConsoleTextAttribute(hOut, FOREGROUND_RED);
					cout << kratka;
				}
				cout << endl;
				if (dwojka1_1 == false)
				{
					SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
					cout << "  " << kratka << kratka << "  ";
				}
				else
				{
					SetConsoleTextAttribute(hOut, FOREGROUND_RED);
					cout << kratka << kratka << "  ";
				}
				if (dwojka2_1 == false)
				{
					SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
					cout << kratka << kratka << "  ";
				}
				else
				{
					SetConsoleTextAttribute(hOut, FOREGROUND_RED);
					cout << kratka << kratka << "  ";
				}
				if (dwojka3_1 == false)
				{
					SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
					cout << kratka << kratka;
				}
				else
				{
					SetConsoleTextAttribute(hOut, FOREGROUND_RED);
					cout << kratka << kratka;
				}

				spacje(96);

				if (dwojka1_2 == false)
				{
					SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
					cout << kratka << kratka << "  ";
				}
				else
				{
					SetConsoleTextAttribute(hOut, FOREGROUND_RED);
					cout << kratka << kratka << "  ";
				}
				if (dwojka2_2 == false)
				{
					SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
					cout << kratka << kratka << "  ";
				}
				else
				{
					SetConsoleTextAttribute(hOut, FOREGROUND_RED);
					cout << kratka << kratka << "  ";
				}
				if (dwojka3_2 == false)
				{
					SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
					cout << kratka << kratka;
				}
				else
				{
					SetConsoleTextAttribute(hOut, FOREGROUND_RED);
					cout << kratka;
				}
				cout << endl;

				if (trojka1_1 == false)
				{
					SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
					cout << "  " << kratka << kratka << kratka << "  ";
				}
				else
				{
					SetConsoleTextAttribute(hOut, FOREGROUND_RED);
					cout << kratka << kratka << kratka << "  ";
				}
				if (trojka2_1 == false)
				{
					SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
					cout << kratka << kratka << kratka;
				}
				else
				{
					SetConsoleTextAttribute(hOut, FOREGROUND_RED);
					cout << kratka << kratka << kratka;
				}
				bool kolejGracza1;
				int ktoZaczyna = ktoZaczyna1(generator);
				if (ktoZaczyna == 0)
				{
					SetConsoleTextAttribute(hOut, FOREGROUND_BLUE);
					spacje(((120 - (dl_imie1 + 26)) / 2) - 10);

					cout << imie1 << ", to twoja tura! Strzelaj!";
					kolejGracza1 = true;
					if ((imie1.length() % 2) == 1)
						spacje(((120 - (dl_imie1 + 26)) / 2) - 11);
					else
						spacje(((120 - (dl_imie1 + 26)) / 2) - 10);
				}
				else
				{
					SetConsoleTextAttribute(hOut, FOREGROUND_BLUE | FOREGROUND_RED);
					spacje(((120 - (dl_imie2 + 26)) / 2) - 10);
					cout << imie2 << ", to twoja tura! Strzelaj!";
					kolejGracza1 = false;
					if ((imie2.length() % 2) == 1)
						spacje(((120 - (dl_imie2 + 26)) / 2) - 11);
					else
						spacje(((120 - (dl_imie2 + 26)) / 2) - 10);
				}

				if (trojka1_2 == false)
				{
					SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
					cout << kratka << kratka << kratka << "  ";
				}
				else
				{
					SetConsoleTextAttribute(hOut, FOREGROUND_RED);
					cout << kratka << kratka << kratka << "  ";
				}
				if (trojka2_2 == false)
				{
					SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
					cout << kratka << kratka << kratka;
				}
				else
				{
					SetConsoleTextAttribute(hOut, FOREGROUND_RED);
					cout << kratka << kratka << kratka;
				}
				cout << endl;

				if (czworka1_1 == false)
				{
					SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
					cout << "  " << kratka << kratka << kratka << kratka;
				}
				else
				{
					SetConsoleTextAttribute(hOut, FOREGROUND_RED);
					cout << kratka << kratka << kratka << kratka;
				}
				spacje(108);
				if (czworka1_2 == false)
				{
					SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
					cout << kratka << kratka << kratka << kratka;
				}
				else
				{
					SetConsoleTextAttribute(hOut, FOREGROUND_RED);
					cout << kratka << kratka << kratka << kratka;
				}

				cout << endl;

				SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
				spacje((60 - (dl_imie1 + 15)) / 2);
				cout << "Plansza gracza ";
				SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
				cout << imie1;
				SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
				spacje((42 - ((dl_imie1 + dl_imie2) / 2)));
				cout << "Plansza komputera ";
				SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
				cout << imie2;
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
				cout << "      " << kreska << "   ";
				for (char x = 65; x <= 74; x++)
				{
					SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
					cout << "    ";
					SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY | BACKGROUND_RED);
					cout << x;

				}
				SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY);


				cout << endl << "                                                           " << kreska << endl;
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
					cout << "      " << kreska << "   ";

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
						cout << kreska;
					cout << endl;
				}
				SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
				int licz{};
				int tabx[100]{};
				int x{};
				int taby[100]{};
				int y{};
				int wspolrzedna{};
				int czworka = 0;
				int czworka2 = 0;
				int graczw{};
				char graczkol{};
				int graczk{};
				bool koniec_gry = false;
				bool k_trafiony = false;
				int k_wiersz = -1;
				int k_kolumna = -1;
				int k_kierunek = 0;
				int k_sprawdzKierunek = 0;

				while (koniec_gry == false)
				{

					if (kolejGracza1 == true)
					{
						cout << "  Podaj kolumne (A-J), a nastepnie wiersz(1-10): ";
						cin >> graczkol;
					}
					else
					{

						spacje(65);
						cout << "  Podaj kolumne (A-J), a nastepnie wiersz(1-10): ";
						if (wybor == 1)
						{
							do
							{
								graczw = wierszL(generator);
								graczk = kolumnaL(generator);
							} while (plansza[graczw][graczk] == 6 || plansza[graczw][graczk] == 5);
						}
						else if (wybor == 2)
						{
							if (k_trafiony == false)
							{
								do
								{
									graczw = wierszL(generator);
									graczk = kolumnaL(generator);
								} while (plansza[graczw][graczk] == 6 || plansza[graczw][graczk] == 5);
							}
							else
							{
								if (k_sprawdzKierunek == 0)
								{
									do
									{
										k_kierunek = kierunekL(generator) + 1;
										if (k_wiersz == 0 && k_kierunek == 1) k_kierunek = 0;
										else if (k_wiersz == 9 && k_kierunek == 3) k_kierunek = 0;
										else if (k_kolumna == 0 && k_kierunek == 4) k_kierunek = 0;
										else if (k_kolumna == 9 && k_kierunek == 2) k_kierunek = 0;
										if (k_kierunek == 1 && plansza[k_wiersz - 1][k_kolumna] == 5) k_kierunek = 0;
										else if (k_kierunek == 2 && plansza[k_wiersz][k_kolumna + 1] == 5) k_kierunek = 0;
										else if (k_kierunek == 3 && plansza[k_wiersz + 1][k_kolumna] == 5) k_kierunek = 0;
										else if (k_kierunek == 4 && plansza[k_wiersz][k_kolumna - 1] == 5) k_kierunek = 0;

									} while (k_kierunek == 0);
									if (k_kierunek == 1)
									{
										graczw = k_wiersz - 1;
										graczk = k_kolumna;
										if (plansza[graczw][graczk] == 3 || plansza[graczw][graczk] == 4) k_sprawdzKierunek = 2;

									}
									else if (k_kierunek == 2)
									{
										graczw = k_wiersz;
										graczk = k_kolumna + 1;
										if (plansza[graczw][graczk] == 3 || plansza[graczw][graczk] == 4) k_sprawdzKierunek = 1;

									}
									else if (k_kierunek == 3)
									{
										graczw = k_wiersz + 1;
										graczk = k_kolumna;
										if (plansza[graczw][graczk] == 3 || plansza[graczw][graczk] == 4) k_sprawdzKierunek = 2;

									}
									else if (k_kierunek == 4)
									{
										graczw = k_wiersz;
										graczk = k_kolumna - 1;
										if (plansza[graczw][graczk] == 3 || plansza[graczw][graczk] == 4) k_sprawdzKierunek = 1;

									}
								}

								else if (k_sprawdzKierunek == 1)
								{
									if (plansza[k_wiersz][k_kolumna - 1] != 5 && plansza[k_wiersz][k_kolumna - 1] != 6 && k_kolumna - 1 >= 0)
									{
										graczw = k_wiersz;
										graczk = k_kolumna - 1;
									}
									else if ((plansza[k_wiersz][k_kolumna - 1] == 5 || plansza[k_wiersz][k_kolumna - 1] == 6) && plansza[k_wiersz][k_kolumna + 1] != 5 && plansza[k_wiersz][k_kolumna + 1] != 6 && k_kolumna + 1 <= 9)
									{
										graczw = k_wiersz;
										graczk = k_kolumna + 1;
									}
									else if (plansza[k_wiersz][k_kolumna - 1] == 6 && (plansza[k_wiersz][k_kolumna + 1] == 5 || plansza[k_wiersz][k_kolumna + 1] == 6) && plansza[k_wiersz][k_kolumna - 2] != 5 && plansza[k_wiersz][k_kolumna - 2] != 6 && k_kolumna - 2 >= 0)
									{
										graczw = k_wiersz;
										graczk = k_kolumna - 2;
									}
									else if ((plansza[k_wiersz][k_kolumna - 1] == 5 || plansza[k_wiersz][k_kolumna - 1] == 6) && plansza[k_wiersz][k_kolumna + 1] == 6 && plansza[k_wiersz][k_kolumna + 2] != 5 && plansza[k_wiersz][k_kolumna + 2] != 6 && k_kolumna + 2 <= 9)
									{
										graczw = k_wiersz;
										graczk = k_kolumna + 2;
									}
									else if (plansza[k_wiersz][k_kolumna - 1] == 6 && (plansza[k_wiersz][k_kolumna + 1] == 5 || plansza[k_wiersz][k_kolumna + 1] == 6) && plansza[k_wiersz][k_kolumna - 2] == 6 && plansza[k_wiersz][k_kolumna - 3] != 5 && plansza[k_wiersz][k_kolumna - 3] != 6 && k_kolumna - 3 >= 0)
									{
										graczw = k_wiersz;
										graczk = k_kolumna - 3;
									}
									else if (plansza[k_wiersz][k_kolumna - 1] == 5 && plansza[k_wiersz][k_kolumna + 1] == 6 && plansza[k_wiersz][k_kolumna + 2] == 6 && plansza[k_wiersz][k_kolumna + 3] != 5 && plansza[k_wiersz][k_kolumna + 3] != 6 && k_kolumna + 3 <= 9)
									{
										graczw = k_wiersz;
										graczk = k_kolumna + 3;
									}


								}
								else if (k_sprawdzKierunek == 2)
								{
									if (plansza[k_wiersz - 1][k_kolumna] != 5 && plansza[k_wiersz - 1][k_kolumna] != 6 && k_wiersz - 1 >= 0)
									{
										graczw = k_wiersz - 1;
										graczk = k_kolumna;
									}
									else if ((plansza[k_wiersz - 1][k_kolumna] == 5 || plansza[k_wiersz - 1][k_kolumna] == 6) && plansza[k_wiersz + 1][k_kolumna] != 5 && plansza[k_wiersz + 1][k_kolumna] != 6 && k_wiersz + 1 <= 9)
									{
										graczw = k_wiersz + 1;

									}
									else if (plansza[k_wiersz - 1][k_kolumna] == 6 && (plansza[k_wiersz + 1][k_kolumna] == 5 || plansza[k_wiersz + 1][k_kolumna] == 6) && plansza[k_wiersz - 2][k_kolumna] != 5 && plansza[k_wiersz - 2][k_kolumna] != 6 && k_wiersz - 2 >= 0)
									{
										graczw = k_wiersz - 2;
										graczk = k_kolumna;
									}
									else if ((plansza[k_wiersz - 1][k_kolumna] == 5 || plansza[k_wiersz - 1][k_kolumna] == 6) && plansza[k_wiersz + 1][k_kolumna] == 6 && plansza[k_wiersz + 2][k_kolumna] != 5 && plansza[k_wiersz + 2][k_kolumna] != 6 && k_wiersz + 2 <= 9)
									{
										graczw = k_wiersz + 2;
										graczk = k_kolumna;
									}
									else if (plansza[k_wiersz - 1][k_kolumna] == 6 && plansza[k_wiersz - 2][k_kolumna] == 6 && plansza[k_wiersz + 1][k_kolumna] == 5 && plansza[k_wiersz - 3][k_kolumna] != 5 && plansza[k_wiersz - 3][k_kolumna] != 6 && k_wiersz - 3 >= 0)
									{
										graczw = k_wiersz - 3;
										graczk = k_kolumna;
									}
									else if (plansza[k_wiersz - 1][k_kolumna] == 5 && plansza[k_wiersz + 1][k_kolumna] == 6 && plansza[k_wiersz + 2][k_kolumna] == 6 && plansza[k_wiersz + 3][k_kolumna] != 5 && plansza[k_wiersz + 3][k_kolumna] != 6 && k_wiersz + 3 <= 9)
									{
										graczw = k_wiersz + 3;
										graczk = k_kolumna;
									}

								}

							}
						}
						else if (wybor == 3)
						{

							if (k_trafiony == false)
							{
								if (dwojka3_1 == false || trojka2_1 == false || czworka1_1 == false)
								{
									licz = 0;
									x = 0;
									y = 0;
									for (int p = 0; p < 100; p++)
									{
										tabx[p] = 0;
										taby[p] = 0;
									}

									if (dwojka3_1 == false)
									{

										for (int p = 0; p < 10; p++)
										{
											for (int q = 0; q < 10; q++)
											{
												if (p != 0 && p != 9 && q != 0 && q != 9)
												{
													if (plansza[p][q] != 5 && plansza[p][q] != 6 && plansza[p + 1][q] != 5 && plansza[p + 1][q] != 6 && plansza[p - 1][q] != 5 && plansza[p - 1][q] != 6 && plansza[p][q + 1] != 5 && plansza[p][q + 1] != 6 && plansza[p][q - 1] != 5 && plansza[p][q - 1] != 6)
													{
														++licz;
														tabx[x] = p;
														taby[y] = q;
														x++;
														y++;

													}
												}
											}
										}

										if (licz == 0)
										{
											for (int p = 0; p < 10; p++)
											{
												for (int q = 0; q < 10; q++)
												{
													if (p == 0 && q > 0 && q < 9)
													{
														if (plansza[p][q] != 5 && plansza[p][q] != 6 && plansza[p + 1][q] != 5 && plansza[p + 1][q] != 6 && plansza[p][q + 1] != 5 && plansza[p][q + 1] != 6 && plansza[p][q - 1] != 5 && plansza[p][q - 1] != 6)
														{
															licz++;
															tabx[x] = p;
															taby[y] = q;
															x++;
															y++;

														}
													}
													else if (p == 9 && q > 0 && q < 9)
													{
														if (plansza[p][q] != 5 && plansza[p][q] != 6 && plansza[p - 1][q] != 5 && plansza[p - 1][q] != 6 && plansza[p][q + 1] != 5 && plansza[p][q + 1] != 6 && plansza[p][q - 1] != 5 && plansza[p][q - 1] != 6)
														{
															licz++;
															tabx[x] = p;
															taby[y] = q;
															x++;
															y++;

														}
													}
													else if (q == 0 && p > 0 && p < 9)
													{
														if (plansza[p][q] != 5 && plansza[p][q] != 6 && plansza[p + 1][q] != 5 && plansza[p + 1][q] != 6 && plansza[p - 1][q] != 5 && plansza[p - 1][q] != 6 && plansza[p][q + 1] != 5 && plansza[p][q + 1] != 6)
														{
															licz++;
															tabx[x] = p;
															taby[y] = q;
															x++;
															y++;

														}
													}
													else if (q == 9 && p > 0 && p < 9)
													{
														if (plansza[p][q] != 5 && plansza[p][q] != 6 && plansza[p + 1][q] != 5 && plansza[p + 1][q] != 6 && plansza[p - 1][q] != 5 && plansza[p - 1][q] != 6 && plansza[p][q - 1] != 5 && plansza[p][q - 1] != 6)
														{
															licz++;
															tabx[x] = p;
															taby[y] = q;
															x++;
															y++;

														}
													}
													if (p != 0 && p != 9 && q != 0 && q != 9)
													{
														if (plansza[p][q] != 5 && plansza[p][q] != 6 && plansza[p - 1][q] != 5 && plansza[p - 1][q] != 6 && plansza[p][q + 1] != 5 && plansza[p][q + 1] != 6 && plansza[p][q - 1] != 5 && plansza[p][q - 1] != 6)
														{
															licz++;
															tabx[x] = p;
															taby[y] = q;
															x++;
															y++;

														}
														else if (plansza[p][q] != 5 && plansza[p][q] != 6 && plansza[p + 1][q] != 5 && plansza[p + 1][q] != 6 && plansza[p][q + 1] != 5 && plansza[p][q + 1] != 6 && plansza[p][q - 1] != 5 && plansza[p][q - 1] != 6)
														{
															licz++;
															tabx[x] = p;
															taby[y] = q;
															x++;
															y++;

														}
														else if (plansza[p][q] != 5 && plansza[p][q] != 6 && plansza[p + 1][q] != 5 && plansza[p + 1][q] != 6 && plansza[p - 1][q] != 5 && plansza[p - 1][q] != 6 && plansza[p][q - 1] != 5 && plansza[p][q - 1] != 6)
														{
															licz++;
															tabx[x] = p;
															taby[y] = q;
															x++;
															y++;

														}
														else if (plansza[p][q] != 5 && plansza[p][q] != 6 && plansza[p + 1][q] != 5 && plansza[p + 1][q] != 6 && plansza[p - 1][q] != 5 && plansza[p - 1][q] != 6 && plansza[p][q + 1] != 5 && plansza[p][q + 1] != 6)
														{
															licz++;
															tabx[x] = p;
															taby[y] = q;
															x++;
															y++;

														}
													}
												}
											}
										}
										if (licz == 0)
										{
											for (int p = 0; p < 10; p++)
											{
												for (int q = 0; q < 10; q++)
												{
													if (p == 0 && q == 0)
													{
														if (plansza[p][q] != 5 && plansza[p][q] != 6 && plansza[p + 1][q] != 5 && plansza[p + 1][q] != 6 && plansza[p][q + 1] != 5 && plansza[p][q + 1] != 6)
														{
															licz++;
															tabx[x] = p;
															taby[y] = q;
															x++;
															y++;

														}
													}
													else if (p == 0 && q == 9)
													{
														if (plansza[p][q] != 5 && plansza[p][q] != 6 && plansza[p + 1][q] != 5 && plansza[p + 1][q] != 6 && plansza[p][q - 1] != 5 && plansza[p][q - 1] != 6)
														{
															licz++;
															tabx[x] = p;
															taby[y] = q;
															x++;
															y++;

														}
													}
													else if (p == 9 && q == 0)
													{
														if (plansza[p][q] != 5 && plansza[p][q] != 6 && plansza[p - 1][q] != 5 && plansza[p - 1][q] != 6 && plansza[p][q + 1] != 5 && plansza[p][q + 1] != 6)
														{
															licz++;
															tabx[x] = p;
															taby[y] = q;
															x++;
															y++;

														}
													}
													else if (p == 9 && q == 9)
													{
														if (plansza[p][q] != 5 && plansza[p][q] != 6 && plansza[p - 1][q] != 5 && plansza[p - 1][q] != 6 && plansza[p][q - 1] != 5 && plansza[p][q - 1] != 6)
														{
															licz++;
															tabx[x] = p;
															taby[y] = q;
															x++;
															y++;

														}
													}
													else if (p == 0 && q > 0 && q < 9)
													{
														if (plansza[p][q] != 5 && plansza[p][q] != 6 && plansza[p][q + 1] != 5 && plansza[p][q + 1] != 6 && plansza[p][q - 1] != 5 && plansza[p][q - 1] != 6)
														{
															licz++;
															tabx[x] = p;
															taby[y] = q;
															x++;
															y++;

														}
														else if (plansza[p][q] != 5 && plansza[p][q] != 6 && plansza[p + 1][q] != 5 && plansza[p + 1][q] != 6 && plansza[p][q - 1] != 5 && plansza[p][q - 1] != 6)
														{
															licz++;
															tabx[x] = p;
															taby[y] = q;
															x++;
															y++;

														}
														else if (plansza[p][q] != 5 && plansza[p][q] != 6 && plansza[p + 1][q] != 5 && plansza[p + 1][q] != 6 && plansza[p][q + 1] != 5 && plansza[p][q + 1] != 6)
														{
															licz++;
															tabx[x] = p;
															taby[y] = q;
															x++;
															y++;

														}
													}
													else if (p == 9 && q > 0 && q < 9)
													{
														if (plansza[p][q] != 5 && plansza[p][q] != 6 && plansza[p][q + 1] != 5 && plansza[p][q + 1] != 6 && plansza[p][q - 1] != 5 && plansza[p][q - 1] != 6)
														{
															licz++;
															tabx[x] = p;
															taby[y] = q;
															x++;
															y++;

														}
														else  if (plansza[p][q] != 5 && plansza[p][q] != 6 && plansza[p - 1][q] != 5 && plansza[p - 1][q] != 6 && plansza[p][q - 1] != 5 && plansza[p][q - 1] != 6)
														{
															licz++;
															tabx[x] = p;
															taby[y] = q;
															x++;
															y++;

														}
														else  if (plansza[p][q] != 5 && plansza[p][q] != 6 && plansza[p - 1][q] != 5 && plansza[p - 1][q] != 6 && plansza[p][q + 1] != 5 && plansza[p][q + 1] != 6)
														{
															licz++;
															tabx[x] = p;
															taby[y] = q;
															x++;
															y++;

														}


													}
													else if (q == 0 && p > 0 && p < 9)
													{
														if (plansza[p][q] != 5 && plansza[p][q] != 6 && plansza[p - 1][q] != 5 && plansza[p - 1][q] != 6 && plansza[p][q + 1] != 5 && plansza[p][q + 1] != 6)
														{
															licz++;
															tabx[x] = p;
															taby[y] = q;
															x++;
															y++;

														}
														else if (plansza[p][q] != 5 && plansza[p][q] != 6 && plansza[p + 1][q] != 5 && plansza[p + 1][q] != 6 && plansza[p][q + 1] != 5 && plansza[p][q + 1] != 6)
														{
															licz++;
															tabx[x] = p;
															taby[y] = q;
															x++;
															y++;

														}
														else if (plansza[p][q] != 5 && plansza[p][q] != 6 && plansza[p + 1][q] != 5 && plansza[p + 1][q] != 6 && plansza[p - 1][q] != 5 && plansza[p - 1][q] != 6)
														{
															licz++;
															tabx[x] = p;
															taby[y] = q;
															x++;
															y++;

														}

													}
													else if (q == 9 && p > 0 && p < 9)
													{
														if (plansza[p][q] != 5 && plansza[p][q] != 6 && plansza[p - 1][q] != 5 && plansza[p - 1][q] != 6 && plansza[p][q - 1] != 5 && plansza[p][q - 1] != 6)
														{
															licz++;
															tabx[x] = p;
															taby[y] = q;
															x++;
															y++;

														}
														else  if (plansza[p][q] != 5 && plansza[p][q] != 6 && plansza[p + 1][q] != 5 && plansza[p + 1][q] != 6 && plansza[p][q - 1] != 5 && plansza[p][q - 1] != 6)
														{
															licz++;
															tabx[x] = p;
															taby[y] = q;
															x++;
															y++;

														}
														else  if (plansza[p][q] != 5 && plansza[p][q] != 6 && plansza[p + 1][q] != 5 && plansza[p + 1][q] != 6 && plansza[p - 1][q] != 5 && plansza[p - 1][q] != 6)
														{
															licz++;
															tabx[x] = p;
															taby[y] = q;
															x++;
															y++;

														}
													}
													else if (p != 0 && p != 9 && q != 0 && q != 9)
													{

														if (plansza[p][q] != 5 && plansza[p][q] != 6 && plansza[p][q + 1] != 5 && plansza[p][q + 1] != 6 && plansza[p][q - 1] != 5 && plansza[p][q - 1] != 6)
														{
															licz++;
															tabx[x] = p;
															taby[y] = q;
															x++;
															y++;

														}
														else if (plansza[p][q] != 5 && plansza[p][q] != 6 && plansza[p - 1][q] != 5 && plansza[p - 1][q] != 6 && plansza[p][q - 1] != 5 && plansza[p][q - 1] != 6)
														{
															licz++;
															tabx[x] = p;
															taby[y] = q;
															x++;
															y++;

														}
														else if (plansza[p][q] != 5 && plansza[p][q] != 6 && plansza[p - 1][q] != 5 && plansza[p - 1][q] != 6 && plansza[p][q + 1] != 5 && plansza[p][q + 1] != 6)
														{
															licz++;
															tabx[x] = p;
															taby[y] = q;
															x++;
															y++;

														}
														else if (plansza[p][q] != 5 && plansza[p][q] != 6 && plansza[p + 1][q] != 5 && plansza[p + 1][q] != 6 && plansza[p][q - 1] != 5 && plansza[p][q - 1] != 6)
														{
															licz++;
															tabx[x] = p;
															taby[y] = q;
															x++;
															y++;

														}
														else if (plansza[p][q] != 5 && plansza[p][q] != 6 && plansza[p + 1][q] != 5 && plansza[p + 1][q] != 6 && plansza[p][q + 1] != 5 && plansza[p][q + 1] != 6)
														{
															licz++;
															tabx[x] = p;
															taby[y] = q;
															x++;
															y++;

														}
														else if (plansza[p][q] != 5 && plansza[p][q] != 6 && plansza[p + 1][q] != 5 && plansza[p + 1][q] != 6 && plansza[p - 1][q] != 5 && plansza[p - 1][q] != 6)
														{
															licz++;
															tabx[x] = p;
															taby[y] = q;
															x++;
															y++;

														}
													}
												}
											}
										}
										if (licz == 0)
										{
											for (int p = 0; p < 10; p++)
											{
												for (int q = 0; q < 10; q++)
												{
													if (p == 0 && q == 0)
													{
														if (plansza[p][q] != 5 && plansza[p][q] != 6 && plansza[p][q + 1] != 5 && plansza[p][q + 1] != 6)
														{
															licz++;
															tabx[x] = p;
															taby[y] = q;
															x++;
															y++;

														}
														else if (plansza[p][q] != 5 && plansza[p][q] != 6 && plansza[p + 1][q] != 5 && plansza[p + 1][q] != 6)
														{
															licz++;
															tabx[x] = p;
															taby[y] = q;
															x++;
															y++;

														}
													}
													else if (p == 0 && q == 9)
													{
														if (plansza[p][q] != 5 && plansza[p][q] != 6 && plansza[p][q - 1] != 5 && plansza[p][q - 1] != 6)
														{
															licz++;
															tabx[x] = p;
															taby[y] = q;
															x++;
															y++;

														}
														else if (plansza[p][q] != 5 && plansza[p][q] != 6 && plansza[p + 1][q] != 5 && plansza[p + 1][q] != 6)
														{
															licz++;
															tabx[x] = p;
															taby[y] = q;
															x++;
															y++;

														}
													}
													else if (p == 9 && q == 0)
													{
														if (plansza[p][q] != 5 && plansza[p][q] != 6 && plansza[p][q + 1] != 5 && plansza[p][q + 1] != 6)
														{
															licz++;
															tabx[x] = p;
															taby[y] = q;
															x++;
															y++;

														}
														else if (plansza[p][q] != 5 && plansza[p][q] != 6 && plansza[p - 1][q] != 5 && plansza[p - 1][q] != 6)
														{
															licz++;
															tabx[x] = p;
															taby[y] = q;
															x++;
															y++;

														}
													}
													else if (p == 9 && q == 9)
													{
														if (plansza[p][q] != 5 && plansza[p][q] != 6 && plansza[p][q - 1] != 5 && plansza[p][q - 1] != 6)
														{
															licz++;
															tabx[x] = p;
															taby[y] = q;
															x++;
															y++;

														}
														else if (plansza[p][q] != 5 && plansza[p][q] != 6 && plansza[p - 1][q] != 5 && plansza[p - 1][q] != 6)
														{
															licz++;
															tabx[x] = p;
															taby[y] = q;
															x++;
															y++;

														}
													}
													else if (p == 0 && q > 0 && q < 9)
													{
														if (plansza[p][q] != 5 && plansza[p][q] != 6 && plansza[p][q - 1] != 5 && plansza[p][q - 1] != 6)
														{
															licz++;
															tabx[x] = p;
															taby[y] = q;
															x++;
															y++;

														}
														else if (plansza[p][q] != 5 && plansza[p][q] != 6 && plansza[p + 1][q] != 5 && plansza[p + 1][q] != 6)
														{
															licz++;
															tabx[x] = p;
															taby[y] = q;
															x++;
															y++;

														}
														else if (plansza[p][q] != 5 && plansza[p][q] != 6 && plansza[p][q + 1] != 5 && plansza[p][q + 1] != 6)
														{
															licz++;
															tabx[x] = p;
															taby[y] = q;
															x++;
															y++;

														}
													}
													else if (p == 9 && q > 0 && q < 9)
													{
														if (plansza[p][q] != 5 && plansza[p][q] != 6 && plansza[p][q - 1] != 5 && plansza[p][q - 1] != 6)
														{
															licz++;
															tabx[x] = p;
															taby[y] = q;
															x++;
															y++;

														}
														else  if (plansza[p][q] != 5 && plansza[p][q] != 6 && plansza[p - 1][q] != 5 && plansza[p - 1][q] != 6)
														{
															licz++;
															tabx[x] = p;
															taby[y] = q;
															x++;
															y++;

														}
														else  if (plansza[p][q] != 5 && plansza[p][q] != 6 && plansza[p][q + 1] != 5 && plansza[p][q + 1] != 6)
														{
															licz++;
															tabx[x] = p;
															taby[y] = q;
															x++;
															y++;

														}


													}
													else if (q == 0 && p > 0 && p < 9)
													{
														if (plansza[p][q] != 5 && plansza[p][q] != 6 && plansza[p][q + 1] != 5 && plansza[p][q + 1] != 6)
														{
															licz++;
															tabx[x] = p;
															taby[y] = q;
															x++;
															y++;

														}
														else if (plansza[p][q] != 5 && plansza[p][q] != 6 && plansza[p + 1][q] != 5 && plansza[p + 1][q] != 6)
														{
															licz++;
															tabx[x] = p;
															taby[y] = q;
															x++;
															y++;

														}
														else if (plansza[p][q] != 5 && plansza[p][q] != 6 && plansza[p - 1][q] != 5 && plansza[p - 1][q] != 6)
														{
															licz++;
															tabx[x] = p;
															taby[y] = q;
															x++;
															y++;

														}

													}
													else if (q == 9 && p > 0 && p < 9)
													{
														if (plansza[p][q] != 5 && plansza[p][q] != 6 && plansza[p][q - 1] != 5 && plansza[p][q - 1] != 6)
														{
															licz++;
															tabx[x] = p;
															taby[y] = q;
															x++;
															y++;

														}
														else  if (plansza[p][q] != 5 && plansza[p][q] != 6 && plansza[p + 1][q] != 5 && plansza[p + 1][q] != 6)
														{
															licz++;
															tabx[x] = p;
															taby[y] = q;
															x++;
															y++;

														}
														else  if (plansza[p][q] != 5 && plansza[p][q] != 6 && plansza[p - 1][q] != 5 && plansza[p - 1][q] != 6)
														{
															licz++;
															tabx[x] = p;
															taby[y] = q;
															x++;
															y++;

														}
													}
													else if (p != 0 && p != 9 && q != 0 && q != 9)
													{

														if (plansza[p][q] != 5 && plansza[p][q] != 6 && plansza[p][q - 1] != 5 && plansza[p][q - 1] != 6)
														{
															licz++;
															tabx[x] = p;
															taby[y] = q;
															x++;
															y++;

														}
														else if (plansza[p][q] != 5 && plansza[p][q] != 6 && plansza[p][q + 1] != 5 && plansza[p][q + 1] != 6)
														{
															licz++;
															tabx[x] = p;
															taby[y] = q;
															x++;
															y++;

														}
														else if (plansza[p][q] != 5 && plansza[p][q] != 6 && plansza[p - 1][q] != 5 && plansza[p - 1][q] != 6)
														{
															licz++;
															tabx[x] = p;
															taby[y] = q;
															x++;
															y++;

														}
														else if (plansza[p][q] != 5 && plansza[p][q] != 6 && plansza[p + 1][q] != 5 && plansza[p + 1][q] != 6)
														{
															licz++;
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
									else if (trojka2_1 == false)
									{
										for (int p = 0; p < 10; p++)
										{
											for (int q = 0; q < 10; q++)
											{
												if (p == 0 && q > 0 && q < 9)
												{
													if (plansza[p][q] != 5 && plansza[p][q] != 6 && plansza[p][q - 1] != 5 && plansza[p][q - 1] != 6 && plansza[p][q + 1] != 5 && plansza[p][q + 1] != 6 && plansza[p + 1][q] != 5 && plansza[p + 1][q] != 6 && plansza[p + 2][q] != 5 && plansza[p + 2][q] != 6)
													{
														licz++;
														tabx[x] = p;
														taby[y] = q;
														x++;
														y++;

													}
												}
												else if (p == 9 && q > 0 && q < 9)
												{
													if (plansza[p][q] != 5 && plansza[p][q] != 6 && plansza[p][q - 1] != 5 && plansza[p][q - 1] != 6 && plansza[p][q + 1] != 5 && plansza[p][q + 1] != 6 && plansza[p - 1][q] != 5 && plansza[p - 1][q] != 6 && plansza[p - 2][q] != 5 && plansza[p - 2][q] != 6)
													{
														licz++;
														tabx[x] = p;
														taby[y] = q;
														x++;
														y++;

													}
												}
												else if (q == 0 && p > 0 && p < 9)
												{
													if (plansza[p][q] != 5 && plansza[p][q] != 6 && plansza[p - 1][q] != 5 && plansza[p - 1][q] != 6 && plansza[p + 1][q] != 5 && plansza[p + 1][q] != 6 && plansza[p][q + 1] != 5 && plansza[p][q + 1] != 6 && plansza[p][q + 2] != 5 && plansza[p][q + 2] != 6)
													{
														licz++;
														tabx[x] = p;
														taby[y] = q;
														x++;
														y++;

													}
												}
												else if (q == 9 && p > 0 && p < 9)
												{
													if (plansza[p][q] != 5 && plansza[p][q] != 6 && plansza[p - 1][q] != 5 && plansza[p - 1][q] != 6 && plansza[p + 1][q] != 5 && plansza[p + 1][q] != 6 && plansza[p][q - 1] != 5 && plansza[p][q - 1] != 6 && plansza[p][q - 2] != 5 && plansza[p][q - 2] != 6)
													{
														licz++;
														tabx[x] = p;
														taby[y] = q;
														x++;
														y++;

													}
												}
												else if (p != 0 && p != 9 && q != 0 && q != 9)
												{
													if (plansza[p][q] != 5 && plansza[p][q] != 6 && plansza[p - 1][q] != 5 && plansza[p - 1][q] != 6 && plansza[p + 1][q] != 5 && plansza[p + 1][q] != 6 && plansza[p][q - 1] != 5 && plansza[p][q - 1] != 6 && plansza[p][q + 1] != 5 && plansza[p][q + 1] != 6)
													{
														licz++;
														tabx[x] = p;
														taby[y] = q;
														x++;
														y++;

													}
												}
											}
										}
										if (licz == 0)
										{
											for (int p = 0; p < 10; p++)
											{
												for (int q = 0; q < 10; q++)
												{
													if (p == 0 && q > 0 && q < 9)
													{
														if (plansza[p][q] != 5 && plansza[p][q] != 6 && plansza[p][q - 1] != 5 && plansza[p][q - 1] != 6 && plansza[p][q + 1] != 5 && plansza[p][q + 1] != 6)
														{
															licz++;
															tabx[x] = p;
															taby[y] = q;
															x++;
															y++;

														}
													}
													else if (p == 9 && q > 0 && q < 9)
													{
														if (plansza[p][q] != 5 && plansza[p][q] != 6 && plansza[p][q - 1] != 5 && plansza[p][q - 1] != 6 && plansza[p][q + 1] != 5 && plansza[p][q + 1] != 6)
														{
															licz++;
															tabx[x] = p;
															taby[y] = q;
															x++;
															y++;

														}
													}
													else if (q == 0 && p > 0 && p < 9)
													{
														if (plansza[p][q] != 5 && plansza[p][q] != 6 && plansza[p - 1][q] != 5 && plansza[p - 1][q] != 6 && plansza[p + 1][q] != 5 && plansza[p + 1][q] != 6)
														{
															licz++;
															tabx[x] = p;
															taby[y] = q;
															x++;
															y++;

														}
													}
													else if (q == 9 && p > 0 && p < 9)
													{
														if (plansza[p][q] != 5 && plansza[p][q] != 6 && plansza[p - 1][q] != 5 && plansza[p - 1][q] != 6 && plansza[p + 1][q] != 5 && plansza[p + 1][q] != 6)
														{
															licz++;
															tabx[x] = p;
															taby[y] = q;
															x++;
															y++;

														}
													}
													else if (p != 0 && p != 9 && q != 0 && q != 9)
													{
														if (plansza[p][q] != 5 && plansza[p][q] != 6 && plansza[p - 1][q] != 5 && plansza[p - 1][q] != 6 && plansza[p + 1][q] != 5 && plansza[p + 1][q] != 6)
														{
															licz++;
															tabx[x] = p;
															taby[y] = q;
															x++;
															y++;

														}
														else if (plansza[p][q] != 5 && plansza[p][q] != 6 && plansza[p][q - 1] != 5 && plansza[p][q - 1] != 6 && plansza[p][q + 1] != 5 && plansza[p][q + 1] != 6)
														{
															licz++;
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
									else if (czworka1_1 == false)
									{
										for (int p = 0; p < 10; p++)
										{
											for (int q = 0; q < 10; q++)
											{
												if (p == 0 && q > 1 && q < 8)
												{
													if (plansza[p][q] != 5 && plansza[p][q] != 6 && plansza[p][q - 1] != 5 && plansza[p][q - 1] != 6 && plansza[p][q + 1] != 5 && plansza[p][q + 1] != 6 && ((plansza[p][q - 2] != 5 && plansza[p][q - 2] != 6) || (plansza[p][q + 2] != 5 && plansza[p][q + 2] != 6)) && plansza[p + 1][q] != 5 && plansza[p + 1][q] != 6 && plansza[p + 2][q] != 5 && plansza[p + 2][q] != 6 && plansza[p + 3][q] != 5 && plansza[p + 3][q] != 6)
													{
														licz++;
														tabx[x] = p;
														taby[y] = q;
														x++;
														y++;

													}
												}
												else if (p == 9 && q > 1 && q < 8)
												{
													if (plansza[p][q] != 5 && plansza[p][q] != 6 && plansza[p][q - 1] != 5 && plansza[p][q - 1] != 6 && plansza[p][q + 1] != 5 && plansza[p][q + 1] != 6 && ((plansza[p][q - 2] != 5 && plansza[p][q - 2] != 6) || (plansza[p][q + 2] != 5 && plansza[p][q + 2] != 6)) && plansza[p - 1][q] != 5 && plansza[p - 1][q] != 6 && plansza[p - 2][q] != 5 && plansza[p - 2][q] != 6 && plansza[p - 3][q] != 5 && plansza[p - 3][q] != 6)
													{
														licz++;
														tabx[x] = p;
														taby[y] = q;
														x++;
														y++;

													}
												}
												else if (q == 0 && p > 1 && p < 8)
												{
													if (plansza[p][q] != 5 && plansza[p][q] != 6 && plansza[p - 1][q] != 5 && plansza[p - 1][q] != 6 && plansza[p + 1][q] != 5 && plansza[p + 1][q] != 6 && ((plansza[p - 2][q] != 5 && plansza[p - 2][q] != 6) || (plansza[p + 2][q] != 5 && plansza[p + 2][q] != 6)) && plansza[p][q + 1] != 5 && plansza[p][q + 1] != 6 && plansza[p][q + 2] != 5 && plansza[p][q + 2] != 6 && plansza[p][q + 3] != 5 && plansza[p][q + 3] != 6)
													{
														licz++;
														tabx[x] = p;
														taby[y] = q;
														x++;
														y++;

													}
												}
												else if (q == 9 && p > 1 && p < 8)
												{
													if (plansza[p][q] != 5 && plansza[p][q] != 6 && plansza[p - 1][q] != 5 && plansza[p - 1][q] != 6 && plansza[p + 1][q] != 5 && plansza[p + 1][q] != 6 && ((plansza[p - 2][q] != 5 && plansza[p - 2][q] != 6) || (plansza[p + 2][q] != 5 && plansza[p + 2][q] != 6)) && plansza[p][q - 1] != 5 && plansza[p][q - 1] != 6 && plansza[p][q - 2] != 5 && plansza[p][q - 2] != 6 && plansza[p][q - 3] != 5 && plansza[p][q + 3] != 6)
													{
														licz++;
														tabx[x] = p;
														taby[y] = q;
														x++;
														y++;

													}
												}
												else if (p != 0 && p != 9 && q != 0 && q != 9 && p != 1 && p != 8 && q != 1 && q != 8)
												{
													if (plansza[p][q] != 5 && plansza[p][q] != 6 && plansza[p][q - 1] != 5 && plansza[p][q - 1] != 6 && plansza[p][q + 1] != 5 && plansza[p][q + 1] != 6 && ((plansza[p][q - 2] != 5 && plansza[p][q - 2] != 6) || (plansza[p][q + 2] != 5 && plansza[p][q + 2] != 6)) && plansza[p - 1][q] != 5 && plansza[p - 1][q] != 6 && plansza[p + 1][q] != 5 && plansza[p + 1][q] != 6 && ((plansza[p - 2][q] != 5 && plansza[p - 2][q] != 6) || (plansza[p + 2][q] != 5 && plansza[p + 2][q] != 6)))
													{
														licz++;
														tabx[x] = p;
														taby[y] = q;
														x++;
														y++;

													}
												}
											}
										}
										if (licz == 0)
										{
											for (int p = 0; p < 10; p++)
											{
												for (int q = 0; q < 10; q++)
												{
													if (p == 0 && q > 1 && q < 8)
													{
														if (plansza[p][q] != 5 && plansza[p][q] != 6 && plansza[p][q - 1] != 5 && plansza[p][q - 1] != 6 && plansza[p][q + 1] != 5 && plansza[p][q + 1] != 6 && ((plansza[p][q - 2] != 5 && plansza[p][q - 2] != 6) || (plansza[p][q + 2] != 5 && plansza[p][q + 2] != 6)))
														{
															licz++;
															tabx[x] = p;
															taby[y] = q;
															x++;
															y++;

														}
													}
													else if (p == 9 && q > 1 && q < 8)
													{
														if (plansza[p][q] != 5 && plansza[p][q] != 6 && plansza[p][q - 1] != 5 && plansza[p][q - 1] != 6 && plansza[p][q + 1] != 5 && plansza[p][q + 1] != 6 && ((plansza[p][q - 2] != 5 && plansza[p][q - 2] != 6) || (plansza[p][q + 2] != 5 && plansza[p][q + 2] != 6)))
														{
															licz++;
															tabx[x] = p;
															taby[y] = q;
															x++;
															y++;

														}
													}
													else if (q == 0 && p > 1 && p < 8)
													{
														if (plansza[p][q] != 5 && plansza[p][q] != 6 && plansza[p - 1][q] != 5 && plansza[p - 1][q] != 6 && plansza[p + 1][q] != 5 && plansza[p + 1][q] != 6 && ((plansza[p - 2][q] != 5 && plansza[p - 2][q] != 6) || (plansza[p + 2][q] != 5 && plansza[p + 2][q] != 6)))
														{
															licz++;
															tabx[x] = p;
															taby[y] = q;
															x++;
															y++;

														}
													}
													else if (q == 9 && p > 1 && p < 8)
													{
														if (plansza[p][q] != 5 && plansza[p][q] != 6 && plansza[p - 1][q] != 5 && plansza[p - 1][q] != 6 && plansza[p + 1][q] != 5 && plansza[p + 1][q] != 6 && ((plansza[p - 2][q] != 5 && plansza[p - 2][q] != 6) || (plansza[p + 2][q] != 5 && plansza[p + 2][q] != 6)))
														{
															licz++;
															tabx[x] = p;
															taby[y] = q;
															x++;
															y++;

														}
													}
													else if (p != 0 && p != 9 && q != 0 && q != 9 && p != 1 && p != 8 && q != 1 && q != 8)
													{
														if (plansza[p][q] != 5 && plansza[p][q] != 6 && plansza[p][q - 1] != 5 && plansza[p][q - 1] != 6 && plansza[p][q + 1] != 5 && plansza[p][q + 1] != 6 && ((plansza[p][q - 2] != 5 && plansza[p][q - 2] != 6) || (plansza[p][q + 2] != 5 && plansza[p][q + 2] != 6)))
														{
															licz++;
															tabx[x] = p;
															taby[y] = q;
															x++;
															y++;

														}
														else if (plansza[p][q] != 5 && plansza[p][q] != 6 && plansza[p - 1][q] != 5 && plansza[p - 1][q] != 6 && plansza[p + 1][q] != 5 && plansza[p + 1][q] != 6 && ((plansza[p - 2][q] != 5 && plansza[p - 2][q] != 6) || (plansza[p + 2][q] != 5 && plansza[p + 2][q] != 6)))
														{
															licz++;
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
										wspolrzedna = wsp(generator);

										graczw = tabx[wspolrzedna];
										graczk = taby[wspolrzedna];
									} while (plansza[graczw][graczk] == 5 || plansza[graczw][graczk] == 6);



								}
								else
								{
									do
									{
										graczw = wierszL(generator);
										graczk = kolumnaL(generator);
									} while (plansza[graczw][graczk] == 6 || plansza[graczw][graczk] == 5);

								}
							}

							else
							{
								if (k_sprawdzKierunek == 0)
								{
									do
									{
										k_kierunek = kierunekL(generator) + 1;
										if (k_wiersz == 0 && k_kierunek == 1) k_kierunek = 0;
										else if (k_wiersz == 9 && k_kierunek == 3) k_kierunek = 0;
										else if (k_kolumna == 0 && k_kierunek == 4) k_kierunek = 0;
										else if (k_kolumna == 9 && k_kierunek == 2) k_kierunek = 0;
										if (k_kierunek == 1 && plansza[k_wiersz - 1][k_kolumna] == 5) k_kierunek = 0;
										else if (k_kierunek == 2 && plansza[k_wiersz][k_kolumna + 1] == 5) k_kierunek = 0;
										else if (k_kierunek == 3 && plansza[k_wiersz + 1][k_kolumna] == 5) k_kierunek = 0;
										else if (k_kierunek == 4 && plansza[k_wiersz][k_kolumna - 1] == 5) k_kierunek = 0;

									} while (k_kierunek == 0);
									if (k_kierunek == 1)
									{
										graczw = k_wiersz - 1;
										graczk = k_kolumna;
										if (plansza[graczw][graczk] == 3 || plansza[graczw][graczk] == 4) k_sprawdzKierunek = 2;

									}
									else if (k_kierunek == 2)
									{
										graczw = k_wiersz;
										graczk = k_kolumna + 1;
										if (plansza[graczw][graczk] == 3 || plansza[graczw][graczk] == 4) k_sprawdzKierunek = 1;

									}
									else if (k_kierunek == 3)
									{
										graczw = k_wiersz + 1;
										graczk = k_kolumna;
										if (plansza[graczw][graczk] == 3 || plansza[graczw][graczk] == 4) k_sprawdzKierunek = 2;

									}
									else if (k_kierunek == 4)
									{
										graczw = k_wiersz;
										graczk = k_kolumna - 1;
										if (plansza[graczw][graczk] == 3 || plansza[graczw][graczk] == 4) k_sprawdzKierunek = 1;

									}
								}

								else if (k_sprawdzKierunek == 1)
								{
									if (plansza[k_wiersz][k_kolumna - 1] != 5 && plansza[k_wiersz][k_kolumna - 1] != 6 && k_kolumna - 1 >= 0)
									{
										graczw = k_wiersz;
										graczk = k_kolumna - 1;
									}
									else if ((plansza[k_wiersz][k_kolumna - 1] == 5 || plansza[k_wiersz][k_kolumna - 1] == 6) && plansza[k_wiersz][k_kolumna + 1] != 5 && plansza[k_wiersz][k_kolumna + 1] != 6 && k_kolumna + 1 <= 9)
									{
										graczw = k_wiersz;
										graczk = k_kolumna + 1;
									}
									else if (plansza[k_wiersz][k_kolumna - 1] == 6 && (plansza[k_wiersz][k_kolumna + 1] == 5 || plansza[k_wiersz][k_kolumna + 1] == 6) && plansza[k_wiersz][k_kolumna - 2] != 5 && plansza[k_wiersz][k_kolumna - 2] != 6 && k_kolumna - 2 >= 0)
									{
										graczw = k_wiersz;
										graczk = k_kolumna - 2;
									}
									else if ((plansza[k_wiersz][k_kolumna - 1] == 5 || plansza[k_wiersz][k_kolumna - 1] == 6) && plansza[k_wiersz][k_kolumna + 1] == 6 && plansza[k_wiersz][k_kolumna + 2] != 5 && plansza[k_wiersz][k_kolumna + 2] != 6 && k_kolumna + 2 <= 9)
									{
										graczw = k_wiersz;
										graczk = k_kolumna + 2;
									}
									else if (plansza[k_wiersz][k_kolumna - 1] == 6 && (plansza[k_wiersz][k_kolumna + 1] == 5 || plansza[k_wiersz][k_kolumna + 1] == 6) && plansza[k_wiersz][k_kolumna - 2] == 6 && plansza[k_wiersz][k_kolumna - 3] != 5 && plansza[k_wiersz][k_kolumna - 3] != 6 && k_kolumna - 3 >= 0)
									{
										graczw = k_wiersz;
										graczk = k_kolumna - 3;
									}
									else if (plansza[k_wiersz][k_kolumna - 1] == 5 && plansza[k_wiersz][k_kolumna + 1] == 6 && plansza[k_wiersz][k_kolumna + 2] == 6 && plansza[k_wiersz][k_kolumna + 3] != 5 && plansza[k_wiersz][k_kolumna + 3] != 6 && k_kolumna + 3 <= 9)
									{
										graczw = k_wiersz;
										graczk = k_kolumna + 3;
									}


								}
								else if (k_sprawdzKierunek == 2)
								{
									if (plansza[k_wiersz - 1][k_kolumna] != 5 && plansza[k_wiersz - 1][k_kolumna] != 6 && k_wiersz - 1 >= 0)
									{
										graczw = k_wiersz - 1;
										graczk = k_kolumna;
									}
									else if ((plansza[k_wiersz - 1][k_kolumna] == 5 || plansza[k_wiersz - 1][k_kolumna] == 6) && plansza[k_wiersz + 1][k_kolumna] != 5 && plansza[k_wiersz + 1][k_kolumna] != 6 && k_wiersz + 1 <= 9)
									{
										graczw = k_wiersz + 1;
										graczk = k_kolumna;
									}
									else if (plansza[k_wiersz - 1][k_kolumna] == 6 && (plansza[k_wiersz + 1][k_kolumna] == 5 || plansza[k_wiersz + 1][k_kolumna] == 6) && plansza[k_wiersz - 2][k_kolumna] != 5 && plansza[k_wiersz - 2][k_kolumna] != 6 && k_wiersz - 2 >= 0)
									{
										graczw = k_wiersz - 2;
										graczk = k_kolumna;
									}
									else if ((plansza[k_wiersz - 1][k_kolumna] == 5 || plansza[k_wiersz - 1][k_kolumna] == 6) && plansza[k_wiersz + 1][k_kolumna] == 6 && plansza[k_wiersz + 2][k_kolumna] != 5 && plansza[k_wiersz + 2][k_kolumna] != 6 && k_wiersz + 2 <= 9)
									{
										graczw = k_wiersz + 2;
										graczk = k_kolumna;
									}
									else if (plansza[k_wiersz - 1][k_kolumna] == 6 && plansza[k_wiersz - 2][k_kolumna] == 6 && plansza[k_wiersz + 1][k_kolumna] == 5 && plansza[k_wiersz - 3][k_kolumna] != 5 && plansza[k_wiersz - 3][k_kolumna] != 6 && k_wiersz - 3 >= 0)
									{
										graczw = k_wiersz - 3;
										graczk = k_kolumna;
									}
									else if (plansza[k_wiersz - 1][k_kolumna] == 5 && plansza[k_wiersz + 1][k_kolumna] == 6 && plansza[k_wiersz + 2][k_kolumna] == 6 && plansza[k_wiersz + 3][k_kolumna] != 5 && plansza[k_wiersz + 3][k_kolumna] != 6 && k_wiersz + 3 <= 9)
									{
										graczw = k_wiersz + 3;
										graczk = k_kolumna;
									}

								}

							}
						}
						if (graczk == 0) cout << "A";
						else if (graczk == 1) cout << "B";
						else if (graczk == 2) cout << "C";
						else if (graczk == 3) cout << "D";
						else if (graczk == 4) cout << "E";
						else if (graczk == 5) cout << "F";
						else if (graczk == 6) cout << "G";
						else if (graczk == 7) cout << "H";
						else if (graczk == 8) cout << "I";
						else if (graczk == 9) cout << "J";
						Sleep(1000);
						cout << graczw + 1;
						Sleep(1500);
					}


					if (kolejGracza1 == true)
					{
						spacje(48);
						cin >> graczw;
						graczw = graczw - 1;
						if (graczkol >= 65 && graczkol <= 74)
						{
							graczk = static_cast<int>(graczkol);
							graczk = graczk - 65;
						}
						else if (graczkol >= 97 && graczkol <= 106)
						{
							graczk = static_cast<int>(graczkol);
							graczk = graczk - 97;
						}
						else
							graczk = static_cast<int>(graczkol);
					}


					system("cls");


					if (kolejGracza1 == false)
					{
						if (graczw > 9 || graczk > 9 || graczw < 0 || graczk < 0)
						{
							if (jedynka1_1 == false)
							{
								SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
								cout << "  " << kratka << "  ";
							}
							else
							{
								SetConsoleTextAttribute(hOut, FOREGROUND_RED);
								cout << "  " << kratka << "  ";
							}
							if (jedynka2_1 == false)
							{
								SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
								cout << kratka << "  ";
							}
							else
							{
								SetConsoleTextAttribute(hOut, FOREGROUND_RED);
								cout << kratka << "  ";
							}
							if (jedynka3_1 == false)
							{
								SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
								cout << kratka << "  ";
							}
							else
							{
								SetConsoleTextAttribute(hOut, FOREGROUND_RED);
								cout << kratka << "  ";
							}
							if (jedynka4_1 == false)
							{
								SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
								cout << kratka;
							}
							else
							{
								SetConsoleTextAttribute(hOut, FOREGROUND_RED);
								cout << kratka;
							}
							SetConsoleTextAttribute(hOut, FOREGROUND_RED);
							spacje(5);
							cout << "Dokonales zlego wyboru! Nie przechodz na ciemna strone mocy i wybierz wlasciwa cyfre!";
							cin.clear();
							cin.ignore(100, '\n');
							spacje(6);
							SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
						}
						else if (plansza[graczw][graczk] == 5 || plansza[graczw][graczk] == 6)
						{
							if (jedynka1_1 == false)
							{
								SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
								cout << "  " << kratka << "  ";
							}
							else
							{
								SetConsoleTextAttribute(hOut, FOREGROUND_RED);
								cout << "  " << kratka << "  ";
							}
							if (jedynka2_1 == false)
							{
								SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
								cout << kratka << "  ";
							}
							else
							{
								SetConsoleTextAttribute(hOut, FOREGROUND_RED);
								cout << kratka << "  ";
							}
							if (jedynka3_1 == false)
							{
								SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
								cout << kratka << "  ";
							}
							else
							{
								SetConsoleTextAttribute(hOut, FOREGROUND_RED);
								cout << kratka << "  ";
							}
							if (jedynka4_1 == false)
							{
								SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
								cout << kratka;
							}
							else
							{
								SetConsoleTextAttribute(hOut, FOREGROUND_RED);
								cout << kratka;
							}
							SetConsoleTextAttribute(hOut, FOREGROUND_RED);
							spacje(22);
							cout << "Przeciez juz tutaj strzelales! Sprobuj jeszcze raz.";
							spacje(23);
							SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
						}

						else
						{
							if (plansza[graczw][graczk] != 1)
							{
								if (jedynka1_1 == false)
								{
									SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
									cout << "  " << kratka << "  ";
								}
								else
								{
									SetConsoleTextAttribute(hOut, FOREGROUND_RED);
									cout << "  " << kratka << "  ";
								}
								if (jedynka2_1 == false)
								{
									SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
									cout << kratka << "  ";
								}
								else
								{
									SetConsoleTextAttribute(hOut, FOREGROUND_RED);
									cout << kratka << "  ";
								}
								if (jedynka3_1 == false)
								{
									SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
									cout << kratka << "  ";
								}
								else
								{
									SetConsoleTextAttribute(hOut, FOREGROUND_RED);
									cout << kratka << "  ";
								}
								if (jedynka4_1 == false)
								{
									SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
									cout << kratka;
								}
								else
								{
									SetConsoleTextAttribute(hOut, FOREGROUND_RED);
									cout << kratka;
								}
							}

							if (plansza[graczw][graczk] == -1 || plansza[graczw][graczk] == 0)
							{
								if (efekty == true)
									PlaySound(L"pusty.wav", NULL, SND_ASYNC);
								plansza[graczw][graczk] = 5;
								SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
								spacje(17);
								cout << "PUSTO ;c";
								spacje(71);
							}
							else if (plansza[graczw][graczk] == 1)
							{
								plansza[graczw][graczk] = 6;
								for (int a = 0; a < 3; a++)
								{
									for (int b = 0; b < 3; b++)
									{
										if (graczk - 1 + a >= 0 && graczk - 1 + a <= 9 && graczw - 1 + b >= 0 && graczw - 1 + b <= 9 && plansza[graczw - 1 + b][graczk - 1 + a] == -1)
											plansza[graczw - 1 + b][graczk - 1 + a] = 5;
									}
								}
								if (jedynka1_1 == false) jedynka1_1 = true;
								else if (jedynka1_1 == true && jedynka2_1 == false) jedynka2_1 = true;
								else if (jedynka1_1 == true && jedynka2_1 == true && jedynka3_1 == false) jedynka3_1 = true;
								else if (jedynka1_1 == true && jedynka2_1 == true && jedynka3_1 == true) jedynka4_1 = true;
								if (jedynka1_1 == false)
								{
									SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
									cout << "  " << kratka << "  ";
								}
								else
								{
									SetConsoleTextAttribute(hOut, FOREGROUND_RED);
									cout << "  " << kratka << "  ";
								}
								if (jedynka2_1 == false)
								{
									SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
									cout << kratka << "  ";
								}
								else
								{
									SetConsoleTextAttribute(hOut, FOREGROUND_RED);
									cout << kratka << "  ";
								}
								if (jedynka3_1 == false)
								{
									SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
									cout << kratka << "  ";
								}
								else
								{
									SetConsoleTextAttribute(hOut, FOREGROUND_RED);
									cout << kratka << "  ";
								}
								if (jedynka4_1 == false)
								{
									SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
									cout << kratka;
								}
								else
								{
									SetConsoleTextAttribute(hOut, FOREGROUND_RED);
									cout << kratka;
								}
								SetConsoleTextAttribute(hOut, FOREGROUND_GREEN);
								spacje(11);
								cout << "TRAFIONY, ZATOPIONY!";
								if (efekty == true)
									PlaySound(L"zatopiony.wav", NULL, SND_ASYNC);
								spacje(65);

							}
							else if (plansza[graczw][graczk] == 2)
							{
								plansza[graczw][graczk] = 6;

								if (plansza[graczw + 1][graczk] != 6 && plansza[graczw - 1][graczk] != 6 && plansza[graczw][graczk + 1] != 6 && plansza[graczw][graczk - 1] != 6)
								{

									SetConsoleTextAttribute(hOut, FOREGROUND_RED);
									spacje(17);
									cout << "TRAFIONY!";
									if (efekty == true)
										PlaySound(L"trafiony.wav", NULL, SND_ASYNC);
									k_trafiony = true;
									if (k_wiersz == -1 && k_kolumna == -1)
									{
										k_wiersz = graczw;
										k_kolumna = graczk;
									}
									spacje(70);
								}
								else if (plansza[graczw + 1][graczk] == 6)
								{
									for (int a = 0; a < 3; a++)
									{
										for (int b = 0; b < 4; b++)
										{
											if (graczk - 1 + a >= 0 && graczk - 1 + a <= 9 && graczw - 1 + b >= 0 && graczw - 1 + b <= 9 && plansza[graczw - 1 + b][graczk - 1 + a] == -1)
												plansza[graczw - 1 + b][graczk - 1 + a] = 5;
										}


									}

									SetConsoleTextAttribute(hOut, FOREGROUND_GREEN);
									spacje(11);
									cout << "TRAFIONY, ZATOPIONY!";
									if (efekty == true)
										PlaySound(L"zatopiony.wav", NULL, SND_ASYNC);
									k_trafiony = false;
									k_wiersz = -1;
									k_kolumna = -1;
									k_kierunek = 0;
									k_sprawdzKierunek = 0;
									spacje(65);
									if (dwojka1_1 == false) dwojka1_1 = true;
									else if (dwojka1_1 == true && dwojka2_1 == false) dwojka2_1 = true;
									else if (dwojka1_1 == true && dwojka2_1 == true) dwojka3_1 = true;

								}
								else if (plansza[graczw][graczk + 1] == 6)
								{
									for (int a = 0; a < 3; a++)
									{
										for (int b = 0; b < 4; b++)
										{
											if (graczw - 1 + a >= 0 && graczw - 1 + a <= 9 && graczk - 1 + b >= 0 && graczk - 1 + b <= 9 && plansza[graczw - 1 + a][graczk - 1 + b] == -1)
												plansza[graczw - 1 + a][graczk - 1 + b] = 5;
										}
									}

									SetConsoleTextAttribute(hOut, FOREGROUND_GREEN);
									spacje(11);
									cout << "TRAFIONY, ZATOPIONY!";
									if (efekty == true)
										PlaySound(L"zatopiony.wav", NULL, SND_ASYNC);
									k_trafiony = false;
									k_wiersz = -1;
									k_kolumna = -1;
									k_kierunek = 0;
									k_sprawdzKierunek = 0;
									spacje(65);
									if (dwojka1_1 == false) dwojka1_1 = true;
									else if (dwojka1_1 == true && dwojka2_1 == false) dwojka2_1 = true;
									else if (dwojka1_1 == true && dwojka2_1 == true) dwojka3_1 = true;
								}
								else if (plansza[graczw - 1][graczk] == 6)
								{
									for (int a = 0; a < 3; a++)
									{
										for (int b = 0; b < 4; b++)
										{
											if (graczk - 1 + a >= 0 && graczk - 1 + a <= 9 && graczw + 1 - b >= 0 && graczw + 1 - b <= 9 && plansza[graczw + 1 - b][graczk - 1 + a] == -1)
												plansza[graczw + 1 - b][graczk - 1 + a] = 5;
										}
									}

									SetConsoleTextAttribute(hOut, FOREGROUND_GREEN);
									spacje(11);
									cout << "TRAFIONY, ZATOPIONY!";
									if (efekty == true)
										PlaySound(L"zatopiony.wav", NULL, SND_ASYNC);
									k_trafiony = false;
									k_wiersz = -1;
									k_kolumna = -1;
									k_kierunek = 0;
									k_sprawdzKierunek = 0;
									spacje(65);
									if (dwojka1_1 == false) dwojka1_1 = true;
									else if (dwojka1_1 == true && dwojka2_1 == false) dwojka2_1 = true;
									else if (dwojka1_1 == true && dwojka2_1 == true) dwojka3_1 = true;
								}
								else if (plansza[graczw][graczk - 1] == 6)
								{
									for (int a = 0; a < 3; a++)
									{
										for (int b = 0; b < 4; b++)
										{
											if (graczw - 1 + a >= 0 && graczw - 1 + a <= 9 && graczk + 1 - b >= 0 && graczk + 1 - b <= 9 && plansza[graczw - 1 + a][graczk + 1 - b] == -1)
												plansza[graczw - 1 + a][graczk + 1 - b] = 5;
										}
									}

									SetConsoleTextAttribute(hOut, FOREGROUND_GREEN);
									spacje(11);
									cout << "TRAFIONY, ZATOPIONY!";
									if (efekty == true)
										PlaySound(L"zatopiony.wav", NULL, SND_ASYNC);
									k_trafiony = false;
									k_wiersz = -1;
									k_kolumna = -1;
									k_kierunek = 0;
									k_sprawdzKierunek = 0;
									spacje(65);
									if (dwojka1_1 == false) dwojka1_1 = true;
									else if (dwojka1_1 == true && dwojka2_1 == false) dwojka2_1 = true;
									else if (dwojka1_1 == true && dwojka2_1 == true) dwojka3_1 = true;
								}
							}
							else if (plansza[graczw][graczk] == 3)
							{
								plansza[graczw][graczk] = 6;

								if (plansza[graczw - 1][graczk] == 3 && plansza[graczw - 2][graczk] == 3)
								{

									SetConsoleTextAttribute(hOut, FOREGROUND_RED);
									spacje(17);
									cout << "TRAFIONY!";
									if (efekty == true)
										PlaySound(L"trafiony.wav", NULL, SND_ASYNC);
									k_trafiony = true;
									if (k_wiersz == -1 && k_kolumna == -1)
									{
										k_wiersz = graczw;
										k_kolumna = graczk;
									}
									spacje(70);
								}
								else if (plansza[graczw - 1][graczk] == 6 && plansza[graczw - 2][graczk] == 3)
								{

									SetConsoleTextAttribute(hOut, FOREGROUND_RED);
									spacje(17);
									cout << "TRAFIONY!";
									if (efekty == true)
										PlaySound(L"trafiony.wav", NULL, SND_ASYNC);
									k_trafiony = true;
									if (k_wiersz == -1 && k_kolumna == -1)
									{
										k_wiersz = graczw;
										k_kolumna = graczk;
									}
									spacje(70);
								}
								else if (plansza[graczw - 1][graczk] == 3 && plansza[graczw - 2][graczk] == 6)
								{

									SetConsoleTextAttribute(hOut, FOREGROUND_RED);
									spacje(17);
									cout << "TRAFIONY!";
									if (efekty == true)
										PlaySound(L"trafiony.wav", NULL, SND_ASYNC);
									k_trafiony = true;
									if (k_wiersz == -1 && k_kolumna == -1)
									{
										k_wiersz = graczw;
										k_kolumna = graczk;
									}
									spacje(70);
								}
								else if (plansza[graczw - 1][graczk] == 6 && plansza[graczw - 2][graczk] == 6)
								{
									for (int a = 0; a < 3; a++)
									{
										for (int b = 0; b < 5; b++)
										{
											if (graczk - 1 + a >= 0 && graczk - 1 + a <= 9 && graczw + 1 - b >= 0 && graczw + 1 - b <= 9 && plansza[graczw + 1 - b][graczk - 1 + a] == -1)
												plansza[graczw + 1 - b][graczk - 1 + a] = 5;
										}


									}

									SetConsoleTextAttribute(hOut, FOREGROUND_GREEN);
									spacje(11);
									cout << "TRAFIONY, ZATOPIONY!";
									if (efekty == true)
										PlaySound(L"zatopiony.wav", NULL, SND_ASYNC);
									k_trafiony = false;
									k_wiersz = -1;
									k_kolumna = -1;
									k_kierunek = 0;
									k_sprawdzKierunek = 0;
									spacje(65);
									if (trojka1_1 == false) trojka1_1 = true;
									else if (trojka1_1 == true) trojka2_1 = true;
								}

								else if (plansza[graczw - 1][graczk] == 3 && plansza[graczw + 1][graczk] == 3)
								{

									SetConsoleTextAttribute(hOut, FOREGROUND_RED);
									spacje(17);
									cout << "TRAFIONY!";
									if (efekty == true)
										PlaySound(L"trafiony.wav", NULL, SND_ASYNC);
									k_trafiony = true;
									if (k_wiersz == -1 && k_kolumna == -1)
									{
										k_wiersz = graczw;
										k_kolumna = graczk;
									}
									spacje(70);
								}
								else if (plansza[graczw - 1][graczk] == 6 && plansza[graczw + 1][graczk] == 3)
								{

									SetConsoleTextAttribute(hOut, FOREGROUND_RED);
									spacje(17);
									cout << "TRAFIONY!";
									if (efekty == true)
										PlaySound(L"trafiony.wav", NULL, SND_ASYNC);
									k_trafiony = true;
									if (k_wiersz == -1 && k_kolumna == -1)
									{
										k_wiersz = graczw;
										k_kolumna = graczk;
									}
									spacje(70);
								}
								else if (plansza[graczw - 1][graczk] == 3 && plansza[graczw + 1][graczk] == 6)
								{

									SetConsoleTextAttribute(hOut, FOREGROUND_RED);
									spacje(17);
									cout << "TRAFIONY!";
									if (efekty == true)
										PlaySound(L"trafiony.wav", NULL, SND_ASYNC);
									k_trafiony = true;
									if (k_wiersz == -1 && k_kolumna == -1)
									{
										k_wiersz = graczw;
										k_kolumna = graczk;
									}
									spacje(70);
								}
								else if (plansza[graczw - 1][graczk] == 6 && plansza[graczw + 1][graczk] == 6)
								{
									for (int a = 0; a < 3; a++)
									{
										for (int b = 0; b < 5; b++)
										{
											if (graczk - 1 + a >= 0 && graczk - 1 + a <= 9 && graczw + 2 - b >= 0 && graczw + 2 - b <= 9 && plansza[graczw + 2 - b][graczk - 1 + a] == -1)
												plansza[graczw + 2 - b][graczk - 1 + a] = 5;
										}


									}

									SetConsoleTextAttribute(hOut, FOREGROUND_GREEN);
									spacje(11);
									cout << "TRAFIONY, ZATOPIONY!";
									if (efekty == true)
										PlaySound(L"zatopiony.wav", NULL, SND_ASYNC);
									k_trafiony = false;
									k_wiersz = -1;
									k_kolumna = -1;
									k_kierunek = 0;
									k_sprawdzKierunek = 0;
									spacje(65);
									if (trojka1_1 == false) trojka1_1 = true;
									else if (trojka1_1 == true) trojka2_1 = true;
								}
								else if (plansza[graczw + 1][graczk] == 3 && plansza[graczw + 2][graczk] == 3)
								{

									SetConsoleTextAttribute(hOut, FOREGROUND_RED);
									spacje(17);
									cout << "TRAFIONY!";
									if (efekty == true)
										PlaySound(L"trafiony.wav", NULL, SND_ASYNC);
									k_trafiony = true;
									if (k_wiersz == -1 && k_kolumna == -1)
									{
										k_wiersz = graczw;
										k_kolumna = graczk;
									}
									spacje(70);
								}
								else if (plansza[graczw + 1][graczk] == 6 && plansza[graczw + 2][graczk] == 3)
								{

									SetConsoleTextAttribute(hOut, FOREGROUND_RED);
									spacje(17);
									cout << "TRAFIONY!";
									if (efekty == true)
										PlaySound(L"trafiony.wav", NULL, SND_ASYNC);
									k_trafiony = true;
									if (k_wiersz == -1 && k_kolumna == -1)
									{
										k_wiersz = graczw;
										k_kolumna = graczk;
									}
									spacje(70);
								}
								else if (plansza[graczw + 1][graczk] == 3 && plansza[graczw + 2][graczk] == 6)
								{

									SetConsoleTextAttribute(hOut, FOREGROUND_RED);
									spacje(17);
									cout << "TRAFIONY!";
									if (efekty == true)
										PlaySound(L"trafiony.wav", NULL, SND_ASYNC);
									k_trafiony = true;
									if (k_wiersz == -1 && k_kolumna == -1)
									{
										k_wiersz = graczw;
										k_kolumna = graczk;
									}
									spacje(70);
								}
								else if (plansza[graczw + 1][graczk] == 6 && plansza[graczw + 2][graczk] == 6)
								{
									for (int a = 0; a < 3; a++)
									{
										for (int b = 0; b < 5; b++)
										{
											if (graczk - 1 + a >= 0 && graczk - 1 + a <= 9 && graczw - 1 + b >= 0 && graczw - 1 + b <= 9 && plansza[graczw - 1 + b][graczk - 1 + a] == -1)
												plansza[graczw - 1 + b][graczk - 1 + a] = 5;
										}


									}

									SetConsoleTextAttribute(hOut, FOREGROUND_GREEN);
									spacje(11);
									cout << "TRAFIONY, ZATOPIONY!";
									if (efekty == true)
										PlaySound(L"zatopiony.wav", NULL, SND_ASYNC);
									k_trafiony = false;
									k_wiersz = -1;
									k_kolumna = -1;
									k_kierunek = 0;
									k_sprawdzKierunek = 0;
									spacje(65);
									if (trojka1_1 == false) trojka1_1 = true;
									else if (trojka1_1 == true) trojka2_1 = true;
								}

								else if (plansza[graczw][graczk + 1] == 3 && plansza[graczw][graczk + 2] == 3)
								{

									SetConsoleTextAttribute(hOut, FOREGROUND_RED);
									spacje(17);
									cout << "TRAFIONY!";
									if (efekty == true)
										PlaySound(L"trafiony.wav", NULL, SND_ASYNC);
									k_trafiony = true;
									if (k_wiersz == -1 && k_kolumna == -1)
									{
										k_wiersz = graczw;
										k_kolumna = graczk;
									}
									spacje(70);
								}
								else if (plansza[graczw][graczk + 1] == 6 && plansza[graczw][graczk + 2] == 3)
								{

									SetConsoleTextAttribute(hOut, FOREGROUND_RED);
									spacje(17);
									cout << "TRAFIONY!";
									if (efekty == true)
										PlaySound(L"trafiony.wav", NULL, SND_ASYNC);
									k_trafiony = true;
									if (k_wiersz == -1 && k_kolumna == -1)
									{
										k_wiersz = graczw;
										k_kolumna = graczk;
									}
									spacje(70);
								}
								else if (plansza[graczw][graczk + 1] == 3 && plansza[graczw][graczk + 2] == 6)
								{

									SetConsoleTextAttribute(hOut, FOREGROUND_RED);
									spacje(17);
									cout << "TRAFIONY!";
									if (efekty == true)
										PlaySound(L"trafiony.wav", NULL, SND_ASYNC);
									k_trafiony = true;
									if (k_wiersz == -1 && k_kolumna == -1)
									{
										k_wiersz = graczw;
										k_kolumna = graczk;
									}
									spacje(70);
								}
								else if (plansza[graczw][graczk + 1] == 6 && plansza[graczw][graczk + 2] == 6)
								{
									for (int a = 0; a < 3; a++)
									{
										for (int b = 0; b < 5; b++)
										{
											if (graczk - 1 + b >= 0 && graczk - 1 + b <= 9 && graczw - 1 + a >= 0 && graczw - 1 + a <= 9 && plansza[graczw - 1 + a][graczk - 1 + b] == -1)
												plansza[graczw - 1 + a][graczk - 1 + b] = 5;
										}
									}

									SetConsoleTextAttribute(hOut, FOREGROUND_GREEN);
									spacje(11);
									cout << "TRAFIONY, ZATOPIONY!";
									if (efekty == true)
										PlaySound(L"zatopiony.wav", NULL, SND_ASYNC);
									k_trafiony = false;
									k_wiersz = -1;
									k_kolumna = -1;
									k_kierunek = 0;
									k_sprawdzKierunek = 0;
									spacje(65);
									if (trojka1_1 == false) trojka1_1 = true;
									else if (trojka1_1 == true) trojka2_1 = true;
								}

								else if (plansza[graczw][graczk - 1] == 3 && plansza[graczw][graczk + 1] == 3)
								{

									SetConsoleTextAttribute(hOut, FOREGROUND_RED);
									spacje(17);
									cout << "TRAFIONY!";
									if (efekty == true)
										PlaySound(L"trafiony.wav", NULL, SND_ASYNC);
									k_trafiony = true;
									if (k_wiersz == -1 && k_kolumna == -1)
									{
										k_wiersz = graczw;
										k_kolumna = graczk;
									}
									spacje(70);
								}
								else if (plansza[graczw][graczk - 1] == 6 && plansza[graczw][graczk + 1] == 3)
								{

									SetConsoleTextAttribute(hOut, FOREGROUND_RED);
									spacje(17);
									cout << "TRAFIONY!";
									if (efekty == true)
										PlaySound(L"trafiony.wav", NULL, SND_ASYNC);
									k_trafiony = true;
									if (k_wiersz == -1 && k_kolumna == -1)
									{
										k_wiersz = graczw;
										k_kolumna = graczk;
									}
									spacje(70);
								}
								else if (plansza[graczw][graczk - 1] == 3 && plansza[graczw][graczk + 1] == 6)
								{

									SetConsoleTextAttribute(hOut, FOREGROUND_RED);
									spacje(17);
									cout << "TRAFIONY!";
									if (efekty == true)
										PlaySound(L"trafiony.wav", NULL, SND_ASYNC);
									k_trafiony = true;
									if (k_wiersz == -1 && k_kolumna == -1)
									{
										k_wiersz = graczw;
										k_kolumna = graczk;
									}
									spacje(70);
								}
								else if (plansza[graczw][graczk - 1] == 6 && plansza[graczw][graczk + 1] == 6)
								{
									for (int a = 0; a < 3; a++)
									{
										for (int b = 0; b < 5; b++)
										{
											if (graczk - 2 + b >= 0 && graczk - 2 + b <= 9 && graczw - 1 + a >= 0 && graczw - 1 + a <= 9 && plansza[graczw - 1 + a][graczk - 2 + b] == -1)
												plansza[graczw - 1 + a][graczk - 2 + b] = 5;
										}
									}

									SetConsoleTextAttribute(hOut, FOREGROUND_GREEN);
									spacje(11);
									cout << "TRAFIONY, ZATOPIONY!";
									if (efekty == true)
										PlaySound(L"zatopiony.wav", NULL, SND_ASYNC);
									k_trafiony = false;
									k_wiersz = -1;
									k_kolumna = -1;
									k_kierunek = 0;
									k_sprawdzKierunek = 0;
									spacje(65);
									if (trojka1_1 == false) trojka1_1 = true;
									else if (trojka1_1 == true) trojka2_1 = true;
								}
								else if (plansza[graczw][graczk - 1] == 3 && plansza[graczw][graczk - 2] == 3)
								{

									SetConsoleTextAttribute(hOut, FOREGROUND_RED);
									spacje(17);
									cout << "TRAFIONY!";
									if (efekty == true)
										PlaySound(L"trafiony.wav", NULL, SND_ASYNC);
									k_trafiony = true;
									if (k_wiersz == -1 && k_kolumna == -1)
									{
										k_wiersz = graczw;
										k_kolumna = graczk;
									}
									spacje(70);
								}
								else if (plansza[graczw][graczk - 1] == 6 && plansza[graczw][graczk - 2] == 3)
								{

									SetConsoleTextAttribute(hOut, FOREGROUND_RED);
									spacje(17);
									cout << "TRAFIONY!";
									if (efekty == true)
										PlaySound(L"trafiony.wav", NULL, SND_ASYNC);
									k_trafiony = true;
									if (k_wiersz == -1 && k_kolumna == -1)
									{
										k_wiersz = graczw;
										k_kolumna = graczk;
									}
									spacje(70);
								}
								else if (plansza[graczw][graczk - 1] == 3 && plansza[graczw][graczk - 2] == 6)
								{

									SetConsoleTextAttribute(hOut, FOREGROUND_RED);
									spacje(17);
									cout << "TRAFIONY!";
									if (efekty == true)
										PlaySound(L"trafiony.wav", NULL, SND_ASYNC);
									k_trafiony = true;
									if (k_wiersz == -1 && k_kolumna == -1)
									{
										k_wiersz = graczw;
										k_kolumna = graczk;
									}
									spacje(70);
								}
								else if (plansza[graczw][graczk - 1] == 6 && plansza[graczw][graczk - 2] == 6)
								{
									for (int a = 0; a < 3; a++)
									{
										for (int b = 0; b < 5; b++)
										{
											if (graczk - 3 + b >= 0 && graczk - 3 + b <= 9 && graczw - 1 + a >= 0 && graczw - 1 + a <= 9 && plansza[graczw - 1 + a][graczk - 3 + b] == -1)
												plansza[graczw - 1 + a][graczk - 3 + b] = 5;
										}
									}

									SetConsoleTextAttribute(hOut, FOREGROUND_GREEN);
									spacje(11);
									cout << "TRAFIONY, ZATOPIONY!";
									if (efekty == true)
										PlaySound(L"zatopiony.wav", NULL, SND_ASYNC);
									k_trafiony = false;
									k_wiersz = -1;
									k_kolumna = -1;
									k_kierunek = 0;
									k_sprawdzKierunek = 0;
									spacje(65);
									if (trojka1_1 == false) trojka1_1 = true;
									else if (trojka1_1 == true) trojka2_1 = true;
								}

							}
							else if (plansza[graczw][graczk] == 4)
							{
								plansza[graczw][graczk] = 6;
								czworka++;
								if (czworka != 4)
								{

									SetConsoleTextAttribute(hOut, FOREGROUND_RED);
									spacje(17);
									cout << "TRAFIONY!";
									if (efekty == true)
										PlaySound(L"trafiony.wav", NULL, SND_ASYNC);
									k_trafiony = true;
									if (k_wiersz == -1 && k_kolumna == -1)
									{
										k_wiersz = graczw;
										k_kolumna = graczk;
									}
									spacje(70);
								}
								else if (czworka == 4)
								{
									if (plansza[graczw][graczk + 1] == 6 && plansza[graczw][graczk + 2] == 6 && plansza[graczw][graczk + 3] == 6)
									{
										for (int a = 0; a < 3; a++)
										{
											for (int b = 0; b < 6; b++)
											{
												if (graczw - 1 + a >= 0 && graczw - 1 + a <= 9 && graczk - 1 + b >= 0 && graczk - 1 + b <= 9 && plansza[graczw - 1 + a][graczk - 1 + b] == -1)
													plansza[graczw - 1 + a][graczk - 1 + b] = 5;
											}
										}

										SetConsoleTextAttribute(hOut, FOREGROUND_GREEN);
										spacje(11);
										cout << "TRAFIONY, ZATOPIONY!";
										if (efekty == true)
											PlaySound(L"zatopiony.wav", NULL, SND_ASYNC);
										k_trafiony = false;
										k_wiersz = -1;
										k_kolumna = -1;
										k_kierunek = 0;
										k_sprawdzKierunek = 0;
										spacje(65);
										czworka1_1 = true;
									}
									else if (plansza[graczw][graczk - 1] == 6 && plansza[graczw][graczk + 1] == 6 && plansza[graczw][graczk + 2] == 6)
									{
										for (int a = 0; a < 3; a++)
										{
											for (int b = 0; b < 6; b++)
											{
												if (graczw - 1 + a >= 0 && graczw - 1 + a <= 9 && graczk - 2 + b >= 0 && graczk - 2 + b <= 9 && plansza[graczw - 1 + a][graczk - 2 + b] == -1)
													plansza[graczw - 1 + a][graczk - 2 + b] = 5;
											}
										}

										SetConsoleTextAttribute(hOut, FOREGROUND_GREEN);
										spacje(11);
										cout << "TRAFIONY, ZATOPIONY!";
										if (efekty == true)
											PlaySound(L"zatopiony.wav", NULL, SND_ASYNC);
										k_trafiony = false;
										k_wiersz = -1;
										k_kolumna = -1;
										k_kierunek = 0;
										k_sprawdzKierunek = 0;
										spacje(65);
										czworka1_1 = true;
									}
									else if (plansza[graczw][graczk - 1] == 6 && plansza[graczw][graczk - 2] == 6 && plansza[graczw][graczk - 3] == 6)
									{
										for (int a = 0; a < 3; a++)
										{
											for (int b = 0; b < 6; b++)
											{
												if (graczw - 1 + a >= 0 && graczw - 1 + a <= 9 && graczk + 1 - b >= 0 && graczk + 1 - b <= 9 && plansza[graczw - 1 + a][graczk + 1 - b] == -1)
													plansza[graczw - 1 + a][graczk + 1 - b] = 5;
											}
										}

										SetConsoleTextAttribute(hOut, FOREGROUND_GREEN);
										spacje(11);
										cout << "TRAFIONY, ZATOPIONY!";
										if (efekty == true)
											PlaySound(L"zatopiony.wav", NULL, SND_ASYNC);
										k_trafiony = false;
										k_wiersz = -1;
										k_kolumna = -1;
										k_kierunek = 0;
										k_sprawdzKierunek = 0;
										spacje(65);
										czworka1_1 = true;
									}
									else if (plansza[graczw][graczk - 1] == 6 && plansza[graczw][graczk + 1] == 6 && plansza[graczw][graczk - 2] == 6)
									{
										for (int a = 0; a < 3; a++)
										{
											for (int b = 0; b < 6; b++)
											{
												if (graczw - 1 + a >= 0 && graczw - 1 + a <= 9 && graczk + 2 - b >= 0 && graczk + 2 - b <= 9 && plansza[graczw - 1 + a][graczk + 2 - b] == -1)
													plansza[graczw - 1 + a][graczk + 2 - b] = 5;
											}
										}

										SetConsoleTextAttribute(hOut, FOREGROUND_GREEN);
										spacje(11);
										cout << "TRAFIONY, ZATOPIONY!";
										if (efekty == true)
											PlaySound(L"zatopiony.wav", NULL, SND_ASYNC);
										k_trafiony = false;
										k_wiersz = -1;
										k_kolumna = -1;
										k_kierunek = 0;
										k_sprawdzKierunek = 0;
										spacje(65);
										czworka1_1 = true;
									}
									else if (plansza[graczw + 1][graczk] == 6 && plansza[graczw + 2][graczk] == 6 && plansza[graczw + 3][graczk] == 6)
									{
										for (int a = 0; a < 3; a++)
										{
											for (int b = 0; b < 6; b++)
											{
												if (graczk - 1 + a >= 0 && graczk - 1 + a <= 9 && graczw - 1 + b >= 0 && graczw - 1 + b <= 9 && plansza[graczw - 1 + b][graczk - 1 + a] == -1)
													plansza[graczw - 1 + b][graczk - 1 + a] = 5;
											}
										}

										SetConsoleTextAttribute(hOut, FOREGROUND_GREEN);
										spacje(11);
										cout << "TRAFIONY, ZATOPIONY!";
										if (efekty == true)
											PlaySound(L"zatopiony.wav", NULL, SND_ASYNC);
										k_trafiony = false;
										k_wiersz = -1;
										k_kolumna = -1;
										k_kierunek = 0;
										k_sprawdzKierunek = 0;
										spacje(65);
										czworka1_1 = true;
									}
									else if (plansza[graczw + 1][graczk] == 6 && plansza[graczw - 1][graczk] == 6 && plansza[graczw + 2][graczk] == 6)
									{
										for (int a = 0; a < 3; a++)
										{
											for (int b = 0; b < 6; b++)
											{
												if (graczk - 1 + a >= 0 && graczk - 1 + a <= 9 && graczw - 2 + b >= 0 && graczw - 2 + b <= 9 && plansza[graczw - 2 + b][graczk - 1 + a] == -1)
													plansza[graczw - 2 + b][graczk - 1 + a] = 5;
											}
										}

										SetConsoleTextAttribute(hOut, FOREGROUND_GREEN);
										spacje(11);
										cout << "TRAFIONY, ZATOPIONY!";
										if (efekty == true)
											PlaySound(L"zatopiony.wav", NULL, SND_ASYNC);
										k_trafiony = false;
										k_wiersz = -1;
										k_kolumna = -1;
										k_kierunek = 0;
										k_sprawdzKierunek = 0;
										spacje(65);
										czworka1_1 = true;
									}
									else if (plansza[graczw - 1][graczk] == 6 && plansza[graczw - 2][graczk] == 6 && plansza[graczw - 3][graczk] == 6)
									{
										for (int a = 0; a < 3; a++)
										{
											for (int b = 0; b < 6; b++)
											{
												if (graczk - 1 + a >= 0 && graczk - 1 + a <= 9 && graczw + 1 - b >= 0 && graczw + 1 - b <= 9 && plansza[graczw + 1 - b][graczk - 1 + a] == -1)
													plansza[graczw + 1 - b][graczk - 1 + a] = 5;
											}
										}

										SetConsoleTextAttribute(hOut, FOREGROUND_GREEN);
										spacje(11);
										cout << "TRAFIONY, ZATOPIONY!";
										if (efekty == true)
											PlaySound(L"zatopiony.wav", NULL, SND_ASYNC);
										k_trafiony = false;
										k_wiersz = -1;
										k_kolumna = -1;
										k_kierunek = 0;
										k_sprawdzKierunek = 0;
										spacje(65);
										czworka1_1 = true;
									}
									else if (plansza[graczw + 1][graczk] == 6 && plansza[graczw - 1][graczk] == 6 && plansza[graczw - 2][graczk] == 6)
									{
										for (int a = 0; a < 3; a++)
										{
											for (int b = 0; b < 6; b++)
											{
												if (graczk - 1 + a >= 0 && graczk - 1 + a <= 9 && graczw + 2 - b >= 0 && graczw + 2 - b <= 9 && plansza[graczw + 2 - b][graczk - 1 + a] == -1)
													plansza[graczw + 2 - b][graczk - 1 + a] = 5;
											}
										}

										SetConsoleTextAttribute(hOut, FOREGROUND_GREEN);
										spacje(11);
										cout << "TRAFIONY, ZATOPIONY!";
										if (efekty == true)
											PlaySound(L"zatopiony.wav", NULL, SND_ASYNC);
										k_trafiony = false;
										k_wiersz = -1;
										k_kolumna = -1;
										k_kierunek = 0;
										k_sprawdzKierunek = 0;
										spacje(65);
										czworka1_1 = true;
									}
								}
							}

							if (plansza[graczw][graczk] == 6)
							{
								kolejGracza1 = false;
							}
							else
								kolejGracza1 = true;

						}

					}
					else
					{
						if (graczw > 9 || graczk > 9 || graczw < 0 || graczk < 0)
						{
							if (jedynka1_1 == false)
							{
								SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
								cout << "  " << kratka << "  ";
							}
							else
							{
								SetConsoleTextAttribute(hOut, FOREGROUND_RED);
								cout << "  " << kratka << "  ";
							}
							if (jedynka2_1 == false)
							{
								SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
								cout << kratka << "  ";
							}
							else
							{
								SetConsoleTextAttribute(hOut, FOREGROUND_RED);
								cout << kratka << "  ";
							}
							if (jedynka3_1 == false)
							{
								SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
								cout << kratka << "  ";
							}
							else
							{
								SetConsoleTextAttribute(hOut, FOREGROUND_RED);
								cout << kratka << "  ";
							}
							if (jedynka4_1 == false)
							{
								SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
								cout << kratka;
							}
							else
							{
								SetConsoleTextAttribute(hOut, FOREGROUND_RED);
								cout << kratka;
							}
							SetConsoleTextAttribute(hOut, FOREGROUND_RED);
							spacje(5);
							cout << "Dokonales zlego wyboru! Nie przechodz na ciemna strone mocy i wybierz wlasciwa cyfre!";
							cin.clear();
							cin.ignore(100, '\n');
							spacje(6);
							SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
						}
						else if (plansza2[graczw][graczk] == 5 || plansza2[graczw][graczk] == 6)
						{
							if (jedynka1_1 == false)
							{
								SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
								cout << "  " << kratka << "  ";
							}
							else
							{
								SetConsoleTextAttribute(hOut, FOREGROUND_RED);
								cout << "  " << kratka << "  ";
							}
							if (jedynka2_1 == false)
							{
								SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
								cout << kratka << "  ";
							}
							else
							{
								SetConsoleTextAttribute(hOut, FOREGROUND_RED);
								cout << kratka << "  ";
							}
							if (jedynka3_1 == false)
							{
								SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
								cout << kratka << "  ";
							}
							else
							{
								SetConsoleTextAttribute(hOut, FOREGROUND_RED);
								cout << kratka << "  ";
							}
							if (jedynka4_1 == false)
							{
								SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
								cout << kratka;
							}
							else
							{
								SetConsoleTextAttribute(hOut, FOREGROUND_RED);
								cout << kratka;
							}
							SetConsoleTextAttribute(hOut, FOREGROUND_RED);
							spacje(22);
							cout << "Przeciez juz tutaj strzelales! Sprobuj jeszcze raz.";
							spacje(23);
							SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
						}

						else
						{
							if (jedynka1_1 == false)
							{
								SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
								cout << "  " << kratka << "  ";
							}
							else
							{
								SetConsoleTextAttribute(hOut, FOREGROUND_RED);
								cout << "  " << kratka << "  ";
							}
							if (jedynka2_1 == false)
							{
								SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
								cout << kratka << "  ";
							}
							else
							{
								SetConsoleTextAttribute(hOut, FOREGROUND_RED);
								cout << kratka << "  ";
							}
							if (jedynka3_1 == false)
							{
								SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
								cout << kratka << "  ";
							}
							else
							{
								SetConsoleTextAttribute(hOut, FOREGROUND_RED);
								cout << kratka << "  ";
							}
							if (jedynka4_1 == false)
							{
								SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
								cout << kratka;
							}
							else
							{
								SetConsoleTextAttribute(hOut, FOREGROUND_RED);
								cout << kratka;
							}
							if (plansza2[graczw][graczk] == -1 || plansza2[graczw][graczk] == 0)
							{
								if (efekty == true)
									PlaySound(L"pusty.wav", NULL, SND_ASYNC);
								plansza2[graczw][graczk] = 5;

								SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
								spacje(77);
								cout << "PUSTO ;c";
								spacje(11);
							}
							else if (plansza2[graczw][graczk] == 1)
							{
								plansza2[graczw][graczk] = 6;
								for (int a = 0; a < 3; a++)
								{
									for (int b = 0; b < 3; b++)
									{
										if (graczk - 1 + a >= 0 && graczk - 1 + a <= 9 && graczw - 1 + b >= 0 && graczw - 1 + b <= 9 && plansza2[graczw - 1 + b][graczk - 1 + a] == -1)
											plansza2[graczw - 1 + b][graczk - 1 + a] = 5;
									}
								}

								SetConsoleTextAttribute(hOut, FOREGROUND_GREEN);
								spacje(71);
								cout << "TRAFIONY, ZATOPIONY!";
								if (efekty == true)
									PlaySound(L"zatopiony.wav", NULL, SND_ASYNC);
								spacje(5);
								if (jedynka1_2 == false) jedynka1_2 = true;
								else if (jedynka1_2 == true && jedynka2_2 == false) jedynka2_2 = true;
								else if (jedynka1_2 == true && jedynka2_2 == true && jedynka3_2 == false) jedynka3_2 = true;
								else if (jedynka1_2 == true && jedynka2_2 == true && jedynka3_2 == true) jedynka4_2 = true;
							}
							else if (plansza2[graczw][graczk] == 2)
							{
								plansza2[graczw][graczk] = 6;

								if (plansza2[graczw + 1][graczk] != 6 && plansza2[graczw - 1][graczk] != 6 && plansza2[graczw][graczk + 1] != 6 && plansza2[graczw][graczk - 1] != 6)
								{

									SetConsoleTextAttribute(hOut, FOREGROUND_RED);
									spacje(77);
									cout << "TRAFIONY!";
									if (efekty == true)
										PlaySound(L"trafiony.wav", NULL, SND_ASYNC);
									spacje(10);
								}
								else if (plansza2[graczw + 1][graczk] == 6)
								{
									for (int a = 0; a < 3; a++)
									{
										for (int b = 0; b < 4; b++)
										{
											if (graczk - 1 + a >= 0 && graczk - 1 + a <= 9 && graczw - 1 + b >= 0 && graczw - 1 + b <= 9 && plansza2[graczw - 1 + b][graczk - 1 + a] == -1)
												plansza2[graczw - 1 + b][graczk - 1 + a] = 5;
										}


									}

									SetConsoleTextAttribute(hOut, FOREGROUND_GREEN);
									spacje(71);
									cout << "TRAFIONY, ZATOPIONY!";
									if (efekty == true)
										PlaySound(L"zatopiony.wav", NULL, SND_ASYNC);
									spacje(5);
									if (dwojka1_2 == false) dwojka1_2 = true;
									else if (dwojka1_2 == true && dwojka2_2 == false) dwojka2_2 = true;
									else if (dwojka1_2 == true && dwojka2_2 == true) dwojka3_2 = true;
								}
								else if (plansza2[graczw][graczk + 1] == 6)
								{
									for (int a = 0; a < 3; a++)
									{
										for (int b = 0; b < 4; b++)
										{
											if (graczw - 1 + a >= 0 && graczw - 1 + a <= 9 && graczk - 1 + b >= 0 && graczk - 1 + b <= 9 && plansza2[graczw - 1 + a][graczk - 1 + b] == -1)
												plansza2[graczw - 1 + a][graczk - 1 + b] = 5;
										}
									}

									SetConsoleTextAttribute(hOut, FOREGROUND_GREEN);
									spacje(71);
									cout << "TRAFIONY, ZATOPIONY!";
									if (efekty == true)
										PlaySound(L"zatopiony.wav", NULL, SND_ASYNC);
									spacje(5);
									if (dwojka1_2 == false) dwojka1_2 = true;
									else if (dwojka1_2 == true && dwojka2_2 == false) dwojka2_2 = true;
									else if (dwojka1_2 == true && dwojka2_2 == true) dwojka3_2 = true;
								}
								else if (plansza2[graczw - 1][graczk] == 6)
								{
									for (int a = 0; a < 3; a++)
									{
										for (int b = 0; b < 4; b++)
										{
											if (graczk - 1 + a >= 0 && graczk - 1 + a <= 9 && graczw + 1 - b >= 0 && graczw + 1 - b <= 9 && plansza2[graczw + 1 - b][graczk - 1 + a] == -1)
												plansza2[graczw + 1 - b][graczk - 1 + a] = 5;
										}
									}

									SetConsoleTextAttribute(hOut, FOREGROUND_GREEN);
									spacje(71);
									cout << "TRAFIONY, ZATOPIONY!";
									if (efekty == true)
										PlaySound(L"zatopiony.wav", NULL, SND_ASYNC);
									spacje(5);
									if (dwojka1_2 == false) dwojka1_2 = true;
									else if (dwojka1_2 == true && dwojka2_2 == false) dwojka2_2 = true;
									else if (dwojka1_2 == true && dwojka2_2 == true) dwojka3_2 = true;
								}
								else if (plansza2[graczw][graczk - 1] == 6)
								{
									for (int a = 0; a < 3; a++)
									{
										for (int b = 0; b < 4; b++)
										{
											if (graczw - 1 + a >= 0 && graczw - 1 + a <= 9 && graczk + 1 - b >= 0 && graczk + 1 - b <= 9 && plansza2[graczw - 1 + a][graczk + 1 - b] == -1)
												plansza2[graczw - 1 + a][graczk + 1 - b] = 5;
										}
									}

									SetConsoleTextAttribute(hOut, FOREGROUND_GREEN);
									spacje(71);
									cout << "TRAFIONY, ZATOPIONY!";
									if (efekty == true)
										PlaySound(L"zatopiony.wav", NULL, SND_ASYNC);
									spacje(5);
									if (dwojka1_2 == false) dwojka1_2 = true;
									else if (dwojka1_2 == true && dwojka2_2 == false) dwojka2_2 = true;
									else if (dwojka1_2 == true && dwojka2_2 == true) dwojka3_2 = true;
								}
							}
							else if (plansza2[graczw][graczk] == 3)
							{
								plansza2[graczw][graczk] = 6;

								if (plansza2[graczw - 1][graczk] == 3 && plansza2[graczw - 2][graczk] == 3)
								{

									SetConsoleTextAttribute(hOut, FOREGROUND_RED);
									spacje(77);
									cout << "TRAFIONY!";
									if (efekty == true)
										PlaySound(L"trafiony.wav", NULL, SND_ASYNC);
									spacje(10);
								}
								else if (plansza2[graczw - 1][graczk] == 6 && plansza2[graczw - 2][graczk] == 3)
								{

									SetConsoleTextAttribute(hOut, FOREGROUND_RED);
									spacje(77);
									cout << "TRAFIONY!";
									if (efekty == true)
										PlaySound(L"trafiony.wav", NULL, SND_ASYNC);
									spacje(10);
								}
								else if (plansza2[graczw - 1][graczk] == 3 && plansza2[graczw - 2][graczk] == 6)
								{

									SetConsoleTextAttribute(hOut, FOREGROUND_RED);
									spacje(77);
									cout << "TRAFIONY!";
									if (efekty == true)
										PlaySound(L"trafiony.wav", NULL, SND_ASYNC);
									spacje(10);
								}
								else if (plansza2[graczw - 1][graczk] == 6 && plansza2[graczw - 2][graczk] == 6)
								{
									for (int a = 0; a < 3; a++)
									{
										for (int b = 0; b < 5; b++)
										{
											if (graczk - 1 + a >= 0 && graczk - 1 + a <= 9 && graczw + 1 - b >= 0 && graczw + 1 - b <= 9 && plansza2[graczw + 1 - b][graczk - 1 + a] == -1)
												plansza2[graczw + 1 - b][graczk - 1 + a] = 5;
										}


									}

									SetConsoleTextAttribute(hOut, FOREGROUND_GREEN);
									spacje(71);
									cout << "TRAFIONY, ZATOPIONY!";
									if (efekty == true)
										PlaySound(L"zatopiony.wav", NULL, SND_ASYNC);
									spacje(5);
									if (trojka1_2 == false) trojka1_2 = true;
									else if (trojka1_2 == true) trojka2_2 = true;

								}

								else if (plansza2[graczw - 1][graczk] == 3 && plansza2[graczw + 1][graczk] == 3)
								{

									SetConsoleTextAttribute(hOut, FOREGROUND_RED);
									spacje(77);
									cout << "TRAFIONY!";
									if (efekty == true)
										PlaySound(L"trafiony.wav", NULL, SND_ASYNC);
									spacje(10);
								}
								else if (plansza2[graczw - 1][graczk] == 6 && plansza2[graczw + 1][graczk] == 3)
								{

									SetConsoleTextAttribute(hOut, FOREGROUND_RED);
									spacje(77);
									cout << "TRAFIONY!";
									if (efekty == true)
										PlaySound(L"trafiony.wav", NULL, SND_ASYNC);
									spacje(10);
								}
								else if (plansza2[graczw - 1][graczk] == 3 && plansza2[graczw + 1][graczk] == 6)
								{

									SetConsoleTextAttribute(hOut, FOREGROUND_RED);
									spacje(77);
									cout << "TRAFIONY!";
									if (efekty == true)
										PlaySound(L"trafiony.wav", NULL, SND_ASYNC);
									spacje(10);
								}
								else if (plansza2[graczw - 1][graczk] == 6 && plansza2[graczw + 1][graczk] == 6)
								{
									for (int a = 0; a < 3; a++)
									{
										for (int b = 0; b < 5; b++)
										{
											if (graczk - 1 + a >= 0 && graczk - 1 + a <= 9 && graczw + 2 - b >= 0 && graczw + 2 - b <= 9 && plansza2[graczw + 2 - b][graczk - 1 + a] == -1)
												plansza2[graczw + 2 - b][graczk - 1 + a] = 5;
										}


									}

									SetConsoleTextAttribute(hOut, FOREGROUND_GREEN);
									spacje(71);
									cout << "TRAFIONY, ZATOPIONY!";
									if (efekty == true)
										PlaySound(L"zatopiony.wav", NULL, SND_ASYNC);
									spacje(5);
									if (trojka1_2 == false) trojka1_2 = true;
									else if (trojka1_2 == true) trojka2_2 = true;
								}
								else if (plansza2[graczw + 1][graczk] == 3 && plansza2[graczw + 2][graczk] == 3)
								{

									SetConsoleTextAttribute(hOut, FOREGROUND_RED);
									spacje(77);
									cout << "TRAFIONY!";
									if (efekty == true)
										PlaySound(L"trafiony.wav", NULL, SND_ASYNC);
									spacje(10);
								}
								else if (plansza2[graczw + 1][graczk] == 6 && plansza2[graczw + 2][graczk] == 3)
								{

									SetConsoleTextAttribute(hOut, FOREGROUND_RED);
									spacje(77);
									cout << "TRAFIONY!";
									if (efekty == true)
										PlaySound(L"trafiony.wav", NULL, SND_ASYNC);
									spacje(10);
								}
								else if (plansza2[graczw + 1][graczk] == 3 && plansza2[graczw + 2][graczk] == 6)
								{

									SetConsoleTextAttribute(hOut, FOREGROUND_RED);
									spacje(77);
									cout << "TRAFIONY!";
									if (efekty == true)
										PlaySound(L"trafiony.wav", NULL, SND_ASYNC);
									spacje(10);
								}
								else if (plansza2[graczw + 1][graczk] == 6 && plansza2[graczw + 2][graczk] == 6)
								{
									for (int a = 0; a < 3; a++)
									{
										for (int b = 0; b < 5; b++)
										{
											if (graczk - 1 + a >= 0 && graczk - 1 + a <= 9 && graczw - 1 + b >= 0 && graczw - 1 + b <= 9 && plansza2[graczw - 1 + b][graczk - 1 + a] == -1)
												plansza2[graczw - 1 + b][graczk - 1 + a] = 5;
										}


									}

									SetConsoleTextAttribute(hOut, FOREGROUND_GREEN);
									spacje(71);
									cout << "TRAFIONY, ZATOPIONY!";
									if (efekty == true)
										PlaySound(L"zatopiony.wav", NULL, SND_ASYNC);
									spacje(5);
									if (trojka1_2 == false) trojka1_2 = true;
									else if (trojka1_2 == true) trojka2_2 = true;
								}

								else if (plansza2[graczw][graczk + 1] == 3 && plansza2[graczw][graczk + 2] == 3)
								{

									SetConsoleTextAttribute(hOut, FOREGROUND_RED);
									spacje(77);
									cout << "TRAFIONY!";
									if (efekty == true)
										PlaySound(L"trafiony.wav", NULL, SND_ASYNC);
									spacje(10);
								}
								else if (plansza2[graczw][graczk + 1] == 6 && plansza2[graczw][graczk + 2] == 3)
								{

									SetConsoleTextAttribute(hOut, FOREGROUND_RED);
									spacje(77);
									cout << "TRAFIONY!";
									if (efekty == true)
										PlaySound(L"trafiony.wav", NULL, SND_ASYNC);
									spacje(10);
								}
								else if (plansza2[graczw][graczk + 1] == 3 && plansza2[graczw][graczk + 2] == 6)
								{

									SetConsoleTextAttribute(hOut, FOREGROUND_RED);
									spacje(77);
									cout << "TRAFIONY!";
									if (efekty == true)
										PlaySound(L"trafiony.wav", NULL, SND_ASYNC);
									spacje(10);
								}
								else if (plansza2[graczw][graczk + 1] == 6 && plansza2[graczw][graczk + 2] == 6)
								{
									for (int a = 0; a < 3; a++)
									{
										for (int b = 0; b < 5; b++)
										{
											if (graczk - 1 + b >= 0 && graczk - 1 + b <= 9 && graczw - 1 + a >= 0 && graczw - 1 + a <= 9 && plansza2[graczw - 1 + a][graczk - 1 + b] == -1)
												plansza2[graczw - 1 + a][graczk - 1 + b] = 5;
										}
									}

									SetConsoleTextAttribute(hOut, FOREGROUND_GREEN);
									spacje(71);
									cout << "TRAFIONY, ZATOPIONY!";
									if (efekty == true)
										PlaySound(L"zatopiony.wav", NULL, SND_ASYNC);
									spacje(5);
									if (trojka1_2 == false) trojka1_2 = true;
									else if (trojka1_2 == true) trojka2_2 = true;
								}

								else if (plansza2[graczw][graczk - 1] == 3 && plansza2[graczw][graczk + 1] == 3)
								{

									SetConsoleTextAttribute(hOut, FOREGROUND_RED);
									spacje(77);
									cout << "TRAFIONY!";
									if (efekty == true)
										PlaySound(L"trafiony.wav", NULL, SND_ASYNC);
									spacje(10);
								}
								else if (plansza2[graczw][graczk - 1] == 6 && plansza2[graczw][graczk + 1] == 3)
								{

									SetConsoleTextAttribute(hOut, FOREGROUND_RED);
									spacje(77);
									cout << "TRAFIONY!";
									if (efekty == true)
										PlaySound(L"trafiony.wav", NULL, SND_ASYNC);
									spacje(10);
								}
								else if (plansza2[graczw][graczk - 1] == 3 && plansza2[graczw][graczk + 1] == 6)
								{

									SetConsoleTextAttribute(hOut, FOREGROUND_RED);
									spacje(77);
									cout << "TRAFIONY!";
									if (efekty == true)
										PlaySound(L"trafiony.wav", NULL, SND_ASYNC);
									spacje(10);
								}
								else if (plansza2[graczw][graczk - 1] == 6 && plansza2[graczw][graczk + 1] == 6)
								{
									for (int a = 0; a < 3; a++)
									{
										for (int b = 0; b < 5; b++)
										{
											if (graczk - 2 + b >= 0 && graczk - 2 + b <= 9 && graczw - 1 + a >= 0 && graczw - 1 + a <= 9 && plansza2[graczw - 1 + a][graczk - 2 + b] == -1)
												plansza2[graczw - 1 + a][graczk - 2 + b] = 5;
										}
									}

									SetConsoleTextAttribute(hOut, FOREGROUND_GREEN);
									spacje(71);
									cout << "TRAFIONY, ZATOPIONY!";
									if (efekty == true)
										PlaySound(L"zatopiony.wav", NULL, SND_ASYNC);
									spacje(5);
									if (trojka1_2 == false) trojka1_2 = true;
									else if (trojka1_2 == true) trojka2_2 = true;
								}
								else if (plansza2[graczw][graczk - 1] == 3 && plansza2[graczw][graczk - 2] == 3)
								{

									SetConsoleTextAttribute(hOut, FOREGROUND_RED);
									spacje(77);
									cout << "TRAFIONY!";
									if (efekty == true)
										PlaySound(L"trafiony.wav", NULL, SND_ASYNC);
									spacje(10);
								}
								else if (plansza2[graczw][graczk - 1] == 6 && plansza2[graczw][graczk - 2] == 3)
								{

									SetConsoleTextAttribute(hOut, FOREGROUND_RED);
									spacje(77);
									cout << "TRAFIONY!";
									if (efekty == true)
										PlaySound(L"trafiony.wav", NULL, SND_ASYNC);
									spacje(10);
								}
								else if (plansza2[graczw][graczk - 1] == 3 && plansza2[graczw][graczk - 2] == 6)
								{

									SetConsoleTextAttribute(hOut, FOREGROUND_RED);
									spacje(77);
									cout << "TRAFIONY!";
									if (efekty == true)
										PlaySound(L"trafiony.wav", NULL, SND_ASYNC);
									spacje(10);
								}
								else if (plansza2[graczw][graczk - 1] == 6 && plansza2[graczw][graczk - 2] == 6)
								{
									for (int a = 0; a < 3; a++)
									{
										for (int b = 0; b < 5; b++)
										{
											if (graczk - 3 + b >= 0 && graczk - 3 + b <= 9 && graczw - 1 + a >= 0 && graczw - 1 + a <= 9 && plansza2[graczw - 1 + a][graczk - 3 + b] == -1)
												plansza2[graczw - 1 + a][graczk - 3 + b] = 5;
										}
									}

									SetConsoleTextAttribute(hOut, FOREGROUND_GREEN);
									spacje(71);
									cout << "TRAFIONY, ZATOPIONY!";
									if (efekty == true)
										PlaySound(L"zatopiony.wav", NULL, SND_ASYNC);
									spacje(5);
									if (trojka1_2 == false) trojka1_2 = true;
									else if (trojka1_2 == true) trojka2_2 = true;
								}

							}
							else if (plansza2[graczw][graczk] == 4)
							{
								plansza2[graczw][graczk] = 6;
								czworka2++;
								if (czworka2 != 4)
								{

									SetConsoleTextAttribute(hOut, FOREGROUND_RED);
									spacje(77);
									cout << "TRAFIONY!";
									if (efekty == true)
										PlaySound(L"trafiony.wav", NULL, SND_ASYNC);
									spacje(10);
								}
								else if (czworka2 == 4)
								{
									if (plansza2[graczw][graczk + 1] == 6 && plansza2[graczw][graczk + 2] == 6 && plansza2[graczw][graczk + 3] == 6)
									{
										for (int a = 0; a < 3; a++)
										{
											for (int b = 0; b < 6; b++)
											{
												if (graczw - 1 + a >= 0 && graczw - 1 + a <= 9 && graczk - 1 + b >= 0 && graczk - 1 + b <= 9 && plansza2[graczw - 1 + a][graczk - 1 + b] == -1)
													plansza2[graczw - 1 + a][graczk - 1 + b] = 5;
											}
										}

										SetConsoleTextAttribute(hOut, FOREGROUND_GREEN);
										spacje(71);
										cout << "TRAFIONY, ZATOPIONY!";
										if (efekty == true)
											PlaySound(L"zatopiony.wav", NULL, SND_ASYNC);
										spacje(5);
										if (czworka1_2 == false) czworka1_2 = true;


									}
									else if (plansza2[graczw][graczk - 1] == 6 && plansza2[graczw][graczk + 1] == 6 && plansza2[graczw][graczk + 2] == 6)
									{
										for (int a = 0; a < 3; a++)
										{
											for (int b = 0; b < 6; b++)
											{
												if (graczw - 1 + a >= 0 && graczw - 1 + a <= 9 && graczk - 2 + b >= 0 && graczk - 2 + b <= 9 && plansza2[graczw - 1 + a][graczk - 2 + b] == -1)
													plansza2[graczw - 1 + a][graczk - 2 + b] = 5;
											}
										}

										SetConsoleTextAttribute(hOut, FOREGROUND_GREEN);
										spacje(71);
										cout << "TRAFIONY, ZATOPIONY!";
										if (efekty == true)
											PlaySound(L"zatopiony.wav", NULL, SND_ASYNC);
										spacje(5);
										if (czworka1_2 == false) czworka1_2 = true;
									}
									else if (plansza2[graczw][graczk - 1] == 6 && plansza2[graczw][graczk - 2] == 6 && plansza2[graczw][graczk - 3] == 6)
									{
										for (int a = 0; a < 3; a++)
										{
											for (int b = 0; b < 6; b++)
											{
												if (graczw - 1 + a >= 0 && graczw - 1 + a <= 9 && graczk + 1 - b >= 0 && graczk + 1 - b <= 9 && plansza2[graczw - 1 + a][graczk + 1 - b] == -1)
													plansza2[graczw - 1 + a][graczk + 1 - b] = 5;
											}
										}

										SetConsoleTextAttribute(hOut, FOREGROUND_GREEN);
										spacje(71);
										cout << "TRAFIONY, ZATOPIONY!";
										if (efekty == true)
											PlaySound(L"zatopiony.wav", NULL, SND_ASYNC);
										spacje(5);
										if (czworka1_2 == false) czworka1_2 = true;
									}
									else if (plansza2[graczw][graczk - 1] == 6 && plansza2[graczw][graczk + 1] == 6 && plansza2[graczw][graczk - 2] == 6)
									{
										for (int a = 0; a < 3; a++)
										{
											for (int b = 0; b < 6; b++)
											{
												if (graczw - 1 + a >= 0 && graczw - 1 + a <= 9 && graczk + 2 - b >= 0 && graczk + 2 - b <= 9 && plansza2[graczw - 1 + a][graczk + 2 - b] == -1)
													plansza2[graczw - 1 + a][graczk + 2 - b] = 5;
											}
										}

										SetConsoleTextAttribute(hOut, FOREGROUND_GREEN);
										spacje(71);
										cout << "TRAFIONY, ZATOPIONY!";
										if (efekty == true)
											PlaySound(L"zatopiony.wav", NULL, SND_ASYNC);
										spacje(5);
										if (czworka1_2 == false) czworka1_2 = true;
									}
									else if (plansza2[graczw + 1][graczk] == 6 && plansza2[graczw + 2][graczk] == 6 && plansza2[graczw + 3][graczk] == 6)
									{
										for (int a = 0; a < 3; a++)
										{
											for (int b = 0; b < 6; b++)
											{
												if (graczk - 1 + a >= 0 && graczk - 1 + a <= 9 && graczw - 1 + b >= 0 && graczw - 1 + b <= 9 && plansza2[graczw - 1 + b][graczk - 1 + a] == -1)
													plansza2[graczw - 1 + b][graczk - 1 + a] = 5;
											}
										}

										SetConsoleTextAttribute(hOut, FOREGROUND_GREEN);
										spacje(71);
										cout << "TRAFIONY, ZATOPIONY!";
										if (efekty == true)
											PlaySound(L"zatopiony.wav", NULL, SND_ASYNC);
										spacje(5);
										if (czworka1_2 == false) czworka1_2 = true;
									}
									else if (plansza2[graczw + 1][graczk] == 6 && plansza2[graczw - 1][graczk] == 6 && plansza2[graczw + 2][graczk] == 6)
									{
										for (int a = 0; a < 3; a++)
										{
											for (int b = 0; b < 6; b++)
											{
												if (graczk - 1 + a >= 0 && graczk - 1 + a <= 9 && graczw - 2 + b >= 0 && graczw - 2 + b <= 9 && plansza2[graczw - 2 + b][graczk - 1 + a] == -1)
													plansza2[graczw - 2 + b][graczk - 1 + a] = 5;
											}
										}

										SetConsoleTextAttribute(hOut, FOREGROUND_GREEN);
										spacje(71);
										cout << "TRAFIONY, ZATOPIONY!";
										if (efekty == true)
											PlaySound(L"zatopiony.wav", NULL, SND_ASYNC);
										spacje(5);
										if (czworka1_2 == false) czworka1_2 = true;
									}
									else if (plansza2[graczw - 1][graczk] == 6 && plansza2[graczw - 2][graczk] == 6 && plansza2[graczw - 3][graczk] == 6)
									{
										for (int a = 0; a < 3; a++)
										{
											for (int b = 0; b < 6; b++)
											{
												if (graczk - 1 + a >= 0 && graczk - 1 + a <= 9 && graczw + 1 - b >= 0 && graczw + 1 - b <= 9 && plansza2[graczw + 1 - b][graczk - 1 + a] == -1)
													plansza2[graczw + 1 - b][graczk - 1 + a] = 5;
											}
										}

										SetConsoleTextAttribute(hOut, FOREGROUND_GREEN);
										spacje(71);
										cout << "TRAFIONY, ZATOPIONY!";
										if (efekty == true)
											PlaySound(L"zatopiony.wav", NULL, SND_ASYNC);
										spacje(5);
										if (czworka1_2 == false) czworka1_2 = true;
									}
									else if (plansza2[graczw + 1][graczk] == 6 && plansza2[graczw - 1][graczk] == 6 && plansza2[graczw - 2][graczk] == 6)
									{
										for (int a = 0; a < 3; a++)
										{
											for (int b = 0; b < 6; b++)
											{
												if (graczk - 1 + a >= 0 && graczk - 1 + a <= 9 && graczw + 2 - b >= 0 && graczw + 2 - b <= 9 && plansza2[graczw + 2 - b][graczk - 1 + a] == -1)
													plansza2[graczw + 2 - b][graczk - 1 + a] = 5;
											}
										}

										SetConsoleTextAttribute(hOut, FOREGROUND_GREEN);
										spacje(71);
										cout << "TRAFIONY, ZATOPIONY!";
										if (efekty == true)
											PlaySound(L"zatopiony.wav", NULL, SND_ASYNC);
										spacje(5);
										if (czworka1_2 == false) czworka1_2 = true;
									}
								}
							}
							if (plansza2[graczw][graczk] == 6)
								kolejGracza1 = true;
							else
								kolejGracza1 = false;

						}

					}
					if (jedynka1_2 == false)
					{
						SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
						cout << kratka << "  ";
					}
					else
					{
						SetConsoleTextAttribute(hOut, FOREGROUND_RED);
						cout << kratka << "  ";
					}
					if (jedynka2_2 == false)
					{
						SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
						cout << kratka << "  ";
					}
					else
					{
						SetConsoleTextAttribute(hOut, FOREGROUND_RED);
						cout << kratka << "  ";
					}
					if (jedynka3_2 == false)
					{
						SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
						cout << kratka << "  ";
					}
					else
					{
						SetConsoleTextAttribute(hOut, FOREGROUND_RED);
						cout << kratka << "  ";
					}
					if (jedynka4_2 == false)
					{
						SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
						cout << kratka << "  ";
					}
					else
					{
						SetConsoleTextAttribute(hOut, FOREGROUND_RED);
						cout << kratka << "  ";
					}
					cout << endl;

					if (dwojka1_1 == false)
					{
						SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
						cout << "  " << kratka << kratka << "  ";
					}
					else
					{
						SetConsoleTextAttribute(hOut, FOREGROUND_RED);
						cout << "  " << kratka << kratka << "  ";
					}
					if (dwojka2_1 == false)
					{
						SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
						cout << kratka << kratka << "  ";
					}
					else
					{
						SetConsoleTextAttribute(hOut, FOREGROUND_RED);
						cout << kratka << kratka << "  ";
					}
					if (dwojka3_1 == false)
					{
						SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
						cout << kratka << kratka;
					}
					else
					{
						SetConsoleTextAttribute(hOut, FOREGROUND_RED);
						cout << kratka << kratka;
					}

					spacje(96);

					if (dwojka1_2 == false)
					{
						SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
						cout << kratka << kratka << "  ";
					}
					else
					{
						SetConsoleTextAttribute(hOut, FOREGROUND_RED);
						cout << kratka << kratka << "  ";
					}
					if (dwojka2_2 == false)
					{
						SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
						cout << kratka << kratka << "  ";
					}
					else
					{
						SetConsoleTextAttribute(hOut, FOREGROUND_RED);
						cout << kratka << kratka << "  ";
					}
					if (dwojka3_2 == false)
					{
						SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
						cout << kratka << kratka;
					}
					else
					{
						SetConsoleTextAttribute(hOut, FOREGROUND_RED);
						cout << kratka << kratka << "  ";
					}
					cout << endl;
					if (trojka1_1 == false)
					{
						SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
						cout << "  " << kratka << kratka << kratka << "  ";
					}
					else
					{
						SetConsoleTextAttribute(hOut, FOREGROUND_RED);
						cout << "  " << kratka << kratka << kratka << "  ";
					}
					if (trojka2_1 == false)
					{
						SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
						cout << kratka << kratka << kratka;
					}
					else
					{
						SetConsoleTextAttribute(hOut, FOREGROUND_RED);
						cout << kratka << kratka << kratka;
					}

					if (kolejGracza1 == true)
					{
						SetConsoleTextAttribute(hOut, FOREGROUND_BLUE);
						spacje(((120 - (dl_imie1 + 26)) / 2) - 10);

						cout << imie1 << ", to twoja tura! Strzelaj!";
						if ((imie1.length() % 2) == 1)
							spacje(((120 - (dl_imie1 + 26)) / 2) - 11);
						else
							spacje(((120 - (dl_imie1 + 26)) / 2) - 10);
					}
					else
					{
						SetConsoleTextAttribute(hOut, FOREGROUND_BLUE | FOREGROUND_RED);
						spacje(((120 - (dl_imie2 + 26)) / 2) - 10);
						cout << imie2 << ", to twoja tura! Strzelaj!";
						if ((imie2.length() % 2) == 1)
							spacje(((120 - (dl_imie2 + 26)) / 2) - 11);
						else
							spacje(((120 - (dl_imie2 + 26)) / 2) - 10);
					}
					if (trojka1_2 == false)
					{
						SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
						cout << kratka << kratka << kratka << "  ";
					}
					else
					{
						SetConsoleTextAttribute(hOut, FOREGROUND_RED);
						cout << kratka << kratka << kratka << "  ";
					}
					if (trojka2_2 == false)
					{
						SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
						cout << kratka << kratka << kratka;
					}
					else
					{
						SetConsoleTextAttribute(hOut, FOREGROUND_RED);
						cout << kratka << kratka << kratka;
					}
					cout << endl;
					if (czworka1_1 == false)
					{
						SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
						cout << "  " << kratka << kratka << kratka << kratka;
					}
					else
					{
						SetConsoleTextAttribute(hOut, FOREGROUND_RED);
						cout << "  " << kratka << kratka << kratka << kratka;
					}
					spacje(108);
					if (czworka1_2 == false)
					{
						SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
						cout << kratka << kratka << kratka << kratka;
					}
					else
					{
						SetConsoleTextAttribute(hOut, FOREGROUND_RED);
						cout << kratka << kratka << kratka << kratka;
					}

					cout << endl;



					SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
					for (int a = 0; a < (60 - (dl_imie1 + 15)) / 2; a++)
						cout << " ";
					cout << "Plansza gracza ";
					SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
					cout << imie1;
					SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
					for (int a = 0; a < (45 - ((dl_imie1 + dl_imie2) / 2)); a++)
						cout << " ";
					cout << "Plansza gracza ";
					SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
					cout << imie2;
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
					cout << "      " << kreska << "   ";
					for (char x = 65; x <= 74; x++)
					{
						SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
						cout << "    ";
						SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY | BACKGROUND_RED);
						cout << x;

					}
					SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY);


					cout << endl << "                                                           " << kreska << endl;
					for (int i = 0; i <= 9; i++)
					{
						cout << "  ";
						SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY | BACKGROUND_RED);
						cout << (i + 1);

						// POKAZuJE u£O¯ON¥ PLANSZÊ
						for (int j = 0; j <= 9; j++)
						{
							if (i == 9 && j == 0)
							{
								if (plansza[i][j] == -1)
								{
									cout.width(4);
									SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
									cout << ".";
								}
								else if (plansza[i][j] == 0)
								{
									cout.width(4);
									SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
									cout << ".";
								}
								else if (plansza[i][j] == 1 || plansza[i][j] == 2 || plansza[i][j] == 3 || plansza[i][j] == 4)
								{
									cout.width(4);
									SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
									cout << ".";
								}
								else if (plansza[i][j] == 5)
								{
									cout.width(4);
									SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
									cout << "o";
								}
								else if (plansza[i][j] == 6)
								{
									cout.width(4);
									SetConsoleTextAttribute(hOut, FOREGROUND_RED);
									cout << "x";
								}
							}
							else
							{
								if (plansza[i][j] == -1)
								{
									cout.width(5);
									SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
									cout << ".";
								}
								else if (plansza[i][j] == 0)
								{
									cout.width(5);
									SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
									cout << ".";
								}
								else if (plansza[i][j] == 1 || plansza[i][j] == 2 || plansza[i][j] == 3 || plansza[i][j] == 4)
								{
									cout.width(5);
									SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
									cout << ".";
								}
								else if (plansza[i][j] == 5)
								{
									cout.width(5);
									SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
									cout << "o";
								}
								else if (plansza[i][j] == 6)
								{
									cout.width(5);
									SetConsoleTextAttribute(hOut, FOREGROUND_RED);
									cout << "x";
								}
							}
						}
						SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY);
						cout << "      " << kreska << "   ";

						for (int q = 0; q <= 9; q++)
						{
							if (i == 9 && q == 0)
							{
								if (plansza2[i][q] == -1)
								{
									cout.width(5);
									SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
									cout << ".";
								}
								else if (plansza2[i][q] == 0)
								{
									cout.width(5);
									SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
									cout << ".";
								}
								else if (plansza2[i][q] == 1 || plansza2[i][q] == 2 || plansza2[i][q] == 3 || plansza2[i][q] == 4)
								{
									cout.width(5);
									SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
									cout << ".";
								}
								else if (plansza2[i][q] == 5)
								{
									cout.width(5);
									SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
									cout << "o";
								}
								else if (plansza2[i][q] == 6)
								{
									cout.width(5);
									SetConsoleTextAttribute(hOut, FOREGROUND_RED);
									cout << "x";
								}
							}
							else
							{
								if (plansza2[i][q] == -1)
								{
									cout.width(5);
									SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
									cout << ".";
								}
								else if (plansza2[i][q] == 0)
								{
									cout.width(5);
									SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
									cout << ".";
								}
								else if (plansza2[i][q] == 1 || plansza2[i][q] == 2 || plansza2[i][q] == 3 || plansza2[i][q] == 4)
								{
									cout.width(5);
									SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
									cout << ".";
								}
								else if (plansza2[i][q] == 5)
								{
									cout.width(5);
									SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
									cout << "o";
								}
								else if (plansza2[i][q] == 6)
								{
									cout.width(5);
									SetConsoleTextAttribute(hOut, FOREGROUND_RED);
									cout << "x";
								}
							}

						}
						SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
						cout << "    ";
						SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY | BACKGROUND_RED);
						cout << i + 1;
						SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY);


						cout << endl << "                                                           ";
						if (i != 9)
							cout << kreska;
						cout << endl;
					}

					SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);

					int licznik = 0;
					int licznik2 = 0;
					for (int s = 0; s <= 9; s++)
					{
						for (int t = 0; t <= 9; t++)
						{

							if (plansza[s][t] == 6 || plansza[s][t] == 5 || plansza[s][t] == 0 || plansza[s][t] == -1)
							{
								licznik++;
							}


						}
					}
					for (int s = 0; s <= 9; s++)
					{
						for (int t = 0; t <= 9; t++)
						{

							if (plansza2[s][t] == 6 || plansza2[s][t] == 5 || plansza2[s][t] == 0 || plansza2[s][t] == -1)
							{
								licznik2++;
							}


						}
					}
					if (licznik == 100)
					{
						koniec_gry = true;
						SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
						cout << "GRATULACJE! TO JUZ KONIEC GRY!";
						Sleep(2000);
						system("cls");
						if (efekty == true)
							PlaySound(L"przegranaK.wav", NULL, SND_ASYNC);
						cout << "GRATULACJE! TO JUZ KONIEC GRY! Wygral ";
						SetConsoleTextAttribute(hOut, FOREGROUND_RED);
						cout << imie2;
						SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
						cout << endl << endl;
						stop = clock();
						czas(start, stop);
						instrukcja = 0;

					}
					else if (licznik2 == 100)
					{
						koniec_gry = true;
						SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
						cout << "GRATULACJE! TO JUZ KONIEC GRY!";
						Sleep(2000);
						system("cls");
						if (efekty == true)
							PlaySound(L"wygranaK.wav", NULL, SND_ASYNC);
						SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
						cout << "GRATULACJE! TO JUZ KONIEC GRY! Wygral ";
						SetConsoleTextAttribute(hOut, FOREGROUND_RED);
						cout << imie1;
						SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
						cout << endl << endl;
						stop = clock();
						czas(start, stop);

						instrukcja = 0;
					}
				}



			}


		}
		else if (instrukcja == 3)
		{
			int opcja{};
			system("cls");
			ramka("INSTRUKCJA", wsk);
			spacje(30);
			SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
			cout << "Aby powrocic do menu glownego, wcisnij ";
			SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_RED);
			cout << "[0]" << endl << endl;
			spacje(30);
			SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
			cout << "Aby zobaczyc instrukcje dotyczaca rozgrywki, wcisnij ";
			SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_RED);
			cout << "[1]" << endl << endl;
			spacje(30);
			SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
			cout << "Aby zobaczyc komendy zwiazane z wlasnorecznym ukladaniem statkow, wcisnij ";
			SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_RED);
			cout << "[2]" << endl << endl;
			spacje(30);
			SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
			cout << "Twoj wybor: ";
			cin >> opcja;
			if (opcja == 0)
				instrukcja = 0;
			else if (opcja == 1)
			{
				system("cls");
				int planszaInstr[10][10]{};
				SetConsoleTextAttribute(hOut, FOREGROUND_RED);
				komputer();
				SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
				string powitanie = "Witaj, jestem komputerem pokladowym 'Kapitan' i moj stworca zlecil mi towarzyszenie ci podczas twojej pierwszej podrozy statkiem. Mam nadzieje, ze bedziemy sie dobrze bawic! To co? Pora wejsc na poklad!";
				int dlugosc_pow = powitanie.length();
				for (int i = 0; i < dlugosc_pow; i++)
				{
					cout << powitanie[i];
					Sleep(100);
				}
				Sleep(2000);
				system("cls");
				if (jedynka1_1 == false)
				{
					SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
					cout << "  " << kratka << "  ";
				}
				else
				{
					SetConsoleTextAttribute(hOut, FOREGROUND_RED);
					cout << "  " << kratka << "  ";
				}
				if (jedynka2_1 == false)
				{
					SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
					cout << kratka << "  ";
				}
				else
				{
					SetConsoleTextAttribute(hOut, FOREGROUND_RED);
					cout << kratka << "  ";
				}
				if (jedynka3_1 == false)
				{
					SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
					cout << kratka << "  ";
				}
				else
				{
					SetConsoleTextAttribute(hOut, FOREGROUND_RED);
					cout << kratka << "  ";
				}
				if (jedynka4_1 == false)
				{
					SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
					cout << kratka;
				}
				else
				{
					SetConsoleTextAttribute(hOut, FOREGROUND_RED);
					cout << kratka;
				}

				cout << endl;
				if (dwojka1_1 == false)
				{
					SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
					cout << "  " << kratka << kratka << "  ";
				}
				else
				{
					SetConsoleTextAttribute(hOut, FOREGROUND_RED);
					cout << kratka << kratka << "  ";
				}
				if (dwojka2_1 == false)
				{
					SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
					cout << kratka << kratka << "  ";
				}
				else
				{
					SetConsoleTextAttribute(hOut, FOREGROUND_RED);
					cout << kratka << kratka << "  ";
				}
				if (dwojka3_1 == false)
				{
					SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
					cout << kratka << kratka;
				}
				else
				{
					SetConsoleTextAttribute(hOut, FOREGROUND_RED);
					cout << kratka << kratka;
				}
				cout << endl;

				if (trojka1_1 == false)
				{
					SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
					cout << "  " << kratka << kratka << kratka << "  ";
				}
				else
				{
					SetConsoleTextAttribute(hOut, FOREGROUND_RED);
					cout << kratka << kratka << kratka << "  ";
				}
				if (trojka2_1 == false)
				{
					SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
					cout << kratka << kratka << kratka;
				}
				else
				{
					SetConsoleTextAttribute(hOut, FOREGROUND_RED);
					cout << kratka << kratka << kratka;
				}

				SetConsoleTextAttribute(hOut, FOREGROUND_BLUE);
				spacje(36);

				cout << "XYZ" << ", to twoja tura! Strzelaj!";
				cout << endl;

				if (czworka1_1 == false)
				{
					SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
					cout << "  " << kratka << kratka << kratka << kratka;
				}
				else
				{
					SetConsoleTextAttribute(hOut, FOREGROUND_RED);
					cout << kratka << kratka << kratka << kratka;
				}
				cout << endl;

				SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
				spacje(22);
				cout << "Plansza gracza ";
				SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
				cout << "XYZ";
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
				cout << "      " << kreska << "   ";
				SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY);


				cout << endl << "                                                           " << kreska << endl;
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
					cout << "      " << kreska;
					cout << endl;
					spacje(59);
					SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY);
					if (i != 10)
						cout << kreska;
					cout << endl;
				}
				SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
				Sleep(2000);
				string strzal = "To juz pora, aby zestrzelic twoj pierwszy statek! Aby to zrobic, musisz podac najpierw kolumne (A-J), nastepnie wiersz  (1-10) i zatwierdzic enterem! Proste?";
				char kol;
				int wier;
				int kolu;
				int dlugosc_strz = strzal.length();
				for (int i = 0; i < dlugosc_strz; i++)
				{
					cout << strzal[i];
					Sleep(100);
				}
				Sleep(2000);
				cout << endl << "Podaj kolumne (A-J) oraz wiersz (1-10): ";
				cin >> kol;
				cin >> wier;
				wier = wier - 1;
				if (kol >= 65 && kol <= 74)
				{
					kolu = static_cast<int>(kol);
					kolu = kolu - 65;
				}
				else if (kol >= 97 && kol <= 106)
				{
					kolu = static_cast<int>(kol);
					kolu = kolu - 97;
				}
				else
				{
					kolu = -1;
				}
				if (wier >= 0 && wier <= 9 && kolu >= 0 && kolu <= 9)
				{
					planszaInstr[wier][kolu] = 2;
				}
				else
				{
					SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
					cout << endl << "Podales zle dane! Pozwol, ze ci pomoge i strzele za ciebie B5.";
					wier = 4;
					kolu = 1;
					planszaInstr[4][1] = 2;
					Sleep(4000);
				}
				system("cls");
				if (jedynka1_1 == false)
				{
					SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
					cout << "  " << kratka << "  ";
				}
				else
				{
					SetConsoleTextAttribute(hOut, FOREGROUND_RED);
					cout << "  " << kratka << "  ";
				}
				if (jedynka2_1 == false)
				{
					SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
					cout << kratka << "  ";
				}
				else
				{
					SetConsoleTextAttribute(hOut, FOREGROUND_RED);
					cout << kratka << "  ";
				}
				if (jedynka3_1 == false)
				{
					SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
					cout << kratka << "  ";
				}
				else
				{
					SetConsoleTextAttribute(hOut, FOREGROUND_RED);
					cout << kratka << "  ";
				}
				if (jedynka4_1 == false)
				{
					SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
					cout << kratka;
				}
				else
				{
					SetConsoleTextAttribute(hOut, FOREGROUND_RED);
					cout << kratka;
				}
				spacje(20);
				SetConsoleTextAttribute(hOut, FOREGROUND_RED);
				cout << "TRAFIONY";
				cout << endl;
				if (dwojka1_1 == false)
				{
					SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
					cout << "  " << kratka << kratka << "  ";
				}
				else
				{
					SetConsoleTextAttribute(hOut, FOREGROUND_RED);
					cout << kratka << kratka << "  ";
				}
				if (dwojka2_1 == false)
				{
					SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
					cout << kratka << kratka << "  ";
				}
				else
				{
					SetConsoleTextAttribute(hOut, FOREGROUND_RED);
					cout << kratka << kratka << "  ";
				}
				if (dwojka3_1 == false)
				{
					SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
					cout << kratka << kratka;
				}
				else
				{
					SetConsoleTextAttribute(hOut, FOREGROUND_RED);
					cout << kratka << kratka;
				}
				cout << endl;

				if (trojka1_1 == false)
				{
					SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
					cout << "  " << kratka << kratka << kratka << "  ";
				}
				else
				{
					SetConsoleTextAttribute(hOut, FOREGROUND_RED);
					cout << kratka << kratka << kratka << "  ";
				}
				if (trojka2_1 == false)
				{
					SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
					cout << kratka << kratka << kratka;
				}
				else
				{
					SetConsoleTextAttribute(hOut, FOREGROUND_RED);
					cout << kratka << kratka << kratka;
				}

				SetConsoleTextAttribute(hOut, FOREGROUND_BLUE);
				spacje(36);

				cout << "XYZ" << ", to twoja tura! Strzelaj!";
				cout << endl;

				if (czworka1_1 == false)
				{
					SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
					cout << "  " << kratka << kratka << kratka << kratka;
				}
				else
				{
					SetConsoleTextAttribute(hOut, FOREGROUND_RED);
					cout << kratka << kratka << kratka << kratka;
				}
				cout << endl;

				SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
				spacje(22);
				cout << "Plansza gracza ";
				SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
				cout << "WROG";
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
				cout << "      " << kreska << "   ";
				SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY);


				cout << endl << "                                                           " << kreska << endl;
				for (int i = 0; i < 10; i++)
				{
					cout << "  ";
					SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY | BACKGROUND_RED);
					cout << i + 1;

					// POKAZUJE KROPKI DO GRY 
					for (int j = 0; j < 10; j++)
					{
						if (i == 9 && j == 0)
						{
							if (planszaInstr[i][j] != 2 && planszaInstr[i][j] != 5)
							{
								cout.width(4);
								SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
								cout << ".";
							}
							else if (planszaInstr[i][j] == 5)
							{
								cout.width(4);
								SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
								cout << "o";
							}
							else
							{
								cout.width(4);
								SetConsoleTextAttribute(hOut, FOREGROUND_RED);
								cout << "x";
							}
						}
						else
						{
							if (planszaInstr[i][j] != 2 && planszaInstr[i][j] != 5)
							{
								cout.width(5);
								SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
								cout << ".";
							}
							else if (planszaInstr[i][j] == 5)
							{
								cout.width(5);
								SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
								cout << "o";
							}
							else
							{
								cout.width(5);
								SetConsoleTextAttribute(hOut, FOREGROUND_RED);
								cout << "x";
							}
						}
					}
					SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY);
					cout << "      " << kreska;
					cout << endl;
					spacje(59);
					SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY);
					if (i != 9)
						cout << kreska;
					cout << endl;
				}
				string zestrzelony = "Brawo, trafiles! Jak widzisz, na samej gorze ekranu pokazal sie napis 'TRAFIONY'. ";
				string zestrzelony2 = "To wlasnie tam beda sie pojawiac      informacje, ktore pokaza ci efekt twojego strzalu. Na planszy pojawil sie takze czerwony x.";
				string zestrzelony3 = " Oznacza on, ze w tym miejscujest zestrzelony statek. Jezeli nie pojawily sie wokol niego koleczka, to  znaczy, ze nie zostal jeszcze zatopiony. To co, pozwol, ze ja teraz strzele w ";
				int dlugosc_z1 = zestrzelony.length();
				int dlugosc_z2 = zestrzelony2.length();
				int dlugosc_z3 = zestrzelony3.length();
				for (int i = 0; i < dlugosc_z1; i++)
				{
					cout << zestrzelony[i];
					Sleep(100);
				}
				Sleep(2000);
				for (int i = 0; i < dlugosc_z2; i++)
				{
					cout << zestrzelony2[i];
					Sleep(100);
				}
				Sleep(2000);
				for (int i = 0; i < dlugosc_z3; i++)
				{
					cout << zestrzelony3[i];
					Sleep(100);
				}
				Sleep(2000);
				if (kolu == 1 && wier == 4)
				{
					cout << "B6";
					planszaInstr[wier + 1][kolu] = 2;
					dwojka1_1 = true;
					for (int a = 0; a < 3; a++)
					{
						for (int b = 0; b < 4; b++)
						{
							if (kolu - 1 + a >= 0 && kolu - 1 + a <= 9 && wier + 2 - b >= 0 && wier + 2 - b <= 9 && planszaInstr[wier + 2 - b][kolu - 1 + a] == 0)
								planszaInstr[wier + 2 - b][kolu - 1 + a] = 5;
						}


					}
				}
				else
				{
					if (wier + 1 <= 9)
					{
						cout << kol << wier + 1;
						planszaInstr[wier + 1][kolu] = 2;
						dwojka1_1 = true;
						for (int a = 0; a < 3; a++)
						{
							for (int b = 0; b < 4; b++)
							{
								if (kolu - 1 + a >= 0 && kolu - 1 + a <= 9 && wier + 2 - b >= 0 && wier + 2 - b <= 9 && planszaInstr[wier + 2 - b][kolu - 1 + a] == 0)
									planszaInstr[wier + 2 - b][kolu - 1 + a] = 5;
							}


						}
					}
					else
					{
						cout << kol << wier - 1;
						planszaInstr[wier + 1][kolu] = 2;
						dwojka1_1 = true;
						for (int a = 0; a < 3; a++)
						{
							for (int b = 0; b < 4; b++)
							{
								if (kolu - 1 + a >= 0 && kolu - 1 + a <= 9 && wier + 1 - b >= 0 && wier + 1 - b <= 9 && planszaInstr[wier + 1 - b][kolu - 1 + a] == 0)
									planszaInstr[wier + 1 - b][kol - 1 + a] = 5;
							}


						}
					}
				}
				Sleep(4000);
				system("cls");
				if (jedynka1_1 == false)
				{
					SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
					cout << "  " << kratka << "  ";
				}
				else
				{
					SetConsoleTextAttribute(hOut, FOREGROUND_RED);
					cout << "  " << kratka << "  ";
				}
				if (jedynka2_1 == false)
				{
					SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
					cout << kratka << "  ";
				}
				else
				{
					SetConsoleTextAttribute(hOut, FOREGROUND_RED);
					cout << kratka << "  ";
				}
				if (jedynka3_1 == false)
				{
					SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
					cout << kratka << "  ";
				}
				else
				{
					SetConsoleTextAttribute(hOut, FOREGROUND_RED);
					cout << kratka << "  ";
				}
				if (jedynka4_1 == false)
				{
					SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
					cout << kratka;
				}
				else
				{
					SetConsoleTextAttribute(hOut, FOREGROUND_RED);
					cout << kratka;
				}
				spacje(14);
				SetConsoleTextAttribute(hOut, FOREGROUND_GREEN);
				cout << "TRAFIONY, ZATOPIONY";
				cout << endl;
				if (dwojka1_1 == false)
				{
					SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
					cout << "  " << kratka << kratka << "  ";
				}
				else
				{
					SetConsoleTextAttribute(hOut, FOREGROUND_RED);
					cout << "  " << kratka << kratka << "  ";
				}
				if (dwojka2_1 == false)
				{
					SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
					cout << kratka << kratka << "  ";
				}
				else
				{
					SetConsoleTextAttribute(hOut, FOREGROUND_RED);
					cout << kratka << kratka << "  ";
				}
				if (dwojka3_1 == false)
				{
					SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
					cout << kratka << kratka;
				}
				else
				{
					SetConsoleTextAttribute(hOut, FOREGROUND_RED);
					cout << kratka << kratka;
				}
				cout << endl;

				if (trojka1_1 == false)
				{
					SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
					cout << "  " << kratka << kratka << kratka << "  ";
				}
				else
				{
					SetConsoleTextAttribute(hOut, FOREGROUND_RED);
					cout << kratka << kratka << kratka << "  ";
				}
				if (trojka2_1 == false)
				{
					SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
					cout << kratka << kratka << kratka;
				}
				else
				{
					SetConsoleTextAttribute(hOut, FOREGROUND_RED);
					cout << kratka << kratka << kratka;
				}

				SetConsoleTextAttribute(hOut, FOREGROUND_BLUE);
				spacje(36);

				cout << "XYZ" << ", to twoja tura! Strzelaj!";
				cout << endl;

				if (czworka1_1 == false)
				{
					SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
					cout << "  " << kratka << kratka << kratka << kratka;
				}
				else
				{
					SetConsoleTextAttribute(hOut, FOREGROUND_RED);
					cout << kratka << kratka << kratka << kratka;
				}
				cout << endl;

				SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
				spacje(22);
				cout << "Plansza gracza ";
				SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
				cout << "WROG";
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
				cout << "      " << kreska << "   ";
				SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY);


				cout << endl << "                                                           " << kreska << endl;
				for (int i = 0; i < 10; i++)
				{
					cout << "  ";
					SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY | BACKGROUND_RED);
					cout << i + 1;

					// POKAZUJE KROPKI DO GRY 
					for (int j = 0; j < 10; j++)
					{
						if (i == 9 && j == 0)
						{
							if (planszaInstr[i][j] != 2 && planszaInstr[i][j] != 5)
							{
								cout.width(4);
								SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
								cout << ".";
							}
							else if (planszaInstr[i][j] == 5)
							{
								cout.width(4);
								SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
								cout << "o";
							}
							else
							{
								cout.width(4);
								SetConsoleTextAttribute(hOut, FOREGROUND_RED);
								cout << "x";
							}
						}
						else
						{
							if (planszaInstr[i][j] != 2 && planszaInstr[i][j] != 5)
							{
								cout.width(5);
								SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
								cout << ".";
							}
							else if (planszaInstr[i][j] == 5)
							{
								cout.width(5);
								SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
								cout << "o";
							}
							else
							{
								cout.width(5);
								SetConsoleTextAttribute(hOut, FOREGROUND_RED);
								cout << "x";
							}
						}
					}
					SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY);
					cout << "      " << kreska;
					cout << endl;
					spacje(59);
					SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY);
					if (i != 9)
						cout << kreska;
					cout << endl;
				}
				string zatopiony = "Zatopilismy razem statek, brawo! Jak widzisz, w lewym gornym rogu dwumasztowiec stal sie czerwony.";
				string zatopiony2 = " Oznacza to, ze zostaljuz on zatopiony, co teraz nam mowi zielony tekst na gorze ekranu.";
				string zatopiony3 = " Na dodatek, wokol zatopionego statku pojawily sie   koleczka! Oznacza to, ze te miejsca sa puste i nie mozesz juz w nie strzelac.";
				string zatopiony4 = " Mam nadzieje, ze ci wszystko wyjasnilem.  Zycze ci udanej zabawy i samych wygranych!";
				int dlugosc_za1 = zatopiony.length();
				int dlugosc_za2 = zatopiony2.length();
				int dlugosc_za3 = zatopiony3.length();
				int dlugosc_za4 = zatopiony4.length();
				for (int i = 0; i < dlugosc_za1; i++)
				{
					cout << zatopiony[i];
					Sleep(100);
				}
				Sleep(2000);
				for (int i = 0; i < dlugosc_za2; i++)
				{
					cout << zatopiony2[i];
					Sleep(100);
				}
				Sleep(2000);
				for (int i = 0; i < dlugosc_za3; i++)
				{
					cout << zatopiony3[i];
					Sleep(100);
				}
				Sleep(2000);
				for (int i = 0; i < dlugosc_za4; i++)
				{
					cout << zatopiony4[i];
					Sleep(100);
				}
				Sleep(5000);
				instrukcja = 0;
				system("cls");
				dwojka1_1 = false;
			}
			else if (opcja == 2)
			{
				system("cls");
				SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
				komputer();
				SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
				string powitanie = "Witaj, jestem slaba maszyna liczaca 'Klodnica'. Moim zadaniem jest pokazanie Ci potrzebnych komend, ktore przydadza ci  sie podczas recznego ukladania statkow. Niestety jestem tylko slaba maszyna liczaca, a wiec nie zrobie Ci tak swietnego tutorialu, jak 'Kapitan', a jedynie wypisze ci ponizej najwazniejsze wskazowki.";
				int dl_powi1 = powitanie.length();
				for (int i = 0; i < dl_powi1; i++)
				{
					cout << powitanie[i];
					Sleep(100);
				}
				Sleep(3000);
				system("cls");

				spacje(45);
				SetConsoleTextAttribute(hOut, FOREGROUND_RED);
				cout << "USTAWIANIE STATKOW NA PLANSZE" << endl;
				spacje(25);
				SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
				cout << "1. Podaj dlugosc statku (1-4). Zatwierdz enterem." << endl;
				spacje(25);
				cout << "2. Podaj kolumne (A-J), wiersz (1-10) i zatwierdz enterem." << endl;
				spacje(25);
				cout << "3. Podaj kierunek (1-4). 1 - w gore, 2 - w prawo, 3 - w dol, 4 - w lewo." << endl << endl;
				spacje(45);
				SetConsoleTextAttribute(hOut, FOREGROUND_RED);
				cout << "SCIAGANIE STATKOW Z PLANSZY" << endl;
				spacje(25);
				SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
				cout << "1. Podaj dlugosc statku (1-4). Zatwierdz enterem." << endl;
				spacje(25);
				cout << "2. Jako kolumne i wiersz podajodpowiednio zera, a wiec wpisz '00' i zatwierdz enterem." << endl;
				spacje(25);
				cout << "3. Postepuj zgodnie z instrukcjami na ekranie." << endl << endl;
				spacje(45);
				SetConsoleTextAttribute(hOut, FOREGROUND_RED);
				cout << "ZAKONCZENIE UKLADANIA STATKOW" << endl;
				spacje(5);
				SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
				cout << "1. Kiedy wylozysz juz wszystkie statki na plansze, wpisz 'OK', kiedy program cie poprosi o podanie dlugosci statku." << endl;
				spacje(5);
				cout << "2. Jezeli wylozyles poprawnie wszystkie statki - przejdziesz dalej, inaczej program poprosi cie o poprawe." << endl << endl;
				spacje(45);
				SetConsoleTextAttribute(hOut, FOREGROUND_RED);
				cout << "REZYGNACJA Z WLASNORECZNEGO UKLADANIA" << endl;
				spacje(5);
				SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
				cout << "1. Jezeli chcesz jednak losowo rozlosowac statki, to wpisz 'POWROT', a program cie przeniesie do poprzedniego menu." << endl << endl;
				SetConsoleTextAttribute(hOut, FOREGROUND_RED);
				cout << "Aby powrocic do menu glowngo - wpisz [0]" << endl;
				SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);

				while (instrukcja != 0)
				{
					cin >> instrukcja;
					if (instrukcja == 0)
						instrukcja = 0;
					else
						cout << "Podano zla liczbe.";
				}

				system("cls");

			}

		}
		else if (instrukcja == 4)
		{
			int opcja = 1;
			while (opcja != 0)
			{
				system("cls");
				ramka("USTAWIENIA", wsk);
				spacje(40);
				SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
				cout << "Aby wrocic do ekranu glownego, wcisnij ";
				SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_RED);
				cout << "[0]" << endl << endl;
				SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
				spacje(40);
				cout << "Aby ";
				if (ekran_powitalny == true)
				{
					SetConsoleTextAttribute(hOut, FOREGROUND_RED);
					cout << "wylaczyc ";
				}
				else
				{
					SetConsoleTextAttribute(hOut, FOREGROUND_GREEN);
					cout << "wlaczyc ";
				}
				SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
				cout << "ekran powitalny, wcisnij ";
				SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_RED);
				cout << "[1]" << endl << endl;
				spacje(40);
				SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
				cout << "Aby ";
				if (muzyka == true)
				{
					SetConsoleTextAttribute(hOut, FOREGROUND_RED);
					cout << "wylaczyc ";
				}
				else
				{
					SetConsoleTextAttribute(hOut, FOREGROUND_GREEN);
					cout << "wlaczyc ";
				}
				SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
				cout << "muzyke, wcisnij ";
				SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_RED);
				cout << "[2]" << endl << endl;
				spacje(40);
				SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
				cout << "Aby ";
				if (efekty == true)
				{
					SetConsoleTextAttribute(hOut, FOREGROUND_RED);
					cout << "wylaczyc ";
				}
				else
				{
					SetConsoleTextAttribute(hOut, FOREGROUND_GREEN);
					cout << "wlaczyc ";
				}
				SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
				cout << "efekty dzwiekowe, wcisnij ";
				SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_RED);
				cout << "[3]" << endl << endl << endl;
				spacje(40);
				SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
				cout << "Wybierz opcje: ";
				cin >> opcja;
				prawda = cin.good();
				sprawdzCin(prawda);
				if (prawda != 0)
				{
					if (opcja == 0)
						instrukcja = 0;
					else if (opcja == 1)
					{
						if (ekran_powitalny == true) ekran_powitalny = false;
						else if (ekran_powitalny == false) ekran_powitalny = true;
					}
					else if (opcja == 2)
					{
						if (muzyka == true)
						{
							muzyka = false;
							PlaySound(L"wyciszenie.wav", NULL, SND_ASYNC);
						}
						else if (muzyka == false) muzyka = true;
					}
					else if (opcja == 3)
					{
						if (efekty == true) efekty = false;
						else if (efekty == false) efekty = true;
					}
					else
					{
						SetConsoleTextAttribute(hOut, FOREGROUND_RED);
						cout << "Dokonales zlego wyboru! Nie przechodz na ciemna strone mocy i wybierz wlasciwa cyfre!";
						Sleep(3000);
					}

					plik.open("ustawienia.txt", ios::out);
					if (ekran_powitalny == true)
						plik << 1 << endl;
					else
						plik << 0 << endl;
					if (muzyka == true)
						plik << 1 << endl;
					else
						plik << 0 << endl;
					if (efekty == true)
						plik << 1 << endl;
					else
						plik << 0 << endl;

					plik.close();
				}
			}
		}

		else
		{
			instrukcja = 0;
			system("cls");

		}

	}

	system("pause");
	return 0;


}

