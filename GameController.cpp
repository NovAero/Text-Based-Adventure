#include "GameController.h"

GameController::GameController(String& player, Object* room00, Object* room01, Object* room02, Object* room10, Object* room11, Object* room12, Object* room20, Object* room21, Object* room22)
{
	GenerateRooms(room00,room01,room02,room10,room11,room12,room20,room21,room22);

	name = player.GetData();
}

GameController::~GameController()
{
}

//Main game loop
void GameController::RunGame(int roomX, int roomY, bool isNewRoom)
{
	LoadRoom(roomX, roomY, isNewRoom);
	int pos[2] = { roomX, roomY };

	command.Input();
	command.ToLower();

	int commandIndex = 0;

	if (command.Find("move") == 0) { //Moves in a direction (N E S W)

		char direction = command.CharAt(5);

		switch (direction) {

		case 'n':

			MHandlerNorth(pos[0], pos[1]);
			break;

		case 'e':

			MHandlerEast(pos[0], pos[1], hasCemKey, levActive);
			break;

		case's':

			MHandlerSouth(pos[0], pos[1]);
			break;
		case'w':

			MHandlerWest(pos[0], pos[1], hasRustKey, dispelMagUsed);
			break;
		default:
			system("CLS");
			cout << "Not a valid action." << endl;
			RunGame(pos[0], pos[1], false);
			break;
		}
	} 
	else if ((commandIndex = command.Find("use")) == 0 && command.len() > 3) { //Use uses an item in inventory if possible
		system("CLS");
		char* temp = new char[command.len() - 3 + 1];
		int j = 0;

		for (int i = 4; i < command.len(); ++i) {
			temp[j] = command[i];
			++j;
		}
		if (temp[command.len() - 4] != '\0') {
			temp[command.len() - 4] = '\0';
		}
		command = temp;
		commandIndex = InvHas(command);

		if (commandIndex == -1) {
			cout << "You don't have that item." << endl;
		}
		else {
			if (inventory[commandIndex].GetID() == RUSTED_KEY_ID || inventory[commandIndex].GetID() == CEMETERY_KEY_ID || inventory[commandIndex].GetID() == FAERIE_KEY_ID) {
				cout << "You can't use that item\n";
			} else {
				Use(inventory[commandIndex].GetID());
				inventory[commandIndex].SetData("N/A", "Empty", -1, false);
			}
		}
		RunGame(pos[0], pos[1], false);

	} 
	else if ((commandIndex = command.Find("pickup") == 0 && command.len() > 7)) { //Pickup item, will add to inventory if able to, then deletes it from the room
		system("CLS");
		int j = 0;
		char* temp = new char[(command.len() - 6) + 1];

		for (int i = 7; i < command.len(); ++i) {
			temp[j] = command[i];
			++j;
		}
		if (temp[command.len() - 7] != '\0') {
			temp[command.len() - 7] = '\0';
		}
		command = temp;
		commandIndex = rooms[pos[0]][pos[1]].HasItem(command);

		if (commandIndex == -1) {
			cout << "There is nothing here that fits that description." << endl;
		}
		else {
			AddToInventory(rooms[pos[0]][pos[1]].GetItemAtIndex(commandIndex));

			KeyChecker(rooms[pos[0]][pos[1]].GetItemAtIndex(commandIndex));
			if (InvHas(command) != -1) {

				int idToRemove = rooms[pos[0]][pos[1]].GetItemAtIndex(commandIndex).GetID();

				Room& currentRoom = rooms[roomX][roomY];

				currentRoom.RemoveItem(idToRemove);
			}
		}
		RunGame(pos[0], pos[1], false);

	}
	else if ((commandIndex = command.Find("inspect room") == 0)) { //Shows contents of room
		system("CLS");
		rooms[pos[0]][pos[1]].ShowContents(fStoneActive, LOrbActive);

		cout << endl;

		RunGame(pos[0], pos[1], false);

	}
	else if ((commandIndex = command.Find("show inv") == 0)) { //shows contents of inventory, and Hp and Mana
		system("CLS");

		DisplayInventory();
		RunGame(pos[0], pos[1], false);
	} 
	else if(commandIndex = command.Find("show spell") == 0){ //Shows spellbook with spells known/unknown
		system("CLS");
		DisplaySpellbook();
		cout << endl;

		RunGame(pos[0], pos[1], false);
	}
	else if (commandIndex = command.Find("help") == 0) { //Displays all commands available
		system("CLS");
		cout << "Commands:\n-move [n/s/e/w]\n-pickup [item]\n-use [item in inventory]\n-inspect room\n-show [inv/spell]\n-cast [spell]\n-interact [target name]\n-map\n";
		RunGame(pos[0], pos[1], false);
	}
	else if (commandIndex = command.Find("cast") == 0 && command.len() > 4) {

		system("CLS");
		char* temp = new char[command.len() - 4 + 1];
		int j = 0;

		for (int i = 5; i < command.len(); ++i) {
			temp[j] = command[i];
			++j;
		}
		if (temp[command.len() - 5] != '\0') {
			temp[command.len() - 5] = '\0';
		}
		command = temp;
		bool hasSpell = FindSpell(command);

		if (hasSpell == true) {
			Cast(command);
			cout << endl;
		}
		RunGame(pos[0], pos[1], false);
	}
	else if (commandIndex = command.Find("interact") == 0 && command.len() > 8 ) { //Interact with object in room
		system("CLS");
		char* temp = new char[(command.len() - 8) + 1];
		int j = 0;

		for (int i = 9; i < command.len(); ++i) {
			temp[j] = command[i];
			++j;
		}
		if (temp[command.len() - 9] != '\0') {
			temp[command.len() - 9] = '\0';
		}

		command = temp;

		Interact(command, rooms[pos[0]][pos[1]]);

		RunGame(pos[0], pos[1], false);
	}
	else if (commandIndex = command.Find("attack") == 0) { //starts attack if in forest 
		if (rooms[pos[0]][pos[1]].HasItemID(ENEMY_ID)) {
			system("CLS");
			LoadCombat();

		}
		else {
			system("CLS");
			cout << "There is nothing to fight here" << endl;
			RunGame(pos[0], pos[1], false);
		}

	}
	else if (commandIndex = command.Find("map") == 0) {
		system("CLS");
		Map();
		RunGame(pos[0], pos[1], false);
	}
	else {
		system("CLS");
		cout << "Not a valid action." << endl;
		RunGame(pos[0], pos[1], false);
	}
}

