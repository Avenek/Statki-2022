#pragma once
#include <iostream>
#include <random>
#include <windows.h>
#include <conio.h>
#include <string>
#include <ctime>
#include <fstream>
#include "Board.h"
#include "Ship.h"
using namespace std;

Board::Board()
{
	for (int c = 0; c <= 9; c++)
	{
		for (int d = 0; d <= 9; d++)
		{
			gameBoard[c][d] = 0;
		}
	}

}
Board::~Board()
{

}
