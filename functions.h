#include <string>
#include <vector>
#include <map>
using namespace std;

#ifndef FUNCTIONS_H
#define FUNCTIONS_H

int sortfile(const string fileName, const int numMems);
int writefile(const vector<string> &fileVector, string fileName, 
const unsigned int fileVectorSize, map<string, vector<string>> mem_map, 
unsigned int numMems, string fileop);
bool sortCheck();
void memberLink(ifstream &ifs, const string current,
 map<string, vector<string>> &mem_map, int numMems);

#endif
