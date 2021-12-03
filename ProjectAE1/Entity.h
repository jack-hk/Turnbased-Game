#pragma once

#include <iostream>
#include <string>
#include <vector>

using namespace std;

//#ifdef _DEBUG
//bool debugMode = true; //Debug
//#endif // _DEBUG

struct Player {
	string name = "Player";
	int health = 0;
	int energy = 0;
};

struct Enemy {
	string name = "Enemy";
	int health = 0;
	int energy = 0;
};

class Entity {
	vector<Enemy> Entity;
public:

	void SpawnEnemy(int enemyType);
	void SpawnPlayer(string name, int health, int energy);
};