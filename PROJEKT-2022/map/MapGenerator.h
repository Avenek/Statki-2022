#pragma once
#include "../Board.h"
#include "../Game.h"
#include "../Ship.h"
#include <iostream>

class MapGenerator {
private:
	void doGenerateRandomMap(Board&);
	void doShowDots(int[10][10]);
public:
	void chooseGenerationType(Game, Board);
	bool generateRandomMap(Board &);
	friend class Ship;
	
	friend class Board;
	
};