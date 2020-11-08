/**
 * @file main.cpp
 * @brief Week 10, C++ Review and warmup from CSI-230
 * @author Grant Hedley
 * @assignment lab 10.1
 * @date 11/06/20
 *
*/

#include <iostream>
#include <string>
#include <stdio.h>
#include <vector>
#include <util.h>

using namespace std;

int main()
{

   vector<string> stringsVec = {"one", "two", "three", "four", "five"};
   cout << "dumping vector of 5 strings: ";
   printVector(stringsVec);

   cout << "clue:    setting srand in main\n";
   srand(time(NULL));

   cout << "calling randomElement\n"
        << randomElement(stringsVec) << endl;

   vector<double> doubleVec = {3.45, 6.9, -51.3, 420.0, 4.2, 69.0};
   cout << "dumping vector of doubles ";
   printVector(doubleVec);
   cout << "sum: " << sum(doubleVec) << endl;
   cout << "avg: " << avg(doubleVec) << endl;
   cout << "lowest: " << lowest(doubleVec) << endl;

   string multiWordString = "A little bird with a yellow bill";
   cout << "Calling camelCase with: " << multiWordString << endl;
   camelCase(multiWordString);
   cout << "multiWordString after camelCase: " << multiWordString << "\n";
}