#include <string>
#include <vector>
#include <map>
using namespace std;#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

#ifndef FUNCTIONS_H
#define FUNCTIONS_H

int sortfile(const string fileName, const int numMems);
int writefile(const vector<string> &fileVector, string fileName, 
const unsigned int fileVectorSize, unordered_map<string, vector<string>> mem_map, 
unsigned int numMems, string fileop);
bool methodCheck(string op);
void memberLink(ifstream &ifs, const string current,
 unordered_map<string, vector<string>> &mem_map, int numMems);
void writefileDict(string fileName, unordered_map<string, vector<string >> &out_map,
 const unsigned int numMems, string fileop);
int removeDupes(const string fileName, const int numMems);

#endif

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
