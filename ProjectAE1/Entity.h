#pragma once

#include <vector>

static const int PLAYER = 0;
static const int ENEMY1 = 1;
static const int ENEMY2 = 2;

static const int MIN_NORMAL_DMG = 1;
static const int MAX_NORMAL_DMG = 10;

static const int MIN_SPECIAL_DMG = 5;
static const int MAX_SPECIAL_DMG = 20;

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
public:
	//simple functions
	int GetEnergy(int target);
	int GetHealth(int target);
	std::string GetName(int name);
	int GetController(int target);
	int DamageEntity(int damage, int target);
	int HealEntity(int heal, int target);
	int ReduceEnergy(int reduction, int target);
	int AddEnergy(int addition, int target);

	//entity
	int AIBrain(int self);
	void ChooseAction(int choice, int self, int target);
	void SpawnEntity(int entityType);
	void ListAllEntity();

	//checks
	int Turn(int gameMode);
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