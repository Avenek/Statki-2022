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
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
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
        frame("Menu glowne", true, 1);                                          // Mo�liwo�� wyj�cia za pomoc� entera
        moving(choose, end, 0);
    }
}

int Menu::show(void(*frame)(string, bool, int), void(*moving)(int&, bool&, int n))
{
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    bool end = false;
    bool color = false;
    while (end == false)
    {
        CursorUtils::setCursor(1, 1);                                                //Wy�wietlenie menu g��wnego, poruszanie si� za pomoc� strza�ek, akcept enterem
        cout << endl << endl;
        frame("Tryb dla dwoch graczy", choose == 0, 0);
        frame("Gra z komputerem", choose == 1, 1);
        frame("Instrukcja", choose == 2, 2);
        frame("Ustawienia", choose == 3, 3);
        frame("O autorze", choose == 4, 4);
        moving(choose, end, 4);
    }
    return choose;
}
