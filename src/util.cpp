#include "../include/util.h"

bool choiceCheck(const string& choice, const vector<string>& arr) {
    return any_of(arr.begin(), arr.end(), [choice] (const string& i) {return i == choice;});
}

void displayArr(vector<string> arr, string playerCharacter) {
    playerCharacter = (playerCharacter == "X") ? "O" : "X";

    cout << "=================\n";
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (!isdigit(arr[3 * i + j][0])) {
                cout << "  " << arr[3 * i + j] << "  ";
            } else {
                cout << "     ";
            }
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
        if (ticArr[pos[0]] == character and ticArr[pos[1]] == character and ticArr[pos[2]] == character) {
            return true;
        }
    }
    return false;
}

void runGame(const string& playerMode, string playerCharacter) {
    cout << endl << "Okay now to play choose a number from 1 - 9";
    cout << endl << "=================\n"
                    "  1  |  2  |  3  \n"
                    "-----|-----|-----\n"
                    "  4  |  5  |  6  \n"
                    "-----|-----|-----\n"
                    "  7  |  8  |  9  \n"
                    "=================\n"
                    "X's turn ->";

    vector<string> ticArr = {"1", "2", "3", "4", "5", "6", "7", "8", "9"};
    vector<string> usedArr = {"1", "2", "3", "4", "5", "6", "7", "8", "9"};
    int counter = 0;
    bool cpuOrHuman = 0;

    while (true) {
        string slotPlace;
        bool cpuPlayed = 0;

        if (playerMode == "1") {
            getline(cin, slotPlace);

            while (!choiceCheck(slotPlace, usedArr) or slotPlace.empty()) {
                printf("%s must enter a number from 1 - 9\n"
                       "->", playerCharacter.c_str());
                getline(cin, slotPlace);
            }
            cout << endl;
        }
        else if (playerMode == "2") {

            if ((playerCharacter == "X" and cpuOrHuman == 0) or (playerCharacter == "O" and cpuOrHuman == 1)) {
                getline(cin, slotPlace);

                while (!choiceCheck(slotPlace, usedArr) or slotPlace.empty()) {
                    printf("%s must enter a number from 1 - 9\n"
                           "->", playerCharacter.c_str());
                    getline(cin, slotPlace);
                }
                cout << endl;
                cpuOrHuman ^= 1;
            }
            else {
                playerCharacter = (playerCharacter == "X") ? "O" : "X";
                slotPlace = computerMove(0, usedArr);
                cpuPlayed = 1;
                cpuOrHuman ^= 1;
            }
        }

        replace(ticArr.begin(), ticArr.end(), slotPlace, playerCharacter);
        auto itr = remove(usedArr.begin(), usedArr.end(), slotPlace);
        if (playerMode == "1") {
            displayArr(ticArr, playerCharacter);
        }
        else if (cpuPlayed) {
            if (counter == 0) {
                printf("%s\n\n", slotPlace.c_str());
            } else {
                printf("-> I choose %s:\n", slotPlace.c_str());
            }
            displayArr(ticArr, playerCharacter);
        }
        counter++;

        // breaking area
        if (checkWin(ticArr, playerCharacter)) {
            if (playerMode == "2" and !cpuPlayed) {
                displayArr(ticArr, playerCharacter);
            }
            printf("\r%s Won!     \n", playerCharacter.c_str());
            break;
        }
        if (counter == 9) {
            cout << "\rIt's a Draw!     \n";
            break;
        }
        if (playerMode == "1" or cpuPlayed) {
            playerCharacter = (playerCharacter == "X") ? "O" : "X";
            cpuPlayed = 0;
        }
    }
}

string computerMove (int cpuLevel, vector<string> usedArr) {
    if (cpuLevel == 0) {
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<> dis(1,9);

        int slotPlace = dis(gen);
        while (!choiceCheck(to_string(slotPlace), usedArr)) {
            slotPlace = dis(gen);
        }
        return to_string(slotPlace);
    }
    return "lol";
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
