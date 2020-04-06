/* ***       Author:  Wei Kian Chen
     *  Last Update:  September 27, 2019
     *        Class:  CSI-281
     *     Filename:  linkedList.h
     *
     *  Description:
     *      This is the template linked list definition.
     *
     *  Certification of Authenticity:
     *     I certify that this assignment is entirely my own work.
     ********************************************************************/

#ifndef LINKED_LIST
#define LINKED_LIST

#include <iostream>

using namespace std;

template <typename T>
class LinkedList
{
   template <typename R>
   struct Node
   {
      R mData;
      Node<R> *mNext;

      /*      Pre:  None
       *     Post:  This object is initialized using default values
       *  Purpose:  To initialize date object
       ********************************************************************/
      Node()
      {
         mData = R();
         mNext = NULL;
      }

      /*      Pre:  None
       *     Post:  This object is initialized using specified data
       *  Purpose:  To intialize date object
       ********************************************************************/
      Node(R data)
      {
         mData = data;
         mNext = NULL;
      }
   };

private:
   Node<T> *mHead, *mTail;
   int mCount;

public:
   LinkedList();
   ~LinkedList();

   int getCount();
   T getData(int index);
   void setData(int index, T data);

   void clear();
   void display();
   bool insert(T data);
   bool isEmpty();
   bool isExist(T searchKey);
   bool remove(T searchKey);
   T removeAt(int index);

   T operator[](int index);
};

/*      Pre:  None
 *     Post:  This object is initialized using the default
 *  Purpose:  To initialize date object
 ************************************************************************/
template <typename T>
LinkedList<T>::LinkedList()
{
   mHead = NULL;
   mTail = NULL;
   mCount = 0;
}

/*      Pre:  None
 *     Post:  All the nodes in the list is deleted
 *  Purpose:  To remove all the nodes in the list
 ************************************************************************/
template <typename T>
LinkedList<T>::~LinkedList()
{
}

/*      Pre:  The object is instantiated
 *     Post:  The number of nodes in the linked list is returned to
 *            the caller
 *  Purpose:  To retrieve the number of nodes in the list
 ************************************************************************/
template <typename T>
int LinkedList<T>::getCount()
{
   return mCount;
}

/*      Pre:  The list is instantiated and the index is valid
 *     Post:  The data in the specified index is returned to the caller
 *  Purpose:  To retrieve the specified nodes in the list
 ************************************************************************/
template <typename T>
T LinkedList<T>::getData(int index)
{
   if (index < 0 || index >= mCount)
      return T();
   Node<T> *curser = mHead;
   int i = 0;
   while (i < index)
   {
      curser = curser->mNext;
      i++;
   }
   return curser->mData;
}

/*      Pre:  The list is instantiated, the index is valid and the
 *            data is available
 *     Post:  The data in the specified index is updated with the
 *            specified data
 *  Purpose:  To update the specified nodes in the list
 ************************************************************************/
template <typename T>
void LinkedList<T>::setData(int index, T data)
{
   if (index < 0 || index >= mCount)
      return;
   Node<T> *curser = mHead;
   int i = 0;
   while (i < index)
   {
      curser = curser->mNext;
      i++;
   }
   curser->mData = data;
}

/*      Pre:  The list is initiated
 *     Post:  All the nodes in the list is deleted
 *  Purpose:  To remove all the nodes in the list
 ************************************************************************/
template <typename T>
void LinkedList<T>::clear()
{
   Node<T> *tmp = mHead, *last;
   while (tmp != nullptr)
   {
      last = tmp;
      tmp = tmp->mNext;
      delete last;
   }
   mCount = 0;
   mHead = nullptr;
   mTail = nullptr;
}

/*      Pre:  The list is instantiated
 *     Post:  The entire list is displayed on the screen
 *  Purpose:  To show the content of the list
 ************************************************************************/
template <typename T>
void LinkedList<T>::display()
{
   Node<T> *tmp = mHead;
   for (int i = 0; i < mCount; i++)
   {
      cout << tmp->mData << " ";
      tmp = tmp->mNext;
   }
   cout << endl;
}

