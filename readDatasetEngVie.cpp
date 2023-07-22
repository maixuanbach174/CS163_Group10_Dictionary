#include "readDatasetEngVie.hpp"

void readDatasetEngVie(TrieNode* root)
{
     _setmode(_fileno(stdin), _O_U16TEXT);
  _setmode(_fileno(stdout), _O_U16TEXT);
   locale loc(locale(), new codecvt_utf8_utf16<wchar_t>);
   wifstream fi;
 // wofstream fo;
  fi.open("DataSet/english-vietnamese.txt");
  fi.imbue(loc);
  wofstream fo("DataSet/test.txt");
  fo.imbue(loc);

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

            //wcout<<word<<endl;
            q.push(word);
            if ((def!=L"")or(q.front()!=L"a"))
            {
                insert(root,q.front(),def);
                //wcout<<def<<endl;
                //wcout<<q.front()<<endl<<def<<endl;
                def=L"";
                q.pop();
            }


        }
        else
        {

            def+=s+L'\n';
        }




      fo<<s<<endl;
    }



  fi.close();



}

