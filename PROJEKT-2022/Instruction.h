#pragma once
#include <iostream>
#include <random>
#include <windows.h>
#include <conio.h>
#include <string>
#include <ctime>
#include <fstream>
using namespace std;
class Instruction
{
    int choose;
public:
    Instruction(int c);
    void show(void(*frame)(string, bool, int), void(*setCursor)(int, int), void(*moving)(int&, bool&, int n));
    void commands(void(*frame)(string, bool, int), void(*setCursor)(int, int), void(*moving)(int&, bool&, int n));
    void how_to_play();
};

