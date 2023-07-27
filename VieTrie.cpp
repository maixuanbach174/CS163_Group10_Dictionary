#include "VieTrie.h"
#include <iostream>
#include <io.h>
#include <codecvt>
#include <fcntl.h>
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

void VieEng(VieTrieNode* root)
{
    if (!root)
        return;
    wifstream in("Text.txt");
    _setmode(_fileno(stdin), _O_U8TEXT);
    _setmode(_fileno(stdout), _O_U8TEXT);
    locale loc(locale(), new codecvt_utf8_utf16<wchar_t>);
    in.imbue(loc);

    if (!in)
    {
        cout << "not found";
        return;
    }

    wstring flag = L"*", line, word, def;
    bool added = false;
    bool flagFound = false; 

    while (getline(in, line))
    {
        size_t pos = line.find(flag);
        word = line.substr(0, pos);
        def = line.substr(pos + 1);
        wstring track;
        while (getline(in, track))
        {
            if (track.find(flag) != wstring::npos)
            {
                flagFound = true;
                break;
            }
            else
                def += L" " + track;
        }
        if (!flagFound) 
            getline(in, track);
        flagFound = false;
        VieInsert(root, word, def);
        wcout << word << " " << def << endl << endl;
    }
    in.close();
}



int main()
{
    VieTrieNode* root = new VieTrieNode();
    VieEng(root);
    return 0;
}
