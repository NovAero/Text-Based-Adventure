#pragma once
#include "Object.h"
#include "Spell.h"

class Player
{
public:

	Player(String& name, int luck);
	~Player();

public:

	void Attack();
	void interact();
	void DisplayInventory();
	void DisplaySpellbook();

	void Hurt(int damage);
	void SetMana(int mana);

private:

	String name;

	int health = 15;
	const int maxHealth = 30;

	int luck = 0;

	int mana = 15;
	const int maxMana = 15;

	Object inventory[5];
	Spell spellbook[10] = { 0,1,2,3,4,5,6,7,8,9 };
	bool spellAccess[10] = { false, false, false, false, false, false, false, false, false, false };

};