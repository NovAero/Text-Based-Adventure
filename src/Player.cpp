#include "Player.h"

Player::Player(const char* name, int luck)
{
	this->name = name;
	this->luck = luck;
}

Player::Player(String& name, int luck)
{
	this->name = name;
	this->luck = luck;
}

Player::~Player()
{
}

void Player::Cast(int spellID)
{
	if (FindSpell(spellID) == true) {
		cout << "You cast " << spellbook[spellID].NameData();
		return;
	}

	cout << "You don't know that spell";
}
void Player::Cast(String& spellName)
{
	//If the spell is in the players inventory, casts it
	if (FindSpell(spellName) == true) {
		Spell spelltmp = spellName;

		if(mana >= spelltmp.GetManaCost()){
			cout << "You cast " << spelltmp.NameData();
			return;
		}
		else {
			cout << "Not enough mana";
			return;
		}
		
	}
	//Else, you dont know/ it doesn't exist
	cout << "You don't know that spell";
}
void Player::Cast(const char* spellName)
{
	//Conversion for string literal to string obj, passes values
	String pass = spellName;
	Cast(pass);
}

bool Player::FindSpell(int spellID)
{ //Binary search for spellID in player's spellbook, more effective at larger sizes
	int l = 0;
	int r = 9;

	while (l <= r) {
		int m = ((l + r) / 2);

		if (spellbook[spellID].GetID() == -1) {//If spellID is -1, spell isnt unlocked
			return false;
		}

		if (m == spellID) {
			return true;
		}
		else if (m < spellID) {
			l = m + 1;

		}
		else if (m > spellID) {
			r = m - 1;
		}
	}
	return false;
}

bool Player::FindSpell(String& find)
{
	Spell temp = find;
	if (FindSpell(temp.GetID()) == false) {
		return false;
	}
	return true;
}

bool Player::FindSpell(const char* find)
{
	Spell temp = find;
	if (FindSpell(temp.GetID()) == false) {
		return false;
	}
	return true;
}

void Player::GiveSpellAccess(int spellID)
{ //Sets the player's spellbook at index spellID to corresponding spell, essential bool flip
	spellbook[spellID].SetDataID(spellID);
}
