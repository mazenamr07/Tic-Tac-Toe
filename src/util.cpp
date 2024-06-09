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