#ifndef TREE_HPP
#define TREE_HPP 

#include <string>
using namespace std;

class Tree
{
public:
    virtual bool insert(wstring word, wstring definition);
    virtual Tree* find(wstring word);
    virtual Tree* remove(wstring word);
};

#endif