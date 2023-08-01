#ifndef TRIE_H
#define TRIE_H

#include <string>
#include "Tree.hpp"
using namespace std;

const int ALPHABET_SIZE = 26;

struct TrieNode
{
    TrieNode *children[ALPHABET_SIZE];
    bool isEndOfWord;
    wstring definition;
    TrieNode();
};

class Trie : Tree
{
public:
    Trie(/* args */);
    ~Trie();
};


bool insert(TrieNode*& root, wstring word, wstring def);

TrieNode* find(TrieNode*& root, wstring word);

bool isEmpty(TrieNode* root);

TrieNode* removefunction(TrieNode* root, string word, int depth);

TrieNode* remove(TrieNode* root, string word);

void deallocate(TrieNode*& root);

#endif