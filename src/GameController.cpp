#include "GameController.h"

void GameController::LoadRoom(Room& toLoad)
{
	toLoad.ShowContents(false);
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
