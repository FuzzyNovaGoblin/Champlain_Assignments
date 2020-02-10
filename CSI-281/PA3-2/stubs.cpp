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

#include "stubs.h"

using namespace std;

/*    pre: none
     post: prints an unsorted and sorted list
  purpose: test selection sort function with array of ints
*/
void selectionSortTest1()
{
  cout << "selection sort Test1:\n";
  int arr[] = {43, 43, 25, 64, 43, 5, 7, 565, 3, -64};
  printArray(arr, 10);
  selectionSort(arr, 10);
  printArray(arr, 10);
  cout << "\n\n";
}

/*    pre: none
     post: prints an unsorted and sorted list
  purpose: test selection sort function with array of strings
*/
void selectionSortTest2()
{
  cout << "selection sort Test2:\n";
  string arr[] = {"2431", "hi", "had", "baby"};
  printArray(arr, 4);
  selectionSort(arr, 4);
  printArray(arr, 4);
  cout << "\n\n";
}

/*    pre: none
     post: prints an unsorted and sorted list
  purpose: test selection sort function with array of chars
*/
void selectionSortTest3()
{
  cout << "selection sort Test3:\n";
  char arr[] = {'f', 's', 'i', 'a', 'l', 'p', 'e'};
  printArray(arr, 4);
  selectionSort(arr, 4);
  printArray(arr, 4);
  cout << "\n\n";
}

/*    pre: none
     post: prints an unsorted and sorted list
  purpose: test selection sort function with array of strings w/ capitals
*/
void selectionSortTest4()
{
  cout << "selection sort Test4:\n";
  string arr[] = {"2431", "Hi", "had", "bAby"};
  printArray(arr, 4);
  selectionSort(arr, 4);
  printArray(arr, 4);
  cout << "\n\n";
}

/*    pre: none
     post: prints an unsorted and sorted list
  purpose: test selection sort function with array of chars with capitals
*/
void selectionSortTest5()
{
  cout << "selection sort Test5:\n";
  char arr[] = {'f', 's', 'I', 'a', 'L', 'p', 'E'};
  printArray(arr, 4);
  selectionSort(arr, 4);
  printArray(arr, 4);
  cout << "\n\n";
}

/*    pre: none
     post: prints an unsorted and sorted list
  purpose: test shell sort function with array of ints
*/
void shellSortTest1()
{
  cout << "shell sort Test1:\n";
  int arr[] = {43, 43, 25, 64, 43, 5, 7, 565, 3, -64};
  printArray(arr, 10);
  shellSort(arr, 10);
  printArray(arr, 10);
  cout << "\n\n";
}

/*    pre: none
     post: prints an unsorted and sorted list
  purpose: test shell sort function with array of strings
*/
void shellSortTest2()
{
  cout << "shell sort Test2:\n";
  string arr[] = {"2431", "hi", "had", "baby"};
  printArray(arr, 4);
  shellSort(arr, 4);
  printArray(arr, 4);
  cout << "\n\n";
}

/*    pre: none
     post: prints an unsorted and sorted list
  purpose: test shell sort function with array of chars
*/
void shellSortTest3()
{
  cout << "shell sort Test3:\n";
  char arr[] = {'f', 's', 'i', 'a', 'l', 'p', 'e'};
  printArray(arr, 4);
  shellSort(arr, 4);
  printArray(arr, 4);
  cout << "\n\n";
}

/*    pre: none
     post: prints an unsorted and sorted list
  purpose: test shell sort function with array of strings w/ capitals
*/
void shellSortTest4()
{
  cout << "shell sort Test4:\n";
  string arr[] = {"2431", "Hi", "had", "bAby"};
  printArray(arr, 4);
  shellSort(arr, 4);
  printArray(arr, 4);
  cout << "\n\n";
}

/*    pre: none
     post: prints an unsorted and sorted list
  purpose: test shell sort function with array of chars w/ capitals
*/
void shellSortTest5()
{
  cout << "shell sort Test5:\n";
  char arr[] = {'f', 's', 'I', 'a', 'L', 'p', 'E'};
  printArray(arr, 4);
  shellSort(arr, 4);
  printArray(arr, 4);
  cout << "\n\n";
}
