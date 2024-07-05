#include "Spell.h"

Spell::Spell(const char* name, const char* description, int id) : Object(name,description)
{
	spellID = id;
}

Spell::Spell(const char* name, String& description, int id) : Object(name, description)
{
	spellID = id;
}

Spell::Spell(String& name, const char* description, int id) : Object(name, description)
{
	spellID = id;
}

Spell::Spell(String& name, String& description, int id) : Object(name, description)
{
	spellID = id;
}

Spell::~Spell()
{
}

void Spell::Cast()
{
	Use();
}
