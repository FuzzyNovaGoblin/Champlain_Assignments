//
//  programmer.h
//  lab2
//
//  Modified by: Murat K. Gungor 
//  Thanks to Brian R. Hall
//

#ifndef __lab2__programmer__
#define __lab2__programmer__

#include <string>
#include <fstream>

using namespace std;

struct Programmer
{
	int programmer_id;
	string name;
	int lines; // lines of code programmed
};

//function prototypes

//returns the number of programmers - fills in the programmers array from the ifstream
int readProgrammers( ifstream& inputFile, Programmer programmers[], int maxProgrammers );

//returns the total of the lines field for all programmers
int calcTotalLines( Programmer programmers[], int numProgrammers );

//returns the average lines coded for all programmers as a float
float calcAverageLines( Programmer programmers[], int numProgrammers );

//return a string containing info for a particular programmer
string generateProgrammerInfo( Programmer theProgrammer );

//generate report for all employees
void generateProgrammerReport( ostream& output, Programmer programmers[], int numProgrammers );


#endif /* defined(__lab2__programmer__) */
