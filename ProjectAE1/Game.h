#pragma once

#include <iostream>
#include <random>
#include <string>
#include <windows.h>

static const int SLEEP_SHORT = 1000;
static const int SLEEP_LONG = 1500;

enum gameMode {
	trainingBattle,
	endlessBattle
};

struct Common { //common functions
	void ClearConsole();
	int RandomInt(int min, int max);
};

void StartGame(int gameMode); //gameflow
void SeeBattlefield(int gameMode);
