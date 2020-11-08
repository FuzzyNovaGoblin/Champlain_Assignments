/**
 * @file util.cpp
 * @brief Week 10, C++ Review and warmup from CSI-230
 * @author Grant Hedley
 * @assignment lab 10.1
 * @date 11/08/20
 *
*/
#include <util.h>

double sum(vector<double> &arr)
{
   double sum = 0;
   for (int i = 0; i < arr.size(); i++)
   {
      sum += arr[i];
   }
   return sum;
}

double avg(vector<double> &arr)
{
   return sum(arr) / arr.size();
}

double lowest(vector<double> &arr)
{
   double low = arr[0];
   for (int i = 1; i < arr.size(); i++)
   {
      if (arr[i] < low)
      {
         low = arr[i];
      }
   }
   return low;
}

void camelCase(string &str)
{
   for (int i = str.size() - 1; i >= 0; i--)
   {
      if (str[i] == 32)
      {
         str.erase(i, 1);
         if (str[i] >= 97 && str[i] <= 122)
            str[i] = str[i] - 32;
      }
      else if (str[i] >= 65 && str[i] <= 90)
      {
         str[i] = str[i] + 32;
      }
   }
}

string &randomElement(vector<string> &arr)
{
   return arr[rand() % arr.size()];
}

void printVector(vector<string> &arr)
{
   cout << "[" << arr[0];
   for (int i = 1; i < arr.size(); i++)
   {
      cout << ", " << arr[i];
   }

   cout << "]\n";
}

void printVector(vector<double> &arr)
{
   cout << "[" << arr[0];
   for (int i = 1; i < arr.size(); i++)
   {
      cout << ", " << arr[i];
   }

   cout << "]\n";
}