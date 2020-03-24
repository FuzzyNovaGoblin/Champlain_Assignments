/* ***       Author:  Wei Kian Chen
     *  Last Update:  March 24, 2019
     *        Class:  CSI-281
     *     Filename:  stub.cp
     *
     *  Description:
     *      This class is template class for a doubly linked list
     *
     *  Certification of Authenticity:
     *     I certify that this assignment is entirely my own work.
     **********************************************************************/

#include <iostream>
#include "doublyLinkedList.h"

using namespace std;

int main()
{
   DoublyLinkedList<int> *list;
   int             i;

   list = new DoublyLinkedList<int>;

   cout << "Testing isEmpty, expecting true, received " 
        << (list->isEmpty() ? "true" : "false") << endl;

   for (i = 0; i <= 10; i += 2)
   {
      list->insert(i);
      list->display();
   }

   for (i = 1; i < 10; i += 2)
   {
      list->insert(i);
      list->display();
   }

   cout << "Display list in reserve:  ";
   list->displayInReverse();
   cout << endl;

   cout << "Testing isEmpty, expecting false, received " 
        << (list->isEmpty() ? "true" : "false") << endl;

   cout << "Testing isExist(6), expecting true, received "
        << (list->isExist(6) ? "true" : "false") << endl;

   cout << "Testing isExist(20), expecting false, received "
        << (list->isExist(20) ? "true" : "false") << endl;


   for (i = 0; i <= 12; i += 2)
   {
      cout << "Removing " << i << ", received " << list->remove(i) << endl;
      list->display();
   }

   for (i = 1; i < 10; i++)
   {
      cout << "Removing " << i << ", received " << list->remove(i) << endl;
      list->display();
   }

   delete list;

   system("pause");

   return 0;
}