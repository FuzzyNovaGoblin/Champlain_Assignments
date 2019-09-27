// Author: Grant Hedley
// Class: CSI-240 - Advanced Programming
// Assignment: lab3
// Date assigned: 9/3/2019
// Due Date: 9/4/2019
// Description: hold values for books stored in books.txt
// Certification of Authenticity :
// I  certify  that  this  is  entirely  my  own  work, except  where  I  have  given fully
// documented  references  to  the  work  of  others. I  understand  the
// definition and consequences of plagiarism and acknowledge that the assessor
// of this assignment may, for the purpose of assessing this assignment:
// - Reproduce  this  assignment and provide  a  copy  to  another  member  of
// academic staff; and/or
// - Communicate  a  copy  of  this  assignment  to  a  plagiarism  checking
// service(which  may  then  retain  a  copy  of  this  assignment  on  its
// database for the purpose of future plagiarism checking)

#include "book.h"
#include <sstream>

using namespace std;

Book::Book() 
{
   bName = "";
   bType = Type(-1);
   bPages = 0;
   bOunces = 0;
}

Book::Book(const string& name, Type type, int pages, float ounces) 
{
   bName = name;
   bType = type;
   bPages = pages;
   bOunces = ounces;
}

string Book::formatReportLine() 
{
   stringstream ss;
   
   ss << bName << "  | Type: " << getTypeName() << "  Pages: "
      << bPages << "  Weight(lbs):" << getWeightLbs();
   
   return ss.str();
}

float Book::getWeightLbs() 
{
   return bOunces / 16;
}

string Book::getTypeName()
{
   return TYPE_WORDS[bType];
}