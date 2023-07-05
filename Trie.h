#ifndef TRIE_H
#define TRIE_H

#include <string>
using namespace std;

const int ALPHABET_SIZE = 26;

struct TrieNode
{
    TrieNode *children[ALPHABET_SIZE];
    bool isEndOfWord;
    string definition;
    TrieNode();
};

bool insert(TrieNode*& root, string word, string def); // return false if the word is already in Trie.


TrieNode* find(TrieNode* root, string& word); // return the found node.
bool isEmpty(TrieNode* root);
TrieNode* removefunction(TrieNode* root, string word, int depth); // remove a word. Remove the unneccessary path to that node if you can.
TrieNode* remove(TrieNode* root, string& word);
void deallocate(TrieNode* root);

#endif

