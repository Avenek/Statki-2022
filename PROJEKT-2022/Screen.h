#pragma once
#include <iostream>
#include <random>
#include <windows.h>
#include <conio.h>
#include <string>
#include <ctime>
#include <fstream>
class Screen
{
public:
virtual	int show(void(*frame)(string, bool, int), void(*setCursor)(int, int), void(*moving)(int&, bool));
};

