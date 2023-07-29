#include "ReadEngEng.hpp"

void readEngEng(TrieNode* root)
{
    string filename = "DataSet/engwords.csv";
    wifstream dict(filename, std::ios::binary);
    wstring line, def;
    if (!dict)
    {
        cout << "Can't open file!";
        return;
    }

    while (getline(dict, line))
    {
        size_t firstCommaPos = line.find(L',');
        wstring word = line.substr(0, firstCommaPos);
        //wcout << word << " ";
        def = line.substr(firstCommaPos + 1);
        //wcout << def << endl << endl;
        insert(root, word, def);
    }
}
