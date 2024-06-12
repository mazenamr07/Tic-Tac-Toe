// Things to be done:
// 3. AI Opponent

#include "../include/util.h"

int main() {
    string playerMode, exitChoice, playerCharacter = "X";
    vector<string> playerChoices = {"1", "2"};
    vector<string> Characters = {"X", "O"};

    while (true) {
        cout << "Tic Tac Toe 1.0\n"
                "To play choose a mode:\n"
                "1- Against a Player\n"
                "2- Against Computer\n"
                "->";

        getline(cin, playerMode);
        while (!choiceCheck(playerMode, playerChoices)) {
            cout << "Please choose a correct mode:\n"
                    "->";
            getline(cin, playerMode);
        }

        // if player chooses a computer he should get levels in the future

        if (playerMode == "2") { // Computer
            cout << endl << "Please enter X or O:\n"
                            "->";

            getline(cin, playerCharacter);
            playerCharacter = strUpp(playerCharacter);
            while (!choiceCheck(playerCharacter, Characters)) {
                cout << "Please choose either X or O:\n"
                        "->";
                getline(cin, playerCharacter);
                playerCharacter = strUpp(playerCharacter);
            }
        }

        runGame(playerMode, playerCharacter);

        cout << endl << "Wanna play again?\n"
                        "1) Yes, Play again\n"
                        "2) No, Quit game\n"
                        "->";

        getline(cin, exitChoice);
        while (!choiceCheck(exitChoice, playerChoices)) {
            cout << "Please choose a correct choice:\n"
                    "->";
            getline(cin, exitChoice);
        }

        if (exitChoice == "1") {
            clearConsole();
        }
        else {
            cout << endl << "Bye-bye!";
            return 0;
        }
    }
}