void GameController::LoadRoom(Room& toLoad, bool isNewRoom)
{
	if (isNewRoom == true) {
		cout << "Entering " << toLoad.Name() << "\n\n";
		toLoad.Description(toLoad.GetX(), toLoad.GetY(), LOrbActive);
	}
	else {
		cout << endl << "You are at the " << toLoad.Name() << "\n\n";
	}
}

void GameController::LoadRoom(int x, int y, bool isNewRoom)
{
	LoadRoom(rooms[x][y], isNewRoom);
}

//Fills out room names, contents, and coords
void GameController::GenerateRooms(Object* room00, Object* room01, Object* room02, Object* room10, Object* room11, Object* room12, Object* room20, Object* room21, Object* room22)
{

	rooms[0][0].SetAllData(room00, "The Ossuary", 0, 0);
	rooms[0][1].SetAllData(room01, "The Cathedral", 0, 1);
	rooms[0][2].SetAllData(room02, "The Cemetery", 0, 2);
	rooms[1][0].SetAllData(room10, "The Forest", 1, 0);
	rooms[1][1].SetAllData(room11, "The Gardens", 1, 1);
	rooms[1][2].SetAllData(room12, "The Library", 1, 2);
	rooms[2][0].SetAllData(room20, "The Boat Shed", 2, 0);
	rooms[2][1].SetAllData(room21, "The Coast",2, 1);
	rooms[2][2].SetAllData(room22, "The Rock Pools", 2, 2);

}

