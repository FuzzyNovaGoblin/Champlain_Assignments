/* ***       Author:  Grant Hedley
     *  Last Update:  April 24, 2020
     *        Class:  CSI-281
     *     Filename:  hashmap.h
     *
     *  Certification of Authenticity:
     *     I certify that this assignment is entirely my work.
     **********************************************************/
#ifndef HASHMAP_H
#define HASHMAP_H

#include <string>
#include "DynamicArray.h"
#include <math.h>

using namespace std;

#define SHIFT_V 20

const size_t PHI_MULTIPLYER = 11400714819323198485llu;
const short int BIT_SHIFT = 64 - SHIFT_V;
const int ARRAY_SIZE = pow(2, SHIFT_V);

class HashMap
{
private:
   DynamicArray<ElementNode<string, int> *> **mElements;
   DynamicArray<ElementNode<string, int> *> **arrHold;
   int iterator;

public:
   HashMap();
   ~HashMap();
   static size_t hashFunc(const string str);
   static size_t hashToFib(size_t hash);
   int &operator[](const string &str);
   int &get(const string &str, bool mustExist = false);
};

/*      Pre:  none
 *     Post:  the array of buckets is initialized
 *  Purpose:  Constructor
 **************************************************************/
HashMap::HashMap()
{
   mElements = new DynamicArray<ElementNode<string, int> *> *[ARRAY_SIZE]();
}

/*      Pre:  data, left pointer and right pointer
 *     Post:  heap data is deleted
 *  Purpose:  Deconstructor
 **************************************************************/
HashMap::~HashMap()
{
   delete[] mElements;
}

/*      Pre:  string hashes the string
 *     Post:  return hash value
 *  Purpose:  convert string to hash
 **************************************************************/
size_t HashMap::hashFunc(const string str)
{
   size_t sum;

   for (int i = 0; i < str.length(); i++)
   {
      sum += (str[i] * PHI_MULTIPLYER) ^ (sum >> (SHIFT_V));
   }

   return sum ^ (sum << SHIFT_V);
}

/*      Pre:  size_t: hash that needs to be maped to the array
 *     Post:  returns position in array
 *  Purpose:  to get the location in the array of a given hash to spread the
 *            values as evenly as posible
 **************************************************************/
size_t HashMap::hashToFib(size_t hash)
{
   return (hash * PHI_MULTIPLYER) >> BIT_SHIFT;
}

/*      Pre:  string key that is looking for, mustexist set true if should
              throw an error if key is not in map
 *     Post:  reference to value in hashmap
 *  Purpose:  acess values in the hash map and potentialy create them if they
 *            don't exist
 **************************************************************/
int &HashMap::get(const string &key, bool mustExist)
{
   arrHold = &(mElements[hashToFib(hashFunc(key))]);
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
   if (mustExist)
   {
      throw EXIT_FAILURE;
   }
   else
   {

      (*arrHold)->add(new ElementNode<string, int>(key));
      return (**arrHold)[iterator]->mValue;
   }
}
#endif