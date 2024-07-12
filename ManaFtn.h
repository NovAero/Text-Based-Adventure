#pragma once
#include "Object.h"

#define MANAFTN_ID 2

class ManaFtn : public Object {
public:

	ManaFtn();
	~ManaFtn();

public:

	int GetID() override;
	const char* Name() override;
	const char* Description() override;

private:

	bool invisible = false;

	String name;
	String desc;


	int itemID = MANAFTN_ID;

};

