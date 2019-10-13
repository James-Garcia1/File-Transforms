#include "functions.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <unordered_map>
using namespace std;

void memberLink(ifstream &ifs, const string current, unordered_map<string, vector<string>>& mem_map, int numMems) {
    vector<string> memberData(numMems);
    string curMem;

    for (int i = 0; i < numMems; ++i) {
        ifs >> curMem;
        memberData[i] = curMem;
    } 

    mem_map.insert(pair<string, vector<string>>(current,memberData));
}

int removeDupes(const string fileName, const int numMems) {
    ifstream ifs(fileName);
    unordered_map<string, vector<string >> dupes_map;
    string current;

    if (!ifs.is_open()){
        return -1;
    }

    while (!ifs.eof()) {
        ifs >> current;
        memberLink(ifs, current, dupes_map, numMems);
    }

    writefileDict(fileName, dupes_map, numMems, "NoDup_");

    return 0;
}

void writefileDict(string fileName, unordered_map<string, vector<string >> &out_map, const unsigned int numMems, string fileop) {
    ofstream ofs(fileName.insert(0, fileop));
    for( auto const& [key,val] : out_map )
    {
        ofs << key;
        for (unsigned int i = 0; i < numMems; ++i) {
            ofs << " " << val[i];
        }
        ofs << endl;
    }
}

int sortfile(const string fileName, const int numMems) {
    ifstream ifs(fileName);
    vector<string> fileVector;
    string current;
    unordered_map<string, vector<string >> memeber_map;

    if (!ifs.is_open()){
        return -1;
    }

    ifs >> current;
    memberLink(ifs, current, memeber_map, numMems);
    fileVector.push_back(current);

    while (!ifs.eof()) {
        ifs >> current;

        memberLink(ifs, current, memeber_map, numMems);

        for (int i = fileVector.size() - 1; i >= 0; --i) {
            if (current >= fileVector[i]) {
                fileVector.insert (fileVector.begin()+i+1, current);
                break;
            }
            else if (i == 0) {
                fileVector.insert (fileVector.begin(), current);
            }
        }
    }

    writefile(fileVector, fileName, fileVector.size(), memeber_map, numMems, "Sort_");

    return 0;
}

int writefile(const vector<string> &fileVector, string fileName, const unsigned int fileVectorSize, unordered_map<string, vector<string>> mem_map, unsigned int numMems, string fileop) {
    ofstream ofs(fileName.insert(0, fileop));

    for (unsigned int i = 0; i < fileVectorSize; ++i) {
        ofs << fileVector[i];
        for (unsigned int j = 0; j < numMems; ++j) {
            ofs << " " << mem_map.at(fileVector[i])[j];
        }
        if (i < fileVectorSize - 1) {
            ofs << '\n';
        }
    }

    return 0;
}

bool methodCheck(string op) {
    char userinput = 'o';
    while (userinput != 'y' && userinput != 'n') {
        cout << op << "? (y/n) ";
        cin >> userinput;
    }

    if (userinput == 'y')
        return true;
    else
        return false;    
}
