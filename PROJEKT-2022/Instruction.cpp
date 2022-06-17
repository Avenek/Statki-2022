#pragma once
#include "Instruction.h"
#include "Game.h"
#include "utils/CursorUtils.h"
#include "utils/FrameUtils.h"
#include <iostream>
#include <random>
#include <windows.h>
#include <conio.h>
#include <string>
#include <ctime>

using namespace std;

Instruction::Instruction(int c)
{
    choose = c;
}

void Instruction::commands()
{
   
}

void fill(int num)
{
	for (int a = 0; a < num; a++)
		cout << " ";
}


void showComputerImage()
{
	unsigned char LG = 201;
	unsigned char poziom = 205;
	unsigned char pion = 186;
	unsigned char LD = 200;
	unsigned char PG = 187;
	unsigned char PD = 188;


	cout << endl << endl;
	fill(54);
	cout << LG << poziom << poziom << poziom << poziom << poziom << poziom << poziom << poziom << poziom << poziom << poziom << poziom << poziom << poziom << poziom << poziom << PG << endl;
	fill(54);
	cout << pion;
	fill(16);
	cout << pion << endl;
	fill(54);
	cout << pion;
	cout << "    -      -    " << pion << endl;
	fill(54);
	cout << pion;
	fill(16);
	cout << pion << endl;
	fill(54);
	cout << pion;
	fill(16);
	cout << pion << endl;
	fill(54);
	cout << pion;
	fill(16);
	cout << pion << endl;
	fill(54);
	cout << pion << "    ________    ";
	cout << pion << endl;
	fill(54);
	cout << pion;
	fill(16);
	cout << pion << endl;
	fill(54);
	cout << LD << poziom << poziom << poziom << poziom << poziom << poziom << poziom << poziom << poziom << poziom << poziom << poziom << poziom << poziom << poziom << poziom << PD << endl << endl;
	Sleep(1000);
}

void setShipShotColorTutorial(bool red) {
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	if (red) {
		SetConsoleTextAttribute(hOut, FOREGROUND_RED);
	}
	else {
		SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
	}
}

