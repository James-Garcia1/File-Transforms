#include "functions.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

int main() {
    string fileName;
    int members;

    cout << "Enter File Name: ";
    getline(cin, fileName);

    cout << "Enter # of memebers: ";
    cin >> members;

    if(sortCheck()) {
        if (sortfile(fileName, members) < 0) {
            cout << "Failed to load file";
            return 0;
        }
    }

    return 0;
}
