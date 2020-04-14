/* ***
     * Author: Grant Hedley
     * original Author:  Wei Kian Chen
     *  Last Update:  April 12, 2020
     *        Class:  CSI-281
     *     Filename:  bst.h
     *
     *  Description:
     *      Binary search tree definition.
     *
     *  Certification of Authenticity:
     *     I certify that this assignment is entirely my work.
     **********************************************************/

#ifndef _BST_H
#define _BST_H

#include <iostream>
#include <sstream>
#include "queue.h"
#include "stack.h"

using namespace std;

template <typename T>
class BST
{
private:
   template <typename R>
   struct Node
   {
      R mData;
      Node<R> *mLeft, *mRight;

      /*      Pre:  None
          *     Post:  This object is initialized using default
          *            values
          *  Purpose:  To intialize date object
          *****************************************************/
      Node()
      {
         mData = R();
         mLeft = NULL;
         mRight = NULL;
      }

      /*      Pre:  None
          *     Post:  This object is initialized using specified
          *            data
          *  Purpose:  To intialize date object
          *****************************************************/
      Node(R data)
      {
         mData = data;
         mLeft = NULL;
         mRight = NULL;
      }

      /*      Pre:  None
          *     Post:  This object is initialized using specified
          *            data with the specified children attached
          *  Purpose:  To intialize date object
          *****************************************************/
      Node(R data, Node<R> *left, Node<R> *right)
      {
         mData = data;
         mLeft = left;
         mRight = right;
      }
   };

   Node<T> *mRootNode;

   BST(T data, Node<T> *left, Node<T> *right);

   void destroySubtree(Node<T> *&node);
   void displayInOrder(Node<T> *node);
   void displayPreOrder(Node<T> *node);
   void displayPostOrder(Node<T> *node);
   void displayTree(Node<T> *node, int tab);
   void insert(Node<T> *&node, const T &data);
   void makeDeletion(Node<T> *&node);
   void remove(Node<T> *&node, const T &searchKey);
   int getNodeHeight(Node<T> *node);

public:
   BST();
   ~BST();

   bool bfs(T searchKey);
   void clear();
   bool dfs(T searchKey);
   int getHeight();
   void insert(T data);
   bool isEmpty();
   bool isExists(T searchKey);
   int leavesCount();
   int nodesCount();
   void remove(T searchKey);
   void printPath(T searchKey);
   void showInOrder();
   void showPreOrder();
   void showPostOrder();
   void showTree();
};

/*      Pre:  None
 *     Post:  The root node of the BST is initialized to NULL
 *  Purpose:  Default constructor
 **************************************************************/
template <typename T>
BST<T>::BST()
{
   mRootNode = NULL;
}

/*      Pre:  data, left pointer and right pointer
 *     Post:  The root node of the BST is initialized to the
 *            new root node with both left and right child
 *  Purpose:  Constructor
 **************************************************************/
template <typename T>
BST<T>::BST(T data, Node<T> *left, Node<T> *right)
{
   Node<T> *newNode;

   newNode = new Node<T>(data, left, right);
   if (newNode != NULL)
      mRootNode = newNode;
}

/*      Pre:  The BST is instantiated
 *     Post:  The root node of the BST is initialized to NULL
 *  Purpose:  Default constructor
 **************************************************************/
template <typename T>
BST<T>::~BST()
{
   destroySubtree(mRootNode);

   mRootNode = NULL;
}

/*      Pre:  A search key
 *     Post:  True is return is the search key is found in the
 *            BST, otherwise false
 *  Purpose:  Searching the tree using breadth-first search
 **************************************************************/
template <typename T>
bool BST<T>::bfs(T searchKey)
{
   stringstream ss;
   Queue<Node<T> *> queue;
   queue.enqueue(mRootNode);
   Node<T> *tmp;
   while (!queue.isEmpty())
   {
      tmp = queue.dequeue();
      ss << tmp->mData;
      if (tmp->mData == searchKey)
      {
         cout << ss.str() << endl;
         return true;
      }
      if (tmp->mLeft != NULL)
         queue.enqueue(tmp->mLeft);
      if (tmp->mRight != NULL)
         queue.enqueue(tmp->mRight);
      ss << ", ";
   }
   cout << "Search key is not found in the tree\n";
   return false;
}

