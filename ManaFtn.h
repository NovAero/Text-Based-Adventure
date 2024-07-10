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

	bool CanPickup() override;

	void Use(Player& plr);

private:

	bool canPickup = false;
	bool invisible = false;

	String name;
	String desc;

	int uses = 3;

	int itemID = MANAFTN_ID;

};

