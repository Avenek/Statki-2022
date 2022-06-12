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
void Instruction::how_to_play()
{

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