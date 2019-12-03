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

#pragma once

#include<sstream>
#include <string>

using namespace std;

class Product{
protected:
    int section;
    string name;
    int calories;
    int count;
public:
    virtual string displayInfo() = 0;
    virtual string getSaveData() = 0;
    Product(string name, int section, int calories = -1);
    void setCount(int count);
    void AddCount(int v = 1);
    int getCount();
};

class TempControlled : public Product{
protected:
    int temp;
public:
   TempControlled(string name, int section, int calories, int temp);
   string displayInfo() = 0;
};

class Meat : public TempControlled{
public:
   Meat(string name, int section, int calories, int temp = 34);
   string displayInfo() override;
   string getSaveData();
};

class Produce : public TempControlled{
public:
   Produce(string name, int section, int calories, int temp = 34);
   string displayInfo() override;
   string getSaveData();
};

class DryFood : public Product{
public:
   DryFood(string name, int section, int calories);
   string displayInfo();
   string getSaveData();
};
