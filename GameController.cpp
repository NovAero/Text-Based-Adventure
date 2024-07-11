#include "GameController.h"

GameController::GameController(Object* room00, Object* room01, Object* room02, Object* room10, Object* room11, Object* room12, Object* room20, Object* room21, Object* room22)
{
	GenerateRooms(room00,room01,room02,room10,room11,room12,room20,room21,room22);
}

GameController::~GameController()
{
}

void GameController::RunGame()
{
	LoadRoom(1, 1);
	int pos[2] = { 1, 1 };

	command.Input();
	command.ToLower();

	if (command.Find("move ") != -1) {

		char direction = command.CharAt(5);

		switch (direction) {

		case 'n':
			try {
				if (rooms[pos[0]][pos[1]].HasItemID(DOOR_ID_N) && pos[0] > 0) {
					pos[0]--;
					LoadRoom(pos[0], pos[1]);
				}
				else {
					throw(rooms[pos[0]][pos[1]].Name());
				}
			}
			catch(const char* name) {
				if (name == rooms[2][2].Name()) {
					cout << "Trying to move north, you are met with a sheer cliff that is too steep to climb.";
				}
				else if (name == rooms[1][0].Name()) {
					cout << "The forest is too thick in that direction."<<endl;
				}
				else if (name == rooms[0][2].Name()) {
					cout << "The cemetery fences are to tall to climb."<<endl;
				}
				else {
					cout << name << " doesn't have a back door, you can't walk through walls." << endl;
				}
			}
			break;

		case 'e':
			try {
				if (rooms[pos[0]][pos[1]].HasItemID(DOOR_ID_E) && pos[1] < 2) {


				}

			}
			catch (int n) {

			}
			break;

		case's':

			break;
		case'w':

			break;
		default:

			break;
		}
	}

}

void GameController::LoadRoom(Room& toLoad)
{
	cout << "Entering " << toLoad.Name() << "\n\n";
	toLoad.Description(toLoad.GetX(), toLoad.GetY());
}

void GameController::LoadRoom(int x, int y)
{
	LoadRoom(rooms[x][y]);
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