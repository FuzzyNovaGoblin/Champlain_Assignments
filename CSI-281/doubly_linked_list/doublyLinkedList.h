/* ***       Author:  Wei Kian Chen
     *  Last Update:  March 24, 2020
     *        Class:  CSI-281
     *     Filename:  doublyLinkedList.h
     *
     *  Description:
     *      This class is template class for a doubly linked list
     *
     *  Certification of Authenticity:
     *     I certify that this assignment is entirely my own work.
     **********************************************************************/

#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

#include <iostream>

using namespace std;

template <typename T>
class DoublyLinkedList
{
private:
   template <typename R>
   struct Node
   {
      R mData;
      Node<R> *mNext, *mPrevious;

      /*      Pre:  None
          *     Post:  This object is initialized using default values
          *  Purpose:  To intialize date object
          *************************************************************************/
      Node()
      {
         mData = R();
         mNext = NULL;
         mPrevious = NULL;
      }

      /*      Pre:  None
          *     Post:  This object is initialized using specified data
          *  Purpose:  To intialize date object
          *************************************************************************/
      Node(R data)
      {
         mData = data;
         mNext = NULL;
         mPrevious = NULL;
      }
   };

   Node<T> *mHead, *mTail;
   int mCount;

public:
   DoublyLinkedList();
   ~DoublyLinkedList();

   int getCount();
   T getData(int index);
   void setData(int index, T data);

   void clear();
   void display();
   void displayInReverse();
   void insert(T data);
   bool isEmpty();
   bool isExist(T searchKey);
   bool remove(T searchKey);
   T removeAt(int index);
};

/*      Pre:  None
 *     Post:  The next and previous pointers are initialized to NULL
 *  Purpose:  Default constructor
******************************************************************************/
template <typename T>
DoublyLinkedList<T>::DoublyLinkedList()
{
   mHead = NULL;
   mTail = NULL;
   mCount = 0;
}

template <typename T>
DoublyLinkedList<T>::~DoublyLinkedList()
{
   clear();
}

/*      Pre:  The object is instantiated
 *     Post:  The number of nodes in the linked list is returned to the caller
 *  Purpose:  To retrieve the number of nodes in the list
 *****************************************************************************/
template <typename T>
int DoublyLinkedList<T>::getCount()
{
   return mCount;
}

/*      Pre:  The list is instantiated and the index is valid
 *     Post:  The data in the specified index is returned to the caller
 *  Purpose:  To retrieve the specified nodes in the list
 *****************************************************************************/
template <typename T>
T DoublyLinkedList<T>::getData(int index)
{
   int i;
   Node<T> *tmp;

   tmp = mHead;
   for (i = 0; i < index; i++)
      tmp = tmp->mNext;

   return tmp->mData;
}

/*      Pre:  The list is instantiated, the index is valid and the data is
 *            available
 *     Post:  The data in the specified index is updated with the specified
 *            data
 *  Purpose:  To update the specified nodes in the list
 *****************************************************************************/
template <typename T>
void DoublyLinkedList<T>::setData(int index, T data)
{
   int i;
   Node<T> *tmp;

   tmp = mHead;
   for (i = 0; i < index; i++)
      tmp = tmp->mNext;

   tmp->mData = data;
}

/*      Pre:  The list is instantiated
 *     Post:  All  nodes in the doubly linked list is deleted. mHead, mTail and
              mCount are reset
 *  Purpose:  To clear the entire doubly linked list
******************************************************************************/
template <typename T>
void DoublyLinkedList<T>::clear()
{
}

/*      Pre:  The list is instantiated
 *     Post:  The data of the nodes in the doubly linked list is displayed on
 *            the screen
 *  Purpose:  To display all data stored in the doubly linked list
******************************************************************************/
template <typename T>
void DoublyLinkedList<T>::display()
{
   Node<T> *tmp;

   if (mHead == NULL)
   {
      cout << "The list is empty\n";
      return;
   }

   tmp = mHead;
   while (tmp != NULL)
   {
      cout << tmp->mData << " ";
      tmp = tmp->mNext;
   }
   cout << endl;
}

/*      Pre:  The list is instantiated
 *     Post:  The data of the nodes in the doubly linked list is displayed on
 *            the screen in reverse order
 *  Purpose:  To display all data stored in the doubly linked list in reverse
 *            order
******************************************************************************/
template <typename T>
void DoublyLinkedList<T>::displayInReverse()
{
}

