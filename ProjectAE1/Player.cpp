#include "Entity.h"

void Entity::SpawnPlayer(string name, int health, int energy) {
	Player Player;
	Player.name = name;
	Player.health = health;
	Player.energy = energy;
	//Entity.push_back(Player);
}