#ifndef READDATASETENGVIE_HPP
#define READDATASETENGVIE_HPP

#include <stdio.h>
#include <string>
#include <fstream>
#include <locale>
#include <Windows.h>
#include <codecvt>
#include <queue>
#include <bits/stdc++.h>
#include "Trie.h"
using namespace std;

void readDatasetEngVie(vector<wstring>& words, vector<vector<wstring>>& defs, vector<vector<wstring>>& examples);
vector <wstring> splitDefinition(wstring definition);
vector <wstring> splitExample(wstring definition);

#endif