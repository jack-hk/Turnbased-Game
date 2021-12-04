#include "Enemy.h"

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
	Entities.push_back(NewEnemy);
}

int Entity::DamageEnemy(int damage, int index) {
	return Entities[index].health = Entities[index].health - damage;
}

int Entity::HealEnemy(int heal, int index) {
	return Entities[index].health = Entities[index].health + heal;
}

//debugger functions
#ifdef _DEBUG
void Entity::DebugListEnemy() {
	for (size_t i = 0; i < Entities.size(); i++) //parse function
	{
		cout << Entities[i] << endl;
	}
}
#endif