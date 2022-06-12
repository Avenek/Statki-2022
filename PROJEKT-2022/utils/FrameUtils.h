#pragma once
#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

class FrameUtils
{
public:
    static void createFrame(string, bool, int);
    static void createFrame(string, bool, int, int, int);
    static void createMovementListener(int&, bool&, int);
};
