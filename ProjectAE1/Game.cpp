#include "Game.h"
#include "Entity.h"
#include "UI.h"
#include "AI.h"

Common GameCmn;
UI BattleUI;

//common functions
int Common::RandomInt(int min, int max) { //Random numbers without using system time.
	std::random_device rd;
	std::mt19937 rng(rd());
	std::uniform_int_distribution<int> uni(min, max);
	auto random_integer = uni(rng);
	return random_integer;
}

//gameflow
void StartGame(int gameMode) {
	EntityHandler TrainingGround;
	EntityHandler EndlessBattleground;

	BattleUI.DisplayCutscene(gameMode);
	switch (gameMode) {
	case trainingBattle:

		TrainingGround.SpawnEntity(classPlayer); //spawn player at 0 index (1st turn every time)
		TrainingGround.SpawnEntity(0);
		break;
	case endlessBattle:
		int rng = GameCmn.RandomInt(1, 3);

		EndlessBattleground.SpawnEntity(classPlayer); //spawn player at 0 index (1st turn every time)
		EndlessBattleground.SpawnEntity(GameCmn.RandomInt(1, 2)); //random spawning
		if (rng == 2) {
			EndlessBattleground.SpawnEntity(GameCmn.RandomInt(1, 2));
		}
		else if (rng == 3) {
			EndlessBattleground.SpawnEntity(GameCmn.RandomInt(1, 2));
		}
		std::cout << "Battleground at a glance:" << std::endl;
		EndlessBattleground.ListAllEntity();


		//debugging
#ifdef _DEBUG
		Sleep(SLEEP_SHORT);
		Action obj;
		obj.ChooseAction(0, 1, 0);
		std::cout << std::endl;
		//EndlessBattleground.GetEnergy(0);
		//EndlessBattleground.ReduceEnergy(9, 0);
		//EndlessBattleground.IsDead(0);
		EndlessBattleground.ListAllEntity();
#endif
		break;
	}
}
