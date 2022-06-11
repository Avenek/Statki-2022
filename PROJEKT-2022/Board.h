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
	int player;
	string player_name;
public:
	void load_names();
};

