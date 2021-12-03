#include "Entity.h"

void Entity::SpawnEnemy(int type) {
	Enemy NewEnemy;

	switch (type) {
	case dummyType: 
		NewEnemy.name = "Dummy";
		NewEnemy.health = 100;
		NewEnemy.energy = 0;
		break;
	case warriorType:
		NewEnemy.name = "Warrior";
		NewEnemy.health = 100;
		NewEnemy.energy = 50;
		break;
	case skeletonType:
		NewEnemy.name = "Skeleton";
		NewEnemy.health = 75;
		NewEnemy.energy = 50;
		break;
	default: 
		NewEnemy.name = "Dummy";
		NewEnemy.health = 100;
		NewEnemy.energy = 0;
		break;
	}

	Entity.push_back(NewEnemy);
}

