/*
Author:       Grant Hedley
Class: 	      CSI-281 - 01
Assignment:    PP2
Due Date:
Description:
A brief description of the purpose of the program.
Certification of Authenticity:
I certify that this is entirely my own work, except where I have given fully
-
documented references to the work of others. I und
erstand the definition and
consequences of plagiarism and acknowledge that the assessor of this assignment
may, for the purpose of assessing this assignment:
-
Reproduce  this  assignment  and  provide  a  copy  to  another  member  of
academic staff; and/or
-
Communicate a copy of this assignment to a plagiarism checking service
(which may then retain a copy of this assignment on its database for
the purpose of future plagiarism checking
*/

#pragma once
#include <iostream>

    using namespace std;

/*    pre: input 2 valus
     post: the variables have swaped values
  purpose: swapes the values of the variables
*/
template <typename T>
void swapValues(T &arg1, T &arg2)
{
   T tmp = arg1;
   arg1 = arg2;
   arg2 = tmp;
}

/*    pre: input 2 arrays and a size, the arrays must have the same length
     post: the values of the arrays are swapped
  purpose: to swape the values of the arrays
*/
template <typename T>
void swapValues(T *arg1, T *arg2, int size)
{
   for (int i = 0; i < size; i++)
   {
      T tmp = arg1[i];
      arg1[i] = arg2[i];
      arg2[i] = tmp;
   }
}

/*    pre: input 2 arrays and 2 array lengths
     post: the first x elements of the arrays are swaped where x is the length
           of the shortest array
  purpose: to swap the values of the arrays
*/
template <typename T>
void swapValues(T *arg1, T *arg2, int size1, int size2)
{
   int smallest = size1 < size2 ? size1 : size2;
   for (int i = 0; i < smallest; i++)
   {
      T tmp = arg1[i];
      arg1[i] = arg2[i];
      arg2[i] = tmp;
   }
}

/*    pre: input array and its length
     post: print the contents of the array
  purpose: to print the contents of the array
*/
template <typename T>
void printArr(T *arr, int length)
{
   for (int i = 0; i < length; i++)
   {
      if (i > 0)
         cout << ", ";
      cout << arr[i];
   }
   cout << endl;
}

/*    pre: input 2 opperands
     post: return sum of the 2 opperands
  purpose: add the 2 opperands
*/
template <typename T>
T sum(T arg1, T arg2)
{
   return arg1 + arg2;
}

/*    pre: input 3 opperands
     post: return sum of the 3 opperands
  purpose: add the 3 opperands
*/
template <typename T>
T sum(T arg1, T arg2, T arg3)
{
   return arg1 + arg2 + arg3;
}