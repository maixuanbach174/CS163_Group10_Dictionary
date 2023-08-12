#include "Trie.h"
#include <bits/stdc++.h>

using namespace std;
vector <wstring> getRandomDefintion(vector <vector <wstring>> definition)
{
    srand(time(0));
    int s=definition.size();
    int randomIndex=rand()%s;
    return definition[randomIndex];


}

