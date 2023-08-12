#ifndef SERIALIZATION_H_INCLUDED
#define SERIALIZATION_H_INCLUDED
#include <fstream>
#include <vector>
using namespace std;
void serialize(std::wofstream& file,vector <wstring> &allWords,vector <vector <wstring>> &allDefinitions,vector <vector<wstring>> &allExamples);
 void saveTrie(const std::string& filename,vector <wstring> &allWords,vector <vector <wstring>> &allDefinitions,vector <vector<wstring>> &allExamples);
 void loadTrie(const std::string& filename,vector<wstring> &allWords,vector <vector <wstring>> &allDefinitions,vector <vector<wstring>> &allExamples);

#endif // SERIALIZATION_H_INCLUDED
