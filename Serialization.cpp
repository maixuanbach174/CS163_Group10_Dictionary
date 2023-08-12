#include <iostream>
#include <stdio.h>
#include <fcntl.h>
#include <io.h>
#include <string>
#include <fstream>
#include <locale>
#include <Windows.h>
#include <codecvt>
#include <bits/stdc++.h>
#include "Serialization.h"
#define ALPHABET_SIZE 28
using namespace std;
//struct TrieNode
//{
//    TrieNode *children[ALPHABET_SIZE];
//    bool isEndOfWord;
//    vector <wstring> definition;
//    TrieNode();
//};
//TrieNode::TrieNode()
//{
//    for(int i = 0; i < ALPHABET_SIZE; ++i) children[i] = nullptr;
//    isEndOfWord = false;
//
//}
//vector <wstring> splitDefinition(wstring definition)
//{
//   vector <wstring> res;
//   wstringstream ss(definition);
//   wstring line;
//   while (getline(ss,line))
//   {
//       if ((line[0]==L'-')or(iswalpha(line[0]))or(line[0]==L'+'))
//       {
//          if(line[0] == L'-' || line[0] == L'+') line.erase(line.begin(), line.begin() + 2);
//          res.push_back(line);
//       }
//    }
//   return res;
//}
//
//vector <wstring> splitExample(wstring definition)
//{
//   vector <wstring> res;
//   wstringstream ss(definition);
//   wstring line;
//   while (getline(ss,line))
//   {
//       if (line[0]==L'=')
//       {
//          line.erase(line.begin());
//          res.push_back(line);
//       }
//   }
//   return res;
//}
//void splitEngEng(wstring definition, vector<wstring>& defs, vector<wstring>& examples)
//{
//    bool isInQuote = false;
//    int count = 0;
//    for(int i = 0; i < definition.size(); ++i)
//    {
//        if(!isInQuote && definition[i] == L';' )
//        {
//            if(i != 0)
//            {
//                if(count)
//                {
//                    examples.push_back(definition.substr(0, i));
//                }
//                else
//                {
//                    defs.push_back(definition.substr(0, i));
//                    count++;
//                }
//            }
//            definition.erase(0, i + 1);
//            i = -1;
//        }
//
//        if(!isInQuote && definition[i] == L',')
//        {
//            if(i != 0 )
//            {
//                if(count)
//                examples.push_back(definition.substr(0, i));
//                else
//                {
//                    defs.push_back(definition.substr(0, i));
//                    count++;
//                }
//            }
//            definition.erase(0, i + 1);
//            i = -1;
//        }
//
//        if(definition[i] == L'\"')
//        {
//            isInQuote = !isInQuote;
//            if(!isInQuote)
//            {
//                if(i != 0 )
//            {
//                if(count)
//                examples.push_back(definition.substr(1, i - 1));
//                else
//                {
//                    defs.push_back(definition.substr(1, i - 1));
//                    count++;
//                }
//            }
//                definition.erase(0, i + 1);
//                i = -1;
//            }
//        }
//
//    }
//
//    if(definition.size() != 0)
//    {
//                if(count)
//                examples.push_back(definition);
//                else
//                {
//                    defs.push_back(definition);
//                    count++;
//                }
//    }
//}
//void readEngEng(vector<wstring>& words, vector<vector<wstring>>& definitions, vector<vector<wstring>>& examples)
//{
//    string filename = "engwords.csv";
//    wifstream dict(filename, std::ios::binary);
//    wstring line, def, limiter = L".";
//    if (!dict)
//    {
//        cout << "Can't open file!";
//        return;
//    }
//
//    while (getline(dict, line))
//    {
//        size_t firstCommaPos = line.find(L',');
//        wstring word = line.substr(0, firstCommaPos);
//        while(line[firstCommaPos + 1] == L' ') ++firstCommaPos;
//        def = line.substr(firstCommaPos + 1);
//        while(def.back() == L' ') def.pop_back();
//        vector<wstring> t1;
//        vector<wstring> t2;
//        splitEngEng(def, t1, t2);
//
//        words.push_back(word);
//        definitions.push_back(t1);
//        examples.push_back(t2);
//    }
//}
//
//
//
//bool insert(TrieNode*& root, wstring word, vector <wstring> def)
//{
//    if(root == nullptr) root = new TrieNode();
//    TrieNode* pCrawl = root;
//    for (int i = 0; i < word.length(); i++)
//    {
//        if (!isalpha(word[i])) continue;
//        int index = word[i] - L'a';
//        if (!pCrawl->children[index])
//            pCrawl->children[index] = new TrieNode();
//
//        pCrawl = pCrawl->children[index];
//    }
//    pCrawl->isEndOfWord = true;
//    pCrawl->definition = def;
//    return pCrawl->isEndOfWord;
//}
//
//void readDatasetEngVie(vector<wstring>& words, vector<vector<wstring>>& defs, vector<vector<wstring>>& examples)
//{
//    _setmode(_fileno(stdin), _O_U16TEXT);
//
//    _setmode(_fileno(stdout), _O_U16TEXT);
//
//   locale loc(locale(), new codecvt_utf8_utf16<wchar_t>);
//   wifstream fi;
//  fi.open("english-vietnamese.txt");
// fi.imbue(loc);
//      wstring s;
//   getline (fi,s);
//    wstring def=L"";
//    queue <wstring> q;
//    //q.push(L"a");
//    while (!fi.eof())
//    {
//
//        getline (fi,s,L'\n');
//        if (s[0]==L'@')
//        {
//            wstring word=L"";
//            for (int i=1;i<s.size();i++)
//            {
//                if ((s[i]==L' ')&&(s[i+1]==L'/')) break;
//                else word+=tolower(s[i]);
//            }
//            q.push(word);
//            //wcout<<word<<endl;
//            if ((def!=L"")or(q.front()!=L"a"))
//            {
//                vector<wstring> t1 = splitDefinition(def);
//                vector<wstring> t2 = splitExample(def);
//                words.push_back(q.front());
//
//                defs.push_back(t1);
//                examples.push_back(t2);
//                def=L"";
//                q.pop();
//            }
//        }
//        else
//        {
//            def+=s+L'\n';
//        }
//    }
//  fi.close();
//}




