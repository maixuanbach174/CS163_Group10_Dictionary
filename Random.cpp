#include "Trie.h"
#include "Random.h"
#include <bits/stdc++.h>
using namespace std;
string getRandomWord(TrieNode *root)
{
    string randomWord="";
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
        randomWord+=char('a'+index);
        cur=cur->children[index];



    }
    return randomWord;
}
