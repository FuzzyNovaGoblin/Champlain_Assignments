/* ***       Author:  Wei Kian Chen with students in CSI-281
     *  Last Update:  October 22, 2019
     *        Class:  CSI-281
     *     Filename:  stub.cpp
     *
     *  Description:
     *      This is the stub driver for the stack definition.
     *
     *  Certification of Authenticity:
     *     I certify that this assignment is entirely owr work.
     ******************************************************************/

#include <iostream>
#include "stack.h"

using namespace std;

int main()
{
   int        i;
   Stack<int> *ptr;

   ptr = new Stack<int>;

   if (ptr->isEmpty())
      cout << "Stack is empty\n";

   for (i = 0; i < 10; i++)
   {
      cout << "Pushing:  " << i << endl;
      ptr->push(i);
      ptr->display();
      cout << endl;
   }

   if (ptr->isEmpty())
      cout << "Stack is empty\n";
   else
      cout << "Stack is populated\n";

   cout << "Searching for 5:  ";
   if (ptr->isExist(5))
      cout << "Match found\n";
   else
      cout << "Match not found\n";

   cout << "Searching for 12:  ";
   if (!ptr->isExist(12))
      cout << "Match not found\n";
   else
      cout << "Match found\n";

   for (i = 0; i < 10; i++)
   {
      cout << "Popping:  " << ptr->pop() << endl;
      ptr->display();
      cout << endl;
   }

   if (ptr->isEmpty())
      cout << "The stack is empty\n";

   delete ptr;

   return 0;
}