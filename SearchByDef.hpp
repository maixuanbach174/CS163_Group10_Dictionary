#ifndef SEARCHBYDEF_HPP
#define SEARCHBYDEF_HPP

#include <string>
#include <vector>
#include "Trie.h"
#include "VieTrie.h"
#include <algorithm>
using namespace std;

vector<wstring> splitToWords(wstring def);
void insertdef(TrieNode *& root, wstring def, int index);
void Vieinsertdef(VieTrieNode *& root, wstring def, int index);
vector<int> finddef(TrieNode*& root, wstring def);
vector<int> Viefinddef(VieTrieNode*& root, wstring def);

#endif