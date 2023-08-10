#include "ReadEngEng.hpp"

void readEngEng(TrieNode* root)                                                  
{
    string filename = "DataSet/engwords.csv";
    wifstream dict(filename, std::ios::binary);
    wstring line, def, limiter = L".";
    if (!dict)
    {
        cout << "Can't open file!";
        return;
    }

    while (getline(dict, line))
    {
        size_t firstCommaPos = line.find(L',');
        wstring word = line.substr(0, firstCommaPos);
        def = line.substr(firstCommaPos + 1);
        vector<wstring> top = splitEngEng(def);
        insert(root, word, top);
    }
}

vector<wstring> splitEngEng(wstring definition)
{
    vector<wstring> top;
    bool isInQuote = false;
    for(int i = 0; i < definition.size(); ++i)
    {
        if(!isInQuote && definition[i] == L';' )
        {
            if(i != 0) top.push_back(definition.substr(0, i));
            definition.erase(0, i + 1);
            i = -1;
        }

        if(!isInQuote && definition[i] == L',')
        {
            if(i != 0 ) top.push_back(definition.substr(0, i));
            definition.erase(0, i + 1);
            i = -1;
        }

        if(definition[i] == L'\"')
        {
            isInQuote = !isInQuote;
            if(!isInQuote)
            {
                if(i != 0)
                top.push_back(definition.substr(1, i - 1));
                definition.erase(0, i + 1);
                i = -1;
            }
        }

    }
    if(definition.size() != 0) top.push_back(definition);
    
    return top;
}