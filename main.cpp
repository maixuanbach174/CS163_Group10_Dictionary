#include "readDatasetEngVie.hpp"
using namespace std;

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

    deallocate(root);



    return 0;
}