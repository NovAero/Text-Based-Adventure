#pragma once
#include "String.h"

class Spell{

public:
	
	Spell();
	Spell(int id); //Constructs by an int ID
	Spell(String& name); //Constructs based on a String object
	Spell(const char* name); //Constructs based on a string literal

	~Spell();

public:
	Spell& operator=(const Spell& toSet);

	bool operator==(int cmp);
	bool operator==(const Spell& cmp);
	bool operator==(const char* cmp);
	bool operator==(const String& cmp);

	bool operator!=(int cmp);
	bool operator!=(const Spell& cmp);
	bool operator!=(const char* cmp);
	bool operator!=(const String& cmp);

public:

	void Cast();
	
	String& NameRef(); //Returns the String object of name
	const char* NameData(); //Returns the string literal of name

	const char* Description(); //Returns a printable description

	int GetID() const; //Returns spell ID

	void SetDataID(int id); //Sets the data by passing in a valid ID
	void SetDataName(const char* name); //Sets the data by a string literal
	void SetDataName(String& name); //Sets the data by a String 

public: //Allows dmg and manacost to be accessed in other classes, but not changed

	const int dmgClamp[2] = { 0,0 }; //{ Minimum, Maximum }
	const int manaCost = 0;

private:

	String name;
	String desc;

	const int spellID = -1; //Default spellID is -1
	
	int* IDptr = const_cast<int*>(&spellID); //Const cast to set spellID only once on creation, or on changing access
	int* dmgPtr = const_cast<int*>(dmgClamp);
	int* manaPtr = const_cast<int*>(&manaCost);
};
