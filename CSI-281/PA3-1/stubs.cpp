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

#include "stubs.h"

using namespace std;

/*    pre: none
     post: prints an unsorted and sorted list
  purpose: test bubble sort function with array of ints
*/
void bubbleSortTest1()
{
   cout << "bubble sort Test1:\n";
   int arr[] = {43, 43, 25, 64, 43, 5, 7, 565, 3, -64};
   printArray(arr, 10);
   bubbleSort(arr, 10);
   printArray(arr, 10);
   cout << "\n\n";
}

/*    pre: none
     post: prints an unsorted and sorted list
  purpose: test bubble sort function with array of strings
*/
void bubbleSortTest2()
{
   cout << "bubble sort Test2:\n";
   string arr[] = {"2431", "hi", "had", "baby"};
   printArray(arr, 4);
   bubbleSort(arr, 4);
   printArray(arr, 4);
   cout << "\n\n";
}

/*    pre: none
     post: prints an unsorted and sorted list
  purpose: test bubble sort function with array of chars
*/
void bubbleSortTest3()
{
   cout << "bubble sort Test3:\n";
   char arr[] = {'f', 's', 'i', 'a', 'l', 'p', 'e'};
   printArray(arr, 4);
   bubbleSort(arr, 4);
   printArray(arr, 4);
   cout << "\n\n";
}

/*    pre: none
     post: prints an unsorted and sorted list
  purpose: test bubble sort function with array of strings w/ capitals
*/
void bubbleSortTest4()
{
   cout << "bubble sort Test4:\n";
   string arr[] = {"2431", "Hi", "had", "bAby"};
   printArray(arr, 4);
   bubbleSort(arr, 4);
   printArray(arr, 4);
   cout << "\n\n";
}

/*    pre: none
     post: prints an unsorted and sorted list
  purpose: test bubble sort function with array of chars with capitals
*/
void bubbleSortTest5()
{
   cout << "bubble sort Test5:\n";
   char arr[] = {'f', 's', 'I', 'a', 'L', 'p', 'E'};
   printArray(arr, 4);
   bubbleSort(arr, 4);
   printArray(arr, 4);
   cout << "\n\n";
}

/*    pre: none
     post: prints an unsorted and sorted list
  purpose: test insertion sort function with array of ints
*/
void insertionSortTest1()
{
   cout << "insertion sort Test1:\n";
   int arr[] = {43, 43, 25, 64, 43, 5, 7, 565, 3, -64};
   printArray(arr, 10);
   insertionSort(arr, 10);
   printArray(arr, 10);
   cout << "\n\n";
}

/*    pre: none
     post: prints an unsorted and sorted list
  purpose: test insertion sort function with array of strings
*/
void insertionSortTest2()
{
   cout << "insertion sort Test2:\n";
   string arr[] = {"2431", "hi", "had", "baby"};
   printArray(arr, 4);
   insertionSort(arr, 4);
   printArray(arr, 4);
   cout << "\n\n";
}

/*    pre: none
     post: prints an unsorted and sorted list
  purpose: test insertion sort function with array of chars
*/
void insertionSortTest3()
{
   cout << "insertion sort Test3:\n";
   char arr[] = {'f', 's', 'i', 'a', 'l', 'p', 'e'};
   printArray(arr, 4);
   insertionSort(arr, 4);
   printArray(arr, 4);
   cout << "\n\n";
}

/*    pre: none
     post: prints an unsorted and sorted list
  purpose: test insertion sort function with array of strings w/ capitals
*/
void insertionSortTest4()
{
   cout << "insertion sort Test4:\n";
   string arr[] = {"2431", "Hi", "had", "bAby"};
   printArray(arr, 4);
   insertionSort(arr, 4);
   printArray(arr, 4);
   cout << "\n\n";
}

/*    pre: none
     post: prints an unsorted and sorted list
  purpose: test insertion sort function with array of chars w/ capitals
*/
void insertionSortTest5()
{
   cout << "insertion sort Test5:\n";
   char arr[] = {'f', 's', 'I', 'a', 'L', 'p', 'E'};
   printArray(arr, 4);
   insertionSort(arr, 4);
   printArray(arr, 4);
   cout << "\n\n";
}
