#include "Instruction.h"
#include "Game.h"
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
void Instruction::commands(void(*frame)(string, bool, int), void(*setCursor)(int, int), void(*moving)(int&, bool&, int n))
{
   
}
void Instruction::how_to_play()
{

}
void Instruction::show(void(*frame)(string, bool, int), void(*setCursor)(int, int), void(*moving)(int&, bool&, int n))
{
    bool end = false;
    bool color = false;
    while (end == false)
    {
        setCursor(1, 1);
        cout << endl << endl;
        choose == 0 ? color = true : color = false;
        frame("Instrukcja dotyczaca rozgrywki", color, 0);   // Instrukcja
        choose == 1 ? color = true : color = false;
        frame("Komendy - ukladanie statkow", color, 1);     // Wypisanie komend
        choose == 2 ? color = true : color = false;
        frame("Menu glowne", color, 2);                     // Powrót do menu g³ównego
        moving(choose, end, 2);
    }
    if (choose == 0) how_to_play();
    else if (choose == 1) commands(frame, setCursor, moving);

    
}