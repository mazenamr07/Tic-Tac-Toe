#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#ifndef TIC_TAC_TOE_FUNCTIONS_H
#define TIC_TAC_TOE_FUNCTIONS_H

//#define strUpp(string) for (char &ch : string) { ch = toupper(ch); }

bool choiceCheck(const string& choice, const vector<string>& arr);
void displayArr(vector<string> arr);
string strUpp(string str);

#endif //TIC_TAC_TOE_FUNCTIONS_H
