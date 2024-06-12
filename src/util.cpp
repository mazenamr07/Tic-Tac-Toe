#include "../include/util.h"

bool choiceCheck(const string& choice, const vector<string>& arr) {
    return any_of(arr.begin(), arr.end(), [choice] (const string& i) {return i == choice;});
}

void displayArr(vector<string> arr, string playerCharacter) {
    playerCharacter = (playerCharacter == "X") ? "O" : "X";

    cout << "=================\n";
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cout << "  " << arr[3 * i + j] << "  ";
            if (j != 2) {
                cout << "|";
            }
        }
        if (i == 2) {
            cout << "\n=================\n";
            printf("%s's turn ->", playerCharacter.c_str());
        }
        else {
            cout << "\n-----|-----|-----\n";
        }
    }
}

string strUpp(string str) {
    for (char &ch : str) {
        ch = toupper(ch);
    }
    return str;
}

bool checkWin(const vector<string>& ticArr, const string& character) {
    const vector<vector<int>> winPositions = {
            {0, 1, 2}, {3, 4, 5}, {6, 7, 8}, // Rows
            {0, 3, 6}, {1, 4, 7}, {2, 5, 8}, // Columns
            {0, 4, 8}, {2, 4, 6}             // Diagonals
    };

    for (const auto& pos : winPositions) {
        if (ticArr[pos[0]] == character && ticArr[pos[1]] == character && ticArr[pos[2]] == character) {
            return true;
        }
    }
    return false;
}

void runGame(string playerMode, string playerCharacter) {
    if (playerMode == "1") { // Another Player
        cout << endl << "Okay now to play choose a number from 1 - 9";
        cout << endl << "=================\n"
                        "  1  |  2  |  3  \n"
                        "-----|-----|-----\n"
                        "  4  |  5  |  6  \n"
                        "-----|-----|-----\n"
                        "  7  |  8  |  9  \n"
                        "=================\n";
        printf("%s's turn ->", playerCharacter.c_str());

        vector<string> ticArr = {"1", "2", "3", "4", "5", "6", "7", "8", "9"};
        vector<string> usedArr = {"1", "2", "3", "4", "5", "6", "7", "8", "9"};
        int counter = 0;

        while (true) {
            string slotPlace;
            getline(cin, slotPlace);

            while (!choiceCheck(slotPlace, usedArr) or slotPlace.empty()) {
                printf("%s must enter a number from 1 - 9\n"
                       "->", playerCharacter.c_str());
                getline(cin, slotPlace);
            }
            cout << endl;

            replace(ticArr.begin(), ticArr.end(), slotPlace, playerCharacter);
            auto itr = remove(usedArr.begin(), usedArr.end(), slotPlace);
            displayArr(ticArr, playerCharacter);
            counter++;

            // breaking area
            if (checkWin(ticArr, playerCharacter)) {
                printf("\r%s Won!     \n", playerCharacter.c_str());
                break;
            }
            if (counter == 9) {
                cout << "\rIt's a Draw!     \n";
                break;
            }
            playerCharacter = (playerCharacter == "X") ? "O" : "X";
        }
    }
    else { // Computer

    }
}

void clearConsole() {
    #ifdef _WIN32
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        COORD coordScreen = {0, 0};
        DWORD cCharsWritten;
        CONSOLE_SCREEN_BUFFER_INFO csbi;
        DWORD dwConSize;

        if (!GetConsoleScreenBufferInfo(hConsole, &csbi)) {
            return;
        }
        dwConSize = csbi.dwSize.X * csbi.dwSize.Y;

        if (!FillConsoleOutputCharacter(hConsole, (TCHAR) ' ', dwConSize, coordScreen, &cCharsWritten)) {
            return;
        }

        if (!FillConsoleOutputAttribute(hConsole, csbi.wAttributes, dwConSize, coordScreen, &cCharsWritten)) {
            return;
        }

        SetConsoleCursorPosition(hConsole, coordScreen);
    #else
        std::cout << "\033[2J\033[1;1H";
    #endif
}