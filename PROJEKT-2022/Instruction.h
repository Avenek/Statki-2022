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
    void show();
    void commands();
    void how_to_play();
};

