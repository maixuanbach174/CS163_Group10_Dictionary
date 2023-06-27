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
bool isEmpty(TrieNode* root)
{
    for (int i = 0; i < ALPHABET_SIZE; i++)
        if (root->children[i])
            return false;
    return true;
}
void erase(TrieNode* root, string& word, int depth = 0)
{
    
    if (root == nullptr)
        return;
    if (word.size() == depth)
    {
        if (root->isEndOfWord)
        {
            root->isEndOfWord = false;
        }
    }
    if (isEmpty(root))
    {
        delete(root);
        root = nullptr;
    }
    int index = key[depth] - 'a';
    root->children[index] =
        erase(root->children[index], key, depth + 1);
   if (isEmpty(root) && root->isEndOfWord == false) {
        delete (root);
        root = nullptr;
    }

    
}

