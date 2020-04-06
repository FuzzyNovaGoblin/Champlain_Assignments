#include <iostream>
#include "doublylinkedlist.h"
#include "linkedlist.h"
#include "timerSys.h"
#include <random>
#include <fstream>

using namespace std;

void testLinkedList(int dataArr[]);
void testDoublyLinkedList(int dataArr[]);
void testArray(int dataArr[]);

int main(int argc, char **argv)
{
   srand(time(NULL));
   int dataArr[100000];

   if (argc < 2)
   {
      cout << "Give a value between 0 and 3\n";
      return 1;
   }
   if (argv[1][0] == '0')
   {
      ofstream file("out.data");
      for (int i = 0; i < 100000; i++)
      {
         file << rand() % 1000 << " ";
      }
      file.close();
   }
   else
   {
      ifstream inFile("out.data");
      int buff, i = 0;

      while (!inFile.eof())
      {
         inFile >> buff;
         dataArr[i] = buff;
         i++;
      }
      if (argv[1][0] == '1')
      {
         testLinkedList(dataArr);
      }
      else if (argv[1][0] == '2')
      {
         testDoublyLinkedList(dataArr);
      }
      else if (argv[1][0] == '3')
      {
         testArray(dataArr);
      }
   }
}

void testLinkedList(int dataArr[])
{
   LinkedList<int> ll;
   Timer timer;
   ofstream outFile("test.txt", ios_base::app);
   outFile << "Test LinkedList" << endl;

   //insert 100,000 elements
   timer.start();
   for (int i = 0; i < 100000; i++)
   {
      ll.insert(dataArr[i]);
   }
   cout << endl;
   timer.stop();
   cout << timer.getTimeReadable() << endl;
   outFile << "\tmake 100,000 insertions: " << timer.getTimeReadable() << endl;

   // get 100,000 elements
   timer.start();
   for (int i = 0; i < 100000; i++)
   {
      ll[dataArr[i]];
   }
   timer.stop();
   cout << timer.getTimeReadable() << endl;
   outFile << "\tretrive 1,000 random elements: " << timer.getTimeReadable() << endl;

   //display all elemanets
   timer.start();
   ll.display();
   timer.stop();
   cout << timer.getTimeReadable() << endl;
   outFile << "\ttraverse and print all elements: " << timer.getTimeReadable() << endl;

   //display all elemanets backwards
   timer.start();
   for (int i = 99999; i >= 0; i--)
   {
      cout << ll[i] << " ";
   }
   cout << endl;
   timer.stop();
   cout << timer.getTimeReadable() << endl;
   outFile << "\ttraverse and print all elements: " << timer.getTimeReadable() << endl;

   //delete all
   timer.start();
   ll.clear();
   timer.stop();
   cout << timer.getTimeReadable() << endl;
   outFile << "\tdelete all elements: " << timer.getTimeReadable() << endl;
}

void testDoublyLinkedList(int dataArr[])
{
   DoublyLinkedList<int> dll;
   Timer timer;

   ofstream outFile("test.txt", ios_base::app);
   outFile << "Test DoublyLinkedList" << endl;

   //insert 100,000 elements
   timer.start();
   for (int i = 0; i < 100000; i++)
   {
      dll.insert(dataArr[i]);
   }
   cout << endl;
   timer.stop();
   cout << timer.getTimeReadable() << endl;
   outFile << "\tmake 100,000 insertions: " << timer.getTimeReadable() << endl;

   // get 100,000 elements
   timer.start();
   for (int i = 0; i < 100000; i++)
   {
      dll.getData(dataArr[i]);
   }
   timer.stop();
   cout << timer.getTimeReadable() << endl;
   outFile << "\tretrive 1,000 random elements: " << timer.getTimeReadable() << endl;

   //display all elemanets
   timer.start();
   dll.display();
   timer.stop();
   cout << timer.getTimeReadable() << endl;
   outFile << "\ttraverse and print all elements: " << timer.getTimeReadable() << endl;

   //display all elemanets backwards
   timer.start();
   dll.displayInReverse();
   cout << timer.getTimeReadable() << endl;
   outFile << "\ttraverse and print all elements backwards: " << timer.getTimeReadable() << endl;

   //delete all
   timer.start();
   dll.clear();
   cout << timer.getTimeReadable() << endl;
   outFile << "\tdelete all elements: " << timer.getTimeReadable() << endl;
}
void testArray(int dataArr[])
{
   int arr[100000];
   Timer timer;
   ofstream outFile("test.txt", ios_base::app);
   outFile << "Test Array" << endl;

   //insert 100,000 elements
   timer.start();
   for (int i = 0; i < 100000; i++)
   {
      arr[i] = dataArr[i];
   }

   cout << endl;
   timer.stop();
   cout << timer.getTimeReadable() << endl;
   outFile << "\tmake 100,000 insertions: " << timer.getTimeReadable() << endl;

   // get 100,000 elements
   timer.start();
   for (int i = 0; i < 100000; i++)
   {
      arr[dataArr[i]];
   }
   timer.stop();
   cout << timer.getTimeReadable() << endl;
   outFile << "\tretrive 1,000 random elements: " << timer.getTimeReadable() << endl;

   //display all elemanets
   timer.start();
   for (int i = 0; i < 100000; i++)
   {
      cout << arr[i] << " ";
   }
   cout << endl;
   timer.stop();
   cout << timer.getTimeReadable() << endl;
   outFile << "\ttraverse and print all elements: " << timer.getTimeReadable() << endl;

   //display all elemanets backwards
   timer.start();
   for (int i = 99999; i >= 0; i--)
   {
      cout << arr[i] << " ";
   }
   cout << endl;
   timer.stop();
   cout << timer.getTimeReadable() << endl;
   outFile << "\ttraverse and print all elements: " << timer.getTimeReadable() << endl;

   //delete all
   timer.start();
   for (int i = 0; i < 100000; i++)
   {
      arr[i] = 0;
   }
   timer.stop();
   cout << timer.getTimeReadable() << endl;
   outFile << "\tdelete all elements: " << timer.getTimeReadable() << endl;
}