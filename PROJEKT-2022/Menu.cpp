#include "utils/CursorUtils.h"
#include "utils/FrameUtils.h"
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
void Menu::info()
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
        FrameUtils::createFrame("Menu glowne", true, 1);                                          // Mo¿liwoœæ wyjœcia za pomoc¹ entera
        FrameUtils::createMovementListener(choose, end, 0);
    }
}

int Menu::show()
{
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    bool end = false;
    bool color = false;
    while (end == false)
    {
        CursorUtils::setCursor(1, 1);                                                //Wyœwietlenie menu g³ównego, poruszanie siê za pomoc¹ strza³ek, akcept enterem
        cout << endl << endl;
        FrameUtils::createFrame("Tryb dla dwoch graczy", choose == 0, 0);
        FrameUtils::createFrame("Gra z komputerem", choose == 1, 1);
        FrameUtils::createFrame("Instrukcja", choose == 2, 2);
        FrameUtils::createFrame("Ustawienia", choose == 3, 3);
        FrameUtils::createFrame("O autorze", choose == 4, 4);
        FrameUtils::createMovementListener(choose, end, 4);
    }
    return choose;
}
