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
  retain a copy of this assignment on its database for the purpose of future plagiarism
  checking)
*/

#include "functions.h"

using namespace std;

/*    pre: input char
     post: return the char as lowercase;
  purpose: change capital char to lowercase
*/
char toLowercase(char c)
{
   if (c >= 'A' && c <= 'Z')
      return c + 32;

   return c;
}

/*    pre: input strng
     post: return the string as lowercase;
  purpose: to elimenate capitals in strings
*/
string toLowercase(string str)
{
   stringstream ss;
   for (int i = 0; i < str.length(); i++)
   {
      ss << toLowercase(str[i]);
   }
   return ss.str();
}

void readFileToArray(int array[], int size, string fileName){
   ifstream file(fileName);
   for (int i = 0; i < size; i++)
   {
      file >> array[i];
   }
   file.close();
}