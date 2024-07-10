#pragma once
#include "Object.h"
#include "Room.h"

class Door :
    public Object
{
public:

	Door(int directionID);
	Door(int directionID, const char* doorName, const char* doorDesc);

	~Door();

public:

	const char* Name();
	String& NameObj();
	const char* Description();

private:

	String doorName;
	String doorDesc;

	int dirID = -1;

};

