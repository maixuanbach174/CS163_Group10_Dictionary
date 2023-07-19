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
#define ALPHABET_SIZE 28
using namespace std;


struct TrieNode
{
    TrieNode *children[ALPHABET_SIZE];
    bool isEndOfWord;
    wstring definition;
    TrieNode();
};
TrieNode::TrieNode()
{
    for(int i = 0; i < ALPHABET_SIZE; ++i) children[i] = nullptr;
    isEndOfWord = false;
    definition = L"";
}

TrieNode* find(TrieNode*& root, wstring word)
{
    if(root == nullptr) return nullptr;

    TrieNode *cur = root;

    for(int i = 0; i < word.size(); ++i)
    {
        if (!isalpha(word[i])) continue;
        int index = tolower(word[i]) - L'a';
        if(cur->children[index] == nullptr) return nullptr;

        cur = cur->children[index];
    }

    if(cur->isEndOfWord) return cur;
    return nullptr;
}

bool insert(TrieNode*& root, wstring word, wstring def)
{
    if(root == nullptr) root = new TrieNode();
    TrieNode* pCrawl = root;
    for (int i = 0; i < word.length(); i++)
    {
        if (!isalpha(word[i])) continue;
        int index = word[i] - L'a';
        if (!pCrawl->children[index])
            pCrawl->children[index] = new TrieNode();

        pCrawl = pCrawl->children[index];
    }
    pCrawl->isEndOfWord = true;
    pCrawl->definition = def;
    return pCrawl->isEndOfWord;
}

bool isEmpty(TrieNode* root)
{
    for (int i = 0; i < ALPHABET_SIZE; i++)
        if (root->children[i])
            return false;
    return true;
}

TrieNode* removefunction(TrieNode* root, string word, int depth)
{

    if (!root)
        return nullptr;
    if (word.size() == depth)
    {
        if (root->isEndOfWord)
        {
            root->isEndOfWord = false;
        }

        if (isEmpty(root))
        {
            delete(root);
            root = nullptr;
        }
        return root;
    }
    int index = word[depth] - L'a';
    root->children[index] = removefunction(root->children[index], word, depth + 1);
   if (isEmpty(root) && root->isEndOfWord == false) {
        delete (root);
        root = nullptr;
    }
   return root;


}

TrieNode* remove(TrieNode* root, string word)
{
    int depth = 0;
    return removefunction(root, word, depth);
}


void deallocate(TrieNode* root)
{
    if(root == nullptr) return;
    for(int i = 0; i < ALPHABET_SIZE; ++i)
    {
        deallocate(root->children[i]);
    }

    delete root;
}

void readDatasetEngVie(TrieNode* root)
{
     _setmode(_fileno(stdin), _O_U16TEXT);
  _setmode(_fileno(stdout), _O_U16TEXT);
   locale loc(locale(), new codecvt_utf8_utf16<wchar_t>);
   wifstream fi;
 // wofstream fo;
  fi.open("english-vietnamese.txt");
  fi.imbue(loc);
  wofstream fo("test.txt");
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

int main()
{

    TrieNode* root=new TrieNode();

    readDatasetEngVie(root);
    wstring word;
    getline(wcin,word);

    if (find(root,word))
    {
        wcout<<find(root,word)->definition;
    }
    else wcout<<L"not found";



    return 0;
}
