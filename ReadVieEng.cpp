#include "ReadVieEng.hpp"

void VieEng(vector<wstring>& words, vector<vector<wstring>>& defs, vector<vector<wstring>>& examples)
{
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
    wstring flag = L"*", wordFlag = L"\t";
    wstring line, word, def;
    bool flagFound = false;
    while (getline(in, line))
    {
        size_t pos = line.find(flag);
        word = line.substr(0, pos);
        def = line.substr(pos + 1);
        size_t wordPos = line.find(wordFlag);
        word = word.substr(0, wordPos);
        vector<wstring> deftemp;
        vector<wstring> examp;
        FormatVieEng(def, deftemp, examp);
        words.push_back(word);
        defs.push_back(deftemp);
        examples.push_back(examp);
    }

    in.close();
}

void FormatVieEng(wstring def, vector<wstring>& definitions, vector<wstring>& examples)
{
    int temp;
    wstring type;
    for(temp = 0; def[temp] != L';' && def[temp] != L'+' &&
        def[temp] != L'=' && temp < def.size() && def[temp] != L'-'; ++temp)
    {
        type.push_back(def[temp]);
    }

    while(!type.empty() && type[0] == L' ')
    {
        type.erase(type.begin());
    }

    definitions.push_back(type);

    if(temp == def.size())
    {
        return;
    }

    for(int index = temp; index < def.size(); ++index)
    {  
        if(def[index] == L'-' || def[index] == L';')
        {
            wstring definition;
            int temp;
            for(temp = index + 1; def[temp] != L';' && def[temp] != L'+' &&
            def[temp] != L'=' && temp < def.size() && def[temp] != L'-'; ++temp)
            {
                definition.push_back(def[temp]);
            }

            index = temp - 1;
            while(!definition.empty() && definition[0] == L' ')
            {
                definition.erase(definition.begin());
            }

            definitions.push_back(definition);
        }

        if(def[index] == L'=' || def[index] == L'+')
        {
            wstring ex;
            int temp;
            for(temp = index + 1; def[temp] != L';' && def[temp] != L'-' &&
            def[temp] != L'+' && temp < def.size() && def[temp] != L'='; ++temp)
            {
                ex.push_back(def[temp]);
            }

            index = temp - 1; 
            while(!ex.empty() && ex[0] == L' ')
            {
                ex.erase(ex.begin());
            }

            examples.push_back(ex);           
        }
    }

}