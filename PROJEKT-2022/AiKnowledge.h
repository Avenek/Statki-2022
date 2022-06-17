#pragma once
#include "Game.h"

class AiKnowledge {
public:
	int calc{}, x{}, y{}, coord{};
	int tabx[100]{}, taby[100]{};
	bool isHit;
	int knownColumn = -1, knownRow = -1, knownDirection = 0, directionCheck = 0;

	void onHit(Game&, int&, int&);
	void resetData(Game&);
	void guessPosition(Game&, int&, int&);
};