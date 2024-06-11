// Things to be done:
// 1. Replaying method needs some love
// 3. AI Opponent

#include "../include/util.h"

int main() {
    while (true) {
        cout << "Tic Tac Toe 1.0\n"
                "To play choose a character X or O\n"
                "===========\n";
        cout << " 1 | 2 | 3 \n"
                " 4 | 5 | 6 \n"
                " 7 | 8 | 9 \n"
                "===========\n"
                "->";
        string character;
        getline(cin, character);
        character = strUpp(character);

        vector<string> charArr = {"X", "O"};
        while (!choiceCheck(character, charArr)) {
            cout << "Wrong Character! Please enter X or O:\n"
                    "->";
            getline(cin, character);
            character = strUpp(character);
        }

        cout << "Okay now choose a number from 1 to 9:\n"
                "->";
        vector<string> ticArr = {"1", "2", "3", "4", "5", "6", "7", "8", "9"};
        int counter = 0;

        while (true) {
            string choice;
            getline(cin, choice);

            while (!choiceCheck(choice, ticArr)) {
                cout << "Wrong Number! Please enter a number from 1 to 9:\n"
                        "->";
                getline(cin, choice);
            }

            replace(ticArr.begin(), ticArr.end(), choice, character);
            displayArr(ticArr);
            counter++;

            // breaking area
            if (checkWin(ticArr, character)) {
                cout << character << " Won!\n";
                break;
            }
            if (counter == 9) {
                cout << "It's a Draw!\n";
                break;
            }

            character = (character == "X") ? "O" : "X";
        }

        cout << "\nWanna play again?\n"
                "Enter 1 to play again,\n"
                "anything else to exit\n"
                "->";

        string endChoice;
        getline(cin, endChoice);

        if (endChoice != "1") {
            break;
        }
    }
    return 0;
}
