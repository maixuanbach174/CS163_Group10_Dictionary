#ifndef MYHASHMAP_H
#define MYHASHMAP_H

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