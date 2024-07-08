#include "Spell.h"

Spell::Spell()
{ //Defaults to -1, name is "NULL". desc is "INVALID ID"
	SetDataID(spellID);
}

Spell::Spell(int id)
{
	SetDataID(id);
}

Spell::Spell(String& name)
{
	SetDataName(name);
}

Spell::Spell(const char* name)
{
	SetDataName(name);
}

Spell::~Spell()
{

}


// Operator Overloads for assignment and equality

Spell& Spell::operator=(const Spell& toSet)
{
	name = toSet.name;
	desc = toSet.desc;
	dmgPtr[0] = toSet.dmgClamp[0];
	dmgPtr[1] = toSet.dmgClamp[1];
	*manaPtr = toSet.manaCost;
	*IDptr = toSet.spellID;

	return *this;
}

bool Spell::operator==(int cmp)
{
	return (spellID == cmp);
}
bool Spell::operator==(const Spell& cmp)
{
	return (spellID == cmp.spellID);
}
bool Spell::operator==(const char* cmp)
{
	return (name.GetData() == cmp);
}
bool Spell::operator==(const String& cmp)
{
	return (name == cmp);
}

bool Spell::operator!=(int cmp)
{
	return (spellID != cmp);
}
bool Spell::operator!=(const Spell& cmp)
{
	return (spellID != cmp.spellID);
}
bool Spell::operator!=(const char* cmp)
{
	return (name.GetData() != cmp);
}
bool Spell::operator!=(const String& cmp)
{
	return (name != cmp);
}

//Public Functions

void Spell::Cast()
{
	cout << "You cast " << NameData();
}

String& Spell::NameRef() {
	return name;
}

const char* Spell::NameData()
{
	return name.GetData();
}

const char* Spell::Description()
{
	return desc.GetData();
}

int Spell::GetID() const
{
	return spellID;
}

//Set data funcs, called in constructors
void Spell::SetDataID(int id)
{
	switch (id)
	{
	case 0:
		*IDptr = id;
		name = "Dispel Magic";
		desc = "Dispels any magic seals or veils in a room";
		*manaPtr = 2;
		break;
	case 1:
		*IDptr = id;
		name = "Levitate";
		desc = "The user floats off the ground, and can move freely until they exit a room";
		*manaPtr = 4;
		break;
	case 2:
		*IDptr = id;
		name = "Fireball";
		desc = "User casts a ball of flame at a target, deals 2d6 fire damage";
		dmgPtr[0] = 2;
		dmgPtr[1] = 12;
		*manaPtr = 5;
		break;
	case 3:
		*IDptr = id;
		name = "Frost Dart";
		desc = "You conjure an icicle from moisture in the air, and propel it towards a target dealing 1d8 damage";
		dmgPtr[0] = 1;
		dmgPtr[1] = 8;
		*manaPtr = 2;
		break;
	case 4:
		*IDptr = id;
		name = "Fairie's Stone";
		desc = "You summon a monocle to peer into other realms, reveals objects hidden by invisibilty";
		*manaPtr = 5;
		break;
	case 5:
		*IDptr = id;
		name = "Speak With Animals";
		desc = "You can converse with any animal, until you leave the room";
		*manaPtr = 2;
		break;
	case 6:
		*IDptr = id;
		name = "Jolt";
		desc = "You evoke a bolt of arcane lightning towards a target, deals 1d10 damage";
		dmgPtr[0] = 1;
		dmgPtr[1] = 10;
		*manaPtr = 3;
		break;
	case 7:
		*IDptr = id;
		name = "Light Orb";
		desc = "You summon an undulating orb of light, allowing you to see in the dark";
		*manaPtr = 2;
		break;
	case 8:
		*IDptr = id;
		name = "Magic Missile";
		desc = "You propel a bolt of force at a target, deals 1d6 damage";
		dmgPtr[0] = 1;
		dmgPtr[1] = 6;
		*manaPtr = 1;
		break;
	case 9:
		*IDptr = id;
		name = "Water Whip";
		desc = "You manipulate water into a whip, and use it on one target, dealing 1d8 damage. Can be used to put out fires";
		dmgPtr[0] = 1;
		dmgPtr[1] = 8;
		*manaPtr = 2;
		break;
	default:
		name = "NULL";
		desc = "INVALID ID";
		break;
	}
}
void Spell::SetDataName(const char* find)
{
	//Passes string literal as a string object to be set
	String pass = find;
	SetDataName(pass);
}
void Spell::SetDataName(String& find)
{
	//Checks if there are any space or apostrophe chars, removes them
	find.ToLower();
	for (int i = 0; i < find.len(); ++i) {
		if (find[i] == ' ' || find[i] == '\'') {
			find.Replace(' ', "", true);
			find.Replace('\'', "", true);
			break;
		}
	}
	//list of all spells without spaces or apostrophes, for the find func
	String SpellList = "dispelmagiclevitatefireballfrostdartfairiesstonespeakwithanimalsjoltlightorbmagicmissilewaterwhip";

	//Finds the string after its been formatted, if it doesnt match any, sets to empty
	switch (SpellList.Find(find))
	{ //Cases are based on constant indexes in SpellList ^^^^^
	case 0: 
		*IDptr = 0;
		name = "Dispel Magic";
		desc = "Dispels any magic seals or veils in a room";
		*manaPtr = 2;
		break;
	case 11:
		*IDptr = 1;
		name = "Levitate";
		desc = "The user floats off the ground, and can move freely until they exit a room";
		*manaPtr = 4;
		break;
	case 19:
		*IDptr = 2;
		name = "Fireball";
		desc = "User casts a ball of flame at a target, deals 2d6 fire damage";
		dmgPtr[0] = 2;
		dmgPtr[1] = 12;
		*manaPtr = 5;
		break;
	case 27:
		*IDptr = 3;
		name = "Frost Dart";
		desc = "You conjure an icicle from moisture in the air, and propel it towards a target dealing 1d8 damage";
		dmgPtr[0] = 1;
		dmgPtr[1] = 8;
		*manaPtr = 2;
		break;
	case 36:
		*IDptr = 4;
		name = "Fairie's Stone";
		desc = "You summon a monocle to peer into other realms, reveals objects hidden by invisibilty";
		*manaPtr = 5;
		break;
	case 48:
		*IDptr = 5;
		name = "Speak With Animals";
		desc = "You can converse with any animal, until you leave the room";
		*manaPtr = 2;
		break;
	case 64:
		*IDptr = 6;
		name = "Jolt";
		desc = "You evoke a bolt of arcane lightning towards a target, deals 1d10 damage";
		dmgPtr[0] = 1;
		dmgPtr[1] = 10;
		*manaPtr = 3;
		break;
	case 68:
		*IDptr = 7;
		name = "Light Orb";
		desc = "You summon an undulating orb of light, allowing you to see in the dark";
		*manaPtr = 2;
		break;
	case 76:
		*IDptr = 8;
		name = "Magic Missile";
		desc = "You propel a bolt of force at a target, deals 1d6 damage";
		dmgPtr[0] = 1;
		dmgPtr[1] = 6;
		*manaPtr = 1;
		break;
	case 88:
		*IDptr = 9;
		name = "Water Whip";
		desc = "You manipulate water into a whip, and use it on one target, dealing 1d8 damage. Can be used to put out fires";
		dmgPtr[0] = 1;
		dmgPtr[1] = 8;
		*manaPtr = 2;
		break;
	default:
		name = "NULL";
		desc = "INVALID ID";
		break;
	}
}