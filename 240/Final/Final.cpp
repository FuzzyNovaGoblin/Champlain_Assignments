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

#include <iostream>
#include <ctime>
#include "functions.h"
#include "Log.h"
#include "dynamicArray.h"

using namespace std;

int main()
{
   logProgStart();
   DynamicArray<Product *> products;

   int response;
   do
   {
      response = displayMenu();

      switch (response)
      {
      case 1:
         printInfo(products);
         break;

      case 2:
         createProduct(&products);
         break;

      case 3:
         adjustCount(&products);
         break;

      case 4:
         saveData(&products);
         break;

      case 5:
         readData(&products);
         break;

      default:
         break;
      }
   } while (response != END_VALUE);

}