//Movement handlers
void GameController::MHandlerNorth(int X, int Y)
{
	try {
		if (rooms[X][Y].HasItemID(DOOR_ID_N) != -1 && X > 0) {
			X--;
			system("CLS");
			RunGame(X, Y, true);
		}
		else {
			throw(rooms[X][Y].Name());
		}
	}
	catch (const char* name) {
		if (name == rooms[2][2].Name()) { //Rock pools
			system("CLS");
			cout << "You are met with a sheer cliff that is too steep to climb." << endl;
		}
		else if (name == rooms[1][0].Name()) { //Forest
			system("CLS");
			cout << "The forest is too thick in that direction." << endl;
		}
		else if (name == rooms[0][2].Name()) { //Cemetery
			system("CLS");
			cout << "The cemetery fences are to tall to climb." << endl;
		}
		else { //Boat Shed, Library, Cathedral, Ossuary
			system("CLS");
			cout << name << " doesn't have a back door, you can't walk through walls." << endl;
		}
		RunGame(X, Y, false);
	}
}
void GameController::MHandlerEast(int X, int Y,bool hasCemKey, bool levActive)
{
	try {
		if (rooms[X][Y].Name() == rooms[0][2].Name() && levActive == true) { //player is levitating and at 0,2
			EndGameHandler();
		}
		else if (rooms[X][Y].Name() == rooms[0][2].Name() && levActive == false) { //player not leveitating at 0,2
			throw(rooms[X][Y].Name());
		}
		else if (rooms[X][Y].HasItemID(DOOR_ID_E) != -1 && Y < 2) { //has door to east
			if (rooms[X][Y + 1].Name() == rooms[0][2].Name() && hasCemKey == true) { //Has key to cemetery and is in cathedral
				system("CLS");
				Y++;
				RunGame(X, Y, true);
			}
			else if(rooms[X][Y + 1].Name() == rooms[0][2].Name() && hasCemKey == false) {//Doesnt have key, is in cathedral
				throw(rooms[X][Y].Name());
			}
			else { //isnt in cathedral
				system("CLS");
				Y++;
				RunGame(X, Y, true);
			}
		}
		else { //no room to right
			throw(rooms[X][Y].Name());
		}
	}
	catch (const char* name) {
		if (name == rooms[2][2].Name()) { //Rock pools
			system("CLS");
			cout << "You are met with a sheer cliff that is too steep to climb." << endl;
		}
		else if (name == rooms[1][2].Name()) { //Library
			system("CLS");
			cout << name << " doesn't have a back door, you can't walk through walls." << endl;
		}
		else if (name == rooms[0][1].Name()) { //Cathedral
			system("CLS");
			cout << "You try to open the cemetery door, but it's locked." << endl;
		}
		else if(name == rooms[0][2].Name()){ //Cemetery
			system("CLS");
			cout << "A wide chasm block your path, you definitely can't make that jump." << endl;
		}
		RunGame(X, Y, false);
	}
}
void GameController::MHandlerSouth(int X, int Y)
{
	try {
		if (rooms[X][Y].HasItemID(DOOR_ID_S) != -1 && X < 2) {
			system("CLS");
			X++;
			RunGame(X, Y, true);
		}
		else {
			throw(rooms[X][Y].Name());
		}
	}
	catch (const char* name) {
		if (name == rooms[2][2].Name() || name == rooms[2][1].Name() || name == rooms[2][0].Name()) { //Rock pools
			system("CLS");
			cout << "You see only ocean until the horizon, it might be a good idea to go another way." << endl;
		}
		else if (name == rooms[1][0].Name()) { //Forest
			system("CLS");
			cout << "The forest is too thick in that direction." << endl;
		}
		else if (name == rooms[0][2].Name()) { //Cemetery
			system("CLS");
			cout << "The cemetery fences are to tall to climb." << endl;
		}
		else {// Library, Cathedral, Ossuary
			system("CLS");
			cout << name << " doesn't have a back door, you can't walk through walls." << endl;
		}
		RunGame(X, Y, false);
	}
}
void GameController::MHandlerWest(int X, int Y, bool hasBoatKey, bool dispelMagUsed)
{
	try {
		if (rooms[X][Y].HasItemID(DOOR_ID_W) != -1 && Y > 0) { //has door to West

			if (rooms[X][Y].Name() == rooms[0][1].Name() && dispelMagUsed == true) { //player has used dispel magic on door, permenant
				system("CLS");
				Y--;
				RunGame(X, Y, true);
			}
			else if (rooms[X][Y].Name() == rooms[0][1].Name() && dispelMagUsed == false) { //player hasnt used dispel magic
				throw(rooms[X][Y].Name());
			}
			if (rooms[X][Y - 1].Name() == rooms[2][0].Name() && hasBoatKey == true) { //Has key to boathouse and is on coast
				system("CLS");
				Y--;
				RunGame(X, Y, true);
			}
			else if (rooms[X][Y - 1].Name() == rooms[2][0].Name() && hasBoatKey == false) {//Doesnt have key, is on coast
				throw(rooms[X][Y].Name());
			}
			else { //isnt in cathedral or boathouse
				system("CLS");
				Y--;
				RunGame(X, Y, true);
			}
		}
		else {
			throw(rooms[X][Y].Name());
		}
	}
	catch (const char* name) {
		if (name == rooms[2][1].Name()) { //Coast
			system("CLS");
			cout << "The Boat house doors are locked." << endl;
		}
		else if (name == rooms[2][0].Name() || name == rooms[0][0].Name()) { //Boat House or Ossuary
			system("CLS");
			cout << name << " doesn't have a back door, you can't walk through walls." << endl;
		}
		else if (name == rooms[0][1].Name()) { //Cathedral
			system("CLS");
			cout << "The door is magically sealed, and cannot be opened." << endl;
		}
		else if (name == rooms[1][0].Name()) { //Forest
			system("CLS");
			cout << "The forest is too thick in that direction." << endl;
		}
		RunGame(X, Y, false);
	}
}

