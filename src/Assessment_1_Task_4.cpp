#include <iostream>
#include "String.h"
#include "GameController.h"
#include "Object.h"
#include "Spell.h"

int main() {

	Spell spellbook[10] = { 0,1,2,3,4,5,6,7,8,9 };
	Player player("Nova", 8);

	player.GiveSpellAccess(3);
	player.GiveSpellAccess(7);
	player.GiveSpellAccess(8);
	player.GiveSpellAccess(4);

	player.Cast("fairie's' sto n e fireball");
} 
