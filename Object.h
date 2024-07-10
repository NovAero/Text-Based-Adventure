#pragma once
#include "String.h"

#define CAT_ID 1
#define MANAFTN_ID 2
#define ENEMY_ID 3
#define SCROLL_ID 4

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

	int itemID = -1;
};