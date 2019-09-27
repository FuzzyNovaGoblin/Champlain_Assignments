// Author: Grant Hedley
// Class: CSI-240 - Advanced Programming
// Assignment: Lab 1
// Date assigned: 8/27/2019
// Due Date: 9/2/2019
// Description: reads files to populate arrays
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
#include <string>
#include <fstream>
#include <sstream>
#include <iomanip>
#include "functions.h"

using namespace std;


int loadLanguages( const string& filename, string names[], int maxLanguages )
{
	int numNames = 0;

	ifstream input(filename);

	if( input.is_open() )
	{
		while( !input.eof() && numNames < maxLanguages )
		{
			getline( input, names[numNames] );
			numNames++;
		}
		input.close();
	}

	return numNames;
}


bool loadInfo( const string& filename, int infoArray[][INFO], int numLanguages )
{
   ifstream file;
	file.open(filename);

	for(int i = 0; !file.eof() && i < numLanguages; i++)
	{
      file >> infoArray[i][0];
		file >> infoArray[i][1];
	}

	file.close();

	return true;
}


string formatReportLine( int languageRank, int infoArray[][INFO], string names[] )
{
	stringstream ss;

	ss << setw(15) << left << names[languageRank] << setw(3) << right << infoArray[languageRank][0] << setw(9) << "" << infoArray[languageRank][1];

	return ss.str();
}