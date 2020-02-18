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

int main()
{
   srand(time(NULL));

   generatDataSet1();
   generatDataSet2();
   generatDataSet3();

   Timer timer;

   runAllSorts(timer);
}