//End game handler
void GameController::EndGameHandler()
{
	system("CLS");

	String endDesc = "You reach the mausoleum, and you read the plaque...\nIn loving memory of [playername]. May they rest well in their eternal slumber\n\n";

	endDesc.Replace("[playername]", name);

	cout << endDesc.GetData();
	cout << "Are you ready to go?\n\n";

	command.Input();
	command.ToLower();
	
	if (command.Find("yes") != -1) {
		cout << "\nYou pass peacefully, Game Over...\n\n";
		system("pause");
		return;
	}
	else if (command.Find("no") != -1) {
		cout << "You may continue to explore, but this is your final resting place\n";
		RunGame(0, 2, false);
	}
	else {
		cout << "Your answer is uncertain, come back when you are ready to rest\n";
		RunGame(0, 2, false);
	};
}

//Bool check for it ID being picked up is a key, which allows you to open doors/finish quest
void GameController::KeyChecker(Object& obj)
{
	if (obj.GetID() == RUSTED_KEY_ID) {
		hasRustKey = true;
	}
	if (obj.GetID() == CEMETERY_KEY_ID) {
		hasCemKey = true;
	} 
	if (obj.GetID() == FAERIE_KEY_ID) {
		hasFaerieKey = true;
	}
}

//Runs combat loop
void GameController::LoadCombat()
{
	cout << "You approach the two goblins and start a fight!!" << endl;

	bool wonFight = false;

	//Game Loop
	while (true) {
		if (playerTurn) {

			if (health > 0) {
				playerTurn = false;
				PlayerActionSelector();

			}
			else if (health <= 0) {
				break;
			}

		}
		else if (!playerTurn) {
			if (eHealth > 0) {
				playerTurn = true;
				EnemyActionSelector();
			}
			else if (eHealth <= 0) {
				wonFight = true;
				break;
			}
		}
	}
	if (wonFight == true) {
		cout << "You defeat the goblins and can now collect the flower!\n";
		canPickup[FAERIE_KEY_ID-1] = true;
		RunGame(1, 0, false);
	}
	else if (wonFight == false) {
		cout << "You Died\n";
		system("pause");
	}
}


//PLAYER FUNCTIONS

