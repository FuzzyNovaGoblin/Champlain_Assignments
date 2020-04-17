/* ***       Author:  Wei Kian Chen
     *  Modified by:
     *  Last Update:  April 10, 2020
     *        Class:  CSI-281
     *     Filename:  avl.h
     *
     *  Description:
     *      This is the template AVL tree definition.
     *
     *  Certification of Authenticity:
     *     I certify that this assignment is entirely my work.
     **********************************************************/

#ifndef _AVL_H
#define _AVL_H

#include <iostream>
#include <algorithm>
#include <

using namespace std;

template <typename T>
class AVL
{
   private:
      template <typename R>
      struct Node
      {
         R       mData;
         int     mHeight;
         Node<R> *mLeft, *mRight;

         /*      Pre:  None
          *     Post:  This object is initialized using default values
          *  Purpose:  To intialize date object
          *************************************************************************/
         Node()
         {
            mData   = R();
            mHeight = 1;
            mLeft   = NULL;
            mRight  = NULL;
         }


         /*      Pre:  None
          *     Post:  This object is initialized using specified data
          *  Purpose:  To intialize date object
          *************************************************************************/
         Node(R data)
         {
            mData   = data;
            mHeight = 1;
            mLeft   = NULL;
            mRight  = NULL;
         }


         Node(R data, Node<R> *left, Node<R> *right)
         {
            mData   = data;
            mHeight = 1;
            mLeft   = left;
            mRight  = right;
         }
      };

      Node<T> *mRootNode;

      AVL(T data, Node<T> *left, Node<T> *right);

      void destroySubtree(Node<T> *&node);
      void displayInOrder(Node<T> *node);
      void displayPreOrder(Node<T> *node);
      void displayPostOrder(Node<T> *node);
      void displayTree(Node<T> *node, int tab);
      int  getBalance(Node<T> *node);
      int  getHeight(Node<T> *node);
      void insert(Node<T> *&node, const T &data);
      int  maxHeight(Node<T> *node1, Node<T> *node2);
      void makeDeletion(Node<T> *&node);
      void remove(Node<T> *&node, const T &searchKey);
      void rotateLeft(Node<T> *&node);
      void rotateLeftRight(Node<T> *&node);
      void rotateRight(Node<T> *&node);
      void rotateRightLeft(Node<T> *&node);


   public:
      AVL();
      ~AVL();

      void insert(T data);
      bool isEmpty();
      bool isExists(T searchKey);
      void remove(T searchKey);
      void showInOrder();
      void showPreOrder();
      void showPostOrder();
      void showTree();
};


/*      Pre:  None
 *     Post:  The root node of the AVL is initialized to NULL
 *  Purpose:  Default constructor
 **************************************************************/
template <typename T>
AVL<T>::AVL()
{
   mRootNode = NULL;
}


/*      Pre:  The data to insert into the AVL, the left child
 *            and the right child of this new node
 *     Post:  The root node of the AVL is initialized to a new
 *            node with the specified left and right child
 *  Purpose:  Constructor
 **************************************************************/
template <typename T>
AVL<T>::AVL(T data, Node<T> *left, Node<T> *right)
{
   Node<T> *newNode;

   newNode = new Node<T>(data, left, right);

   if (newNode != NULL)
   {
	  newNode->mHeight = maxHeight(left, right) + 1;
      mRootNode = newNode;
   }
}


/*      Pre:  The AVL tree is instantiated
 *     Post:  The entire AVL tree is deleted and the root node
 *            reset back to NULL
 *  Purpose:  Destructor
 **************************************************************/
template <typename T>
AVL<T>::~AVL()
{
   destroySubtree(mRootNode);
}


/*      Pre:  A node within the AVL
 *     Post:  All the subtree branching from the node (including
 *            the node) is deleted
 *  Purpose:  To delete a subtree
 **************************************************************/
template <typename T>
void AVL<T>::destroySubtree(Node<T> *&node)
{
   if (node == NULL)
      return;

   destroySubtree(node->mLeft);
   destroySubtree(node->mRight);

   // Delete the node at the root.
   delete node;
   node = NULL;
}


/*      Pre:  A node within a tree
 *     Post:  The entire AVL is displayed using in-order format
 *  Purpose:  A private function that display the entire AVL
 *            using in-order format.
 **************************************************************/
template <typename T>
void AVL<T>::displayInOrder(Node<T> *node)
{
}


/*      Pre:  A node within a tree
 *     Post:  The entire AVL is displayed using pre-order format
 *  Purpose:  A private function that display the entire AVL
 *            using pre-order format.
 **************************************************************/
template <typename T>
void AVL<T>::displayPreOrder(Node<T> *node)
{
}


/*      Pre:  A node within a tree
 *     Post:  The entire AVL is displayed using post-order format
 *  Purpose:  A private function that display the entire AVL
 *            using post-order format.
 **************************************************************/
