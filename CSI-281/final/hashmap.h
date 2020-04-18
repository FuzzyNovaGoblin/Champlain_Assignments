#ifndef HASHMAP_H
#define HASHMAP_H
#define SHIFT_V 20

#include <string>
#include "DynamicArray.h"
#include <math.h>
#include <functional>

using namespace std;

const size_t PHI_MULTIPLYER = 11400714819323198485llu;
const short int BIT_SHIFT = 64 - SHIFT_V;
const int ARRAY_SIZE = pow(2, SHIFT_V);
// const int ARRAY_SIZE = 1048576;

class HashMap
{
private:
   DynamicArray<ElementNode<string, int>*> **mElements;
   DynamicArray<ElementNode<string, int>*> **arrHold;
   int iterator;
  // int loc;
   // int iSize;
   //TODO: remove this
   //int tst = 0;


public:
   HashMap();
   ~HashMap();
   // static int hash(string str);
   std::hash<string> strHash;
   static size_t hashToFib(size_t _hash);
   int& operator[](const string& str);
   int& get(const string& str);
};
HashMap::HashMap(){
   mElements = new DynamicArray<ElementNode<string,int>*>*[ARRAY_SIZE];
}

// int HashMap::hash(string str)
// {
//    int sum = 0;
//    for (int i = 0; i < str.length(); i++)
//    {
//       sum += (int)(str[i]) * (i + 1) *(i * str.length());
//    }
//    return sum;
// }

size_t HashMap::hashToFib(size_t hash){
   return (hash * PHI_MULTIPLYER) >> BIT_SHIFT;
}

// int& MyHashmap::operator[](const string& key){
//    return mElements[hashToFib(hash(key))].get(key);
// }

int& HashMap::get(const string& key){
   // loc = hashToFib(hash(key));
   //cout <<hashToFib(hash(key))<< endl;
   arrHold = &(mElements[hashToFib(strHash(key))]);
   if (*arrHold == NULL)
   {
      *arrHold = new DynamicArray<ElementNode<string, int> *>;
   }
   for (iterator = 0; iterator < (*arrHold)->size(); iterator++)
   {

      if ((**arrHold)[iterator]->mKey == key)
      {
         return (**arrHold)[iterator]->mValue;
      }
   }
   (*arrHold)->add(new ElementNode<string, int>(key));
   return (**arrHold)[iterator]->mValue;
}

#endif