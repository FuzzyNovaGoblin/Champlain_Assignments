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

#include <iostream>
#include "runSorts.h"
#include "functions.h"
#include "generateData.h"
#include "timerSys.h"

using namespace std;

int main(int argc, char **argv)
{
   bool runSort[7] = {true, false, true, true, true, true, true};

   srand(time(NULL));
   Timer timer;

   generatDataSet1();
   generatDataSet2();
   generatDataSet3();

   if (argc > 1 && ((string)argv[1]).length() == 7)
   {
      for (int i = 0; i < 7; i++)
      {
         if (argv[1][i] == '0')
            runSort[i] = false;
         else
            runSort[i] = true;
      }
   }

   if (argc > 2)
   {
      runAllSorts(timer, argv[2], runSort);
   }
   else
   {
      runAllSorts(timer, "results.txt", runSort);
   }
}
