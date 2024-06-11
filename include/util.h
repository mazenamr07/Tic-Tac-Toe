#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#ifndef TIC_TAC_TOE_FUNCTIONS_H
#define TIC_TAC_TOE_FUNCTIONS_H

bool choiceCheck(const string& choice, const vector<string>& arr);
void displayArr(vector<string> arr);
string strUpp(string str);
bool checkWin(const vector<string>& ticArr, const string& character);

#endif //TIC_TAC_TOE_FUNCTIONS_H
