// Author: Grant Hedley
// Class: CSI-240 - Advanced Programming
// Assignment: Module-07-Lab Assignment 6 - Linked List
// Date assigned: 10/24/19
// Due Date: 10/30/19
// Description:
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
#include "LinkedList.h"

using namespace std;

int presentMenu();

int main()
{
   LinkedList list;
   int choice;
   do
   {
      choice = presentMenu();
      string tmp = "";
      int response = -1;

      switch (choice)
      {
      case 1:
         cout << "Enter book title: \n";
         cin.ignore();
         getline(cin, tmp);
         list + tmp;
         break;

      case 2:
         list.displayList();
         break;

      case 3:
         cout << endl;
         cout << endl;
         list.displayList(true);
         do
         {
            cout << "enter the number of the book you would like to remove (0 to cancel)\n";
            cin >> tmp;
            try
            {
               response = stoi(tmp);
            }
            catch (exception e)
            {
               response = -1;
            }
         } while (response < 0 || response > list.getSize());
         if(response != 0)
            list.removeAt(response - 1);
         break;

      case 4:
         list.destroyList();
         break;
      case 5:
         break;
      }
   } while (choice != 5);
}

int presentMenu()
{
   int response = 0;
   while (response <= 0 || response > 5)
   {
      string tmp = "";

      cout << "\nWhat would you like to do? (enter number between 1 and 5)\n"
              "1) Add a book title to list\n"
              "2) Display list of books\n"
              "3) Remove book from list\n"
              "4) clear the list of books\n"
              "5) Quit\n";

      cin >> tmp;
      try
      {
         response = stoi(tmp);
      }
      catch (exception e)
      {
         response = 0;
      }
   }
   return response;
}
