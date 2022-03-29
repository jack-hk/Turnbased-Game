#pragma once

#include <iostream>
#include <random>
#include <string>

enum gameMode {
	trainingBattle,
	endlessBattle
};

struct Common { //common functions
	int RandomInt(int min, int max);
};

void StartGame(int gameMode); //gameflow
