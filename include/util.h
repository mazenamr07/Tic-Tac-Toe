#include <iostream>
#include <algorithm>
#include <vector>
#include <random>

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

void clearConsole();
bool choiceCheck(const string& choice, const vector<string>& arr);
void displayArr(vector<string> arr, string playerCharacter);
string strUpp(string str);
bool checkWin(const vector<string>& ticArr, const string& character);
void runGame(const string& playerMode, string playerCharacter);
string computerMove (int cpuLevel, vector<string> usedArr);

#endif //TIC_TAC_TOE_FUNCTIONS_H
