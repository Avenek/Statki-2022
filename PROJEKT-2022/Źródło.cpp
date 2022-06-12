#include <iostream>
#include <random>
#include <windows.h>
#include <conio.h>
#include <string>
#include <ctime>
#include <fstream>
#include "Ship.h"
#include "Board.h"
#include "Menu.h"
#include "Game.h"
#include "Instruction.h"
#include "Settings.h"
#include "utils/CursorUtils.h"

using namespace std;

Settings settings(0);

void play_music(string name) //Wybiera odpowiedni¹ muzykê dla zadanego argumentu.
{
	if(name=="game") PlaySound(L"music/game", NULL, SND_ASYNC | SND_LOOP);
	else if (name == "loseC") PlaySound(L"music/loseC", NULL, SND_ASYNC);
	else if (name == "empty") PlaySound(L"music/empty", NULL, SND_ASYNC);
	else if (name == "hit") PlaySound(L"music/hit", NULL, SND_ASYNC);
	else if (name == "mute") PlaySound(L"music/mute", NULL, SND_ASYNC);
	else if (name == "winC") PlaySound(L"music/winC", NULL, SND_ASYNC);
	else if (name == "winP") PlaySound(L"music/winP", NULL, SND_ASYNC);
	else if (name == "sunk") PlaySound(L"music/sunk", NULL, SND_ASYNC);
}
void show_welcome()
{
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hOut, FOREGROUND_RED);
	CursorUtils::setCursor(26, 1);																					// Ekran startowy      
	cout << "Statek w porcie jest bezpieczny, ale nie po to buduje sie statki..." << endl;
	Sleep(5000);
	SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE);
	ifstream file ("welcome.txt");
	string line;
	while (file >> line) {
		cout << endl << line;
		Sleep(100);
	}
	file.close();
	Sleep(3000);
	system("cls");
}

int main()
{
	CursorUtils::hideCursor();
	// ZMIENNE USTAWIENIA, POBOROWE PLIKU, KOLORU I PRZYCISKU//
	bool welcome_screen = true;
	bool music = true;
	bool effects = true;
	HANDLE hOut;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);

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
	CONSOLE_SCREEN_BUFFER_INFO sbi;
	GetConsoleScreenBufferInfo(handle, &sbi);

	//POZOSTA£E ZMIENNE//
	bool if_true{};
	unsigned char dash = 179;
	unsigned char square = 254;

	
	settings.load_settings(welcome_screen, music, effects);			//wczytanie danych z pliku

	if (music == true)
		play_music("game");
	if (welcome_screen == true)
		show_welcome();												//puszczenie muzyki, w³¹czenie ekranu powitalnego zale¿nie od ustawieñ
	
	Menu menu(0, true);
	
	while (menu.if_menu == true)
	{
		int option = menu.show();	// Pokazanie ekranu menu g³ównego wraz z wyborem
		if (option == 0)
		{
			Game game;											// Gra z przeciwnikiem
			
			game.createGame(VERSUS_PLAYER);
		}
		else if (option == 1)
		{
			Game game;											// Gra z komputerem
			game.createGame(VERSUS_COMPUTER);
		}
		else if (option == 2)
		{
			Instruction instruction(0);
			instruction.show();    // Instrukcja
		}
		else if (option == 3)
		{
			settings.show(&play_music, welcome_screen, music, effects);    // Instrukcja
		}
		else if (option == 4)
		{
			menu.info();			 // O autorze
		}
	}

	system("pause");
	return 0;
}