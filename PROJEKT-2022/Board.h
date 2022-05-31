#pragma once
#include <iostream>
#include <random>
#include <windows.h>
#include <conio.h>
#include <string>
#include <ctime>
#include "Ship.h"
#include <fstream>
using namespace std;
class Ship;
class Board
{
protected:
	int board[10][10];
	Ship ship_board[10][10];
	int player; // 1 = pierwszy gracz, 2 = drugi gracz 
public:
	void load_names();
};

