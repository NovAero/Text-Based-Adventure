#include "Cat.h"

Cat::Cat() : Object("Cat","A furry friend.")
{
	name = Object::Name();
	desc = Object::Description();

	converse = "Meow";
}

Cat::~Cat()
{
}

const char* Cat::Name()
{
	return name.GetData();
}

const char* Cat::Description()
{
	return desc.GetData();
}

const char* Cat::Interact()
{
	converse = "Meow";
	return converse.GetData();
}

const char* Cat::Interact(bool SwAisActive, int numOfHidden)
{
	String test = numOfHidden;

	if(SwAisActive == true){
		converse = "There are [num] hidden items in this room, meow";
		converse.Replace("[num]", test);

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
