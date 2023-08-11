#ifndef READVIEENG_HPP
#define READVIEENG_HPP

#include <SFML/Graphics.hpp>
#include <string>
#include "VieTrie.h"
#include <io.h>
#include <codecvt>
#include <fcntl.h>
#include <fstream>
using namespace std;

void VieEng(vector<wstring>& words, vector<vector<wstring>>& defs, vector<vector<wstring>>& examples);
void FormatVieEng(wstring def, vector<wstring>& definitions, vector<wstring>& examples);

#endif