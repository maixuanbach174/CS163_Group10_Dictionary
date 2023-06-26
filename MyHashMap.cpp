#ifndef MYHASHMAP_CPP
#define MYHASHMAP_CPP

#include "MyHashMap.h"

template<class K, class V>
HashNode<K, V>::HashNode(K nkey, V nval)
{
    key = nkey;
    val = nval;
}

template<class K, class V>
int MyHashMap<K, V>::hash(K nkey)
{
    int sum = 0;
    for(int i = 0; nkey[i] != '\0'; ++i)
    {
        sum += int(nkey[i]);
    }
    return sum;
}

template<class K, class V>
MyHashMap<K, V>::MyHashMap(int cap)
{
    capacity = cap;
    arr = new HashNode<K, V>* [capacity];
    si = 0;
    for(int i = 0; i < capacity; ++i) arr[i] = nullptr;
    dummy = new HashNode<K, V>("", "");
}

template<class K, class V>
MyHashMap<K, V>::~MyHashMap()
{   
    for(int i = 0; i < capacity; ++i)
    {
        if(arr[i] != nullptr) delete arr[i];
    }

    delete [] arr;
}

template<class K, class V>
HashNode<K, V>* MyHashMap<K, V>::find(K nkey)
{
    int index = hash(nkey) % capacity;
    int counter = 0;

    while(arr[index] != nullptr && arr[index]->key != nkey)
    {
        if(counter++ > capacity) return nullptr;
        index++;
        index %= capacity;
    }

    if(arr[index] == nullptr) return nullptr;

    return arr[index];
}

template<class K, class V>
bool MyHashMap<K, V>::insert(K nkey, V nval)
{

    int index = hash(nkey) % capacity;

    while(arr[index] != nullptr && arr[index]->key != nkey && arr[index]->key != "")
    {
        index++;
        index %= capacity;
    }

    if(arr[index] == nullptr || arr[index]->key == "")
    {
        arr[index] = new HashNode<K, V>(nkey, nval);
        si++;
        return true;
    }
    
    return false;
}

template<class K, class V>
V MyHashMap<K, V>::erase(K nkey)
{
    HashNode<K, V> *tempptr = find(nkey);
    if(tempptr == nullptr) return "";
    
    V temp = tempptr->val;

    tempptr->key = "";
    tempptr->val = "";
    si--;

    return temp;
}

template<class K, class V>
int MyHashMap<K, V>::size()
{
    return si;
}

template<class K, class V>
bool MyHashMap<K, V>::empty()
{
    return si == 0;
}

#endif