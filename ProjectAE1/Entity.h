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
	friend ostream& operator<<(ostream& output, const Enemy& item) {
		return output << item.name << " HP:" << item.health << " E:" << item.energy << endl;
	}
};

class Entity {
	vector<Enemy> Entity;

public:
#ifdef _DEBUG
	void DebugEnemy() {
		for (size_t i = 0; i < Entity.size(); i++) //parse function
		{
			cout << Entity[i] << endl;
		}
	}
#endif

	void SpawnEnemy(int enemyType);
};