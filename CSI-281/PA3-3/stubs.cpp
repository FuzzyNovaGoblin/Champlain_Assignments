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

#include "stubs.h"

using namespace std;

/*    pre: none
     post: prints an unsorted and sorted list
  purpose: test quick sort function with array of ints
*/
void quickSortTest1()
{
   cout << "quick sort Test1:\n";
   int arr[] = {43, 43, 25, 64, 43, 5, 7, 565, 3, -64};
   printArray(arr, 10);
   quickSort(arr, 0, 9);
   printArray(arr, 10);
   cout << "\n\n";
}

/*    pre: none
     post: prints an unsorted and sorted list
  purpose: test quick sort function with array of strings
*/
void quickSortTest2()
{
   cout << "quick sort Test2:\n";
   string arr[] = {"2431", "hi", "had", "baby"};
   printArray(arr, 4);
   quickSort(arr, 0, 3);
   printArray(arr, 4);
   cout << "\n\n";
}

/*    pre: none
     post: prints an unsorted and sorted list
  purpose: test quick sort function with array of chars
*/
void quickSortTest3()
{
   cout << "quick sort Test3:\n";
   char arr[] = {'f', 's', 'i', 'a', 'l', 'p', 'e'};
   printArray(arr, 4);
   quickSort(arr, 0, 3);
   printArray(arr, 4);
   cout << "\n\n";
}

/*    pre: none
     post: prints an unsorted and sorted list
  purpose: test quick sort function with array of strings w/ capitals
*/
void quickSortTest4()
{
   cout << "quick sort Test4:\n";
   string arr[] = {"2431", "Hi", "had", "bAby"};
   printArray(arr, 4);
   quickSort(arr, 0, 3);
   printArray(arr, 4);
   cout << "\n\n";
}

/*    pre: none
     post: prints an unsorted and sorted list
  purpose: test quick sort function with array of chars with capitals
*/
void quickSortTest5()
{
   cout << "quick sort Test5:\n";
   char arr[] = {'f', 's', 'I', 'a', 'L', 'p', 'E'};
   printArray(arr, 4);
   quickSort(arr, 0, 3);
   printArray(arr, 4);
   cout << "\n\n";
}

/*    pre: none
     post: prints an unsorted and sorted list
  purpose: test merge sort function with array of ints
*/
void mergeSortTest1()
{
   cout << "merge sort Test1:\n";
   int arr[] = {43, 43, 25, 64, 43, 5, 7, 565, 3, -64};
   printArray(arr, 10);
   mergeSort(arr, 0, 9);
   printArray(arr, 10);
   cout << "\n\n";
}

/*    pre: none
     post: prints an unsorted and sorted list
  purpose: test merge sort function with array of strings
*/
void mergeSortTest2()
{
   cout << "merge sort Test2:\n";
   string arr[] = {"2431", "hi", "had", "baby"};
   printArray(arr, 4);
   mergeSort(arr, 0, 3);
   printArray(arr, 4);
   cout << "\n\n";
}

/*    pre: none
     post: prints an unsorted and sorted list
  purpose: test merge sort function with array of chars
*/
void mergeSortTest3()
{
   cout << "merge sort Test3:\n";
   char arr[] = {'f', 's', 'i', 'a', 'l', 'p', 'e'};
   printArray(arr, 4);
   mergeSort(arr, 0, 3);
   printArray(arr, 4);
   cout << "\n\n";
}

/*    pre: none
     post: prints an unsorted and sorted list
  purpose: test merge sort function with array of strings w/ capitals
*/
void mergeSortTest4()
{
   cout << "merge sort Test4:\n";
   string arr[] = {"2431", "Hi", "had", "bAby"};
   printArray(arr, 4);
   mergeSort(arr, 0, 3);
   printArray(arr, 4);
   cout << "\n\n";
}

/*    pre: none
     post: prints an unsorted and sorted list
  purpose: test merge sort function with array of chars w/ capitals
*/
void mergeSortTest5()
{
   cout << "merge sort Test5:\n";
   char arr[] = {'f', 's', 'I', 'a', 'L', 'p', 'E'};
   printArray(arr, 4);
   mergeSort(arr, 0, 3);
   printArray(arr, 4);
   cout << "\n\n";
}

/*    pre: none
     post: prints an unsorted and sorted list
  purpose: test cycle sort function with array of ints
*/
void cycleSortTest1()
{
   cout << "cycle sort Test1:\n";
   int arr[] = {43, 43, 25, 64, 43, 5, 7, 565, 3, -64};
   printArray(arr, 10);
   cycleSort(arr, 10);
   printArray(arr, 10);
   cout << "\n\n";
}

/*    pre: none
     post: prints an unsorted and sorted list
  purpose: test cycle sort function with array of strings
*/
void cycleSortTest2()
{
   cout << "cycle sort Test2:\n";
   string arr[] = {"2431", "hi", "had", "baby"};
   printArray(arr, 4);
   cycleSort(arr, 4);
   printArray(arr, 4);
   cout << "\n\n";
}

/*    pre: none
     post: prints an unsorted and sorted list
  purpose: test cycle sort function with array of chars
*/
void cycleSortTest3()
{
   cout << "cycle sort Test3:\n";
   char arr[] = {'f', 's', 'i', 'a', 'l', 'p', 'e'};
   printArray(arr, 4);
   cycleSort(arr, 4);
   printArray(arr, 4);
   cout << "\n\n";
}

/*    pre: none
     post: prints an unsorted and sorted list
  purpose: test cycle sort function with array of strings w/ capitals
*/
void cycleSortTest4()
{
   cout << "cycle sort Test4:\n";
   string arr[] = {"2431", "Hi", "had", "bAby"};
   printArray(arr, 4);
   cycleSort(arr, 4);
   printArray(arr, 4);
   cout << "\n\n";
}

/*    pre: none
     post: prints an unsorted and sorted list
  purpose: test cycle sort function with array of chars w/ capitals
*/
void cycleSortTest5()
{
   cout << "cycle sort Test5:\n";
   char arr[] = {'f', 's', 'I', 'a', 'L', 'p', 'E'};
   printArray(arr, 4);
   cycleSort(arr, 4);
   printArray(arr, 4);
   cout << "\n\n";
}
