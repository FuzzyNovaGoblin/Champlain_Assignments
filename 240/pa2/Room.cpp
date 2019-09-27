#include "Room.h"
#include <sstream>

Room::Room( RoomType type, int width, int breadth, int height )
{
	mType = type;
	mWidth = width;
	mBreadth = breadth;
	mHeight = height;
}

Room::Room()
{
	mType = BATHROOM;
	mWidth = 0;
	mBreadth = 0;
	mHeight = 0;
}

string Room::getDescription() const
{
	stringstream theStream;
	theStream
		<< getRoomName() << ": "
		<< "width=" << mWidth
		<< " breadth=" << mBreadth
		<< " height=" << mHeight
		<< "    " << getSquareFootage() << " Total Square Footage\n\n";

	return theStream.str();
}