// Pre-order traversal for serialization
void serialize(std::wofstream& file,vector <wstring> &allWords,vector <vector <wstring>> &allDefinitions,vector <vector<wstring>> &allExamples) {

//    if ((root->isEndOfWord)&&(!root->definition.empty()))
//    {
//        file<<word<<"#";
//
//        for (const wstring& def : root->definition) {
//            file << def << L"|";
//        }
//        file<<endl;
//    }
//    for (int i = 0; i < 26; i++) {
//
//
//        if (root->children[i] != nullptr) {
//
//            wchar_t t=L'a'+i;
//
//            serialize(root->children[i], file,word+t);
//
//        }
//
//    }


   locale loc(locale(), new codecvt_utf8_utf16<wchar_t>);
   file.imbue(loc);
    int s=allWords.size();
    for (int i=0;i<s;i++)
    {
        file<<allWords[i]<<L'#';
        int ss=allDefinitions[i].size();
        if (allDefinitions[i].empty()) file<<"";
        else
        {
            for (int j=0;j<ss;j++)
        {

            file<<allDefinitions[i][j]<<L'|';
           file<<L"";

        }
        }

        file<<L'@';
        int sss=allExamples[i].size();
        if (allExamples[i].empty()) file<<"";
        else {
           for (int j=0;j<sss;j++)
        {
            file<<allExamples[i][j]<<L'|';
        }
        }

        file<<endl;
    }

}

// Serialize the trie
void saveTrie(const std::string& filename,vector <wstring> &allWords,vector <vector <wstring>> &allDefinitions,vector <vector<wstring>> &allExamples) {
    std::wofstream file;
    file.open(filename);
    serialize(file,allWords,allDefinitions,allExamples);
    file.close();
}