/*      Pre:  The list is instantiated and the new value is available
 *     Post:  The new node is added onto the doubly linked list in ascending
 *            order.  For example, if the new data is B, then it must be added
 *            in between A and C
 *  Purpose:  To add a new node onto the doubly linked list.  Duplication is
 *            allowed
******************************************************************************/
template <typename T>
void DoublyLinkedList<T>::insert(T data)
{
   Node<T> *tmp = new Node(data);

   if (mHead == NULL)
   {
      mHead = tmp;
      mTail = tmp;
   }
   else if (data <= mHead->data)
   {
      mHead->mPrevious = tmp;
      tmp->mNext = mHead;
      mHead = tmp;
   }
   else if(data >= mTail->data){
      mTail->mNext = tmp;
      tmp->mPrevious = mTail;
      mTail = tmp;
   }
   else{
      Node<T> *c = mHead;
      while(tmp->mData > c->mData){
         c = c->mNext;
      }
      c->mPrevious->mNext = tmp;
      tmp->mPrevious = c->mPrevious;
      tmp->mNext = c;
      c->mPrevious = tmp;
   }
   mCount++;
}

/*      Pre:  The list is instantiated and the new value is available
 *     Post:  Return true is the list is empty, otherwise false
 *  Purpose:  To determine if the doubly linked list is empty
******************************************************************************/
template <typename T>
bool DoublyLinkedList<T>::isEmpty()
{
   return mCount == 0;
}

/*      Pre:  The list is instantiated and the searchkey is provided
 *     Post:  True is the given value exists in the doubly linked list,
 *            otherwise false
 *  Purpose:  To validate if a given value exists in the doubly linked list
 *            using binary search
******************************************************************************/
template <typename T>
bool DoublyLinkedList<T>::isExist(T searchKey)
{
}

/*      Pre:  The list is instantiated and the searchkey is provided
 *     Post:  If the given searchKey exists in the doubly linked list, it is
 *            removed from the list
 *  Purpose:  To remove a given value from the doubly linked list
******************************************************************************/
template <typename T>
bool DoublyLinkedList<T>::remove(T searchKey)
{

   if (mHead == nullptr)
      return false;

   if (searchKey < mHead->mData ||
       searchKey > mTail->mData)
   {
      return false;
   }

   Node<T> *curser = mHead;

   if (mHead->mData == searchKey)
   {
      mHead = mHead->mNext;
      mHead->mPrevious = nullptr;
      delete curser;
      mCount--;
      return true;
   }

   Node<T> *oneBefore = curser;

   while (curser != nullptr)
   {
      if (curser->mData == searchKey)
         break;

      oneBefore = curser;
      curser = curser->mNext;
   }
   if (curser == nullptr)
      return false;
   if (curser == mTail)
   {
      delete mTail;
      oneBefore->mNext = nullptr;
      mTail = oneBefore;
      mCount--;
      return true;
   }
   oneBefore->mNext = curser->mNext;
   curser->mNext->mPrevious = oneBefore;
   mCount--;
   delete curser;

   return true;
}

/*      Pre:  The list is instantiated and the index for the node to be deleted
 *            is provided.  The index starts at zero
 *     Post:  If the index is valid, the node at the specified index location is
 *            removed and mCount is adjust accordingly.  And, mHead and mTail
 *            will be adjust when needed
 *  Purpose:  To remove a node at the specified index location within the
 *            doubly linked list
******************************************************************************/
template <typename T>
T DoublyLinkedList<T>::removeAt(int index)
{
   T data = T();
   if (index < 0 || index >= mCount)
      return data;
   Node<T> *curser = mHead, *oneBefore;
   int i = 0;
   while (i < index)
   {
      oneBefore = curser;
      curser = curser->mNext;
      i++;
   }
   if (i == 0)
   {
      data = mHead->mData;
      mHead = mHead->mNext;
      delete curser;
      mCount--;
      return data;
   }
   if (i == mCount - 1)
   {
      mTail = oneBefore;
   }
   oneBefore->mNext = curser->mNext;
   data = curser->mData;
   delete curser;
   mCount--;
   return data;
}

#endif