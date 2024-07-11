#pragma once
#include <fstream>
#include "String.h"
#include "Player.h"
#include "Spell.h"
#include "Room.h"
#include "Object.h"
#include "Cat.h"
#include "ManaFtn.h"
#include "Enemy.h"
#include "Scroll.h"
#include "Door.h"

class GameController
{
public:

	GameController(Object* room00, Object* room01, Object* room02, Object* room10, Object* room11, Object* room12, Object* room20, Object* room21, Object* room22);
	~GameController();

public:

	void RunGame(int roomX, int roomY);
	void LoadRoom(Room& toLoad);
	void LoadRoom(int x, int y);

	void GenerateRooms(Object* room00, Object* room01, Object* room02, Object* room10, Object* room11, Object* room12, Object* room20, Object* room21, Object* room22);

	void LoadCombat();



private:

	String command;

	Room rooms[3][3];

};
