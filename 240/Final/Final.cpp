#include <iostream>
#include "Log.h"
#include <ctime>

using namespace std;

int main()
{
   time_t startTime = time(nullptr);
   log("Start program @ " + (string)(asctime(localtime(&startTime))));
}