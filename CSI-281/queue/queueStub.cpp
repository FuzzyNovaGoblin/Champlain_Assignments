/* ***       Author:  Wei Kian Chen with students in CSI-281
     *  Last Update:  October 22, 2017
     *        Class:  CSI-281
     *     Filename:  queueStub.h
     *
     *  Description:
     *      This is the stub driver for the queue definition.
     *
     *  Certification of Authenticity:
     *     I certify that this assignment is entirely owr work.
     ******************************************************************/

#include <iostream>
#include "queue.h"

using namespace std;

int main()
{
   Queue<int> queue;
   int        i;

   cout << "Testing isEmpty, expecting true, received " 
        << (queue.isEmpty() ? "true" : "false") << endl;

   for (i = 0; i <= 10; i += 2)
   {
      queue.enqueue(i);
      queue.display();
   }

   for (i = 1; i < 10; i += 2)
   {
      queue.enqueue(i);
      queue.display();
   }

   cout << "getCount = " << queue.getCount() << endl;

   cout << "Testing isEmpty, expecting false, received " 
        << (queue.isEmpty() ? "true" : "false") << endl;

   cout << "Testing isExist(6), expecting true, received "
        << (queue.isExist(6) ? "true" : "false") << endl;

   cout << "Testing isExist(20), expecting false, received "
        << (queue.isExist(20) ? "true" : "false") << endl;


   while (queue.getCount() != 0)
   {
      cout << "Removing " << queue.dequeue() << endl;
      queue.display();
   }

   queue.clear();
   cout << "The queue after clear:  ";
   queue.display();
   cout << endl;

   system("pause");

   return 0;
}