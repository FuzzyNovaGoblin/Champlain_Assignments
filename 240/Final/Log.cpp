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
#include "Log.h"

void log(std::string logStr)
{
   std::ofstream log;
   log.open(LOG_FILE_NAME, std::ios_base::app);

   log << std::endl;
   log << logStr << std::endl;
   log.close();
}

void logProgStart()
{
   time_t startTime = time(nullptr);
   log("Start program @ " + (std::string)(asctime(localtime(&startTime))));
}