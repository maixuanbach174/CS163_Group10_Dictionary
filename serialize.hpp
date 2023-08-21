#ifndef SERIALIZE_HPP
#define SERIALIZE_HPP

#include <iostream>
#include <stdio.h>
#include <fcntl.h>
#include <io.h>
#include <string>
#include <fstream>
#include <locale>
#include <Windows.h>
#include <codecvt>
#include <vector>
using namespace std;

void serialize(std::wofstream& file,vector <wstring> &allWords,vector <vector <wstring>> &allDefinitions,vector <vector<wstring>> &allExamples);
void saveTrie(const std::string& filename,vector <wstring> &allWords,vector <vector <wstring>> &allDefinitions,vector <vector<wstring>> &allExamples);
void loadTrie(const std::string& filename,vector<wstring> &allWords,vector <vector <wstring>> &allDefinitions,vector <vector<wstring>> &allExamples);


#endif // SERIALIZE_HPP