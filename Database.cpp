#include "functions.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

int main() {
    string fileName;

    cout << "Enter File Name: ";
    getline(cin, fileName);

    if(sortCheck()) {
        if (sortfile(fileName) < 0) {
            cout << "Failed to load file";
            return 0;
        }
    }

    return 0;
}
