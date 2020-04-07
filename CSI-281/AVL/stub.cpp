#include <iostream>
#include "avl.h"

using namespace std;

int main()
{
   AVL<int> tree;
   int i;

   cout << "inserting:  3\n";
   tree.insert(3);
   tree.showTree();
   cout << endl;

   cout << "inserting:  1\n";
   tree.insert(1);
   tree.showTree();
   cout << endl;

   cout << "inserting:  7\n";
   tree.insert(7);
   tree.showTree();
   cout << endl;

   cout << "inserting:  0\n";
   tree.insert(0);
   tree.showTree();
   cout << endl;

   cout << "inserting:  2\n";
   tree.insert(2);
   tree.showTree();
   cout << endl;

   cout << "inserting:  5\n";
   tree.insert(5);
   tree.showTree();
   cout << endl;

   cout << "inserting:  9\n";
   tree.insert(9);
   tree.showTree();
   cout << endl;

   cout << "inserting:  4\n";
   tree.insert(4);
   tree.showTree();
   cout << endl;

   cout << "inserting:  6\n";
   tree.insert(6);
   tree.showTree();
   cout << endl;

   cout << "inserting:  8\n";
   tree.insert(8);
   tree.showTree();
   cout << endl;

   cout << "inserting:  10\n";
   tree.insert(10);
   tree.showTree();
   cout << endl << endl;

   cout << "deleting:  0\n";
   tree.remove(0);
   tree.showTree();
   cout << endl;

   cout << "deleting:  2\n";
   tree.remove(2);
   tree.showTree();
   cout << endl;

   cout << "deleting:  3\n";
   tree.remove(3);
   tree.showTree();
   cout << endl;

   cout << "deleting:  8\n";
   tree.remove(8);
   tree.showTree();
   cout << endl;

   cout << "deleting:  5\n";
   tree.remove(5);
   tree.showTree();
   cout << endl;

   cout << "deleting:  7\n";
   tree.remove(7);
   tree.showTree();
   cout << endl;

   cout << "deleting:  10\n";
   tree.remove(10);
   tree.showTree();
   cout << endl;

   //for (i = 0; i < 9; i++)
   //{
   //   cout << "Inserting:  " << i << "\n";
   //   tree.insert(i);
   //   tree.showTree();
   //}

   //cout << "Deleting:  7\n";
   //tree.remove(7);
   //tree.showTree();

   //cout << "Deleting:  5\n";
   //tree.remove(5);
   //tree.showTree();

   //cout << "Deleting:  3\n";
   //tree.remove(3);
   //tree.showTree();

   //cout << "Deleting:  2\n";
   //tree.remove(2);
   //tree.showTree();

   //cout << "Deleting:  4\n";
   //tree.remove(4);
   //tree.showTree();

   //cout << "Deleting:  6\n";
   //tree.remove(6);
   //tree.showTree();


   //for (i = 0; i <= 10; i+=2)
   //{
   //   cout << "Inserting:  " << i << "\n";
   //   tree.insert(i);
   //   tree.showTree();
   //}

   //for (i = 1; i <= 10; i+=2)
   //{
   //   cout << "Inserting:  " << i << "\n";
   //   tree.insert(i);
   //   tree.showTree();
   //}

   //for (i = 10; i >= 0; i--)
   //{
   //   cout << "Inserting:  " << i << "\n";
   //   tree.insert(i);
   //   tree.showTree();
   //}

   //cout << "Inserting:  3\n";
   //tree.insert(3);
   //tree.showTree();

   //cout << "Inserting:  2\n";
   //tree.insert(2);
   //tree.showTree();

   //cout << "Inserting:  1\n";
   //tree.insert(1);
   //tree.showTree();

   //cout << "Inserting:  4\n";
   //tree.insert(4);
   //tree.showTree();

   //cout << "Inserting:  5\n";
   //tree.insert(5);
   //tree.showTree();

   //cout << "Inserting:  6\n";
   //tree.insert(6);
   //tree.showTree();

   //cout << "Inserting:  7\n";
   //tree.insert(7);
   //tree.showTree();

   //cout << "Inserting:  16\n";
   //tree.insert(16);
   //tree.showTree();

   //cout << "Inserting:  15\n";
   //tree.insert(15);
   //tree.showTree();

   //cout << "Inserting:  14\n";
   //tree.insert(14);
   //tree.showTree();

   //cout << "Deleting:  2\n";
   //tree.remove(2);
   //tree.showTree();

   //cout << "Deleting:  3\n";
   //tree.remove(3);
   //tree.showTree();

   //cout << "Deleting:  1\n";
   //tree.remove(1);
   //tree.showTree();


   //cout << "Deleting:  14\n";
   //tree.remove(14);
   //tree.showTree();

   //cout << "Deleting:  15\n";
   //tree.remove(15);
   //tree.showTree();

   system("pause");

   return 0;
}