#pragma once

#include <string>

using namespace std;

enum RoomType
{
	KITCHEN = 0,
	BATHROOM,
	LIVINGROOM,
	BEDROOM,
	NUM_ROOM_TYPES
};

const string ROOM_STRINGS[NUM_ROOM_TYPES] = {	"Kitchen",
												"Bathroom",
												"Livingroom",
												"Bedroom"
											};

class Room
{
public:
	//constructor
	Room( RoomType type, int width, int breadth, int height );
	//default constructor
	Room();
	//destructor
	~Room(){};

	//accessors
	inline RoomType getType() const { return mType; };
	inline int getHeight() const { return mHeight; };

	inline int getSquareFootage() const { return mWidth * mBreadth; };
	inline int getVolume() const { return getSquareFootage() * mHeight; };

	inline string getRoomName() const { return ROOM_STRINGS[mType]; };
	string getDescription() const;

private:
	//type of room
	RoomType mType;

	//floor dimensions - in feet
	int mWidth;
	int mBreadth;

	//ceiling height - in feet
	int mHeight;
};