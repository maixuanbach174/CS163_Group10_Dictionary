#include "Trie.h"
#include "MyHashMap.cpp"
#include <iostream>
using namespace std;

int main()
{
    MyHashMap<string, string> m(3);
    m.insert("an animal", "dog");
    m.insert("a drink", "coke");
    m.insert("a sport", "football");
    cout << m.insert("no insert", "non_sert") << endl;

    cout << m.find("an animal")->val << endl;
    cout << m.find("a drink")->val << endl;
    cout << m.find("a sport")->val << endl;
    cout << m.find("nos insert") << endl;

    cout << "_________________________________" << endl;

    cout << m.erase("an animal")->val << endl;
    cout << m.erase("an aninmal") << endl;
    cout << m.find("an animal") << endl;
    cout << m.find("a sport")->val << endl;
    cout << m.find("a drink")->val << endl;

    cout << "__________________________________" << endl;

    m.erase("a drink");
    cout << m.find("a sport")->val << endl;
    cout << m.find("a drink") << endl;

    cout << "__________________________________" << endl;
    cout << m.size() << endl;
    cout << m.empty() << endl;

    return 0;
}