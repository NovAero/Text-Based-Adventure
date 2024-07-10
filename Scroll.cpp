#include "Scroll.h"

Scroll::Scroll(int SpellID) 
{
	spell.SetDataID(SpellID);
	name.Suffix(spell.NameData());
	desc.Replace("[spell]", spell.NameRef());
}

Scroll::~Scroll()
{
}

int Scroll::GetID()
{
	return itemID;
}

const char* Scroll::Name()
{
	return name.GetData();
}

const char* Scroll::Description()
{
	return desc.GetData();
}

void Scroll::Use(Player& player)
{
	player.GiveSpellAccess(spell.GetID());

}
