#pragma once
#include <iostream>
#include <random>
#include <windows.h>
#include <conio.h>
#include <string>
#include <ctime>
#include <fstream>
class Ship
{
protected:
	int lenght, x1, y1, direction;
	bool if_sunk, if_onBoard;
public:
	Ship();
	Ship(int, int, int, int, bool, bool);
	void load(int, int, int, int);
	friend class MapGenerator;
	bool operator!=(const Ship& other);
	
};

