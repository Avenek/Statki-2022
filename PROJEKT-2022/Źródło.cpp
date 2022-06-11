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
using namespace std;
void setCursor(int x, int y)
{
	COORD c;
	c.X = x - 1;
	c.Y = y - 1;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}
void load_settings(bool & welcome_screen, bool & music, bool & effects)
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

			if (nr_line == 1)
			{
				check = atoi(line.c_str());
				if (check == 1)
					welcome_screen = true;
				else if (check == 0)							// Pobiera dane z pliku i ustawia ustawienia do stanu z poprzedniego
					welcome_screen = false;						// 1 - true, 0 - false
				else
					welcome_screen = true;						//Na wypadek manipulacji plikiem, ustawia wartoœæ true.
			}
			else if (nr_line == 2)
			{
				check = atoi(line.c_str());
				if (check == 1)
					music = true;
				else if (check == 0)
					music = false;
				else
					music = true;
			}
			else if (nr_line == 3)
			{
				check = atoi(line.c_str());
				if (check == 1)
					effects = true;
				else if (check == 0)
					effects = false;
				else
					effects= true;
			}

			nr_line++;
		}

		plik.close();						
	}

}
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
	HANDLE hOut;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hOut, FOREGROUND_RED);
	setCursor(26, 1);																					// Ekran startowy      
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
	system("cls");
}
void frame(string napis, bool color=false, int n=0)
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
	int dl = napis.length();
	setCursor(42,1+6*n);
	if (color == false)
		SetConsoleTextAttribute(hOut, FOREGROUND_RED);
	else
		SetConsoleTextAttribute(hOut, FOREGROUND_GREEN);
	cout << LG;
	for (int a = 0; a < 30; a++)
		cout << poziom;
	cout << PG << endl;
	setCursor(42, 2 + 6 * n);
	cout << pion;
	setCursor(73, 2 + 6 * n);
	cout << pion << endl;
	setCursor(42, 3 + 6 * n);
	if (color == false)
		SetConsoleTextAttribute(hOut, FOREGROUND_RED);
	else
		SetConsoleTextAttribute(hOut, FOREGROUND_GREEN);
	cout << pion;
	if (color == false)
		SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_GREEN);
	else
		SetConsoleTextAttribute(hOut, FOREGROUND_BLUE);
	setCursor(43 + (31 - dl) / 2 , 3 + 6 * n);
	cout << napis;
	setCursor(42 + (30 - dl) / 2 , 3 + 6 * n);
	if (color == false)
		SetConsoleTextAttribute(hOut, FOREGROUND_RED);
	else
		SetConsoleTextAttribute(hOut, FOREGROUND_GREEN);
	setCursor(73, 3 + 6 * n);
	cout << pion << endl;
	setCursor(42,4 + 6 * n);
	cout << pion;
	setCursor(73, 4 + 6 * n);
	cout << pion << endl;
	setCursor(42, 5 + 6 * n);
	cout << LD;
	for (int a = 0; a < 30; a++)
		cout << poziom;
	cout << PD << endl;
	SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);


}
void HideCursor()
{
	::HANDLE hConsoleOut = ::GetStdHandle(STD_OUTPUT_HANDLE);
	::CONSOLE_CURSOR_INFO hCCI;
	::GetConsoleCursorInfo(hConsoleOut, &hCCI);
	hCCI.bVisible = FALSE;
	::SetConsoleCursorInfo(hConsoleOut, &hCCI);
}
void ShowCursor()
{
	::HANDLE hConsoleOut = ::GetStdHandle(STD_OUTPUT_HANDLE);
	::CONSOLE_CURSOR_INFO hCCI;
	::GetConsoleCursorInfo(hConsoleOut, &hCCI);
	if (hCCI.bVisible != TRUE)
	{
		hCCI.bVisible = TRUE;
		::SetConsoleCursorInfo(hConsoleOut, &hCCI);
	}
}
void moving(int &choose, bool &end, int number)
{
	unsigned char sign = 224;
	switch (sign)
	{
	case 0: //klawisze specjalne (czasem zero, czasem 224 - zale¿ne od pc'ta chyba)
	case 224: //klawisze specjalne
	{
		sign = _getch();
		if (sign == 72 && choose > 0 && number !=0) //strza³ka w górê
			choose -= 1;

		else if (sign == 80 && choose < number) //strza³ka w dó³
			choose += 1;
		else if (sign == 13) //ENTER
		{
			end = true;
			system("cls");
		}
	}
	}
}

int main()
{
	HideCursor(); // Schowanie kursora //
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

	
	
	load_settings(welcome_screen, music, effects);			//wczytanie danych z pliku

	if (music == true)
		play_music("game");
	if (welcome_screen == true)
		show_welcome();												//puszczenie muzyki, w³¹czenie ekranu powitalnego zale¿nie od ustawieñ
	
	Menu menu(0, true);
	
	while (menu.if_menu == true)
	{
		int option = menu.show(&frame, &setCursor, &moving);	// Pokazanie ekranu menu g³ównego wraz z wyborem
		if (option == 0)
			Game game;											// Gra z przeciwnikiem
		else if (option == 1)
			Game game;											// Gra z komputerem
		else if (option == 2)
		{
			Instruction instruction(0);
			instruction.show(&frame, &setCursor, &moving);    // Instrukcja
		}
		else if (option == 3)
		{
			Settings settings(0);
			settings.show(&frame, &setCursor, &moving, &play_music, welcome_screen, music, effects);    // Instrukcja
		}
		else if (option == 4)
		{
			menu.info(&frame, &setCursor, &moving);			 // O autorze
		}
	}

	system("pause");
	return 0;
}