/* ***       Author:  Grant Hedley
     *  Last Update:  April 24, 2020
     *        Class:  CSI-281
     *     Filename:  main.cpp
     *
     *  Certification of Authenticity:
     *     I certify that this assignment is entirely my work.
     **********************************************************/


/*The data structire used is a hashmap. It uses a hash function to generate
large hashes that are maped to the array useing a constant derived from the
golden ratio, this is to try and create the greatest amount of distribution
in the map. The advantage of a hashmap is it can map keys of non numeric types
and map them to an array for fast lookups. The problem is they tend to use more
space than they need and they can have more than one key getting stored in
the same loaction which leads to slower lookup times.
*/

#include <iostream>
#include "hashmap.h"
#include <fstream>
#include <iomanip>
#include "timerSys.h"

using namespace std;

string toLowerCase(string str);

int main()
{
   Timer timer;
   ifstream inFile("codes.txt");

   if(!inFile.is_open()){
      cout << "codes.txt missing\n";
      return 1;
   }

   ofstream outFile;
   int numBuff;
   string strBuff;
   DynamicArray<string> txtData = DynamicArray<string>();

   timer.start();
   HashMap *map = new HashMap();
   timer.stop();
   std::cout << "Creating data structures: "<< timer.getTimeReadable() << endl;

   timer.start();
   while (!inFile.eof())
   {
      inFile >> strBuff;
      inFile >> numBuff;
      map->get(strBuff) = numBuff;
   }
   timer.stop();
   inFile.close();
   std::cout << "Loading Data Structure" << timer.getTimeReadable() << endl;

   while (true)
   {
      std::cout << "Enter Input File: ";
      getline(cin, strBuff);
      if (strBuff == "exit")
         break;
      inFile.open(strBuff);

      if (inFile.is_open())
      {
         std::cout << "Enter Output File: ";
         getline(cin, strBuff);
         outFile.open(strBuff);

         strBuff = "";
         inFile >> strBuff;

         while (!inFile.eof())
         {
            strBuff = toLowerCase(strBuff);
            txtData.add(strBuff);
            inFile >> strBuff;
         }
         inFile.close();

         timer.start();
         for (int i = 0; i < txtData.size(); i++)
         {
            try
            {
               txtData[i] = to_string(map->get(txtData[i], true));
            }
            catch (int e)
            {
            }
         }
         timer.stop();

         for (int i = 0; i < txtData.size(); i++)
         {
            outFile << txtData[i]<<" ";
         }
         outFile.close();
         txtData.clear();
         std::cout << "Encrypting time: " << timer.getTimeReadable() << endl;
      }
      else
      {
         std::cout << "Not a valid file name\n";
      }
   }
   delete map;
}

/*      Pre:  string input
 *     Post:  return the array in all lowercase
 *  Purpose:  convert text of input file to all lowercase
 **************************************************************/
string toLowerCase(string str)
{
   for (int i = 0; i < str.length(); i++){
      str[i] = std::tolower(str[i]);
   }
return str;
}