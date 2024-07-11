#pragma once
#include "Object.h"
#include "Room.h"

#define DOOR_ID_N 7
#define DOOR_ID_E 8
#define DOOR_ID_S 9 
#define DOOR_ID_W 10

class Door :
    public Object
{
public:

	Door(int directionID);
	Door(int directionID, const char* doorName, const char* doorDesc);

	~Door();

public:

	int GetID() override;
	const char* Name() override;
	String& NameObj() override;
	const char* Description() override;

private:

	String doorName;
	String doorDesc;

	bool canPickup = false;

	int dirID = -1;

};

