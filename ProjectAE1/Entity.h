#pragma once

#include <iostream>
#include <string>
#include <vector>

using namespace std;

//#ifdef _DEBUG
//bool debugMode = true; //Debug
//#endif // _DEBUG

enum enemyType {
	dummyType,
	warriorType,
	skeletonType
};

struct Enemy {
	string name = "Enemy";
	int health = 0;
	int energy = 0;
	int type = 0;
	friend ostream& operator<<(ostream& output, const Enemy& item) {
		return output << item.name << endl;
	}
};

struct Player {
	string name = "Player";
	int health = 0;
	int energy = 0;
};


class Entity {
	vector<Enemy> Entity;
public:

	void SpawnEnemy(int enemyType);
	void SpawnPlayer(string name, int health, int energy);
	void DebugEnemy() {
		for (size_t i = 0; i < Entity.size(); i++) //parse function
		{
#ifdef _DEBUG
			cout << "debugging";
#endif
			cout << Entity[i] << endl;
		}
	}
};