#include "Trie.h"
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;
TrieNode::TrieNode()
{
    for(int i = 0; i < ALPHABET_SIZE; ++i) children[i] = nullptr;
    isEndOfWord = false;
    definition = L"";
}

TrieNode* find(TrieNode* root, wstring word)
{
    if(root == nullptr) return nullptr;
    
    TrieNode *cur = root;

    for(int i = 0; i < word.size(); ++i)
    {
        if (isalpha(word[i])) continue;
        int index = tolower(word[i]) - L'a';
        if(cur->children[index] == nullptr) return nullptr;

        cur = cur->children[index];
    }

    if(cur->isEndOfWord) return cur;
    return nullptr;
}




bool insert(TrieNode* &root, wstring word, wstring def)
{
    if (root == nullptr)
        root = new TrieNode();

    TrieNode* pCrawl = root;
    for (int i = 0; i < word.length(); i++)
    {
        if (!isalpha(word[i])) continue;
        int index = word[i] - L'a';
        if (!pCrawl->children[index])
            (pCrawl->children[index] = new TrieNode());

        pCrawl = pCrawl->children[index];
    }
    pCrawl->isEndOfWord = true;
    pCrawl->definition = def;
    return pCrawl->isEndOfWord;
}



bool isEmpty(TrieNode* root)
{
    for (int i = 0; i < ALPHABET_SIZE; i++)
        if (root->children[i])
            return false;
    return true;
}




TrieNode* removefunction(TrieNode* root, string word, int depth)

{
    
    if (!root)
        return nullptr;
    if (word.size() == depth)
    {
        if (root->isEndOfWord)
        {
            root->isEndOfWord = false;
        }

        if (isEmpty(root))
        {
            delete(root);
            root = nullptr;
        }
        return root;
    }
    int index = word[depth] - 'a';
    root->children[index] = removefunction(root->children[index], word, depth + 1);
   if (isEmpty(root) && root->isEndOfWord == false) {
        delete (root);
        root = nullptr;
    }
   return root;

    
}


TrieNode* remove(TrieNode* root, string word)

{
    int depth = 0;
    return removefunction(root, word, depth);
}



void deallocate(TrieNode* root)
{
    if(root == nullptr) return;
    for(int i = 0; i < ALPHABET_SIZE; ++i)
    {
        deallocate(root->children[i]);
    }

    delete root;
}

bool isLeafNode(TrieNode* root)
{
    return root->isEndOfWord != false;
}
void serialize(TrieNode* root, char str[], int level, wofstream& newfile) {
    TrieNode* pcrawl = root;
    if (isLeafNode(pcrawl)) {
        str[level] = '\0';
        newfile.open(L"serialize.txt", ios::out | ios::app);
        if (newfile.is_open()) {
            newfile << str << "\n";
            newfile << root->definition<< "\n";
            newfile.close();
        }
        
    }
    int i;
    for (i = 0; i < ALPHABET_SIZE; i++) {

        if (root->children[i]) {
            str[level] = i + L'a';
            serialize(root->children[i], str, level + 1, newfile);
        }
    }
}



