#pragma once
#include "SoundUtils.h"
#include <windows.h>
#include <iostream>
#include <string>

using namespace std;

void SoundUtils::playSound(string name) {
	if (name == "game") PlaySound(L"music/game", NULL, SND_ASYNC | SND_LOOP);
	else if (name == "loseC") PlaySound(L"music/loseC", NULL, SND_ASYNC);
	else if (name == "empty") PlaySound(L"music/empty", NULL, SND_ASYNC);
	else if (name == "hit") PlaySound(L"music/hit", NULL, SND_ASYNC);
	else if (name == "mute") PlaySound(L"music/mute", NULL, SND_ASYNC);
	else if (name == "winC") PlaySound(L"music/winC", NULL, SND_ASYNC);
	else if (name == "winP") PlaySound(L"music/winP", NULL, SND_ASYNC);
	else if (name == "sunk") PlaySound(L"music/sunk", NULL, SND_ASYNC);
}
