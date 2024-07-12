#include "Scroll.h"

Scroll::Scroll(int ScrollID, bool isInvisible) : Object(ScrollID, isInvisible)
{
	spell.SetDataID(ScrollID-11);

	name = Object::Name();
	desc = Object::Description();

	this->invisible = isInvisible;
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

void Scroll::Interact()
{
	cout << Name() << ", " << Description() << endl;
}

