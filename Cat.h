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

	void Interact() override;

	void Pet();

private:

	bool canPickup = false;
	bool purring = false;
	bool invisible = false;

	String name;
	String desc;

	int itemID = CAT_ID;

};