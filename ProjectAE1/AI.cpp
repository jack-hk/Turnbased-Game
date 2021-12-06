#include "Game.h"
#include "Entity.h"
#include "AI.h"


void Action::ChooseAction(int choice, int self, int target) {
	EntityHandler AI;
	switch (choice) {
	case normalAttack:
		AI.NormalAttack(target);
		break;
	case specialAttack:
		AI.SpecialAttack(target);
		break;
	case rechargeDefend:
		break;
	case dodgeDefend:
		break;
	case healPassive:
		AI.HealPassive(self);
		break;
	}
}