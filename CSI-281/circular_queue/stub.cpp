/* ***       Author:  Wei Kian Chen
     *  Last Update:  October 22, 2019
     *        Class:  CSI-281
     *     Filename:  stub.h
     *
     *  Description:
     *      This is the stub driver for the circular queue definition.
     *
     *  Certification of Authenticity:
     *     I certify that this assignment is entirely my work.
     ******************************************************************/

#include <iostream>
#include "circularQueue.h"

using namespace std;

const int SIZE = 10;

int main()
{
   CircularQueue<int> list;
   int                i;

   if (list.isEmpty())
      cout << "The list is empty\n";

   for (i = 0; i <= SIZE; i++)
   {
      cout << "Enqueue:  " << i << endl;
      list.enqueue(i);
      list.display();
      cout << endl;
   }

   if (!list.isEmpty())
      cout << "The list is populated\n";
   
   if (list.isFull())
      cout << "The list is full\n";

   list.display();

   return 0;
}