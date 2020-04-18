#include <iostream>
#include "hashmap.h"
#include <fstream>
#include "timerSys.h"

using namespace std;

int main()
{
   Timer timer;

   timer.start();
   HashMap *map = new HashMap();
   timer.stop();

   cout << timer.getTimeReadable() << endl;

   bool done = false;
   ifstream codesFile("codes.txt");
   int numBuff;
   string strBuff;
   timer.start();

   while (!codesFile.eof())
   // for (int i = 0; i < 5; i++)
   {
      codesFile >> strBuff;
      codesFile >> numBuff;
      map->get(strBuff) = numBuff;
   }
   timer.stop();
   codesFile.close();

   cout << timer.getTimeReadable() << endl;
}