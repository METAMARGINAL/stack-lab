#pragma once
#include "stack.h"
#include <iostream>
#include <stdexcept>
#include <algorithm>

using namespace std;



int main() {
    string text = "";
    cout << "enter the text" << endl;
    cin >> text;
    find_bracket_pairs(text);
    return 0;
}
