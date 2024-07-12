#include "GameController.h"

GameController::GameController(String& player, Object* room00, Object* room01, Object* room02, Object* room10, Object* room11, Object* room12, Object* room20, Object* room21, Object* room22)
{
	GenerateRooms(room00,room01,room02,room10,room11,room12,room20,room21,room22);

	name = player.GetData();
}

GameController::~GameController()
{
}

void GameController::RunGame(int roomX, int roomY, bool isNewRoom)
{
	LoadRoom(roomX, roomY, isNewRoom);
	int pos[2] = { roomX, roomY };

	command.Input();
	command.ToLower();

	int commandIndex = 0;

	if (command.Find("move") == 0) {

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
	else if ((commandIndex = command.Find("use")) == 0 && command.len() > 3) {
		system("CLS");
		String temp = new char[command.len() - 3];
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
			Use(inventory[commandIndex].GetID());

		}
		RunGame(pos[0], pos[1], false);

	} 
	else if ((commandIndex = command.Find("pickup") == 0 && command.len() > 6)) {
		system("CLS");
		int j = 0;
		String temp = new char[(command.len() - 6) + 1];

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

			rooms[pos[0]][pos[1]].RemoveItem(rooms[pos[0]][pos[1]].GetItemAtIndex(commandIndex));
		}
		RunGame(pos[0], pos[1], false);

	}
	else if ((commandIndex = command.Find("inspect room") == 0)) {
		system("CLS");
		rooms[pos[0]][pos[1]].ShowContents(fStoneActive);

		cout << endl;

		RunGame(pos[0], pos[1], false);

	}
	else if ((commandIndex = command.Find("show inv") == 0)) {
		system("CLS");

		DisplayInventory();
		RunGame(pos[0], pos[1], false);
	} 
	else if(commandIndex = command.Find("show spell") == 0){
		system("CLS");
		DisplaySpellbook();
		cout << endl;

		RunGame(pos[0], pos[1], false);
	}
	else if (commandIndex = command.Find("help") == 0) {
		system("CLS");
		cout << "Commands:\n-move [n/s/e/w]\n-pickup [item]\n-use [item in inventory]\n-inspect room\n-show [inv/spell]\n-cast [spell]\n-interact [target name]\n";
		RunGame(pos[0], pos[1], false);
	}
	else if (commandIndex = command.Find("cast") == 0 && command.len() > 4) {

		system("CLS");
		String temp = new char[command.len() - 4];
		int j = 0;

		for (int i = 4; i < command.len(); ++i) {
			temp[j] = command[i];
			++j;
		}
		if (temp[command.len() - 4] != '\0') {
			temp[command.len() - 4] = '\0';
		}
		command = temp;
		bool hasSpell = FindSpell(command);

		if (hasSpell == true) {
			Cast(command);
			cout << endl;
		}
		RunGame(pos[0], pos[1], false);
	}
	else if (commandIndex = command.Find("interact") == 0 && command.len() > 9 ) {
		system("CLS");
		String temp = new char[command.len() - 9];
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
		toLoad.Description(toLoad.GetX(), toLoad.GetY());

	}
	else {
		cout << endl << "You are at the " << toLoad.Name() << "\n\n";
	}
}

void GameController::LoadRoom(int x, int y, bool isNewRoom)
{
	LoadRoom(rooms[x][y], isNewRoom);
}

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
			system("pause");
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

void GameController::EndGameHandler()
{
	system("CLS");
	fstream file;
	String endGameDesc;
	int length = 0;

	file.open("EndGameText.txt", ios::in);
	if (file.is_open()) {

		char singleCharacter;

		while (true) {
			file.get(singleCharacter) >> noskipws;
			if (singleCharacter == '#') {
				break;
			}
			else {
				length++;
			}
		}
		
		endGameDesc = new char[length + 1];

		file.seekg(0);

		int i = 0;

		while (i < length) {
			file.get(singleCharacter) >> noskipws;
			endGameDesc[i] = singleCharacter;
			i++;
		}

	}

	file.close(); //close file !!!

	if (endGameDesc[length] != '\0') { //Check for null terminator, adds if it doesnt exist
		endGameDesc[length] = '\0';
	}
	
	endGameDesc.Replace("[playername]", name);

	cout << endGameDesc.GetData();
	cout << "Are you ready to go?\n\n";

	command.Input();
	command.ToLower();
	
	if (command.Find("yes") != -1) {
		cout << "\nYou pass peacefully, Game Over...\n\n";
		system("pause");
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

void GameController::KeyChecker(Object& obj)
{
	if (obj.GetID() == RUSTED_KEY_ID) {
		hasRustKey = true;
	}
	if (obj.GetID() == CEMETERY_KEY_ID) {
		hasCemKey = true;
	}
}


//PLAYER FUNCTIONS


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

void GameController::Interact(String& name, Room& currentRoom)
{
	if (name == "cat" && currentRoom.GetItemAtIndex(0).GetID() == CAT_ID) {
		Cat cat;
		cat.Interact(SwAActive, currentRoom.AnyHiddenItems());
	}
	int itemIndex = currentRoom.HasItem(name);

	if (itemIndex != -1) {
	
		Object& toInteract = currentRoom.GetItemAtIndex(itemIndex);
		itemIndex = toInteract.GetID();

		toInteract.Interact();
	}
	else {
		cout << "You talk to yourself, weirdo..." << endl;
	}

}

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
void GameController::Cast(const char* spellName)
{
	//Conversion for string literal to string obj, passes values
	String pass = spellName;
	Cast(pass);
}

void GameController::DisplayInventory()
{
	int s = 1;
	for (Object i : inventory) {
		if (i.GetID() != -1) {
			cout << "Slot " << s << " " << i.Name() << " Description " << i.Description() << endl;
		}
		else {
			cout << "Slot " << s << "Empty" << endl;
		}
		s++;
	}
}

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

void GameController::AddToInventory(Object& toAdd)
{
	int first = FindFirstEmpty();
	int s = 1;

	if (first != -1) {
		if (toAdd.GetID() != -1 && canPickup[toAdd.GetID()] == true) {
			if (InvHasCopy(toAdd) == false) {
				inventory[first].CopyData(toAdd);
				cout << "Added " << toAdd.Name() << " to inventory slot " << s << endl;
				return;
			}
			else if (InvHasCopy(toAdd) == true) {
				cout << "You cannot carry any more of that item!" << endl;
				return;
			}
			else {
				cout << "You cannot pick that up" << endl;
			}
			s++;
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

void GameController::GiveSpellAccess(int spellID)
{ //Sets the player's spellbook at index spellID to corresponding spell, essential bool flip
	spellbook[spellID].SetDataID(spellID);
}

void GameController::Hurt(int damage)
{
	health -= damage;
}

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