//Player actions for combat
void GameController::PlayerActionSelector()
{

	String command;
	int commandIndex = 0;

	cout << "||Health: " << health << "||\t" << "||Enemy Health: " << eHealth << "\nEnemy is readying attack!\n";
	command.Input();

	if (commandIndex = command.Find("cast") == 0 && command.len() > 5) {

		system("CLS");
		char* temp = new char[command.len() - 4 + 1];
		int j = 0;

		for (int i = 5; i < command.len(); ++i) {
			temp[j] = command[i];
			++j;
		}
		if (temp[command.len() - 5] != '\0') {
			temp[command.len() - 5] = '\0';
		}
		command = temp;
		bool hasSpell = FindSpell(command);

		if (hasSpell == true) {

			Spell temp(command);
			int tempID = temp.Cast();

			int dmg = 0;
			int healAmt;

			switch (tempID) {
			case 2:
				dmg = rand() & spellbook[2].GetMaxDmg() + 2;
				cout << "You deal " << dmg << " damage";

				eHealth -= dmg;

				break;

			case 3:
				dmg = rand() & spellbook[3].GetMaxDmg() + 1;
				cout << "You deal " << dmg << " damage";

				eHealth -= dmg;

				break;

			case 6:
				dmg = rand() & spellbook[6].GetMaxDmg() + 1;
				cout << "You deal " << dmg << " damage";

				eHealth -= dmg;

				break;

			case 8:
				
				dmg = rand() & spellbook[8].GetMaxDmg() + 1;
				cout << "You deal " << dmg << " damage";

				eHealth -= dmg;

				break;

			case 9:

				healAmt = rand() & 10 + 1;
				cout << "You heal for " << healAmt << " health";
				Heal(healAmt);
				break;

			default:
				cout << "That spell does nothing here.";
				break;
			}
			cout << endl;

		}
	}
	else {
		system("CLS");
		cout << "Choose a valid action\n";
		PlayerActionSelector();
	}
}
//Enemy action for combat
void GameController::EnemyActionSelector()
{
	int atkDmg = rand() % dmgClamp[1] + dmgClamp[0];

	cout << endl << "You were hit for " << Hurt(atkDmg) << " health" << endl;
}
//Heal handler
int GameController::Heal(int healAmt)
{
	health += healAmt;
	if (health >= maxHealth) {
		health = maxHealth;
	}
	return healAmt;
}

//Displays map
void GameController::Map()
{
	char singleCharacter = 0;
	char temp[2] = "0";

	fstream file; //Opens file for reading
	file.open("Map.txt", std::ios::in);

	if (!file.is_open()) { //If its not open, its open by something else, exits
		cout << "Failure to open file Map.txt";
		return;
	}

	while (singleCharacter != '#') //while char isn't #, keeps printing
	{
		file.get(singleCharacter) >> noskipws;
		if (singleCharacter == '#') {
			break;
		}
		temp[0] = singleCharacter;
		cout << temp[0];
	}

	file.close(); //close file !!!
}

//Use handler
void GameController::Use(int itemID)
{
	String useText = "You read the Scroll of ";
	String flavour = ", filling you with newfound knowledge! \n\n";

	switch (itemID) {
	case SCROLL_ID_DM:
		GiveSpellAccess(SCROLL_ID_DM - 11);
		cout << useText.GetData() << spellbook[0].NameData() << flavour.GetData();
		break;
	case SCROLL_ID_L:
		GiveSpellAccess(SCROLL_ID_L - 11);
		cout << useText.GetData() << spellbook[1].NameData() << flavour.GetData();
		break;
	case SCROLL_ID_FB:
		GiveSpellAccess(SCROLL_ID_FB - 11);
		cout << useText.GetData() << spellbook[2].NameData() << flavour.GetData();
		break;
	case SCROLL_ID_FD:
		GiveSpellAccess(SCROLL_ID_FD - 11);
		cout << useText.GetData() << spellbook[3].NameData() << flavour.GetData();
		break;
	case SCROLL_ID_FS:
		GiveSpellAccess(SCROLL_ID_FS - 11);
		cout << useText.GetData() << spellbook[4].NameData() << flavour.GetData();
		break;
	case SCROLL_ID_SWA:
		GiveSpellAccess(SCROLL_ID_SWA - 11);
		cout << useText.GetData() << spellbook[5].NameData() << flavour.GetData();
		break;
	case SCROLL_ID_J:
		GiveSpellAccess(SCROLL_ID_J - 11);
		cout << useText.GetData() << spellbook[6].NameData() << flavour.GetData();
		break;
	case SCROLL_ID_LO:
		GiveSpellAccess(SCROLL_ID_LO - 11);
		cout << useText.GetData() << spellbook[7].NameData() << flavour.GetData();
		break;
	case SCROLL_ID_MM:
		GiveSpellAccess(SCROLL_ID_MM - 11);
		cout << useText.GetData() << spellbook[8].NameData() << flavour.GetData();
		break;
	case SCROLL_ID_H:
		GiveSpellAccess(SCROLL_ID_H - 11);
		cout << useText.GetData() << spellbook[9].NameData() << flavour.GetData();
		break;
	default:
		cout << "You can't use that item." << endl;
	}
}

