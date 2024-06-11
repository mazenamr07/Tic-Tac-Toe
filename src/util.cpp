#include "../include/util.h"

bool choiceCheck(const string& choice, const vector<string>& arr) {
    return any_of(arr.begin(), arr.end(), [choice] (const string& i) {return i == choice;});
}

void displayArr(vector<string> arr) {
    cout << "===========\n";
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cout << ' ' << arr[3 * i + j];
            if (j != 2) {
                cout << " |";
            }
        }
        cout << endl;
        if (i == 2) {
            cout << "===========\n"
                    "->";
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