#pragma once
#include <iostream>
#include <random>
#include <windows.h>
#include <conio.h>
#include <string>
#include <ctime>
#include <fstream>
using namespace std;
class Menu
{
	friend class Game;
protected:
	int choose;
public:
	Menu(int c, bool s);
	bool if_menu;
	int show(void(*frame)(string, bool, int), void(*moving)(int&, bool&, int n));
	void info(void(*frame)(string, bool, int), void(*moving)(int&, bool&, int n));
	
};

