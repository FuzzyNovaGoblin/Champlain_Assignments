#ifndef HASHMAP_H
#define HASHMAP_H

// #include <string>

// template <typename K, typename T>
// class Hashmap
// {
// private:
//    T *elements;
//    Hash()

// public:
//    Hashmap();
//    ~Hashmap();
// };

// #endif

#include <string>
#include "bst.h"
using namespace std;


class MyHashmap
{
private:
   BST<string, int> **mElements;

public:
   MyHashmap();
   ~MyHashmap();
   static int hash(string str);
   static size_t hashToFib(int hash);
   int& operator[](const string& str);
   int& get(const string& str);
};
MyHashmap::MyHashmap(){
   mElements = new BST<string,int>*[1048576];
}

int MyHashmap::hash(string str)
{
   int sum = 0;
   for (int i = 0; i < str.length(); i++)
   {
      sum += (int)(str[i]) * (i + 1) * (i * str.length()) ;
   }
   return sum;
}

size_t MyHashmap::hashToFib(int hash){
   return (hash * 11400714819323198485llu) >> 45;
}

// int& MyHashmap::operator[](const string& key){
//    return mElements[hashToFib(hash(key))].get(key);
// }

int& MyHashmap::get(const string& key){
   if (mElements[hashToFib(hash(key))] == nullptr)
   {
      mElements[hashToFib(hash(key))] = new BST<string, int>;
      return mElements[hashToFib(hash(key))]->get(key);
   }
   return mElements[hashToFib(hash(key))]->get(key);
}

#endif