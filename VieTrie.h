#ifndef VIETRIE_H
#define VIETRIE_H

#include <string>
#include "Encode.h"
#include <iostream>
#include <vector>
using namespace std;

struct VieTrieNode
{
    VieTrieNode *children[16];
    bool isEndOfWord;
    vector<wstring> definition;
    VieTrieNode();
};

bool VieInsert(VieTrieNode *& root, wstring vieword, vector<wstring> def);
VieTrieNode * VieFind(VieTrieNode *& root, wstring vieword);
void VieDeallocate(VieTrieNode * root);

#endif