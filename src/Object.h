#pragma once
#include "String.h"

class Object
{

public:

	Object();

	Object(const char* name, const char* description);
	Object(const char* name, String& description);
	Object(String& name,const char* description);
	Object(String& name, String& description);

	~Object();

public:

	//const char* return types for printability inside game manager

	virtual const char* Name();
	virtual const char* Description();
	virtual const char* Use();

private:

	String name;
	String desc;

	const int itemID = -1;

	bool isInvisible = false;

};