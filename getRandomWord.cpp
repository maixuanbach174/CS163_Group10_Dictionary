#include "Trie.h"
#include "getRandomWord.h"
#include <algorithm>  // For std::shuffle
#include <random>     // For random_device, mt19937
#include <ctime>      // For time
#include <cstdlib>    // For srand

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

//vector <wstring> getRandomWord(vector <wstring> words,vector <vector <wstring>> definitions)
//{
//    vector <wstring> res;
//    srand(time(0));
//    int s=words.size();
//    int randomIndex=rand()%s;
//    res.push_back(words[randomIndex]);
//    std::random_device rd;
//    std::mt19937 rng(rd());
//    vector <wstring> def;
//    int randomLine=rand%definitions[randomIndex].size();
//    def.push_back(definitions[randomIndex][randomLine]);
//
//    for (int i=0;i<3;i++)
//    {
//        int nums=rand()%s;
//        int ss=definitions[nums].size();
//        int line=rand()%ss;
//        def.push_back(definitions[nums][line]);
//
//    }
//    shuffle(def.begin(),def.end(),rng);
//    res+=def;
//    return res;
//
//
//
//}
vector<wstring> getRandomWord(vector<wstring> words, vector<vector<wstring>> definitions) {
    vector<wstring> res;
    srand(time(0));
    int s = words.size();
    int randomIndex = rand() % s;
    res.push_back(words[randomIndex]);

//    std::random_device rd;
//    std::mt19937 rng(rd());

    vector<wstring> def;
    int randomLine = rand() % definitions[randomIndex].size();
    def.push_back(definitions[randomIndex][randomLine]);

    for (int i = 0; i < 3; i++) {
        int nums = rand() % s;
        int ss = definitions[nums].size();
        int line = rand() % ss;
        def.push_back(definitions[nums][line]);
    }

    std::random_device rd;
    std::mt19937 rng(rd());
    std::shuffle(def.begin(), def.end(), rng);
    // Append the elements of 'def' to 'res'
    res.insert(res.end(), def.begin(), def.end());

    return res;
}
//int main()
//{
//    vector <wstring> words={L"1",L"2",L"5",L"3",L"44",L"15"};
//    wcout<<getRandomWord(words);
//}
