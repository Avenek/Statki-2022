#include <iostream>
#include <random>
#include <windows.h>
#include <conio.h>
#include <string>
#include <ctime>
#include <fstream>
#include "Board.h"

using namespace std;

int Board::getPlayerNameLength() {
	return playerName.length() - (playerName.length() % 2);
}