/*      Pre:  The BST is instantiated
 *     Post:  The entire BST is deleted
 *  Purpose:  To clear the entire BST
 **************************************************************/
template <typename T>
void BST<T>::clear()
{
   destroySubtree(mRootNode);
}

/*      Pre:  A node within the BST
 *     Post:  All the subtree branching from the node (including
 *            the node) is deleted
 *  Purpose:  To delete a subtree
 **************************************************************/
template <typename T>
void BST<T>::destroySubtree(Node<T> *&node)
{
   if (node != NULL)
   {
      destroySubtree(node->mLeft);
      destroySubtree(node->mRight);
      delete node;
      node = NULL;
   }
}

/*      Pre:  A search key
 *     Post:  True is return is the search key is found in the
 *            BST, otherwise false
 *  Purpose:  Searching the tree using depth-first search
 **************************************************************/
template <typename T>
bool BST<T>::dfs(T searchKey)
{
   stringstream ss;
   Stack<Node<T> *> stack;
   stack.push(mRootNode);
   Node<T> *tmp;
   while (!stack.isEmpty())
   {
      tmp = stack.pop();
      ss << tmp->mData;
      if (tmp->mData == searchKey)
      {
         cout << ss.str() << endl;
         return true;
      }
      if (tmp->mLeft != NULL)
         stack.push(tmp->mLeft);
      if (tmp->mRight != NULL)
         stack.push(tmp->mRight);

      ss << ", ";
   }
   cout << "Search key is not found in the tree\n";
   return false;
}

/*      Pre:  A node within a tree
 *     Post:  The entire BST is displayed using in-order format
 *  Purpose:  A private function that display the entire BST
 *            using in-order format.
 **************************************************************/
template <typename T>
void BST<T>::displayInOrder(Node<T> *node)
{
   if (node != NULL)
   {
      displayInOrder(node->mLeft);
      cout << node->mData << " ";
      displayInOrder(node->mRight);
   }
}

/*      Pre:  A node within a tree
 *     Post:  The entire BST is displayed using pre-order format
 *  Purpose:  A private function that display the entire BST
 *            using pre-order format.
 **************************************************************/
template <typename T>
void BST<T>::displayPreOrder(Node<T> *node)
{
   if (node != NULL)
   {
      cout << node->mData << " ";
      displayPreOrder(node->mLeft);
      displayPreOrder(node->mRight);
   }
}

/*      Pre:  A node within a tree
 *     Post:  The entire BST is displayed using post-order format
 *  Purpose:  A private function that display the entire BST
 *            using post-order format.
 **************************************************************/
template <typename T>
void BST<T>::displayPostOrder(Node<T> *node)
{
   if (node != NULL)
   {
      displayPostOrder(node->mLeft);
      displayPostOrder(node->mRight);
      cout << node->mData << " ";
   }
}

/*      Pre:  A node within a tree
 *     Post:  The entire BST is displayed
 *  Purpose:  A private function that display the entire BST
 **************************************************************/
template <typename T>
void BST<T>::displayTree(Node<T> *node, int tab)
{
   for (int i = 0; i < tab; i++)
   {
      cout << "   ";
   }
   cout << node->mData << endl;
   if (node->mLeft != NULL)
      displayTree(node->mLeft, tab + 1);
   if (node->mRight != NULL)
      displayTree(node->mRight, tab + 1);
}

/*      Pre:  None
 *     Post:  The height of a tree is returned, -1 if tree is empty
 *  Purpose:  To compute the longest branch within the BST
 **************************************************************/
template <typename T>
int BST<T>::getHeight()
{
   return getNodeHeight(mRootNode);
}

/*      Pre:  None
 *     Post:  The height of a node is returned
 *  Purpose:  To compute the height of a single node within the BST
 **************************************************************/
