// Things to be done:
// 1. Adjust out of possible inputs for arr msg
// 2. AI Opponent needs some love

#include "../include/util.h"

int mains () {
    int x;
    cin >> x;
    x ^= 1;
    cout << x;
}

int main() {
    int counter = 1;
    string playerMode, exitChoice, playerCharacter = "X";
    vector<string> playerChoices = {"1", "2"};
    vector<string> Characters = {"X", "O"};

    while (true) {
        printf("Tic Tac Toe: Game #%i\n", counter);
        cout << "To play choose a mode:\n"
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
            counter++;
            clearConsole();
        }
        else {
            cout << endl << "Bye-bye!";
            return 0;
        }
    }
}
