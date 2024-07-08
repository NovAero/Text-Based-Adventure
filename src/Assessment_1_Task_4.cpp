#include <iostream>
#include "String.h"
#include "GameController.h"
#include "Object.h"
#include "Spell.h"
#include "Cat.h"

int main() {

	Cat kitty;

	cout << kitty.Description();
	kitty.Pet();
	cout << kitty.Description();
}