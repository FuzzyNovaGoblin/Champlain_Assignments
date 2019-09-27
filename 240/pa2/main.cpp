#include <fstream>
#include <iostream>
#include <string>

#include "Room.h"
#include "House.h"

using namespace std;


int main()
{
	ifstream inFile( "HouseDriver.txt" );

	House theHouse;

	if( inFile.good() )
	{
		while( !inFile.eof() )
		{
			//read data
			int type;//kitchen/bathroom/bedroom/ etc.
			inFile >> type;

			int width, breadth;//floor dimensions - in feet
			int height;//ceiling height - in feet
			inFile >> width >> breadth >> height;

			//create Room
			Room newRoom( (RoomType)type, width, breadth, height );

			//report on room
			cout << "Room to Add:\n" << newRoom.getDescription();

			//add room to the house
			bool successful = theHouse.addRoom( newRoom );

			if( !successful )
			{
				cout << "\nRoom could not be added!!!\n\n";
			}

			//report on the house
			cout << theHouse.getDescription();

			system("pause");
			system("cls");
		}
		cout << theHouse.enumerateRooms();
	}
	else
	{
		cout << "File not found!\n";
	}
	system( "pause" );
}

