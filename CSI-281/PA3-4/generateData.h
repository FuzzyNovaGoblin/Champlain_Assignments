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
#ifndef GENERATE_DATA_H
#define GENERATE_DATA_H

#include <iostream>
#include <fstream>
#include "sortingFunctions.h"

using namespace std;

const string DATA_SET_1_FILE = "dataSet1.data";
const string DATA_SET_2_FILE = "dataSet2.data";
const string DATA_SET_3_FILE = "dataSet3.data";
const string DATA_SETS[] = {DATA_SET_1_FILE, DATA_SET_2_FILE, DATA_SET_3_FILE};
const int N1 = 100;
const int N2 = 10000;
const int N3 = 1000000;
const int N_LIST[] = {N1, N2, N3};

void generatDataSet1();
void generatDataSet2();
void generatDataSet3();
#endif