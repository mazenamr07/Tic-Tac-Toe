#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool choiceCheck(const string& choice, const vector<string>& arr) {
    return any_of(arr.begin(), arr.end(), [choice] (const string& i) {return i == choice;});
}

int main() {
    cout << "Tic Tac Toe 1.0\n"
            "To play enter a number from 1 to 9\n";
    cout << " 1 | 2 | 3 \n"
            " 4 | 5 | 6 \n"
            " 7 | 8 | 9 \n"
            "->";
    vector<string> ticArr = {"1", "2", "3", "4", "5", "6", "7", "8", "9"};
    string choice;
    getline(cin, choice);

    while (!choiceCheck(choice, ticArr)) {
        cout << "Wrong Number! Please enter a number from 1 to 9:\n"
                "->";
        getline(cin, choice);
    }

    return 0;
}
