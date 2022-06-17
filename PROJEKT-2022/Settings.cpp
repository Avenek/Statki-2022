#include "utils/CursorUtils.h"
#include "utils/FrameUtils.h"
#include "utils/SoundUtils.h"
#include "Settings.h"
#include "Game.h"
#include <iostream>
#include <random>
#include <windows.h>
#include <conio.h>
#include <string>
#include <ctime>
#include <fstream>
using namespace std;


Settings::Settings(int c)
{
    choose = c;
}
void Settings::show(bool& welcome_screen, bool& music, bool& effects)
{
	HANDLE hOut;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	fstream plik;
	string option;
	bool end = false;
	bool color = false;
	while (end == false || choose != 3)
	{
		end = false;
		while (end == false)
		{
			CursorUtils::setCursor(1, 1);
			cout << endl << endl;
			welcome_screen == true ? option = "Wylacz " : option = "Wlacz ";	
			option += "ekran powitalny";
			FrameUtils::createFrame(option, choose == 0, 0);
			music == true ? option = "Wylacz " : option = "Wlacz ";
			option += "muzyke ";
			FrameUtils::createFrame(option, choose == 1, 1);
			effects == true ? option = "Wylacz " : option = "Wlacz ";		
			option += "efekty dzwiekowe ";
			FrameUtils::createFrame(option, choose == 2, 2);
			FrameUtils::createFrame("Menu glowne", choose == 3, 3);
			FrameUtils::createMovementListener(choose, end, 3);
		}
		if (choose == 0)
		{
			welcome_screen == true ? welcome_screen = false : welcome_screen = true;
		}
		else if (choose == 1)
		{
			if (music == true)
				SoundUtils::playSound("mute");
			else
				SoundUtils::playSound("game");
			music = !music;
		}
		else if (choose == 2)
		{
			effects == true ? effects = false : effects = true;
		}
		plik.open("ustawienia.txt", ios::out);
		welcome_screen == true ? plik << 1 << endl : plik << 0 << endl;
		music == true ? plik << 1 << endl : plik << 0 << endl;
		effects == true ? plik << 1 << endl : plik << 0 << endl;
		plik.close();
	}	
}

void Settings::load_settings(bool& welcome_screen, bool& music, bool& effects)
{
	fstream plik;
	int nr_line = 1;
	int check{};
	string line{};

	plik.open("ustawienia.txt", ios::in);
	if (plik.good() == false)
	{
		plik.close();
		plik.open("ustawienia.txt", ios::out);
		plik << "1" << endl << "1" << endl << "1";                   // W przypadku problemów z otwarciem pliku
		plik.close();                                                // tworzy siê nowy plik i ustawienia domyœlnie s¹ w³¹czone.
		welcome_screen = true;
		music = true;
		effects = true;
	}
	else
	{
		while (getline(plik, line))
		{
			// Pobiera dane z pliku i ustawia ustawienia do stanu z poprzedniego
			// 1 - true, 0 - false
			//Na wypadek manipulacji plikiem, ustawia wartoœæ true.
			check = atoi(line.c_str());
			if (nr_line == 1)
			{
				if (check == 0)
					welcome_screen = false;
				else
					welcome_screen = true;
			}
			else if (nr_line == 2)
			{
				if (check == 0)
					music = false;
				else
					music = true;
			}
			else if (nr_line == 3)
			{
				if (check == 0)
					effects = false;
				else
					effects = true;
			}
			nr_line++;
		}

		plik.close();
	}
}