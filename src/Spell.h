#pragma once
#include "String.h"

class Spell{

public:

	Spell(int id);

	~Spell();

public:

	void Cast();
	void Description();

private:

	String name;
	String desc;

	int dmgClamp[2] = { 0,0 };
	int manaCost = 0;

	const int spellID = -1;
	int* IDptr = const_cast<int*>(&spellID);
};
