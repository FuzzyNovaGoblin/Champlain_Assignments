
// Author: Grant Hedley
// Class: CSI-240 - Advanced Programming
// Assignment: Lab 2
// Date assigned: 8/29/2019
// Due Date: 9/4/2019
// Description: reads file into structs
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


#include "programmer.h"
#include <sstream>

using namespace std;

//returns the number of programmers - fills in the programmers array from the ifstream
int readProgrammers( ifstream& inputFile, Programmer programmers[], int maxProgrammers )
{
   int count = 0;
   while (!inputFile.eof() && count < maxProgrammers) {
      inputFile >> programmers[count].programmer_id;
      inputFile >> programmers[count].name;
      inputFile >> programmers[count].lines;
      count++;
   }
   return count;
}

//returns the total of the lines field for all programmers
int calcTotalLines( Programmer programmers[], int numProgrammers )
{
   int total = 0;
   for (int i = 0; i < numProgrammers; i++) {
      total += programmers[i].lines;
   }
   return total;
}

//returns the average lines coded for all programmers as a float
float calcAverageLines( Programmer programmers[], int numProgrammers )
{
   return calcTotalLines(programmers, numProgrammers) / numProgrammers;
}


// return a string containing info for a particular programmer
string generateProgrammerInfo( Programmer theProgrammer )
{
   stringstream ss;

   ss << theProgrammer.programmer_id << ' ' << theProgrammer.name << ' ' << theProgrammer.lines;


   return ss.str();
}

//generate report for all programmers
//call calcTotalLines, calcAverageLines, and generateProgrammerInfo functions
void generateProgrammerReport( ostream& output, Programmer programmers[], int numProgrammers )
{
   //just a stub!
   output << "These are all the programmers:";

   for( int i = 0; i < numProgrammers; i++ )
   {
      output << "\n" << generateProgrammerInfo(programmers[i]);
   }

   output << "\nTotal lines = " << calcTotalLines(programmers, numProgrammers);
   output << "\nAverage lines = " << calcAverageLines(programmers, numProgrammers);
   output << endl;
}