#pragma once
#include "String.h"
#include "Player.h"
#include "Room.h"
#include "Object.h"
#include "Cat.h"


class GameController
{
public:

	GameController();
	~GameController();

public:

	void RunGame();
	void LoadRoom(Room& toLoad);

	void GenerateRooms(Object* room00, Object* room01, Object* room02, Object* room10, Object* room11, Object* room12, Object* room20, Object* room21, Object* room22);

	void PlayerInput();

	void LoadCombat();

private:

	Room rooms[3][3];

};
