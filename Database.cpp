#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

int sortfile(char* fileName) {
    ifstream ifs(fileName);
    vector<string> fileVector;
    string current;

    if (!ifs.is_open()){
        return -1;
    }

    ifs >> current;
    fileVector.push_back(current);

    while (!ifs.eof()) {
        int i;
        ifs >> current;

        for (i = fileVector.size() - 1; i >= 0; --i) {
            if (current >= fileVector[i]) {
                fileVector.insert (fileVector.begin()+i+1, current);
                break;
            }
            else if (i == 1) {
                fileVector.insert (fileVector.begin(), current);
            }
        }
    }
    
    for (int i = 0; i < fileVector.size(); ++i) {
        cout << fileVector[i] << " ";
    }

    return 0;
}

int main() {
    char fileName[20];
    char sort;

    cout << "Enter File Name: ";
    cin >> fileName;
    cout << "Sort? (y/n) ";
    cin  >> sort;
    if(sort == 'y') {
        if (sortfile(fileName) < 0) {
            cout << "Failed to load file";
            return 0;
        }
    }

    return 0;
}
