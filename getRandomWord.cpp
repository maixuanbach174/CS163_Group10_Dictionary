#include "Trie.h"
#include "getRandomWord.h"
#include <bits/stdc++.h>
using namespace std;
//wstring getRandomWord(TrieNode *root)
//{
//    wstring randomWord=L"";
//    TrieNode *cur = root;
//
//    srand(time(0));
//
//    while ((cur != nullptr) && (!cur->isEndOfWord))
//    {
//        int index;
//        do
//        {
//            index=rand()%26;
//        }
//        while (!cur->children[index]);
//        randomWord+=char(L'a'+index);
//        cur=cur->children[index];
//
//
//
//    }
//    return randomWord;
//}

wstring getRandomWord(vector <wstring> words)
{
    srand(time(0));
    int s=words.size();
    int randomIndex=rand()%s;
    return words[randomIndex];

}
//int main()
//{
//    vector <wstring> words={L"1",L"2",L"5",L"3",L"44",L"15"};
//    wcout<<getRandomWord(words);
//}