//Interaction handler
void GameController::Interact(String& name, Room& currentRoom)
{
	int itemIndex = currentRoom.HasItem(name);

	if (itemIndex != -1) {
		if(name == "cat" && SwAActive == true && currentRoom.AnyHiddenItems() > -1) {
			cout << "There are " << currentRoom.AnyHiddenItems() << " invisible items in this room, meow~" << endl;
		}
		else if(name == "cat" && SwAActive == true && currentRoom.AnyHiddenItems() <= 0) {
			cout << "There are no invisible items in this room, meow~" << endl;
		}
		else if (name == "faerie" && hasFaerieKey == false) {
			cout << "Hello stranger, if you would be so kind as to retrieve the magical flower from those goblins in the forest\nI would be eternally grateful, and I have a little gift for you in return!" << endl;
		}
		else if (name == "faerie" && hasFaerieKey == true) {
			cout << "Oh thank you so much for bringing me this flower! Here, as a token of my gratitude, the secrets of the\nFaerie stones." << endl << endl;
			GiveSpellAccess(4);
			cout << "You learnt the secrets of how to cast \"Faerie's Stone\"" << endl;
		}
		else if (name == "mana fountain") {
			if (mana < maxMana && manaFtnUses > 0) {
				cout << "You drink from the fountain and feel energy rush through you, restoring your mana to full!" << endl;
				SetMana(maxMana);
				manaFtnUses--;
			}
			else if (mana < maxMana && manaFtnUses == 0) {
				cout << "The fountain has run dry." << endl;
			}
			else {
				cout << "You are already full of mana!" << endl;
			}
		}
		else {
			Object& toInteract = currentRoom.GetItemAtIndex(itemIndex);
			itemIndex = toInteract.GetID();

			toInteract.Interact();
		}
	}
	else {
		cout << "You talk to yourself, weirdo..." << endl;
	}

}

