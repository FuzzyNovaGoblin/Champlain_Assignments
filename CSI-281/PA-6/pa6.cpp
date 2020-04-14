/*
Author:       Grant Hedley
Class: 	      CSI-281 - 01
Assignment: PA6
Due Date: 4/14/20
Description: stub driver for BST

Certification of Authenticity:
I certify that this is entirely my own work, except where I have given
fully-documented references to the work of others. I understand the definition
andconsequences of plagiarism and acknowledge that the assessor of this assignment
may, for the purpose of assessing this assignment:
- Reproduce this assignment and provide a copy to another member of academic staff; and/or
- Communicate a copy of this assignment to a plagiarism checking service(which may then
  retain a copy of this assignment on its database for the purpose of future plagiarism
  checking)
*/

#include <iostream>
#include "bst.h"

int main(){
   BST<int> bst;

   cout << "Testing isEmpty, expecting true, received "
        << (bst.isEmpty() ? "true" : "false") << endl;
   cout << endl;

   int arr[] = {5,3,8,1,4};
   for (int i = 0; i < 5; i++)
   {
      bst.insert(arr[i]);
   }

   cout << "Testing nodesCount, expecting 5, received "
        << bst.nodesCount() << endl;
   cout << endl;

   cout << "Testing getHeight, expecting 2, received "
        << bst.getHeight() << endl;
   cout << endl;

   cout << "Testing printPath for 4:"  << endl;
   bst.printPath(4);
   cout << endl;

   cout << "Testing printPath for 10:" << endl;
   bst.printPath(10);
   cout << endl;

   cout << "Testing showTree:" << endl;
   bst.showTree();
   cout << endl;

   cout << "Testing bfs for 4:" << endl;
   bst.bfs(4);
   cout << endl;

   cout << "Testing bfs for 10:" << endl;
   bst.bfs(10);
   cout << endl;
   cout << endl;

   cout << "Testing dfs for 4:" << endl;
   bst.dfs(4);
   cout << endl;

   cout << "Testing dfs for 10:" << endl;
   bst.dfs(10);
   cout << endl;
}