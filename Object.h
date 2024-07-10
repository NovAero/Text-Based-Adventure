#pragma once
#include "String.h"
#include "Spell.h"

#define CAT_ID 1
#define MANAFTN_ID 2
#define ENEMY_ID 3
#define SCROLL_ID 4
#define RUSTED_KEY_ID 5
#define CEMETERY_KEY_ID 6
#define DOOR_ID_N 7
#define DOOR_ID_E 8
#define DOOR_ID_S 9 
#define DOOR_ID_W 10


class Object
{

public:

	Object();

	Object(int spellID, int ID, bool isInvis);
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
	virtual bool CanPickup();

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

	bool canPickup = false;
	bool invisible = false;

	int itemID = -1;
};