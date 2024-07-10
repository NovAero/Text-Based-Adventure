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

	const char* Name() override;
	String& NameObj() override;
	const char* Description() override;
	bool CanPickup() override;

private:

	String doorName;
	String doorDesc;

	bool canPickup = false;

	int dirID = -1;

};

