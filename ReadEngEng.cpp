#include "ReadEngEng.hpp"

void readEngEng(vector<wstring>& words, vector<vector<wstring>>& definitions, vector<vector<wstring>>& examples)                                                  
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
        while(line[firstCommaPos + 1] == L' ') ++firstCommaPos;
        def = line.substr(firstCommaPos + 1);
        while(def.back() == L' ') def.pop_back();
        vector<wstring> t1;
        vector<wstring> t2;
        splitEngEng(def, t1, t2);
        words.push_back(word);
        definitions.push_back(t1);
        examples.push_back(t2);
    }
}

void splitEngEng(wstring definition, vector<wstring>& defs, vector<wstring>& examples)
{
    bool isInQuote = false;
    int count = 0;
    for(int i = 0; i < definition.size(); ++i)
    {
        if(!isInQuote && definition[i] == L';' )
        {
            if(i != 0) 
            {
                if(count)
                {
                    examples.push_back(definition.substr(0, i));
                }
                else
                {
                    defs.push_back(definition.substr(0, i));
                    count++;
                }
            }
            definition.erase(0, i + 1);
            i = -1;
        }

        if(!isInQuote && definition[i] == L',')
        {
            if(i != 0 ) 
            {
                if(count)
                examples.push_back(definition.substr(0, i));
                else
                {
                    defs.push_back(definition.substr(0, i));
                    count++;
                }
            }
            definition.erase(0, i + 1);
            i = -1;
        }

        if(definition[i] == L'\"')
        {
            isInQuote = !isInQuote;
            if(!isInQuote)
            {
                if(i != 0 ) 
            {
                if(count)
                examples.push_back(definition.substr(1, i - 1));
                else
                {
                    defs.push_back(definition.substr(1, i - 1));
                    count++;
                }
            }
                definition.erase(0, i + 1);
                i = -1;
            }
        }

    }

    if(definition.size() != 0)
    {
                if(count)
                examples.push_back(definition);
                else
                {
                    defs.push_back(definition);
                    count++;
                }
    }
    
}
