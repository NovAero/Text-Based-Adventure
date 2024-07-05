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

void Object::Name() const
{

	cout << name.GetData();

}

void Object::Description() const
{
	
	cout << desc.GetData();

}

void Object::Use() const
{
	cout << "you use ";
	Name();
}
