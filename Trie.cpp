#include "Trie.h"

TrieNode::TrieNode()
{
    for(int i = 0; i < ALPHABET_SIZE; ++i) children[i] = nullptr;
    isEndOfWord = false;
    definition = "";
}

TrieNode* find(TrieNode* root, string& word)
{
    if(root == nullptr) return nullptr;
    
    TrieNode *cur = root;

    for(int i = 0; word[i] != '\0'; ++i)
    {
        int index = word[i] - 'a';
        if(cur->children[index] == nullptr) return nullptr;

        cur = cur->children[index];
    }

    if(cur->isEndOfWord) return cur;
    return nullptr;
}