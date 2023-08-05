#include "Trie.h"
#include <bits/stdc++.h>

using namespace std;
wstring getRandomDefintion(TrieNode* root)
{
    TrieNode *cur = root;
    wstring fulldef = L"";
    srand(time(0));

    while ((cur != nullptr) && (!cur->isEndOfWord))
    {
        int index;
        do
        {
            index=rand()%26;
        }
        while (!cur->children[index]);
        cur=cur->children[index];
        if ((cur)&&(cur->isEndOfWord)) fulldef=cur->definition;
    }
    wstringstream line(fulldef);
    wstring line;
    vector <wstring> def;
    vector <wstring> normal;
    while (getline(line,fulldef))
    {
        if (line[0]==L'-') def.push_back(line);
        normal.push_back(line);
    }
    if (!def.empty())
    {
        srand(0);
        int index=rand%def.size();
        return def[index];
    }
    else
    {
        srand(0);
        int index=rand%normal.size();
        return normal[index];
    }

}

