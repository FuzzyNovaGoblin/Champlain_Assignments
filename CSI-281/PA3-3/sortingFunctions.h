/*
Author:       Grant Hedley
Class: 	      CSI-281 - 01
Assignment: PA3 part 3
Date Assigned: 2/4/20
Due Date: 2/14/20
Description: quick sort and merge sort algorithems

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

/*    pre: input array, lower bound and upper bound
     post: the values of the array are sorted
  purpose: to sort the values of the array
*/
template <typename T>
void quickSort(T array[], int lower, int upper)
{
  T tmp;
  int i = lower;
  int j = upper;

  T pivot = toLowercase(array[(lower + upper) / 2]);
  while (i <= j)
  {
    while (toLowercase(array[i]) < pivot)
    {
      i++;
    }
    while (toLowercase(array[j]) > pivot)
    {
      j--;
    }
    if (i <= j)
    {
      tmp = array[i];
      array[i] = array[j];
      array[j] = tmp;
      i++;
      j--;
    }
  }
  if (lower < j)
  {
    quickSort(array, lower, j);
  }
  if (i < upper)
  {
    quickSort(array, i, upper);
  }
}

/*    pre: input array, lower bound, middle element, and upper bound
     post: the values of the 2 sub arrays are merged and sorted
  purpose: to merge 2 sub arrays
*/
template <typename T>
void merge(T array[], int lower, int mid, int upper)
{
  int size1 = mid - lower + 1;
  int size2 = upper - mid;
  int i, j, k;

  T *tmp1 = new T[size1];
  T *tmp2 = new T[size2];

  for (i = 0; i < size1; i++)
  {
    tmp1[i] = array[lower + i];
  }
  for (j = 0; j < size2; j++)
  {
    tmp2[j] = array[mid + j + 1];
  }

  i = 0;
  j = 0;

  for (k = lower; k < upper && i < size1 && j < size2; k++)
  {
    if (toLowercase(tmp1[i]) <= toLowercase(tmp2[j]))
    {
      array[k] = tmp1[i];
      i++;
    }
    else
    {
      array[k] = tmp2[j];
      j++;
    }
  }

  while (i < size1)
  {
    array[k] = tmp1[i];
    i++;
    k++;
  }

  while (j < size2)
  {
    array[k] = tmp2[j];
    j++;
    k++;
  }

  delete[] tmp1;
  tmp1 = nullptr;
  delete[] tmp2;
  tmp2 = nullptr;
}

/*    pre: input array, lower bound, and upper bound
     post: the values of the array are sorted
  purpose: to sort the values of the array
*/
template <typename T>
void mergeSort(T array[], int lower, int upper)
{
  if (lower < upper)
  {
    int mid = (lower + upper) / 2;
    mergeSort(array, lower, mid);
    mergeSort(array, mid + 1, upper);
    merge(array, lower, mid, upper);
  }
}

/*    pre: input array and a size
     post: the values of the array are sorted
  purpose: to sort the values of the array
*/
template <typename T>
void cycleSort(T array[], int length)
{
  T item, tmp;
  int pos;
  for (int cycleStart = 0; cycleStart < length - 1; cycleStart++)
  {
    item = array[cycleStart];
    pos = cycleStart;

    for (int i = cycleStart; i < length; i++)
    {
      if (toLowercase(array[i]) < toLowercase(item))
      {
        pos++;
      }
    }
    if (pos == cycleStart)
      continue;

    while (toLowercase(item) == toLowercase(array[pos]))
    {
      pos++;
    }

    tmp = array[pos];
    array[pos] = item;
    item = tmp;

    while (pos != cycleStart)
    {
      pos = cycleStart;
      for (int i = cycleStart + 1; i < length; i++)
      {
        if (toLowercase(array[i]) < toLowercase(item))
          pos++;
      }
      while (toLowercase(item) == toLowercase(array[pos]))
        pos++;

      tmp = array[pos];
      array[pos] = item;
      item = tmp;
    }
  }
}