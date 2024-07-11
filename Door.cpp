#include "Door.h"

Door::Door(int directionID) : Object("Exit Gate","", directionID, false)
{
	doorName = Object::Name();
	doorDesc = Object::Description();

	dirID = directionID;
}

Door::Door(int directionID, const char* doorName, const char* doorDesc) : Object(doorName, doorDesc, directionID, false)
{
	this->doorName = Object::Name();
	this->doorDesc = Object::Description();

	dirID = directionID;
}

Door::~Door()
{

}


int Door::GetID()
{
	return dirID;
}

const char* Door::Name()
{
	return doorName.GetData();
}

String& Door::NameObj()
{
	return doorName;
}

const char* Door::Description()
{
	return doorDesc.GetData();
}
