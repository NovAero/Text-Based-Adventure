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

	virtual int GetID();
	virtual const char* Name();
	virtual String& NameObj();
	virtual const char* Description();
	virtual const char* Use();

	void CopyData(Object& copy);

private:

	String name;
	String desc;

	bool isInvisible = false;

	const int itemID = -1;

	int* IDPtr = const_cast<int*>(&itemID);
};