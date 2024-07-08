#include <iostream>
#include "String.h"
#include "GameController.h"
#include "Object.h"
#include "Spell.h"
#include "Cat.h"

int main() {

	/*Spell spellbook[10] = { 0,1,2,3,4,5,6,7,8,9 };
	Player player("Nova", 8);

	player.GiveSpellAccess(3);
	player.GiveSpellAccess(7);
	player.GiveSpellAccess(8);
	player.GiveSpellAccess(4);

	player.Cast("fairie's' sto n e");
	player.Cast("fair/ies ' ston'e");
	cout << endl;

	for (int i = 0; i < 10; ++i) {
		cout << spellbook[i].NameData() << endl;

		if (spellbook[i].GetMinDmg() != 0) {
			cout << "min damage: " << spellbook[i].GetMinDmg() << endl;
			cout << "max damage: " << spellbook[i].GetMaxDmg() << endl;
		}
		cout << "mana cost: " << spellbook[i].GetManaCost() << endl << endl;
	}*/

	Cat kitty;

	cout << kitty.Interact(true, 765);

}