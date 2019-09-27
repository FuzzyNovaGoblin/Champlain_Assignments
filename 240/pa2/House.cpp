// Author: Grant Hedley
// Class: CSI-240 - Advanced Programming
// Assignment: Lab2
// Date assigned: 9/12/19
// Due Date: 9/26/19
// Description: Choose member data, implement missing functions, and add new private functions as needed to the
//House class.
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
#include <sstream>
#include "House.h"

using namespace std;

House::House()
{
	bedroomsCount = 0;
	bathroomsCount = 0;
	kitchensCount = 0;
	livingroomsCount = 0;
   roomCount = 0;
}

//return false if room has too low a height, too small an area or the house already is at max for that type of room
bool House::addRoom( const Room& theRoom )
{
	if (theRoom.getHeight() < MIN_HEIGHT || theRoom.getSquareFootage() < MIN_AREA)
		return false;

	switch (theRoom.getType())
	{
	case KITCHEN:
		if (kitchensCount >= MAX_KITCHENS)
			return false;
		rooms[roomCount] = theRoom;
		kitchensCount++;
      roomCount++;
		return true;

	case BEDROOM:
		if (bedroomsCount >= MAX_BEDROOMS)
			return false;
		rooms[roomCount] = theRoom;
		bedroomsCount++;
      roomCount++;
		return true;

	case BATHROOM:
		if (bathroomsCount >= MAX_BATHROOMS)
			return false;
		rooms[roomCount] = theRoom;
		bathroomsCount++;
      roomCount++;
		return true;

	case LIVINGROOM:
		if (livingroomsCount >= MAX_LIVINGROOMS)
			return false;
		rooms[roomCount] = theRoom;
		livingroomsCount++;
      roomCount++;
		return true;
	default:
		return false;
	}
}

int House::getNumBedrooms()
{
	return bedroomsCount;
}

int House::getNumBathrooms()
{
	return bathroomsCount;
}

int House::getNumKitchens()
{
	return kitchensCount;
}

int House::getNumLivingrooms()
{
	return livingroomsCount;
}

int House::getTotalSquareFootage()
{
	int total = 0;

	for (int i = 0; i < roomCount; i++)
	{
		total += rooms[i].getSquareFootage();
	}

	return total;
}

int House::getTotalVolume()
{
	int total = 0;

	for (int i = 0; i < roomCount; i++)
	{
		total += rooms[i].getSquareFootage() * rooms[i].getHeight();
	}

	return total;
}

bool House::isValid()
{
	if (bedroomsCount < MIN_BEDROOMS || kitchensCount < MIN_KITCHENS ||
		bathroomsCount < MIN_BATHROOMS || livingroomsCount < MIN_LIVINGROOMS)
	{
		return false;
	}
	return true;
}

string House::enumerateRooms()
{
	stringstream report;
   report << "These are the rooms in the house:\n\n";

	for (int i = 0; i < roomCount; i++)
	{
		report << rooms[i].getDescription();
	}

	return report.str();
}

string House::getDescription()
{
	stringstream theStream;

	theStream
		<< "House has:\n"
		<< getNumBedrooms() << " Bedrooms\n"
		<< getNumBathrooms() << " Bathrooms\n"
		<< getNumKitchens() << " Kitchens\n"
		<< getNumLivingrooms() << " Livingrooms\n\n"
		<< getTotalSquareFootage() << " Square feet total\n"
		<< getTotalVolume() << " Cubic feet total volume\n";

	if( isValid() )
	{
		theStream << "House is Valid!\n\n";
	}
	else
	{
		theStream << "House is not Valid!\n\n";
	}

	return theStream.str();
}