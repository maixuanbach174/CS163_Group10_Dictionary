#include "SearchByDef.hpp"
#include <fstream>

vector<wstring> splitToWords(wstring def)
{
    vector<wstring> words;
    wstring word = L"";
    for (int i = 0; i < def.length(); i++)
    {
        if (def[i] == L' ' || def[i] == L'(' || def[i] == L')' || def[i] == L';' || def[i] == L'+' || def[i] == L'.' || def[i] == L',')
        {
            if (word != L"")
            {
                words.push_back(word);
                word = L"";
            }
        }
        else
        {
            word += def[i];
        }
    }
    if (word != L"")
    {
        words.push_back(word);
    }
    return words;
}

void insertdef(TrieNode *& root, wstring def, int index)
{
    vector<wstring> words = splitToWords(def);
    for (int i = 0; i < words.size(); i++)
    {
        insert(root, words[i], index);
    }
}

vector<int> finddef(TrieNode*& root, wstring def)
{
    vector<wstring> words = splitToWords(def);
    if(words.empty())
    {
        return vector<int>();
    }
    TrieNode* cur = find(root, words[0]);
    if(cur == nullptr)
    {
        return vector<int>();
    }
    vector<int> indexs = cur->value;
    for(int i = 1; i < words.size(); ++i)
    {
        TrieNode * cur2 = find(root, words[i]);
        if(cur2 == nullptr)
        {
            return vector<int>();
        }
        vector<int> temp = cur2->value;
        vector<int> sol;
        set_intersection(indexs.begin(), indexs.end(), temp.begin(), temp.end(), back_inserter(sol));
        indexs = sol;
    }
    return indexs;
}

void Vieinsertdef(VieTrieNode *& root, wstring def, int index)
{
    vector<wstring> words = splitToWords(def);
    for (int i = 0; i < words.size(); i++)
    {
        VieInsert(root, words[i], index);
    }
}

vector<int> Viefinddef(VieTrieNode*& root, wstring def)
{
    vector<wstring> words = splitToWords(def);
    if(words.empty())
    {
        return vector<int>();
    }
    VieTrieNode* cur = VieFind(root, words[0]);
    if(cur == nullptr)
    {
        return vector<int>();
    }
    vector<int> indexs = cur->value;
    for(int i = 1; i < words.size(); ++i)
    {
        VieTrieNode * cur2 = VieFind(root, words[i]);
        if(cur2 == nullptr)
        {
            return vector<int>();
        }
        vector<int> temp = cur2->value;
        vector<int> sol;
        set_intersection(indexs.begin(), indexs.end(), temp.begin(), temp.end(), back_inserter(sol));
        indexs = sol;
    }
    return indexs;
}


