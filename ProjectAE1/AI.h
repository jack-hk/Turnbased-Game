#pragma once

enum controllerType {
	player, 
	//The player controls.

	debuggerAI, 
	//AI used for debugging; entity does not attack, just defends and heals.

	humanlikeAI, 
	//AI used by human enemies; values its life above anything else.

	undeadAI 
	//AI used by undead enemies; focuses on destroying the player above anything else.
};

enum actionChoice {
	normalAttack,
	specialAttack,
	rechargeDefend,
	dodgeDefend,
	healPassive
};

struct Action {
	void ChooseAction(int choice, int self, int target);
};