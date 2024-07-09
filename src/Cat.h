#pragma once
#include "Object.h"

class Cat : public Object{
public:

	Cat();
	~Cat();

public:

	int GetID() override;
	const char* Name() override;
	const char* Description() override;

	const char* Interact(bool SwAisActive, int numOfHidden);

	void Pet();

private:

	//Deprecated, use Interact()
	const char* Use() override;


private:

	bool purring = false;
	bool invisible = false;

	String name;
	String desc;

	String converse;

	const int itemID = 1;

};