template <typename T>
int BST<T>::getNodeHeight(Node<T> *node)
{
   if (node == NULL)
      return -1;
   int rightHeight, leftHeight;
   rightHeight = 1 + getNodeHeight(node->mRight);
   leftHeight = 1 + getNodeHeight(node->mLeft);

   return rightHeight > leftHeight ? rightHeight : leftHeight;
}

/*      Pre:  A data to insert into a BST
 *     Post:  A new data is inserted into a BST
 *  Purpose:  To insert a new value into a BST
 **************************************************************/
template <typename T>
void BST<T>::insert(T data)
{
   insert(mRootNode, data);
}

/*      Pre:  A node within a tree and the value to insert
 *     Post:  The new value is inserted into the BST
 *  Purpose:  A private function that insert a new data into a
 *            BST.  BST does not allow duplication of value.
 *            Hence, a duplicated value will not be inserted
 **************************************************************/
template <typename T>
void BST<T>::insert(Node<T> *&node, const T &data)
{
   // If the tree is empty, make a new node and make it
   // the root of the tree.
   if (node == NULL)
   {
      node = new Node<T>(data);
      return;
   }

   // If num is already in tree: return.
   if (node->mData == data)
      return;
   // The tree is not empty: insert the new node into the
   // left or right subtree.
   else if (node->mData < data)
      insert(node->mRight, data);
   else
      insert(node->mLeft, data);
}

/*      Pre:  None
 *     Post:  True if the BST is empty, otherwise false
 *  Purpose:  To determine if the BST is empty
 **************************************************************/
template <typename T>
bool BST<T>::isEmpty()
{
   return (mRootNode == NULL);
}

/*      Pre:  A search key
 *     Post:  True is return if the search key existed in the
 *            BST, otherwise false
 *  Purpose:  To search if a search key exists in the BST using
 *            the typical binary tree search
 **************************************************************/
template <typename T>
bool BST<T>::isExists(T searchKey)
{
   Node<T> *tmp;
   bool found = false;

   tmp = mRootNode;

   while (tmp != NULL)
   {
      if (tmp->mData == searchKey)
      {
         found = true;
         break;
      }
      else if (tmp->mData > searchKey)
         tmp = tmp->mLeft;
      else
         tmp = tmp->mRight;
   }

   return found;

   /*  recurive method

   return isExist(mRootNode, searchKey);
*/
}

/*
template <typename T>
bool BST<T>::isExist(Node<T> *node, T searchKey)
{
   if (node == NULL)
      return false;

   if (tmp->mData == searchKey)
      return true;
   else if (tmp->mData > searchKey)
      return isExist(tmp->mLeft, searchKey);
   else
      return isExist(tmp->mRight, searchKey);
}
*/

/*      Pre:  None
 *     Post:  The number of leave nodes is returned
 *  Purpose:  To determine the number of leave nodes in the BST
 **************************************************************/
template <typename T>
int BST<T>::leavesCount()
{
   Queue<Node<T> *> queue;
   Node<T> *tmp;
   int count = 0;

   queue.enqueue(mRootNode);
   while (!queue.isEmpty())
   {
      tmp = queue.dequeue();
      if (tmp->mRight == NULL && tmp->mLeft == NULL)
         count++;
      if (tmp->mRight != NULL)
         queue.enqueue(tmp->mRight);
      if (tmp->mLeft != NULL)
         queue.enqueue(tmp->mLeft);
   }
   return count;
}

/*      Pre:  A node within the BST
 *     Post:  The node is deleted from the BST
 *  Purpose:  A private function that delete the node from the
 *            BST.  If the node has only one child, then the
 *            child will serve as the new root node for that
 *            branch.  However, if the node has two children,
 *            then the right child will serve as the new root
 *            node for the branch.
 **************************************************************/
