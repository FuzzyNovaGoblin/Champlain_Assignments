// Author: Grant Hedley
// Class: CSI-240 - Advanced Programming
// Assignment: Lab 4
// Date assigned: 9/19/19
// Due Date: 9/25/19
// Description: Write a program that will prompt the user for a size.
// Based on the specified size, create a dynamic array and populate the dynamic array with random numbers.
//
//Certification of Authenticity :
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
#include <iomanip>
#include <ctime>
#include <cstdlib>

using namespace std;

int promptSize();
void populate(int size, int* ptr);
void display(int size, int* ptr);
void sort(int size, int* ptr);

const int UPPER_BOUND = 51; // The largest random number, inclusive

int main()
{
	srand(time(NULL));

	int size;
	int* arr;
	
	size = promptSize();
	arr = new int[size];

	populate(size, arr);

	cout << "\nUnsorted array: \n"; 
	display(size, arr);

	sort(size, arr);

	cout << "\n\nSorted array: \n";
	display(size, arr);
	
	delete[] arr;
	arr = nullptr;
}

int promptSize() 
{
	int size;
	cout << "Please enter a size for your array greater than 0\n";
	cin >> size;

	while (size < 0)
	{
		cout << "\nThat is not a number greater than 0";
		cin >> size;
	}
	return size;
	system("pause");
}

void populate(const int size, int* ptr) 
{

	for (int i = 0; i < size; i++)
	{
		ptr[i] = rand() % UPPER_BOUND;
	}
}



void display(int size, int* ptr)
{
	for (int i = 0; i < size; i++)
	{
		if (i % 10 == 0)cout << endl;

		cout << left << setw(4) << ptr[i];
	}
	cout << endl;
}

void sort(int size, int* ptr) {
	bool notDone = true;
	while (notDone)
	{
		notDone = false;
		for (int i = 0; i < size - 1; i++)
		{
			if (ptr[i] > ptr[i + 1])
			{
				int tmp = ptr[i];
				ptr[i] = ptr[i + 1];
				ptr[i + 1] = tmp;
				notDone = true;
			}
		}
	}
}
