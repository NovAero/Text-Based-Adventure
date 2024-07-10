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

void Player::DisplayInventory()
{
	int s = 1;
	for (Object i: inventory) {
		if (i.GetID() != -1) {
			cout << "Slot " << s << " " << i.Name() << " Description " << i.Description() <<  endl;
		}
		else {
			cout << "Slot " << s << "Empty" << endl;
		}
		s++;
	}
}

void Player::DisplaySpellbook()
{
	int k = 1;
	for (Spell s : spellbook) {
		if (FindSpell(s.GetID()) == true) {
			cout << "Spell " << k << " " << s.NameData() << endl;
			k++;
		}
	}
}

void Player::AddToInventory(Object& toAdd)
{
	int s = 1;
	for (Object& i: inventory) {

		if (i.NameObj() == "N/A" && toAdd.CanPickup() == true) {
			if (InvHasCopy(toAdd) == false) {
				i.CopyData(toAdd);
				cout << "Added " << toAdd.Name() << " to inventory slot " << s << endl;
				return;
			}
			else if(InvHasCopy(toAdd) == true){
				cout << "You cannot carry any more of that item!" << endl;
				return;
			}
			else {
				cout << "You cannot pick that up" << endl;
			}
			s++;
		}

	}
	cout << "Inventory is full!" << endl;
}
bool Player::InvHasCopy(Object& obj)
{
	for (Object& o: inventory) {

		if (o.GetID() == obj.GetID()) {
			return true;
		}
	}
	return false;
}

bool Player::FindSpell(int spellID)
{ //Binary search for spellID in player's spellbook, more effective at larger sizes
	int l = 0;
	int r = 9;

	if (spellbook[spellID].GetID() == -1) {//If spellID is -1, spell isnt unlocked
		return false;
	}

	while (l <= r) {
		int m = ((l + r) / 2);

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

void Player::Hurt(int damage)
{
	health -= damage;
}

int Player::GetMana()
{
	return mana;
}

void Player::SetMana(int mana)
{
	this->mana = mana;
	if (this->mana >= maxMana) {
		this->mana = maxMana;
	}
}
