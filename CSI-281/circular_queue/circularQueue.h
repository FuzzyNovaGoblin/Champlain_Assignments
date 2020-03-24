/* ***       Author:  Wei Kian Chen
     *  Last Update:  March 6, 2020
     *        Class:  CSI-281
     *     Filename:  circularQueue.h
     *
     *  Description:
     *      This is the template circular queue definition.
     *
     *  Certification of Authenticity:
     *     I certify that this assignment is entirely my work.
     ******************************************************************/

#ifndef CIRCULAR_QUEUE_H
#define CIRCULAR_QUEUE_H

#include <iostream>

using namespace std;

template <typename T>
class CircularQueue
{
   // the maximum capacity of this queue is 10
   static const int C_CAPACITY = 10;

private:
   T mList[C_CAPACITY];
   int mHead, mTail, mCount;

public:
   CircularQueue();

   T dequeue();
   void display();
   void enqueue(T data);
   bool isEmpty();
   bool isExist(T searchKey);
   bool isFull();
};

/*      Pre:  None
 *     Post:  All mHead, mTail and mCount are initialized to zero
 *  Purpose:  Default constructor
 ***************************************************************/
template <typename T>
CircularQueue<T>::CircularQueue()
{
   mHead = 0;
   mTail = 0;
   mCount = 0;
}

/*      Pre:  None
 *     Post:  The first item in the circular queue is removed
 *  Purpose:  To remove an item in the circular queue.  The
 *            queue process is FIFO
 ***************************************************************/
template <typename T>
T CircularQueue<T>::dequeue()
{
   T data();
   if (!isEmpty())
   {
      data = mList[mHead];
      if (mCount != 1)
         mHead = (mHead + 1) % C_CAPACITY;
      mCount--;
   }
   return data;
}

/*      Pre:  None
 *     Post:  ALl items in the circular queue is displayed on
 *            the screen
 *  Purpose:  To display the entire queue from head to tail
 ***************************************************************/
template <typename T>
void CircularQueue<T>::display()
{
   int tmp = mHead;
   while (tmp != mTail)
   {
      cout << mList[tmp] << " ";
      tmp = (tmp + 1) % C_CAPACITY;
   }
   cout << mList[mTail] << endl;

}

/*      Pre:  A data to insert into the circular queue
 *     Post:  A new data is inserted into the circular queue
 *  Purpose:  A new data is inserted at the end of the circular
 *            queue.  The queue operation in FIFO and duplication
 *            is allowed.  If the circular queue is full, the new
 *            new data is not allowed to insert
 ***************************************************************/
template <typename T>
void CircularQueue<T>::enqueue(T data)
{
   if (!isFull())
   {
      if (mCount != 0)
         maTail = (mTail + 1) % C_CAPACITY;
      mList[mTail] = data;
      mCount++;
   }
}

/*      Pre:  None
 *     Post:  True if the circular queue is empty, otherwise false
 *  Purpose:  To determine if the circular queue is empty
 ***************************************************************/
template <typename T>
bool CircularQueue<T>::isEmpty()
{
   return (mCount == 0);
}

/*      Pre:  Search key
 *     Post:  True if the search key exists in the circular queue,
 *            otherwise false
 *  Purpose:  To determine if a search key exists in the queue
 ***************************************************************/
template <typename T>
bool CircularQueue<T>::isExist(T searchKey)
{
}

/*      Pre:  None
 *     Post:  True if the circular queue if full, otherwise false
 *  Purpose:  To determine if the circular queue is full where
 *            mCount is the same as C_CAPACITY
 ***************************************************************/
template <typename T>
bool CircularQueue<T>::isFull()
{
   return (mCount == C_CAPACITY);
}

#endif