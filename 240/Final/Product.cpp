// Author: Grant Hedley
// Class: CSI-240 - Advanced Programming
// Assignment: 240 Final
// Description: write a dynamic array class and read in words from a file to fill the array, also the user can set the size of the array
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

#include "Product.h"
#include <iomanip>

Product::Product(string name, int section, int calories)
{
   this->name = name;
   this->section = section;
   this->count = 0;
   this->calories = calories;
}

void Product::setCount(int count)
{
   this->count = count;
}

void Product::AddCount(int v)
{
   this->count += v;
}

int Product::getCount()
{
   return this->count;
}

TempControlled::TempControlled(string name, int section, int calories, int temp) : Product(name, section, calories)
{
   this->temp = temp;
}

Meat::Meat(string name, int section, int calories, int temp) : TempControlled(name, section, calories, temp) {}
string Meat::displayInfo()
{
   stringstream loc, cals, info;
   loc << "freezer " << section;

   info << setw(10) << name << " | ";
   info << "count: " << setw(4) << count << " | ";
   info << "calories: " << setw(5) << calories << " | ";
   info << "location:    " << loc.str();

   return info.str();
}

Produce::Produce(string name, int section, int calories, int temp) : TempControlled(name, section, calories, temp) {}

string Produce::displayInfo()
{
   stringstream loc, cals, info;
   loc << "fridge " << section;

   info << setw(10) << name << " | ";
   info << "count: " << setw(4) << count << " | ";
   info << "calories: " << setw(5) << calories << " | ";
   info << "location:    " << loc.str();

   return info.str();
}

DryFood::DryFood(string name, int section, int calories) : Product(name, section, calories) {}

string DryFood::displayInfo()
{
   stringstream loc, info;
   loc << "aisle " << section;

   info << setw(10) << name << " | ";
   info << "count: " << setw(4) << count << " | ";
   info << "calories: " << setw(5) << calories << " | ";
   info << "location:    " << loc.str();

   return info.str();
}

string DryFood::getSaveData()
{
   return "DryFood " + name + " " + to_string(section) + " " + to_string(calories);
}
string Produce::getSaveData()
{
   return "Produce " + name + " " + to_string(section) + " " + to_string(calories) + " " + to_string(temp);
}
string Meat::getSaveData()
{
   return "Meat " + name + " " + to_string(section) + " " + to_string(calories) + " " + to_string(temp);
}