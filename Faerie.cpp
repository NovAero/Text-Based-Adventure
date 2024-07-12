#include "Faerie.h"

Faerie::Faerie() : Object("Faerie", "A small magical creature with wings", FAERIE_ID, invisible)
{

	name = Object::Name();
	desc = Object::Description();

}

Faerie::~Faerie()
{
}

int Faerie::GetID()
{
	return this->itemID;
}

const char* Faerie::Name()
{
	return name.GetData();
}

const char* Faerie::Description()
{
	return desc.GetData();
}

void Faerie::Interact()
{
	
}

