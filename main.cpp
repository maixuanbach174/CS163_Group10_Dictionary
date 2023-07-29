
#include <iostream>
#include "readDatasetEngVie.hpp"
#include "Trie.h"

using namespace std;

int main()
{
 //*VieTrieNode *root = nullptr;

    //cout << VieInsert(root, L"Mai", "a flower") << endl;

    //cout << VieInsert(root, L"Mai Xuân Bách", "a name") << endl;
    //cout << VieInsert(root, L"Bóng đá", "a sport") << endl;

    //cout << "___________________________________________________" << endl;
    //int level = 0;
    //char str[20];
    //ofstream newfile;
    //serialize(root, str, level, newfile);
    //root = remove(root, L"Mai");
    //cout << VieFind(root, L"Mai") << endl;
    //cout << VieFind(root, L"tôi") << endl;
    //cout << VieFind(root, L"Mai Xuân Bách")->definition << endl;
    //cout << VieFind(root, L"Bóng đá")->definition << endl;

     //TrieNode *root = nullptr;

     //insert(root, "app", "sortware");
     //insert(root, "apple", "a fruit");
     //insert(root, "application", "ssss");

    TrieNode* root = new TrieNode();
    insert(root, L"Tin", L"Người");
    wofstream newfile;
    char str[26];
    int level = 0;
    serialize(root, str, level, newfile);
        //cout << find(root, L"application")->definition << endl;
    //cout << find(root, L"apple")->definition << endl; 
    //cout << find(root, L"app")<< endl;

     //cout << find(root, "car")<< endl;
     //cout << find(root, "chicken") << endl;
     //TrieNode* root=new TrieNode();

    //readDatasetEngVie(root);
    //wstring word;
    //getline(wcin,word);

    //if (find(root,word))
    //{
        //wcout<<find(root,word)->definition;
    //}
    //else wcout<<L"not found";





    return 0;
}