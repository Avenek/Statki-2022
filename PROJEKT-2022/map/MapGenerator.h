#pragma once
#include "../Board.h"
#include "../Game.h"
#include <iostream>

class MapGenerator {
private:
	void doGenerateRandomMap(int[10][10]);
	void doGenerateHandMap(int[10][10], bool, void(*deleteShip)(int, int, int[10][10]));
	void doShowDots(int[10][10]);
	
public:
	void chooseGenerationType(Game&, Board&);
	bool generateRandomMap(Game&, Board&, bool);
	void deleteShip(int, int, int[10][10]);
};