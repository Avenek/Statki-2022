#pragma once
#include <iostream>
#include <random>
#include <windows.h>
#include <conio.h>
#include <string>
#include <ctime>
#include <fstream>
using namespace std;

class Game
{
	bool versus_player;
	string player_name;
	string second_player_name;

public:
	friend class Ship;
};

