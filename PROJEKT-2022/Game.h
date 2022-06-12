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
	bool versusPlayer;
	string name1, name2;
	AiMode aiMode;

public:
	void createGame(GameType);
	void generateMap();
	friend class Ship;
};

