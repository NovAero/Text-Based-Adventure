#include "Scroll.h"

Scroll::Scroll(int SpellID) : Object(SpellID, itemID, invisible)
{
	spell.SetDataID(SpellID);

	name = Object::Name();
	desc = Object::Description();
}

Scroll::~Scroll()
{
}

int Scroll::GetID()
{
	return this->itemID;
}

const char* Scroll::Name()
{
	return this->name.GetData();
}

const char* Scroll::Description()
{
	return this->desc.GetData();
}

void Scroll::Use(Player& player)
{
	player.GiveSpellAccess(spell.GetID());

}
