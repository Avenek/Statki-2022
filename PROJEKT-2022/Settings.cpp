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
void Settings::show(void(*frame)(string, bool, int), void(*setCursor)(int, int), void(*moving)(int&, bool&, int n), void(*play_music)(string), bool& welcome_screen, bool& music, bool& effects)
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
			setCursor(1, 1);
			cout << endl << endl;
			welcome_screen == true ? option = "Wylacz " : option = "Wlacz ";	
			option += "ekran powitalny";
			choose == 0 ? color = true : color = false;
			frame(option, color, 0);
			music == true ? option = "Wylacz " : option = "Wlacz ";
			option += "muzyke ";
			choose == 1 ? color = true : color = false;
			frame(option, color, 1);
			effects == true ? option = "Wylacz " : option = "Wlacz ";		
			option += "efekty dzwiekowe ";
			choose == 2 ? color = true : color = false;
			frame(option, color, 2);
			choose == 3 ? color = true : color = false;
			frame("Menu glowne", color, 3);
			moving(choose, end, 3);
		}
		if (choose == 0)
		{
			welcome_screen == true ? welcome_screen = false : welcome_screen = true;
		}
		else if (choose == 1)
		{
			if (music == true)
			{
				music = false;
				play_music("mute");
			}
			else
			{
				music = true;
				play_music("game");
			}
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