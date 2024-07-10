#include "Door.h"

Door::Door(int directionID) : Object("Exit Gate", "", directionID, false);
{
	doorName = Object::Name();
	doorDesc = Object::Description();

	dirID = directionID;
}

Door::Door(int directionID, const char* doorName, const char* doorDesc) : Object(doorName, doorDesc, directionID, false)
{
	doorName = Object::Name();
	doorDesc = Object::Description();

	dirID = directionID;
}

Door::~Door()
{

}


const char* Door::Name()
{
	return doorName.GetData();
}

const char* Door::Description()
{
	return doorDesc.GetData();
}
