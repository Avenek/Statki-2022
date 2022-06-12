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

enum State {
	START_GAME
};

class Board
{
public:
	int gameBoard[10][10];
	Ship ship_board[10][10];
	string playerName;
	State state;
};

