/*
Author:       Grant Hedley
Class: 	      CSI-281 - 01
Assignment: PA3 part 1
Date Assigned: 2/4/20
Due Date: 2/7/20
Description: bubble sort and insertion sort algorithems

Certification of Authenticity:
I certify that this is entirely my own work, except where I have given
fully-documented references to the work of others. I understand the definition
andconsequences of plagiarism and acknowledge that the assessor of this assignment
may, for the purpose of assessing this assignment:
- Reproduce this assignment and provide a copy to another member of academic staff; and/or
- Communicate a copy of this assignment to a plagiarism checking service(which may then
  retain a copy of this assignment on its database for the purpose of future plagiarism
  checking)
*/

#pragma once
#include <sstream>
#include <type_traits>
#include "functions.h"

using namespace std;


/*    pre: input array and a size
     post: the values of the array are sorted
  purpose: to sort the values of the array
*/
template <typename T>
void bubbleSort(T *array, int length)
{
   bool swaped = true;
   while (swaped)
   {
      swaped = false;
      for (int i = 0; i < length - 1; i++)
      {
         if (toLowercase(array[i]) > toLowercase(array[i + 1]))
         {
            swaped = true;
            T tmp = array[i];
            array[i] = array[i + 1];
            array[i + 1] = tmp;
         }
      }
   }
}

/*    pre: input array and a size
     post: the values of the array are sorted
  purpose: to sort the values of the array
*/
template <typename T>
void insertionSort(T *array, int length)
{
   for (int i = 1; i < length; i++)
   {
      T value = array[i];
      int j = i - 1;
      while (toLowercase(j) >= 0 && toLowercase(array[j]) > toLowercase(value))
      {
         array[j + 1] = array[j];
         j--;
      }
      array[j + 1] = value;
   }
}