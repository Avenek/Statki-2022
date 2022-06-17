#pragma once
#include "Board.h"
#include <iostream>
#include <windows.h>
#include <conio.h>
#include <string>
#include <ctime>
#include <fstream>
#include "AiKnowledge.h"

using namespace std;

enum State {
	START_GAME
};

enum GameType {
	VERSUS_PLAYER, VERSUS_COMPUTER
};

enum AiMode {
	NONE, EASY, MEDIUM, HARD
};

class Game
{
public:
	const unsigned char CHECK_MARK = 254;
	const unsigned char LINE_MARK = 179;

	Board board1, board2;
	clock_t start, stop;
	bool playerOneTurn = false;

	bool versusPlayer, music, effects;
	State state;
	AiMode aiMode;
	AiKnowledge aiKnowledge;
	void createGame(GameType);
	void generateMap(Game);
	void startGame(Game);
	friend class Ship;
	friend class AiKnowledge;
};

