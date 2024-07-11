#pragma once
#include "Object.h"
#include "Spell.h"

class Player
{
public:

	Player();
	Player(const char* name);
	Player(String& name);
	 
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
	bool InvHas(int ID);

	bool FindSpell(int spellID);
	bool FindSpell(String& find);
	bool FindSpell(const char* find);

	void GiveSpellAccess(int spellID);

	void Hurt(int damage);

	int GetMana();
	void SetMana(int mana);

	void SetData(Player& copy);

public:

	String name;

	bool levActive = false;
	bool SwAActive = false;

private:


	Object inventory[5];
	Spell spellbook[10];

	int health = 30;
	const int maxHealth = 30;

	int mana = 15;
	const int maxMana = 15;

};