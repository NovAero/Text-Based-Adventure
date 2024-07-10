#include "Key.h"

Key::Key(char colour, const char* name, const char* description, bool invisible) : Object(name, description, itemID, invisible)
{

	name = Object::Name();
	desc = Object::Description();

	this->invisible = invisible;
	keyColour = colour;

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
