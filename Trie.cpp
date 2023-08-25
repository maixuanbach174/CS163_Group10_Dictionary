#include "Trie.h"

TrieNode::TrieNode()
{
    for(int i = 0; i < ALPHABET_SIZE; ++i) children[i] = nullptr;
    isEndOfWord = false;
}

TrieNode* find(TrieNode*& root, wstring word)
{
    if(root == nullptr) return nullptr;

    TrieNode *cur = root;

    for(int i = 0; i < word.size(); ++i)
    {
        if (!isalpha(word[i])) continue;
        int index = tolower(word[i]) - L'a';
        if(cur->children[index] == nullptr) return nullptr;

        cur = cur->children[index];
    }

    if(cur->isEndOfWord) return cur;
    return nullptr;
}

bool insert(TrieNode*& root, wstring word, int index)
{
    if(root == nullptr) root = new TrieNode();
    TrieNode* pCrawl = root;
    for (int i = 0; i < word.length(); i++)
    {
        if (!isalpha(word[i])) continue;
        int index = tolower(word[i]) - L'a';
        if (!pCrawl->children[index])
            pCrawl->children[index] = new TrieNode();

        pCrawl = pCrawl->children[index];
    }
    pCrawl->isEndOfWord = true;
    for(auto &i : pCrawl->value)
    {
        if(i == index) return pCrawl->isEndOfWord;
    }
    pCrawl->value.push_back(index);
    return pCrawl->isEndOfWord;
}

bool isEmpty(TrieNode* root)
{
    for (int i = 0; i < ALPHABET_SIZE; i++)
        if (root->children[i])
            return false;
    return true;
}
 
TrieNode* remove(TrieNode* root, wstring key, int depth)
{
    if (!root)
        return NULL;
    if (depth == key.size()) {

        if (root->isEndOfWord)
            root->isEndOfWord = false;
        if (isEmpty(root)) {
            delete (root);
            root = NULL;
        }
 
        return root;
    }
    int index = key[depth] - L'a';
    root->children[index] =
          remove(root->children[index], key, depth + 1);
    if (isEmpty(root) && root->isEndOfWord == false) {
        delete (root);
        root = NULL;
    }
    return root;
}

TrieNode* erase(TrieNode* root, wstring word)
{
    return remove(root, word, 0);
}

TrieNode* eraseOneIndex(TrieNode* root, wstring word, int& val)
{
    return removeIndex(root, word, val, 0);
}

TrieNode * removeIndex(TrieNode* root, wstring key, int& val, int depth)
{
    // TrieNode * cur = find(root, key);
    // if(cur)
    // {
    //     for(int i = 0; i < cur->value.size(); ++i)
    //     {
    //         if(cur->value[i] == val)
    //         {
    //             cur->value.erase(cur->value.begin() + i);
    //         }
    //     }

    //     if(cur->value.empty()) cur->isEndOfWord = false;
    // }
     if (!root)
        return NULL;
    if (depth == key.size()) {

        if (root->isEndOfWord)
            {
                for(int i = 0; i < root->value.size(); ++i)
                {
                    if(root->value[i] == val)
                    {
                        root->value.erase(root->value.begin() + i);
                    }
                }
                if(root->value.empty())
                root->isEndOfWord = false;
            }
        if (isEmpty(root) && root->isEndOfWord == false) {
            delete (root);
            root = NULL;
        }
 
        return root;
    }
    int index = key[depth] - L'a';
    root->children[index] =
          removeIndex(root->children[index], key, val,depth + 1);
    if (isEmpty(root) && root->isEndOfWord == false) {
        delete (root);
        root = NULL;
    }
    return root;
}

void deallocate(TrieNode*& root)
{
    if(root == nullptr) return;
    for(int i = 0; i < ALPHABET_SIZE; ++i)
    {
        deallocate(root->children[i]);
    }
    delete root;
    root = nullptr;
}

