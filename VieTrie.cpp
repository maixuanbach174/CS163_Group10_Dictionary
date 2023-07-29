#include "VieTrie.h"
#include <iostream>
#include <fstream>
VieTrieNode::VieTrieNode()
{
    for(int i = 0; i < 16; ++i) children[i] = nullptr;

    isEndOfWord = false;
    definition = L"";
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

bool VieInsert(VieTrieNode *& root, wstring vieword, wstring def)
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

VieTrieNode* removefunction(VieTrieNode* root, string word, int depth)
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
    int index;
    if (isdigit(word[depth])) index = word[depth] - '0';
    else index = word[depth] - 'A' + 10;
    root->children[index] = removefunction(root->children[index], word, depth + 1);
   if (isEmpty(root) && root->isEndOfWord == false) {
        delete (root);
        root = nullptr;
    }
   return root;

    
}

VieTrieNode* remove(VieTrieNode* root, wstring vieword)
{
    string word = unicodeToUtf8(vieword);
    int depth = 0;
    return removefunction(root, word, depth);
}
bool isLeafNode(VieTrieNode* root)
{
    return root->isEndOfWord != false;
}
void Vieserialize(VieTrieNode* root, char str[], int level, wofstream& newfile) {

    if (isLeafNode(root)) {
        str[level] = '\0';
        string t = str;
        wstring s = UTF8toUnicode(t);
        newfile.open(L"VieSerialize.txt", ios::out | ios::app);
        if (newfile.is_open()) {
            newfile << s << "\n";
            newfile << root->definition;
            newfile.close();
        }
        cout << "Added: " << str << endl;
    }

    int i;
    for (i = 0; i < 16; i++) {

        if (root->children[i]) {
            if (i < 10)
                str[level] = i + 48;
            else str[level] = i + 55;
            Vieserialize(root->children[i], str, level + 1, newfile);
        }
    }
}
