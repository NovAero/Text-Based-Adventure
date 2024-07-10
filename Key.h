#pragma once
#include "Object.h"
class Key : public Object
{
public:

	Key(const char* name, const char* description, bool invisible, int KEY_ID);
	~Key();

public:

	const char* Name() override;
	const char* Description() override;

	bool CanPickup() override;

private:
	
	String name;
	String desc;
	
	bool canPickup = true;
	bool invisible = false;

	int itemID = -1;

};

