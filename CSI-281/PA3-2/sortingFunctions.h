/*
Author:       Grant Hedley
Class: 	      CSI-281 - 01
Assignment: PA3 part 2
Date Assigned: 2/4/20
Due Date: 2/11/20
Description: selection sort and shell sort algorithems

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
void selectionSort(T array[], int length)
{
   int minIndex;
   T tmp;
   for (int i = 0; i < length - 1; i++)
   {
      minIndex = i;
      for (int j = i + 1; j < length; j++)
      {
         if (toLowercase(array[j]) < toLowercase(array[minIndex]))
            minIndex = j;
      }
      if (minIndex != i)
      {
         tmp = array[minIndex];
         array[minIndex] = array[i];
         array[i] = tmp;
      }
   }
}

/*    pre: input array and a size
     post: the values of the array are sorted
  purpose: to sort the values of the array
*/
template <typename T>
void bubbleSort(T *array, int length)
{
   bool swaped = true;
   T tmp;
   while (swaped)
   {
      swaped = false;
      for (int i = 0; i < length - 1; i++)
      {
         if (toLowercase(array[i]) > toLowercase(array[i + 1]))
         {
            swaped = true;
            tmp = array[i];
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
void shellSort(T array[], int length)
{
   int gap = length / 2;
   T tmp;
   while (gap > 1)
   {
      for (int i = 0; i < length - 1 - gap; i++)
      {
         if (toLowercase(array[i]) > toLowercase(array[i + gap]))
         {
            tmp = array[i];
            array[i] = array[i + gap];
            array[i + gap] = tmp;
         }
      }
      gap = gap / 2;
   }
   bubbleSort(array, length);
}