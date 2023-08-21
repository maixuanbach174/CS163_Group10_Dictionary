#ifndef EMOJi_HPP
#define EMOJi_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <io.h>
#include <codecvt>
#include <fcntl.h>
#include <vector>
#include "VieTrie.h"
using namespace std;

void readEmoji(vector<wstring>& emo, vector<vector<wstring>>& def);

#endif