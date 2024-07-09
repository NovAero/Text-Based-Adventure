#include <iostream>
#include "String.h"
#include "GameController.h"
#include "Object.h"
#include "Spell.h"
#include "Cat.h"

int main() {

	Cat kitty;

	Player player("Nova", 3);

	player.AddToInventory(kitty);

	player.DisplayInventory();

	player.AddToInventory(kitty);

	player.GiveSpellAccess(0);
	player.GiveSpellAccess(9);
	player.GiveSpellAccess(1);
	player.GiveSpellAccess(2);
	player.GiveSpellAccess(3);
	player.GiveSpellAccess(5);
	player.GiveSpellAccess(6);
	player.GiveSpellAccess(8);
	player.GiveSpellAccess(4);
	player.GiveSpellAccess(7);

	player.DisplaySpellbook();
}