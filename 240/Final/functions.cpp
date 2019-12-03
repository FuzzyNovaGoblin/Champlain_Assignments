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

#include "functions.h"
#include <iostream>

using namespace std;

int displayMenu()
{

   int response;
   do
   {
      string tmp = "";
      cout
          << "1) Display saved data\n"
          << "2) Add item to products\n"
          << "3) Adjust count\n"
          << "4) Save data\n"
          << "5) Read in data\n"
          << END_VALUE << ") exit program\n"
          << "Please enter number to execute action\n";
      cin >> tmp;

      try
      {
         response = stoi(tmp);
      }
      catch (exception e)
      {
         response = 0;
      }
   } while (response <= 0 || response > END_VALUE);
   return response;
}

void printInfo(DynamicArray<Product *> products, bool pre)
{
   for (int i = 0; i < products.size(); i++)
   {
      if (pre)
         cout << i << ')' << products[i]->displayInfo() << endl;
      else
         cout << products[i]->displayInfo() << endl;
   }
}

void createProduct(DynamicArray<Product *> *products)
{
   int typeOfFood;
   string name, location, calories, temperature;
   do
   {
      cout << "1) Meat\n"
           << "2) Produce\n"
           << "3) Dry Food\n";
      string buffer;
      cin >> buffer;
      typeOfFood = stoi(buffer);
   } while (typeOfFood <= 0 && typeOfFood > 3);

   cin.ignore(INT64_MAX, '\n');
   cout << "name?\n";
   getline(cin, name);
   for (int i = 0; i < name.length(); i++)
   {
      if ((int)(name[i]) == 32)
         name[i] = '_';
   }
   cout << "location?\n";
   cin >> location;
   cout << "calories?\n";
   cin >> calories;
   if (typeOfFood != 3)
   {
      cout << "fridge temp?\n";
      cin >> temperature;
   }
   switch (typeOfFood)
   {
   case 1:
      addItem(new Meat(name, stoi(location), stoi(calories), stoi(temperature)), *products);
      break;
   case 2:
      addItem(new Produce(name, stoi(location), stoi(calories), stoi(temperature)), *products);
      break;
   case 3:
      addItem(new DryFood(name, stoi(location), stoi(calories)), *products);
      break;
   default:
      break;
   }
}

void adjustCount(DynamicArray<Product *> *products)
{
   cout << "\n\n";
   printInfo(*products, true);

   cout << endl
        << "Enter a number between 0 and " << (products->size() - 1) << endl;
   int choice = 0, val = 0;
   cin >> choice;
   cout << "new val\n";
   cin >> val;
   (*products)[choice]->setCount(val);
}

bool checkFileName(string name)
{
   for (int i = 0; i < name.length(); i++)
   {
      if ((int)(name[i]) != 32)
         return true;
   }
   return false;
}

void saveData(DynamicArray<Product *> *products)
{
   string fileName;
   do
   {
      cout << "Enter file name\n";
      cin.ignore(INT32_MAX, '\n');
      getline(cin, fileName);
   } while (!checkFileName(fileName));

   ofstream file(fileName);

   for (int i = 0; i < products->size(); i++)
   {
      file << (*products)[i]->getSaveData() << endl;
   }
   file.close();
   log("saved data to " + fileName);
}

void readData(DynamicArray<Product *> *products)
{
   stringstream lineBuffer;
   string fileName, buffer;
   do
   {
      cout << "Enter file name\n";
      cin.ignore(INT32_MAX, '\n');
      getline(cin, fileName);
   } while (!checkFileName(fileName));

   ifstream file(fileName);
   while (!file.eof())
   {
      getline(file, buffer);
      lineBuffer = stringstream(buffer);
      lineBuffer >> buffer;

      if (buffer == "DryFood")
      {
         string name;
         int section, calories;
         lineBuffer >> name;
         lineBuffer >> buffer;
         section = stoi(buffer);
         lineBuffer >> buffer;
         calories = stoi(buffer);
         products->add(new DryFood(name, section, calories));
      }
      else if (buffer == "Produce")
      {
         string name;
         int section, calories, temp;
         lineBuffer >> name;
         lineBuffer >> buffer;
         section = stoi(buffer);
         lineBuffer >> buffer;
         calories = stoi(buffer);
         lineBuffer >> buffer;
         temp = stoi(buffer);
         products->add(new Produce(name, section, calories, temp));
      }
      else if (buffer == "Meat")
      {
         string name;
         int section, calories, temp;
         lineBuffer >> name;
         lineBuffer >> buffer;
         section = stoi(buffer);
         lineBuffer >> buffer;
         calories = stoi(buffer);
         lineBuffer >> buffer;
         temp = stoi(buffer);
         products->add(new Meat(name, section, calories, temp));
      }
   }

   file.close();
   log("read data from " + fileName);
}