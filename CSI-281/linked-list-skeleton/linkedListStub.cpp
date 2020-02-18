/* ***       Author:  Wei Kian Chen
     *  Last Update:  September 27, 2019
     *        Class:  CSI-281
     *     Filename:  linkedListStub.cpp
     *
     *  Description:
     *      This is a stub to test the templated linked list.
     *
     *  Certification of Authenticity:
     *     I certify that this assignment is entirely my own work.
     ********************************************************************/


#include <iostream>
#include "linkedList.h"

using namespace std;

const int SIZE = 10;

int main()
{
   LinkedList<int> list;
   int             i;

   cout << "Testing isEmpty, expecting true, received " 
        << (list.isEmpty() ? "true" : "false") << endl;

   for (i = 0; i <= SIZE; i += 2)
   {
      list.insert(i);
      list.display();
   }

   for (i = 1; i < SIZE; i += 2)
   {
      list.insert(i);
      list.display();
   }

   cout << "getCount = " << list.getCount() << endl;

   cout << "Adding 6 in the list again, but 6 already existed in the "
        << "system, it should not be added since the insert function\n"
        << "does not allow duplication\n";
   list.insert(6);

   cout << "Checking the total count in the list and it should be the "
        << "the same as before: " << list.getCount() << endl;

   cout << "Checking the list, and it should be the same as before: ";
   list.display();
   cout << endl;

   cout << "Display list using getData:  ";
   for (i = 0; i <= SIZE; i++)
      cout << list.getData(i) << " ";
   cout << endl;

   cout << "Changing the odd indexed item\n";
   for (i = 1; i < SIZE; i += 2)
      list.setData(i, 10 + i);
   list.display();

   cout << "Performing the clear function that will clear the entire list\n";
   list.clear();
   cout << "The count should be 0, and it is " << list.getCount() << endl;
   cout << "The list should be empty and it is ";
   list.display();
   cout << endl;

   for (i = 0; i <= SIZE; i++)
      list.insert(i);

   cout << "Current list:  ";
   list.display();

   cout << "Display list using [] operator overloading:  ";
   for (i = 0; i < SIZE; i++)
      cout << list[i] << " ";
   cout << endl;

   cout << "Testing isEmpty, expecting false, received " 
        << (list.isEmpty() ? "true" : "false") << endl;

   cout << "Testing isExist(6), expecting true, received "
        << (list.isExist(6) ? "true" : "false") << endl;

   cout << "Testing isExist(20), expecting false, received "
        << (list.isExist(20) ? "true" : "false") << endl;

   cout << "Current list:  ";
   list.display();

   for (i = -2; i <= SIZE + 2; i += 2)
   {
      cout << "Removing " << i << ", " << (list.remove(i) ? "Done" : "Failed") << endl;
      list.display();
   }

   for (i = 0; i <= SIZE; i += 2)
      list.insert(i);

   cout << "Current list:  ";
   list.display();

   for (i = 0; i < SIZE; i++)
   {
      cout << "Removing at index " << i << ", received " << list.removeAt(SIZE - i) << endl;
      list.display();
   }

   list.clear();
   cout << "The list after clear:  ";
   list.display();
   cout << endl;

   system("pause");

   return 0;
}