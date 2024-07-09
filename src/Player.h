#pragma once
#include "Object.h"
#include "Spell.h"

class Player
{
public:

	Player(const char* name, int luck);
	Player(String& name, int luck);
	 
	~Player();

public:

	void Attack();

	void Cast(int spellID);
	void Cast(String& spellName);
	void Cast(const char* spellName);

	void DisplayInventory();
	void DisplaySpellbook();

	void AddToInventory(Object& toAdd);
	bool InvHasCopy(Object& obj);

	bool FindSpell(int spellID);
	bool FindSpell(String& find);
	bool FindSpell(const char* find);

	void GiveSpellAccess(int spellID);

	void Hurt(int damage);

	int GetMana();
	void SetMana(int mana);

private:

	String name;

	int health = 15;
	const int maxHealth = 30;

	int luck = 0;

	int mana = 15;
	const int maxMana = 15;

	Object inventory[5];
	Spell spellbook[10];
};