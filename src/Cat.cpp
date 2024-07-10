#include "Cat.h"

Cat::Cat() : Object("Cat","A furry friend.", CAT_ID, false)
{
	name = Object::Name();
	desc = Object::Description();

	converse = "Meow";
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

const char* Cat::Interact(bool SwAisActive, int numOfHidden)
{
	if(SwAisActive == true) {
		String num = numOfHidden;

		converse = "There are [num] hidden items in this room, meow";
		converse.Replace("[num]", num);

		return converse.GetData();
	}
	converse = "Meow";
	return converse.GetData();
}

void Cat::Pet()
{
	cout << "You pet the cat." << endl;
	desc.Replace('.', ", it is purring!");
	purring = true;
}
