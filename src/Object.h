#pragma once
#include "String.h"

class Object
{

public:

	Object();

	Object(const char* name, const char* description, int ID, bool isInvis);
	Object(const char* name, String& description, int ID, bool isInvis);
	Object(String& name,const char* description, int ID, bool isInvis);
	Object(String& name, String& description, int ID, bool isInvis);

	~Object();

public:

	void SetData(String& name, String& description, int ID, bool isInvis);
	void SetData(const char* name, const char* description, int ID, bool isInvis);
	void SetID(int ID);
	
	virtual int GetID();

	virtual const char* Name();
	virtual String& NameObj();
	virtual const char* Description();
	virtual void Use();

	bool isInvisible();
	void ToggleInivs();

	void CopyData(Object& copy);

private:

	String name;
	String desc;

	bool invisible = false;

	const int itemID = -1;

	int* IDPtr = const_cast<int*>(&itemID);
};