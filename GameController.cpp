#include "GameController.h"

GameController::GameController(Player& player, Object* room00, Object* room01, Object* room02, Object* room10, Object* room11, Object* room12, Object* room20, Object* room21, Object* room22)
{
	GenerateRooms(room00,room01,room02,room10,room11,room12,room20,room21,room22);

	this->player.SetData(player);
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

	if (command.Find("move") != -1) {

		char direction = command.CharAt(5);

		switch (direction) {

		case 'n':
			
			MHandlerNorth(pos[0], pos[1]);
			break;

		case 'e':

			MHandlerEast(pos[0], pos[1], player.InvHas(CEMETERY_KEY_ID), levActive);
			break;

		case's':

			MHandlerSouth(pos[0], pos[1]);
			break;
		case'w':

			MHandlerWest(pos[0], pos[1], player.InvHas(RUSTED_KEY_ID), dispelMagUsed);
			break;
		default:
			system("CLS");
			cout << "Not a valid action." << endl;
			RunGame(pos[0], pos[1], false);
			break;
		}
	}
	else {
		system("CLS");
		cout << "Not a valid action." << endl;
		RunGame(pos[0], pos[1], false);
	}

	if (command.Find("use") != -1) {

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
		if (rooms[X][Y].HasItemID(DOOR_ID_N) && X > 0) {
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
		else if (rooms[X][Y].HasItemID(DOOR_ID_E) && Y < 2) { //has door to east
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
		if (rooms[X][Y].HasItemID(DOOR_ID_S) && X < 2) {
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
		if (rooms[X][Y].Name() == rooms[0][1].Name() && dispelMagUsed == true) { //player has used dispel magic on door, permenant
			system("CLS");
			Y--;
			RunGame(X, Y, true);
		}
		else if (rooms[X][Y].Name() == rooms[0][1].Name() && dispelMagUsed == false) { //player hasnt used dispel magic
			throw(rooms[X][Y].Name());
		}
		else if (rooms[X][Y].HasItemID(DOOR_ID_W) && Y > 0) { //has door to West
			if (rooms[X][Y - 1].Name() == rooms[2][0].Name() && hasBoatKey== true) { //Has key to boathouse and is on coast
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
		else { //no room to left
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
	
	endGameDesc.Replace("[playername]", player.name);

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

