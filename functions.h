#include <string>
#include <vector>
using namespace std;

#ifndef FUNCTIONS_H
#define FUNCTIONS_H

int sortfile(const string fileName);
int writefile(const vector<string> &fileVector, string fileName,
const unsigned int fileVectorSize, string fileop);
bool sortCheck();

#endif
