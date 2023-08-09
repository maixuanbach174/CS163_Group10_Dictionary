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
        vector<wstring> top = splitEngEng(subDef);
        insert(root, word, top);
    }
}

vector<wstring> splitEngEng(wstring definition)
{
	    vector<wstring> Split; 
		wstring temp = definition;
	    while (!temp.empty())
		{
			int count1;
			count1 = temp.find(L'\n');
			wstring def = temp.substr(0, count1);
			Split.push_back(def);
			temp=temp.erase(0, count1+1);
			int count2;
			count2 = temp.find(L'.');
			wstring ex = temp.substr(0, count2 + 1);
			Split.push_back(ex);
			temp=temp.erase(0, count2+2);
		}
		return Split;
    
}