//Spellcast handlers
void GameController::Cast(int spellID)
{
	if (FindSpell(spellID) == true) {
		cout << "You cast " << spellbook[spellID].NameData();
		return;
	}

	cout << "You don't know that spell";
}
void GameController::Cast(String& spellName)
{
	//If the spell is in the players inventory, casts it
	if (FindSpell(spellName) == true) {
		Spell spelltmp = spellName;

		if (mana >= spelltmp.GetManaCost()) {

			int castID = spelltmp.Cast();
			int healAmt = rand() % 10 + 1;

			switch (castID) {
			case 0:
				dispelMagUsed = true;
				cout << "You cast " << spelltmp.NameData() << endl;
				mana -= spelltmp.GetManaCost();
				break;

			case 1:
				levActive = true;
				cout << "You cast " << spelltmp.NameData() << endl;
				mana -= spelltmp.GetManaCost();
				break;

			case 4:
				fStoneActive = true;
				canPickup[12] = true;
				canPickup[11] = true;
				canPickup[5] = true;
				cout << "You cast " << spelltmp.NameData() << endl;
				mana -= spelltmp.GetManaCost();
				break;

			case 5:
				SwAActive = true;
				cout << "You cast " << spelltmp.NameData() << endl;
				mana -= spelltmp.GetManaCost();
				break;
			case 7:
				LOrbActive = true;
				canPickup[19] = true;
				cout << "You cast " << spelltmp.NameData() << endl;
				mana -= spelltmp.GetManaCost();
				break;
			case 9:
				if (health = maxHealth) {
					cout << "You are at full health!" << endl;
				}
				else {
					Heal(healAmt);
					cout << "You cast " << spelltmp.NameData() << " and heal for " << healAmt << " health!" << endl;
					mana -= spelltmp.GetManaCost();
					break;
				}
			default:
				cout << "That spell does nothing here.";
			}
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
void GameController::Cast(const char* spellName)
{
	//Conversion for string literal to string obj, passes values
	String pass = spellName;
	Cast(pass);
}

//Displays inventory, hp, and mana
void GameController::DisplayInventory()
{
	int s = 1;
	cout << "[Mana: " << mana << "] [Health :" << health << "]" << endl;
	for (Object i : inventory) {
		if (i.GetID() != -1) {
			cout << "Slot " << s << " " << i.Name() << " Description " << i.Description() << endl;
		}
		else {
			cout << "Slot " << s << " Empty" << endl;
		}
		s++;
	}
}
//Displays spells, if unknown shows "you dont know" text
void GameController::DisplaySpellbook()
{
	int k = 1;
	for (Spell s : spellbook) {
		if (FindSpell(s.GetID()) == true) {
			cout << "Spell " << k << " " << s.NameData() << endl;
			k++;
		}
		else {
			cout << "Spell " << k << ": You don't know this spell yet" << endl;
			k++;
		}
	}
}

//Finds first empty object in inventory
int GameController::FindFirstEmpty()
{
	int i = 0;
	for (Object o : inventory) {

		if (o.GetID() == -1) {
			return i;
		}
		++i;
	}
	return -1;
}

//Add item to inventory
void GameController::AddToInventory(Object& toAdd)
{
	int first = FindFirstEmpty();

	if (first != -1) {
		if (toAdd.GetID() != -1 && canPickup[toAdd.GetID()-1] == true) {
			if (InvHasCopy(toAdd) == false) {
				inventory[first].CopyData(toAdd);
				cout << "Added " << toAdd.Name() << " to inventory slot " << first+1 << endl;
				return;
			}
			else if (InvHasCopy(toAdd) == true) {
				cout << "You cannot carry any more of that item!" << endl;
				return;
			}
		}
		else {
			cout << "You cannot pick that up" << endl;
		}
	}
	else {
		cout << "Inventory is full!" << endl;
	}
}
bool GameController::InvHasCopy(Object& obj)
{
	for (Object o : inventory) {

		if (o.GetID() == obj.GetID()) {
			return true;
		}
	}
	return false;
}

//Checks if inventory has item, if it does returns the index, if not returns -1
int GameController::InvHas(int ID)
{
	int i = 0;
	for (Object o : inventory) {
		if (o.GetID() == ID) {
			return i;
		}
		++i;
	}
	return -1;
}
int GameController::InvHas(String& itemName)
{
	int i = 0;
	for (Object o : inventory) {
		String temp = o.NameObj();
		temp.ToLower();
		if (temp == itemName.ToLower()) {
			return i;
		}
		i++;
	}
	return -1;
}

//Checks player spellbook if they have access to a spell
bool GameController::FindSpell(int spellID)
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
bool GameController::FindSpell(String& find)
{
	Spell temp = find;
	if (FindSpell(temp.GetID()) == false) {
		return false;
	}
	return true;
}
bool GameController::FindSpell(const char* find)
{
	Spell temp = find;
	if (FindSpell(temp.GetID()) == false) {
		return false;
	}
	return true;
}

//Sets spell access in spellbook from -1 to the spell's ID
void GameController::GiveSpellAccess(int spellID)
{ //Sets the player's spellbook at index spellID to corresponding spell, essential bool flip
	spellbook[spellID].SetDataID(spellID);
}

//Damages player by dmgAmount
int GameController::Hurt(int damage)
{
	health -= damage;
	return damage;
}

//Gets value of mana, sets value of mana, cant go above max mana
int GameController::GetMana()
{
	return mana;
}
void GameController::SetMana(int mana)
{
	this->mana = mana;
	if (this->mana >= maxMana) {
		this->mana = maxMana;
	}
}