template <typename T>
void BST<T>::makeDeletion(Node<T> *&node)
{
   Node<T> *toBeDeleted = node;
   Node<T> *attachPoint;

   if (node->mRight == NULL)
   {
      node = node->mLeft;
   }
   else if (node->mLeft == NULL)
   {
      node = node->mRight;
   }
   else
   {
      attachPoint = node->mRight;

      while (attachPoint->mLeft != NULL)
         attachPoint = attachPoint->mLeft;

      attachPoint->mLeft = node->mLeft;

      node = node->mRight;
   }

   delete toBeDeleted;
}

/*      Pre:  None
 *     Post:  The number of nodes is returned
 *  Purpose:  To determine the number of nodes in the BST
 **************************************************************/
template <typename T>
int BST<T>::nodesCount()
{
   Queue<Node<T> *> queue;
   Node<T> *tmp;
   int count = 0;

   queue.enqueue(mRootNode);
   while (!queue.isEmpty())
   {
      tmp = queue.dequeue();
      count++;
      if (tmp->mRight != NULL)
         queue.enqueue(tmp->mRight);
      if (tmp->mLeft != NULL)
         queue.enqueue(tmp->mLeft);
   }
   return count;
}

/*      Pre:  None
 *     Post:  The path from the root node to the search key is
 *            displayed on the screen or an error message
 *            indicating the search key does not exist
 *  Purpose:  To display the path from the root node to the
 *            search key is displayed on the screen.  If the
 *            search key does not exist in the BST, a message
 *            indicating the search key does not exist in the
 *            BST
 **************************************************************/
template <typename T>
void BST<T>::printPath(T searchKey)
{
   stringstream ss;
   Node<T> *tmp = mRootNode;
   while (tmp != NULL)
   {
      ss << tmp->mData;
      if (tmp->mData == searchKey)
      {
         cout << ss.str() << endl;
         return;
      }
      if (searchKey > tmp->mData)
      {
         tmp = tmp->mRight;
      }
      else
      {
         tmp = tmp->mLeft;
      }
      ss << ", ";
   }
   cout << "Search key is not found in the tree\n";
}

/*      Pre:  A search key
 *     Post:  The search key is removed from the BST
 *  Purpose:  To remove a value from a BST
 **************************************************************/
template <typename T>
void BST<T>::remove(T searchKey)
{
   remove(mRootNode, searchKey);
}

/*      Pre:  A node within the BST and a search key
 *     Post:  The search key is removed from the BST if the
 *            value exists
 *  Purpose:  A private function that to remove a value from a
 *            BST recursively.  This function will find the node
 *            where the value occur.  Once the node is found,
 *            call makeDeletion to complete the process.
 **************************************************************/
template <typename T>
void BST<T>::remove(Node<T> *&node, const T &searchKey)
{
   if (node == NULL)
      return;
   else if (node->mData > searchKey)
      remove(node->mLeft, searchKey);
   else if (node->mData < searchKey)
      remove(node->mRight, searchKey);
   else
      makeDeletion(node);
}

/*      Pre:  None
 *     Post:  The entire BST is displayed using in-order format
 *  Purpose:  A function that display the entire BST using
 *            in-order format.  This function will call
 *            displayInOrder to complete the process
 **************************************************************/
template <typename T>
void BST<T>::showInOrder()
{
   displayInOrder(mRootNode);
}

/*      Pre:  None
 *     Post:  The entire BST is displayed using pre-order format
 *  Purpose:  A function that display the entire BST using
 *            pre-order format.  This function will call
 *            displayPreOrder to complete the process
 **************************************************************/
template <typename T>
void BST<T>::showPreOrder()
{
   displayPreOrder(mRootNode);
}

/*      Pre:  None
 *     Post:  The entire BST is displayed using post-order format
 *  Purpose:  A function that display the entire BST using
 *            post-order format.  This function will call
 *            displayPostOrder to complete the process
 **************************************************************/
template <typename T>
void BST<T>::showPostOrder()
{
   displayPostOrder(mRootNode);
}

/*      Pre:  None
 *     Post:  The entire BST is displayed
 *  Purpose:  A function that display the entire BST.  This
 *            function will call displayTree to complete the
 *            process
 **************************************************************/

template <typename T>
void BST<T>::showTree()
{
   displayTree(mRootNode, 0);
}

#endif