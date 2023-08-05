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
        wstring word = line.substr(0, firstCommaPos), subDef = L"";
        def = line.substr(firstCommaPos + 1);
        for (int i = 0; i < def.size(); i++)
        {
            if (def[i] == L',')
            {
                subDef += def.substr(0, i) + L"\n" + def.substr(i + 1);
            }
        }
        insert(root, word, subDef);
    }
}
