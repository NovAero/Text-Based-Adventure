#include <iostream>
#include "String.h"
#include "GameController.h"
#include "Object.h"
#include "Spell.h"

int main() {

	String test = "testes ";

	Spell newSpell("test?", test, 0);

	newSpell.Cast(); 
	newSpell.Description();

}
