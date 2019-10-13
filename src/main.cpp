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

    if(methodCheck("Remove Duplicates")) {
        cout << "Enter File Name: ";
        cin.ignore();
        getline(cin, fileName);
        cout << "Enter # of memebers: ";
        cin >> members;
        if (removeDupes(fileName, members) < 0) {
            cout << "Failed to load file";
            return 0;
        }
    }

    if(methodCheck("Sort")) {
        cout << "Enter File Name: ";
        cin.ignore();
        getline(cin, fileName);
        cout << "Enter # of memebers: ";
        cin >> members;
        if (sortfile(fileName, members) < 0) {
            cout << "Failed to load file";
            return 0;
        }
    }

    return 0;
}
