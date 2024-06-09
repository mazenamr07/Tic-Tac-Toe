#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define strLow(string) for (char &ch : string) { ch = tolower(ch); }

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
            cout << "===========\n";
        }
    }
}

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
    strLow(character)

    while (character != "x" and character != "o") {
        cout << "Wrong Character! Please enter X or O:\n"
                "->";
        getline(cin, character);
        strLow(character)
    }

    cout << "Okay now choose a number from 1 to 9:\n"
            "->";
    vector<string> ticArr = {"1", "2", "3", "4", "5", "6", "7", "8", "9"};
    string choice;
    getline(cin, choice);

    while (!choiceCheck(choice, ticArr)) {
        cout << "Wrong Number! Please enter a number from 1 to 9:\n"
                "->";
        getline(cin, choice);
    }
//    std::replace(ticArr.begin(), ticArr.end(), "1", "5");
    displayArr(ticArr);

    return 0;
}
