#include "Game.h"
#include "Entity.h"
#include "AI.h"

Common EntityCmn;

std::string actionPlayer;

//simple functions
int EntityHandler::GetEnergy(int target) {
	return Entities[target].energy;
}

int EntityHandler::GetHealth(int target) {
	return Entities[target].health;
}

std::string EntityHandler::GetName(int target) {
	return Entities[target].name;
}

int EntityHandler::GetController(int target) {
	return Entities[target].controller;
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
int EntityHandler::AIBrain(int self) {
	int choice = -1;
	switch (GetController(self)) {
	case player:
		//give player input
		break;
	case debuggerAI:
		choice = EntityCmn.RandomInt(0, 4); //used for defining AI types
		break;
	case humanlikeAI:
		choice = EntityCmn.RandomInt(0, 4);
		break;
	case undeadAI:
		choice = EntityCmn.RandomInt(0, 4);
		break;
	}
	return choice;
}

void EntityHandler::ChooseAction(int choice, int self, int target) {
	std::cout << std::endl;
	if (self == 0) { //player's turn
		std::cout << "1) Normal Attack" << std::endl;
		std::cout << "2) Special Attack" << std::endl;
		std::cout << "3) Recharge" << std::endl;
		std::cout << "4) Dodge" << std::endl;
		std::cout << "5) Heal" << std::endl;
		std::cin >> choice;
		choice = choice - 1;

		std::cout << "Who do you want to attack?:" << std::endl << std::endl;
		for (size_t i = 1; i < Entities.size(); i++) //parse function
		{
			std::cout << i << ". " << Entities[i].name << std::endl;
		}
		target = target + 1;
		std::cin >> target;
		int rng = EntityCmn.RandomInt(1, 10);
		switch (choice) {
		case normalAttack:
			if (rng < 9) { //80%
				NormalAttack(target);
			}
			break;
		case specialAttack:
			if (rng < 6) { //50%
				SpecialAttack(target);
			}
			break;
		case rechargeDefend:
			break;
		case dodgeDefend:
			break;
		case healPassive:
			HealPassive(self);
			break;
		}
	}
	else {
		//AIBrain(self);
		target = 0;
		switch (EntityCmn.RandomInt(0, 4)) {
		case normalAttack:
			NormalAttack(target);
			break;
		case specialAttack:
			SpecialAttack(target);
			break;
		case rechargeDefend:
			break;
		case dodgeDefend:
			break;
		case healPassive:
			HealPassive(self);
			break;
		}
	}
}

int EntityHandler::Turn(int gameMode){
	while (IsDead(0) == false) 
	{
		for (size_t turn = 0; turn < Entities.size(); turn++)
		{
			std::cout << std::endl;
			std::cout << GetName(turn) << " is deciding their action...";
			std::cout << std::endl;
			Sleep(SLEEP_SHORT); //change to const
#ifdef _DEBUG
			std::cout << turn;
#endif
			ChooseAction(-1, turn, PLAYER);
			std::cout << std::endl;
			EntityCmn.ClearConsole();
			SeeBattlefield(gameMode);
		}
	}
	return 0;
}

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
		IsDead(i);
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
	int rng = EntityCmn.RandomInt(MIN_NORMAL_DMG, MAX_NORMAL_DMG);
	DamageEntity(rng, target);
	std::cout << target << "was hit for " << rng << "damage!";
}
void EntityHandler::SpecialAttack(int target) {
	int rng = EntityCmn.RandomInt(MIN_SPECIAL_DMG, MAX_SPECIAL_DMG);
	DamageEntity(rng, target);
	std::cout << target << "was hit for " << rng << "damage!";
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