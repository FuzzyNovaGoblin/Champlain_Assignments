#pragma once
#include <vector>
#include <iostream>

using namespace std;

class Col;

class Data{
private:
   vector<Col*> cols;


public:
   Data();
   ~Data();
   int getNumberOfRecords();
   int getNumberOfAttributes();
   int getColsSize();
   void newCol();
   void addVal(int index, string val);

};

class Col{
   friend Data;
private:
   int numberOfAttributes;
   vector<string> keys;
   vector<int> values;

   void newValue(string value);

public:
   void operator+=(string key);
   int getNumberOfAttributes();
};