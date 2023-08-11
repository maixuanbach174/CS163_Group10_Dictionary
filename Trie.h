#ifndef TRIE_H
#define TRIE_H

#include <string>
#include <vector>
using namespace std;

const int ALPHABET_SIZE = 26;

struct TrieNode
{
    TrieNode *children[ALPHABET_SIZE];
    bool isEndOfWord;
    vector<wstring> definition;
    int value;
    TrieNode();
};

// bool insert(TrieNode*& root, wstring word, vector<wstring> def);
bool insert(TrieNode*& root, wstring word, int index);

TrieNode* find(TrieNode*& root, wstring word);

bool isEmpty(TrieNode* root);

TrieNode* remove(TrieNode* root, wstring key, int depth);

TrieNode* erase(TrieNode* root, wstring word);

#endif