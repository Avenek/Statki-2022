#pragma once
#include <iostream>
#include <random>
#include <windows.h>
#include <conio.h>
#include <string>
#include <ctime>
#include "Ship.h"
#include <fstream>
#include <vector>
using namespace std;

enum State {
	START_GAME
};

class ship;

class Board
{
public:

	
	friend class Ship;
	friend class Game;
	int gameBoard[10][10];
	Ship shipBoard[10][10];
	string playerName;
	State state;
	Board();
	~Board();
};