void loadTrie(const std::string& filename,vector<wstring> &allWords,vector <vector <wstring>> &allDefinitions,vector <vector<wstring>> &allExamples) {
    TrieNode* root = new TrieNode();
    std::wifstream file(filename);
      locale loc(locale(), new codecvt_utf8_utf16<wchar_t>);
   file.imbue(loc);
    wstring line;
    while (getline(file,line)) {

       int s=line.size();
       wstring word;
       vector <wstring> definitions;
       vector <wstring> examples;

       int i;
         for (i = 0; i < s; i++) {
            if (line[i] == L'#') {
                word = line.substr(0, i);
                break;
            }
        }

        // Extract the definitions
        if (i < s - 1) {  // Ensuring there is at least one character left after '#'
            wstring defAndExPart = line.substr(i + 1);
            size_t defDelimPos = defAndExPart.find(L'|');
            size_t exDelimPos = defAndExPart.find(L'@');

            while (defDelimPos != wstring::npos) {
                if (defAndExPart[0]==L'@') break;
                wstring definition = defAndExPart.substr(0, defDelimPos);
                definitions.push_back(definition);
                defAndExPart = defAndExPart.substr(defDelimPos + 1);
                defDelimPos = defAndExPart.find(L'|');
            }

          while (exDelimPos != wstring::npos) {
                exDelimPos = defAndExPart.find(L'|');
    wstring example = defAndExPart.substr(0, exDelimPos);
    if (!example.empty()) {
        if (example==L"@") example.clear();
        if (example[0] == L'@') {
            example = example.substr(1);  // Remove the "@" symbol
        }
        if (example[0]==L'|') example.clear();
    }
    if (!example.empty())
    examples.push_back(example);

    if (exDelimPos + 1 < defAndExPart.size()) {
        defAndExPart = defAndExPart.substr(exDelimPos + 1);
    } else {
        defAndExPart.clear();  // Clear the string to exit the loop
    }


}
        allDefinitions.push_back(definitions);
        allExamples.push_back(examples);
        allWords.push_back(word);
    }



}
file.close();
}

//TrieNode* find(TrieNode*& root, wstring word)
//{
//    if(root == nullptr) return nullptr;
//
//    TrieNode *cur = root;
//
//    for(int i = 0; i < word.size(); ++i)
//    {
//        if (!isalpha(word[i])) continue;
//        int index = tolower(word[i]) - L'a';
//        if(cur->children[index] == nullptr) return nullptr;
//
//        cur = cur->children[index];
//    }
//
//    if(cur->isEndOfWord) return cur;
//    return nullptr;
//}
//int main() {
//    _setmode(_fileno(stdin), _O_U16TEXT);
//
//    _setmode(_fileno(stdout), _O_U16TEXT);
//    //TrieNode* root = new TrieNode();
//
//    // Load dataset and construct the trie (assuming you have code for this)
//
//    // Save the trie
//    vector <vector <wstring>> allExamples;
//    vector <vector<wstring>> allDefinitions;
//    vector <wstring> allWords;
//    //readDatasetEngVie(allWords,allDefinitions,allExamples);
//    //readEngEng(allWords,allDefinitions,allExamples);
//    //saveTrie("trie_data.txt",allWords,allDefinitions,allExamples);
//
//    // Load the trie
//      vector <vector <wstring>> allExamples2;
//    vector <vector<wstring>> allDefinitions2;
//    vector <wstring> allWords2;
//     loadTrie("trie_data.txt",allWords2,allDefinitions2,allExamples2);
//
//    saveTrie("trie_data2.txt",allWords2,allDefinitions2,allExamples2);
//        wcout<<allWords2[2]<<endl;
//        int ss=allDefinitions2[2].size();
//        int sss=allExamples2[2].size();
//        for(int i=0;i<ss;i++)
//        {
//            wcout<<allDefinitions2[2][i]<<endl;
//        }
//        wcout<<ss<<endl;
//        for(int i=0;i<sss;i++)
//        {
//            wcout<<"**"<<allExamples2[2][i]<<endl;
//        }
//         wcout<<sss<<endl;
////
////    wstring word;
////    word=L"cow";
////    int s= find(root,word)->definition.size();
////    for (int i=0;i<s;i++)
////    {
////        wcout<<find(root,word)->definition[i]<<endl;
////    }
////     TrieNode* loadroot=loadTrie("trie_data.txt",allDefinitions,allWords);
////    int ss=find(loadroot,word)->definition.size();
////    for (int i=0;i<ss;i++)
////    {
////        wcout<<find(loadroot,word)->definition[i]<<endl;
////    }
////    int sized=allDefinitions.size();
////    for (int i=0;i<sized;i++)
////    {
////        int s3=allDefinitions[i].size();
////        wcout<<allWords[i]<<endl;
////        if (allDefinitions[i].empty()) wcout<<L"";
////        else{
////            for(int j=0;j<s3;j++)
////        {
////
////            wcout<<allDefinitions[i][j]<<endl;
////        }
////        }
////
////    }
//    return 0;
//}
