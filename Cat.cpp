#include "Cat.h"

Cat::Cat() : Object("Cat","A furry friend.", CAT_ID, invisible)
{
	name = Object::Name();
	desc = Object::Description();
}

Cat::~Cat()
{
}

int Cat::GetID()
{
	return this->itemID;
}

const char* Cat::Name()
{
	return name.GetData();
}

const char* Cat::Description()
{
	return desc.GetData();
}

void Cat::Interact()
{
	Pet();
}

void Cat::Pet()
{
	cout << "You pet the cat, it is purring!") << endl;
	purring = true;
}
