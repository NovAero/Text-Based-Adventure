#pragma once
#include "Object.h"


#define FAERIE_KEY_ID 4
#define RUSTED_KEY_ID 5
#define CEMETERY_KEY_ID 6

class Key : public Object
{
public:

	Key(const char* name, const char* description, bool invisible, int KEY_ID);
	~Key();

public:

	const char* Name() override;
	const char* Description() override;

private:
	
	String name;
	String desc;
	
	bool invisible = false;

	int itemID = -1;

};

