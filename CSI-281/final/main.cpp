#include <iostream>
#include "hashmap.h"
#include <fstream>
#include "timerSys.h"

using namespace std;

int main()
{
   Timer timer;

   timer.start();
   MyHashmap *map = new MyHashmap();
   timer.stop();
   cout << timer.getTimeReadable() << endl;

   bool done = false;
   ifstream file("codes.txt");
   int numBuff;
   string strBuff;
   timer.start();


   while (!file.eof())
   {
      file >> strBuff;
      file >> numBuff;
      map->get(strBuff) = numBuff;
   }
   timer.stop();




   cout << timer.getTimeReadable() << endl;
   file.close();
}