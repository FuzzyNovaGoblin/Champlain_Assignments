/* ***       Author:  Grant Hedley
     *  Last Update:  March 31, 2020
     *        Class:  CSI-281
     *     Filename:  bst.h
     *
     *  Description:
     *      This is the template binary search tree definition.
     *
     *  Certification of Authenticity:
     *     I certify that this assignment is entirely my work.
     **********************************************************/

#ifndef _BST_H
#define _BST_H


using namespace std;

template <typename T, typename V>
class BST
{
private:
   template <typename R, typename S>
   struct Node
   {
      R mData;
      S mValue;
      Node<R, S> *mLeft, *mRight;

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
      Node(R data, Node<R,S> *left, Node<R,S> *right)
      {
         mData = data;
         mLeft = left;
         mRight = right;
      }
   };

   Node<T,V> *mRootNode;

   BST(T data, Node<T,V> *left, Node<T,V> *right);

   void destroySubtree(Node<T, V> *&node);
   void displayInOrder(Node<T,V> *node);
   void insert(Node<T,V> *&node, const T &data);
   void makeDeletion(Node<T,V> *&node);
   void remove(Node<T,V> *&node, const T &searchKey);

public:
   BST();
   ~BST();

   void clear();
   void insert(T data);
   bool isEmpty();
   bool isExists(T searchKey);
   void remove(T searchKey);
   void showInOrder();
   void showTree();
   V &get(T key);
};

/*      Pre:  None
 *     Post:  The root node of the BST is initialized to NULL
 *  Purpose:  Default constructor
 **************************************************************/
template <typename T, typename V>
BST<T,V>::BST()
{
   mRootNode = NULL;
}

/*      Pre:  data, left pointer and right pointer
 *     Post:  The root node of the BST is initialized to the
 *            new root node with both left and right child
 *  Purpose:  Constructor
 **************************************************************/
template <typename T, typename V>
BST<T,V>::BST(T data, Node<T,V> *left, Node<T,V> *right)
{
   Node<T,V> *newNode;

   newNode = new Node<T,V>(data, left, right);
   if (newNode != NULL)
      mRootNode = newNode;
}

/*      Pre:  The BST is instantiated
 *     Post:  The root node of the BST is initialized to NULL
 *  Purpose:  Default constructor
 **************************************************************/
template <typename T, typename V>
BST<T,V>::~BST()
{
   destroySubtree(mRootNode);

   mRootNode = NULL;
}


/*      Pre:  The BST is instantiated
 *     Post:  The entire BST is deleted
 *  Purpose:  To clear the entire BST
 **************************************************************/
template <typename T, typename V>
void BST<T,V>::clear()
{
   destroySubtree(mRootNode);
}

/*      Pre:  A node within the BST
 *     Post:  All the subtree branching from the node (including
 *            the node) is deleted
 *  Purpose:  To delete a subtree
 **************************************************************/
template <typename T, typename V>
void BST<T, V>::destroySubtree(Node<T, V> *&node)
{
   if (node->mRight != NULL)
      destroySubtree(node->mRight);
   if (node->mLeft != NULL)
      destroySubtree(node->mLeft);
   delete node;
   node = NULL;
}

/*      Pre:  A node within a tree
 *     Post:  The entire BST is displayed using in-order format
 *  Purpose:  A private function that display the entire BST
 *            using in-order format.
 **************************************************************/
template <typename T, typename V>
void BST<T,V>::displayInOrder(Node<T,V> *node)
{
   if (node == NULL)
      return;
   displayInOrder(node->mLeft);
   cout << node->mData << " ";
   displayInOrder(node->mRight);
}




/*      Pre:  A data to insert into a BST
 *     Post:  A new data is inserted into a BST
 *  Purpose:  To insert a new value into a BST
 **************************************************************/
template <typename T, typename V>
void BST<T,V>::insert(T data)
{
   insert(mRootNode, data);
}

