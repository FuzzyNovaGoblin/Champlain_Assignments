// Author: Grant Hedley
// Class: CSI-240 - Advanced Programming
// Assignment: 240 Final
// Description: write a dynamic array class and read in words from a file to fill the array, also the user can set the size of the array
// Certification of Authenticity :
// I  certify  that  this  is  entirely  my  own  work, except  where  I  have  given fully
// documented  references  to  the  work  of  others. I  understand  the
// definition and consequences of plagiarism and acknowledge that the assessor
// of this assignment may, for the purpose of assessing this assignment:
// - Reproduce  this  assignment and provide  a  copy  to  another  member  of
// academic staff; and/or
// - Communicate  a  copy  of  this  assignment  to  a  plagiarism  checking
// service(which  may  then  retain  a  copy  of  this  assignment  on  its
// database for the purpose of future plagiarism checking)

#pragma once
#include <stdexcept>
#include <iostream>
#include <cstdlib>
#include <sstream>

using namespace std;

template <class T>
class DynamicArray
{
private:
   T *arr;
   int count;
   int arraycount;

public:
   DynamicArray()
   {
      count = 0;
      arraycount = 10;
      arr = new T[arraycount];
   }

   DynamicArray(const DynamicArray &d)
   {
      count = d.count;
      arraycount = d.arraycount;
      arr = new T[arraycount];
      for (int i = 0; i < d.count; i++)
      {
         arr[i] = d.arr[i];
      }
   }

   ~DynamicArray()
   {
      delete[] arr;
      arr = nullptr;
   }

   int size() const
   {
      return count;
   }

   T &operator[](int i) const
   {
      if (i >= count || i < 0)
      {
         throw invalid_argument("index out of bounds");
      }

      return arr[i];
   }

   string getPrintInfo() const
   {
      stringstream ss;
      ss << "The current capacity of the array is: " << arraycount;
      ss << "\nThe current size of the array is: " << count;
      ss << "\nArray content:\n";

      for (int i = 0; i < count; i++)
      {
         ss << (*this)[i] << endl;
      }

      return ss.str();
   }

   void add(T item)
   {
      if (count >= arraycount)
      {
         T *tmp = new T[count];
         for (int i = 0; i < count; i++)
         {
            tmp[i] = arr[i];
         }

         arraycount *= 2;
         delete[] arr;
         arr = new T[arraycount];
         for (int i = 0; i < count; i++)
         {
            arr[i] = tmp[i];
         }
      }
      arr[count++] = item;
   }

   void resizeArray(int newSize)
   {
      DynamicArray tmp = DynamicArray(*this);
      delete[] arr;
      arraycount = newSize;
      if (tmp.count > arraycount)
         count = arraycount;
      else
         count = tmp.count;
      arr = new T[arraycount];

      for (int i = 0; i < count; i++)
      {
         arr[i] = tmp.arr[i];
      }
   }

   T remove(int i)
   {
      for (int i = 0; i < arraycount - 1;)
         arr[i] = arr[++i];
   }
};