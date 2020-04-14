/* ***       Author:  Wei Kian Chen with students in CSI-281
     *  Last Update:  March 3, 2020
     *        Class:  CSI-281
     *     Filename:  queue.h
     *
     *  Description:
     *      This is the template queue definition.
     *
     *  Certification of Authenticity:
     *     I certify that this assignment is entirely owr work.
     ******************************************************************/

#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>

using namespace std;

template <typename T>
class Queue
{
private:
   template <typename R>
   struct Node
   {
      R mData;
      Node<R> *mNext;

      /*      Pre:  None
          *     Post:  This object is initialized using default values
          *  Purpose:  To intialize node object
          *************************************************************/
      Node()
      {
         mData = R();
         mNext = NULL;
      }

      /*      Pre:  None
          *     Post:  This object is initialized using specified data
          *  Purpose:  To intialize node object
          *************************************************************/
      Node(R data)
      {
         mData = data;
         mNext = NULL;
      }
   };

   Node<T> *mHead, *mTail;
   int mCount;

public:
   Queue();
   ~Queue();

   int getCount();

   void clear();
   T dequeue();
   void display();
   void enqueue(T data);
   bool isEmpty();
   bool isExist(T searchKey);
};

/*      Pre:  The queue is instantiated
 *     Post:  Both mHead and mTail are initialized to NULL and mCount
 *            is set to zero
 *  Purpose:  To intialize queue object
 *********************************************************************/
template <typename T>
Queue<T>::Queue()
{
   mHead = nullptr;
   mTail = nullptr;
   mCount = 0;
}

/*      Pre:  The queue is instantiated
 *     Post:  The queue is removed and both mHead and mTail are
 *            reset to NULL and mCount is reset to zero
 *  Purpose:  To clear up a queue object
 *********************************************************************/
template <typename T>
Queue<T>::~Queue()
{
   clear();
}

/*      Pre:  The queue is instantiated
 *     Post:  The count for the queue object is returned
 *  Purpose:  To retrieve the count for a queue object
 *********************************************************************/
template <typename T>
int Queue<T>::getCount()
{
   return mCount;
}

/*      Pre:  The queue is instantiated
 *     Post:  The entire queue is cleared
 *  Purpose:  To clear the entire queue object
 *********************************************************************/
template <typename T>
void Queue<T>::clear()
{
   Node<T> *tmp;

   while (mHead != NULL)
   {
      tmp = mHead;
      mHead = mHead->mNext;
      tmp->mNext = NULL;
      delete tmp;
   }

   mTail = NULL;
   mCount = 0;
}

/*      Pre:  The queue is instantiated
 *     Post:  The data for the object in the front of the queue is
 *            returned and the node is removed
 *  Purpose:  To retrieve the data in the first node in the queue and
 *            delete the node
 *********************************************************************/
template <typename T>
T Queue<T>::dequeue()
{
   T tmpData = mHead->mData;
   Node<T> *tmpNode = mHead;
   mHead = mHead->mNext;
   delete tmpNode;
   mCount--;
   return tmpData;
}

/*      Pre:  The queue is instantiated
 *     Post:  The entire queue is displayed on the screen
 *  Purpose:  To display the entire queue from the front to the back
 *********************************************************************/
template <typename T>
void Queue<T>::display()
{
   Node<T> *tmp;

   if (isEmpty())
      cout << "Empty Queue\n";
   else
   {
      tmp = mHead;
      while (tmp != nullptr)
      {
         cout << tmp->mData << "   ";
         tmp = tmp->mNext;
      }
      cout << endl;
   }
}

/*      Pre:  The queue is instantiated
 *     Post:  A new node is added at the end of the queue
 *  Purpose:  To add a new data to the queue
 *********************************************************************/
template <typename T>
void Queue<T>::enqueue(T data)
{
   Node<T> *tmp = new Node<T>(data);
   if (tmp == NULL)
      return;

   if (mCount == 0)
   {
      mHead = tmp;
      mTail = tmp;
      mCount = 1;
   }
   else
   {
      mTail->mNext = tmp;
      mTail = tmp;
      mCount++;
   }
}

/*      Pre:  The queue is instantiated
 *     Post:  True if the queue is empty, otherwise false
 *  Purpose:  To determine if the queue is empty
 *********************************************************************/
template <typename T>
bool Queue<T>::isEmpty()
{
   return mCount == 0;
}

/*      Pre:  The queue is instantiated and a searchKey is available
 *     Post:  True if the the searchKey existed in the queue,
 *            otherwise false
 *  Purpose:  To determine if a value existed in the queue
 *********************************************************************/
template <typename T>
bool Queue<T>::isExist(T searchKey)
{
   Node<T> *tmp = mHead;
   while (tmp != nullptr)
   {
      if(tmp->mData == searchKey)
         return true;
      tmp = tmp->mNext;
   }
   return false;
}

#endif