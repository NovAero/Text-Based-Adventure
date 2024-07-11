#pragma once
#include "Object.h"

Object::Object()
{
	name = "N/A";
	desc = "Empty";

}
Object::Object(int scrollID, bool isInvis)
{
	Spell spell(scrollID-11);

	String nTemp = spell.NameData();
	String dTemp = "A dusty bound scroll, which when read reveals the secrets of casting ";
	dTemp.Suffix(nTemp);
	nTemp.Prefix("Scroll of ");

	SetData(nTemp, dTemp, scrollID, isInvis);
}
Object::Object(const char* name, const char* description, int ID, bool isInvis)
{
	String nTemp = name;
	String dTemp = description;

	SetData(nTemp, dTemp, ID, isInvis);
}
Object::Object(const char* name, String& description, int ID, bool isInvis)
{
	String nTemp = name;

	SetData(nTemp, description, ID, isInvis);
}
Object::Object(String& name, const char* description, int ID, bool isInvis)
{
	String dTemp = description;

	SetData(name, dTemp, ID, isInvis);
}
Object::Object(String& name, String& description, int ID, bool isInvis)
{
	SetData(name, description, ID, isInvis);
}

Object::~Object()
{
}

void Object::SetData(String& name, String& description, int ID, bool isInvis)
{
	this->name = name;
	desc = description;
	SetID(ID);
	invisible = isInvis;
	
}

void Object::SetData(const char* name, const char* description, int ID, bool isInvis)
{
	this->name = name;
	desc = description;
	SetID(ID);
	invisible = isInvis;
	
}

void Object::SetID(int ID)
{
	itemID = ID;
}

int Object::GetID()
{
	return this->itemID;
}

bool Object::CanPickup()
{
	return canPickup;
}

const char* Object::Name()
{
	return name.GetData();
}

String& Object::NameObj()
{
	return name;
}

const char* Object::Description() 
{
	return desc.GetData();
}

void Object::Interact()
{
	cout << Name() << ", " << Description() << endl;
}

bool Object::isInvisible()
{
	return invisible;
}

void Object::ToggleInivs()
{
	invisible = !invisible;
}

void Object::CopyData(Object& copy)
{
	this->name = copy.name;
	this->desc = copy.desc;
	itemID = copy.GetID();
	invisible = copy.isInvisible();
}
