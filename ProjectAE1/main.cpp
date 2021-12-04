#include <iostream>

#include "Enemy.h"

int main() {
	Entity Battleground1;
	
	Battleground1.SpawnEnemy(skeletonType);
	Battleground1.SpawnEnemy(skeletonType);
	Battleground1.SpawnEnemy(skeletonType);
	Battleground1.SpawnEnemy(skeletonType);
	Battleground1.SpawnEnemy(skeletonType);
	Battleground1.SpawnEnemy(skeletonType);
	Battleground1.SpawnEnemy(skeletonType);
	
#ifdef _DEBUG
	Battleground1.DebugListEnemy();
#endif
}