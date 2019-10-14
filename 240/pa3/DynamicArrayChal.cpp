// Author: Grant Hedley
// Class: CSI-240 - Advanced Programming
// Assignment: Programming Assignment 3 - Dynamic Array Challenge
// Date assigned: 10/3/19
// Due Date: 10/9/19
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
#include <fstream>
#include <string>
#include "DynamicArray.h"
using namespace std;

int presentMenu();
int getNewCapacity();
void readInput(DynamicArray<string>& arr);

int main()
{
	DynamicArray<string> arr;
   int choice;
   do{
	   int choice = presentMenu();
	   switch (choice)
	   {
	   case 1:
	   	readInput(arr);
	   	break;
	   case 2:
	   	cout << endl << arr.getPrintInfo() << endl;
	   	break;
      case 3:
         arr.resizeArray(getNewCapacity());
         break;
	   case 4:
	   default:
	   	return 0;
	   }
   } while(choice != 4);
}

void readInput(DynamicArray<string>& arr) {
	ifstream readFile;
	cout << "Enter a file name:\n";

	string fileName;
	cin >> fileName;
	readFile.open(fileName);

	while (!readFile)
	{
		cout << "\n\"" << fileName << "\" could not be opened\nPlaease enter a valid file name" << endl;
		cin >> fileName;
		readFile.open(fileName);
	}

	string tmp;
	while(readFile >> tmp) {
		arr.add(tmp);
	}
}


int presentMenu() {
	int response = 0;
	while (response <= 0 || response > 4) {
		string tmp = "";

		cout << "\nWhat would you like to do? (enter number between 1 and 3)" << endl
			<< "1) read values from a file" << endl
			<< "2) Print out Array capacity and Array contents" << endl
			<< "3) set the capacity of the array" << endl
			<< "4) Quit" << endl;

		cin >> tmp;
		try {
			response = stoi(tmp);
		}
		catch (exception e) {
			response = 0;
		}
	}
	return response;
}

int getNewCapacity(){
   int response = -1;
	while (response < 0) {
		string tmp = "";

		cout << "\nenter a new capacity for the array\nmust be an integer that is at least 0\n";
		cin >> tmp;
		try {
			response = stoi(tmp);
		}
		catch (exception e) {
			response = -1;
		}
      if(response < 0)
         cout << "invalid input\n";
	}
	return response;
}