void Instruction::how_to_play()
{
	Game game;
	system("cls");
	int planszaInstr[10][10]{};
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hOut, FOREGROUND_RED);
	showComputerImage();
	SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
	string powitanie = "Witaj, jestem komputerem pokladowym 'Kapitan' i moj stworca zlecil mi towarzyszenie ci podczas twojej pierwszej podrozy statkiem. Mam nadzieje, ze bedziemy sie dobrze bawic! To co? Pora wejsc na poklad!";
	int dlugosc_pow = powitanie.length();
	for (int i = 0; i < dlugosc_pow; i++)
	{
		cout << powitanie[i];
		Sleep(50);
	}
	Sleep(2000);
	system("cls");

	setShipShotColorTutorial(game.board1.one1);
	cout << "  " << game.CHECK_MARK << "  ";
	setShipShotColorTutorial(game.board1.one2);
	cout << game.CHECK_MARK << "  ";
	setShipShotColorTutorial(game.board1.one3);
	cout << game.CHECK_MARK << "  ";
	setShipShotColorTutorial(game.board1.one4);
	cout << game.CHECK_MARK;

	cout << endl;

	setShipShotColorTutorial(game.board1.two1);
	if (!game.board1.two1) {
		cout << "  " << game.CHECK_MARK << game.CHECK_MARK << "  ";
	}
	else {
		cout << game.CHECK_MARK << game.CHECK_MARK << "  ";
	}
	setShipShotColorTutorial(game.board1.two2);
	cout << game.CHECK_MARK << game.CHECK_MARK << "  ";
	setShipShotColorTutorial(game.board1.two3);
	cout << game.CHECK_MARK << game.CHECK_MARK;

	cout << endl;

	setShipShotColorTutorial(game.board1.three1);
	if (!game.board1.three1) {
		cout << "  " << game.CHECK_MARK << game.CHECK_MARK << game.CHECK_MARK << "  ";
	}
	else {
		cout << game.CHECK_MARK << game.CHECK_MARK << game.CHECK_MARK << "  ";
	}
	setShipShotColorTutorial(game.board1.three2);
	cout << game.CHECK_MARK << game.CHECK_MARK << game.CHECK_MARK;

	SetConsoleTextAttribute(hOut, FOREGROUND_BLUE);
	fill(36);

	cout << "XYZ" << ", to twoja tura! Strzelaj!";
	cout << endl;

	setShipShotColorTutorial(game.board2.three1);
	cout << game.CHECK_MARK << game.CHECK_MARK << game.CHECK_MARK << "  ";
	setShipShotColorTutorial(game.board2.three2);
	cout << game.CHECK_MARK << game.CHECK_MARK << game.CHECK_MARK;

	cout << endl;

	SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
	fill(22);
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
	cout << "      " << game.LINE_MARK << "   ";
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
		cout << "      " << game.LINE_MARK;
		cout << endl;
		fill(59);
		SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY);
		if (i != 10)
			cout << game.LINE_MARK;
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
		Sleep(50);
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

	setShipShotColorTutorial(game.board1.one1);
	cout << "  " << game.CHECK_MARK << "  ";
	setShipShotColorTutorial(game.board1.one2);
	cout << game.CHECK_MARK << "  ";
	setShipShotColorTutorial(game.board1.one3);
	cout << game.CHECK_MARK << "  ";
	setShipShotColorTutorial(game.board1.one4);
	cout << game.CHECK_MARK;

	fill(20);
	SetConsoleTextAttribute(hOut, FOREGROUND_RED);
	cout << "TRAFIONY";

	cout << endl;

	setShipShotColorTutorial(game.board1.two1);
	if (!game.board1.two1) {
		cout << "  " << game.CHECK_MARK << game.CHECK_MARK << "  ";
	}
	else {
		cout << game.CHECK_MARK << game.CHECK_MARK << "  ";
	}
	setShipShotColorTutorial(game.board1.two2);
	cout << game.CHECK_MARK << game.CHECK_MARK << "  ";
	setShipShotColorTutorial(game.board1.two3);
	cout << game.CHECK_MARK << game.CHECK_MARK;

	cout << endl;

	setShipShotColorTutorial(game.board1.three1);
	if (!game.board1.three1) {
		cout << "  " << game.CHECK_MARK << game.CHECK_MARK << game.CHECK_MARK << "  ";
	}
	else {
		cout << game.CHECK_MARK << game.CHECK_MARK << game.CHECK_MARK << "  ";
	}
	setShipShotColorTutorial(game.board1.three2);
	cout << game.CHECK_MARK << game.CHECK_MARK << game.CHECK_MARK;

	SetConsoleTextAttribute(hOut, FOREGROUND_BLUE);
	fill(36);

	cout << "XYZ" << ", to twoja tura! Strzelaj!";
	cout << endl;

	setShipShotColorTutorial(game.board1.four1);
	if (!game.board1.four1) {
		cout << "  " << game.CHECK_MARK << game.CHECK_MARK << game.CHECK_MARK << game.CHECK_MARK;
	}
	else {
		cout << game.CHECK_MARK << game.CHECK_MARK << game.CHECK_MARK << game.CHECK_MARK;
	}

	cout << endl;

	SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
	fill(22);
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
	cout << "      " << game.LINE_MARK << "   ";
	SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY);


	cout << endl << "                                                           " << game.LINE_MARK << endl;
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
		cout << "      " << game.LINE_MARK;
		cout << endl;
		fill(59);
		SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY);
		if (i != 9)
			cout << game.LINE_MARK;
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
		Sleep(50);
	}
	Sleep(2000);
	for (int i = 0; i < dlugosc_z2; i++)
	{
		cout << zestrzelony2[i];
		Sleep(50);
	}
	Sleep(2000);
	for (int i = 0; i < dlugosc_z3; i++)
	{
		cout << zestrzelony3[i];
		Sleep(50);
	}
	Sleep(2000);
	if (kolu == 1 && wier == 4)
	{
		cout << "B6";
		planszaInstr[wier + 1][kolu] = 2;
		game.board1.two1 = true;
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
			game.board1.two1 = true;
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
			game.board1.two1 = true;
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

	setShipShotColorTutorial(game.board1.one1);
	cout << "  " << game.CHECK_MARK << "  ";
	setShipShotColorTutorial(game.board1.one2);
	cout << game.CHECK_MARK << "  ";
	setShipShotColorTutorial(game.board1.one3);
	cout << game.CHECK_MARK << "  ";
	setShipShotColorTutorial(game.board1.one4);
	cout << game.CHECK_MARK;

	fill(14);
	SetConsoleTextAttribute(hOut, FOREGROUND_GREEN);
	cout << "TRAFIONY, ZATOPIONY";

	cout << endl;

	setShipShotColorTutorial(game.board1.two1);
	if (!game.board1.two1) {
		cout << "  " << game.CHECK_MARK << game.CHECK_MARK << "  ";
	}
	else {
		cout << game.CHECK_MARK << game.CHECK_MARK << "  ";
	}
	setShipShotColorTutorial(game.board1.two2);
	cout << game.CHECK_MARK << game.CHECK_MARK << "  ";
	setShipShotColorTutorial(game.board1.two3);
	cout << game.CHECK_MARK << game.CHECK_MARK;

	cout << endl;

	setShipShotColorTutorial(game.board1.three1);
	if (!game.board1.three1) {
		cout << "  " << game.CHECK_MARK << game.CHECK_MARK << game.CHECK_MARK << "  ";
	}
	else {
		cout << game.CHECK_MARK << game.CHECK_MARK << game.CHECK_MARK << "  ";
	}
	setShipShotColorTutorial(game.board1.three2);
	cout << game.CHECK_MARK << game.CHECK_MARK << game.CHECK_MARK;

	SetConsoleTextAttribute(hOut, FOREGROUND_BLUE);
	fill(36);

	cout << "XYZ" << ", to twoja tura! Strzelaj!";
	cout << endl;

	setShipShotColorTutorial(game.board2.three1);
	cout << game.CHECK_MARK << game.CHECK_MARK << game.CHECK_MARK << "  ";
	setShipShotColorTutorial(game.board2.three2);
	cout << game.CHECK_MARK << game.CHECK_MARK << game.CHECK_MARK;

	cout << endl;

	SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
	fill(22);
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
	cout << "      " << game.LINE_MARK << "   ";
	SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY);


	cout << endl << "                                                           " << game.LINE_MARK << endl;
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
		cout << "      " << game.LINE_MARK;
		cout << endl;
		fill(59);
		SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY);
		if (i != 9)
			cout << game.LINE_MARK;
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
		Sleep(50);
	}
	Sleep(2000);
	for (int i = 0; i < dlugosc_za2; i++)
	{
		cout << zatopiony2[i];
		Sleep(50);
	}
	Sleep(2000);
	for (int i = 0; i < dlugosc_za3; i++)
	{
		cout << zatopiony3[i];
		Sleep(50);
	}
	Sleep(2000);
	for (int i = 0; i < dlugosc_za4; i++)
	{
		cout << zatopiony4[i];
		Sleep(50);
	}
	Sleep(5000);
	system("cls");
	game.board1.two1 = false;
}

void Instruction::show()
{
    bool end = false;
    bool color = false;
    while (end == false)
    {
        CursorUtils::setCursor(1, 1);
        cout << endl << endl;
        FrameUtils::createFrame("Instrukcja dotyczaca rozgrywki", choose == 0, 0);   // Instrukcja
        FrameUtils::createFrame("Komendy - ukladanie statkow", choose == 1, 1);     // Wypisanie komend
        FrameUtils::createFrame("Menu glowne", choose == 2, 2);                     // Powrót do menu g³ównego
        FrameUtils::createMovementListener(choose, end, 2);
    }
    if (choose == 0)
        how_to_play();
    else if (choose == 1)
        commands();

    
}