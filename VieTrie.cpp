#include "VieTrie.h"

VieTrieNode::VieTrieNode()
{
    for(int i = 0; i < 16; ++i) children[i] = nullptr;

    isEndOfWord = false;
}

VieTrieNode * VieFind(VieTrieNode *& root, wstring vieword)
{
    if(root == nullptr) return nullptr;

    string encode = unicodeToUtf8(vieword);
    int si = encode.size();

    VieTrieNode * cur = root;
    for(int i = 0; i < si; ++i)
    {
        int index;
        if(isdigit(encode[i])) index = encode[i] - '0';
        else index = encode[i] - 'A' + 10;
        if(cur->children[index] == nullptr) return nullptr;

        cur = cur->children[index];
    }

    if(cur->isEndOfWord) return cur;

    return nullptr;
}

bool VieInsert(VieTrieNode *& root, wstring vieword, vector<wstring> def)
{
    if(root == nullptr) root = new VieTrieNode();

    VieTrieNode* pCrawl = root;
    string encode = unicodeToUtf8(vieword);
    
    for (int i = 0; i < encode.length(); i++)
    {
        int index;
        if(isdigit(encode[i])) index = encode[i] - '0';
        else index = encode[i] - 'A' + 10;

        if (!pCrawl->children[index])
            pCrawl->children[index] = new VieTrieNode();

        pCrawl = pCrawl->children[index];
    }

    pCrawl->isEndOfWord = true;
    pCrawl->definition = def;
    return pCrawl->isEndOfWord;
}

bool VieInsert(VieTrieNode *& root, wstring vieword, int index)
{
    if(root == nullptr) root = new VieTrieNode();

    VieTrieNode* pCrawl = root;
    string encode = unicodeToUtf8(vieword);
    
    for (int i = 0; i < encode.length(); i++)
    {
        int index;
        if(isdigit(encode[i])) index = encode[i] - '0';
        else index = encode[i] - 'A' + 10;

        if (!pCrawl->children[index])
            pCrawl->children[index] = new VieTrieNode();

        pCrawl = pCrawl->children[index];
    }

    pCrawl->isEndOfWord = true;
    pCrawl->value.push_back(index);
    return pCrawl->isEndOfWord;
}

void VieDeallocate(VieTrieNode * root)
{
    if(root == nullptr) return;

    for(int i = 0; i < 17; ++i)
    {
        VieDeallocate(root->children[i]);
    }
    
    delete root;
}

bool isEmpty(VieTrieNode* root)
{
    for (int i = 0; i < 16; i++)
        if (root->children[i])
            return false;
    return true;
}

VieTrieNode* VieErase(VieTrieNode* root, wstring vieword)
{
    string encode = unicodeToUtf8(vieword);
    return VieRemove(root, encode, 0);
}
 
VieTrieNode* VieRemove(VieTrieNode* root, string key, int depth)
{
    if (!root)
        return NULL;
    if (depth == key.size()) {
        if (root->isEndOfWord)
            {
                root->isEndOfWord = false;
                root->definition.clear();
            }
        if (isEmpty(root)) {
            delete (root);
            root = NULL;
        }
        return root;
    }
    int index;
    if(isdigit(key[depth])) index = key[depth] - '0';
        else index = key[depth] - 'A' + 10;
    root->children[index] =
          VieRemove(root->children[index], key, depth + 1);
    if (isEmpty(root) && root->isEndOfWord == false) {
        delete (root);
        root = NULL;
    }
    return root;
}

