#include "Trie.h"
#include <bits/stdc++.h>
using namespace std;
wstring getRandomDefintion(TrieNode* root)
{
    TrieNode *cur = root;

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
        if ((cur)&&(cur->isEndOfWord)) return cur->definition;
    }

}
