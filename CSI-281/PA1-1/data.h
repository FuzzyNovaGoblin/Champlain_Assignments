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
#pragma once
#include <vector>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <math.h>

    using namespace std;

class Col;

class Data{
private:
   vector<Col*> cols;
   int numberOfRecords;

public:
   Data();
   ~Data();
   int getNumberOfRecords();
   void incNumberOfRecords(int v = 1);
   int getColsSize();
   void newCol();
   void addVal(int index, char val);
   string toString();
};

class Col{
   friend Data;
private:
   int numberOfAttributes;
   vector<char> keys;
   vector<int> values;
   vector<double> percents;

   void newValue(char value);

public:
   void operator+=(char key);
   int getNumberOfAttributes();
   string toString();
   void calcPercent();
};