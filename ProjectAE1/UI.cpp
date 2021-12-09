#include "Game.h"
#include "UI.h"

Common UICmn;

using namespace std;

void UI::DisplayMenu(int menuID) {
    UICmn.ClearConsole();
    switch (menuID) {
    case menuMain:
        cout << "1) Start" << endl;
        cout << "2) Credits" << endl;
        break;
    case menuMode:
        cout << "1) Battle" << endl;
        cout << "2) Training" << endl;
        cout << "3) Back" << endl;
        break;
    case menuGameOver:
        cout << "You have died." << endl;
        cout << "1) Try Again" << endl;
        cout << "2) Main Menu" << endl;
        break;
    case menuVictory:
        cout << "Finally, you grasp victory!";
        cout << "1) Next Room" << endl;
        cout << "2) Main Menu" << endl;
        break;
    case menuCredits:
        cout << "Made by Jack" << endl;
        cout << "1) Back" << endl;
        break;
    }
}

void UI::DisplayCutscene(int cutsceneID) {
    UICmn.ClearConsole();
    switch (cutsceneID) {
    case cutsceneTrainingMode:
        cout << "You enter a well lit hall full of training equipment." << endl;
        cout << "You approach a dummy..." << endl << endl;
        break;
    case cutsceneEndlessMode:
        cout << "You hear loud, approaching sounds from afar." << endl;
        cout << "You brace yourself..." << endl << endl;
        break;
    case cutsceneEnemyIntro:
        cout << "You see a dark figure approaching..." << endl;
        break;
    case cutsceneEnemyDeath:
        cout << "After a couple of seconds, you hear a loud thump on the ground..." << endl;
        break;
    }
    Sleep(SLEEP_LONG);
}

int UI::GetChoice(int menuID) {
    DisplayMenu(menuID);
    int choice = -1;
    while (!(cin >> choice)) {
        cin.clear(); 
        cin.ignore(10000, '\n'); //cleans input
        cout << "Invaild Selection! Please choose again...";
        Sleep(SLEEP_SHORT);
        DisplayMenu(menuID);
    } 
    return choice;
}

//Unique Menus
void MainMenu() {
    for (int choice = -1; choice != 0;) {
        UI MainMenu;
        choice = MainMenu.GetChoice(menuID::menuMain);
        switch (choice) {
        case 1:
            GameModeMenu();
            break;
        case 2:
            CreditsMenu();
            break;
        case 0:
            break;
        }
        choice = 0;
    }
};

void GameModeMenu() {
    for (int choice = -1; choice != 0;) {
        UI GameModeMenu;
        choice = GameModeMenu.GetChoice(menuID::menuMode);
        switch (choice) {
        case 1:
            UICmn.ClearConsole();
            StartGame(endlessBattle);
            break;
        case 2:
            UICmn.ClearConsole();
            StartGame(trainingBattle);
            break;
        case 3:
            MainMenu();
            break;
        case 0:
            break;
        }
        choice = 0;
    }
};

void GameOverMenu() {
    for (int choice = -1; choice != 0;) {
        UI GameOverMenu;
        choice = GameOverMenu.GetChoice(menuID::menuGameOver);
        switch (choice) {
        case 1:
            StartGame(endlessBattle);
            break;
        case 2:
            MainMenu();
            break;
        case 0:
            break;
        }
        choice = 0;
    }
};

void VictoryMenu() {
    for (int choice = -1; choice != 0;) {
        UI VictoryMenu;
        choice = VictoryMenu.GetChoice(menuID::menuVictory);
        switch (choice) {
        case 1:
            StartGame(endlessBattle);
            break;
        case 2:
            MainMenu();
            break;
        case 0:
            break;
        }
        choice = 0;
    }
};

void CreditsMenu() {
    for (int choice = -1; choice != 0;) {
        UI CreditsMenu;
        choice = CreditsMenu.GetChoice(menuID::menuCredits);
        switch (choice) {
        case 1:
            MainMenu();
            break;
        case 0:
            break;
        }
        choice = 0;
    }
};