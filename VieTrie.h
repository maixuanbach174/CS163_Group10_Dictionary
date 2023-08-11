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
    int value;
    VieTrieNode();
};

// bool VieInsert(VieTrieNode *& root, wstring vieword, vector<wstring> def);
bool VieInsert(VieTrieNode *& root, wstring vieword, int index);
VieTrieNode * VieFind(VieTrieNode *& root, wstring vieword);
VieTrieNode* VieRemove(VieTrieNode* root, string key, int depth);
void VieDeallocate(VieTrieNode * root);
bool isEmpty(VieTrieNode* root);
VieTrieNode* VieErase(VieTrieNode* root, wstring vieword);

#endif