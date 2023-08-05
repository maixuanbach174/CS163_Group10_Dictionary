#include "ReadVieEng.hpp"

void VieEng(VieTrieNode* root)
{
    if (!root)
        return;
    int count = 0;
    wifstream in("DataSet/Text.txt");
    _setmode(_fileno(stdin), _O_U8TEXT);
    _setmode(_fileno(stdout), _O_U8TEXT);
    locale loc(locale(), new codecvt_utf8_utf16<wchar_t>);
    in.imbue(loc);

    if (!in)
    {
        cout << "not found";
        return;
    }
    wstring flag = L"*";
    wstring line, word, def;
    bool flagFound = false;
    while (getline(in, line))
    {
        size_t pos = line.find(flag);
        word = line.substr(0, pos);
        def = line.substr(pos + 1);
        size_t subPos = 0;
        wstring subDef;
        for (int i = 0; i < def.size(); i++)
        {
            if (def[i] == L'=' || def[i] == L'+' || i == def.size() - 1)
            {
                if (i == def.size() - 1)
                    subDef += def.substr(subPos, i - subPos + 1);
                subDef += def.substr(subPos, i - subPos + 1) + L"\n";
                subPos = i+1;
            }
        }
        VieInsert(root, word, subDef);
    }
    in.close();
}