template <typename T>
void AVL<T>::displayPostOrder(Node<T> *node)
{
}


/*      Pre:  A node within a tree
 *     Post:  The entire AVL is displayed
 *  Purpose:  A private function that display the entire AVL
 **************************************************************/
template <typename T>
void AVL<T>::displayTree(Node<T> *node, int tab)
{
   cout << ws
}


/*      Pre:  A node within a tree
 *     Post:  The balance factor of the node is returned
 *  Purpose:  A private function that compute the balance factor
 *            for a given node.  The balance factor is computed
 *            by using the H(R) - H(L)
 **************************************************************/
template <typename T>
int AVL<T>::getBalance(Node<T> *node)
{
   return node->mRight->mHeight - node->mLeft->mHeight;
}


/*      Pre:  A node within a tree
 *     Post:  The height of the node within AVL is returned
 *  Purpose:  A private function that return the height facot
 *            of a node in AVL
 **************************************************************/
template <typename T>
int AVL<T>::getHeight(Node<T> *node)
{
   if (node == NULL)
      return 0;
   else
      return node->mHeight;
}


/*      Pre:  A data to insert into an AVL
 *     Post:  A new data is inserted into an AVL
 *  Purpose:  To insert a new value into an AVL
 **************************************************************/
template <typename T>
void AVL<T>::insert(T data)
{
   insert(mRootNode, data);
}


/*      Pre:  A node within a tree and the value to insert
 *     Post:  The new value is inserted into the AVL if the value
 *            does not already existed
 *  Purpose:  A private function that insert a new data into an
 *            AVL.  AVL does not allow duplication of value.
 *            Hence, a duplicated value will not be inserted.
 *            The tree will be balanced so that it is in its
 *            optimal stage for searching later.  So, the balance
 *            factor will be check from the newly inserted value
 *            to root node.  The acceptable balance factors are
 *            {-1, 0, 1}.
 **************************************************************/
template <typename T>
void AVL<T>::insert(Node<T> *&node, const T &data)
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
   if (data < node->mData)
   {
      insert(node->mLeft, data);
   }
   else
   {
      insert(node->mRight, data);
   }
}


/*      Pre:  None
 *     Post:  True if the AVL is empty, otherwise false
 *  Purpose:  To determine if the AVL is empty
 **************************************************************/
template <typename T>
bool AVL<T>::isEmpty()
{
   return (mRootNode == NULL);
}


/*      Pre:  A search key
 *     Post:  True is return if the search key existed in the
 *            AVL, otherwise false
 *  Purpose:  To search if a search key exists in the AVL using
 *            the typical binary tree search
 **************************************************************/
template <typename T>
bool AVL<T>::isExists(T searchKey)
{
   Node<T> *tmp = mRootNode;

   while (tmp != NULL)
   {
      if (tmp->mData == searchKey)
         return true;
      else if (tmp->mData > searchKey)
         tmp = tmp->mLeft;
      else
         tmp = tmp->mRight;
   }
   return false;
}


/*      Pre:  A node within the AVL
 *     Post:  The node is deleted from the AVL if it existed
 *  Purpose:  A private function that delete the node from the
 *            AVL.  If the node has only one child, then the
 *            child will serve as the new root node for that
 *            branch.  However, if the node has two children,
 *            then the right child will serve as the new root
 *            node for the branch.  Once the deletion is
 *            completed, the height and balance factor for the
 *            new root will be computed.  If the tree is out of
 *            balance, it will be rotated.  The acceptable
 *            balance factors are {-1, 0, 1}.
 **************************************************************/
template <typename T>
void AVL<T>::makeDeletion(Node<T> *&node)
{
   // Used to hold node that will be deleted.
   Node<T> *nodeToDelete = node;

   // Used to locate the  point where the
   // left subtree is attached.
   Node<T> *attachPoint;

   // Replace tree with its left subtree.
   if (node->mRight == NULL)
   {
      node = node->mLeft;
   }
   // Replace tree with its right subtree.
   else if (node->mLeft == NULL)
   {
      node = node->mRight;
   }
   else
   {
      // Move to right subtree.
      attachPoint = node->mRight;

      // Locate the smallest node in the right subtree
      // by moving as far to the left as possible.
      while (attachPoint->mLeft != NULL)
      {
         attachPoint = attachPoint->mLeft;
      }

      // Attach the left subtree of the original tree
      // as the left subtree of the smallest node
      // in the right subtree.
      attachPoint->mLeft = node->mLeft;

      // Replace the original tree with its right subtree.
      node = node->mRight;
   }

   nodeToDelete->mLeft = NULL;
   nodeToDelete->mRight = NULL;

   // Delete root of original tree
   delete nodeToDelete;
}


/*      Pre:  Two nodes
 *     Post:  The higher high value for the two nodes is returned
 *  Purpose:  To determine the highest high value for the two
 *            given nodes
 **************************************************************/
template <typename T>
int AVL<T>::maxHeight(Node<T> *node1, Node<T> *node2)
{
}


