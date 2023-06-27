#ifndef MYHASHMAP_H
#define MYHASHMAP_H

#include <typeinfo>
#include <string>
using namespace std;

template<class K, class V>
class HashNode
{
    public:
    K key;
    V val;
    HashNode(K nkey, V nval);
};

template<class K, class V>
class MyHashMap
{
private:
    HashNode<K, V>** arr;
    int capacity;
    int si;
    HashNode<K, V>* dummy;
private:
    int hashfunction(string nkey);
    int hashfunction(int nkey);
    int hash(K nkey);
public:
    MyHashMap(int cap);
    ~MyHashMap();
    HashNode<K, V>* find(K nkey);
    bool insert(K nkey, V nval); 
    V erase(K nkey);
    int size();
    bool empty();
};
#include "MyHashMap.cpp"

#endif