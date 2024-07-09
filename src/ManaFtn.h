#pragma once
#include "Object.h"
#include "Player.h"

class ManaFtn : public Object {
public:

	ManaFtn();
	~ManaFtn();

public:

	int GetID() override;
	const char* Name() override;
	const char* Description() override;

	void Use(Player& plr);

private:

	bool invisible = false;

	String name;
	String desc;

	int uses = 3;

	const int itemID = 2;

};

