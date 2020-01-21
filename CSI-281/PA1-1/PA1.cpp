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

#include <iostream>
#include "linkedList.h"
#include "functions.h"
#include "data.h"

    using namespace std;

int main()
{
   Node *head;
   Data dataSet;

   head = readData();

   Node *curser = head;
   while (curser != nullptr)
   {
      dataSet.incNumberOfRecords();
      for (int i = 0; !curser->data.eof(); i++)
      {
         if (dataSet.getColsSize() <= i)
         {
            dataSet.newCol();
         }

         string val;
         curser->data >> val;
         dataSet.addVal(i, val[0]);
      }
      curser = curser->child;
   }

   writeData(dataSet);

   deleteList(head);
}
