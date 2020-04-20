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
   ofstream outFile;
   int numBuff;
   string strBuff;

   timer.start();
   HashMap *map = new HashMap();
   timer.stop();
   std::cout << timer.getTimeReadable() << endl;

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

         timer.start();
         while (!inFile.eof())
         {
            inFile >> strBuff;
            strBuff = toLowerCase(strBuff);
            try
            {
               outFile << setfill('0') << setw(7) << map->get(strBuff, true) << " ";
            }
            catch (int e)
            {
               outFile << strBuff << " \n";
            }
         }
         timer.stop();
         outFile.close();
         inFile.close();
         std::cout << "Encrypting time: " << timer.getTimeReadable() << endl;
      }
      else
      {
         std::cout << "Not a valid file name\n";
      }
   }
}

string toLowerCase(string str)
{
   for (int i = 0; i < str.length(); i++){
      str[i] = std::tolower(str[i]);
   }
return str;
}