/*      Pre:  The list is instantiated and the data is available
 *     Post:  The data is inserted in ascending order
 *  Purpose:  To insert a data into the list in ascending order.
 *            However, if the data already existed in the list, it will
 *            not be added again
 ************************************************************************/
template <typename T>
bool LinkedList<T>::insert(T data)
{
   bool inserted = false;
   Node<T> *newNode = new Node<T>(data);
   if (newNode == NULL)
      return inserted;
   if (mHead == NULL)
   {
      mHead = newNode;
      mTail = newNode;
      inserted = true;
   }
   else if (data <= mHead->mData)
   {
      newNode->mNext = mHead;
      mHead = newNode;
      inserted = true;
   }
   else if (data >= mTail->mData)
   {
      mTail->mNext = newNode;
      mTail = newNode;
      inserted = true;
   }
   else
   {
      Node<T> *curser = mHead;
      while (curser != nullptr)
      {
         if (curser->mNext->mData > data)
         {
            break;
         }
         curser = curser->mNext;
      }

      newNode->mNext = curser->mNext;
      curser->mNext = newNode;
      inserted = true;
   }
   if (inserted)
      mCount++;
   return inserted;
}

/*      Pre:  The list is instantiated
 *     Post:  The function returns true is the list is empty; false
 *            otherwise
 *  Purpose:  To determine if the list is empty
 ************************************************************************/
template <typename T>
bool LinkedList<T>::isEmpty()
{
   return mHead == NULL;
}

/*      Pre:  The list is instantiated and the searchKey is available
 *     Post:  The function returns true if the search key exists in the
 *            list; otherwise false
 *  Purpose:  To determine if a specific value exists in the list or not
 ************************************************************************/
template <typename T>
bool LinkedList<T>::isExist(T searchKey)
{
   Node<T> *curser = mHead;
   while (curser != nullptr)
   {
      if (curser->mData == searchKey)
         return true;
      if (curser->mData > searchKey)
         return false;
      curser = curser->mNext;
   }
   return false;
}

/*      Pre:  The list is instantiated and the searchKey is available
 *     Post:  If the searchKey exists, removes it from the list and the
 *            function returns true; otherwise the function does nothing
 *            and returns false
 *  Purpose:  To remove a specific value from the list
 ************************************************************************/
template <typename T>
bool LinkedList<T>::remove(T searchKey)
{
   T data = T();
   if (searchKey < mHead->mData || searchKey >= mTail->mData)
      return data;
   Node<T> *curser = mHead, *oneBefore;

   while (curser->mData < searchKey)
   {
      oneBefore = curser;
      curser = curser->mNext;
   }
   if (curser == mHead)
   {
      data = mHead->mData;
      mHead = mHead->mNext;
      delete curser;
      mCount--;
      return data;
   }
   if (curser == mTail)
   {
      mTail = oneBefore;
   }
   oneBefore->mNext = curser->mNext;
   data = curser->mData;
   delete curser;
   mCount--;
   return data;
}

/*      Pre:  The list is instantiated and the index is valid
 *     Post:  Remove the element in the specified index location and
 *            returns its content to the caller.  If the index location
 *            is invalid, the function returns the default value
 *  Purpose:  To remove an item in the specified index location
 ************************************************************************/
template <typename T>
T LinkedList<T>::removeAt(int index)
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

/*      Pre:  The list is instantiated and the index is valid
 *     Post:  The data in the specified index is returned to the
 *            caller
 *  Purpose:  To retrieve the specified nodes in the list using []
 *            operator
 ************************************************************************/
template <typename T>
T LinkedList<T>::operator[](int index)
{
   if (index < 0 || index >= mCount)
      return T();
   Node<T> *curser = mHead;
   int i = 0;
   while (i < index)
   {
      curser = curser->mNext;
      i++;
   }
   return curser->mData;
}

#endif