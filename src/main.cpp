#include "../include/util.h"

int main() {
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

        // breaking area
        if (ticArr[0] == ticArr[4]) {
            if (ticArr[0] == ticArr[8]) {
                cout << character << " Won!";
                exit(0);
            }
        }
        if (ticArr[2] == ticArr[4]) {
            if (ticArr[2] == ticArr[6]) {
                cout << character << " Won!";
                exit(0);
            }
        }
        for (int i = 0; i < 3; ++i) {
            if (ticArr[i] == ticArr[i + 3]) {
                if (ticArr[i + 3] == ticArr[i + 6]) {
                    cout << character << " Won!";
                    exit(0);
                }
            }
        }
        for (int i = 0; i < 3; i += 3) {
            if (ticArr[i] == ticArr[i + 1]) {
                if (ticArr[i] == ticArr[i + 2]) {
                    cout << character << " Won!";
                    exit(0);
                }
            }
        }

        if (character == "X") {
            character = "O";
        } else {
            character = "X";
        }
    }
}
