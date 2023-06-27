#include <iostream>
#include "Trie.h"
using namespace std;

const int ALPHABET_SIZE = 26;


TrieNode::TrieNode()
{
    for(int i = 0; i < ALPHABET_SIZE; ++i) children[i] = nullptr;
    isEndOfWord = false;
    definition = "";
}
void deallocateTrie(TrieNode* node)
{
    if (node == nullptr)
        return;

    for (int i = 0; i < ALPHABET_SIZE; ++i)
    {
        if (node->children[i] != nullptr)
        {
            deallocateTrie(node->children[i]);
            node->children[i] = nullptr;
        }
    }
    delete node;
}

bool insert(TrieNode* root, string& word)
{
    TrieNode* pCrawl = root;
    for (int i = 0; i < word.length(); i++)
    {
        int index = word[i] - 'a';
        if (!pCrawl->children[index])
            pCrawl->children[index] = new TrieNode();

        pCrawl = pCrawl->children[index];
    }
    pCrawl->isEndOfWord = true;
    return pCrawl->isEndOfWord;
}

