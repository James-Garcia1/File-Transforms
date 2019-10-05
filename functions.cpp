#include "functions.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

int sortfile(const string fileName) {
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
            else if (i == 0) {
                fileVector.insert (fileVector.begin(), current);
            }
        }
    }
    
    writefile(fileVector, fileName, fileVector.size(), "Sort");

    return 0;
}

int writefile(const vector<string> &fileVector, string fileName, const unsigned int fileVectorSize, string fileop) {
    ofstream ofs(fileName.insert(0, fileop));

    for (int i = 0; i < fileVectorSize; ++i) {
        if (i < fileVectorSize - 1)
            ofs << fileVector[i] << '\n';
        else
            ofs << fileVector[i];
    }

    return 0;
}

bool sortCheck() {
    bool sort;
    char userinput = 'o';
    while (userinput != 'y' && userinput != 'n') {
        cout << "Sort? (y/n) ";
        cin >> userinput;
    }

    if (userinput == 'y')
        return true;
    else
        return false;    
}
