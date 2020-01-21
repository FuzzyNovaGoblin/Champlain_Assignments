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
#include "data.h"

Data::Data()
{
   numberOfRecords = 0;
}
Data::~Data()
{
   for (int i = cols.size() - 1; i >= 0; i--)
   {
      delete cols[i];
   }
}

void Col::newValue(char value)
{
   keys.push_back(value);
   values.push_back(1);
}

void Col::operator+=(char key)
{
   if (key == '?')
      return;

   int index = -1;
   for (int i = 0; i < keys.size(); i++)
   {
      if (keys[i] == key)
      {
         index = i;
         break;
      }
   }
   if (index == -1)
   {
      newValue(key);
   }
   else
   {
      values[index]++;
   }
}

int Data::getNumberOfRecords()
{
   return numberOfRecords;
}

int Data::getColsSize()
{
   return cols.size();
}

void Data::incNumberOfRecords(int v){
   numberOfRecords += v;
}

void Data::newCol()
{
   cols.push_back(new Col);
}
void Data::addVal(int index, char val)
{
   *cols[index] += val;
}

string Data::toString()
{
   stringstream ss;
   ss << "Total number of records: " << getNumberOfRecords() << endl
      << "Number of attributes for each record: " << getColsSize() << "\n\n";

   for (int i = 0; i < cols.size(); i++)
   {
      cols[i]->calcPercent();
      ss << "Attr #" << i + 1 << ":\n";
      ss << cols[i]->toString();
   }
   return ss.str();
}

string Col::toString()
{
   stringstream ss;
   for (int i = 0; i < keys.size(); i++)
   {
      ss << setw(5) << " " << keys[i] << " (" << values[i] << ") [" << percents[i] << "]" << endl;
   }
   return ss.str();
}

void Col::calcPercent()
{
   int totalCount = 0;
   for (int i = 0; i < values.size(); i++)
   {
      totalCount += values[i];
   }

   percents.clear();

   for (int i = 0; i < values.size(); i++)
   {
      double num = (double)100 * values[i] / totalCount;
      num *= 10;
      num += 0.5;
      num = floor(num);
      num /= 10;
      percents.push_back(num);
   }
}