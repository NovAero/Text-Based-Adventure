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
	LoadRoom(rooms[2][1]);

	command.Input();
	command.ToLower();

	/*if (command.Find("move ")) {

		char direction = command.CharAt(5);

		switch (direction) {

		case 'n':
			try {
				LoadRoom()
			}
			catch(){

			}
			break;
		case 'e':

			break;
		case's':

			break;
		case'w':

			break;
		default:

			break;
		}
	}*/

}

void GameController::LoadRoom(Room& toLoad)
{
	system("CLS");
	cout << "You enter the " << toLoad.Name() << "\n\n";
	cout << toLoad.Description();
	toLoad.ShowContents();
}

void GameController::LoadRoom(int x, int y)
{

}

void GameController::GenerateRooms(Object* room00, Object* room01, Object* room02,Object* room10, Object* room11, Object* room12, Object* room20, Object* room21, Object* room22)
{
	rooms[0][0].SetContents(room00);
	rooms[0][1].SetContents(room01);
	rooms[0][2].SetContents(room02);
	rooms[1][0].SetContents(room10);
	rooms[1][1].SetContents(room11);
	rooms[1][2].SetContents(room12);
	rooms[2][0].SetContents(room20);
	rooms[2][1].SetContents(room21);
	rooms[2][2].SetContents(room22);


}


