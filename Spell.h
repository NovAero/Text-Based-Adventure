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

	//Returns the String object of name
	String& NameRef();
	//Returns the string literal of name
	const char* NameData(); 
	//Returns a printable description
	const char* Description(); 
	//Returns spell ID
	const int GetID() const; 
	//Returns const mana cost
	const int GetManaCost() const; 
	//Returns dmgClamp[0]
	const int GetMinDmg() const; 
	//Return dmgClamp[1]
	const int GetMaxDmg() const; 

	//Sets the data by passing in a valid ID
	void SetDataID(int id); 
	//Sets the data by a string literal
	void SetDataName(const char* name); 
	//Sets the data by a String 
	void SetDataName(String& name); 

	int Cast();

private:

	String name;
	String desc;
	
	int dmgClamp[2] = { 0,0 };
	int manaCost = 0;

	int spellID = -1; //Default spellID is -1
	
};
