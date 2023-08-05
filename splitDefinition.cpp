#include <bits/stdc++.h>
using namespace std;
vector <wstring> splitDefinition(wstring definition)
{
    vector <wstring> res;
    wstringstream ss(definition);
    wstring line;
    while (getline(ss,line))
    {
        if ((line[0]==L'-')or(iswalpha(line[0]))or(line[0]==L'+'))
        res.push_back(line);
        //wcout<<line<<endl;
    }
    return res;
}
vector <wstring> splitExample(wstring definition)
{
    vector <wstring> res;
    wstringstream ss(definition);
    wstring line;
    while (getline(ss,line))
    {
        if (line[0]==L'=') res.push_back(line);
    }
    return res;
}
//int main()
//{
//    wstring def=L"";
//    def += L"lam banh" + wstring(L"\n"); // Use double quotes for the newline character
//    def += L"da banh";    //def+=L"da banh";
//    vector <wstring> afterSPlit=splitDefinition(def);
//    for (int i=0;i<afterSPlit.size();i++)
//    {
//        wcout<<afterSPlit[i]<<endl;
//    }
////wcout<<def;
//    return 0;
//}
