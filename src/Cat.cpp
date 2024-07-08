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

const char* Cat::Interact(bool SwAisActive)
{
	if(SwAisActive == true){
		converse = "There are hidden items in this room, meow";
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
