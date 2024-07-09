#include <iostream>
#include "String.h"
#include "GameController.h"
#include "Object.h"
#include "Spell.h"
#include "Cat.h"
#include "Room.h"

int main() {

	Room test;
	
	Cat cat1;
	Object obj("deez", "nuts", 3, true);

	test.AppendItem(obj);
	test.AppendItem(cat1);
	test.itemsInRoom[0].ToggleInivs();

	test.ShowContents(false);

	test.itemsInRoom[0].ToggleInivs();

	test.ShowContents(false);

	test.RemoveItem(obj);

	test.ShowContents(true);
}