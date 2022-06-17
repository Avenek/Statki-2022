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
public:
	int gameBoard[10][10]{};
	Ship ship_board[10][10]{};
	string playerName;
	

	bool one1 = false;
	bool one2 = false;
	bool one3 = false;
	bool one4 = false;
	bool two1 = false;
	bool two2 = false;
	bool two3 = false;
	bool three1 = false;
	bool three2 = false;
	bool four1 = false;

	int getPlayerNameLength();
};

