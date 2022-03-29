#include "Game.h"
#include "Entity.h"
#include "AI.h"

Common EntityCmn;

//simple functions
int EntityHandler::GetEnergy(int target) {
	return Entities[target].energy;
}

int EntityHandler::GetHealth(int target) {
	return Entities[target].health;
}

int EntityHandler::DamageEntity(int damage, int target) {
	if (Entities[target].health - damage < 1) {
		return Entities[target].health = 0;
	}
	else
		return Entities[target].health = Entities[target].health - damage;
}

int EntityHandler::HealEntity(int heal, int target) {
	return Entities[target].health = Entities[target].health + heal;
}

int EntityHandler::ReduceEnergy(int reduction, int target) {
	if (Entities[target].energy - reduction < 1) {
		return Entities[target].energy = 0;
	}
	else
		return Entities[target].energy = Entities[target].energy - reduction;
}

int EntityHandler::AddEnergy(int addition, int target) {
	return Entities[target].energy = Entities[target].energy + addition;
}

//entity
void EntityHandler::SpawnEntity(int type) {
	Entity NewEntity;

	switch (type) {
	case classPlayer:
		NewEntity.name = "Player";
		NewEntity.health = 100;
		NewEntity.energy = 50;
		NewEntity.controller = player;
		break;
	case warriorEnemy:
		NewEntity.name = "Warrior";
		NewEntity.health = 100;
		NewEntity.energy = 50;
		NewEntity.controller = humanlikeAI;
		break;
	case skeletonEnemy:
		NewEntity.name = "Skeleton";
		NewEntity.health = 75;
		NewEntity.energy = 50;
		NewEntity.controller = undeadAI;
		break;
	default: 
		NewEntity.name = "Dummy";
		NewEntity.health = 100;
		NewEntity.energy = 50;
		NewEntity.controller = debuggerAI;
		break;
	}
	Entities.push_back(NewEntity);
}

void EntityHandler::ListAllEntity() {
	for (size_t i = 0; i < Entities.size(); i++) //parse function
	{
		std::cout << Entities[i];
	}
}

//checks
bool EntityHandler::IsDead(int target) {
	if (Entities[target].health < 1) {
		std::cout << Entities[target].name;
		std::cout << " has been defeated!" << std::endl;
		Entities.erase(Entities.begin() + target);
		return true; //killed
	} else
	return false;
}

//actions
void EntityHandler::NormalAttack(int target) {
	DamageEntity(EntityCmn.RandomInt(1,10), target);
}
void EntityHandler::SpecialAttack(int target) {
	DamageEntity(EntityCmn.RandomInt(5, 20), target);
}
void EntityHandler::RechargeDefend(int target) {

}
void EntityHandler::DodgeDefend(int target) {

}
void EntityHandler::HealPassive(int target) {
	int halfEnergy = GetEnergy(target) / 2;
	ReduceEnergy(halfEnergy, target);
	HealEntity(halfEnergy, target);
	return;
}

//debugger functions
#ifdef _DEBUG
#endif