#pragma once
#include "String.h"
#include "Player.h"
#include "Room.h"

class GameController
{
public:

	GameController();
	~GameController();

public:

	void RunGame();
	void LoadRoom();
	void LoadCombat();

private:


};
