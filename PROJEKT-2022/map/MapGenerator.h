#pragma once
#include "../Board.h"
#include <iostream>

class MapGenerator {
private:
	void doGenerateRandomMap(int[10][10]);
	void doShowDots(int[10][10]);
public:
	void generateRandomMap(Board);
};