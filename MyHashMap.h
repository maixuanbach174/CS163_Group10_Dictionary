#ifndef MYHASHMAP_H
#define MYHASHMAP_H

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
private:
    int hash(K nkey);
public:
    MyHashMap(int cap);
    ~MyHashMap();
    HashNode<K, V>* find(K nkey);
    bool insert(K nkey, V nval); 
    HashNode<K, V>* erase(K nkey);
    int size();
    bool empty();
};
#include "MyHashMap.cpp"

#endif