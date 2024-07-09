#include <iostream>
#include "String.h"
#include "GameController.h"
#include "Object.h"
#include "Spell.h"
#include "Cat.h"
#include "Room.h"


int main() {

	const int testint = 5;

	Cat cat1;
	Object obj("deez", "nuts", 3, true);

	Object objtest[testint];

	objtest[0].CopyData(obj);
	objtest[1].CopyData(cat1);

	Room test(objtest, 1 , 1);

	test.ShowContents(true);
}