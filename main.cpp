#include "Trie.h"
#include "MyHashMap.h"
#include <iostream>
#include <io.h>
#include <fcntl.h>
using namespace std;

int main()
{
    // MyHashMap<string, string> m(3);
    // m.insert("an animal", "dog");
    // m.insert("a drink", "coke");
    // m.insert("a sport", "football");
    // cout << m.insert("no insert", "non_sert") << endl;

    // cout << m.find("an animal")->val << endl;
    // cout << m.find("a drink")->val << endl;
    // cout << m.find("a sport")->val << endl;
    // cout << m.find("nos insert") << endl;

    // cout << "_________________________________" << endl;

    // cout << m.erase("an animal")->val << endl;
    // cout << m.erase("an aninmal") << endl;
    // cout << m.find("an animal") << endl;
    // cout << m.find("a sport")->val << endl;
    // cout << m.find("a drink")->val << endl;

    // cout << "__________________________________" << endl;

    // m.erase("a drink");
    // cout << m.find("a sport")->val << endl;
    // cout << m.find("a drink") << endl;

    // cout << "__________________________________" << endl;
    // cout << m.size() << endl;
    // cout << m.empty() << endl;

    _setmode(_fileno(stdin), _O_U8TEXT);
    _setmode(_fileno(stdout), _O_U8TEXT);

    // wchar_t c = L'ă';
    // wcout <<  c << endl;
    MyHashMap<string, wstring> m(3);
    m.insert("a book", L"sách");
    m.insert("chicken", L"gà");

    wcout << m.find("a book")->val << endl;
    wcout << m.find("chicken")->val << endl;

    return 0;
}