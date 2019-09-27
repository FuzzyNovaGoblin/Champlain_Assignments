//
//  main.cpp
//  lab2
//
//
//  Modified by: Murat K. Gungor 
//  Thanks to Brian R. Hall
//

#include <iostream>
#include <string>
#include <fstream>
#include "programmer.h"

using namespace std;

const int MAX_PROGRAMMERS = 10;

int main()
{
	Programmer programmers[MAX_PROGRAMMERS];
	int numProgrammers = 0;
   
	ifstream inputFile( "programmers.txt" ); // declares file stream and opens for input
   
	if( inputFile.good() )
	{
		numProgrammers = readProgrammers( inputFile, programmers, MAX_PROGRAMMERS );
      
		//close the input file because we are done with it
		inputFile.close();
      
		//report on programmers to console
		generateProgrammerReport( cout, programmers, numProgrammers ); // cout passed as an ostream
      
		//report on programmers to a file
		ofstream outputFile("ProgrammerReport.txt");
		generateProgrammerReport( outputFile, programmers, numProgrammers );
		outputFile.close();
	}
	else
	{
		cout << "File not opened properly!!\n\n";
	}
   
	system("pause");
	return 0;
   
}

