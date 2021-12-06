#pragma once

#include <vector>

enum entityType {
	classPlayer,
	warriorEnemy,
	skeletonEnemy
};

struct Entity {
	std::string name = "entity";
	int health = 0;
	int energy = 0;
	int controller = 1;
	friend std::ostream& operator<<(std::ostream& output, const Entity& entity) {
		return output << entity.name << " HP:" << entity.health << " E:" << entity.energy << std::endl;
	}
};

class EntityHandler {
	std::vector<Entity> Entities;

	//simple functions
	int GetEnergy(int target);
	int GetHealth(int target);
	int DamageEntity(int damage, int target);
	int HealEntity(int heal, int target);
	int ReduceEnergy(int reduction, int target);
	int AddEnergy(int addition, int target);
public:
	//entity
	void SpawnEntity(int entityType);
	void ListAllEntity();

	//checks
	bool IsDead(int target); 

	//actions
	void HealPassive(int target); 
	void NormalAttack(int target);
	void SpecialAttack(int target);
	void RechargeDefend(int target);
	void DodgeDefend(int target);

//debugger functions
#ifdef _DEBUG

#endif

};