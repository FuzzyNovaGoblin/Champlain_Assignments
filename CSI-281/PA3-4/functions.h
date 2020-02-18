/*
Author:       Grant Hedley
Class: 	      CSI-281 - 01
Assignment: PA3
Date Assigned: 2/14/20
Due Date: 2/28/20
Description: quick sort and merge sort algorithems

Certification of Authenticity:
I certify that this is entirely my own work, except where I have given
fully-documented references to the work of others. I understand the definition
andconsequences of plagiarism and acknowledge that the assessor of this assignment
may, for the purpose of assessing this assignment:
- Reproduce this assignment and provide a copy to another member of academic staff; and/or
- Communicate a copy of this assignment to a plagiarism checking service(which may then
  retain a copy of this assignment on its database for the purpose of
  checking)
*/

#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include <iostream>
#include <fstream>
#include <sstream>
#include <type_traits>


using namespace std;

/*    pre: input array and a size
     post: returns array's contents as a string
  purpose: turns the array into the string
*/
template <typename T>
string arrayToString(const T arr, int length)
{
   stringstream ss;
   for (int i = 0; i < length; i++)
   {
      if (i == 0)
         ss << '[';
      else
         ss << ", ";

      ss << arr[i];

      if (i == length - 1)
         ss << "]";
   }
   return ss.str();
}

/*    pre: input array and a size
     post: outputs array to console
  purpose: to print the array
*/
template <typename T>
void printArray(const T arr, int length)
{
   cout << arrayToString<T>(arr, length) << endl;
}

/*    pre: input should be string or char
     post: return the string or char as lowercase; or just the input value
  purpose: to elimenate capitals in strings and chars
*/
template <typename T>
T toLowercase(T val)
{
   return val;
}

char toLowercase(char c);
string toLowercase(string str);

void readFileToArray(int array[], int size, string fileName);

#endif