#pragma once

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
	void DisplayCutscene(int cutsceneID);
	int GetChoice(int menuID);
};

//Unique Menus
void MainMenu();
void GameModeMenu();
void GameOverMenu();
void VictoryMenu();
void CreditsMenu();