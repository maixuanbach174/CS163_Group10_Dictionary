#ifndef EMOJIS_HPP
#define EMOJIS_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <io.h>
#include <codecvt>
#include <fcntl.h>
#include <vector>
using namespace std;

void readEmoji(vector<wstring>& emos, vector<wstring>& defs);

#endif