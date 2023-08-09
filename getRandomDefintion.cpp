#include "Trie.h"
#include <bits/stdc++.h>

using namespace std;
vector <wstring> getRandomDefintion(TrieNode* root)
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
        if ((cur)&&(cur->isEndOfWord)) return root->definition[1];
    }


}

