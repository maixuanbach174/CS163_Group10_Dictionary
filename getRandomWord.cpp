#include "Trie.h"
#include "getRandomWord.h"
#include <bits/stdc++.h>
using namespace std;
wstring getRandomWord(TrieNode *root)
{
    wstring randomWord=L"";
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
        randomWord+=char(L'a'+index);
        cur=cur->children[index];



    }
    return randomWord;
}
