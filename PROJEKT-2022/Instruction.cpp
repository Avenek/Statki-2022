#include "Instruction.h"
#include "Game.h"
#include "CursorUtils.h"
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
void Instruction::commands(void(*frame)(string, bool, int), void(*moving)(int&, bool&, int n))
{
   
}
void Instruction::how_to_play()
{

}
void Instruction::show(void(*frame)(string, bool, int), void(*moving)(int&, bool&, int n))
{
    bool end = false;
    bool color = false;
    while (end == false)
    {
        CursorUtils::setCursor(1, 1);
        cout << endl << endl;
        frame("Instrukcja dotyczaca rozgrywki", choose == 0, 0);   // Instrukcja
        frame("Komendy - ukladanie statkow", choose == 1, 1);     // Wypisanie komend
        frame("Menu glowne", choose == 2, 2);                     // Powrót do menu g³ównego
        moving(choose, end, 2);
    }
    if (choose == 0) how_to_play();
    else if (choose == 1) commands(frame, moving);

    
}