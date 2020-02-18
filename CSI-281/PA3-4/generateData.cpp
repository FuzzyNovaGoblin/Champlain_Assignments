/*
Author:       Grant Hedley
Class: 	      CSI-281 - 01
Assignment: PA3
Date Assigned: 2/14/20
Due Date: 2/28/20
Description: quick sort and merge sort algorithems

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

#include "generateData.h"

/*      Pre:  none
 *     Post:  dataset file
 *  Purpose:  to generate a dataset file with compleetly random values
 ************************************************************************/

void generatDataSet1()
{
   ofstream outFile(DATA_SET_1_FILE);
   // int data[N3];
   for(int i = 0; i < N3; i++){
      // data[i] =
      outFile << rand() % N3 + 1 << ' ';
   }
   outFile.close();
}

/*      Pre:  none
 *     Post:  dataset file
 *  Purpose:  to generate a dataset file with the best case senario for sorting
 ************************************************************************/
void generatDataSet2()
{
   ofstream outFile(DATA_SET_2_FILE);
   int data[N3];
   for (int i = 0; i < N3; i++)
   {
      data[i] = rand() % N3 + 1;
   }

   quickSort(data, 0, N3 - 1);

   for (int i = 0; i < N3; i++)
   {
      outFile << data[i]<<' ';
   }
   outFile.close();
}

/*      Pre:  none
 *     Post:  dataset file
 *  Purpose:  to generate a dataset file with the wost case senario for sorting
 ************************************************************************/
void generatDataSet3()
{
   ofstream outFile(DATA_SET_3_FILE);
   int data[N3];
   for (int i = 0; i < N3; i++)
   {
      data[i] = rand() % N3 + 1;
   }

   quickSort(data, 0, N3 - 1);

   for (int i = N3-1; i >= 0; i--)
   {
      outFile << data[i]<<' ';
   }
   outFile.close();
}