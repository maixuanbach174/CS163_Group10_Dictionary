#include "readDatasetEngVie.hpp"

void readDatasetEngVie(vector<wstring>& words, vector<vector<wstring>>& defs, vector<vector<wstring>>& examples)
{
   locale loc(locale(), new codecvt_utf8_utf16<wchar_t>);
   wifstream fi;
  fi.open("DataSet/english-vietnamese.txt");
  fi.imbue(loc);
      wstring s;
    getline (fi,s,L'\n');
    wstring def=L"";
    queue <wstring> q;
    while (!fi.eof())
    {

        getline (fi,s,L'\n');
        if (s[0]==L'@')
        {
            wstring word=L"";
            for (int i=1;i<s.size();i++)
            {
                if ((s[i]==L' ')&&(s[i+1]==L'/')) break;
                else word+=tolower(s[i]);
            }
            q.push(word);
            if ((def!=L"")or(q.front()!=L"a"))
            {
                vector<wstring> t1 = splitDefinition(def);
                vector<wstring> t2 = splitExample(def);
                words.push_back(q.front());
                defs.push_back(t1);
                examples.push_back(t2);
                def=L"";
                q.pop();
            }
        }
        else
        {
            def+=s+L'\n';
        }
    }
  fi.close();
}

vector <wstring> splitDefinition(wstring definition)
{
   vector <wstring> res;
   wstringstream ss(definition);
   wstring line;
   while (getline(ss,line))
   {
       if ((line[0]==L'-')or(iswalpha(line[0]))or(line[0]==L'+'))
       {
          if(line[0] == L'-' || line[0] == L'+') line.erase(line.begin(), line.begin() + 2);
          res.push_back(line);
       }
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
       if (line[0]==L'=') 
       {
          line.erase(line.begin());
          res.push_back(line);
       }
   }
   return res;
}

