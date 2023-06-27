#include "Trie.h"
#include "MyHashMap.h"
#include <iostream>
using namespace std;

int main()
{
    MyHashMap <string, string> m(3);
    m.insert("A fruit which is red", "apple");
    m.insert("a common animal with four legs, especially kept by people as a pet or to hunt or guard things", "dog");
    m.insert("an animal", "cat");
    cout << m.erase("an animal") << endl;
    cout << m.erase("A fruit which is red") << endl;
    cout << m.erase("a common animal with four legs, especially kept by people as a pet or to hunt or guard things") << endl;
    cout << m.find("a common animal with four legs, especially kept by people as a pet or to hunt or guard things") << endl;
    cout << m.find("A fruit which is red") << endl;
    return 0;
}