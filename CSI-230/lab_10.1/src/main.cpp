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

using namespace std;

int main()
{
   srand(time(NULL));
   //initialization
   int i{0};
   int k = 0;
   int j;
   printf("Values of i, j and k\n%d %d %d\n", i, k, j);
   printf("\nAddresses of i, j and k\n%p %p %p\n%llu %llu %llu\n", &i, &k, &j, &i, &k, &j);

   //size
   printf("Size of various variables\n");
   unsigned short int usi{};
   string str{"Hello"};
   char c{'a'};
   double d = 3.14159;
   float f = 3.14159;
   bool myBool{true};
   cout << "unsigned short int:" << sizeof(usi) << endl;
   cout << "string:" << sizeof(str) << endl;
   cout << "char:" << sizeof(c) << endl;
   cout << "double:" << sizeof(d) << endl;
   cout << "float:" << sizeof(f) << endl;
   cout << "bool:" << sizeof(myBool) << endl;

   //canversion of datatypes
   int convertedD = d; //from above
   cout << "d converted to int:" << convertedD << endl;
   i = 8;
   k = 3;
   cout << "integer division:" << i / k << endl;
   cout << "casting:" << static_cast<double>(i) / k << endl;

   //conditional logic
   bool a{false};
   bool b{true};
   cout << boolalpha << a << " " << b << endl;

   cout << boolalpha << (6 == 7) << endl;

   if(i > k){
      cout << "i is greater than k" << endl;
   }else{
      cout << "k is greater than i" << endl;
   }

   // for()

   // string str = "A little bird with a yellow bill";
   // printf("Hello, World!");
}