#pragma once
#include "Object.h"
class Key : public Object
{
public:

	Key(char colour, const char* name, const char* description, bool invisible);
	~Key();

public:

	const char* Name() override;
	const char* Description() override;

private:
	
	String name;
	String desc;
	
	bool invisible = false;

	char keyColour;


	int itemID = KEY_ID;

};