/*      Pre:  A search key
 *     Post:  The search key is removed from the AVL
 *  Purpose:  To remove a value from a AVL
 **************************************************************/
template <typename T>
void AVL<T>::remove(T searchKey)
{
   remove(mRootNode, searchKey);
}


/*      Pre:  A node within the AVL and a search key
 *     Post:  The search key is removed from the AVL if the
 *            value exists
 *  Purpose:  A private function that to remove a value from a
 *            AVL recursively.  This function will find the node
 *            where the value occur.  Once the node is found,
 *            call makeDeletion to complete the process.  And,
 *            the balance factor will be check and the tree will
 *            be rotated when needed to keep the tree is its
 *            optimal stage.  The acceptable balance factors are
 *            {-1, 0, 1}
 **************************************************************/
template <typename T>
void AVL<T>::remove(Node<T> *&node, const T &searchKey)
{
   if (node == NULL)
      return;
   else if (node->mData > searchKey)
   {
      remove(node->mLeft, searchKey);
   }
   else if (node->mData < searchKey)
   {
      remove(node->mRight, searchKey);
   }
   else
   {
      // We have found the node to delete.
      makeDeletion(node);
   }
}


/*      Pre:  None
 *     Post:  The entire AVL is displayed using in-order format
 *  Purpose:  A function that display the entire AVL using
 *            in-order format.  This function will call
 *            displayInOrder to complete the process
 **************************************************************/
template <typename T>
void AVL<T>::showInOrder()
{
   displayInOrder(mRootNode);
}


/*      Pre:  None
 *     Post:  The entire AVL is displayed using pre-order format
 *  Purpose:  A function that display the entire AVL using
 *            pre-order format.  This function will call
 *            displayPreOrder to complete the process
 **************************************************************/
template <typename T>
void AVL<T>::showPreOrder()
{
   displayPreOrder(mRootNode);
}


/*      Pre:  None
 *     Post:  The entire AVL is displayed using post-order format
 *  Purpose:  A function that display the entire AVL using
 *            post-order format.  This function will call
 *            displayPostOrder to complete the process
 **************************************************************/
template <typename T>
void AVL<T>::showPostOrder()
{
   displayPostOrder(mRootNode);
}


/*      Pre:  None
 *     Post:  The entire AVL is displayed
 *  Purpose:  A function that display the entire AVL.  This
 *            function will call displayTree to complete the
 *            process
 **************************************************************/
template <typename T>
void AVL<T>::showTree()
{
   displayTree(mRootNode, 0);
}


/*      Pre:  A node
 *     Post:  The node is rotated to the left
 *  Purpose:  A private function that rotate the node to the
 *            left when its balance factor is 2 which means it
 *            is too heavy on the right.  If the tree is
 *                  A
 *                   \
 *                    B
 *                     \
 *                      C
 *            the resulting tree is
 *                   B
 *                  / \
 *                 A   C
 *            the height factor for all nodes involved will be
 *            recalculated
 **************************************************************/
template <typename T>
void AVL<T>::rotateLeft(Node<T> *&node)
{
}


/*      Pre:  A node
 *     Post:  The node is rotated using the left right rotation
 *  Purpose:  A private function that rotate the node to the
 *            left first than right when its balance factor is
 *            -2 but its left child is 1 means it is too heavy
 *            on the left but it needs double rotation.  If the
 *            tree is
 *                      C
 *                     /
 *                    A
 *                     \
 *                      B
 *            the resulting tree is
 *                   B
 *                  / \
 *                 A   C
 *            the height factor for all nodes involved will be
 *            recalculated
 **************************************************************/
template <typename T>
void AVL<T>::rotateLeftRight( Node<T> *&node)
{
}


/*      Pre:  A node
 *     Post:  The node is rotated to the right
 *  Purpose:  A private function that rotate the node to the
 *            left when its balance factor is -2 which
 *            means it is too heavy on the left.  If the tree
 *            is
 *                         C
 *                        /
 *                       B
 *                      /
 *                     A
 *            the resulting tree is
 *                   B
 *                  / \
 *                 A   C
 *            the height factor for all nodes involved will be
 *            recalculated
 **************************************************************/
template <typename T>
void AVL<T>::rotateRight( Node<T> *&node)
{
}


/*      Pre:  A node
 *     Post:  The node is rotated using the right left rotation
 *  Purpose:  A private function that rotate the node to the
 *            right first than left when its balance factor is
 *            2 but its left child is -1 means it is too heavy
 *            on the right but it needs double rotation.  If the
 *            tree is
 *                      A
 *                       \
 *                        C
 *                       /
 *                      B
 *            the resulting tree is
 *                   B
 *                  / \
 *                 A   C
 *            the height factor for all nodes involved will be
 *            recalculated
 **************************************************************/
template <typename T>
void AVL<T>::rotateRightLeft(Node<T> *&node)
{
}


#endif