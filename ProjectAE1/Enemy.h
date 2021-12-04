#pragma once

#include <iostream>
#include <string>
#include <vector>

using namespace std;

enum enemyType {
	dummyType,
	warriorType,
	skeletonType
};

struct Enemy {
	string name = "Enemy";
	int health = 0;
	int energy = 0;
#ifdef _DEBUG
	friend ostream& operator<<(ostream& output, const Enemy& item) {
		return output << item.name << " HP:" << item.health << " E:" << item.energy << endl;
	}
#endif
};

class Entity {
	vector<Enemy> Entities;

public:
	void SpawnEnemy(int enemyType);
	int DamageEnemy(int damage, int index);
	int HealEnemy(int heal, int index);

//debugger functions
#ifdef _DEBUG
	void DebugListEnemy();
#endif

};