/*      Pre:  A node within a tree and the value to insert
 *     Post:  The new value is inserted into the BST
 *  Purpose:  A private function that insert a new data into a
 *            BST.  BST does not allow duplication of value.
 *            Hence, a duplicated value will not be inserted
 **************************************************************/
template <typename T, typename V>
void BST<T,V>::insert(Node<T,V> *&node, const T &data)
{
   if (node == NULL)
   {
      node = new Node<T,V>(data);
   }
   else if (node->mData == data)
   {
      return;
   }
   else if (node->mData < data)
   {
      insert(node->mRight, data);
   }
   else
   {
      insert(node->mLeft, data);
   }
}

/*      Pre:  None
 *     Post:  True if the BST is empty, otherwise false
 *  Purpose:  To determine if the BST is empty
 **************************************************************/
template <typename T, typename V>
bool BST<T,V>::isEmpty()
{
   return (mRootNode == NULL);
}

/*      Pre:  A search key
 *     Post:  True is return if the search key existed in the
 *            BST, otherwise false
 *  Purpose:  To search if a search key exists in the BST using
 *            the typical binary tree search
 **************************************************************/
template <typename T, typename V>
bool BST<T,V>::isExists(T searchKey)
{
   Node<T,V> tmp = mRootNode;

   while (tmp != NULL)
   {
      if (tmp->mData == searchKey)
         return true;
      else if (tmp->mData < searchKey)
         tmp = tmp->mRight;
      else
         tmp = tmp->mLeft;
   }

   return tmp != NULL;
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
template <typename T, typename V>
void BST<T,V>::makeDeletion(Node<T,V> *&node)
{
   Node<T,V> *toBeDeleted = node;
   Node<T,V> *attachPoint;

   if (node->mRight == NULL)
      node = node->mLeft;
   else if (node->mLeft == NULL)
      node = node->mRight;
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


/*      Pre:  A search key
 *     Post:  The search key is removed from the BST
 *  Purpose:  To remove a value from a BST
 **************************************************************/
template <typename T, typename V>
void BST<T,V>::remove(T searchKey)
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
template <typename T, typename V>
void BST<T,V>::remove(Node<T,V> *&node, const T &searchKey)
{
   if (node == NULL)
   {
      return;
   }
   else if (node->mData < searchKey)
   {
      remove(node->mRight, searchKey);
   }
   else if (node->mData > searchKey)
   {
      remove(node->mLeft, searchKey);
   }
   else
   {
      makeDeletion(node);
   }
}

/*      Pre:  None
 *     Post:  The entire BST is displayed using in-order format
 *  Purpose:  A function that display the entire BST using
 *            in-order format.  This function will call
 *            displayInOrder to complete the process
 **************************************************************/
template <typename T, typename V>
void BST<T,V>::showInOrder()
{
   displayInOrder(mRootNode);
}


/*      Pre:  None
 *     Post:  The entire BST is displayed
 *  Purpose:  A function that display the entire BST.  This
 *            function will call displayTree to complete the
 *            process
 **************************************************************/

template <typename T, typename V>
void BST<T,V>::showTree()
{
   displayTree(mRootNode, 0);
}

template <typename T, typename V>
V& BST<T,V>::get(T key){
   if(mRootNode == nullptr){
      mRootNode = new Node<T, V>(key);
      return mRootNode->mValue;
   }
   Node<T, V> *tmp = mRootNode;
   Node<T, V> *oneBefore = mRootNode;
   while (tmp != nullptr)
   {
      if(tmp->mData == key){
         return tmp->mValue;
      }
      else if (tmp->mData > key){
         oneBefore = tmp;
         tmp = tmp->mLeft;
      }
      else{
         oneBefore = tmp;
         tmp = tmp->mRight;
      }
   }

   if(key > oneBefore->mData){
      oneBefore->mRight = new Node<T,V>(key);
      return oneBefore->mRight->mValue;
   }
   else
   {
      oneBefore->mLeft = new Node<T, V>(key);
      return oneBefore->mLeft->mValue;
   }
}

#endif