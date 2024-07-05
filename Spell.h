#pragma once
#include "Object.h"

class Spell : public Object {

public:

	Spell(const char* name, const char* description, int id);
	Spell(const char* name, String& description, int id);
	Spell(String& name, const char* description, int id);
	Spell(String& name, String& description, int id);

	~Spell();

public:

	void Cast();

private:

	String name;
	String desc;

	int spellID;

};

