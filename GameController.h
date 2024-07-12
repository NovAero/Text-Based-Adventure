#pragma once
#include "String.h"
#include "Spell.h"
#include "Room.h"
#include "Cat.h"
#include "ManaFtn.h"
#include "Enemy.h"
#include "Scroll.h"
#include "Door.h"
#include "Key.h"
#include "Faerie.h"

class GameController
{
public:

	GameController(String& playerName, Object* room00, Object* room01, Object* room02, Object* room10, Object* room11, Object* room12, Object* room20, Object* room21, Object* room22);
	~GameController();

public:


	void RunGame(int roomX, int roomY, bool isNewRoom);
	void LoadRoom(Room& toLoad, bool isNewRoom);
	void LoadRoom(int x, int y, bool isNewRoom);

	void GenerateRooms(Object* room00, Object* room01, Object* room02, Object* room10, Object* room11, Object* room12, Object* room20, Object* room21, Object* room22);

	void MHandlerNorth(int X, int Y);
	void MHandlerEast(int X, int Y, bool hasCemKey, bool levActive);
	void MHandlerSouth(int X, int Y);
	void MHandlerWest(int X, int Y, bool hasBoatKey, bool dispelMagUsed);

	void EndGameHandler();
	
	void KeyChecker(Object& obj);

	void LoadCombat();

	//player funcs

	void PlayerActionSelector();
	void EnemyActionSelector();

	int Heal(int healAmt);

	void Use(int itemID);
	void Interact(String& name, Room& currentRoom);

	void Cast(int spellID);
	void Cast(String& spellName);
	void Cast(const char* spellName);

	void DisplayInventory();
	void DisplaySpellbook();

	int FindFirstEmpty();
	void AddToInventory(Object& toAdd);
	bool InvHasCopy(Object& obj);

	int InvHas(int ID);
	int InvHas(String& itemName);

	bool FindSpell(int spellID);
	bool FindSpell(String& find);
	bool FindSpell(const char* find);

	void GiveSpellAccess(int spellID);

	int Hurt(int damage);

	int GetMana();
	void SetMana(int mana);

public:

	bool dispelMagUsed = false;
	bool fStoneActive = false;
	bool levActive = false;
	bool SwAActive = false;
	bool LOrbActive = false;

	bool hasRustKey = false;
	bool hasCemKey = false;
	bool hasFaerieKey = false;

private:

	String name;

	String command;

	Room rooms[3][3];

	int manaFtnUses = 3;

	//Player things
	bool playerTurn = true;
	bool canPickup[21] = { false,false,false,false,true,true,false,false,false,false,true,true,true ,true ,true ,true ,true ,true ,true , false, false };

	Object inventory[5];
	Spell spellbook[10];

	int health = 30;
	const int maxHealth = 30;

	int mana = 15;
	const int maxMana = 15;
	
	//Enemy things
	int eHealth = 30;
	int dmgClamp[2] = { 1,8 };

};