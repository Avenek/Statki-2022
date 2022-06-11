#pragma once
#include <iostream>
#include <windows.h>

using namespace std;

class CursorUtils
{
public:
    static void setCursor(int, int);
    static void hideCursor();
    static void showCursor();
};

