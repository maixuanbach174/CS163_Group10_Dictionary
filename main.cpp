#include <iostream>

#include "VieTrie.h"
using namespace std;

int main()
{
    VieTrieNode *root = nullptr;

    cout << VieInsert(root, L"Mai", "a flower") << endl;

    cout << VieInsert(root, L"Mai Xuân Bách", "a name") << endl;
    cout << VieInsert(root, L"Bóng đá", "a sport") << endl;

    cout << "___________________________________________________" << endl;
    root = remove(root, L"Mai");
    cout << VieFind(root, L"Mai") << endl;
    cout << VieFind(root, L"tôi") << endl;
    cout << VieFind(root, L"Mai Xuân Bách")->definition << endl;
    cout << VieFind(root, L"Bóng đá")->definition << endl;

    // TrieNode *root = nullptr;

    // insert(root, "app", "sortware");
    // insert(root, "apple", "a fruit");
    // insert(root, "application", "ssss");

    // remove(root, "apple");
    // remove(root, "app");

    // cout << find(root, "application")->definition << endl;
    // cout << find(root, "apple") << endl; 
    // cout << find(root, "app") << endl;

    // cout << find(root, "car") << endl;
    // cout << find(root, "chicken") << endl;



    return 0;
}