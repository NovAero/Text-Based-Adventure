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
	return this->dirID;
}

const char* Door::Name()
{
	return this->doorName.GetData();
}

String& Door::NameObj()
{
	return this->doorName;
}

const char* Door::Description()
{
	return this->doorDesc.GetData();
}
