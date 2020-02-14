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
#include "functions.h"
#include "sortingFunctions.h"

using namespace std;

class TestClass
{
private:
   int mValue;

public:
   /*    pre: none
        post: saves mValue to 0
     purpose: default constructor
   */
   TestClass()
   {
      mValue = 0;
   }
   /*    pre: input int
        post: saves input to mValue in object
     purpose: construct TestClass object
   */
   TestClass(int v)
   {
      mValue = v;
   }

   /*    pre: input TestClass object
        post: bool first object mValue is less than second objects mValue
     purpose: compare 2 testclass objects
   */
   friend ostream& operator<<(std::ostream &stream, const TestClass &test){
      stream << "{TestClassObj: " << test.mValue << '}';
      return stream;
   }

   /*    pre: input TestClass object
        post: bool first object mValue is less than second objects mValue
     purpose: compare 2 testclass objects
   */
   bool operator<(const TestClass &otherObj)
   {
      return mValue < otherObj.mValue;
   }

   /*    pre: input TestClass object
        post: bool first object mValue is less than or equal to the second objects mValue
     purpose: compare 2 testclass objects
   */
   bool operator<=(const TestClass &otherObj)
   {
      return mValue <= otherObj.mValue;
   }

   /*    pre: input TestClass object
        post: bool first object mValue is greater than second objects mValue
     purpose: compare 2 testclass objects
   */
   bool operator>(const TestClass &otherObj)
   {
      return mValue > otherObj.mValue;
   }

   /*    pre: input TestClass object
        post: bool first object mValue is greater than or equal to the second objects mValue
     purpose: compare 2 testclass objects
   */
   bool operator>=(const TestClass &otherObj)
   {
      return mValue >= otherObj.mValue;
   }

   /*    pre: input TestClass object
        post: bool first object mValue is equal to the second objects mValue
     purpose: compare 2 testclass objects
   */
   bool operator==(const TestClass &otherObj)
   {
      return mValue == otherObj.mValue;
   }
};

void quickSortTest1();
void quickSortTest2();
void quickSortTest3();
void quickSortTest4();
void quickSortTest5();
void quickSortTest6();

void mergeSortTest1();
void mergeSortTest2();
void mergeSortTest3();
void mergeSortTest4();
void mergeSortTest5();
void mergeSortTest6();

void cycleSortTest1();
void cycleSortTest2();
void cycleSortTest3();
void cycleSortTest4();
void cycleSortTest5();
void cycleSortTest6();
