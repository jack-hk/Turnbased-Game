#pragma once

#include <windows.h>

static const int SLEEP_SHORT = 1000;
static const int SLEEP_LONG = 1500;

enum menuID { //UI that requires player interaction (input choices).
	menuMain,
	menuMode,
	menuGameOver,
	menuVictory,
	menuCredits
};

enum cutsceneID {  //UI that is time based.
	cutsceneTrainingMode,
	cutsceneEndlessMode,
	cutsceneEnemyIntro,
	cutsceneEnemyDeath
};

class UI {
private:
	void DisplayMenu(int menuID);
public:
	void ClearConsole();
	void DisplayCutscene(int cutsceneID);
	int GetChoice(int menuID);
};

//Unique Menus
void MainMenu();
void GameModeMenu();
void GameOverMenu();
void VictoryMenu();
void CreditsMenu();