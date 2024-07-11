#pragma once
#include "Object.h"

#define CAT_ID 1

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

	bool canPickup = false;
	bool purring = false;
	bool invisible = false;

	String name;
	String desc;

	String converse;

	int itemID = CAT_ID;

};