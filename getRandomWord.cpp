#include "Trie.h"
#include "getRandomWord.h"
#include <algorithm>  
#include <random>     
#include <ctime>      
#include <cstdlib>    

using namespace std;

vector<wstring> getRandomWord(vector<wstring> words, vector<vector<wstring>> definitions, int& index) {
    vector<wstring> res;
    int s = words.size();
    int randomIndex = rand() % s;
    res.push_back(words[randomIndex]);

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
    for(int i = 0; i < def.size(); ++i)
    {
        if(def[i] == definitions[randomIndex][randomLine])
        {
            index = i;
        }
    }
    
    res.insert(res.end(), def.begin(), def.end());

    return res;
}
