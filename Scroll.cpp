#include "Scroll.h"

Scroll::Scroll(int ScrollID) : Object(ScrollID, invisible)
{
	spell.SetDataID(ScrollID-11);

	name = Object::Name();
	desc = Object::Description();
}

Scroll::~Scroll()
{
}

int Scroll::GetID()
{
	return this->itemID;
}

const char* Scroll::Name()
{
	return this->name.GetData();
}

const char* Scroll::Description()
{
	return this->desc.GetData();
}

