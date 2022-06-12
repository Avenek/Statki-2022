#pragma once
#include <iostream>
#include <random>
#include <windows.h>
#include <conio.h>
#include <string>
#include <ctime>
#include <fstream>
using namespace std;

class Settings
{
    int choose;
public:
    Settings(int c);
    void show(void(*play_music)(string), bool&, bool&, bool&);
    void load_settings(bool& welcome_screen, bool& music, bool& effects);
};
