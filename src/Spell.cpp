#include "Spell.h"

Spell::Spell(int id)
{
	switch (id)
	{
	case 0:
		*IDptr = id;
		name = "Dispel Magic";
		desc = "Dispels any magic seals or veils in a room";
		manaCost = 2;
		break;
	case 1:
		*IDptr = id;
		name = "Levitate";
		desc = "The user floats off the ground, and can move freely until they exit a room";
		manaCost = 4;
		break;
	case 2:
		*IDptr = id;
		name = "Fireball";
		desc = "User casts a ball of flame at a target, deals 2d6 fire damage";
		dmgClamp[0] = 2;
		dmgClamp[1] = 12;
		manaCost = 5;
		break;
	case 3:
		*IDptr = id;
		name = "Frost Dart";
		desc = "You conjure an icicle from moisture in the air, and propel it towards a target dealing 1d8 damage";
		dmgClamp[0] = 1;
		dmgClamp[1] = 8;
		manaCost = 2;
		break;
	case 4:
		*IDptr = id;
		name = "Fairie's Stone";
		desc = "You summon a monocle to peer into other realms, reveals objects hidden by invisibilty";
		manaCost = 5;
		break;
	case 5:
		*IDptr = id;
		name = "Speak With Animals";
		desc = "You can converse with any animal, until you leave the room";
		manaCost = 2;
		break;
	case 6:
		*IDptr = id;
		name = "Jolt";
		desc = "You evoke a bolt of arcane lightning towards a target, deals 1d10 damage";
		dmgClamp[0] = 1;
		dmgClamp[1] = 10;
		manaCost = 3;
		break;
	case 7:
		*IDptr = id;
		name = "Light Orb";
		desc = "You summon an undulating orb of light, allowing you to see in the dark";
		manaCost = 2;
		break;
	case 8:
		*IDptr = id;
		name = "Magic Missile";
		desc = "You propel a bolt of force at a target, deals 1d6 damage";
		dmgClamp[0] = 1;
		dmgClamp[1] = 6;
		manaCost = 1;
		break;
	case 9:
		*IDptr = id;
		name = "Water Whip";
		desc = "You manipulate water into a whip, and use it on one target, dealing 1d8 damage. Can be used to put out fires";
		dmgClamp[0] = 1;
		dmgClamp[1] = 8;
		manaCost = 2;
		break;
	default:
		name = "NULL";
		desc = "INVALID ID";
		break;
	}
}

Spell::~Spell()
{
}

void Spell::Cast()
{
	cout << "You cast " << name.GetData();

}

void Spell::Description()
{
	cout << desc.GetData();
}
