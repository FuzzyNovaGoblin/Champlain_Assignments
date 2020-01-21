/*
Author: Frodo Baggins
Class: CSI-281 - 01
Assignment: PA1
Date Assigned: 01/14/20
Due Date: 01/21/20
Description: Analyzing data sets

A brief description of the purpose of the program.
Certification of Authenticity:
I certify that this is entirely my own work, except where I have given fully
-
documented references to the work of others. I und
erstand the definition and
consequences of plagiarism and acknowledge that the assessor of this assignment
may, for the purpose of assessing this assignment:
-
Reproduce  this  assignment  and  provide  a  copy  to  another  member  of
academic staff; and/or
-
Communica
te a copy of this assignment to a plagiarism checking service
(which may then retain a copy of this assignment on its database for
the purpose of future plagiarism checking
*/

#include "functions.h"

    using namespace std;

void deleteList(Node *head)
{
   Node *tmp;
   while (head != nullptr)
   {
      tmp = head;
      head = head->child;
      delete tmp;
   }
   tmp = nullptr;
}

void getFileName(string &name, string ask)
{
   cout << "Enter input file name:\n";

   do
   {
      getline(cin, name);
      if (!validateFileName(name))
      {
         cout << "That is not a valid file name\n";
      }
   } while (!validateFileName(name));
}

bool validateFileName(string name)
{
   bool valid = false;

   if (name.length() == 0)
      return false;
   for (int i = 0; i < name.length(); i++)
   {
      if ((int)name[i] > 32 && (int)name[i] <= 126)
      {
         valid = true;
      }
      else if ((int)name[i] < 32 || (int)name[i] > 126)
      {
         return false;
      }
   }
   return valid;
}

Node *readData()
{
   string fileName, buffer;
   Node *head, *currentNode, *tmp;
   ifstream file;

   head = new Node("head");
   currentNode = head;

   getFileName(fileName, " input ");

   file.open(fileName);

   while (!file.eof())
   {
      getline(file, buffer);
      for (int i = 0; i < buffer.length(); i++)
      {
         if ((int)buffer[i] == 44)
         {
            buffer[i] = ' ';
         }
      }
      if (buffer.length() > 0)
      {
         currentNode->child = new Node(buffer);
         currentNode = currentNode->child;
      }
   }
   currentNode = nullptr;

   tmp = head->child;
   delete head;
   head = nullptr;

   return tmp;
}

void writeData(Data &ds)
{
   string outFileName;
   ofstream outFile;

   getFileName(outFileName, " output ");
   outFile.open(outFileName);
   outFile << ds.toString() << endl;
   outFile.close();
}