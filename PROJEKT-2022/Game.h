#pragma once
#include <iostream>
#include <random>
#include <windows.h>
#include <conio.h>
#include <string>
#include <ctime>
#include <fstream>
using namespace std;

enum GameType {
	VERSUS_PLAYER, VERSUS_COMPUTER
};

enum AiMode {
	NONE, EASY, MEDIUM, HARD
};

class Game
{
	bool versus_player;
	AiMode aiMode;

public:
	void createGame(GameType, void(*frame)(string, bool, int), void(*moving)(int&, bool&, int n));
	friend class Ship;
};

