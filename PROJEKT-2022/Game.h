#pragma once
#include "Board.h"
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
	Board board1, board2;
public:
	bool versusPlayer;
	AiMode aiMode;
	void createGame(GameType);
	void generateMap(Game);
	friend class Ship;
};

