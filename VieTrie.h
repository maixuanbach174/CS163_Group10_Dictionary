#ifndef VIETRIE_H
#define VIETRIE_H

#include <string>
#include "Encode.h"
#include <iostream>
using namespace std;

struct VieTrieNode
{
    VieTrieNode *children[16];
    bool isEndOfWord;
    string definition;
    VieTrieNode();
};

bool VieInsert(VieTrieNode *& root, wstring vieword, string def);
VieTrieNode * VieFind(VieTrieNode *& root, wstring vieword);
void VieDeallocate(VieTrieNode * root);

#endif