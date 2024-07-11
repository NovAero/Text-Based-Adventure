#include "Key.h"

Key::Key(const char* name, const char* description, bool invisible, int KEY_ID) : Object(name, description, KEY_ID, invisible)
{

	name = Object::Name();
	desc = Object::Description();

	this->invisible = invisible;

	itemID = KEY_ID;

}

Key::~Key()
{
}

const char* Key::Name()
{
	return name.GetData();
}

const char* Key::Description()
{
	return desc.GetData();
}