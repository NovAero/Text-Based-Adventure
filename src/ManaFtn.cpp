#include "ManaFtn.h"

ManaFtn::ManaFtn() : Object("Mana Fountain", "A glistening pedestal with a bowl of iridescent liquid.", 2, false)
{
	name = Object::Name();
	desc = Object::Description();
	
	uses = 3;

}

ManaFtn::~ManaFtn()
{
}

int ManaFtn::GetID()
{
	return this->itemID;
}

const char* ManaFtn::Name()
{
	return name.GetData();
}

const char* ManaFtn::Description()
{
	return desc.GetData();
}

void ManaFtn::Use(Player& plr)
{
	if (plr.GetMana() < 15 && uses > 0 ) {
		uses--;
		plr.SetMana(15);
	}
	else {
		cout << "Your mana is full!" << endl;
	}
}
