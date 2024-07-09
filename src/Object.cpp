#pragma once
#include "Object.h"

Object::Object()
{
	name = "N/A";
	desc = "Empty";
}
Object::Object(const char* name, const char* description)
{
	this->name = name;
	desc = description;
}
Object::Object(const char* name, String& description)
{
	this->name = name;
	desc = description;
}
Object::Object(String& name, const char* description)
{
	this->name = name;
	desc = description;
}
Object::Object(String& name, String& description)
{
	this->name = name;
	desc = description;
}
Object::~Object()
{
}



int Object::GetID()
{
	return itemID;
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

const char* Object::Use() 
{
	return "fix later";
}

void Object::CopyData(Object& copy)
{
	this->name = copy.name;
	this->desc = copy.desc;
	*IDPtr = copy.GetID();
	this->isInvisible = copy.isInvisible;
}
