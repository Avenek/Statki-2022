#include "CursorUtils.h"
#include <iostream>
#include <random>
#include <windows.h>
#include <conio.h>
#include <string>
#include <ctime>
#include <fstream>
#include "Menu.h"

using namespace std;

class Game;
Menu::Menu(int c, bool s)
{
    choose = c;
    if_menu = s;
}
void Menu::info(void(*frame)(string, bool, int), void(*moving)(int&, bool&, int n))
{
    HANDLE hOut;
    hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    bool end = false;
    while (end == false)
    {
        CursorUtils::setCursor(40, 1);                                               // Informacje o autorze
        cout << "Autorem projektu jest Jakub Machnik.";
        CursorUtils::setCursor(40, 2);
        cout << "Kontakt: j.machnik2002@gmail.com";
        CursorUtils::setCursor(40, 3);
        SetConsoleTextAttribute(hOut, FOREGROUND_RED);
        cout << "Copyright 2022 Jakub Machnik. All rights reserved.";
        SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE); 
        frame("Menu glowne", true, 1);                                          // Mo¿liwoœæ wyjœcia za pomoc¹ entera
        moving(choose, end, 0);
    }

   
}

int Menu::show(void(*frame)(string, bool, int), void(*moving)(int&, bool&, int n))
{
    HANDLE hOut;
    hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    bool end = false;
    bool color = false;
    while (end == false)
    {
        CursorUtils::setCursor(1, 1);                                                //Wyœwietlenie menu g³ównego, poruszanie siê za pomoc¹ strza³ek, akcept enterem
        cout << endl << endl;
        choose == 0 ? color = true : color = false;
        frame("Tryb dla dwoch graczy", color, 0);
        choose == 1 ? color = true : color = false;
        frame("Gra z komputerem", color, 1);
        choose == 2 ? color = true : color = false;
        frame("Instrukcja", color, 2);
        choose == 3 ? color = true : color = false;
        frame("Ustawienia", color, 3);
        choose == 4 ? color = true : color = false;
        frame("O autorze", color, 4);
        moving(choose, end, 4);
    }
    return choose;
}
