#include <iostream>
#include <algorithm>
#include <vector>

// For erasing the console
#include <iostream>
#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif

using namespace std;

#ifndef TIC_TAC_TOE_FUNCTIONS_H
#define TIC_TAC_TOE_FUNCTIONS_H

bool choiceCheck(const string& choice, const vector<string>& arr);
void displayArr(vector<string> arr, string playerCharacter);
string strUpp(string str);
bool checkWin(const vector<string>& ticArr, const string& character);
void runGame(string playerMode, string playerCharacter);
void clearConsole();

#endif //TIC_TAC_TOE_FUNCTIONS_H
