#include "Game.h"
#include "Entity.h"
#include "UI.h"
#include "AI.h"

EntityHandler TrainingGround;
EntityHandler EndlessBattleground;
Common GameCmn;
UI BattleUI;

//common functions
void Common::ClearConsole() { //clears via console API, without using 'system'
	COORD topLeft = { 0, 0 };
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO screen;
	DWORD written;

	GetConsoleScreenBufferInfo(console, &screen);
	FillConsoleOutputCharacterA(
		console, ' ', screen.dwSize.X * screen.dwSize.Y, topLeft, &written
	);
	FillConsoleOutputAttribute(
		console, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE,
		screen.dwSize.X * screen.dwSize.Y, topLeft, &written
	);
	SetConsoleCursorPosition(console, topLeft);
}

int Common::RandomInt(int min, int max) { //random numbers without using system time.
	std::random_device rd;
	std::mt19937 rng(rd());
	std::uniform_int_distribution<int> uni(min, max);
	auto random_integer = uni(rng);
	return random_integer;
}

//gameflow
void StartGame(int gameMode) {
	BattleUI.DisplayCutscene(gameMode);
	switch (gameMode) {
	case trainingBattle:

		TrainingGround.SpawnEntity(classPlayer); //spawn player at 0 index (1st turn every time)
		TrainingGround.SpawnEntity(0);
		std::cout << TrainingGround.Turn(gameMode);
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
		std::cout << EndlessBattleground.Turn(gameMode);

#ifdef _DEBUG
		//debugging; testing random stuff
		Sleep(SLEEP_SHORT);
		std::cout << std::endl;
		//std::cout << EndlessBattleground.Turn();
		//Action d;
		//d.ChooseAction(GameCmn.RandomInt(1, 3), EndlessBattleground.Turn(), 0);
		//EndlessBattleground.GetEnergy(0);
		//EndlessBattleground.ReduceEnergy(9, 0);
		//EndlessBattleground.IsDead(0);
		EndlessBattleground.ListAllEntity();
#endif
		break;
	}
}

void SeeBattlefield(int gameMode) {
	switch (gameMode) {
	case trainingBattle:
		TrainingGround.ListAllEntity();
		break;
	case endlessBattle:
		EndlessBattleground.ListAllEntity();
		break;
	}
	
}