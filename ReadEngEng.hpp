#ifndef READENGENG_HPP
#define READENGENG_HPP

#include <iostream>
#include "Trie.h"
#include <fstream>
#include <vector>
#include <sstream>
#include <string>
#include <cctype>
using namespace std;

void readEngEng(vector<wstring>& words, vector<vector<wstring>>& defs, vector<vector<wstring>>& examples);
void splitEngEng(wstring definition, vector<wstring>& defs, vector<wstring>& examples);

#endif