#pragma once
#include "Object.h"
#include "GameController.h"

class Cat : public Object{
public:

	Cat();
	~Cat();

public:

	const char* Name() override;
	const char* Description() override;

	const char* Interact();
	const char* Interact(bool SwAisActive, int numOfHidden);

	void Pet();

private:

	//Deprecated, use Interact()
	const char* Use() override;

private:

	bool purring = false;

	String name;
	String desc;

	String converse;

};