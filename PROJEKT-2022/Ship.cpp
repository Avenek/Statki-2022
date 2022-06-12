#pragma once
#include <iostream>
#include <random>
#include <windows.h>
#include <conio.h>
#include <string>
#include <ctime>
#include <fstream>
#include "Ship.h"
using namespace std;
Ship::Ship()
{
	lenght = 0;
	x1 = 0;
	y1 = 0;
	direction = 0;
	if_sunk = 0;
	if_onBoard = false;

}
Ship::Ship(int len = 0, int x = 0, int y = 0, int dir = 0, bool sunk = false, bool onBoard = false)
{
	lenght = len;
	x1 = x;
	y1 = y;
	direction = dir;
	if_sunk = sunk;
	if_onBoard = onBoard;
}
bool Ship::operator!=(const Ship& other)
{
	if (lenght == other.lenght && x1 == other.x1 && y1 == other.y1 && direction == other.direction) return true;
	else return false;

}
void Ship::load(int len, int x, int y, int dir)
{
	lenght = len;
	x1 = x;
	y1 = y;
	direction = dir;
	if_onBoard = true;

}
